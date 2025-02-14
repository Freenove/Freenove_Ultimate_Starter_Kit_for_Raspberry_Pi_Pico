##############################################################################
Chapter L293D & Motor
##############################################################################

Project Control Motor with Potentiometer
******************************************************

Control the direction and speed of the motor with a potentiometer.

Component List
============================

+-----------------------------------------+------------------------------------------+
| Raspberry Pi Pico x1                    | USB Cable x1                             |
|                                         |                                          |
| |Chapter01_08|                          | |Chapter01_09|                           |
+-----------------------------------------+------------------------------------------+
| Breadboard x1                                                                      |
|                                                                                    |
| |Chapter01_10|                                                                     |
+-------------------------+-------------------------------+--------------------------+
| Rotary                  | Motor x1                      |  L293D x1                |
|                         |                               |                          |
| potentiometer x1        |                               |                          |
|                         |                               |                          |
| |Chapter18_00|          |  |Chapter18_01|               |  |Chapter18_02|          |
+-------------------------+---------------+---------------+--------------------------+
| Jumper                                  | Battery box x1                           |
|                                         |                                          |
|  |Chapter18_03|                         | |Chapter18_04|                           |
+-----------------------------------------+------------------------------------------+

.. |Chapter01_08| image:: ../_static/imgs/1_LED/Chapter01_08.png
.. |Chapter01_09| image:: ../_static/imgs/1_LED/Chapter01_09.png
.. |Chapter01_10| image:: ../_static/imgs/1_LED/Chapter01_10.png
.. |Chapter18_00| image:: ../_static/imgs/18_L293D_&_Motor/Chapter18_00.png
.. |Chapter18_01| image:: ../_static/imgs/18_L293D_&_Motor/Chapter18_01.png
.. |Chapter18_02| image:: ../_static/imgs/18_L293D_&_Motor/Chapter18_02.png
.. |Chapter18_03| image:: ../_static/imgs/18_L293D_&_Motor/Chapter18_03.png
.. |Chapter18_04| image:: ../_static/imgs/18_L293D_&_Motor/Chapter18_04.png

Component Knowledge
========================

L293D
------------------------

L293D is an IC Chip (Integrated Circuit Chip) with a 4-channel motor drive. You can drive a Unidirectional DC Motor with 4 ports or a Bi-Directional DC Motor with 2 ports or a Stepper Motor (Stepper Motors are covered later in this Tutorial).

.. image:: ../_static/imgs/18_L293D_&_Motor/Chapter18_05.png
    :align: center

Port description of L293D module is as follows:

+----------+--------------+----------------------------------------------------------------------------------------------------------------+
| Pin name |  Pin number  |                                                  Description                                                   |
+==========+==============+================================================================================================================+
| In x     | 2, 7, 10, 15 | Channel x digital signal input pin                                                                             |
+----------+--------------+----------------------------------------------------------------------------------------------------------------+
| Out x    | 3, 6, 11, 14 | Channel x output pin, input high or low level according to In x pin, get connected to +Vmotor or 0V            |
+----------+--------------+----------------------------------------------------------------------------------------------------------------+
| Enable1  | 1            | Channel 1 and channel 2 enable pin, high level enable                                                          |
+----------+--------------+----------------------------------------------------------------------------------------------------------------+
| Enable2  | 9            | Channel 3 and channel 4 enable pin, high level enable                                                          |
+----------+--------------+----------------------------------------------------------------------------------------------------------------+
| 0V       | 4, 5, 12, 13 | Power cathode (GND)                                                                                            |
+----------+--------------+----------------------------------------------------------------------------------------------------------------+
| +V       | 16           | Positive electrode (VCC) of power supply, supply voltage 3.0~36V                                               |
+----------+--------------+----------------------------------------------------------------------------------------------------------------+
| +Vmotor  | 8            | Positive electrode of load power supply, provide power supply for the Out pin x, the supply voltage is +3V~36V |
+----------+--------------+----------------------------------------------------------------------------------------------------------------+

For more details, please refer to the datasheet for this IC Chip.

When using L293D to drive DC motor, there are usually two connection options.

The following connection option uses one channel of the L239D, which can control motor speed through the PWM. However, the motor then can only rotate in one direction.

.. image:: ../_static/imgs/18_L293D_&_Motor/Chapter18_06.png
    :align: center

The following connection uses two channels of the L239D: one channel outputs the PWM wave, and the other channel connects to GND, therefore you can control the speed of the motor. When these two channel signals are exchanged, not only can they control the speed of motor, but also control the direction of the motor.

.. image:: ../_static/imgs/18_L293D_&_Motor/Chapter18_07.png
    :align: center

In practical use, the motor is usually connected to channels 1 and 2 by outputting different levels to in1 and in2 to control the rotational direction of the motor, and output to the PWM wave to Enable1 port to control the motor's rotational speed. If the motor is connected to channel 3 and 4 by outputting different levels to in3 and in4 to control the motor's rotation direction, and output to the PWM wave to Enable2 pin to control the motor's rotational speed.

Circuit
=============================

.. list-table::
   :width: 100%
   :align: center
   
   * -  Schematic diagram
   * -  |Chapter18_08|
   * -  Hardware connection. 
       
        :red:`If you need any support, please contact us via:` support@freenove.com
   * -  |Chapter18_09|
    
.. |Chapter18_08| image:: ../_static/imgs/18_L293D_&_Motor/Chapter18_08.png
.. |Chapter18_09| image:: ../_static/imgs/18_L293D_&_Motor/Chapter18_09.png

Sketch
==============================

Sketch_Control_Motor_by_L293D
---------------------------------------

.. image:: ../_static/imgs/18_L293D_&_Motor/Chapter18_10.png
    :align: center

Download code to Pico, rotate the potentiometer in one direction, and the motor speeds up slowly in one direction. Then rotate the potentiometer in the other direction and the motor will slow down to stop. Then rotate it in an inverse direction to accelerate the motor.

.. image:: ../_static/imgs/18_L293D_&_Motor/Chapter18_11.png
    :align: center

The following is the sketch:

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_18.1_Control_Motor_by_L293D/Sketch_18.1_Control_Motor_by_L293D.ino
    :linenos: 
    :language: c
    :lines: 1-49
    :dedent:

The ADC of Pico has a 10-bit accuracy, corresponding to a range from 0 to 1023. In this program, set the number 512 as the midpoint. If the value of ADC is less than 512, make the motor rotate in one direction. If the value of ADC is greater than 512, make the motor rotate in the other direction. Subtract 512 from the ADC value and take the absolute value and use this result as the speed of the motor.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_18.1_Control_Motor_by_L293D/Sketch_18.1_Control_Motor_by_L293D.ino
    :linenos: 
    :language: c
    :lines: 23-34
    :dedent:

Function driveMotor is used to control the rotation direction and speed of the motor. The dir represents direction while spd refers to speed.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_18.1_Control_Motor_by_L293D/Sketch_18.1_Control_Motor_by_L293D.ino
    :linenos: 
    :language: c
    :lines: 37-49
    :dedent: