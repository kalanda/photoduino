package com.photoduino.remote;

public class PhotoduinoCommands {
	
	// Command codes
	public static final int  CMD_REMOTE_MODE_START					= 0x01;
	public static final int  CMD_REMOTE_MODE_STOP					= 0x02;
	public static final int  CMD_ALL_PARAM_REQUEST					= 0x03;
	public static final int  CMD_PARAM_REQUEST						= 0x04;
	public static final int  CMD_PARAM_UPDATE						= 0x05;	
	public static final int  CMD_SET_SENSOR_BEEP_ONLIMIT     		= 0x06;
	public static final int  CMD_MANUAL_CONTROL_AF_START			= 0x0A;
	public static final int  CMD_MANUAL_CONTROL_AF_STOP				= 0x0B;
	public static final int  CMD_MANUAL_CONTROL_SHUTTER_START		= 0x0C;
	public static final int  CMD_MANUAL_CONTROL_SHUTTER_STOP		= 0x0D;
	public static final int  CMD_MANUAL_CONTROL_SHOOT_FLASH1		= 0x0E;
	public static final int  CMD_MANUAL_CONTROL_SHOOT_FLASH2		= 0x0F;
	public static final int  CMD_MANUAL_CONTROL_DEVICE_ON			= 0x10;
	public static final int  CMD_MANUAL_CONTROL_DEVICE_OFF			= 0x11;
	public static final int  CMD_TEST_MAKE_DROPS                    = 0x12;
	public static final int  CMD_RUN_INTERVALOMETER_MODE 		    = 0x13;
	public static final int  CMD_RUN_SENSOR_TRIGGER_MODE 		    = 0x14;
	public static final int  CMD_CANCEL_RUNMODE                     = 0x15;


}
