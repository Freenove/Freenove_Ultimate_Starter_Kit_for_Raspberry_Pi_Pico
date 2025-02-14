##############################################################################
Chapter Control LED with Web (Only for Pico W)
##############################################################################

In this chapter, we will use PICO W to make a simple smart home. We will learn how to control LED lights through web pages.

Project Control the LED with Web
************************************************

In this project, we need to build a Web Service and then use PICO W to control the LED through the Web browser of the phone or PC. Through this example, you can remotely control the appliances in your home to achieve smart home.

Component List
=============================

+-----------------------------------------+------------------------------------------+
| Raspberry Pi Pico x1                    | Micro USB Wire x1                        |
|                                         |                                          |
| |Chapter01_08|                          | |Chapter01_09|                           |
+-----------------------------------------+------------------------------------------+

.. |Chapter01_08| image:: ../_static/imgs/1_LED/Chapter01_08.png
.. |Chapter01_09| image:: ../_static/imgs/1_LED/Chapter01_09.png

Component knowledge
===============================

HTML
-------------------------------

Hypertext Markup Language (HTML) is a standard Markup Language for creating web pages. It includes a set of tags that unify documents on the network and connect disparate Internet resources into a logical whole.HTML text is descriptive text composed of HTML commands that describe text, graphics, animations, sounds, tables, links, etc. The extension of the HTML file is HTM or HTML. Hypertext is a way to organize information. It uses hyperlinks to associate words and charts in Text with other information media. These related information media may be in the same Text, other files, or files located on a remote computer. This way of organizing information connects the information resources distributed in different places, which is convenient for people to search and retrieve information.

The nature of the Web is hypertext Markup Language (HTML), which can be combined with other Web technologies (e.g., scripting languages, common gateway interfaces, components, etc.) to create powerful Web pages. Thus, Hypertext Markup Language (HTML) is the foundation of World Wide Web (Web) programming, that is, the World Wide Web is based on hypertext. Hypertext Markup Language is called hypertext Markup language because the text contains so-called "hyperlink" points.

You can build your own WEB site using HTML, which runs on the browser and is parsed by the browser.

Example analysis is shown in the figure below:

.. image:: ../_static/imgs/32_Control_LED_with_Web_(Only_for_Pico_W)/Chapter32_00.png
    :align: center

**<!DOCTYPE html>:** Declare it as an HTML5 document

**<html>:** Is the root element of an HTML page

**<head>:** Contains meta data for the document, such as &lt; meta charset="utf-8"&gt; Define the web page encoding format to UTF-8.

**<title>:** Notes the title of the document

**<body>:** Contains visible page content

**<h1>:** Define a big heading

**<p>:** Define a paragraph

For more information, please visit: https://developer.mozilla.org/en-US/docs/Web/HTML

Circuit
===========================

Connect Pico W to the computer using the USB cable.

.. image:: ../_static/imgs/30_WiFi_Working_Modes_(Only_for_Pico_W)/Chapter30_01.png
    :align: center

Sketch
==============================

Sketch_Control_the_LED_with_Web
-----------------------------------------

.. image:: ../_static/imgs/32_Control_LED_with_Web_(Only_for_Pico_W)/Chapter32_01.png
    :align: center

Download the code to PICO W, open the serial port monitor, set the baud rate to 115200, and you can use it to measure the distance between the ultrasonic module and the object. As shown in the following figure: 

.. image:: ../_static/imgs/32_Control_LED_with_Web_(Only_for_Pico_W)/Chapter32_02.png
    :align: center

When PICO W successfully connects to "ssid_Router", serial monitor will print out the IP address assigned to PICO W by the router. Access http://192.168.1.23 in a computer browser on the LAN. As shown in the following figure:

.. image:: ../_static/imgs/32_Control_LED_with_Web_(Only_for_Pico_W)/Chapter32_03.png
    :align: center

You can click the corresponding button to control the LED on and off.

The following is the program code:

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_32.1_Control_the_LED_with_Web/Sketch_32.1_Control_the_LED_with_Web.ino    
    :linenos: 
    :language: c
    :lines: 1-120
    :dedent:

Include the WiFi Library header file of PICO W.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_32.1_Control_the_LED_with_Web/Sketch_32.1_Control_the_LED_with_Web.ino    
    :linenos: 
    :language: c
    :lines: 11-11
    :dedent:

Enter correct router name and password.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_32.1_Control_the_LED_with_Web/Sketch_32.1_Control_the_LED_with_Web.ino    
    :linenos: 
    :language: c
    :lines: 14-15
    :dedent:

Set PICO W in Station mode and connect it to your router.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_32.1_Control_the_LED_with_Web/Sketch_32.1_Control_the_LED_with_Web.ino    
    :linenos: 
    :language: c
    :lines: 40-40
    :dedent:

Check whether PICO W has connected to router successfully every 0.5s.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_32.1_Control_the_LED_with_Web/Sketch_32.1_Control_the_LED_with_Web.ino    
    :linenos: 
    :language: c
    :lines: 41-44
    :dedent:

Serial monitor prints out the IP address assigned to PICO W.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_32.1_Control_the_LED_with_Web/Sketch_32.1_Control_the_LED_with_Web.ino    
    :linenos: 
    :language: c
    :lines: 49-49
    :dedent:

Click the button on the web page to control the LED light on and off.

.. literalinclude:: ../../../freenove_Kit/C/Sketches/Sketch_32.1_Control_the_LED_with_Web/Sketch_32.1_Control_the_LED_with_Web.ino    
    :linenos: 
    :language: c
    :lines: 75-84
    :dedent: