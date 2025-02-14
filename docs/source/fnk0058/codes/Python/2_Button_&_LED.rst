
.. _button:

##############################################################################
Chapter Button & LED
##############################################################################

Usually, there are three essential parts in a complete automatic control device: INPUT, OUTPUT, and CONTROL. In last section, the LED module was the output part and Raspberry Pi Pico was the control part. In practical applications, we not only make LEDs blink, but also make a device sense the surrounding environment, receive instructions and then take the appropriate action such as lighting up LEDs, turning ON a buzzer and so on.

.. image:: ../_static/imgs/2_Button_&_LED/Chapter02_00.png
    :align: center

Next, we make a simple project: build a control system with button, LED and Raspberry Pi Pico. 

Input: Button

Control: Raspberry Pi Pico

Output: LED

Project Button & LED
*********************************

.. note::
    
    Raspberry Pi Pico, Raspberry Pi Pico W and Raspberry Pi Pico 2 only differ by wireless function, and are almost identical in other aspects. In this tutorial, except for the wireless function, other parts use Raspberry Pi Pico's map for tutorial demonstration.

In the project, we will control the LED state through a Push Button Switch. When the button is pressed, our LED will turn ON, and when it is released, the LED will turn OFF.

Component List
================================

+-----------------------------------------+-------------------------------------------------------+
| Raspberry Pi Pico x1                    | USB Cable x1                                          |
|                                         |                                                       |
| |Chapter01_08|                          | |Chapter01_09|                                        |
+-----------------------------------------+-------------------------------------------------------+
| Breadboard x1                                                                                   |
|                                                                                                 |
| |Chapter01_10|                                                                                  |
+----------------------+------------------+----------------+-----------------+--------------------+
| LED x1               | Resistor         | Jumper         |Resistor         | Push               |
|                      |                  |                |                 |                    |
|                      | 220Ω x1          |                |10kΩ x2          | button x1          |
|                      |                  |                |                 |                    |
| |Chapter01_11|       | |Chapter01_12|   | |Chapter02_12| | |Chapter02_01|  |  |Chapter02_11|    |
+----------------------+------------------+----------------+-----------------+--------------------+

.. |Chapter01_08| image:: ../_static/imgs/1_LED/Chapter01_08.png
.. |Chapter01_09| image:: ../_static/imgs/1_LED/Chapter01_09.png
.. |Chapter01_10| image:: ../_static/imgs/1_LED/Chapter01_10.png
.. |Chapter01_11| image:: ../_static/imgs/1_LED/Chapter01_11.png
.. |Chapter01_12| image:: ../_static/imgs/1_LED/Chapter01_12.png
.. |Chapter02_12| image:: ../_static/imgs/2_Button_&_LED/Chapter02_12.png
    :width: 50%
.. |Chapter02_01| image:: ../_static/imgs/2_Button_&_LED/Chapter02_01.png
.. |Chapter02_11| image:: ../_static/imgs/2_Button_&_LED/Chapter02_11.png

Component Knowledge
================================

Push button
-------------------------------

This type of Push Button Switch has four pins (2 Pole Switch). Two pins on the left are connected, and both left and right sides are the same per the illustration:

.. image:: ../_static/imgs/2_Button_&_LED/Chapter02_02.png
    :align: center

When the button on the switch is pressed, the circuit is completed (your project is Powered ON).

Circuit
===============================

.. list-table::
   :width: 100%
   :align: center
   
   * -  Schematic diagram
   * -  |Chapter02_03|
   * -  Hardware connection. 
       
        :red:`If you need any support, please contact us via:` support@freenove.com
   * -  |Chapter02_04|
    
.. |Chapter02_03| image:: ../_static/imgs/2_Button_&_LED/Chapter02_03.png
.. |Chapter02_04| image:: ../_static/imgs/2_Button_&_LED/Chapter02_04.png

.. note::
    
    :red:`To help users have a better experience when doing the projects, we have made some modifications to Pico's simulation diagram. Please note that there are certain differences between the simulation diagram and the actual board to avoid misunderstanding.`

Code
=================================

This project is designed to learn to control an LED with a push button switch. First, we need to read the state of the switch and then decide whether the LED is turned on or not based on it.

Move the program folder "Freenove_Ultimate_Starter_Kit_for_Raspberry_Pi_Pico/Python_Codes" to disk(D) in advance with the path of "D:/Micropython_Codes".

