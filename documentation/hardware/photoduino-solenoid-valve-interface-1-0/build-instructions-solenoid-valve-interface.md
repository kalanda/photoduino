---
layout: default
title: Build instructions of solenoid valve interface
---

Making this circuit is so easy. You need the components of course, but also you need some tools like soldering iron, tin, cutting pliers and a pair of screwdrivers (with flat and star tips).

**IS VERY IMPORTANT** know how to soldering well.[  
Get this comic for easy learning "Soldering is Easy"](https://kalanda.github.io/photoduino/assets/pdf/FullSolderComic_EN.pdf)

## The PCB

![](../../../../assets/images/IMG_4791.jpg "IMG_4791")

## Components

First, you have to solder the 1ok resistor (brown, black and orange bands).  Has no polarity and is only one. In the PCB is masked as R2.

![](../../../../assets/images/IMG_4792.jpg "IMG_4792")

Next step is solder the 1N4004 diode. It has a gray band at one end to indicate their polarity. You place it as shown in the next picture.

![](../../../../assets/images/IMG_4793.jpg "IMG_4793")

Now you have to solder the MOSFET IRL520. It has polarity. You place it as shown in the next picture.

![](../../../../assets/images/IMG_4803.jpg "IMG_4803")

Now solder the screw terminals.

![](../../../../assets/images/IMG_4804.jpg "IMG_4804")

And last, solder the RCA connector.

![](../../../../assets/images/IMG_48061.jpg "IMG_4806")

## Solenoid Valve wiring

To connect the solenoid valve, first you have to solder to a couple of wires. Solenoid valve has no polarity.

![](../../../../assets/images/IMG_4808.jpg "IMG_4808")

![](../../../../assets/images/IMG_4809.jpg "IMG_4809")

Take apart a couple of heat shrink tubes to isolate the connections later.

![](../../../../assets/images/IMG_4812.jpg "IMG_4812")

![](../../../../assets/images/IMG_4813.jpg "IMG_4813")

![](../../../../assets/images/IMG_4816.jpg "IMG_4816")

![](../../../../assets/images/IMG_4818.jpg "IMG_4818")

![](../../../../assets/images/IMG_4822.jpg "IMG_4822")

![](../../../../assets/images/IMG_4823.jpg "IMG_4823")

![](../../../../assets/images/IMG_4824.jpg "IMG_4824")

## Solenoid valve and power supply connections

IT IS VERY IMPORTANT. You must be very careful with the polarity of the power. Inthe picture you can see that the positive supply (red) is connected to “+12 v power” and the negative to “GND power”. If instead of the battery socket you are using a DC power supply, determine the polarity  using a multimeter.

![](../../../../assets/images/IMG_48301.jpg "IMG_4830")

![](../../../../assets/images/IMG_48281.jpg "IMG_4828")

## Connection to Photoduino

The connection is made by a RCA cable to the DEVICE port of Photoduino.

![](../../../../assets/images/IMG_52351.jpg "IMG_5235")

## Assemble example

In the photo above you can see how to use the syringe as a reservoir of liquid using the plastic microtube to connect to the input of the solenoid. Although not included in the kit the other materials you can see int the photos, I put them as an example of how you can assemble the system.

![](../../../../assets/images/IMG_52411.jpg "IMG_5241")

![](../../../../assets/images/IMG_52451.jpg "IMG_5245")
