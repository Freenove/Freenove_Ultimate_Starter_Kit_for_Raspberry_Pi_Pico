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

Code
=======================

Open "Thonny", click "This computer" -> "D:" -> "Micropython_Codes" -> "27.1_MPU6050". Select "mpu6050.py", right click your mouse to select "Upload to /", wait for "mpu6050.py" to be uploaded to Raspberry Pi Pico and then double click "27.1_MPU6050.py". 

MPU6050
-------------------------

.. image:: ../_static/imgs/27_Attitude_Sensor_MPU6050/Chapter27_08.png
    :align: center

Click "Run current script". When Raspberry Pi Pico obtains acceleration data and gyroscope data of MPU605, it will print them in "Shell". Press Ctrl+C or click "Stop/Restart backend" to exit the program.

.. image:: ../_static/imgs/27_Attitude_Sensor_MPU6050/Chapter27_09.png
    :align: center

.. note::
    
    The data transmission of MPU6050 is very sensitive. Therefore, when using it, please make sure the jumper wire is in good contact; otherwise, the data may fail to be obtained.

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/27.1_MPU6050/27.1_MPU6050.py
    :linenos: 
    :language: python
    :lines: 1-21
    :dedent:

Import MPU6050 and time modules. 

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/27.1_MPU6050/27.1_MPU6050.py
    :linenos: 
    :language: python
    :lines: 1-2
    :dedent:

Set I2C pins and associate them with MPU6050 module, and then initialize MPU6050 and wait for the initialization to complete.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/27.1_MPU6050/27.1_MPU6050.py
    :linenos: 
    :language: python
    :lines: 5-6
    :dedent:

Obtain the acceleration data of MPU6050 and store it in accel. Obtain the gyroscope data and store it in gyro.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/27.1_MPU6050/27.1_MPU6050.py
    :linenos: 
    :language: python
    :lines: 11-12
    :dedent:

Update and collect the original data of the gyroscope every second and print the original data and processed acceleration and angular velocity data in "Shell".

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/27.1_MPU6050/27.1_MPU6050.py
    :linenos: 
    :language: python
    :lines: 10-19
    :dedent:

Reference
-------------------

.. py:function:: Class mpu6050	
    
    Before each use of **mpu6050** , please add the statement " **from mpu6050 import MPU6050** " to the top of the python file.
    
    **MPU6050(bus, sclpin, sdapin):** Create MPU6050 object and set the bus and pins for I2C.
    
    **MPU_Init():** Initialize MPU6050 module.
    
    **MPU_Get_Accelerometer():** Obtain original data of MPU6050's acceleration.
    
    **MPU_Get_Gyroscope():** Obtain original data of MPU6050's Gyroscope.