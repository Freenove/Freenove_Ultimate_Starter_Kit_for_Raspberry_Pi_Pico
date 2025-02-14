##############################################################################
Chapter Servo
##############################################################################

Previously, we learned how to control the speed and rotational direction of a Motor. In this chapter, we will learn about servos, which are a rotary actuator type motor that can be controlled to rotate to specific angles.

Project Servo Sweep
************************************

First, we need to learn how to make a Servo rotate.

Component List
==================================

+-----------------------------------------+------------------------------------------+
| Raspberry Pi Pico x1                    | USB Cable x1                             |
|                                         |                                          |
| |Chapter01_08|                          | |Chapter01_09|                           |
+-----------------------------------------+------------------------------------------+
| Breadboard x1                                                                      |
|                                                                                    |
| |Chapter01_10|                                                                     |
+-----------------------------------------+------------------------------------------+
| Jumper                                  | Servo x1                                 |
|                                         |                                          |
|  |Chapter19_00|                         | |Chapter19_01|                           |
+-----------------------------------------+------------------------------------------+

.. |Chapter01_08| image:: ../_static/imgs/1_LED/Chapter01_08.png
.. |Chapter01_09| image:: ../_static/imgs/1_LED/Chapter01_09.png
.. |Chapter01_10| image:: ../_static/imgs/1_LED/Chapter01_10.png
.. |Chapter19_00| image:: ../_static/imgs/19_Servo/Chapter19_00.png
.. |Chapter19_01| image:: ../_static/imgs/19_Servo/Chapter19_01.png

Component Knowledge
=========================

Servo
--------------------------

Servo is a compact package, which consists of a DC Motor, a set of reduction gears to provide torque, a sensor and control circuit board. Most Servos only have a 180-degree range of motion via their "horn". Servos can output higher torque than a simple DC Motor alone and they are widely used to control motion in model cars, model airplanes, robots, etc. Servos have three wire leads, which usually terminate to a male or female 3-pin plug. Two leads are for electric power: Positive (2-VCC, Red wire), Negative (3-GND, Brown wire), and the signal line (1-Signal, Orange wire) as represented in the Servo provided in your Kit.

.. image:: ../_static/imgs/19_Servo/Chapter19_02.png
    :align: center

We will use a 50Hz PWM signal with a duty cycle in a certain range to drive the Servo. The time interval of 0.5ms-2.5ms of PWM single cycle high level corresponds to the Servo angle 0 degrees - 180 degrees linearly. Part of the corresponding values are as follows:

+-----------------+-------------+
| High level time | Servo angle |
+=================+=============+
| 0.5ms           | 0 degree    |
+-----------------+-------------+
| 1ms             | 45 degree   |
+-----------------+-------------+
| 1.5ms           | 0 degree    |
+-----------------+-------------+
| 2ms             | 45 degree   |
+-----------------+-------------+
| 2.5ms           | 180 degree  |
+-----------------+-------------+

When you change the Servo signal value, the Servo will rotate to the designated angle.

Circuit
=============================

.. list-table::
   :width: 100%
   :align: center
   
   * -  Schematic diagram
   * -  |Chapter19_03|
   * -  Hardware connection. 
       
        :red:`If you need any support, please contact us via:` support@freenove.com
   * -  |Chapter19_04|
    
.. |Chapter19_03| image:: ../_static/imgs/19_Servo/Chapter19_03.png
.. |Chapter19_04| image:: ../_static/imgs/19_Servo/Chapter19_04.png

Code
=============================

Open "Thonny", click "This computer" -> "D:" -> "Micropython_Codes" -> "19.1_Servo_Sweep".Select "myservo.py", right click your mouse to select "Upload to /", wait for "myservo.py" to be uploaded to Raspberry Pi Pico and then double click "19.1_Servo_Sweep.py". 

Servo_Sweep
----------------------------

.. image:: ../_static/imgs/19_Servo/Chapter19_13.png
    :align: center

Click "Run current script", the Servo will rotate from 0 degrees to 180 degrees and then reverse the direction to make it rotate from 180 degrees to 0 degrees and repeat these actions in an endless loop. Press Ctrl+C or click "Stop/Restart backend" to exit the program.

.. image:: ../_static/imgs/19_Servo/Chapter19_14.png
    :align: center

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/19.1_Servo_Sweep/19.1_Servo_Sweep.py
    :linenos: 
    :language: python
    :lines: 1-17
    :dedent:

