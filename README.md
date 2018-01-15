# KmlTool

Retrieve coordinates from a KML file

**KML Tool** is a program designed to retrieve coordinates from Google Earth's Keyhole Markup Language files (KML).

The program interface has a very minimalistic interface as shown in the figure. At the top of the program should be the menu bar followed by a field to select a KML. Below there is a button to retrieve coordinates followed by a text field to show the coordinates.

# Installation and requirements

At the moment no installer is provided.

This program does not have any special requirements, but it's designed to work in any modern computer using a graphical interface, so at least you should have:

* SO: Windows 10, macOS Sierra 10.12, Linux 4.4 (64 bits recommended)
* 50 MB free space in hard drive
* Processor 1.2 GHz
* 1 GB of RAM
* Keyboard, mouse and screen

# Features

Some technical features are:

* This program is coded in the C++ programming language.
* The Qt5 libraries are used for the graphical interface.
* The program can retrieve coordinates text from KML files.
* Supported place marks are: Point, LineString and Polygon.

# Usage

The procedure to retrieve coordinates from a KML file is very simple.

## Retrieving coordinates

* Use the browse button (the one with the three dots "...") to locate a file from your computer, only KML files can be selected.
* You can also use the menu **File > Open**
* The path and name of the selected file will appear in the text field.
* Use button **Retrieve** to extract the coordinates from the selected KML file.
* The text of the coordinates should appear in the text field below.
* You can copy, edit or save the coordinates as desired.
* To save the coordinates to a text file use the menu **File > Save**

# License

``` KML Tool

Retrieve coordinates from a KML file

Copyright (C) 2018 Eduardo Jiménez <[ecoslacker@irriapps.com]>

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2 of the License, or (at your option)
any later version.


This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
more details.
```
