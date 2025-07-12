##############################################################################
Chapter 74HC595 & LED Matrix
##############################################################################

Thus far, we have learned how to use the 74HC595 IC Chip to control the Bar Graph LED and the 7-Segment Display. We will now use 74HC595 IC Chips to control an LED Matrix.

Project LED Matrix
***************************************

In this project, we will use two 74HC595 IC chips to control a monochrome (one color) (8X8) LED Matrix to make it display both simple graphics and characters.

Component List
================================

+-----------------------------------------+---------------------------------+
| Raspberry Pi Pico x1                    | USB Cable x1                    |
|                                         |                                 |
| |Chapter01_08|                          | |Chapter01_09|                  |
+-----------------------------------------+---------------------------------+
| Breadboard x1                                                             |
|                                                                           |
| |Chapter01_10|                                                            |
+----------------------+------------------+----------------+----------------+
| 74HC595 x2           | Resistor         | Jumper         |8*8 LED         |
|                      |                  |                |                |
|                      | 220Ω x8          |                |Matrix x1       |
|                      |                  |                |                |
| |Chapter14_00|       | |Chapter01_12|   | |Chapter01_13| | |Chapter16_00| |
+----------------------+------------------+----------------+----------------+

.. |Chapter01_08| image:: ../_static/imgs/1_LED/Chapter01_08.png
.. |Chapter01_09| image:: ../_static/imgs/1_LED/Chapter01_09.png
.. |Chapter01_10| image:: ../_static/imgs/1_LED/Chapter01_10.png
.. |Chapter01_12| image:: ../_static/imgs/1_LED/Chapter01_12.png
.. |Chapter01_13| image:: ../_static/imgs/1_LED/Chapter01_13.png
.. |Chapter14_00| image:: ../_static/imgs/14_74HC595_&_LED_Bar_Graph/Chapter14_00.png
.. |Chapter16_00| image:: ../_static/imgs/16_74HC595_&_LED_Matrix/Chapter16_00.png    

Component Knowledge
===============================

LED matrix
-------------------------------

An LED Matrix is a rectangular display module that consists of a uniform grid of LEDs. The following is an 8X8 monochrome (one color) LED Matrix containing 64 LEDs (8 rows by 8 columns).

.. image:: ../_static/imgs/16_74HC595_&_LED_Matrix/Chapter16_01.png
    :align: center

In order to facilitate the operation and reduce the number of ports required to drive this component, the Positive Poles of the LEDs in each row and Negative Poles of the LEDs in each column are respectively connected together inside the LED Matrix module, which is called a Common Anode. There is another arrangement type. Negative Poles of the LEDs in each row and the Positive Poles of the LEDs in each column are respectively connected together, which is called a Common Cathode.

The LED Matrix that we use in this project is a Common Anode LED Matrix.

.. image:: ../_static/imgs/16_74HC595_&_LED_Matrix/Chapter16_02.png
    :align: center

Here is how a Common Anode LED Matrix works. First, choose 16 ports on Raspberry Pi Pico to connect to the 16 ports of LED Matrix. Configure one port in columns for low level, which makes that column the selected port. Then configure the eight port in the row to display content in the selected column. Add a delay value and then select the next column that outputs the corresponding content. This kind of operation by column is called Scan. If you want to display the following image of a smiling face, you can display it in eight columns, and each column is represented by one byte.

.. image:: ../_static/imgs/16_74HC595_&_LED_Matrix/Chapter16_03.png
    :align: center

+--------+-----------+-------------+
| Column |  Binary   | Hexadecimal |
+========+===========+=============+
| 1      | 0001 1100 | 0x1c        |
+--------+-----------+-------------+
| 2      | 0010 0010 | 0x22        |
+--------+-----------+-------------+
| 3      | 0101 0001 | 0x51        |
+--------+-----------+-------------+
| 4      | 0100 0101 | 0x45        |
+--------+-----------+-------------+
| 5      | 0100 0101 | 0x45        |
+--------+-----------+-------------+
| 6      | 0101 0001 | 0x51        |
+--------+-----------+-------------+
| 7      | 0010 0010 | 0x22        |
+--------+-----------+-------------+
| 8      | 0001 1100 | 0x1c        |
+--------+-----------+-------------+

To begin, display the first column, then turn off the first column and display the second column. (and so on) .... turn off the seventh column and display the eighth column, and then start the process over from the first column again like the control of LED Bar Graph project. The whole process will be repeated rapidly in a loop. Due to the principle of optical afterglow effect and the vision persistence effect in human sight, we will see a picture of a smiling face directly rather than individual columns of LEDs turned ON one column at a time (although in fact this is the reality we cannot perceive).

Then, to save the number of GPIO, we use a 74HC595. When the first column is turned ON, set the lights that need to be displayed in the first column to "1", otherwise to "0", as shown in the above example, where the value of the first column is 0x1c. This value is sent to 74HC595 to control the display of the first column of the LEDMatrix. Following the above idea, turn OFF the display of the first column, then turn ON the second column, and then send the value of the second column to 74HC595...... Until each column is displayed, the LEDMatrix is displayed again from the first column.

Circuit
========================

In circuit of this project, the power pin of the 74HC595 IC Chip is connected to 3.3V. It can also be connected to 5V to make LED Matrix brighter.

.. list-table::
   :width: 100%
   :align: center
   
   * -  Schematic diagram
   * -  |Chapter16_04|
   * -  Hardware connection. 
       
        :red:`If you need any support, please contact us via:` support@freenove.com
   * -  |Chapter16_05|
    
.. |Chapter16_04| image:: ../_static/imgs/16_74HC595_&_LED_Matrix/Chapter16_04.png
.. |Chapter16_05| image:: ../_static/imgs/16_74HC595_&_LED_Matrix/Chapter16_05.png

Sketch
=========================

.. raw:: html

    <iframe style="display: block; margin: 0 auto;" height="421.875" width="750" src="https://www.youtube.com/embed/KtbcngNopgk" frameborder="0" allowfullscreen></iframe>

The following code will make LED matrix display a smiling face, and then display scrolling character "0-F".

Sketch_LED_Matrix
--------------------------

.. image:: ../_static/imgs/16_74HC595_&_LED_Matrix/Chapter16_06.png
    :align: center

Download the code to Pico, and the LED matrix display a smiling face, and then display characters "0 to F" scrolling in a loop on the LED matrix.

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_16.1_LED_Matrix/Sketch_16.1_LED_Matrix.ino
    :linenos: 
    :language: c
    :dedent:

The first "for" loop in the "while" loop is used to display a static smile. Displaying column information from left to right, one column at a time with a total of eight columns. This repeats 500 times to ensure sufficient display time.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_16.1_LED_Matrix/Sketch_16.1_LED_Matrix.ino
    :linenos: 
    :language: c
    :lines: 45-56
    :dedent:

The second "for" loop is used to display scrolling characters "0 to F", for a total of 17* 8 = 144 columns. Displaying the 0-8 column, then the 1-9 column, then the 2-10 column... and so on…128-136 column in consecutively to achieve the scrolling effect. The display of each frame is repeated a certain number of times and the more repetitions, the longer the single frame display will be and the slower the scrolling movement.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_16.1_LED_Matrix/Sketch_16.1_LED_Matrix.ino
    :linenos: 
    :language: c
    :lines: 58-69
    :dedent:

In this example, we use two 74HC595 to drive the LED matrix, requiring only 3 pins, so that we could save the rest of 13 pins.