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

// Runs the controller
void controller_run(){

   controller_showWelcome();
   remote_sendReady();
   
   while(true) {
     
     keyboard_scan();
     
     if(lastKey != KEY_NONE) {
        controller_showMainMenu();
        controller_showWelcome();
     }
     
     if(FirmataLite.available()) FirmataLite.processInput();
     
     if(remoteMode){
       controller_showRemoteMode();
       while(remoteMode){
          if(FirmataLite.available()) FirmataLite.processInput();
          remote_sensor_broadcast();
       }
       controller_showWelcome();
     }
   }
}

// Show remote mode
void controller_showRemoteMode(){
   lcd.clear();
   display_printMessage(MSG_REMOTE_MODE);
}

// Show welcome
void controller_showWelcome(){
   lcd.clear();
   display_printMessage(MSG_PHOTODUINO_V);
   lcd.print(CODE_MAJOR_VERSION,10);
   lcd.print(".");
   lcd.print(CODE_MINOR_VERSION,10);
   lcd.setCursor(0,1);
   display_printMessage(MSG_READY);
   buzzer_beep(200);
}

// Main Menu View
void controller_showMainMenu(){
  
  byte currentOption = 0;
  
  for(boolean exit = false;!exit;){
      
    display_printTitle(MSG_MAIN_MENU);

    if(currentOption==0) display_printEnumeration(0, MSG_SYSTEM_CONFIG); 
    if(currentOption==1) display_printEnumeration(1, MSG_INTERVALOMETER); 
    if(currentOption==2) display_printEnumeration(2, MSG_SENSOR_TRIGGER);
    
    keyboard_waitForAnyKey();
    
    if(lastKey==KEY_A) circularList_incrementBy(&currentOption, 0, 2, -1);   
    if(lastKey==KEY_B) circularList_incrementBy(&currentOption, 0, 2, 1);        
    if(lastKey==KEY_AH) exit = true;
    if(lastKey==KEY_BH) {
                        
          if(currentOption==0) controller_showSystemConfig(); 
          if(currentOption==1) controller_showIntervalMenu(); 
          if(currentOption==2) controller_showSensorTriggerMenu();
    }
  }
}

// Interval Menu View
void controller_showIntervalMenu(){
  
  byte currentOption = 0;
 
  for(boolean exit = false;!exit;){
      
    display_printTitle(MSG_INTERVALOMETER);

    // Show menu option
    if(currentOption==0) display_printMessage(MSG_CONFIG);
    if(currentOption==1) display_printMessage(MSG_RUN);
    if(currentOption==2) display_printMessage(MSG_RESET_CONFIG);
    
    keyboard_waitForAnyKey();
    
    if(lastKey==KEY_A) circularList_incrementBy(&currentOption, 0, 2, -1);        
    if(lastKey==KEY_B) circularList_incrementBy(&currentOption, 0, 2, 1);   
    if(lastKey==KEY_AH) exit = true;
    if(lastKey==KEY_BH) {
                    
         if(currentOption==0)  { controller_showIntervalConfig(); } 
         if(currentOption==1)  { runAs_intervalometer(); }
         if(currentOption==2)  { if(controller_confirmAction(MSG_RESET_CONFIG)) {config_loadDefaults_intervalometerMode(); config_saveBackup_intervalometerMode(); display_printResetting(); } }
    }
  }
}

// Sensor trigger menu view
void controller_showSensorTriggerMenu(){
  
  byte currentOption = 0;
  boolean skipOption = false;
  
  for(boolean exit = false;!exit;){
      
    display_printTitle(MSG_SENSOR_TRIGGER);

    // Show menu option
    if(currentOption==0) display_printMessage(MSG_CONFIG_TRIGGER);
    if(currentOption==1) { if(system_devicePortType==DEVICE_PORT_TYPE_SOLENOID_VALVE) display_printMessage(MSG_CONFIG_DROPS); else skipOption = true; }
    if(currentOption==2) display_printMessage(MSG_RUN);
    if(currentOption==3) display_printMessage(MSG_RESET_CONFIG);
    
    if (!skipOption) keyboard_waitForAnyKey();
    else skipOption = false;
      
    if(lastKey==KEY_A) { circularList_incrementBy(&currentOption, 0, 3, -1); }
    if(lastKey==KEY_B) { circularList_incrementBy(&currentOption, 0, 3, 1); }
    if(lastKey==KEY_AH) exit = true;
    if(lastKey==KEY_BH) {
                    
           if(currentOption==0) { controller_showSensorTriggerConfig(); } 
           if(currentOption==1) { controller_showDropsConfig(); } 
           if(currentOption==2) { runAs_sensorTriggerMode(); }
           if(currentOption==3) { if(controller_confirmAction(MSG_RESET_CONFIG)) {config_loadDefaults_sensorTriggerMode(); config_saveBackup_sensorTriggerMode(); display_printResetting();} }
    }
    
  }
}


// System config View
void controller_showSystemConfig(){
  
  byte currentOption = 0;
 
  for(boolean exit = false;!exit;){
      
    display_printTitle(MSG_SYSTEM_CONFIG);

    // Show menu option
    if(currentOption==0) { display_printMessage(MSG_DEVICE_PORT_TYPE); }
    if(currentOption==1) { display_printMessage(MSG_SENSOR_TUNING); }
    if(currentOption==2) { display_printMessage(MSG_SHUTTERLAG_TIME); }
    if(currentOption==3) { display_printMessage(MSG_MIRROR_LOCKUP_TIMEOUT); }
    if(currentOption==4) { display_printMessage(MSG_USE_FLASH1); display_printBoolean(system_useFlash1); }
    if(currentOption==5) { display_printMessage(MSG_USE_FLASH2); display_printBoolean(system_useFlash2); }
    if(currentOption==6) { display_printMessage(MSG_SPEAKER); display_printBoolean(system_useSpeaker); }
    if(currentOption==7) { display_printMessage(MSG_BACKLIGHT); display_printBoolean(system_useBacklight); }

    
    keyboard_waitForAnyKey();
    
    if(lastKey==KEY_A) circularList_incrementBy(&currentOption, 0, 7, -1);
    if(lastKey==KEY_B) circularList_incrementBy(&currentOption, 0, 7, 1);
    if(lastKey==KEY_AH) { config_saveBackup_system(); exit = true; } 
    if(lastKey==KEY_BH) {
          
          if(currentOption==0) controller_setDevicePortType(&system_devicePortType);
          if(currentOption==1) controller_setSensorTuningMode(&system_sensorTuningMode);
          if(currentOption==2) controller_setNumericParameterValue(&system_cameraShutterLag, MSG_SHUTTERLAG_TIME, UNITS_MS);
          if(currentOption==3) controller_setNumericParameterValue(&system_cameraMirrorLockUpTimeout, MSG_MIRROR_LOCKUP_TIMEOUT,UNITS_MS);
          if(currentOption==4) system_useFlash1 = !system_useFlash1;
          if(currentOption==5) system_useFlash2 = !system_useFlash2;       
          if(currentOption==6) system_useSpeaker = !system_useSpeaker;
          if(currentOption==7) backlight_toggle();     
          
    }
  }
}

// Interval Config view
void controller_showIntervalConfig(){
  
  byte currentOption = 0;
  boolean skipOption = false;
  
  for(boolean exit = false;!exit;){
     
      display_printTitle(MSG_INTERVALOMETER);
     
      // Show menu options
      if(currentOption==0) { display_printMessage(MSG_AUTOFOCUS_TIME);  }
      if(currentOption==1) { if(system_useFlash1) display_printMessage(MSG_FLASH1_PRETIME); else skipOption = true; }
      if(currentOption==2) { if(system_useFlash2) display_printMessage(MSG_FLASH2_PRETIME); else skipOption = true; }
      if(currentOption==3) { display_printMessage(MSG_CLOSE_PRETIME); }
      if(currentOption==4) { display_printMessage(MSG_INTERVAL_UNITS); }
      if(currentOption==5) { display_printMessage(MSG_INTERVAL_VALUE); }
      if(currentOption==6) { display_printMessage(MSG_CYCLES); }

      if (!skipOption) keyboard_waitForAnyKey();
      else skipOption = false;
        
      if(lastKey==KEY_A) { circularList_incrementBy(&currentOption, 0, 6, -1); }
      if(lastKey==KEY_B) { circularList_incrementBy(&currentOption, 0, 6, 1); } 
      if(lastKey==KEY_AH) { config_saveBackup_intervalometerMode(); exit = true; }
      if(lastKey==KEY_BH) {          

             if(currentOption==0)  controller_setNumericParameterValue(&intervalometerMode_autofocusTime, MSG_AUTOFOCUS_TIME,UNITS_MS);
             if(currentOption==1)  controller_setNumericParameterValue(&intervalometerMode_preFlash1Time, MSG_FLASH1_PRETIME,UNITS_MS);
             if(currentOption==2)  controller_setNumericParameterValue(&intervalometerMode_preFlash2Time, MSG_FLASH2_PRETIME,UNITS_MS);
             if(currentOption==3)  controller_setNumericParameterValue(&intervalometerMode_preCloseTime, MSG_CLOSE_PRETIME,UNITS_MS);
             if(currentOption==4)  controller_setUnits(&intervalometerMode_intervalUnits, MSG_INTERVAL_UNITS); 
             if(currentOption==5)  controller_setNumericParameterValue(&intervalometerMode_intervalValue, MSG_INTERVAL_VALUE,intervalometerMode_intervalUnits);
             if(currentOption==6)  controller_setNumericParameterValue(&intervalometerMode_numCycles, MSG_CYCLES,UNITS_CYCLES);     
      } 
      
   }
}



// Sensor Trigger Config view
void controller_showSensorTriggerConfig(){
  
   byte currentOption = 0;
   boolean skipOption = false;
  
   for(boolean exit = false;!exit;){
     
      display_printTitle(MSG_CONFIG_TRIGGER);
         
      // Show menu options
      
      if(currentOption==0) { display_printMessage(MSG_SENSOR); lcd.print(" "); display_printSensorType(sensorTriggerMode_sensorType); }
      if(currentOption==1) { display_printMessage(MSG_SENSOR_LIMIT); }
      if(currentOption==2) { display_printMessage(MSG_SHOOTING_MODE);  }
      if(currentOption==3) { display_printMessage(MSG_AUTOFOCUS_TIME);  }
      if(currentOption==4) { if(system_useFlash1) display_printMessage(MSG_FLASH1_PRETIME); else skipOption = true; }
      if(currentOption==5) { if(system_useFlash2) display_printMessage(MSG_FLASH2_PRETIME); else skipOption = true; }
      if(currentOption==6) { display_printMessage(MSG_CLOSE_PRETIME); }
      if(currentOption==7) { display_printMessage(MSG_CYCLES); }
      if(currentOption==8) { display_printMessage(MSG_INTERCYCLE_TIME); }
  
      if (!skipOption) keyboard_waitForAnyKey();
      else skipOption = false;
          
      if(lastKey==KEY_A) { circularList_incrementBy(&currentOption, 0, 8, -1); }
      if(lastKey==KEY_B) { circularList_incrementBy(&currentOption, 0, 8, 1); }
      if(lastKey==KEY_AH) { config_saveBackup_sensorTriggerMode(); exit = true; }
      if(lastKey==KEY_BH) {          
          
             if(currentOption==0)  controller_setSensorType(&sensorTriggerMode_sensorType);
             if(currentOption==1)  controller_setSensorLimit(sensorTriggerMode_sensorType); 
             if(currentOption==2)  controller_setShootingMode(&sensorTriggerMode_shootingMode);
             if(currentOption==3)  controller_setNumericParameterValue(&sensorTriggerMode_autofocusTime, MSG_AUTOFOCUS_TIME,UNITS_MS);
             if(currentOption==4)  controller_setNumericParameterValue(&sensorTriggerMode_preFlash1Time, MSG_FLASH1_PRETIME,UNITS_MS);
             if(currentOption==5)  controller_setNumericParameterValue(&sensorTriggerMode_preFlash2Time, MSG_FLASH2_PRETIME,UNITS_MS);
             if(currentOption==6)  controller_setNumericParameterValue(&sensorTriggerMode_preCloseTime, MSG_CLOSE_PRETIME,UNITS_MS);
             if(currentOption==7)  controller_setNumericParameterValue(&sensorTriggerMode_numCycles, MSG_CYCLES,UNITS_CYCLES);
             if(currentOption==8)  controller_setNumericParameterValue(&sensorTriggerMode_interCycleTime, MSG_INTERCYCLE_TIME,UNITS_MS);
                      
      }
   }
}


// Drops config View
void controller_showDropsConfig(){
  
  byte currentOption = 0;
 
  for(boolean exit = false;!exit;){
      
    display_printTitle(MSG_CONFIG_DROPS);

    // Show menu option
    if(currentOption==0) { display_printMessage(MSG_DROPS_COUNT); }
    if(currentOption==1) { display_printMessage(MSG_DROPS_DURATION); }
    if(currentOption==2) { display_printMessage(MSG_DROPS_INTERVAL); }
    
    keyboard_waitForAnyKey();
    
    if(lastKey==KEY_A) circularList_incrementBy(&currentOption, 0, 2, -1);
    if(lastKey==KEY_B) circularList_incrementBy(&currentOption, 0, 2, 1);
    if(lastKey==KEY_AH) { config_saveBackup_sensorTriggerMode(); exit = true; } 
    if(lastKey==KEY_BH) {
          
          if(currentOption==0) controller_setNumericParameterValue(&sensorTriggerMode_dropsCount, MSG_DROPS_COUNT, UNITS_DROPS);
          if(currentOption==1) controller_setNumericParameterValue(&sensorTriggerMode_dropsDuration, MSG_DROPS_DURATION, UNITS_MS);
          if(currentOption==2) controller_setNumericParameterValue(&sensorTriggerMode_dropsInterval, MSG_DROPS_INTERVAL, UNITS_MS);
    }
  }
}



// set of sensorlimit
void controller_setSensorLimit(byte sensorType){
  
  if(system_sensorTuningMode==SENSOR_TUNING_VISUAL) controller_setSensorLimitVisual(sensorType);
  if(system_sensorTuningMode==SENSOR_TUNING_NUMERIC) controller_setSensorLimitNumeric(sensorType);

}



// set of sensorlimit in visual mode
void controller_setSensorLimitVisual(byte sensorType){

     unsigned int sensorValue;
     unsigned int *sensorLimit;
     byte sensorPin;
     byte sensorMode;
     

     sensor_getConfiguration(sensorType, &sensorLimit, &sensorPin, &sensorMode);
     
     display_printTitle(MSG_SENSOR_LIMIT);

     do { 
          sensorValue = sensor_read(sensorPin);
          byte sensorValueEquivalent = map(sensorValue, 0, 999, 0, LCD_COLS-1);
          byte sensorLimitEquivalent = map(*sensorLimit, 0, 999, 0, LCD_COLS-1);
          
          lcd.setCursor(0,1);
          
          for (byte i=0; i < LCD_COLS; i++) {
              if(i==sensorLimitEquivalent){
                 if (sensorMode==SENSOR_MODE_HIGHER){
                     if (sensorValueEquivalent >= sensorLimitEquivalent) buzzer_beep(100); 
                     lcd.write((uint8_t)SYMBOL_UP);
                 } 
                 else                  
                 if (sensorMode==SENSOR_MODE_LOWER){
                     if (sensorValueEquivalent <= sensorLimitEquivalent) buzzer_beep(100); 
                     lcd.write((uint8_t)SYMBOL_DOWN);
                 }
              }
              if(i < sensorValueEquivalent) lcd.write((uint8_t)SYMBOL_BOX); else lcd.print(" ");
          }
          
          keyboard_scan();
             
          if (lastKey==KEY_A) circularList_incrementBy(sensorLimit, 0, 999, 64);
          if (lastKey==KEY_B) circularList_incrementBy(sensorLimit, 0, 999, -64);
               
          if (lastKey == KEY_ABH) {

               if (sensorMode==SENSOR_MODE_HIGHER) circularList_matchBy(sensorLimit, sensorValue, 0, 999, 64);
               if (sensorMode==SENSOR_MODE_LOWER) circularList_matchBy(sensorLimit, sensorValue, 0, 999, -64);
           } 
      
          
     } while (lastKey!=KEY_AH);
}

// set of sensorlimit in numeric mode
void controller_setSensorLimitNumeric(byte sensorType){

     unsigned int sensorValue = 0;
     unsigned int previousSensorValue = 0;
     unsigned int *limitValue;
     byte currentPosition = 2;
     byte sensorPin;
     byte sensorMode;
       
     sensor_getConfiguration(sensorType, &limitValue, &sensorPin, &sensorMode);    
     
     sensorValue = sensor_read(sensorPin);
     
     lcd.clear();
     display_printMessage(MSG_SENSOR_VALUE);
     lcd.setCursor(0,1);
     display_printMessage(MSG_LIMIT_VALUE);
     
     if (sensorMode==SENSOR_MODE_HIGHER) {
             lcd.setCursor(15,1);
             lcd.write((uint8_t)SYMBOL_UP);
     }
     if (sensorMode==SENSOR_MODE_LOWER) {
             lcd.setCursor(15,1);
             lcd.write((uint8_t)SYMBOL_DOWN);
     }       
                    
     lcd.setCursor(9,0);
     display_leadingZeroNumber(sensorValue, 3);
          
     lcd.setCursor(9,1);
     display_leadingZeroNumber(*limitValue, 3);
     
     keyboard_waitForNokey();

     do { 
         
           sensorValue = sensor_read(sensorPin);
                    
           if (sensorValue != previousSensorValue) {
             lcd.noBlink();
             lcd.setCursor(9,0);
             display_leadingZeroNumber(sensorValue, 3);
             lcd.setCursor(9+currentPosition,1);
             lcd.blink();
           }
        
           keyboard_scan();
           
           if (lastKey == KEY_ABH) {
               if (sensorMode==SENSOR_MODE_HIGHER) circularList_matchBy(limitValue, sensorValue, 0, 999, 10);
               if (sensorMode==SENSOR_MODE_LOWER) circularList_matchBy(limitValue, sensorValue, 0, 999, -10);
                         
               lcd.setCursor(9,1);
               display_leadingZeroNumber(*limitValue, 3);
           } 
           
           if (lastKey!=KEY_NONE) controller_setUnsignedIntValue(limitValue, &currentPosition, 3, 9, 1);     
          
           if (((sensorMode==SENSOR_MODE_HIGHER && sensorValue >= *limitValue) || (sensorMode==SENSOR_MODE_LOWER  && sensorValue <= *limitValue)) && lastKey==KEY_NONE) buzzer_beep(100); 
           else delay(20);
          
           previousSensorValue = sensorValue;
          
     } while (lastKey!=KEY_AH);
     
     lcd.noBlink();
}

// set of interval units
void controller_setUnits(byte *variable, const prog_char* msg){
  
     do { 
       
      display_printTitle(msg);
      display_printUnits(*variable);
      
      keyboard_waitForAnyKey();
      
      if (lastKey==KEY_A) circularList_incrementBy(variable, 0, 4, -1);
      if (lastKey==KEY_B) circularList_incrementBy(variable, 0, 4, 1);
   
     } while (lastKey!=KEY_AH);     
}

// set of shooting mode
void controller_setShootingMode(byte *variable){
  
     do { 
       
      display_printTitle(MSG_SHOOTING_MODE);
      display_printShootingMode(*variable);
      
      keyboard_waitForAnyKey();
      
      if (lastKey==KEY_A) circularList_incrementBy(variable, 0, 2, -1);
      if (lastKey==KEY_B) circularList_incrementBy(variable, 0, 2, 1);
   
     } while (lastKey!=KEY_AH);     
}

// set of sensor tunning mode
void controller_setSensorTuningMode(byte *value){
  
     do { 
       
      display_printTitle(MSG_SENSOR_TUNING);
      display_printInterfaceSensorMode(*value);
      
      keyboard_waitForAnyKey();
      
      if (lastKey==KEY_A) circularList_incrementBy(value, 0, 1, -1);
      if (lastKey==KEY_B) circularList_incrementBy(value, 0, 1, 1);
   
     } while (lastKey!=KEY_AH);     
}

