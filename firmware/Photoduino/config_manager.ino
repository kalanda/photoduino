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

void config_init(){

  // Check if the firmware version is the same of eeprom config
  if (
    EEPROM.read(EE_ADDR_SIGNATURE_CODE1) == SIGNATURE_CODE1 && 
    EEPROM.read(EE_ADDR_SIGNATURE_CODE2) == SIGNATURE_CODE2 && 
    EEPROM.read(EE_ADDR_SIGNATURE_CODE3) == SIGNATURE_CODE3 && 
    EEPROM.read(EE_ADDR_SIGNATURE_CODE4) == SIGNATURE_CODE4 &&
    EEPROM.read(EE_ADDR_CODE_MAJOR_VERSION) == CODE_MAJOR_VERSION &&
    EEPROM.read(EE_ADDR_CODE_MINOR_VERSION) == CODE_MINOR_VERSION 
    ) {

    // loads in ram the eeprom config
    config_loadBackup_all();

  } 
  else {

    backlight_toggle();
    display_printResetting();

    // clear the eeprom
    for (unsigned int i = 0; i < EEPROM_SIZE; i++) {
      display_printProgressBar(i, EEPROM_SIZE);
      EEPROM.write(i, 0x00);
    }

    // writes sign codes
    EEPROM.write(EE_ADDR_SIGNATURE_CODE1,SIGNATURE_CODE1);
    EEPROM.write(EE_ADDR_SIGNATURE_CODE2,SIGNATURE_CODE2);
    EEPROM.write(EE_ADDR_SIGNATURE_CODE3,SIGNATURE_CODE3);
    EEPROM.write(EE_ADDR_SIGNATURE_CODE4,SIGNATURE_CODE4);
    EEPROM.write(EE_ADDR_CODE_MAJOR_VERSION,CODE_MAJOR_VERSION);
    EEPROM.write(EE_ADDR_CODE_MINOR_VERSION,CODE_MINOR_VERSION);

    // load defaults to ram and save on eeprom
    config_loadDefaults_all();
    config_saveBackup_all();
  } 
}

void config_loadDefaults_all(){

  config_loadDefaults_system();
  config_loadDefaults_intervalometerMode();
  config_loadDefaults_sensorTriggerMode();
}

void config_saveBackup_all(){

  config_saveBackup_system();
  config_saveBackup_intervalometerMode();
  config_saveBackup_sensorTriggerMode();
}

void config_loadBackup_all(){

  config_loadBackup_system();
  config_loadBackup_intervalometerMode();
  config_loadBackup_sensorTriggerMode();
} 

// Load the system config from eeprom to ram
void config_loadBackup_system(){   

  system_useBacklight = EEPROM.read(EE_ADDR_system_useBacklight);
  system_useSpeaker = EEPROM.read(EE_ADDR_system_useSpeaker);
  system_sensorTuningMode = EEPROM.read(EE_ADDR_system_sensorTuningMode);
  system_cameraShutterLag = eeprom_readInt(EE_ADDR_system_cameraShutterLag);
  system_cameraMirrorLockUpTimeout = eeprom_readInt(EE_ADDR_system_cameraMirrorLockUpTimeout);
  system_useFlash1 = EEPROM.read(EE_ADDR_system_useFlash1);
  system_useFlash2 = EEPROM.read(EE_ADDR_system_useFlash2);
  system_devicePortType = EEPROM.read(EE_ADDR_system_devicePortType);
}

// Load the default system config to ram
void config_loadDefaults_system() {

  system_useBacklight = DEFAULT_system_useBacklight;
  system_useSpeaker = DEFAULT_system_useSpeaker;
  system_sensorTuningMode = DEFAULT_system_sensorTuningMode;
  system_cameraShutterLag = DEFAULT_system_cameraShutterLag;
  system_cameraMirrorLockUpTimeout = DEFAULT_system_cameraMirrorLockUpTimeout;
  system_useFlash1 = DEFAULT_system_useFlash1;
  system_useFlash2 = DEFAULT_system_useFlash2;
  system_devicePortType = DEFAULT_system_devicePortType;
}

// Save the system config from ram to eeprom
void config_saveBackup_system(){ 

  EEPROM.write(EE_ADDR_system_useBacklight, system_useBacklight);
  EEPROM.write(EE_ADDR_system_useSpeaker, system_useSpeaker);
  EEPROM.write(EE_ADDR_system_sensorTuningMode, system_sensorTuningMode);
  eeprom_writeInt(EE_ADDR_system_cameraShutterLag, system_cameraShutterLag);
  eeprom_writeInt(EE_ADDR_system_cameraMirrorLockUpTimeout, system_cameraMirrorLockUpTimeout);
  EEPROM.write(EE_ADDR_system_useFlash1, system_useFlash1);
  EEPROM.write(EE_ADDR_system_useFlash2, system_useFlash2);
  EEPROM.write(EE_ADDR_system_devicePortType, system_devicePortType);
}

