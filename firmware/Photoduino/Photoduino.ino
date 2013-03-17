/*
 *             _                          _       _                  
 *            | |           _            | |     (_)                 
 *       ____ | |__   ___ _| |_  ___   __| |_   _ _ ____   ___       
 *      |  _ \|  _ \ / _ (_   _)/ _ \ / _  | | | | |  _ \ / _ \       
 *      | |_| | | | | |_| || |_| |_| ( (_| | |_| | | | | | |_| |      
 *      |  __/|_| |_|\___/  \__)\___/ \____|____/|_|_| |_|\___/       
 *      |_|  THE OPENSOURCE CAMERA CONTROLLER BASED ON ARDUINO         
 *       
 *
 * @name        Photoduino Firmware
 * @version     1.1
 * @web         http://www.photoduino.com
 * @author      http://www.kalanda.com
 *
 * This file is part of Photoduino.
 *
 * Photoduino is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Photoduino is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Photoduino.  If not, see <http://www.gnu.org/licenses/>.
 */

/* ------------------------------------------------------------------------------------------------ *
 *                                         CONFIGURATION VALUES:                                    *
 *                                You can set the next configuration values                         *
 *                                 before compile and upload this sketch                            *
 * ------------------------------------------------------------------------------------------------ */

//
// Language of menus:
// - Set the language of menus in LCD
// 
// Valid values: 
// - "language_EN.h" for (English)
// - "language_ES.h" for (Spanish) 
// - "language_IT.h" for (Italian)
// - "language_FR.h" for (Francais) 
// - "language_DE.h" for (Deutsch) 
//
#define LANGUAGE_FILE "language_EN.h"

//
// Default Camera Shutterlag:
// - The default value for shutterlag to load when you reset config. 
// - Also configurable throught menus.
// 
// Valid values:
// - Number between 0 and 59999 in miliseconds
// - Check your camera model at: http://www.photoduino.com/documentation/reference/cameras-shutterlag/
//
#define DEFAULT_SHUTTERLAG               100 // ms

// 
// Default intercicle time:
// - The default value in miliseconds camera needs to process photo and be ready for the next. 
// - Also configurable throught menus.
// 
// Valid values:
// - Number between 0 and 59999 in miliseconds
//
#define DEFAULT_INTERCYCLE_TIME          200 // ms 

// 
// Default camera mirror lock-up time limit:
// - When use the mirror lock-up shooting mode, all cameras has a limit time (about 30 seconds) to 
//   make the photo while the mirror is locked up. After that time, the mirror is automaticaly unlocked
//   by the camera without taking photo. The next value is this time in miliseconds to say to photoduino 
//   when to re-lock-up the mirror if no photo has taken.  Also configurable throught menus.
// 
// Valid values:
// - Number between 0 and 59999 in miliseconds
//
#define DEFAULT_CAMERA_MIRROR_LOCKUP_TIMEOUT         31000 //ms

// 
// Default device port type:
// - You can set the default device connected to DEVICE port.  Also configurable throught menus.
// 
// Valid values:
// - DEVICE_PORT_TYPE_NONE
// - DEVICE_PORT_TYPE_LASER 
//
#define DEFAULT_DEVICE_PORT_TYPE                DEVICE_PORT_TYPE_NONE    

// 
// Default sensor type:
// - You can set the default sensor type.  Also configurable throught menus.
// 
// Valid values:
// - SENSOR_TYPE_BARRIER
// - SENSOR_TYPE_AUDIO
// - SENSOR_TYPE_LIGHT
// - SENSOR_TYPE_SHOCK
//
#define DEFAULT_SENSOR_TYPE                     SENSOR_TYPE_BARRIER

// 
// Default sensor tunning mode:
// - You can set the default sensor tunning mode.  Also configurable throught menus.
// 
// Valid values:
// - SENSOR_TUNNING_VISUAL
// - SENSOR_TUNNING_NUMERIC
//
#define DEFAULT_SENSOR_TUNING_MODE              SENSOR_TUNING_VISUAL

// 
// Pulse width for shooting flashes:
// - Time in microseconds of the pulse to shoot the flashes.
// - Increase this value if you have problems with your flash model.
// 
// Valid values:
// - Number between 0 and 59999 in microseconds
// 
#define DEVICES_FLASHES_SHOOTING_PULSE     40 // us


//
// Arduino board type:
// - Make the firmware compatible with different boards
// 
// Valid values: 
// - BOARD_ARDUINO_DUEMILANOVE_OR_UNO 
// - BOARD_ARDUINO_MEGA
//
#define BOARD_ARDUINO_DUEMILANOVE_OR_UNO

/* ------------------------------------------------------------------------------------------- *
 *                                     IMPORTANT NOTE:                                         *
 *                        You don't need to modify the code below this lines                   * 
 * ------------------------------------------------------------------------------------------- */

// Signature and version codes 
#define SIGNATURE_CODE1             29 // day 
#define SIGNATURE_CODE2             5  // month
#define SIGNATURE_CODE3             20 // century
#define SIGNATURE_CODE4             12 // year of century
#define CODE_MAJOR_VERSION          1  // major version
#define CODE_MINOR_VERSION          2  // minor version

// Default system config
#define DEFAULT_system_useBacklight                   true
#define DEFAULT_system_useSpeaker                     true
#define DEFAULT_system_useFlash1                      true
#define DEFAULT_system_useFlash2                      true
#define DEFAULT_system_sensorTuningMode               DEFAULT_SENSOR_TUNING_MODE
#define DEFAULT_system_cameraShutterLag               DEFAULT_SHUTTERLAG
#define DEFAULT_system_cameraMirrorLockUpTimeout      DEFAULT_CAMERA_MIRROR_LOCKUP_TIMEOUT
#define DEFAULT_system_devicePortType                 DEFAULT_DEVICE_PORT_TYPE

// Default interval mode config
#define DEFAULT_intervalometerMode_autofocusTime      0
#define DEFAULT_intervalometerMode_preFlash1Time      0
#define DEFAULT_intervalometerMode_preFlash2Time      0
#define DEFAULT_intervalometerMode_preCloseTime       0
#define DEFAULT_intervalometerMode_intervalUnits      UNITS_SECS
#define DEFAULT_intervalometerMode_intervalValue      1
#define DEFAULT_intervalometerMode_numCycles          0

// Audio trigger mode default config
#define DEFAULT_sensorTriggerMode_sensorType          DEFAULT_SENSOR_TYPE
#define DEFAULT_sensorTriggerMode_sensorAudioLimit    500
#define DEFAULT_sensorTriggerMode_sensorBarrierLimit  500
#define DEFAULT_sensorTriggerMode_sensorLightLimit    500
#define DEFAULT_sensorTriggerMode_sensorShockLimit    500
#define DEFAULT_sensorTriggerMode_shootingMode        SHOOTINGMODE_NORMAL
#define DEFAULT_sensorTriggerMode_autofocusTime       0
#define DEFAULT_sensorTriggerMode_preFlash1Time       0
#define DEFAULT_sensorTriggerMode_preFlash2Time       0
#define DEFAULT_sensorTriggerMode_preCloseTime        0
#define DEFAULT_sensorTriggerMode_numCycles           0
#define DEFAULT_sensorTriggerMode_interCycleTime      DEFAULT_INTERCYCLE_TIME
#define DEFAULT_sensorTriggerMode_dropsCount          3
#define DEFAULT_sensorTriggerMode_dropsDuration       20
#define DEFAULT_sensorTriggerMode_dropsInterval       1000

// LCD settings
#define LCD_COLS             16 // columns
#define LCD_ROWS             2  // rows

// Pinout settings
#define PINS_LCD_LED         13 //(digital pin)
#define PINS_LCD_RS          12 //(digital pin)
#define PINS_LCD_ENABLE      11 //(digital pin)
#define PINS_LCD_DB4         10 //(digital pin)
#define PINS_LCD_DB5         9  //(digital pin)
#define PINS_LCD_DB6         8  //(digital pin)
#define PINS_LCD_DB7         7  //(digital pin)
#define PINS_BUZZER          6  //(digital pin with pwm)
#define PINS_SHUTTER         5  //(digital pin)
#define PINS_AUTOFOCUS       4  //(digital pin)
#define PINS_BTN_A           3  //(digital pin)
#define PINS_BTN_B           2  //(digital pin)

#define PINS_SENSOR_SHOCK    5  //(analog pin)
#define PINS_SENSOR_BARRIER  4  //(analog pin)
#define PINS_SENSOR_MIC      3  //(analog pin)

#ifdef BOARD_ARDUINO_MEGA    // For ArduinoMega compatibility
  #define PINS_FLASH1        56 // Mega pin 56 = Duemilanove 16 (digital pin)
  #define PINS_FLASH2        55 // Mega pin 55 = Duemilanove 15 (digital pin)
  #define PINS_DEVICE        54 // Mega pin 54 = Duemilanove 14 (digital pin)
#else  
  #define PINS_FLASH1        16 //(digital pin)
  #define PINS_FLASH2        15 //(digital pin)
  #define PINS_DEVICE        14 //(digital pin)
#endif

#define PINS_LASER           PINS_DEVICE  // alias(digital pin)
#define PINS_SOLENOID_VALVE  PINS_DEVICE  // alias(digital pin)

// Sensor types
#define SENSOR_TYPE_NONE                 0 // None sensor
#define SENSOR_TYPE_AUDIO                1 // Audio sensor
#define SENSOR_TYPE_BARRIER              2 // Barrier sensor
#define SENSOR_TYPE_LIGHT                3 // Light sensor
#define SENSOR_TYPE_SHOCK                4 // Shock sensor

// Sensor tunning modes
#define SENSOR_TUNING_VISUAL             0 // Visual 
#define SENSOR_TUNING_NUMERIC            1 // Numeric 

// Sensor limit modes
#define SENSOR_MODE_LOWER                0 // for triggering by lower values
#define SENSOR_MODE_HIGHER               1 // for triggering by higher values

// Shooting modes
#define SHOOTINGMODE_NORMAL              0 // Normal mode 
#define SHOOTINGMODE_PREBULB             1 // Prebulb mode
#define SHOOTINGMODE_MIRRORLOCKUP        2 // Mirror lookup mode

// Device types
#define DEVICE_PORT_TYPE_NONE            0 // None device connected
#define DEVICE_PORT_TYPE_LASER           1 // Laser connected for laser barrier
#define DEVICE_PORT_TYPE_SOLENOID_VALVE  2 // Solenoid valve connected for liquid drops 

// Measurement units
#define UNITS_MS             0  // miliseconds
#define UNITS_SECS           1  // seconds
#define UNITS_MINS           2  // minutes
#define UNITS_HOURS          3  // hours
#define UNITS_DAYS           4  // days
#define UNITS_CYCLES         10 // cycles
#define UNITS_US             11 // microseconds
#define UNITS_DROPS          12 // drops

// Keycodes
#define KEY_NONE             0 // No keys pressed
#define KEY_A                1 // Button A was pressed
#define KEY_B                2 // Button B was pressed
#define KEY_AH               3 // Button A was pressed and holded (KEY_HOLD_TIME) milisecons
#define KEY_BH               4 // Button B was pressed and holded (KEY_HOLD_TIME) milisecons
#define KEY_ABH              5 // Buttons A+B was pressed and holded (KEY_HOLD_TIME) milisecons

// Keyboard times
#define KEY_DEBOUNCE_TIME    30 // debounce time (ms) to prevent flickering when pressing or releasing the button
#define KEY_HOLD_TIME       400 // holding period (ms) how long to wait for press+hold event
#define KEY_HOLD_TIME_WAIT  100 // Used for double key holding

// Characters and symbols addresses on lcd eeprom
#define SYMBOL_DOWN         0x00 // Down arrow
#define SYMBOL_UP           0x01 // Up arrow
#define SYMBOL_BOX          0xff // Black box

// EEPROM size in bytes
#define EEPROM_SIZE         0x200  

