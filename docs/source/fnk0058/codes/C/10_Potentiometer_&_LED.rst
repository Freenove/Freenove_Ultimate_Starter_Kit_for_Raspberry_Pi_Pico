##############################################################################
Chapter Potentiometer & LED
##############################################################################

We have learnt to use ADC in the previous chapter. In this chapter, we will combine PWM and ADC to use potentiometer to control LED, RGBLED and Neopixel.

.. _c_Soft_Light:

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

Sketch
=============================

Sketch_Softlight
------------------------------

.. image:: ../_static/imgs/10_Potentiometer_&_LED/Chapter10_02.png
    :align: center

Download the code to Pico, by turning the adjustable resistor to change the input voltage of GP26, Pico changes the output voltage of GP15 according to this voltage value, thus changing the brightness of the LED.

.. image:: ../_static/imgs/10_Potentiometer_&_LED/Chapter10_03.png
    :align: center

The following is the code:

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_10.1_SoftLight/Sketch_10.1_SoftLight.ino
    :linenos: 
    :language: c
    :dedent:

In the code, read the ADC value of potentiometer and map it to the duty cycle of PWM to control LED brightness.

:red:`If you have any concerns, please contact us via:` support@freenove.com

.. include:: 10.2_Potentiometer_&_LED.rst