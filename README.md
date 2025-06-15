# Introduction to PIC Programming Using C
## Programming a Super Simple LED Switch

The code provided here is for a PIC programming project series that I made for <a href="https://motbots.com/super-simple-led-switch-series-pic-project/" target="_blank" rel="noopener noreferrer nofollow">Motbots</a>
that uses a PIC18F4525 microcontroller to control an LED using a couple of tactile momentarty push-button switches. For this project there are explainations on:

* how to setup Microchip's MPLAB software,
* preliminaries for knowing what a PICkit is and what it’s for,
* information about the PIC18F4525 microcontroller and the pins we use for this project,
* how we use the datasheet to properly code for the pins used,
* how to prototype the PIC circuit on a breadboard,
* a thorough explanation is given of the code, line-by-line,
* and many other key information and material is given.

## A Three-Part PIC Project

As mentioned, this PIC project is divided into three managable parts. The following is s brief synopsis of each part of the Motbots <a href="https://motbots.com/super-simple-led-switch-series-pic-project/" target="_blank" rel="noopener noreferrer nofollow">Super Simple LED Switch PIC Project Series</a>:

### :open_book: Part 1 - The Preliminaries

In <a href="https://motbots.com/intro-to-pic-programming-using-c-super-simple-led-switch-part-1/" target="_blank" rel="noopener noreferrer nofollow">Part 1</a> of the series, we’ll discuss some basics, like what a PICkit is, and why we need a PICkit.
We’ll talk about the PIC18F4525 microcontroller and Microchip’s MPLAB software. I’ll show you how to install the MPLAB software and how to set it up.
We’ll also discuss things we’ll need to know in C, and other important topics we’ll need to know. The following bullet-points are some headings from Part 1 of this project:

* **Using the Ol’ PICkit 3 In-Circuit Debugger/Programmer**
* **Why Do We Need a PICkit?**
* **The PIC18F4525 8-bit Microcontroller**
* **But Isn’t the PICkit 3 Outdated?**
* **MPLAB X v6.15**
* **What We Need to Know in C**
* **Getting Familiar With the Hexadecimal Number System**

### :hammer_and_wrench: Part 2 - The Project

In <a href="https://motbots.com/intro-to-pic-programming-using-c-super-simple-led-switch-part-2/" target="_blank" rel="noopener noreferrer nofollow">Part 2</a> of the series, we’ll get into building the prototype circuit – first going over the parts
and tools we’ll need, then we’ll discuss about power supplies, then we’ll get into what a flowchart is and why they’re good to use for programming projects, like this one. The following bullet-points are some headings from Part 2 of this project:

* **Parts List**
* **Tools List**
* **The Flowchart**
* **The PIC18F4525 Datasheet**
* **Schematic for the Prototype Circuit**
* **Assembling the Prototype Circuit**

### :computer: Part 3 - The Code

In <a href="https://motbots.com/intro-to-pic-programming-using-c-super-simple-led-switch-part-3/" target="_blank" rel="noopener noreferrer nofollow">Part 3</a> of the series, we’ll finish our discussion by going over the code, line-by-line,
and how it works. We’ll even go over some common errors when trying to connect the PICkit device to the MPLAB IPE. Part 3, is where we’ll finish up the project as a whole. Near the end, we’ll test the circuit and hopefully have a working circuit.
The following bullet-points are some headings from Part 3 of this project:

* **First Steps to Programming Your PIC**
* **The Code**
* **The Code Explained**
* **Placing the PIC184525 MCU Into the Programmer Seat Adapter**
* **Programmer Adapter Jumper Wires**
* **Connecting the PICkit 3 to the Computer**
* **Compiling Our Code**
* **Connecting the PICkit Device to MPLAB IPE**
* **Common Errors When Trying to Connect a PICkit Device to MPLAB IPE**
* **Loading a Hex File to a PIC using the PICkit 3 and MPLAB IPE**
* **Testing Our Prototype Circuit**

## Super Simple LED Switch - PIC Project

You may find the Super Simple LED Switch three-part series project, in its entirety at the <a href="https://motbots.com/super-simple-led-switch-series-pic-project/" target="_blank" rel="noopener noreferrer nofollow">Motbots website here</a>.
