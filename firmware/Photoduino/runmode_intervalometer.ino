/**
 *
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
 
 // Run interval mode
void runAs_intervalometer() { 
   
   display_printTitle(MSG_RUNNING);

   keyboard_waitForNokey();
   
   attachInterrupt(0, keyboard_interrupts, CHANGE);
   attachInterrupt(1, keyboard_interrupts, CHANGE);
   
   for(unsigned int cyclesCounter = 0; (cancelFlag==false && !(intervalometerMode_numCycles>0 && cyclesCounter >= intervalometerMode_numCycles));cyclesCounter++) { 
     
     camera_autofocusBegin(intervalometerMode_autofocusTime); 
     camera_shutterBegin(system_cameraShutterLag); 
  
     if (system_useFlash1) flash_shoot(intervalometerMode_preFlash1Time, PINS_FLASH1);
     if (system_useFlash2) flash_shoot(intervalometerMode_preFlash2Time, PINS_FLASH2); 
     
     camera_shutterEnd(intervalometerMode_preCloseTime); 
     camera_autofocusEnd(); 
     
     waitInterval();
     
     if(remoteMode && FirmataLite.available()) FirmataLite.processInput();
    
   }
   
   display_printAborting();
   keyboard_waitForNokey();
      
   detachInterrupt(0);
   detachInterrupt(1);

}

// Wait interval time
void waitInterval(){
  
   if(intervalometerMode_intervalUnits == UNITS_MS)     delay(intervalometerMode_intervalValue); 
   if(intervalometerMode_intervalUnits == UNITS_SECS)   delaySeconds(intervalometerMode_intervalValue);  
   if(intervalometerMode_intervalUnits == UNITS_MINS)   delayMinutes(intervalometerMode_intervalValue);  
   if(intervalometerMode_intervalUnits == UNITS_HOURS)  delayHours(intervalometerMode_intervalValue);  
   if(intervalometerMode_intervalUnits == UNITS_DAYS)   delayDays(intervalometerMode_intervalValue);  
}

// Wait a time in seconds
void delaySeconds(unsigned int value) {
  for (unsigned int i = 0; i<value && !cancelFlag; i++) delay(1000); 
}

// Wait a time in minutes
void delayMinutes(unsigned int value) {
  for (unsigned int i = 0; i<value && !cancelFlag; i++) delaySeconds(60); 
}

// Wait a time in hours
void delayHours(unsigned int value){
  for (unsigned int i = 0; i<value && !cancelFlag; i++) delayMinutes(60); 
}

// Wait a time in days
void delayDays(unsigned int value){
  for (unsigned int i = 0; i<value && !cancelFlag; i++) delayHours(24); 
}