// Load the default interval mode config to ram
void config_loadDefaults_intervalometerMode() {

  intervalometerMode_autofocusTime =   DEFAULT_intervalometerMode_autofocusTime;
  intervalometerMode_preFlash1Time =   DEFAULT_intervalometerMode_preFlash1Time;
  intervalometerMode_preFlash2Time =   DEFAULT_intervalometerMode_preFlash2Time;
  intervalometerMode_preCloseTime =    DEFAULT_intervalometerMode_preCloseTime;
  intervalometerMode_intervalUnits =   DEFAULT_intervalometerMode_intervalUnits;
  intervalometerMode_intervalValue =   DEFAULT_intervalometerMode_intervalValue;
  intervalometerMode_numCycles =       DEFAULT_intervalometerMode_numCycles;
}

// Save the inverval mode config to eeprom
void config_saveBackup_intervalometerMode(){

  eeprom_writeInt(EE_ADDR_intervalometerMode_autofocusTime, intervalometerMode_autofocusTime);
  eeprom_writeInt(EE_ADDR_intervalometerMode_preFlash1Time, intervalometerMode_preFlash1Time);
  eeprom_writeInt(EE_ADDR_intervalometerMode_preFlash2Time, intervalometerMode_preFlash2Time);
  eeprom_writeInt(EE_ADDR_intervalometerMode_preCloseTime, intervalometerMode_preCloseTime);
  EEPROM.write(EE_ADDR_intervalometerMode_intervalUnits, intervalometerMode_intervalUnits);
  eeprom_writeInt(EE_ADDR_intervalometerMode_intervalValue, intervalometerMode_intervalValue);
  eeprom_writeInt(EE_ADDR_intervalometerMode_numCycles, intervalometerMode_numCycles);  

}

// Load the interval mode config from eeprom to ram
void config_loadBackup_intervalometerMode(){  

  intervalometerMode_autofocusTime = eeprom_readInt(EE_ADDR_intervalometerMode_autofocusTime);
  intervalometerMode_preFlash1Time = eeprom_readInt(EE_ADDR_intervalometerMode_preFlash1Time);
  intervalometerMode_preFlash2Time = eeprom_readInt(EE_ADDR_intervalometerMode_preFlash2Time);
  intervalometerMode_preCloseTime = eeprom_readInt(EE_ADDR_intervalometerMode_preCloseTime);
  intervalometerMode_intervalUnits = EEPROM.read(EE_ADDR_intervalometerMode_intervalUnits);
  intervalometerMode_intervalValue = eeprom_readInt(EE_ADDR_intervalometerMode_intervalValue);
  intervalometerMode_numCycles = eeprom_readInt(EE_ADDR_intervalometerMode_numCycles);
}

// Load the sensorTriggerMode from eeprom to ram
void config_loadBackup_sensorTriggerMode(){   

  sensorTriggerMode_sensorType = EEPROM.read(EE_ADDR_sensorTriggerMode_sensorType);
  sensorTriggerMode_sensorAudioLimit = eeprom_readInt(EE_ADDR_sensorTriggerMode_sensorAudioLimit);
  sensorTriggerMode_sensorBarrierLimit = eeprom_readInt(EE_ADDR_sensorTriggerMode_sensorBarrierLimit);
  sensorTriggerMode_sensorLightLimit = eeprom_readInt(EE_ADDR_sensorTriggerMode_sensorLightLimit);
  sensorTriggerMode_sensorShockLimit = eeprom_readInt(EE_ADDR_sensorTriggerMode_sensorShockLimit);
  sensorTriggerMode_shootingMode = EEPROM.read(EE_ADDR_sensorTriggerMode_shootingMode);
  sensorTriggerMode_autofocusTime = eeprom_readInt(EE_ADDR_sensorTriggerMode_autofocusTime);
  sensorTriggerMode_preFlash1Time = eeprom_readInt(EE_ADDR_sensorTriggerMode_preFlash1Time);
  sensorTriggerMode_preFlash2Time = eeprom_readInt(EE_ADDR_sensorTriggerMode_preFlash2Time);
  sensorTriggerMode_preCloseTime = eeprom_readInt(EE_ADDR_sensorTriggerMode_preCloseTime);
  sensorTriggerMode_numCycles =  eeprom_readInt(EE_ADDR_sensorTriggerMode_numCycles);
  sensorTriggerMode_interCycleTime =  eeprom_readInt(EE_ADDR_sensorTriggerMode_interCycleTime);
  sensorTriggerMode_dropsCount =  eeprom_readInt(EE_ADDR_sensorTriggerMode_dropsCount);
  sensorTriggerMode_dropsDuration =  eeprom_readInt(EE_ADDR_sensorTriggerMode_dropsDuration);
  sensorTriggerMode_dropsInterval =  eeprom_readInt(EE_ADDR_sensorTriggerMode_dropsInterval);
}

