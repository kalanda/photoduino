package com.photoduino.remote;

import java.util.ArrayList;
import java.util.Iterator;



public abstract class PhotoduinoEventDispatcher {

  private ArrayList<PhotoduinoEventListener> _listeners = new ArrayList<PhotoduinoEventListener>();

  public synchronized void addSysexEventListener(PhotoduinoEventListener listener)  {

    _listeners.add(listener);
  }

  public synchronized void removeSysexEventListener(PhotoduinoEventListener listener)   {

    _listeners.remove(listener);

  }
  
  public synchronized void dispatchSysexEvent(PhotoduinoEvent sysexEvent) {

    Iterator<PhotoduinoEventListener> i = _listeners.iterator();
    while(i.hasNext())  {
      i.next().handlePhotoduinoEvent(sysexEvent);
    }
  }
}