Open "Thonny", click "This computer" -> "D:" -> "Micropython_Codes" -> "02.1_ButtonAndLed" and double click "02.1_ButtonAndLed.py".

ButtonAndLed 
------------------------------

.. image:: ../_static/imgs/2_Button_&_LED/Chapter02_13.png
    :align: center

Click "Run current script" shown in the box of the above illustration, press the push button switch, LED turns ON; release the switch, LED turns OFF. Press Ctrl+C or click "Stop/Restart backend" to exit program. 

.. image:: ../_static/imgs/2_Button_&_LED/Chapter02_14.png
    :align: center

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/02.1_ButtonAndLed/02.1_ButtonAndLed.py
    :linenos: 
    :language: python
    :dedent:

In this project, we use the Pin module of the machine, so before initializing the Pin, we need to import this module first.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/02.1_ButtonAndLed/02.1_ButtonAndLed.py
    :linenos: 
    :language: python
    :lines: 1-1
    :dedent:

In the circuit connection, LED and Button are connected with GP15 and GP13 respectively, so define LED and button as 0 and 3 respectively.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/02.1_ButtonAndLed/02.1_ButtonAndLed.py
    :linenos: 
    :language: python
    :lines: 4-5
    :dedent:

Read the pin state of button with value() function. Press the button switch, the function returns low level and the result of "if" is true, and then LED will be turned ON; Otherwise, LED is turned OFF.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/02.1_ButtonAndLed/02.1_ButtonAndLed.py
    :linenos: 
    :language: python
    :lines: 9-12
    :dedent:

.. _Tablelamp:

Project MINI table lamp
**************************************

We will also use a Push Button Switch, LED and Raspberry Pi Pico to make a MINI Table Lamp but this will function differently: Press the button, the LED will turn ON, and pressing the button again, the LED turns OFF. The ON switch action is no longer momentary (like a door bell) but remains ON without needing to continually press on the Button Switch.

First, let us learn something about the push button switch.

Debounce for Push Button 
=====================================

When a Momentary Push Button Switch is pressed, it will not change from one state to another state immediately. Due to tiny mechanical vibrations, there will be a short period of continuous buffeting before it completely reaches another state too fast for Humans to detect but not for computer microcontrollers. The same is true when the push button switch is released. This unwanted phenomenon is known as "bounce".

.. image:: ../_static/imgs/2_Button_&_LED/Chapter02_15.png
    :align: center

Therefore, if we can directly detect the state of the Push Button Switch, there are multiple pressing and releasing actions in one pressing cycle. This buffeting will mislead the high-speed operation of the microcontroller to cause many false decisions. Therefore, we need to eliminate the impact of buffeting. Our solution: to judge the state of the button multiple times. Only when the button state is stable (consistent) over a period of time, can it indicate that the button is actually in the ON state (being pressed). 

This project needs the same components and circuits as we used in the previous section.

Code
================================

Tablelamp
--------------------------------

Move the program folder "Freenove_Ultimate_Starter_Kit_for_Raspberry_Pi_Pico/Python_Codes" to disk(D) in advance with the path of "D:/Micropython_Codes".

Open "Thonny", click "This computer" -> "D:" -> "Micropython_Codes" -> "02.2_TableLamp"and double click "02.2_TableLamp.py".

.. image:: ../_static/imgs/2_Button_&_LED/Chapter02_16.png
    :align: center

Click "Run current script" shown in the box of the above illustration, press the push button switch, LED turns ON; press it again, LED turns OFF. Press Ctrl+C or click "Stop/Restart backend" to exit file. 

.. image:: ../_static/imgs/2_Button_&_LED/Chapter02_17.png
    :align: center

:red:`If you have any concerns, please contact us via:` support@freenove.com

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/02.2_TableLamp/02.2_TableLamp.py
    :linenos: 
    :language: python
    :dedent:

When the button is detected to be pressed, delay 20ms to avoid the effect of bounce, and then check whether the button has been pressed again. If so, the conditional statement will be executed, otherwise it will not be executed.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/02.2_TableLamp/02.2_TableLamp.py
    :linenos: 
    :language: python
    :lines: 14-20
    :dedent:

Customize a function and name it reverseGPIO(), which reverses the output level of the LED.

.. literalinclude:: ../../../freenove_Kit/Python/Python_Codes/02.2_TableLamp/02.2_TableLamp.py
    :linenos: 
    :language: python
    :lines: 7-11
    :dedent: