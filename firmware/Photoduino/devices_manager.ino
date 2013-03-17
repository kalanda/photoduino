/*
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

// Shoots the flash after wait a delay
void flash_shoot(unsigned int previousDelay, byte pin) {
    delay(previousDelay);
    digitalWrite(pin,HIGH); 
    delayMicroseconds(DEVICES_FLASHES_SHOOTING_PULSE);
    digitalWrite(pin,LOW);
 }

// Begins the shutter 
void camera_shutterBegin(unsigned int shutterLag){
    digitalWrite(PINS_SHUTTER,HIGH); 
    delay(shutterLag);
}
 
// Ends the shutter
void camera_shutterEnd(unsigned int preCloseTime){
    delay(preCloseTime);
    digitalWrite(PINS_SHUTTER,LOW); 
}

// Begins the autofocus
void camera_autofocusBegin(unsigned int autofocusTime){
    digitalWrite(PINS_AUTOFOCUS,HIGH); 
    delay(autofocusTime);
}

// Ends the autofocus
void camera_autofocusEnd(){
    digitalWrite(PINS_AUTOFOCUS,LOW);
}

// Look-up the mirror 
void camera_mirrorLockUp(unsigned int autofocusTime, unsigned int shutterLag){
    
    digitalWrite(PINS_AUTOFOCUS,HIGH); 
    delay(autofocusTime);  
    digitalWrite(PINS_SHUTTER,HIGH); 
    delay(shutterLag);
    digitalWrite(PINS_SHUTTER,LOW); 
    digitalWrite(PINS_AUTOFOCUS,LOW);
}



// Reads the value of a sensor
unsigned int sensor_read(byte sensorPin) {
  
  unsigned int value = analogRead(sensorPin);
  if (value>999) value = 999;
 
  if (sensorPin == PINS_SENSOR_MIC) {
    if (value > 500) value = (value-500)*2;
    else value = (500-value)*2;
  } 
  
  return value;
}

// Sets the sensor pin and sensor mode according the sensor type
void sensor_getConfiguration(byte sensorType, unsigned int **limitValue, byte *sensorPin, byte *sensorMode) {
   
   if (sensorType == SENSOR_TYPE_NONE) {  }
   else if (sensorType == SENSOR_TYPE_AUDIO) { *sensorPin = PINS_SENSOR_MIC; *sensorMode = SENSOR_MODE_HIGHER; *limitValue = &sensorTriggerMode_sensorAudioLimit; }
   else if (sensorType == SENSOR_TYPE_SHOCK) { *sensorPin = PINS_SENSOR_SHOCK; *sensorMode = SENSOR_MODE_HIGHER; *limitValue = &sensorTriggerMode_sensorShockLimit; }
   else if (sensorType == SENSOR_TYPE_LIGHT) { *sensorPin = PINS_SENSOR_BARRIER; *sensorMode = SENSOR_MODE_HIGHER; *limitValue = &sensorTriggerMode_sensorLightLimit;}
   else if (sensorType == SENSOR_TYPE_BARRIER) { *sensorPin = PINS_SENSOR_BARRIER; *sensorMode = SENSOR_MODE_LOWER; *limitValue = &sensorTriggerMode_sensorBarrierLimit;}
}

// Waits for sensor cross the limit
boolean sensor_waitFor(byte sensorType, unsigned int limitTime){
  
  boolean result = false;
  
  if(sensorType != SENSOR_TYPE_NONE){
    
    byte sensorPin;
    byte sensorMode;
    unsigned int *limitValue;
    sensor_getConfiguration(sensorType, &limitValue, &sensorPin, &sensorMode);
    
    unsigned long time = millis();
    unsigned int sensorValue = sensor_read(sensorPin);
  
    for(; !result && !cancelFlag && (millis()<time+limitTime || limitTime==0); sensorValue = sensor_read(sensorPin)) {
      if (sensorMode==SENSOR_MODE_HIGHER && sensorValue>=*limitValue) result = true;
      if (sensorMode==SENSOR_MODE_LOWER && sensorValue<=*limitValue) result = true;
    }
    if(cancelFlag) result = true;
  
  } else {
  
    result = true;
  
  }
  
  return result;
}

// Called in interrupt mode when any button is pressed
void keyboard_interrupts(){
  if (!digitalRead(PINS_BTN_A)&&!digitalRead(PINS_BTN_B)) cancelFlag = false; 
  else cancelFlag = true;
}

// Scans keyboard in normal mode
void keyboard_scan() { 
   keyboard_scan(false);
}

// Scans keyboard buttons
void keyboard_scan(boolean quickmode) { 

  unsigned long time = millis();  
  
  
  if (flagHoldKey && !quickmode) { 
      buzzer_beep(100);
      while(digitalRead(PINS_BTN_A) || digitalRead(PINS_BTN_B)) {}
      flagHoldKey = false;
      lastKey = KEY_NONE; 
      
  } else if (digitalRead(PINS_BTN_A)) {
     while(digitalRead(PINS_BTN_A) && (millis()-time) <= KEY_HOLD_TIME+KEY_HOLD_TIME_WAIT){  
        if (millis()-time >= KEY_DEBOUNCE_TIME) lastKey = KEY_A;  
        if (millis()-time >= KEY_HOLD_TIME) { if(digitalRead(PINS_BTN_B)) lastKey = KEY_ABH; else lastKey = KEY_AH; flagHoldKey = true; }
     }
     
  } else if (digitalRead(PINS_BTN_B)) {
     while(digitalRead(PINS_BTN_B) && (millis()-time) <= KEY_HOLD_TIME+KEY_HOLD_TIME_WAIT){  
        if (millis()-time >= KEY_DEBOUNCE_TIME)  lastKey = KEY_B;  
        if (millis()-time >= KEY_HOLD_TIME) { if(digitalRead(PINS_BTN_A)) lastKey = KEY_ABH; else lastKey = KEY_BH; flagHoldKey = true; }
     }    
  } else {
    flagHoldKey = false;
    lastKey = KEY_NONE;
  }
  
}

// Waits until any key is pressed
void keyboard_waitForAnyKey(){
   do{ keyboard_scan(); } while (lastKey==KEY_NONE);
}

// Waits until no key is pressed
void keyboard_waitForNokey(){
   do{ keyboard_scan(); } while (lastKey!=KEY_NONE);
}

// Beeps buzzer a time in ms
void buzzer_beep(int time){
  
  if (system_useSpeaker){
     analogWrite(PINS_BUZZER,64); 
     delay(time);
     analogWrite(PINS_BUZZER,0); 
  } else {
     delay(time);
  }
}

// Init the backlight
void backlight_init(){
   digitalWrite(PINS_LCD_LED, system_useBacklight); 
}

// Toggle the backlight status (on/off)
void backlight_toggle(){
  
  system_useBacklight = !system_useBacklight;
  digitalWrite(PINS_LCD_LED, system_useBacklight);
}

// Print on lcd a progmem string
void display_printMessage(const prog_char* str) {
  char c;
  if (!str) return;
  while ((c = pgm_read_byte(str))) {
    lcd.print(c);
    str++;
  }
}

// prints screen title
void display_printTitle(const prog_char* str){
    lcd.clear();
    lcd.print(">");
    display_printMessage(str);
    lcd.setCursor(0,1);
}

// prints screen title
void display_printQuestion(const prog_char* str){
    lcd.clear();
    lcd.print(">");
    display_printMessage(str);
    lcd.print("?");
    lcd.setCursor(0,1);
}

void display_printEnumeration(byte num, const prog_char* str){
    lcd.print(num, 10);
    lcd.print(".");
    display_printMessage(str);
}

// prints aborting message
void display_printResetting(){
  lcd.clear();
  display_printMessage(MSG_RESETTING);
}

// prints aborting message
void display_printAborting(){
  lcd.clear();
  display_printMessage(MSG_ABORTING);
}

// prints a boolean value
void display_printBoolean(boolean value) {
  lcd.print(" (");
  if (value) display_printMessage(MSG_YES); else display_printMessage(MSG_NO);
  lcd.print(")");
}

// Print units value
void display_printUnits(byte units){
  lcd.print("(");
  if(units==UNITS_US) display_printMessage(MSG_UNITS_US);
  if(units==UNITS_MS) display_printMessage(MSG_UNITS_MS);     
  if(units==UNITS_SECS) display_printMessage(MSG_UNITS_SECS);
  if(units==UNITS_MINS) display_printMessage(MSG_UNITS_MINS);
  if(units==UNITS_HOURS) display_printMessage(MSG_UNITS_HOURS);
  if(units==UNITS_DAYS) display_printMessage(MSG_UNITS_DAYS);
  if(units==UNITS_CYCLES) display_printMessage(MSG_UNITS_CYCLES);
  if(units==UNITS_DROPS) display_printMessage(MSG_UNITS_DROPS);
  lcd.print(")");
}

// Print sesnor type value
void display_printSensorType(byte type){
  lcd.print("(");
  if(type==SENSOR_TYPE_NONE) display_printMessage(MSG_NONE);
  if(type==SENSOR_TYPE_AUDIO) display_printMessage(MSG_SENSOR_TYPE_AUDIO);
  if(type==SENSOR_TYPE_BARRIER) display_printMessage(MSG_SENSOR_TYPE_BARRIER);
  if(type==SENSOR_TYPE_LIGHT) display_printMessage(MSG_SENSOR_TYPE_LIGHT);
  if(type==SENSOR_TYPE_SHOCK) display_printMessage(MSG_SENSOR_TYPE_SHOCK);
  lcd.print(")");
}


// Print shooting mode value
void display_printShootingMode(byte mode){
  lcd.print("(");
  if(mode==SHOOTINGMODE_NORMAL) display_printMessage(MSG_SHOOTINGMODE_NORMAL);
  if(mode==SHOOTINGMODE_PREBULB) display_printMessage(MSG_SHOOTINGMODE_PREBULB);     
  if(mode==SHOOTINGMODE_MIRRORLOCKUP) display_printMessage(MSG_SHOOTINGMODE_MIRRORLOCKUP);
  lcd.print(")");
}

// Print sensor tunning modes
void display_printInterfaceSensorMode(byte mode){
  lcd.print("(");
  if(mode==SENSOR_TUNING_VISUAL) display_printMessage(MSG_SENSOR_TUNING_VISUAL);
  if(mode==SENSOR_TUNING_NUMERIC) display_printMessage(MSG_SENSOR_TUNING_NUMERIC);     
  lcd.print(")");
}

// Print a progressbar
void display_printProgressBar(int howMany, int total){
  
    byte positions = map(howMany, 0, total, 0, LCD_COLS);
    if(positions!=lastProgressBarValue){
      lcd.setCursor(0,1);
      for(byte i=0;i<=positions && positions>0;i++){
        lcd.write(SYMBOL_BOX);
      }  
    }
    lastProgressBarValue = positions;
 
}

// Print units value
void display_printDevicePortType(byte type){
  lcd.print("(");
  if(type==DEVICE_PORT_TYPE_NONE) display_printMessage(MSG_NONE);
  if(type==DEVICE_PORT_TYPE_LASER) display_printMessage(MSG_DEVICE_PORT_TYPE_LASER);
  if(type==DEVICE_PORT_TYPE_SOLENOID_VALVE) display_printMessage(MSG_DEVICE_PORT_TYPE_SOLENOID_VALVE);
  lcd.print(")");
}

// Print a number of any positions with leading zeros.
void display_leadingZeroNumber(unsigned int number, byte positions){
  
     if(positions>4) lcd.print(number/10000,10);
     if(positions>3) lcd.print((number%10000)/1000, 10);
     if(positions>2) lcd.print((number%1000)/100, 10);
     if(positions>1) lcd.print((number%100)/10, 10);
     lcd.print((number%10), 10);
  
}

void device_init(){
  
   if(system_devicePortType == DEVICE_PORT_TYPE_NONE) laser_turnOff();
   if(system_devicePortType == DEVICE_PORT_TYPE_LASER) laser_turnOn();
   if(system_devicePortType == DEVICE_PORT_TYPE_SOLENOID_VALVE) digitalWrite(PINS_SOLENOID_VALVE,LOW);
}

// Turns the laser ON
void laser_turnOn(){
  
  // Turn on laser if device port is laser
   if(system_devicePortType == DEVICE_PORT_TYPE_LASER) {
      digitalWrite(PINS_LASER,HIGH);
      delay(1); // waits for laser to anything
   }
}

// Turns the laser OFF
void laser_turnOff(){
  if (system_devicePortType == DEVICE_PORT_TYPE_NONE || DEVICE_PORT_TYPE_LASER) digitalWrite(PINS_LASER,LOW); 
}

void solenoidValve_makeDrops(){
  
  if(system_devicePortType == DEVICE_PORT_TYPE_SOLENOID_VALVE) {
     for(unsigned int count = 0; count < sensorTriggerMode_dropsCount && cancelFlag==false; count++){
        if (count>0) delay(sensorTriggerMode_dropsInterval);
        digitalWrite(PINS_SOLENOID_VALVE,HIGH);
        delay(sensorTriggerMode_dropsDuration);
        digitalWrite(PINS_SOLENOID_VALVE,LOW);
     } 
  }
}

