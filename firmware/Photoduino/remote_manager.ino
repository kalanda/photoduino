// Command codes
#define REMOTE_CMD_REMOTE_MODE_START                    0x01
#define REMOTE_CMD_REMOTE_MODE_STOP                     0x02
#define REMOTE_CMD_ALL_PARAM_REQUEST                    0x03
#define REMOTE_CMD_PARAM_REQUEST                        0x04
#define REMOTE_CMD_PARAM_UPDATE                         0x05  
#define REMOTE_CMD_SET_SENSOR_BEEP_ONLIMIT              0x06

#define REMOTE_CMD_MANUAL_CONTROL_AF_START              0x0A
#define REMOTE_CMD_MANUAL_CONTROL_AF_STOP               0x0B
#define REMOTE_CMD_MANUAL_CONTROL_SHUTTER_START         0x0C
#define REMOTE_CMD_MANUAL_CONTROL_SHUTTER_STOP          0x0D
#define REMOTE_CMD_MANUAL_CONTROL_SHOOT_FLASH1          0x0E
#define REMOTE_CMD_MANUAL_CONTROL_SHOOT_FLASH2          0x0F
#define REMOTE_CMD_MANUAL_CONTROL_DEVICE_ON             0x10
#define REMOTE_CMD_MANUAL_CONTROL_DEVICE_OFF            0x11
#define REMOTE_CMD_TEST_MAKE_DROPS                      0x12
#define REMOTE_CMD_RUN_INTERVALOMETER_MODE              0x13
#define REMOTE_CMD_RUN_SENSOR_TRIGGER_MODE              0x14
#define REMOTE_CMD_CANCEL_RUNMODE                       0x15
    
// Response codes
#define REMOTE_RSP_REPORT_READY                         0x01
#define REMOTE_RSP_REPORT_REMOTE_MODE                   0x02
#define REMOTE_RSP_REPORT_PARAM                         0x03
#define REMOTE_RSP_REPORT_SENSOR_READ                   0x04
#define REMOTE_RSP_REPORT_SYSTEM_BUSY                   0x05
#define REMOTE_RSP_REPORT_SYSTEM_IDLE                   0x06


// On sysex message from host
void sysexCallback(byte command, byte argc, byte*argv)
{
    
    switch(command){
        
       case REMOTE_CMD_REMOTE_MODE_START            : remote_mode_start(argc, argv); break;   
       case REMOTE_CMD_REMOTE_MODE_STOP             : remote_mode_stop(); break;               
       
       case REMOTE_CMD_ALL_PARAM_REQUEST            : remote_report_all_params(); break;
       case REMOTE_CMD_PARAM_REQUEST                : remote_report_param(argc, argv); break;   
       case REMOTE_CMD_PARAM_UPDATE                 : remote_set_param(argc, argv); break;       
       
       case REMOTE_CMD_SET_SENSOR_BEEP_ONLIMIT      : remote_set_beep_onlimit(argc, argv); break;  
       
       case REMOTE_CMD_MANUAL_CONTROL_AF_START      : camera_autofocusBegin(0); break;
       case REMOTE_CMD_MANUAL_CONTROL_AF_STOP       : camera_autofocusEnd(); break;   
       case REMOTE_CMD_MANUAL_CONTROL_SHUTTER_START : camera_shutterBegin(0); break;   
       case REMOTE_CMD_MANUAL_CONTROL_SHUTTER_STOP  : camera_shutterEnd(0);break;  
       
       case REMOTE_CMD_MANUAL_CONTROL_SHOOT_FLASH1  : flash_shoot(0, PINS_FLASH1); break;
       case REMOTE_CMD_MANUAL_CONTROL_SHOOT_FLASH2  : flash_shoot(0, PINS_FLASH2); break;
       
       case REMOTE_CMD_MANUAL_CONTROL_DEVICE_ON     : digitalWrite(PINS_DEVICE,HIGH); break;
       case REMOTE_CMD_MANUAL_CONTROL_DEVICE_OFF    : digitalWrite(PINS_DEVICE,LOW); break;
       
       case REMOTE_CMD_TEST_MAKE_DROPS              : remote_report_system_busy(false); 
                                                      solenoidValve_makeDrops(); 
                                                      remote_report_system_idle(); 
                                                      break;
                                                      
       case REMOTE_CMD_RUN_INTERVALOMETER_MODE      : remote_report_system_busy(true); 
                                                      runAs_intervalometer(); 
                                                      remote_report_system_idle(); 
                                                      controller_showRemoteMode();
                                                      break;
                                                      
       case REMOTE_CMD_RUN_SENSOR_TRIGGER_MODE      : remote_report_system_busy(true); 
                                                      runAs_sensorTriggerMode();
                                                      remote_report_system_idle(); 
                                                      controller_showRemoteMode();
                                                      break;
       
       case REMOTE_CMD_CANCEL_RUNMODE               : cancelFlag = true;
                                                      break;
       
              
       default:  FirmataLite.sendString("Unknown command");
                 break;      
    }
}

// Send a ready state to the host
void remote_sendReady(){
  
  byte FirmwareVersion[3] = { 1, CODE_MAJOR_VERSION, CODE_MINOR_VERSION };
  FirmataLite.sendSysex(REMOTE_RSP_REPORT_READY, 3, FirmwareVersion);
  
}

// Starts the remote mode
void remote_mode_start(byte argc, byte *argv){
  
  // Report to the host all params in the config eeprom  
  remote_report_all_params();
  
  // Start the sensor broadcasting mode
  if (argv[0]==1) remoteSensorBroadcastingBeepOnLimit = true;
  else remoteSensorBroadcastingBeepOnLimit = false;
  remoteSensorBroadcasting = true;
  
  // Start the remote mode and inform to the host
  remoteMode = true; 
  FirmataLite.sendSysex(REMOTE_RSP_REPORT_REMOTE_MODE, 0, 0);
             
}