// EEPROM Addresses for signature code and version of firmware
#define EE_ADDR_SIGNATURE_CODE1                      0x00 // BYTE
#define EE_ADDR_SIGNATURE_CODE2                      0x01 // BYTE
#define EE_ADDR_SIGNATURE_CODE3                      0x02 // BYTE
#define EE_ADDR_SIGNATURE_CODE4                      0x03 // BYTE
#define EE_ADDR_CODE_MAJOR_VERSION                   0x04 // BYTE
#define EE_ADDR_CODE_MINOR_VERSION                   0x05 // BYTE

// EEPROM Addresses for system config
#define EE_ADDR_system_useBacklight                  0x10 // BYTE
#define EE_ADDR_system_useSpeaker                    0x12 // BYTE
#define EE_ADDR_system_sensorTuningMode              0x14 // BYTE
#define EE_ADDR_system_cameraShutterLag              0x16 // WORD
#define EE_ADDR_system_cameraMirrorLockUpTimeout     0x18 // WORD
#define EE_ADDR_system_useFlash1                     0x1A // BYTE
#define EE_ADDR_system_useFlash2                     0x1C // BYTE
#define EE_ADDR_system_devicePortType                0x1E // BYTE

// EEPROM Addresses for interval mode config
#define EE_ADDR_intervalometerMode_autofocusTime     0x30 // WORD
#define EE_ADDR_intervalometerMode_preFlash1Time     0x32 // WORD
#define EE_ADDR_intervalometerMode_preFlash2Time     0x34 // WORD
#define EE_ADDR_intervalometerMode_preCloseTime      0x36 // WORD
#define EE_ADDR_intervalometerMode_intervalUnits     0x38 // BYTE
#define EE_ADDR_intervalometerMode_intervalValue     0x3A // WORD
#define EE_ADDR_intervalometerMode_numCycles         0x3C // WORD

// EEPROM Addresses for sensor trigger mode config
#define EE_ADDR_sensorTriggerMode_sensorType         0x50 // BYTE
#define EE_ADDR_sensorTriggerMode_sensorAudioLimit   0x52 // WORD
#define EE_ADDR_sensorTriggerMode_sensorBarrierLimit 0x54 // WORD
#define EE_ADDR_sensorTriggerMode_sensorLightLimit   0x56 // WORD
#define EE_ADDR_sensorTriggerMode_sensorShockLimit   0x58 // WORD
#define EE_ADDR_sensorTriggerMode_shootingMode       0x5A // BYTE
#define EE_ADDR_sensorTriggerMode_autofocusTime      0x5C // WORD
#define EE_ADDR_sensorTriggerMode_preFlash1Time      0x5E // WORD
#define EE_ADDR_sensorTriggerMode_preFlash2Time      0x60 // WORD
#define EE_ADDR_sensorTriggerMode_preCloseTime       0x62 // WORD
#define EE_ADDR_sensorTriggerMode_numCycles          0x64 // WORD
#define EE_ADDR_sensorTriggerMode_interCycleTime     0x66 // WORD
#define EE_ADDR_sensorTriggerMode_dropsCount         0x68 // WORD
#define EE_ADDR_sensorTriggerMode_dropsDuration      0x6A // WORD
#define EE_ADDR_sensorTriggerMode_dropsInterval      0x6C // WORD

// Import libraries 
#include <avr/pgmspace.h>  // For messages in flash memory
#include <LiquidCrystal.h> // For LCD Display use 
#include <EEPROM.h>        // For persistent config 
#include "FirmataLite.h"   // For remote control throught USB
#include LANGUAGE_FILE     // Messages

// LiquidCrystal LCD control object instance
LiquidCrystal lcd(PINS_LCD_RS, PINS_LCD_ENABLE, PINS_LCD_DB4, PINS_LCD_DB5, PINS_LCD_DB6, PINS_LCD_DB7);

// Variables used on interrupt mode
volatile boolean cancelFlag = false;    // Flag used to abort interrupt mode

// Remote mode variables
boolean remoteMode = false;
boolean remoteSensorBroadcasting = false;
boolean remoteSensorBroadcastingBeepOnLimit = false;