Import myservo module.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/19.1_Servo_Sweep/19.1_Servo_Sweep.py
    :linenos: 
    :language: python
    :lines: 1-1
    :dedent:

Initialize pins of the servo and set the starting point of the servo to 0 degree.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/19.1_Servo_Sweep/19.1_Servo_Sweep.py
    :linenos: 
    :language: python
    :lines: 4-6
    :dedent:

Control the servo to rotate to a specified angle within the range of 0-180 degrees.  

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/19.1_Servo_Sweep/19.1_Servo_Sweep.py
    :linenos: 
    :language: python
    :lines: 5-5
    :dedent:

Use two for loops. The first one controls the servo to rotate from 0 degree to 180 degrees while the other controls it to rotate back from 180 degrees to 0 degree.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/19.1_Servo_Sweep/19.1_Servo_Sweep.py
    :linenos: 
    :language: python
    :lines: 10-15
    :dedent:

Reference
--------------------------------

.. py:function:: class myServo 	
    
    Before each use of **Servo** , please make sure myservo.py has been uploaded to "/" of Raspberry Pi Pico, and then add the statement " **from myservo import Servo** " to the top of the python file.
    
    **Servo():** The object that controls the servo, with the default pin GP15, default frequency 50Hz.
    
    **ServoDuty(duty):** The function controls the servo's rotating angle through the duty cycle.
    
        **duty:** Ranges from 1638 to 8190, with 1638 corresponding to the servo's 0 degree and 8190 corresponding to 180 degrees.
    
    **ServoAngle(pos):** The function passes in pos(angle) value to control the servo's rotating angle. 
    
        **pos:** Ranging from 0-180, corresponding the 0-180 degrees of the servo.
    
    **ServoTime(us):** The function passes in us(time) to control the servo's rotating angle.
    
        **us:** Ranges from 500-2500, with 500 corresponding to the servo's 0 degree and 2500 corresponding to 180 degrees.

Project Servo Knob
******************************

Use a potentiometer to control the servomotor to rotate at any angle.

Component List
==============================

+-----------------------------------------+------------------------------------------+
| Raspberry Pi Pico x1                    | USB Cable x1                             |
|                                         |                                          |
| |Chapter01_08|                          | |Chapter01_09|                           |
+-----------------------------------------+------------------------------------------+
| Breadboard x1                                                                      |
|                                                                                    |
| |Chapter01_10|                                                                     |
+-----------------------------------------+----------------+-------------------------+
| Jumper                                  | Servo x1       |  Rotary                 |
|                                         |                |                         |
|                                         |                |  potentiometer x1       |
|                                         |                |                         |
|  |Chapter19_01|                         | |Chapter19_00| |  |Chapter19_09|         |
+-----------------------------------------+----------------+-------------------------+

.. |Chapter19_09| image:: ../_static/imgs/19_Servo/Chapter19_09.png
    :width: 80%

Circuit
==============================

Use caution when supplying power to the Servo, it should be 5V. Make sure you do not make any errors when connecting the Servo to the power supply.

.. list-table::
   :width: 100%
   :align: center
   
   * -  Schematic diagram
   * -  |Chapter19_10|
   * -  Hardware connection. 
       
        :red:`If you need any support, please contact us via:` support@freenove.com
   * -  |Chapter19_11|
    
.. |Chapter19_10| image:: ../_static/imgs/19_Servo/Chapter19_10.png
.. |Chapter19_11| image:: ../_static/imgs/19_Servo/Chapter19_11.png

Code
=============================

Open "Thonny", click "This computer" -> "D:" -> "Micropython_Codes" -> "19.2_Servo_Knob". Select "myservo.py", right click your mouse to select "Upload to /", wait for "myservo.py" to be uploaded to Raspberry Pi Pico and then double click "19.2_Servo_Knob.py". 

Servo_Knob
------------------------------

.. image:: ../_static/imgs/19_Servo/Chapter19_15.png
    :align: center

Click "Run current script", twist the potentiometer back and forth, and the servo motor rotates accordingly.

.. image:: ../_static/imgs/19_Servo/Chapter19_16.png
    :align: center

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/19.2_Servo_Knob/19.2_Servo_Knob.py
    :linenos: 
    :language: python
    :lines: 1-16
    :dedent:

In this project, we will use GP26 of Raspberry Pi Pico to read the ADC value of the rotary potentiometer and then convert it to the angle value required by the servo and control the servo to rotate to the corresponding angle.