void remote_mode_stop(){
  
  remoteMode = false; 
  byte FirmwareVersion[3] = { 0, CODE_MAJOR_VERSION, CODE_MINOR_VERSION };
  FirmataLite.sendSysex(REMOTE_RSP_REPORT_REMOTE_MODE, 3, FirmwareVersion);
             
}

void remote_report_param(byte address){
  byte eepromAddress[1] = { address };
  remote_report_param(1, eepromAddress);
}

// Report param value from eeprom
void remote_report_param(byte argc, byte *argv){
  
  // Read value from eeprom
  unsigned int address =  argv[0];
  unsigned int value = eeprom_readInt(address); 
  
  // Create response including the value code
  byte response[3] = {};
  response[0] = argv[0];
  response[1] = value/256;
  response[2] = value % 256;
  
  // Send response
  FirmataLite.sendSysex(REMOTE_RSP_REPORT_PARAM, 3, response);
  
}

void remote_report_all_params(){
   
  remote_report_param(EE_ADDR_system_useBacklight);
  remote_report_param(EE_ADDR_system_useSpeaker);
  remote_report_param(EE_ADDR_system_sensorTuningMode);
  remote_report_param(EE_ADDR_system_cameraShutterLag);
  remote_report_param(EE_ADDR_system_cameraMirrorLockUpTimeout);
  remote_report_param(EE_ADDR_system_useFlash1);
  remote_report_param(EE_ADDR_system_useFlash2);
  remote_report_param(EE_ADDR_system_devicePortType);
  
  remote_report_param(EE_ADDR_intervalometerMode_autofocusTime);
  remote_report_param(EE_ADDR_intervalometerMode_preFlash1Time);
  remote_report_param(EE_ADDR_intervalometerMode_preFlash2Time);
  remote_report_param(EE_ADDR_intervalometerMode_preCloseTime);
  remote_report_param(EE_ADDR_intervalometerMode_intervalUnits);
  remote_report_param(EE_ADDR_intervalometerMode_intervalValue);
  remote_report_param(EE_ADDR_intervalometerMode_numCycles);
  
  remote_report_param(EE_ADDR_sensorTriggerMode_sensorType);
  remote_report_param(EE_ADDR_sensorTriggerMode_sensorAudioLimit);
  remote_report_param(EE_ADDR_sensorTriggerMode_sensorBarrierLimit);
  remote_report_param(EE_ADDR_sensorTriggerMode_sensorLightLimit);
  remote_report_param(EE_ADDR_sensorTriggerMode_sensorShockLimit);
  remote_report_param(EE_ADDR_sensorTriggerMode_shootingMode);
  remote_report_param(EE_ADDR_sensorTriggerMode_autofocusTime);
  remote_report_param(EE_ADDR_sensorTriggerMode_preFlash1Time);
  remote_report_param(EE_ADDR_sensorTriggerMode_preFlash2Time);
  remote_report_param(EE_ADDR_sensorTriggerMode_preCloseTime);
  remote_report_param(EE_ADDR_sensorTriggerMode_numCycles);
  remote_report_param(EE_ADDR_sensorTriggerMode_interCycleTime);
  remote_report_param(EE_ADDR_sensorTriggerMode_dropsCount);
  remote_report_param(EE_ADDR_sensorTriggerMode_dropsDuration);
  remote_report_param(EE_ADDR_sensorTriggerMode_dropsInterval);
  
}

// Set param value in eeprom
void remote_set_param(byte argc, byte *argv){
    
  unsigned int address = argv[0];
  unsigned int value = argv[1]*256+argv[2];
  
  eeprom_writeInt(address, value); 
  config_loadBackup_all();
  backlight_init();
  device_init();
}

// Sensor broadcasting
void remote_sensor_broadcast(){
    
   byte sensorType = sensorTriggerMode_sensorType;
   boolean sensorOverflow = false;
   
   unsigned int sensorValue;
   unsigned int *sensorLimit;
   byte sensorPin;
   byte sensorMode;
   
   if (sensorTriggerMode_sensorType != SENSOR_TYPE_NONE){
     sensor_getConfiguration(sensorType, &sensorLimit, &sensorPin, &sensorMode);
     sensorValue = sensor_read(sensorPin);
     
     
     if ( ((sensorMode==SENSOR_MODE_HIGHER && sensorValue >= *sensorLimit) || 
           (sensorMode==SENSOR_MODE_LOWER  && sensorValue <= *sensorLimit)) ) {
           sensorOverflow = true;
           if (remoteSensorBroadcastingBeepOnLimit) buzzer_beep(50);
     } else {
           sensorOverflow = false;
     }
   
   } else {
     sensorOverflow = true;
     sensorValue = 999;
   }
   
   byte responseValues[4] = {sensorType, sensorValue/256, sensorValue % 256, sensorOverflow};  
   
   FirmataLite.sendSysex(REMOTE_RSP_REPORT_SENSOR_READ, 4, responseValues); 
}

void remote_report_system_busy(boolean cancelable){
   
  byte response[1] = {cancelable};
   FirmataLite.sendSysex(REMOTE_RSP_REPORT_SYSTEM_BUSY, 1, response); 
}

void remote_report_system_idle(){
  cancelFlag = false;
  FirmataLite.sendSysex(REMOTE_RSP_REPORT_SYSTEM_IDLE, 0, 0); 
}

void remote_set_beep_onlimit(byte argc, byte *argv){
    
  if (argv[0]==1) remoteSensorBroadcastingBeepOnLimit = true;
  else remoteSensorBroadcastingBeepOnLimit = false;
  
  
}


