##############################################################################
Chapter Attitude Sensor MPU6050
##############################################################################

In this chapter, we will learn about an MPU6050 Attitude Sensor, which integrates an Accelerometer and Gyroscope. 

Project Read an MPU6050 Sensor Module
****************************************************

In this project, we will read Acceleration and Gyroscope Data of the MPU6050 Sensor.

Component List
===============================

+-----------------------------------------+------------------------------------------+
| Raspberry Pi Pico x1                    | USB Cable x1                             |
|                                         |                                          |
| |Chapter01_08|                          | |Chapter01_09|                           |
+-----------------------------------------+------------------------------------------+
| Breadboard x1                                                                      |
|                                                                                    |
| |Chapter01_10|                                                                     |
+-----------------------------------------+------------------------------------------+
| Jumper                                  | MPU6050 x1                               |
|                                         |                                          |
|  |Chapter26_03|                         | |Chapter27_00|                           |
+-----------------------------------------+------------------------------------------+

.. |Chapter01_08| image:: ../_static/imgs/1_LED/Chapter01_08.png
.. |Chapter01_09| image:: ../_static/imgs/1_LED/Chapter01_09.png
.. |Chapter01_10| image:: ../_static/imgs/1_LED/Chapter01_10.png
.. |Chapter26_03| image:: ../_static/imgs/26_Infrared_Motion_Sensor/Chapter26_03.png
.. |Chapter27_00| image:: ../_static/imgs/27_Attitude_Sensor_MPU6050/Chapter27_00.png

Component Knowledge
============================

MPU6050
----------------

MPU6050 Sensor Module is a complete 6-axis Motion Tracking Device. It combines a 3-axis Gyroscope, a 3-axis Accelerometer and a DMP (Digital Motion Processor) all in a small package. The settings of the Accelerometer and Gyroscope of MPU6050 can be changed. A precision wide range digital temperature sensor is also integrated to compensate data readings for changes in temperature, and temperature values can be read. The MPU6050 Module follows the I2C communication protocol and the default address is 0x68.

MPU6050 is widely used to assist with balancing vehicles, robots and aircraft, mobile phones and other products which require stability to control stability and attitude or which need to sense same.

.. image:: ../_static/imgs/27_Attitude_Sensor_MPU6050/Chapter27_01.png
    :align: center

The port description of the MPU6050 module is as follows:

+----------+------------+--------------------------------------------------------------+
| Pin name | Pin number |                         Description                          |
+==========+============+==============================================================+
| VCC      | 1          | Positive pole of power supply with voltage 5V                |
+----------+------------+--------------------------------------------------------------+
| GND      | 2          | Negative pole of power supply                                |
+----------+------------+--------------------------------------------------------------+
| SCL      | 3          | I2C communication clock pin                                  |
+----------+------------+--------------------------------------------------------------+
| SDA      | 4          | I2C communication clock pin                                  |
+----------+------------+--------------------------------------------------------------+
| XDA      | 5          | I2C host data pin, which can be connected to other devices.  |
+----------+------------+--------------------------------------------------------------+
| XCL      | 6          | I2C host clock pin, which can be connected to other devices. |
+----------+------------+--------------------------------------------------------------+
|          |            | I2C address bit control pin.                                 |
|          |            |                                                              |
| AD0      | 7          | Low level: the device address is 0x68                        |
|          |            |                                                              |
|          |            | High level: the device address is 0x69                       |
+----------+------------+--------------------------------------------------------------+
| INT      | 8          | Output interrupt pin                                         |
+----------+------------+--------------------------------------------------------------+

For more details, please refer to datasheet.

Circuit
===========================

.. list-table::
   :width: 100%
   :align: center
   
   * -  Move to the Infrared Motion Sensor
   * -  |Chapter27_02|
   * -  Move away from the Infrared Motion Sensor
       
        :red:`If you need any support, please contact us via:` support@freenove.com
   * -  |Chapter27_03| 

.. |Chapter27_02| image:: ../_static/imgs/27_Attitude_Sensor_MPU6050/Chapter27_02.png
.. |Chapter27_03| image:: ../_static/imgs/27_Attitude_Sensor_MPU6050/Chapter27_03.png

Sketch
=======================

How to install the library
----------------------------------

In this project, we will read the acceleration data and gyroscope data of MPU6050, and print them out.

We use a third-party library named MPU6050_tockn. Here are two ways to install the library for your reference.

The first one: Open Arduino IDE, click Library Manage on the left, search "MPU6050_tockn" to install.

.. image:: ../_static/imgs/27_Attitude_Sensor_MPU6050/Chapter27_04.png
    :align: center

The second way, open Arduino IDE, click Sketch -> Include Library -> Add .ZIP Library. In the pop-up window, find the file named " **./Libraries/MPU6050_tockn-V1.5.2.Zip** " which locates in this directory, and click OPEN.

.. image:: ../_static/imgs/27_Attitude_Sensor_MPU6050/Chapter27_05.png
    :align: center

Sketch_Acceleration_Detection
------------------------------------------

.. image:: ../_static/imgs/27_Attitude_Sensor_MPU6050/Chapter27_06.png
    :align: center

Download the code to Pico, open the serial monitor set the baud rate to 115200, as shown in the following picture: 

.. image:: ../_static/imgs/27_Attitude_Sensor_MPU6050/Chapter27_07.png
    :align: center

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_27.1_Acceleration_Detection/Sketch_27.1_Acceleration_Detection.ino    
    :linenos: 
    :language: c
    :lines: 1-50
    :dedent:

Two library files " **MPU6050_tockn.h** " and " **Wire.h** " are used in the code and will be compiled with others. Class MPU6050 is used to operate the MPU6050. When using it, please instantiate an object first.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_27.1_Acceleration_Detection/Sketch_27.1_Acceleration_Detection.ino    
    :linenos: 
    :language: c
    :lines: 10-10
    :dedent:

In the setup function, IIC and MPU6050 are initialized and the offset difference of MPU6050 is obtained.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_27.1_Acceleration_Detection/Sketch_27.1_Acceleration_Detection.ino    
    :linenos: 
    :language: c
    :lines: 16-21
    :dedent:

The getMotion6 function is used to obtain the x, y, z axis acceleration raw data and the Gyroscope raw data.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_27.1_Acceleration_Detection/Sketch_27.1_Acceleration_Detection.ino    
    :linenos: 
    :language: c
    :lines: 44-51
    :dedent:

Finally, the original data of the gyroscope is updated and acquired every second, and the original data, the processed acceleration and angular velocity data are printed out through the serial port.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_27.1_Acceleration_Detection/Sketch_27.1_Acceleration_Detection.ino    
    :linenos: 
    :language: c
    :lines: 23-43
    :dedent:

Reference
------------------------------------

.. py:function:: Class MPU6050	

    This is a class library used to operate MPU6050, which can directly read and set MPU6050. Here are some member functions:

    **MPU6050 mpu6050(Wire):** Associate MPU6050 with IIC. 

    **begin():** Initialize the MPU6050.

    **calcGyroOffsets(true):** If the parameter is true, get the gyro offset and automatically correct the offset. If the parameter is false, the offset value is not obtained and the offset is not corrected.

    **getRawAccX():** Gain the values of X axis acceleration raw data.

    **getRawAccY():** Gain the values of Y axis acceleration raw data.

    **getRawAccZ():** Gain the values of Z axis acceleration raw data.

    **getRawGyroX():** Gain the values of X axis Gyroscope raw data.

    **getRawGyroY():** Gain the values of Y axis Gyroscope raw data.

    **getRawGyroZ():** Gain the values of Z axis Gyroscope raw data.

    **getTemp():** Gain the values of MPU6050'temperature data.

    **update():** Update the MPU6050. If the updated function is not used, the IIC will not be able to retrieve the new data.