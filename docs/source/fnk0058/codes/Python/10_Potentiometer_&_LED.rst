##############################################################################
Chapter Potentiometer & LED
##############################################################################

We have learnt to use ADC in the previous chapter. In this chapter, we will combine PWM and ADC to use potentiometer to control LED, RGBLED and Neopixel.

.. _p_Soft_Light:

Project Soft Light
**************************************

In this project, we will make a soft light. We will use an ADC Module to read ADC values of a potentiometer and map it to duty cycle of the PWM used to control the brightness of an LED. Then you can change the brightness of an LED by adjusting the potentiometer.

Component List
=================================

+-------------------------------------------------------------------+------------------+
| Raspberry Pi Pico x1                                              |   USB Cable x1   |
|                                                                   |                  |
| |Chapter01_08|                                                    |   |Chapter01_09| |
+-------------------------------------------------------------------+------------------+
| Breadboard x1                                                                        |
|                                                                                      |
| |Chapter01_10|                                                                       |
+-------------------------+---------------------+-------------------+------------------+
| Rotary                  | Resistor            | LED x1            |   Jumper         |
|                         |                     |                   |                  |
| potentiometer x1        | 220Ω x1             |                   |                  |
|                         |                     |                   |                  |
|  |Chapter09_00|         | |Chapter01_12|      | |Chapter01_11|    |   |Chapter01_13| |
+-------------------------+---------------------+-------------------+------------------+

.. |Chapter01_08| image:: ../_static/imgs/1_LED/Chapter01_08.png
.. |Chapter01_09| image:: ../_static/imgs/1_LED/Chapter01_09.png
.. |Chapter01_10| image:: ../_static/imgs/1_LED/Chapter01_10.png
.. |Chapter01_11| image:: ../_static/imgs/1_LED/Chapter01_11.png
.. |Chapter01_12| image:: ../_static/imgs/1_LED/Chapter01_12.png
.. |Chapter01_13| image:: ../_static/imgs/1_LED/Chapter01_13.png
.. |Chapter09_00| image:: ../_static/imgs/9_AD_Converter/Chapter09_00.png

Circuit
===============================

.. list-table::
   :width: 100%
   :align: center
   
   * -  Schematic diagram
   * -  |Chapter10_00|
   * -  Hardware connection. 
       
        :red:`If you need any support, please contact us via:` support@freenove.com
   * -  |Chapter10_01|
    
.. |Chapter10_00| image:: ../_static/imgs/10_Potentiometer_&_LED/Chapter10_00.png
.. |Chapter10_01| image:: ../_static/imgs/10_Potentiometer_&_LED/Chapter10_01.png

Code
=============================

Open "Thonny", click "This computer" -> "D:" -> "Micropython_Codes" -> "10.1_Soft_LED" and double click "10.1_Soft_LED.py". 

Soft_LED
-----------------------------

.. image:: ../_static/imgs/10_Potentiometer_&_LED/Chapter10_12.png
    :align: center

Click "Run current script". Rotate the handle of potentiometer and the brightness of LED will change correspondingly. Press Ctrl+C or click "Stop/Restart backend" to exit the program.

.. image:: ../_static/imgs/10_Potentiometer_&_LED/Chapter10_13.png
    :align: center

:red:`If you have any concerns, please contact us via:` support@freenove.com

The following is the code:

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/10.1_Soft_LED/10.1_Soft_LED.py
    :linenos: 
    :language: python
    :lines: 1-12
    :dedent:

In the code, read the ADC value of potentiometer and map it to the duty cycle of PWM to control LED brightness.

Project Soft Colorful Light 
********************************************

In this project, three potentiometers are used to control the RGB LED and in principle, it is the same as the Soft Light project. Namely, read the voltage value of the potentiometer and then convert it to PWM used to control LED brightness. Difference is that the original project only controlled one LED, but this project required (3) RGB LEDs.

Component List
=======================================

+-------------------------------------------------------------------+------------------+
| Raspberry Pi Pico x1                                              |   USB Cable x1   |
|                                                                   |                  |
| |Chapter01_08|                                                    |   |Chapter01_09| |
+-------------------------------------------------------------------+------------------+
| Breadboard x1                                                                        |
|                                                                                      |
| |Chapter01_10|                                                                       |
+-------------------------+---------------------+-------------------+------------------+
| Rotary                  | Resistor            | RGBLED x1         |   Jumper         |
|                         |                     |                   |                  |
| potentiometer x3        | 220Ω x3             |                   |                  |
|                         |                     |                   |                  |
|  |Chapter09_00|         | |Chapter01_12|      | |Chapter05_00|    |   |Chapter01_13| |
+-------------------------+---------------------+-------------------+------------------+

.. |Chapter05_00| image:: ../_static/imgs/5_RGBLED/Chapter05_00.png

Circuit
======================================

.. list-table::
   :width: 100%
   :align: center
   
   * -  Schematic diagram
   * -  |Chapter10_04|
   * -  Hardware connection. 
       
        :red:`If you need any support, please contact us via:` support@freenove.com
   * -  |Chapter10_05|
    
.. |Chapter10_04| image:: ../_static/imgs/10_Potentiometer_&_LED/Chapter10_04.png
.. |Chapter10_05| image:: ../_static/imgs/10_Potentiometer_&_LED/Chapter10_05.png

Code
====================================

Open "Thonny", click "This computer" -> "D:" -> "Micropython_Codes" -> "10.2_Soft_Colorful_Light" and double click "10.2_Soft_Colorful_Light.py". 

Soft_Colorful_Light
------------------------------------

.. image:: ../_static/imgs/10_Potentiometer_&_LED/Chapter10_14.png
    :align: center

Click "Run current script" and control the change of RGBLED color by rotating the handles of three rotary potentiometers. Press Ctrl+C or click "Stop/Restart backend" to exit the program.

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/10.2_Soft_Colorful_Light/10.2_Soft_Colorful_Light.py
    :linenos: 
    :language: python
    :dedent:

In the code, you can read the ADC values of the three potentiometers and map it into a PWM duty cycle to control the three LED elements to vary the color of their respective RGB LED.

Project Soft Rainbow Light
****************************************

In this project, we use a potentiometer to control Freenove 8 RGBLED Module.

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
+-------------------------+---------------+----------------+
| Rotary potentiometer x1 | Freenove 8 RGB| Jumper         |
|                         |               |                |
|                         | LED Module x1 |                |
|                         |               |                |
|  |Chapter09_00|         | |Chapter06_00|| |Chapter10_07| |
+-------------------------+---------------+----------------+
 
.. |Chapter10_07| image:: ../_static/imgs/10_Potentiometer_&_LED/Chapter10_07.png
.. |Chapter06_00| image:: ../_static/imgs/6_NeoPixel/Chapter06_00.png

Circuit
======================================

.. list-table::
   :width: 100%
   :align: center
   
   * -  Schematic diagram
   * -  |Chapter10_08|
   * -  Hardware connection. 
       
        :red:`If you need any support, please contact us via:` support@freenove.com
   * -  |Chapter10_09|
    
.. |Chapter10_08| image:: ../_static/imgs/10_Potentiometer_&_LED/Chapter10_08.png
.. |Chapter10_09| image:: ../_static/imgs/10_Potentiometer_&_LED/Chapter10_09.png

Code
====================================

Open "Thonny", click "This computer" -> "D:" -> "Micropython_Codes" -> "10.3_Soft_Rainbow_Light". Select"neopixel.py", right click to select "Upload to /", wait for "neopixel.py" to be uploaded to Raspberry Pi Pico and then double click "10.3_Soft_Rainbow_Light.py".

Soft_Rainbow_Light
------------------------------------

.. image:: ../_static/imgs/10_Potentiometer_&_LED/Chapter10_15.png
    :align: center

Click "Run current script". Rotate the handle of potentiometer and the color of the lights will change.

.. image:: ../_static/imgs/10_Potentiometer_&_LED/Chapter10_16.png
    :align: center

:red:`If you have any concerns, please contact us via:` support@freenove.com

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/10.3_Soft_Rainbow_Light/10.3_Soft_Rainbow_Light.py
    :linenos: 
    :language: python
    :dedent:

The logic of the code is basically the same as the previous project :ref:`Rainbow Light<Rainbow>`. The difference is that in this code, the starting point of the color is controlled by the potentiometer.

.. include:: 10.2_Potentiometer_&_LED.rst