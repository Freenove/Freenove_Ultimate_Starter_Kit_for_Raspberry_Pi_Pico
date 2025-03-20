##############################################################################
Chapter Photoresistor & LED
##############################################################################

In this chapter, we will learn how to use photoresistor.

Project Control LED through Photoresistor
********************************************************

A Photoresistor is very sensitive to the amount of light present. We can take advantage of the characteristic to make a night lamp with the following function: when the ambient light is less (darker environment) the LED will automatically become brighter to compensate and when the ambient light is greater (brighter environment) the LED will automatically dim to compensate.

Component List
=======================================

+-----------------------------------------+------------------+
| Raspberry Pi Pico x1                    |   USB Cable x1   |
|                                         |                  |
| |Chapter01_08|                          |   |Chapter01_09| |
+-----------------------------------------+------------------+
| Breadboard x1                                              |
|                                                            |
| |Chapter01_10|                                             |
+----------------------+------------------+------------------+
| Photoresistor x1     | Resistor 10kΩ x2 | Jumper           |
|                      |                  |                  |
| |Chapter11_00|       | |Chapter02_01|   |   |Chapter01_13| |
+----------------------+------------------+------------------+
| LED x1               | Resistor 220Ω x1                    |
|                      |                                     |
| |Chapter01_11|       | |Chapter01_12|                      |
+----------------------+-------------------------------------+

.. |Chapter01_08| image:: ../_static/imgs/1_LED/Chapter01_08.png
.. |Chapter01_09| image:: ../_static/imgs/1_LED/Chapter01_09.png
.. |Chapter01_10| image:: ../_static/imgs/1_LED/Chapter01_10.png
.. |Chapter01_11| image:: ../_static/imgs/1_LED/Chapter01_11.png
.. |Chapter11_00| image:: ../_static/imgs/11_Photoresistor_&_LED/Chapter11_00.png
.. |Chapter01_12| image:: ../_static/imgs/1_LED/Chapter01_12.png
.. |Chapter01_13| image:: ../_static/imgs/1_LED/Chapter01_13.png
.. |Chapter02_01| image:: ../_static/imgs/2_Button_&_LED/Chapter02_01.png

Component Knowledge
============================

Photoresistor
------------------------------

Photoresistor is simply a light sensitive resistor. It is an active component that decreases resistance with respect to receiving luminosity (light) on the component's light sensitive surface. Photoresistor's resistance value will change in proportion to the ambient light detected. With this characteristic, we can use a Photoresistor to detect light intensity. The Photoresistor and its electronic symbol are as follows.

.. image:: ../_static/imgs/11_Photoresistor_&_LED/Chapter11_01.png
    :align: center

The circuit below is used to detect the change of a Photoresistor's resistance value:

.. image:: ../_static/imgs/11_Photoresistor_&_LED/Chapter11_02.png
    :align: center

In the above circuit, when a Photoresistor's resistance value changes due to a change in light intensity, the voltage between the Photoresistor and Resistor R1 will also change. Therefore, the intensity of the light can be obtained by measuring this voltage.

Circuit
=========================

The circuit of this project is similar to SoftLight. The only difference is that the input signal is changed from a potentiometer to a combination of a photoresistor and a resistor.

.. list-table::
   :width: 100%
   :align: center
   
   * -  Schematic diagram
   * -  |Chapter11_03|
   * -  Hardware connection. 
       
        :red:`If you need any support, please contact us via:` support@freenove.com
   * -  |Chapter11_04|
    
.. |Chapter11_03| image:: ../_static/imgs/11_Photoresistor_&_LED/Chapter11_03.png
.. |Chapter11_04| image:: ../_static/imgs/11_Photoresistor_&_LED/Chapter11_04.png

Code
=========================

Codes of this project is logically the same as the project :ref:`Soft_Light`

Open "Thonny", click "This computer" -> "D:" -> "Micropython_Codes" -> "11.1_Photoresistor" and double click "11.1_Photoresistor.py".

Photoresistor
--------------------------

.. image:: ../_static/imgs/11_Photoresistor_&_LED/Chapter11_09.png
    :align: center

Click "Run current script". Cover the photoresistor with your hands or illuminate it with lights, the brightness of LEDs will change. 

.. list-table::
   :width: 100%
   :align: center
   
   * -  Fully cover the photoresistor:
   * -  |Chapter11_10|
   * -  Half cover the photoresistor:
   * -  |Chapter11_11|
   * -  Not cover the photoresistor:
   * -  |Chapter11_12|

.. |Chapter11_10| image:: ../_static/imgs/11_Photoresistor_&_LED/Chapter11_10.png
.. |Chapter11_11| image:: ../_static/imgs/11_Photoresistor_&_LED/Chapter11_11.png
.. |Chapter11_12| image:: ../_static/imgs/11_Photoresistor_&_LED/Chapter11_12.png

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/11.1_Photoresistor/11.1_Photoresistor.py
    :linenos: 
    :language: python
    :dedent: