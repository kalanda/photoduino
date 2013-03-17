package com.photoduino.remote.swt.widgets;

import org.eclipse.swt.SWT;
import org.eclipse.swt.events.DisposeEvent;
import org.eclipse.swt.events.DisposeListener;
import org.eclipse.swt.events.MouseAdapter;
import org.eclipse.swt.events.MouseEvent;
import org.eclipse.swt.events.PaintListener;
import org.eclipse.swt.events.PaintEvent;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.graphics.Color;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.widgets.Canvas;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.TypedListener;

public class SensorBar extends Canvas  {
	
	private int sensorReading;
	private Boolean sensorOverflow;
	private int sensorLimit;
	private int controlWidth;
	private int leftPadding;
	private Color colorRed;
	private Color colorGreen;
	
	
	public SensorBar(Composite parent, int style){
		
		super(parent, style);
		colorGreen = new Color(getDisplay(),0,255,0);
		colorRed = new Color(getDisplay(),255,0,0);
		sensorReading = 0;
		sensorLimit = 500;
		sensorOverflow = false;
		controlWidth = 0;
		leftPadding = 30;
		
        addPaintListener(new PaintListener() {
            public void paintControl(PaintEvent e) {
            	
            	controlWidth = e.width;
            	int barWidth = controlWidth-leftPadding-1;
            	int barHeight = e.height-1;
            	
            	int sensorReadingPixels = ((sensorReading*barWidth)/999);
            	int sensorLimitPixels =  ((sensorLimit*barWidth)/999);
            	
            	Rectangle barBorder = new Rectangle(leftPadding, 0, barWidth, barHeight);
            	Rectangle barFill = new Rectangle(leftPadding, 0, sensorReadingPixels, barHeight);

            	e.gc.drawText(String.format("%d",sensorReading), 0, 3, true);
            						
				if(sensorOverflow) e.gc.setBackground(colorRed);
				else e.gc.setBackground(colorGreen);
				
				e.gc.fillRectangle(barFill);
				e.gc.drawRectangle(barBorder);
				e.gc.drawLine(leftPadding+sensorLimitPixels, 0, leftPadding+sensorLimitPixels, e.height-1);

            }
        });
        
        addMouseListener(new MouseAdapter() {
           
            public void mouseDown(MouseEvent event){
            	if (event.button == 1) {
	                
	                int newSensorLimit = ((999*(event.x-leftPadding))/(controlWidth-leftPadding));
	                setSelection(newSensorLimit);
	                notifyListeners(SWT.Selection, new Event());
	            }
            	
            }
        });
        
        addDisposeListener(new DisposeListener() {
			public void widgetDisposed(DisposeEvent e) {
				colorGreen.dispose();
				colorRed.dispose();
			}
               
        });
        
    }

	public void addSelectionListener(SelectionListener listener) {
		  addListener(SWT.Selection, new TypedListener(listener));
	}
	
    public void setSensorReading(int value){
    	sensorReading = value;
    	this.redraw();
    }
    
    public void setSelection(int value){
    	sensorLimit = value;
    	this.redraw();
    }
    
    public void setSensorOverflow(Boolean value){
    	sensorOverflow = value;
    	this.redraw();
    }
    
    public int getSelection(){
    	return sensorLimit;
    }
    
}
