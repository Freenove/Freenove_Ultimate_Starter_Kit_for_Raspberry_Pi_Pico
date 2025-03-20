##############################################################################
Chapter Infrared Motion Sensor
##############################################################################

In this chapter, we will learn a widely used sensor, Infrared Motion Sensor. 

Project Infrared Motion Detector with LED Indicator
*******************************************************************

In this project, we will make a Motion Detector, with the human body infrared pyroelectric sensors.

When someone is in close proximity to the Motion Detector, it will automatically light up and when there is no one close by, it will be out.

This Infrared Motion Sensor can detect the infrared spectrum (heat signatures) emitted by living humans and animals.

Component List
=============================

+-----------------------------------------+------------------------------------------+
| Raspberry Pi Pico x1                    | USB Cable x1                             |
|                                         |                                          |
| |Chapter01_08|                          | |Chapter01_09|                           |
+-----------------------------------------+------------------------------------------+
| Breadboard x1                                                                      |
|                                                                                    |
| |Chapter01_10|                                                                     |
+-----------------------------------------+------------------------------------------+
| HC SR501 x1                             | LED x1                                   |
|                                         |                                          |
|  |Chapter26_00|                         | |Chapter26_01|                           |
+-----------------------------------------+------------------------------------------+
| Resistor 220Ω x1                        | Jumper                                   |
|                                         |                                          |
|  |Chapter26_02|                         | |Chapter26_03|                           |
+-----------------------------------------+------------------------------------------+

.. |Chapter01_08| image:: ../_static/imgs/1_LED/Chapter01_08.png
.. |Chapter01_09| image:: ../_static/imgs/1_LED/Chapter01_09.png
.. |Chapter01_10| image:: ../_static/imgs/1_LED/Chapter01_10.png
.. |Chapter26_00| image:: ../_static/imgs/26_Infrared_Motion_Sensor/Chapter26_00.png
.. |Chapter26_01| image:: ../_static/imgs/26_Infrared_Motion_Sensor/Chapter26_01.png
.. |Chapter26_02| image:: ../_static/imgs/26_Infrared_Motion_Sensor/Chapter26_02.png
.. |Chapter26_03| image:: ../_static/imgs/26_Infrared_Motion_Sensor/Chapter26_03.png

Component Knowledge
============================

The following is the diagram of the infrared Motion sensor(HC SR-501):

.. list-table::
   :width: 100%
   :align: center
   
   * -  Top
     -  Bottom 
     -  Schematic
   * -  |Chapter26_04| 
     -  |Chapter26_05|
     -  |Chapter26_06| 

.. |Chapter26_04| image:: ../_static/imgs/26_Infrared_Motion_Sensor/Chapter26_04.png
.. |Chapter26_05| image:: ../_static/imgs/26_Infrared_Motion_Sensor/Chapter26_05.png
.. |Chapter26_06| image:: ../_static/imgs/26_Infrared_Motion_Sensor/Chapter26_06.png

Description: 

    Working voltage: 5v-20v(DC) Static current: 65uA.
    
    Automatic Trigger: When a living body enters into the active area of sensor, the module will output high level (3.3V). When the body leaves the sensor's active detection area, it will output high level lasting for time period T, then output low level(0V). Delay time T can be adjusted by the potentiometer R1.
    
    According to the position of jumper cap, you can choose non-repeatable trigger mode or repeatable mode.
    
    L: non-repeatable trigger mode. The module output high level after sensing a body, then when the delay time is over, the module will output low level. During high level time, the sensor no longer actively senses bodies.  
    
    H: repeatable trigger mode. The distinction from the L mode is that it can sense a body until that body leaves during the period of high-level output. After this, it starts to time and output low level after delaying T time.
    
    Induction block time: the induction will stay in block condition and does not induce external signal at lesser time intervals (less than delay time) after outputting high level or low level. 
    
    Initialization time: the module needs about 1 minute to initialize after being powered ON. During this period, it will alternately output high or low level. 
    
    One characteristic of this sensor is when a body moves close to or moves away from the sensor's dome edge, the sensor will work at high sensitivity. When a body moves close to or moves away from the sensor's dome in a vertical direction, the sensor cannot detect well (please take note of this deficiency). 

.. note::
    
    The Sensing Range (distance before a body is detected) is adjusted by the potentiometer.

We can regard this sensor as a simple inductive switch when in use.

Circuit
===============================

.. list-table::
   :width: 100%
   :align: center
   
   * -  Schematic diagram
   * -  |Chapter26_07|
   * -  Hardware connection. 
       
        :red:`If you need any support, please contact us via:` support@freenove.com
   * -  |Chapter26_08| 

.. |Chapter26_07| image:: ../_static/imgs/26_Infrared_Motion_Sensor/Chapter26_07.png
.. |Chapter26_08| image:: ../_static/imgs/26_Infrared_Motion_Sensor/Chapter26_08.png

Sketch
============================

In this project, we will use the infrared motion sensor to trigger an LED, essentially making the infrared motion sensor act as a motion switch. Therefore, the code is very similar to the earlier project "push button switch and LED". The difference is that, when infrared motion sensor detects change, it will output high level; when button is pressed, it will output low level. When the sensor output high level, the LED turns ON, or it will turn OFF.

Sketch_Infrared_Motion_Sensor
-----------------------------------------

.. image:: ../_static/imgs/26_Infrared_Motion_Sensor/Chapter26_09.png
    :align: center

Verify and upload the code, and put the sensor on a stationary table and wait for about a minute. Then try to move away from or move closer to the infrared motion sensor and observe whether the LED turns ON or OFF automatically.

You can rotate the potentiometer on the sensor to adjust the detection effect, or use different modes by changing the jumper.

.. image:: ../_static/imgs/26_Infrared_Motion_Sensor/Chapter26_10.png
    :align: center

Apart from that, you can also use this sensor to control some other modules to implement different functions by reediting the code, such as the induction lamp, induction door.

.. list-table::
   :width: 100%
   :align: center
   
   * -  Move to the Infrared Motion Sensor
   * -  |Chapter26_11|
   * -  Move away from the Infrared Motion Sensor
   * -  |Chapter26_12| 

.. |Chapter26_11| image:: ../_static/imgs/26_Infrared_Motion_Sensor/Chapter26_11.png
.. |Chapter26_12| image:: ../_static/imgs/26_Infrared_Motion_Sensor/Chapter26_12.png