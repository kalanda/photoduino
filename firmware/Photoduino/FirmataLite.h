/*
  FirmataLite.h - FirmataLite library
  Copyright (C) 2011 Jeff Hoefs.  All rights reserved.
  
  FirmataLite is a simplified version of Firmata by Hans-Christoph Steiner.
  Copyright (C) 2006-2008 Hans-Christoph Steiner.  All rights reserved.
 
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  See file LICENSE.txt for further informations on licensing terms.
*/

#ifndef FirmataLite_h
#define FirmataLite_h

#include <Arduino.h>
#include <inttypes.h>

#define MAX_DATA_BYTES 32 // max number of data bytes in non-Sysex messages

// message command bytes (128-255/0x80-0xFF)
#define SYSTEM_RESET            0xFF // reset from MIDI
//
#define START_SYSEX             0xF0 // start a MIDI Sysex message
#define END_SYSEX               0xF7 // end a MIDI Sysex message

// extended command set using sysex (0-127/0x00-0x7F)
/* 0x00-0x0F reserved for user-defined commands */
#define STRING_DATA             0x71 // a string message with 14-bits per char
#define SAMPLING_INTERVAL       0x7A // set the poll rate of the main loop
#define SYSEX_NON_REALTIME      0x7E // MIDI Reserved for non-realtime messages
#define SYSEX_REALTIME          0x7F // MIDI Reserved for realtime messages


extern "C" {
// callback function types
    typedef void (*systemResetCallbackFunction)(void);
    typedef void (*stringCallbackFunction)(char*);
    typedef void (*sysexCallbackFunction)(byte command, byte argc, byte*argv);
}


// TODO make it a subclass of a generic Serial/Stream base class
class FirmataLiteClass
{
public:
	FirmataLiteClass();
/* Arduino constructors */
    void begin();
    void begin(long);
/* serial receive handling */
    int available(void);
    void processInput(void);
/* serial send handling */
    void sendString(const char* string);
    void sendString(byte command, const char* string);
	void sendSysex(byte command, byte bytec, byte* bytev);
/* attach & detach callback functions to messages */
    void attach(byte command, systemResetCallbackFunction newFunction);
    void attach(byte command, stringCallbackFunction newFunction);
    void attach(byte command, sysexCallbackFunction newFunction);
    void detach(byte command);

private:
/* input message handling */
    byte waitForData; // this flag says the next serial input will be data
    byte executeMultiByteCommand; // execute this after getting multi-byte data
    byte multiByteChannel; // channel data for multiByteCommands
    byte storedInputData[MAX_DATA_BYTES]; // multi-byte data
/* sysex */
    boolean parsingSysex;
    int sysexBytesRead;
/* callback functions */
    systemResetCallbackFunction currentSystemResetCallback;
    stringCallbackFunction currentStringCallback;
    sysexCallbackFunction currentSysexCallback;

/* private methods ------------------------------ */
    void processSysexMessage(void);
	void systemReset(void);
};

extern FirmataLiteClass FirmataLite;


#endif /* FirmataLite_h */

