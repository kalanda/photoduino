/*
  FirmataLite.cpp - FirmataLite library
  Jeff Hoefs
  
  FirmataLite is a simplified version of Firmata by Hans-Christoph Steiner.
  Everything but the ability to send and receive Strings and Sysex messages
  has been stripped out.
  
  Copyright (C) 2006-2008 Hans-Christoph Steiner.  All rights reserved.
 
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  See file LICENSE.txt for further informations on licensing terms.
*/

//******************************************************************************
//* Includes
//******************************************************************************

#include "Arduino.h"
#include "HardwareSerial.h"
#include "FirmataLite.h"

extern "C" {
#include <string.h>
#include <stdlib.h>
}

//******************************************************************************
//* Support Functions
//******************************************************************************

void sendValueAsTwo7bitBytes(int value)
{
  Serial.write(value & B01111111); // LSB
  Serial.write(value >> 7 & B01111111); // MSB
}

void startSysex(void)
{
  Serial.write(START_SYSEX);
}

void endSysex(void)
{
  Serial.write(END_SYSEX);
}

//******************************************************************************
//* Constructors
//******************************************************************************

FirmataLiteClass::FirmataLiteClass(void)
{
  systemReset();
}

//******************************************************************************
//* Public Methods
//******************************************************************************

/* begin method for overriding default serial bitrate */
void FirmataLiteClass::begin(void)
{
  begin(57600);
}

/* begin method for overriding default serial bitrate */
void FirmataLiteClass::begin(long speed)
{
#if defined(__AVR_ATmega128__)  // Wiring
  Serial.begin((uint32_t)speed);
#else
  Serial.begin(speed);
#endif
}

//------------------------------------------------------------------------------
// Serial Receive Handling

int FirmataLiteClass::available(void)
{
  return Serial.available();
}


void FirmataLiteClass::processSysexMessage(void)
{
  switch(storedInputData[0]) { //first byte in buffer is command
  case STRING_DATA:
    if(currentStringCallback) {
      byte bufferLength = (sysexBytesRead - 1) / 2;
      char *buffer = (char*)malloc(bufferLength * sizeof(char));
      byte i = 1;
      byte j = 0;
      while(j < bufferLength) {
        buffer[j] = (char)storedInputData[i];
        i++;
        buffer[j] += (char)(storedInputData[i] << 7);
        i++;
        j++;
      }
      (*currentStringCallback)(buffer);
    }
    break;
  default:
    if(currentSysexCallback)
      (*currentSysexCallback)(storedInputData[0], sysexBytesRead - 1, storedInputData + 1);
  }
}

void FirmataLiteClass::processInput(void)
{
  int inputData = Serial.read(); // this is 'int' to handle -1 when no data
  int command;
    
  // TODO make sure it handles -1 properly

  if (parsingSysex) {
    if(inputData == END_SYSEX) {
      //stop sysex byte      
      parsingSysex = false;
      //fire off handler function
      processSysexMessage();
    } else {
      //normal data byte - add to buffer
      storedInputData[sysexBytesRead] = inputData;
      sysexBytesRead++;
    }
  } else if( (waitForData > 0) && (inputData < 128) ) {  
    waitForData--;
    storedInputData[waitForData] = inputData;
    if( (waitForData==0) && executeMultiByteCommand ) { // got the whole message
	  // jhoefs - ever get here?
      executeMultiByteCommand = 0;
    }	
  } else {
    // remove channel info from command byte if less than 0xF0
    if(inputData < 0xF0) {
      command = inputData & 0xF0;
      multiByteChannel = inputData & 0x0F;
    } else {
      command = inputData;
      // commands in the 0xF* range don't use channel data
    }
    switch (command) {
    case START_SYSEX:
      parsingSysex = true;
      sysexBytesRead = 0;
      break;
    case SYSTEM_RESET:
      systemReset();
      break;
    }
  }
}

//------------------------------------------------------------------------------
// Serial Send Handling
void FirmataLiteClass::sendSysex(byte command, byte bytec, byte* bytev) 
{
  byte i;
  startSysex();
  Serial.write(command);
  for(i=0; i<bytec; i++) {
    sendValueAsTwo7bitBytes(bytev[i]);        
  }
  endSysex();
}

void FirmataLiteClass::sendString(byte command, const char* string) 
{
  sendSysex(command, strlen(string), (byte *)string);
}


// send a string as the protocol string type
void FirmataLiteClass::sendString(const char* string) 
{
  sendString(STRING_DATA, string);
}


// Internal Actions/////////////////////////////////////////////////////////////

void FirmataLiteClass::attach(byte command, systemResetCallbackFunction newFunction)
{
  switch(command) {
  	case SYSTEM_RESET: currentSystemResetCallback = newFunction; break;
  }
}

void FirmataLiteClass::attach(byte command, stringCallbackFunction newFunction)
{
  switch(command) {
  	case STRING_DATA: currentStringCallback = newFunction; break;
  }
}

void FirmataLiteClass::attach(byte command, sysexCallbackFunction newFunction)
{
  currentSysexCallback = newFunction;
}

void FirmataLiteClass::detach(byte command)
{
  switch(command) {
  	case SYSTEM_RESET: currentSystemResetCallback = NULL; break;
  	case STRING_DATA: currentStringCallback = NULL; break;
  	case START_SYSEX: currentSysexCallback = NULL; break;
  }
}

//******************************************************************************
//* Private Methods
//******************************************************************************



// resets the system state upon a SYSTEM_RESET message from the host software
void FirmataLiteClass::systemReset(void)
{
  byte i;

  waitForData = 0; // this flag says the next serial input will be data
  executeMultiByteCommand = 0; // execute this after getting multi-byte data
  multiByteChannel = 0; // channel data for multiByteCommands


  for(i=0; i<MAX_DATA_BYTES; i++) {
    storedInputData[i] = 0;
  }

  parsingSysex = false;
  sysexBytesRead = 0;

  if(currentSystemResetCallback)
    (*currentSystemResetCallback)();

  //flush(); //TODO uncomment when Firmata is a subclass of HardwareSerial
}

// make one instance for the user to use
FirmataLiteClass FirmataLite;