// Load the default sensorTriggerMode config to ram
void config_loadDefaults_sensorTriggerMode() {

  sensorTriggerMode_sensorType =         DEFAULT_sensorTriggerMode_sensorType;
  sensorTriggerMode_sensorAudioLimit =   DEFAULT_sensorTriggerMode_sensorAudioLimit;
  sensorTriggerMode_sensorBarrierLimit = DEFAULT_sensorTriggerMode_sensorBarrierLimit;
  sensorTriggerMode_sensorLightLimit =   DEFAULT_sensorTriggerMode_sensorLightLimit;
  sensorTriggerMode_sensorShockLimit =   DEFAULT_sensorTriggerMode_sensorShockLimit;
  sensorTriggerMode_shootingMode =       DEFAULT_sensorTriggerMode_shootingMode; 
  sensorTriggerMode_autofocusTime =      DEFAULT_sensorTriggerMode_autofocusTime;  
  sensorTriggerMode_preFlash1Time =      DEFAULT_sensorTriggerMode_preFlash1Time;
  sensorTriggerMode_preFlash2Time =      DEFAULT_sensorTriggerMode_preFlash2Time;
  sensorTriggerMode_preCloseTime =       DEFAULT_sensorTriggerMode_preCloseTime;
  sensorTriggerMode_numCycles =          DEFAULT_sensorTriggerMode_numCycles;
  sensorTriggerMode_interCycleTime =     DEFAULT_sensorTriggerMode_interCycleTime;
  sensorTriggerMode_dropsCount =         DEFAULT_sensorTriggerMode_dropsCount;
  sensorTriggerMode_dropsDuration =      DEFAULT_sensorTriggerMode_dropsDuration;
  sensorTriggerMode_dropsInterval =      DEFAULT_sensorTriggerMode_dropsInterval;
}

// Save the sensorTriggerMode from ram to eeprom
void config_saveBackup_sensorTriggerMode(){ 

  EEPROM.write(EE_ADDR_sensorTriggerMode_sensorType, sensorTriggerMode_sensorType);
  eeprom_writeInt(EE_ADDR_sensorTriggerMode_sensorAudioLimit, sensorTriggerMode_sensorAudioLimit);
  eeprom_writeInt(EE_ADDR_sensorTriggerMode_sensorBarrierLimit, sensorTriggerMode_sensorBarrierLimit);
  eeprom_writeInt(EE_ADDR_sensorTriggerMode_sensorLightLimit, sensorTriggerMode_sensorLightLimit);
  eeprom_writeInt(EE_ADDR_sensorTriggerMode_sensorShockLimit, sensorTriggerMode_sensorShockLimit);
  EEPROM.write(EE_ADDR_sensorTriggerMode_shootingMode, sensorTriggerMode_shootingMode);
  eeprom_writeInt(EE_ADDR_sensorTriggerMode_autofocusTime, sensorTriggerMode_autofocusTime);
  eeprom_writeInt(EE_ADDR_sensorTriggerMode_preFlash1Time, sensorTriggerMode_preFlash1Time);
  eeprom_writeInt(EE_ADDR_sensorTriggerMode_preFlash2Time, sensorTriggerMode_preFlash2Time);
  eeprom_writeInt(EE_ADDR_sensorTriggerMode_preCloseTime, sensorTriggerMode_preCloseTime);
  eeprom_writeInt(EE_ADDR_sensorTriggerMode_numCycles, sensorTriggerMode_numCycles);
  eeprom_writeInt(EE_ADDR_sensorTriggerMode_interCycleTime, sensorTriggerMode_interCycleTime); 
  eeprom_writeInt(EE_ADDR_sensorTriggerMode_dropsCount, sensorTriggerMode_dropsCount); 
  eeprom_writeInt(EE_ADDR_sensorTriggerMode_dropsDuration, sensorTriggerMode_dropsDuration); 
  eeprom_writeInt(EE_ADDR_sensorTriggerMode_dropsInterval, sensorTriggerMode_dropsInterval); 
}

