---
layout: default
title: Installing the firmware
---
## DOWNLOADING

1.  Download the zip with the Arduino sketch of [latest Photoduino firmware](http://sourceforge.net/projects/photoduino/files/firmware/photoduino.shield.firmware.v.1.1.zip/download)
2.  Download the latest version of the [Arduino development environment](http://arduino.cc/en/Main/Software)

## PREPARING

1.  **Unzip the downloaded Arduino environment.** You will find two things. The installer of the environment and the drivers for the FTDI chip that carries Arduino to connect to USB. You should install both.
2.  **Unzip the downloaded firmware.** Is very important that all files are together in a folder called “Photoduino”, if not, rename it.
3.  You must **connect the Arduino board** to your computer via USB.
4.  **Open the Arduino environment** you have installed.
5.  In the Arduino environment, **go to menu “Tools->Board” and select your arduino model**.
6.  In the Arduino environment, **go to menu “Tools->Serial Port” and select the port of arduino**.

## COMPILING AND UPLOADING THE FIRMWARE

1.  In the Arduino environment **go to menu “File-> Open …” and select the file “Photoduino.ino”** in the unzipped firmware folder. This will open as tabs each of the firmware files in the folder.
2.  If you want to modify some [firmware parameter](../firmware-parameters/ "Firmware parameters"), is the time to do it.
3.  Click the “Verify” or **go to the “Sketches”> Verify / Compile … “**
4.  In the black area at the bottom **should not appear any error**. Only white text. **If the text is red are errors** and you should check the name of the folder as explained above.
5.  If all goes fine, you can **press the button “Upload” or go to the menu “File-> Upload to IO board”** and wait to finish.
6.  The environment **will tell you about everything on the console** (bottom box with black background)

## FINISHING

-   If all goes well, you have the firmware loaded on your plate and you should hear one beep (if photoduino shield is connected to the arduino board).
-   If not text appears on the LCD screen of photoduino, adjust the contrast potentiometer.
