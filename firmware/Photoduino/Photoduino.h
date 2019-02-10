/**
 * config_manager.ino
 */
void config_init();
void config_loadDefaults_all();
void config_saveBackup_all();
void config_loadBackup_all();
void config_loadBackup_system();
void config_loadDefaults_system();
void config_saveBackup_system();
void config_loadDefaults_intervalometerMode();
void config_saveBackup_intervalometerMode();
void config_loadBackup_intervalometerMode();
void config_loadBackup_sensorTriggerMode();
void config_loadDefaults_sensorTriggerMode();
void config_saveBackup_sensorTriggerMode();

/**
 * controller_manager.ino
 */
void controller_run();
void controller_showRemoteMode();
void controller_showWelcome();
void controller_showMainMenu();
void controller_showIntervalMenu();
void controller_showSensorTriggerMenu();
void controller_showSystemConfig();
void controller_showIntervalConfig();
void controller_showSensorTriggerConfig();
void controller_showDropsConfig();
void controller_setSensorLimit(byte sensorType);
void controller_setSensorLimitVisual(byte sensorType);
void controller_setSensorLimitNumeric(byte sensorType);
void controller_setUnits(byte *variable, const prog_char* msg);
void controller_setShootingMode(byte *variable);
void controller_setSensorTuningMode(byte *value);
void controller_setSensorType(byte *value);
void controller_setDevicePortType(byte *variable);
void controller_setNumericParameterValue(unsigned int *value, const prog_char* msg, byte units);
void controller_setUnsignedIntValue(unsigned int *value, byte *currentPos, byte positions, byte col, byte row);
boolean controller_confirmAction(const prog_char* str);

/**
 * devices_manager.ino
 */
void flash_shoot(unsigned int previousDelay, byte pin) ;
void camera_shutterBegin(unsigned int shutterLag);
void camera_shutterEnd(unsigned int preCloseTime);
void camera_autofocusBegin(unsigned int autofocusTime);
void camera_autofocusEnd();
void camera_mirrorLockUp(unsigned int autofocusTime, unsigned int shutterLag);
unsigned int sensor_read(byte sensorPin) ;
void sensor_getConfiguration(byte sensorType, unsigned int **limitValue, byte *sensorPin, byte *sensorMode) ;
boolean sensor_waitFor(byte sensorType, unsigned int limitTime);
void keyboard_interrupts();
void keyboard_scan();
void keyboard_scan(boolean quickmode) ;
void keyboard_waitForAnyKey();
void keyboard_waitForNokey();
void buzzer_beep(int time);
void backlight_init();
void backlight_toggle();
void display_printMessage(const prog_char* str) ;
void display_printTitle(const prog_char* str);
void display_printQuestion(const prog_char* str);
void display_printEnumeration(byte num, const prog_char* str);
void display_printResetting();
void display_printAborting();
void display_printBoolean(boolean value);
void display_printUnits(byte units);
void display_printSensorType(byte type);
void display_printShootingMode(byte mode);
void display_printInterfaceSensorMode(byte mode);
void display_printProgressBar(int howMany, int total);
void display_printDevicePortType(byte type);
void display_leadingZeroNumber(unsigned int number, byte positions);
void device_init();
void laser_turnOn();
void laser_turnOff();
void solenoidValve_makeDrops();

/**
 * functions_util.ino
 */
void eeprom_writeInt(unsigned int address, unsigned int value);
unsigned int eeprom_readInt(unsigned int address);
void circularList_incrementBy(byte *value, byte minimun, byte maximun, int incrementBy);
void circularList_incrementBy(unsigned int *value, unsigned int minimun, unsigned int maximun, int incrementBy);
void circularList_matchBy(unsigned int *value, unsigned int targetValue, unsigned int minimun, unsigned int maximun, int offset);

/**
 * runmode_intervalometer.ino
 */
void runAs_intervalometer();
void waitInterval();
void delaySeconds(unsigned int value);
void delayMinutes(unsigned int value);
void delayHours(unsigned int value);
void delayDays(unsigned int value);

/**
 * runmode_sensor_trigger.ino
 */
void runAs_sensorTriggerMode();

/**
 * remote_manager.ino
 */
void sysexCallback(byte command, byte argc, byte*argv);
void remote_sendReady();
void remote_mode_stop();
void remote_report_param(byte address);
void remote_report_param(byte argc, byte *argv);
void remote_report_all_params();
void remote_set_param(byte argc, byte *argv);
void remote_sensor_broadcast();
void remote_report_system_busy(boolean cancelable);
void remote_report_system_idle();
void remote_set_beep_onlimit(byte argc, byte *argv);