// set of sensor type
void controller_setSensorType(byte *value){
  
  do { 
       
      display_printTitle(MSG_SENSOR_TYPE);
      display_printSensorType(*value);
      
      keyboard_waitForAnyKey();
      
      if (lastKey==KEY_A) circularList_incrementBy(value, 0, 4, -1);
      if (lastKey==KEY_B) circularList_incrementBy(value, 0, 4, 1);
   
     } while (lastKey!=KEY_AH); 
 
}


// set of device port type
void controller_setDevicePortType(byte *variable){
  
     do { 
       
      display_printTitle(MSG_DEVICE_PORT_TYPE);
      display_printDevicePortType(*variable);
      
      keyboard_waitForAnyKey();
      
      if (lastKey==KEY_A) circularList_incrementBy(variable, 0, 2, -1);
      if (lastKey==KEY_B) circularList_incrementBy(variable, 0, 2, 1);
      
     } while (lastKey!=KEY_AH);    
    
     device_init(); 
}

// set of numeric parameter value
void controller_setNumericParameterValue(unsigned int *value, const prog_char* msg, byte units){
     
     lcd.clear();
     lcd.print(">");
     display_printMessage(msg);
     
     lcd.setCursor(6,1);
     display_printUnits(units);
     
     lcd.setCursor(0,1);     
     display_leadingZeroNumber(*value, 5);
     
     byte currentPosition = 4;
     lcd.setCursor(currentPosition,1);
     lcd.blink();
     
     do{
       keyboard_scan();
       if (lastKey!=KEY_NONE) controller_setUnsignedIntValue(value, &currentPosition, 5, 0, 1);     
     
     } while(lastKey!=KEY_AH);
     
     lcd.noBlink();
}

// set of unsigned integer value assisted by other function.
void controller_setUnsignedIntValue(unsigned int *value, byte *currentPos, byte positions, byte col, byte row){
     
     if (positions>5) positions = 5;
     byte values[positions];

     byte counter = 0;
       
     if (positions>4) { values[counter] = *value/10000; counter++; }
     if (positions>3) { values[counter] = (*value%10000)/1000; counter++; }
     if (positions>2) { values[counter] = (*value%1000)/100; counter++; }
     if (positions>1) { values[counter] = (*value%100)/10; counter++; }
     if (positions>0) { values[counter] = *value%10; counter++; }
    
      if (lastKey==KEY_A) {
           
             if (*currentPos == 0 && positions == 5) circularList_incrementBy(&values[*currentPos],0,5, 1);
             else circularList_incrementBy(&values[*currentPos],0,9, 1); 
      }
      if (lastKey==KEY_B) {
        
             if (*currentPos == 0 && positions == 5) circularList_incrementBy(&values[*currentPos],0,5, -1);
             else circularList_incrementBy(&values[*currentPos],0,9, -1);
      }
      if (lastKey==KEY_BH) circularList_incrementBy(currentPos,0, positions-1, -1);             
     
     counter = positions-1;
     *value = 0;
     
     if (positions>0) { *value = *value + values[counter]; counter--; }
     if (positions>1) { *value = *value + values[counter]*10; counter--; }
     if (positions>2) { *value = *value + values[counter]*100; counter--; }
     if (positions>3) { *value = *value + values[counter]*1000; counter--; }
     if (positions>4) { *value = *value + values[counter]*10000; }     
     
     lcd.noBlink();
     lcd.setCursor(col+*currentPos,row);
     lcd.print(values[*currentPos],10);
     lcd.setCursor(col+*currentPos,row);
     lcd.blink();
}

// Alert for confirm action
boolean controller_confirmAction(const prog_char* str){
  
     boolean confirm = false;
     
     do { 
       
      display_printQuestion(str);
    
      lcd.setCursor(2,1);
     
      if(confirm) lcd.print(" "); else lcd.print("<");
      display_printMessage(MSG_NO);
      if(confirm) lcd.print(" "); else lcd.print(">");
     
      lcd.setCursor(9,1);
     
      if(confirm) lcd.print("<"); else lcd.print(" ");
      display_printMessage(MSG_YES);
      if(confirm) lcd.print(">"); else lcd.print(" ");      
       
      keyboard_waitForAnyKey();
      
      if (lastKey==KEY_A || lastKey==KEY_B) { confirm = !confirm;  };
   
     } while (lastKey!=KEY_BH);   
     
     return confirm;  
}


