/*
 *******************************************************************************
 * Class   SerialDevice
 * Author  Zhentao Lin @ Freenove (http://www.freenove.com)
 * Date    2020/7/11
 *******************************************************************************
 * Brief
 *   This class is used to connect a specific serial port.
 *   It will automatically detect and connect to a device (serial port) which 
 *   use the same trans format.
 *******************************************************************************
 * Serial data formats
 *   Baud    115200
 *   Data    Range 0 ~ 127 per data byte
 *   Format  0          1       2       ... n-1       n 
 *           transStart data[0] data[1] ... data[n-1] transEnd
 *******************************************************************************
 * Copyright
 *   Copyright © Freenove (http://www.freenove.com)
 * License
 *   Creative Commons Attribution ShareAlike 3.0 
 *   (http://creativecommons.org/licenses/by-sa/3.0/legalcode)
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
import processing.serial.*;
/* Private define ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/*
 * Brief  This class is used to save serial command
 *****************************************************************************/
class SerialCommand
{
  // Trans control command, range 128 ~ 255
  final static int transStart = 128;
  final static int transEnd = 129;

  // General command , range 0 ~ 127
  // The odd command is sent by the requesting party
  // The even command is sent by the responding party
  // Request echo, to confirm the device
  final static String requestEcho = "0";      // Comm
  // Respond echo, to tell this is the device
  final static int echo = 1;             // Comm
  // Request 1 analog value
  final static String requestAnalog = "10";   // Comm 
  // Respond 1 analog value
  final static int Analog = 11;          // Comm A/100 A%100
  // Request n analog values
  final static String requestAnalogs = "12";  // Comm n
  // Respond n analog values
  final static int Analogs = 13;         // Comm A1/100 A1%100 ... An/100 An%100
  // Request 1 digital value
  final static String requestDigital = "14";   // Comm 
  // Respond 1 analog value
  final static int Digital = 15;          // Comm 
}

/*
 * Brief  This class is used to automatically detect and connect to a device 
 *        (serial port) which use the same trans format.
 *****************************************************************************/
class SerialDevice
{
  private final static int readTimeOut = 30;

  private PApplet parent;
  private boolean active = false;
  public Serial serial;
  public String serialName;
  public int[] InData = new int[64];

  SerialDevice(PApplet pApplet)
  {
    parent = pApplet;
  }

  public boolean active()
  {
    return active;
  }

  public boolean start()
  {
    stop();
    println(time() + "Start connect device...");
    String[] serialNames = Serial.list();
    if (serialNames.length == 0)
    {
      println(time() + "No serial port detected, waiting for connection...");
      return false;
    }
    print(time() + "Detected serial port: ");
    for (int i = 0; i < serialNames.length; i++)
      print(serialNames[i] + " ");
    println("");
    for (int i = 0; i < serialNames.length; i++)
    {
      println(time() + "Attempt to connect " + serialNames[i] + "...");
      try {
        serial = new Serial(parent, serialNames[i], 115200);
        serial.clear();
        delay(2000);
        String data = SerialCommand.requestEcho;
        write(serial, data);
        delay(200);
        if(serial.available() > 0){
          InData = read(serial);
        }
        if (InData != null)
        {
          if (InData[1] == SerialCommand.echo)
          {
            serialName = serialNames[i];
            println(time() + "Device connection success: " + serialDevice.serialName);
            active = true;
            return true;
          }
        }
        serial.stop();
        //serial.clear();
      }
      catch (Exception e) {
        e.printStackTrace();
      }
    }
    println(time() + "Device connection failed");
    return false;
  }

  public void stop()
  {
    if (active())
    {
      active = false;
      serial.stop();
    }
  }

  public boolean write(String data)
  {
    if (active())
    {
      write(serial, data);
      return true;
    }
    println(time() + "Write failed");
    return false;
  }
  
   private void write(Serial serial, String data)
  {
    serial.write(SerialCommand.transStart + "/" + data + "/" + SerialCommand.transEnd + "\r\n");
  }



  public int[] read()
  {
    if (active())
    {
      int[] data = read(serial);
      if (data != null)
        return data;
    }
    println(time() + "Read failed");
    return null;
  }

  private int[] read(Serial serial)
  {
    String[] inDatas;
    String[] inData;
    String inDataStr;
    int[] acceptData = new int[0];
    int startTime = millis();
    do
    {
      if (serial.available() > 0)
      {
        delay(20);
        inDataStr = serial.readString();
        inDatas = split(inDataStr, "\r\n");
        inData = split(inDatas[1], "/");
        if(inData.length >= 3){
          if (unhex(inData[0]) == SerialCommand.transStart && unhex(inData[inData.length - 1]) == SerialCommand.transEnd)
          {
            for(int i = 0; i < inData.length; i++){
              acceptData = splice(acceptData, unhex(inData[i]), i);
            }
            return acceptData;
          }
        }
        
        startTime = millis();
      }
    } 
    while (millis () - startTime < readTimeOut);
    return null;
  }

  public int requestAnalog()
  {
    write(SerialCommand.requestAnalog);
    int[] inData = read();
    if (inData != null)
    {
      if (inData[1] == SerialCommand.Analog)
      {
        return inData[2];
      }
    }
    return -1;
  }

  public int requestDigital()
  {
    write(SerialCommand.requestDigital);
    int[] inData = read();
    if (inData != null)
    {
      if (inData[1] == SerialCommand.Digital)
      {
        return inData[2];
      }
    }
    return -1;
  }

  public int[] requestAnalogs(int number)
  {
    String commd = "";
    if(number == 2){
      commd = SerialCommand.requestAnalogs + "/2";
    }
    if(number == 3){
      commd = SerialCommand.requestAnalogs + "/3";
    }
    write(commd);
    int[] inData = read();
    if (inData != null)
    {
      if (inData[1] == SerialCommand.Analogs)
      {
        int[] analogs = new int[number];
        for (int i = 0; i < number; i++)
        {
          analogs[i] = inData[2+i];
        }
        return analogs;
      }
    }
    return null;
  }

  public String time()
  {
    return hour() + ":" + minute() + ":" + second() + " ";
  }
}
