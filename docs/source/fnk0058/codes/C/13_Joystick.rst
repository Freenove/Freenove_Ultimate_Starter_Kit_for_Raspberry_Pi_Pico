##############################################################################
Chapter 13 Joystick
##############################################################################

In the previous chapter, we have learned how to use rotary potentiometer. Now, let us learn a new electronic module Joystick that works on the same principle as rotary potentiometer.

Project Joystick
********************************

In this project, we will read the output data of a Joystick and display it to the Terminal screen.

Component List
=================================

+-----------------------------------------+----------------+
| Raspberry Pi Pico x1                    | USB Cable x1   |
|                                         |                |
| |Chapter01_08|                          | |Chapter01_09| |
+-----------------------------------------+----------------+
| Breadboard x1                                            |
|                                                          |
| |Chapter01_10|                                           |
+-----------------------------------------+----------------+
| Joystick x1                             | Jumper         |
|                                         |                |
|  |Chapter13_00|                         | |Chapter01_13| |
+-----------------------------------------+----------------+

.. |Chapter01_08| image:: ../_static/imgs/1_LED/Chapter01_08.png
.. |Chapter01_09| image:: ../_static/imgs/1_LED/Chapter01_09.png
.. |Chapter01_10| image:: ../_static/imgs/1_LED/Chapter01_10.png
.. |Chapter01_13| image:: ../_static/imgs/1_LED/Chapter01_13.png
.. |Chapter13_00| image:: ../_static/imgs/13_Joystick/Chapter13_00.png

Component Knowledge
================================

Joystick
------------------------------

A Joystick is a kind of input sensor used with your fingers. You should be familiar with this concept already as they are widely used in gamepads and remote controls. It can receive input on two axes (Y and or X) at the same time (usually used to control direction on a two dimensional plane). In addition, it has a third direction capability by pressing down (Z axis/direction).

.. image:: ../_static/imgs/13_Joystick/Chapter13_01.png
    :align: center

This is accomplished by incorporating two rotary potentiometers inside the Joystick Module at 90 degrees of each other, placed in such a manner as to detect shifts in direction in two directions simultaneously and with a Push Button Switch in the "vertical" axis, which can detect when a User presses on the Joystick.

.. image:: ../_static/imgs/13_Joystick/Chapter13_02.png
    :align: center

When the Joystick data is read, there are some differences between the axes: data of X and Y axes is analog, which needs to use the ADC. The data of the Z axis is digital, so you can directly use the GPIO to read this data or you have the option to use the ADC to read this.

Circuit
===============================

.. list-table::
   :width: 100%
   :align: center
   
   * -  Schematic diagram
   * -  |Chapter13_03|
   * -  Hardware connection. 
       
        :red:`If you need any support, please contact us via:` support@freenove.com
   * -  |Chapter13_04|
    
.. |Chapter13_03| image:: ../_static/imgs/13_Joystick/Chapter13_03.png
.. |Chapter13_04| image:: ../_static/imgs/13_Joystick/Chapter13_04.png

Sketch
=================================

In this project's code, we will read the ADC values of X and Y axes of the joystick, and read digital quality of the Z axis, then display these out in terminal.

Sketch_Joystick
---------------------------------

.. image:: ../_static/imgs/13_Joystick/Chapter13_06.png
    :align: center

Download the code to Pico, open the serial port monitor, the baud rate is 115200, as shown in the picture below, shift (moving) the joystick or pressing it down will make the data change.

.. image:: ../_static/imgs/13_Joystick/Chapter13_05.png
    :align: center

The following is the code:

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_13.1_Joystick/Sketch_13.1_Joystick.ino
    :linenos: 
    :language: c
    :dedent:

In the code, configure xyzPins[2] to pull-up input mode. In loop(), use analogRead () to read the value of axes X and Y and use digitalRead () to read the value of axis Z, and then display them.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_13.1_Joystick/Sketch_13.1_Joystick.ino
    :linenos: 
    :language: c
    :lines: 10-10
    :dedent:

In the code, configure xyzPins[2] to pull-up input mode. In loop (), use analogRead () to read the value of axes X and Y and use digitalRead () to read the value of axis Z, and then display them.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_13.1_Joystick/Sketch_13.1_Joystick.ino
    :linenos: 
    :language: c
    :lines: 14-18
    :dedent: