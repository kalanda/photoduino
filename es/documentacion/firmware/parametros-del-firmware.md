---
layout: default
lang: es
title: Parámetros del firmware
---
Algunos valores de configuración pueden ser modificados solamente desde el código fuente del firmware antes de [cargarlo en la placa Arduino](../instalando-el-firmware/ "Instalando el firmware"). En esta página te mostraré los importantes, pero puedes encontrar algunos más.

Estos parámetros de configuración están en el archivo “Photoduino.ino” del código fuente del firmware y comienzan con un bloque como este:

```
/* --------------------------------------------------- *  
* CONFIGURATION VALUES: *  
* You can set the next configuration values *  
* before compile and upload this sketch *  
* --------------------------------------------------- */
```

## Idioma de los menus

Este parámetro define en que lenguaje deseas que estén escritos los menus. Básicamente es el nombre del archivo que contiene los textos a usar. Si quieres realizar tu propia traducción a otro idioma y compartirla con la comunidad, simplemente crea un archivo llamado “language\_XX.h” donde “XX” es el código ISO del lenguaje.

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

## Retardo del obturador por defecto

Puedes modificar este valor también desde el interface, pero este parámetro en el código fuente será el valor por defecto del “Retardo de obturador” cuando borres la configuración del sistema en algún momento.

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

## Pulso de disparo del Flash

Cuando Photoduino dispara un flash, crea un pulso a través del pin de salida de Arduino conectado a un tiristor que dispara el flash. El ancho de este pulso es de 40 microsegundos por defecto, pero en algunos flashes tal vez necesites modificar este valor a uno más alto.

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

Después de modificar cualquier valor debes volver a [compilar y subir el firmware](../instalando-el-firmware/ "Instalando el firmware") a la placa Arduino.