// Global variables
byte         lastKey = KEY_NONE;        // Last key pressed
boolean      flagHoldKey = false;       // Flag to ignore keys after a hold key
byte         lastProgressBarValue = 0;  // Last value of progress bar

// System config in ram
boolean      system_useBacklight;    
boolean      system_useSpeaker;
byte         system_sensorTuningMode;
unsigned int system_cameraShutterLag;
unsigned int system_cameraMirrorLockUpTimeout;
boolean      system_useFlash1;
boolean      system_useFlash2;
byte         system_devicePortType;

// Interval mode config in ram
unsigned int intervalometerMode_autofocusTime;
unsigned int intervalometerMode_preFlash1Time;
unsigned int intervalometerMode_preFlash2Time;
unsigned int intervalometerMode_preCloseTime;
byte         intervalometerMode_intervalUnits;
unsigned int intervalometerMode_intervalValue;
unsigned int intervalometerMode_numCycles;

// Sensor trigger mode config in ram
byte         sensorTriggerMode_sensorType;
unsigned int sensorTriggerMode_sensorAudioLimit;
unsigned int sensorTriggerMode_sensorBarrierLimit;
unsigned int sensorTriggerMode_sensorLightLimit;
unsigned int sensorTriggerMode_sensorShockLimit;
byte         sensorTriggerMode_shootingMode;
unsigned int sensorTriggerMode_autofocusTime;
unsigned int sensorTriggerMode_preFlash1Time;
unsigned int sensorTriggerMode_preCloseTime;
unsigned int sensorTriggerMode_preFlash2Time;
unsigned int sensorTriggerMode_numCycles;
unsigned int sensorTriggerMode_interCycleTime;
unsigned int sensorTriggerMode_dropsCount;
unsigned int sensorTriggerMode_dropsDuration;
unsigned int sensorTriggerMode_dropsInterval;

// Setups at startup
void setup() 
{   
  // Create custom LCD symbols
  byte char_arrow_down[8] = {B00000, B00100, B00100, B00100, B00100, B10101, B01110, B00100};
  byte char_arrow_up[8]   = {B00100, B01110, B10101, B00100, B00100, B00100, B00100, B00000};

  // LCD initialize
  lcd.begin( LCD_COLS,  LCD_ROWS);
  lcd.createChar(SYMBOL_DOWN, char_arrow_down);
  lcd.createChar(SYMBOL_UP, char_arrow_up);

  // Pinmode inputs
  pinMode(PINS_BTN_A,          INPUT);     
  pinMode(PINS_BTN_B,          INPUT);    
  pinMode(PINS_SENSOR_SHOCK,   INPUT); 
  pinMode(PINS_SENSOR_BARRIER, INPUT);
  pinMode(PINS_SENSOR_MIC,     INPUT);  

  // Pinmode outputs
  pinMode(PINS_SHUTTER,        OUTPUT);
  pinMode(PINS_AUTOFOCUS,      OUTPUT);
  pinMode(PINS_FLASH1,         OUTPUT);
  pinMode(PINS_FLASH2,         OUTPUT);
  pinMode(PINS_LCD_LED,        OUTPUT);
  pinMode(PINS_LCD_RS,         OUTPUT);
  pinMode(PINS_LCD_ENABLE,     OUTPUT);
  pinMode(PINS_LCD_DB4,        OUTPUT);
  pinMode(PINS_LCD_DB5,        OUTPUT);
  pinMode(PINS_LCD_DB6,        OUTPUT);
  pinMode(PINS_LCD_DB7,        OUTPUT);
  pinMode(PINS_BUZZER,         OUTPUT);
  pinMode(PINS_DEVICE,         OUTPUT);
  
  // Init Firmata 
  FirmataLite.attach(START_SYSEX, sysexCallback);
  FirmataLite.begin();
}

// Run controller
void loop(){ 
  
  // Initialize config
  config_init(); 

  // Init backlight
  backlight_init();

  // Init device connected to device port
  device_init();
  
  // Run main controller
  controller_run();
 
}



