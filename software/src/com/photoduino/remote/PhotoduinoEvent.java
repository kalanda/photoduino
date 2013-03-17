package com.photoduino.remote;

public class PhotoduinoEvent  {
	
	private int command;
	private int[] values;
	
	public PhotoduinoEvent(int command, int[] values) {
	
		this.setCommand(command);
		this.setValues(values);

	}

	public int getCommand() {
		return command;
	}
	
	private void setCommand(int command) {
		this.command = command;
	}

	public int[] getValues() {
		return values;
	}

	private void setValues(int[] values) {
		this.values = values;
	}

	// Response codes
	public static final int  RSP_REPORT_READY                       = 0x01;
	public static final int  RSP_REPORT_REMOTE_MODE	 				= 0x02;
	public static final int  RSP_REPORT_PARAM		 				= 0x03;
	public static final int  RSP_REPORT_SENSOR_READ	 				= 0x04;
	public static final int  RSP_REPORT_SYSTEM_BUSY                 = 0x05;
	public static final int  RSP_REPORT_SYSTEM_IDLE                 = 0x06;
}
