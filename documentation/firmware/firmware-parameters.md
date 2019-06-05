---
layout: default
title: Firmware parameters
---

Some settings can be modified in the firmware code before [upload to the Arduino board](../installing-the-firmware/ "Installing the firmware"). In this page I will show you the most important, but you can find others.

These configuration parameters are in the “Photoduino.ino” file of the firmware code and start with a block like this.

```
/* --------------------------------------------------- *  
* CONFIGURATION VALUES: *  
* You can set the next configuration values *  
* before compile and upload this sketch *  
* --------------------------------------------------- */
```

## Language of menus

This parameter define which language you want to use in the menus. Basically is the name of the file containing the strings used. If you want to translate to another language and share with the community you can maker your own “language\_XX.h” file where “XX” is the standard ISO code of the language.

```
// Language of menus:  
// - Set the language of menus in LCD  
//  
// Valid values:  
// - "language_EN.h" for (English)  
// - "language_ES.h" for (Spanish)  
//  
#define LANGUAGE_FILE "language_ES.h"
```

## Default shutterlag

You can also change this parameter through the interface, but this value in the firmware code will be the default value if you reset your system config anytime.

```
//  
// Default Camera Shutterlag:  
// - The default value for shutterlag to load when you reset config.  
// - Also configurable throught menus.  
//  
// Valid values:  
// - Number between 0 and 59999 in miliseconds  
// - Check your camera model at: http://photoduino.com/documentation/reference/cameras-shutterlag/  
//  
#define DEFAULT_SHUTTERLAG 100 // ms
```

## Flash shooting pulse

When Photoduino fire a flash, make a pulse to the output pin of the Arduino board connected to a thyristor which fire the flash. The width of this pulse is 40 microseconds by default, but in some flashes maybe you need to modify this value to a longer time.

```
//  
// Pulse width for shooting flashes:  
// - Time in microseconds of the pulse to shoot the flashes.  
// - Increase this value if you have problems with your flash model.  
//  
// Valid values:  
// - Number between 0 and 59999 in microseconds  
//  
#define DEVICES_FLASHES_SHOOTING_PULSE 40 // us
```

After modify any value you need to [compile and upload the firmware](../installing-the-firmware/ "Installing the firmware") again to the Arduino board.
