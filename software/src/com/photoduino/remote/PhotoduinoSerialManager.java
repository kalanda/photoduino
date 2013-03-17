package com.photoduino.remote;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import gnu.io.CommPortIdentifier; 
import gnu.io.SerialPort;
import gnu.io.SerialPortEvent; 
import gnu.io.SerialPortEventListener; 

import java.util.ArrayList;
import java.util.Enumeration;

import org.apache.log4j.Logger;


public class PhotoduinoSerialManager extends PhotoduinoEventDispatcher implements SerialPortEventListener {
	
	private Logger logger = Logger.getLogger(getClass());
	
	/**
	 * Static values
	 */
	private static final int CONNECTION_TIME_OUT 	= 2000;   // Timeout for connection
	private static final int BAUD_RATE 				= 57600;  // Connection baudrate
	private static final int SYSEX_MAX_DATA_BYTES 	= 32;	  // Max length of a sysex message
	private static final int SYSEX_START       		= 0xF0;   // start a SysEx message
	private static final int SYSEX_END         		= 0xF7;   // end a SysEx message
	private static final int SYSEX_STRING			= 0x71;   // command identifier for string messages
	
	/**
	 * Private fields
	 */
	private Boolean connected;
	private SerialPort serialPort;
	private InputStream serialInput;
	private OutputStream serialOutput;
	private int[] storedInputData;
	private boolean parsingSysex;
	private int sysexBytesRead;
	
	
	/**
	 * Constructor
	 */
	public PhotoduinoSerialManager(){
		super();
		connected = false;
		storedInputData = new int[SYSEX_MAX_DATA_BYTES];
	}
	
	/**
	 * Return if is currently connected
	 * @return
	 */
	public Boolean isConnected(){
		return connected;
	}
	
	/**
	 * Create a connection to the specified serial port name
	 * @param portName
	 * @param ownerApp
	 * @return
	 */
	public Boolean connect(String portName, String ownerApp){
		
		try {
			// Get the port list
			ArrayList<CommPortIdentifier> serialPortList = getCommPortList();
			
			// Look for the port specified by portName
			CommPortIdentifier portId = null;
			for (CommPortIdentifier currPortId : serialPortList) {
				if (currPortId.getName().equals(portName)) {
					portId = currPortId;
					break;
				}
			}
			
			// if port is found
			if (portId != null) {

				// open serial port,
				serialPort = (SerialPort)portId.open(ownerApp,CONNECTION_TIME_OUT);
				
				// set port parameters
				serialPort.setSerialPortParams(BAUD_RATE, SerialPort.DATABITS_8, SerialPort.STOPBITS_1,	SerialPort.PARITY_NONE);

				// open the streams
				serialInput = serialPort.getInputStream();
				serialOutput = serialPort.getOutputStream();

				// add event listeners
				serialPort.addEventListener(this);
				serialPort.notifyOnDataAvailable(true);
				//serialPort.notifyOnOverrunError(true);
				//serialPort.notifyOnOutputEmpty(true);
				connected = true;

			} 
			// If port is not found
			else {
				logger.warn("Could not find serial port '"+portName+"'");
				return false;
			}
			
			// return true if all goes fine
			return true;
			
		} catch (Exception e) {
			logger.error(e.toString());
			return false;
		}
	}
	
	
	/**
	 * Remove any connection to the serial port
	 */
	public void disconnect() {
		
		logger.info("Closing serial port");
		
		try {
			if (serialInput != null) {
				serialInput.close();
			}
			if (serialOutput != null) {
				serialOutput.close();
			}
			if (serialPort != null) {
				serialPort.removeEventListener();
				serialPort.close();
				serialPort = null;
				connected = false;
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	/**
	 * Get the available port list as String[]
	 * @return
	 */
	public String[] getPortList(){
		
		ArrayList<CommPortIdentifier> serialCommPortList = getCommPortList();
		String[] serialPortList = new String[serialCommPortList.size()];
		for(int i=0; i<serialCommPortList.size();i++){
			serialPortList[i] = serialCommPortList.get(i).getName();
		}
		return serialPortList;
	}
	
	/**
	 * Get the available comm port list as Arraylist<CommPortIdentiefier>
	 * @return
	 */
	private ArrayList<CommPortIdentifier> getCommPortList(){
		
		ArrayList<CommPortIdentifier> serialPortList = new ArrayList<CommPortIdentifier>();
		
		try {
			
			Enumeration<?> tempSerialPortList = CommPortIdentifier.getPortIdentifiers();
			while (tempSerialPortList.hasMoreElements()) {
			
				CommPortIdentifier portId = (CommPortIdentifier) tempSerialPortList.nextElement();
				//logger.debug(portId.getName());
				if (portId.getPortType() == CommPortIdentifier.PORT_SERIAL) {
					String name = portId.getName();
					if (!name.startsWith("/dev/tty.")) {
						serialPortList.add(portId);
					}
				}
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		}

		return serialPortList;
	}
	
	/**
	 * Handle an event on the serial port
	 */
	public synchronized void serialEvent(SerialPortEvent oEvent) {
				
		if (oEvent.getEventType() == SerialPortEvent.DATA_AVAILABLE) {
			try {
				while(serialInput.available() > 0) processInput();
			} catch (Exception e) {
				logger.error(e.toString());
			}
		} 
		else if(oEvent.getEventType() == SerialPortEvent.OUTPUT_BUFFER_EMPTY){
			//logger.info("Output buffer empty");
		}else if(oEvent.getEventType() == SerialPortEvent.OE){
			//logger.info("Overrun");
		} else {
			//logger.info("Another serial event:"+oEvent.getEventType());
			
		}
	}
	
		
	/**
	 * Send Sysex command without values
	 * @param command
	 */
	private void sendSysexCommand(int command){
		sendSysexCommand(command, new int[0]);
	}
	
	/**
	 * Send Sysex command with values
	 * @param command
	 * @param values
	 */
	private void sendSysexCommand(int command, int[] values) {
		
		if(connected){
			int totalSize = values.length+3;
			byte[] message = new byte[totalSize];
			
			message[0] = (byte)SYSEX_START;
			message[1] = (byte)command;
			for(int i = 2; i < values.length+2; i++){
				message[i] = (byte)values[i-2];
			}
			
			message[totalSize-1] = (byte)SYSEX_END;
			
			try {
				serialOutput.write(message);
				//Thread.sleep(50);
		
			} catch (IOException e) {
				e.printStackTrace();
			} 
		} else {
			logger.warn("Trying to send, but not connected");
		}
	}
	
	/**
	 * Process the input bytes from serial port to construct each Sysex message
	 * @throws IOException
	 */
	private void processInput() throws IOException{
		
		int inputData = serialInput.read();
				
		if(parsingSysex && sysexBytesRead < SYSEX_MAX_DATA_BYTES){
			
			if(inputData == SYSEX_START){
				 // a new command start
				 // clear buffer
				 storedInputData = new int[SYSEX_MAX_DATA_BYTES];
				 sysexBytesRead = 0;
			} 
			else if (inputData == SYSEX_END){
				
				int command = storedInputData[0];
				
				// For string commands
				if (command == SYSEX_STRING){
					
					int[] message = new int[sysexBytesRead-1];
					
					int messageIndex = 0;
					int storedInputDataIndex = 1;
					
					while(messageIndex < sysexBytesRead-1){
						message[messageIndex] = storedInputData[storedInputDataIndex];
						messageIndex++;
						storedInputDataIndex++;
					}
										
					processSysexStringMessage(message);
				} 
				// For sysex commands
				else {
					
					int numOfValues = (sysexBytesRead-1)/2;
					int[] values = new int[numOfValues];
					
					int valuesIndex = 0;
					int storedInputDataIndex = 1;
					
					while(valuesIndex < numOfValues){
						int LSB = storedInputData[storedInputDataIndex];
						int MSB = storedInputData[storedInputDataIndex+1];
						
						values[valuesIndex] = MSB*128+LSB;
						valuesIndex++;
						storedInputDataIndex = storedInputDataIndex+2;
					}
										
					super.dispatchSysexEvent(new PhotoduinoEvent(command, values));
				}
				
				storedInputData = new int[SYSEX_MAX_DATA_BYTES];
				parsingSysex = false;
				sysexBytesRead = 0;
			} 
			else {
				storedInputData[sysexBytesRead] = inputData;
				sysexBytesRead++;
			}
			
			
		} else {
			
			if(inputData == SYSEX_START){
				 parsingSysex = true;
				 storedInputData = new int[SYSEX_MAX_DATA_BYTES];
				 sysexBytesRead = 0;
			} else {
				// waste this bytes if not in a sysex parsing
				sysexBytesRead = 0;
			}
		}		
		
	}
	
	
	/**
	 * Process a Sysex string message printing it to console
	 * @param message 
	 */
	private void processSysexStringMessage(int[] message){
		
		char[] msg = new char[message.length];
		
		for(int i=0; i<message.length; i++){
			msg[i] = (char)message[i];
		}
		logger.debug(String.format("String message: %s", new String(msg)));

	}
		
	/**
	 * Request to enter in remote mode
	 */
	public void requestStartRemoteMode(boolean beepOnLimit){
		int[] arguments = { beepOnLimit ? 1 : 0 };
		sendSysexCommand(PhotoduinoCommands.CMD_REMOTE_MODE_START, arguments);
	}
	
	public void requestStopRemoteMode(){
		sendSysexCommand(PhotoduinoCommands.CMD_REMOTE_MODE_STOP);
	}
	
	/**
	 * Request param value
	 * @param param
	 */
	public void requestParamValue(int param){
		
		int[] arguments = { param };
		sendSysexCommand(PhotoduinoCommands.CMD_PARAM_REQUEST, arguments);

	}
	
	public void requestAllParamsValues(){
		
		sendSysexCommand(PhotoduinoCommands.CMD_ALL_PARAM_REQUEST);

	}
	
	
	/**
	 * Update param value
	 * @param param
	 * @param value
	 */
	public void updateParamValue(int param, int value){
		
		int MSB = value/256;
		int LSB = value%256;
		
		int[] arguments = { param, MSB, LSB };
		
		sendSysexCommand(PhotoduinoCommands.CMD_PARAM_UPDATE, arguments);
	}
	
	public void setSensorBeepOnLimit(boolean value){
		
		int [] arguments = { value ? 1 : 0 };
		sendSysexCommand(PhotoduinoCommands.CMD_SET_SENSOR_BEEP_ONLIMIT, arguments);
	}
	
	
	public void manualControlStartShutter(){
			
		sendSysexCommand(PhotoduinoCommands.CMD_MANUAL_CONTROL_SHUTTER_START);
	}
	
	public void manualControlStopShutter(){
		
		sendSysexCommand(PhotoduinoCommands.CMD_MANUAL_CONTROL_SHUTTER_STOP);
	}
	
	public void manualControlStartAutofocus(){
		
		sendSysexCommand(PhotoduinoCommands.CMD_MANUAL_CONTROL_AF_START);
	}
	
	public void manualControlStopAutofocus(){
		
		sendSysexCommand(PhotoduinoCommands.CMD_MANUAL_CONTROL_AF_STOP);
	}
	
	public void manualControlShootFlash1(){
		
		sendSysexCommand(PhotoduinoCommands.CMD_MANUAL_CONTROL_SHOOT_FLASH1);
	}
	
	public void manualControlShootFlash2(){
		
		sendSysexCommand(PhotoduinoCommands.CMD_MANUAL_CONTROL_SHOOT_FLASH2);
	}
	
	public void manualControlDeviceOn(){
		
		sendSysexCommand(PhotoduinoCommands.CMD_MANUAL_CONTROL_DEVICE_ON);
	}
	
	public void manualControlDeviceOff(){
		
		sendSysexCommand(PhotoduinoCommands.CMD_MANUAL_CONTROL_DEVICE_OFF);
	}
	
	public void testDrops(){
		
		sendSysexCommand(PhotoduinoCommands.CMD_TEST_MAKE_DROPS);
	}
	
	public void runAsIntervalomenter(){
		
		sendSysexCommand(PhotoduinoCommands.CMD_RUN_INTERVALOMETER_MODE);
	}
	
	public void runAsSensorTrigger(){
		
		sendSysexCommand(PhotoduinoCommands.CMD_RUN_SENSOR_TRIGGER_MODE);
	}
	
	public void requestCancelRunMode(){
		sendSysexCommand(PhotoduinoCommands.CMD_CANCEL_RUNMODE);
	}
}
