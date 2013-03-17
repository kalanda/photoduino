package com.photoduino.remote;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

import org.apache.log4j.Logger;

import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.SWT;
import org.eclipse.swt.events.DisposeEvent;
import org.eclipse.swt.events.DisposeListener;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Combo;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Listener;
import org.eclipse.swt.widgets.TabFolder;
import org.eclipse.swt.widgets.TabItem;
import org.eclipse.swt.widgets.Spinner;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.events.SelectionEvent;

import com.photoduino.remote.swt.widgets.SensorBar;
import org.eclipse.swt.events.MouseListener;
import org.eclipse.swt.events.MouseEvent;
import org.eclipse.swt.graphics.Color;


public class AppWindow implements SelectionListener, PhotoduinoEventListener, MouseListener {
	
	private static final int SERIAL_PORTS_UPDATE_FREQ = 1000;
	
	private Properties appConfig;
	private PhotoduinoSerialManager serialManager;
	private Logger logger = Logger.getLogger(getClass());
	private PhotoduinoConfig photoduinoConfig = new PhotoduinoConfig();
	private int lastSensorRead = 0;
	private Boolean lastSensorOverflow = false;
	private BusyDialog busyDialog = null;
	
	protected Shell shell;
	private Composite connectionPanel;
	private Label serialPortListLabel;
	private Combo serialPortListCombo;
	private Button connectButton;
	private TabFolder tabsPanel;
	private TabItem system_tabItem;
	private Composite system_tabPanel;
	private Label system_devicePortTypeLabel;
	private Combo system_devicePortType;
	private Label system_sensorTuningModeLabel;
	private Combo system_sensorTuningMode;
	private Label system_cameraShutterLagLabel;
	private Spinner system_cameraShutterLag;
	private Label system_cameraMirrorLockUpTimeoutLabel;
	private Spinner system_cameraMirrorLockUpTimeout;
	private TabItem intervalometerMode_tabItem;
	private Composite intervalometerMode_tabPanel;
	private Label intervalometerMode_autofocusTimeLabel;
	private Spinner intervalometerMode_autofocusTime;
	private Spinner intervalometerMode_preFlash1Time;
	private Label intervalometerMode_preFlash1TimeLabel;
	private Label intervalometerMode_preFlash2TimeLabel;
	private Spinner intervalometerMode_preFlash2Time;
	private Label intervalometerMode_preCloseTimeLabel;
	private Spinner intervalometerMode_preCloseTime;
	private Combo intervalometerMode_intervalUnits;
	private Spinner intervalometerMode_intervalValue;
	private Label intervalometerMode_intervalLabel;
	private Spinner intervalometerMode_numCycles;
	private Label intervalometerMode_numCyclesLabel;
	private TabItem sensorTrigger_tabItem;
	private Composite sensorTrigger_tabPanel;
	private Group sensorTrigger_sensorGroup;
	private Combo sensorTriggerMode_sensorType;
	private Label sensorTriggerMode_sensorTypeLabel;
	private Spinner sensorTriggerMode_sensorLimit;
	private Label sensorTriggerMode_sensorLimitLabel;
	private Group sensorTrigger_dropsConfigGroup;
	private Label sensorTriggerMode_dropsCountLabel;
	private Spinner sensorTriggerMode_dropsCount;
	private Label sensorTriggerMode_dropsDurationLabel;
	private Spinner sensorTriggerMode_dropsDuration;
	private Label sensorTriggerMode_dropsIntervalLabel;
	private Spinner sensorTriggerMode_dropsInterval;
	private Button sensorTriggerMode_testDropsButton;
	private Label sensorTriggerMode_dropsCountUnitsLabel;
	private Label sensorTriggerMode_dropsDurationUnitsLabel;
	private Label sensorTriggerMode_dropsIntervalUnitsLabel;
	private Button sensorTrigger_runButton;
	private Group sensorTrigger_lifeCycleGroup;
	private Label sensorTriggerMode_autofocusTimeLabel;
	private Label sensorTriggerMode_shootingModeLabel;
	private Combo sensorTriggerMode_shootingMode;
	private Spinner sensorTriggerMode_autofocusTime;
	private Label sensorTriggerMode_autofocusTimeUnitsLabel;
	private Label sensorTriggerMode_preFlash1TimeLabel;
	private Spinner sensorTriggerMode_preFlash1Time;
	private Label sensorTriggerMode_preFlash1TimeUnitsLabel;
	private Label sensorTriggerMode_preFlash2TimeLabel;
	private Spinner sensorTriggerMode_preFlash2Time;
	private Label sensorTriggerMode_preFlash2TimeUnitsLabel;
	private Label sensorTriggerMode_preCloseTimeLabel;
	private Spinner sensorTriggerMode_preCloseTime;
	private Label sensorTriggerMode_preCloseTimeUnitsLabel;
	private Label sensorTriggerMode_numCyclesLabel;
	private Spinner sensorTriggerMode_numCycles;
	private Label sensorTriggerMode_numCyclesUnitsLabel;
	private Label sensorTriggerMode_interCycleTimeLabel;
	private Spinner sensorTriggerMode_interCycleTime;
	private Label sensorTriggerMode_interCycleTimeUnitsLabel;
	private Group intervalometerMode_lifeCycleGroup;
	private Label intervalometerMode_autofocusTimeUnitsLabel;
	private Label intervalometerMode_preFlash1TimeUnitsLabel;
	private Label intervalometerMode_preFlash2TimeUnitsLabel;
	private Label intervalometerMode_preCloseTimeUnitsLabel;
	private Label intervalometerMode_numCyclesUnitsLabel;
	private Group system_defaultGroup;
	private Label system_cameraShutterLagUnitsLabel;
	private Label system_cameraMirrorLockUpTimeoutUnitsLabel;
	private Button intervalometerMode_runButton;
	private Label statusBar;
	private Label system_useFlash1Label;
	private Label system_useFlash2Label;
	private Label system_useSpeakerLabel;
	private Label system_useBacklightLabel;
	private SensorBar sensorTriggerMode_sensorBar;
	private TabItem manualControl_tabItem;
	private Composite manualControl_tabPanel;
	private Group manualControl_cameraGroup;
	private Button manualControl_shutterButton;
	private Button manualControl_autofocusButton;
	private Button manualControl_autofocusAndShutterButton;
	private Group manualControl_flashesGroup;
	private Button manualControl_flash1Button;
	private Button manualControl_flash2Button;
	private Group manualControl_solenoidValveGroup;
	private Button manualControl_solenoidValveButton;
	private Button system_useFlash1;
	private Button system_useFlash2;
	private Button system_useSpeaker;
	private Button system_useBacklight;
	private Button sensorBeepOnLimit;
	private Composite statusBarPanel;
	private Label statusLabel;

	/**
	 * Launch the application.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			AppWindow window = new AppWindow();
			window.open();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	/**
	 * Application Window constructor
	 */
	public AppWindow(){	
		
		loadConfig();
		serialManager = new PhotoduinoSerialManager();
		serialManager.addSysexEventListener(this);
		
	}
	
	/**
	 * Load project configuration
	 */
	private void loadConfig(){
		
		appConfig = new Properties();
		
        try {
            // the configuration file name
            InputStream is = getClass().getResourceAsStream("/project.properties");

            // load the properties file
            appConfig.load(is);

            // get the value for app.name key
            System.out.println(appConfig.getProperty("app.name")+" "+appConfig.getProperty("app.version"));

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
	}
	
	/**
	 * Open the window.
	 */
	public void open() {
		    
		Display.setAppName(appConfig.getProperty("app.name")+" "+appConfig.getProperty("app.version"));
		Display display = Display.getDefault();
		
		createContents();
		createAutomaticTasks();
		
		shell.addDisposeListener(new DisposeListener(){
			@Override
			public void widgetDisposed(DisposeEvent arg0) {
				if(serialManager.isConnected()) serialManager.requestStopRemoteMode();
				logger.info("Closing application");
				System.exit(0);
			}
		});
		
		shell.addListener(SWT.Traverse, new Listener() {
	  		@Override
			public void handleEvent(Event e) {
				if (e.detail == SWT.TRAVERSE_ESCAPE) {
					disconnect();
	            }
			}
        });
		
		if(!serialManager.isConnected()) tabsPanel.setVisible(false);
		
		shell.pack();
		shell.open();
		shell.layout();
		while (!shell.isDisposed()) {
			if (!display.readAndDispatch()) {
				display.sleep();
			}
		}
	}
	
	/**
	 * Create automatic tasks
	 */
	private void createAutomaticTasks(){
		
		// Task for update the sensorBar each 10 ms
		Runnable refreshSensorBarTask = new Runnable() { 
			 
	        @Override 
	        public void run() { 
	        	sensorTriggerMode_sensorBar.setSelection(sensorTriggerMode_sensorLimit.getSelection()); // TODO quitar y hacer desde el evento del spinner
				sensorTriggerMode_sensorBar.setSensorReading(lastSensorRead);
				sensorTriggerMode_sensorBar.setSensorOverflow(lastSensorOverflow);
				Display.getDefault().timerExec(10, this); 
	        } 
	 
	    }; 
	    refreshSensorBarTask.run(); 
	    
	    // Task for update the available port list every SERIAL_PORTS_UPDATE_FREQ ms
	    Runnable refreshSerialPortListTask = new Runnable() { 
			 
	        @Override 
	        public void run() { 
	        	if(!serialManager.isConnected()){
		        	String[] serialPortList = serialManager.getPortList();
					
					if(serialPortListCombo.getItemCount() != serialPortList.length){
						serialPortListCombo.setItems(serialPortList);
						serialPortListCombo.select(0);
					}
					Display.getDefault().timerExec(SERIAL_PORTS_UPDATE_FREQ, this); 
	        	}
	        } 
	 
	    }; 
	    refreshSerialPortListTask.run();
	}

	/**
	 * Create contents of the window.
	 */
	protected void createContents() {
		shell = new Shell(SWT.CLOSE | SWT.MIN | SWT.TITLE);
		shell.setText(appConfig.getProperty("app.name")+" "+appConfig.getProperty("app.version"));
		shell.setLayout(new GridLayout(1, false));
		
		connectionPanel = new Composite(shell, SWT.NO_REDRAW_RESIZE);
		connectionPanel.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		connectionPanel.setLayout(new GridLayout(3, false));
		
		serialPortListLabel = new Label(connectionPanel, SWT.NONE);
		serialPortListLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		serialPortListLabel.setText("Serial Port");
		
		serialPortListCombo = new Combo(connectionPanel, SWT.READ_ONLY);
		serialPortListCombo.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		serialPortListCombo.setItems(new String[] {});	
		
		connectButton = new Button(connectionPanel, SWT.NONE);
		GridData gd_connectButton = new GridData(SWT.LEFT, SWT.CENTER, false, false, 1, 1);
		gd_connectButton.widthHint = 125;
		connectButton.setLayoutData(gd_connectButton);
		connectButton.addSelectionListener(this);
		connectButton.setText("Connect");
		
		tabsPanel = new TabFolder(shell, SWT.NONE);
		tabsPanel.setLayoutData(new GridData(SWT.CENTER, SWT.TOP, false, false, 1, 1));
		
		system_tabItem = new TabItem(tabsPanel, SWT.NONE);
		system_tabItem.setText("System config");
		
		system_tabPanel = new Composite(tabsPanel, SWT.NONE);
		system_tabItem.setControl(system_tabPanel);
		system_tabPanel.setLayout(new GridLayout(1, false));
		
		system_defaultGroup = new Group(system_tabPanel, SWT.NONE);
		system_defaultGroup.setLayoutData(new GridData(SWT.FILL, SWT.FILL, true, true, 1, 1));
		system_defaultGroup.setLayout(new GridLayout(3, false));
		
		system_devicePortTypeLabel = new Label(system_defaultGroup, SWT.RIGHT);
		system_devicePortTypeLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		system_devicePortTypeLabel.setText("Device Type");
		
		system_devicePortType = new Combo(system_defaultGroup, SWT.READ_ONLY);
		system_devicePortType.addSelectionListener(this);
		system_devicePortType.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, false, false, 2, 1));
		system_devicePortType.setItems(new String[] {"None", "Laser", "Solenoid Valve"});
		system_devicePortType.select(0);
		
		system_sensorTuningModeLabel = new Label(system_defaultGroup, SWT.RIGHT);
		system_sensorTuningModeLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		system_sensorTuningModeLabel.setText("Sensor Tuning");
		
		system_sensorTuningMode = new Combo(system_defaultGroup, SWT.READ_ONLY);
		system_sensorTuningMode.addSelectionListener(this);
		system_sensorTuningMode.setLayoutData(new GridData(SWT.LEFT, SWT.CENTER, false, false, 2, 1));
		system_sensorTuningMode.setItems(new String[] {"Visual", "Numeric"});
		system_sensorTuningMode.select(0);
		
		system_cameraShutterLagLabel = new Label(system_defaultGroup, SWT.RIGHT);
		system_cameraShutterLagLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		system_cameraShutterLagLabel.setText("Shutterlag Time");
		
		system_cameraShutterLag = new Spinner(system_defaultGroup, SWT.BORDER | SWT.WRAP);
		system_cameraShutterLag.addSelectionListener(this);
		system_cameraShutterLag.setMaximum(59999);
		
		system_cameraShutterLagUnitsLabel = new Label(system_defaultGroup, SWT.NONE);
		system_cameraShutterLagUnitsLabel.setText("ms");
		
		system_cameraMirrorLockUpTimeoutLabel = new Label(system_defaultGroup, SWT.RIGHT);
		system_cameraMirrorLockUpTimeoutLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		system_cameraMirrorLockUpTimeoutLabel.setText("Mirror Lookup Timeout");
		
		system_cameraMirrorLockUpTimeout = new Spinner(system_defaultGroup, SWT.BORDER | SWT.WRAP);
		system_cameraMirrorLockUpTimeout.setMaximum(59999);
		system_cameraMirrorLockUpTimeout.addSelectionListener(this);
		
		system_cameraMirrorLockUpTimeoutUnitsLabel = new Label(system_defaultGroup, SWT.NONE);
		system_cameraMirrorLockUpTimeoutUnitsLabel.setText("ms");
		
		system_useFlash1Label = new Label(system_defaultGroup, SWT.RIGHT);
		system_useFlash1Label.setText("Use Flash1");
		system_useFlash1Label.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		
		system_useFlash1 = new Button(system_defaultGroup, SWT.CHECK);
		system_useFlash1.addSelectionListener(this);
		new Label(system_defaultGroup, SWT.NONE);
		
		system_useFlash2Label = new Label(system_defaultGroup, SWT.RIGHT);
		system_useFlash2Label.setText("Use Flash2");
		system_useFlash2Label.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		
		system_useFlash2 = new Button(system_defaultGroup, SWT.CHECK);
		system_useFlash2.addSelectionListener(this);
		new Label(system_defaultGroup, SWT.NONE);
		
		system_useSpeakerLabel = new Label(system_defaultGroup, SWT.RIGHT);
		system_useSpeakerLabel.setText("Use Speaker");
		system_useSpeakerLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		
		system_useSpeaker = new Button(system_defaultGroup, SWT.CHECK);
		system_useSpeaker.addSelectionListener(this);
		new Label(system_defaultGroup, SWT.NONE);
		
		system_useBacklightLabel = new Label(system_defaultGroup, SWT.RIGHT);
		system_useBacklightLabel.setText("Use Backlight");
		system_useBacklightLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		
		system_useBacklight = new Button(system_defaultGroup, SWT.CHECK);
		system_useBacklight.addSelectionListener(this);
		new Label(system_defaultGroup, SWT.NONE);
		
		intervalometerMode_tabItem = new TabItem(tabsPanel, SWT.NONE);
		intervalometerMode_tabItem.setText("Intervalometer");
		
		intervalometerMode_tabPanel = new Composite(tabsPanel, SWT.NONE);
		intervalometerMode_tabItem.setControl(intervalometerMode_tabPanel);
		intervalometerMode_tabPanel.setLayout(new GridLayout(1, false));
		
		intervalometerMode_lifeCycleGroup = new Group(intervalometerMode_tabPanel, SWT.NONE);
		intervalometerMode_lifeCycleGroup.setLayout(new GridLayout(3, false));
		intervalometerMode_lifeCycleGroup.setLayoutData(new GridData(SWT.FILL, SWT.FILL, true, false, 1, 1));
		intervalometerMode_lifeCycleGroup.setText("Lifecycle config");
		
		intervalometerMode_autofocusTimeLabel = new Label(intervalometerMode_lifeCycleGroup, SWT.RIGHT);
		intervalometerMode_autofocusTimeLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		intervalometerMode_autofocusTimeLabel.setText("Autofocus Time");
		
		intervalometerMode_autofocusTime = new Spinner(intervalometerMode_lifeCycleGroup, SWT.BORDER | SWT.WRAP);
		intervalometerMode_autofocusTime.setMaximum(59999);
		intervalometerMode_autofocusTime.addSelectionListener(this);
		
		intervalometerMode_autofocusTimeUnitsLabel = new Label(intervalometerMode_lifeCycleGroup, SWT.NONE);
		intervalometerMode_autofocusTimeUnitsLabel.setText("ms");
		
		intervalometerMode_preFlash1TimeLabel = new Label(intervalometerMode_lifeCycleGroup, SWT.RIGHT);
		intervalometerMode_preFlash1TimeLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		intervalometerMode_preFlash1TimeLabel.setText("Flash1 pretime (ms)");
		
		intervalometerMode_preFlash1Time = new Spinner(intervalometerMode_lifeCycleGroup, SWT.BORDER | SWT.WRAP);
		intervalometerMode_preFlash1Time.setMaximum(59999);
		intervalometerMode_preFlash1Time.addSelectionListener(this);
		
		intervalometerMode_preFlash1TimeUnitsLabel = new Label(intervalometerMode_lifeCycleGroup, SWT.NONE);
		intervalometerMode_preFlash1TimeUnitsLabel.setText("ms");
		
		intervalometerMode_preFlash2TimeLabel = new Label(intervalometerMode_lifeCycleGroup, SWT.RIGHT);
		intervalometerMode_preFlash2TimeLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		intervalometerMode_preFlash2TimeLabel.setText("Flash2 pretime (ms)");
		
		intervalometerMode_preFlash2Time = new Spinner(intervalometerMode_lifeCycleGroup, SWT.BORDER | SWT.WRAP);
		intervalometerMode_preFlash2Time.setMaximum(59999);
		intervalometerMode_preFlash2Time.addSelectionListener(this);
		
		intervalometerMode_preFlash2TimeUnitsLabel = new Label(intervalometerMode_lifeCycleGroup, SWT.NONE);
		intervalometerMode_preFlash2TimeUnitsLabel.setText("ms");
		
		intervalometerMode_preCloseTimeLabel = new Label(intervalometerMode_lifeCycleGroup, SWT.RIGHT);
		intervalometerMode_preCloseTimeLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		intervalometerMode_preCloseTimeLabel.setText("Close pretime (ms)");
		
		intervalometerMode_preCloseTime = new Spinner(intervalometerMode_lifeCycleGroup, SWT.BORDER | SWT.WRAP);
		intervalometerMode_preCloseTime.setMaximum(59999);
		intervalometerMode_preCloseTime.addSelectionListener(this);
		
		intervalometerMode_preCloseTimeUnitsLabel = new Label(intervalometerMode_lifeCycleGroup, SWT.NONE);
		intervalometerMode_preCloseTimeUnitsLabel.setText("ms");
		
		intervalometerMode_intervalLabel = new Label(intervalometerMode_lifeCycleGroup, SWT.RIGHT);
		intervalometerMode_intervalLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		intervalometerMode_intervalLabel.setText("Interval");
		
		intervalometerMode_intervalValue = new Spinner(intervalometerMode_lifeCycleGroup, SWT.BORDER | SWT.WRAP);
		intervalometerMode_intervalValue.setMaximum(59999);
		intervalometerMode_intervalValue.addSelectionListener(this);
		
		intervalometerMode_intervalUnits = new Combo(intervalometerMode_lifeCycleGroup, SWT.READ_ONLY);
		intervalometerMode_intervalUnits.setItems(new String[] {"Miliseconds", "Seconds", "Minutes", "Hours", "Days"});
		intervalometerMode_intervalUnits.select(0);
		intervalometerMode_intervalUnits.addSelectionListener(this);
		
		intervalometerMode_numCyclesLabel = new Label(intervalometerMode_lifeCycleGroup, SWT.RIGHT);
		intervalometerMode_numCyclesLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		intervalometerMode_numCyclesLabel.setText("Cycles");
		
		intervalometerMode_numCycles = new Spinner(intervalometerMode_lifeCycleGroup, SWT.BORDER | SWT.WRAP);
		intervalometerMode_numCycles.setMaximum(59999);
		intervalometerMode_numCycles.addSelectionListener(this);
		
		intervalometerMode_numCyclesUnitsLabel = new Label(intervalometerMode_lifeCycleGroup, SWT.NONE);
		intervalometerMode_numCyclesUnitsLabel.setText("cycles");
		
		intervalometerMode_runButton = new Button(intervalometerMode_tabPanel, SWT.NONE);
		intervalometerMode_runButton.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		intervalometerMode_runButton.setText("Run as Intervalometer");
		intervalometerMode_runButton.addSelectionListener(this);
		
		sensorTrigger_tabItem = new TabItem(tabsPanel, SWT.NONE);
		sensorTrigger_tabItem.setText("Sensor Trigger");
		
		sensorTrigger_tabPanel = new Composite(tabsPanel, SWT.NONE);
		sensorTrigger_tabItem.setControl(sensorTrigger_tabPanel);
		sensorTrigger_tabPanel.setLayout(new GridLayout(1, false));
		
		sensorTrigger_sensorGroup = new Group(sensorTrigger_tabPanel, SWT.NONE);
		sensorTrigger_sensorGroup.setLayout(new GridLayout(5, false));
		sensorTrigger_sensorGroup.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		sensorTrigger_sensorGroup.setText("Sensor config");
		
		sensorTriggerMode_sensorTypeLabel = new Label(sensorTrigger_sensorGroup, SWT.RIGHT);
		sensorTriggerMode_sensorTypeLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		sensorTriggerMode_sensorTypeLabel.setText("Sensor Type");
		
		sensorTriggerMode_sensorType = new Combo(sensorTrigger_sensorGroup, SWT.READ_ONLY);
		sensorTriggerMode_sensorType.addSelectionListener(this);
		sensorTriggerMode_sensorType.setItems(new String[] {"None", "Audio", "Barrier", "Light", "Shock"});
		sensorTriggerMode_sensorType.select(0);
		
		sensorTriggerMode_sensorLimitLabel = new Label(sensorTrigger_sensorGroup, SWT.RIGHT);
		sensorTriggerMode_sensorLimitLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		sensorTriggerMode_sensorLimitLabel.setText("Sensor limit");
		
		sensorTriggerMode_sensorLimit = new Spinner(sensorTrigger_sensorGroup, SWT.BORDER);
		sensorTriggerMode_sensorLimit.setMaximum(999);
		sensorTriggerMode_sensorLimit.addSelectionListener(this);
		
		sensorBeepOnLimit = new Button(sensorTrigger_sensorGroup, SWT.CHECK);
		sensorBeepOnLimit.addSelectionListener(this);
		sensorBeepOnLimit.setText("Beep on limit");
		
		sensorTriggerMode_sensorBar = new SensorBar(sensorTrigger_sensorGroup, SWT.NONE);
		sensorTriggerMode_sensorBar.addSelectionListener(this);
		sensorTriggerMode_sensorBar.setSelection(0);
		sensorTriggerMode_sensorBar.setSensorOverflow(false);
		GridData gd_sensorTriggerMode_sensorBar = new GridData(SWT.FILL, SWT.CENTER, true, false, 5, 1);
		gd_sensorTriggerMode_sensorBar.heightHint = 20;
		sensorTriggerMode_sensorBar.setLayoutData(gd_sensorTriggerMode_sensorBar);
		
		sensorTrigger_lifeCycleGroup = new Group(sensorTrigger_tabPanel, SWT.NONE);
		sensorTrigger_lifeCycleGroup.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		sensorTrigger_lifeCycleGroup.setText("Lifecycle config");
		sensorTrigger_lifeCycleGroup.setLayout(new GridLayout(3, false));
		
		sensorTriggerMode_shootingModeLabel = new Label(sensorTrigger_lifeCycleGroup, SWT.NONE);
		sensorTriggerMode_shootingModeLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		sensorTriggerMode_shootingModeLabel.setText("Shooting Mode");
		
		sensorTriggerMode_shootingMode = new Combo(sensorTrigger_lifeCycleGroup, SWT.READ_ONLY);
		sensorTriggerMode_shootingMode.setItems(new String[] {"Normal", "Pre-Bulb", "Mirror Look-Up"});
		sensorTriggerMode_shootingMode.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 2, 1));
		sensorTriggerMode_shootingMode.select(0);
		sensorTriggerMode_shootingMode.addSelectionListener(this);
		
		sensorTriggerMode_autofocusTimeLabel = new Label(sensorTrigger_lifeCycleGroup, SWT.RIGHT);
		sensorTriggerMode_autofocusTimeLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		sensorTriggerMode_autofocusTimeLabel.setText("Autofocus time");
		
		sensorTriggerMode_autofocusTime = new Spinner(sensorTrigger_lifeCycleGroup, SWT.BORDER | SWT.WRAP);
		sensorTriggerMode_autofocusTime.setMaximum(59999);
		sensorTriggerMode_autofocusTime.addSelectionListener(this);
		
		sensorTriggerMode_autofocusTimeUnitsLabel = new Label(sensorTrigger_lifeCycleGroup, SWT.NONE);
		sensorTriggerMode_autofocusTimeUnitsLabel.setText("ms");
		
		sensorTriggerMode_preFlash1TimeLabel = new Label(sensorTrigger_lifeCycleGroup, SWT.NONE);
		sensorTriggerMode_preFlash1TimeLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		sensorTriggerMode_preFlash1TimeLabel.setText("Flash1 pretime");
		
		sensorTriggerMode_preFlash1Time = new Spinner(sensorTrigger_lifeCycleGroup, SWT.BORDER | SWT.WRAP);
		sensorTriggerMode_preFlash1Time.setMaximum(59999);
		sensorTriggerMode_preFlash1Time.addSelectionListener(this);
		
		sensorTriggerMode_preFlash1TimeUnitsLabel = new Label(sensorTrigger_lifeCycleGroup, SWT.NONE);
		sensorTriggerMode_preFlash1TimeUnitsLabel.setText("ms");
		
		sensorTriggerMode_preFlash2TimeLabel = new Label(sensorTrigger_lifeCycleGroup, SWT.NONE);
		sensorTriggerMode_preFlash2TimeLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		sensorTriggerMode_preFlash2TimeLabel.setText("Flash2 pretime");
		
		sensorTriggerMode_preFlash2Time = new Spinner(sensorTrigger_lifeCycleGroup, SWT.BORDER | SWT.WRAP);
		sensorTriggerMode_preFlash2Time.setMaximum(59999);
		sensorTriggerMode_preFlash2Time.addSelectionListener(this);
		
		sensorTriggerMode_preFlash2TimeUnitsLabel = new Label(sensorTrigger_lifeCycleGroup, SWT.NONE);
		sensorTriggerMode_preFlash2TimeUnitsLabel.setText("ms");
		
		sensorTriggerMode_preCloseTimeLabel = new Label(sensorTrigger_lifeCycleGroup, SWT.NONE);
		sensorTriggerMode_preCloseTimeLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		sensorTriggerMode_preCloseTimeLabel.setText("Close pretime");
		
		sensorTriggerMode_preCloseTime = new Spinner(sensorTrigger_lifeCycleGroup, SWT.BORDER | SWT.WRAP);
		sensorTriggerMode_preCloseTime.setMaximum(59999);
		sensorTriggerMode_preCloseTime.addSelectionListener(this);
		
		sensorTriggerMode_preCloseTimeUnitsLabel = new Label(sensorTrigger_lifeCycleGroup, SWT.NONE);
		sensorTriggerMode_preCloseTimeUnitsLabel.setText("ms");
		
		sensorTriggerMode_numCyclesLabel = new Label(sensorTrigger_lifeCycleGroup, SWT.NONE);
		sensorTriggerMode_numCyclesLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		sensorTriggerMode_numCyclesLabel.setText("Cycles");
		
		sensorTriggerMode_numCycles = new Spinner(sensorTrigger_lifeCycleGroup, SWT.BORDER | SWT.WRAP);
		sensorTriggerMode_numCycles.setMaximum(59999);
		sensorTriggerMode_numCycles.addSelectionListener(this);
		
		sensorTriggerMode_numCyclesUnitsLabel = new Label(sensorTrigger_lifeCycleGroup, SWT.NONE);
		sensorTriggerMode_numCyclesUnitsLabel.setText("cycles");
		
		sensorTriggerMode_interCycleTimeLabel = new Label(sensorTrigger_lifeCycleGroup, SWT.NONE);
		sensorTriggerMode_interCycleTimeLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		sensorTriggerMode_interCycleTimeLabel.setText("Intercycle time");
		
		sensorTriggerMode_interCycleTime = new Spinner(sensorTrigger_lifeCycleGroup, SWT.BORDER | SWT.WRAP);
		sensorTriggerMode_interCycleTime.setMaximum(59999);
		sensorTriggerMode_interCycleTime.addSelectionListener(this);
		
		sensorTriggerMode_interCycleTimeUnitsLabel = new Label(sensorTrigger_lifeCycleGroup, SWT.NONE);
		sensorTriggerMode_interCycleTimeUnitsLabel.setText("ms");
		
		sensorTrigger_dropsConfigGroup = new Group(sensorTrigger_tabPanel, SWT.NONE);
		sensorTrigger_dropsConfigGroup.setLayout(new GridLayout(3, false));
		sensorTrigger_dropsConfigGroup.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		sensorTrigger_dropsConfigGroup.setText("Drops config");
		
		sensorTriggerMode_dropsCountLabel = new Label(sensorTrigger_dropsConfigGroup, SWT.RIGHT);
		sensorTriggerMode_dropsCountLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		sensorTriggerMode_dropsCountLabel.setText("Drops count");
		
		sensorTriggerMode_dropsCount = new Spinner(sensorTrigger_dropsConfigGroup, SWT.BORDER | SWT.WRAP);
		sensorTriggerMode_dropsCount.setMaximum(59999);
		sensorTriggerMode_dropsCount.addSelectionListener(this);
		
		sensorTriggerMode_dropsCountUnitsLabel = new Label(sensorTrigger_dropsConfigGroup, SWT.NONE);
		sensorTriggerMode_dropsCountUnitsLabel.setText("drops");
		
		sensorTriggerMode_dropsDurationLabel = new Label(sensorTrigger_dropsConfigGroup, SWT.RIGHT);
		sensorTriggerMode_dropsDurationLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		sensorTriggerMode_dropsDurationLabel.setText("Drop duration");
		
		sensorTriggerMode_dropsDuration = new Spinner(sensorTrigger_dropsConfigGroup, SWT.BORDER | SWT.WRAP);
		sensorTriggerMode_dropsDuration.setMaximum(59999);
		sensorTriggerMode_dropsDuration.addSelectionListener(this);
		
		sensorTriggerMode_dropsDurationUnitsLabel = new Label(sensorTrigger_dropsConfigGroup, SWT.NONE);
		sensorTriggerMode_dropsDurationUnitsLabel.setText("ms");
		
		sensorTriggerMode_dropsIntervalLabel = new Label(sensorTrigger_dropsConfigGroup, SWT.RIGHT);
		sensorTriggerMode_dropsIntervalLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		sensorTriggerMode_dropsIntervalLabel.setText("Drops interval");
		
		sensorTriggerMode_dropsInterval = new Spinner(sensorTrigger_dropsConfigGroup, SWT.BORDER | SWT.WRAP);
		sensorTriggerMode_dropsInterval.setMaximum(59999);
		sensorTriggerMode_dropsInterval.addSelectionListener(this);
		
		sensorTriggerMode_dropsIntervalUnitsLabel = new Label(sensorTrigger_dropsConfigGroup, SWT.NONE);
		sensorTriggerMode_dropsIntervalUnitsLabel.setText("ms");
				
		sensorTriggerMode_testDropsButton = new Button(sensorTrigger_dropsConfigGroup, SWT.NONE);
		sensorTriggerMode_testDropsButton.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 3, 1));
		sensorTriggerMode_testDropsButton.setText("Test drops");
		sensorTriggerMode_testDropsButton.addSelectionListener(this);
		
		sensorTrigger_runButton = new Button(sensorTrigger_tabPanel, SWT.NONE);
		sensorTrigger_runButton.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		sensorTrigger_runButton.setText("Run as Sensor Trigger");
		sensorTrigger_runButton.addSelectionListener(this);
		
		manualControl_tabItem = new TabItem(tabsPanel, SWT.NONE);
		manualControl_tabItem.setText("Manual control");
		
		manualControl_tabPanel = new Composite(tabsPanel, SWT.NONE);
		manualControl_tabItem.setControl(manualControl_tabPanel);
		manualControl_tabPanel.setLayout(new GridLayout(1, false));
		
		manualControl_cameraGroup = new Group(manualControl_tabPanel, SWT.NONE);
		manualControl_cameraGroup.setLayout(new GridLayout(3, false));
		manualControl_cameraGroup.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		manualControl_cameraGroup.setText("Camera control");
		
		manualControl_autofocusButton = new Button(manualControl_cameraGroup, SWT.NONE);
		manualControl_autofocusButton.addMouseListener(this);
		manualControl_autofocusButton.setText("Autofocus");
		
		manualControl_shutterButton = new Button(manualControl_cameraGroup, SWT.NONE);
		manualControl_shutterButton.addMouseListener(this);
		manualControl_shutterButton.setText("Shutter");
		
		manualControl_autofocusAndShutterButton = new Button(manualControl_cameraGroup, SWT.NONE);
		manualControl_autofocusAndShutterButton.addMouseListener(this);
		manualControl_autofocusAndShutterButton.setText("Autofocus+Shutter");
		
		manualControl_flashesGroup = new Group(manualControl_tabPanel, SWT.NONE);
		manualControl_flashesGroup.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		manualControl_flashesGroup.setText("Flashes control");
		manualControl_flashesGroup.setLayout(new GridLayout(2, false));
		
		manualControl_flash1Button = new Button(manualControl_flashesGroup, SWT.NONE);
		manualControl_flash1Button.addMouseListener(this);
		manualControl_flash1Button.setText("Shoot Flash1");
		
		manualControl_flash2Button = new Button(manualControl_flashesGroup, SWT.NONE);
		manualControl_flash2Button.addMouseListener(this);
		manualControl_flash2Button.setText("Shoot Flash2");
		
		manualControl_solenoidValveGroup = new Group(manualControl_tabPanel, SWT.NONE);
		manualControl_solenoidValveGroup.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		manualControl_solenoidValveGroup.setText("Solenoid valve");
		manualControl_solenoidValveGroup.setLayout(new GridLayout(1, false));
		
		manualControl_solenoidValveButton = new Button(manualControl_solenoidValveGroup, SWT.NONE);
		manualControl_solenoidValveButton.addMouseListener(this);
		manualControl_solenoidValveButton.setText("Solenoid valve ON/OFF");
		
		statusBarPanel = new Composite(shell, SWT.NONE);
		statusBarPanel.setLayout(new GridLayout(2, false));
		statusBarPanel.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, false, false, 1, 1));
		
		statusLabel = new Label(statusBarPanel, SWT.NONE);
		statusLabel.setLayoutData(new GridData(SWT.RIGHT, SWT.CENTER, false, false, 1, 1));
		statusLabel.setText("Status:");
		
		statusBar = new Label(statusBarPanel, SWT.NONE);
		statusBar.setLayoutData(new GridData(SWT.FILL, SWT.CENTER, true, false, 1, 1));
		statusBar.setText("Disconnected");
		
	}
	
	/**
	 * Default seletion handler for widgets
	 */
	@Override
	public void widgetDefaultSelected(SelectionEvent arg0) {
		// Nothing to do yet		
	}
	
	/**
	 * Widget selecion handler
	 */
	public void widgetSelected(SelectionEvent e) {
		
		
		/**
		 * Connection button
		 */
		if(e.getSource() == connectButton){
			
			if(!serialManager.isConnected()){
				
				this.connect();

			} else {
				
				this.disconnect();
			}
		} 
				
		/**
		 * System settings
		 */
		else if(e.getSource() == system_useBacklight){
			photoduinoConfig.system_useBacklight = system_useBacklight.getSelection() ? 1 : 0;
			serialManager.updateParamValue(PhotoduinoParams.system_useBacklight, photoduinoConfig.system_useBacklight);
		}
		
		else if(e.getSource() == system_useSpeaker){
			photoduinoConfig.system_useSpeaker = system_useSpeaker.getSelection() ? 1 : 0;
			serialManager.updateParamValue(PhotoduinoParams.system_useSpeaker, photoduinoConfig.system_useSpeaker);
		}
		
		else if(e.getSource() == system_sensorTuningMode){
			photoduinoConfig.system_sensorTuningMode = system_sensorTuningMode.getSelectionIndex();
			serialManager.updateParamValue(PhotoduinoParams.system_sensorTuningMode, photoduinoConfig.system_sensorTuningMode);
		}		
		
		else if(e.getSource() == system_cameraShutterLag){
			photoduinoConfig.system_cameraShutterLag = system_cameraShutterLag.getSelection();
			serialManager.updateParamValue(PhotoduinoParams.system_cameraShutterLag, photoduinoConfig.system_cameraShutterLag);
		}
		
		else if(e.getSource() == system_cameraMirrorLockUpTimeout){
			photoduinoConfig.system_cameraMirrorLockUpTimeout = system_cameraMirrorLockUpTimeout.getSelection();
			serialManager.updateParamValue(PhotoduinoParams.system_cameraMirrorLockUpTimeout, photoduinoConfig.system_cameraMirrorLockUpTimeout);
		}
		
		else if(e.getSource() == system_useFlash1){
			photoduinoConfig.system_useFlash1 = system_useFlash1.getSelection() ? 1 : 0;
			serialManager.updateParamValue(PhotoduinoParams.system_useFlash1, photoduinoConfig.system_useFlash1);
			refreshFlashDependantFields();
		}
		
		else if(e.getSource() == system_useFlash2){
			photoduinoConfig.system_useFlash2 = system_useFlash2.getSelection() ? 1 : 0;
			serialManager.updateParamValue(PhotoduinoParams.system_useFlash2, photoduinoConfig.system_useFlash2);
			refreshFlashDependantFields();
		}
		
		else if(e.getSource() == system_devicePortType){
			photoduinoConfig.system_devicePortType = system_devicePortType.getSelectionIndex();
			serialManager.updateParamValue(PhotoduinoParams.system_devicePortType, photoduinoConfig.system_devicePortType);
			refreshDevicePortTypeDependantFields();
		}
		
		/**
		 * Intervalometer settings
		 */
		else if(e.getSource() == intervalometerMode_autofocusTime){
			photoduinoConfig.intervalometerMode_autofocusTime = intervalometerMode_autofocusTime.getSelection();
			serialManager.updateParamValue(PhotoduinoParams.intervalometerMode_autofocusTime, photoduinoConfig.intervalometerMode_autofocusTime);
		}
		
		else if(e.getSource() == intervalometerMode_preFlash1Time){
			photoduinoConfig.intervalometerMode_preFlash1Time = intervalometerMode_preFlash1Time.getSelection();
			serialManager.updateParamValue(PhotoduinoParams.intervalometerMode_preFlash1Time, photoduinoConfig.intervalometerMode_preFlash1Time);
		}
		
		else if(e.getSource() == intervalometerMode_preFlash2Time){
			photoduinoConfig.intervalometerMode_preFlash2Time = intervalometerMode_preFlash2Time.getSelection();
			serialManager.updateParamValue(PhotoduinoParams.intervalometerMode_preFlash2Time, photoduinoConfig.intervalometerMode_preFlash2Time);
		}
		
		else if(e.getSource() == intervalometerMode_preCloseTime){
			photoduinoConfig.intervalometerMode_preCloseTime = intervalometerMode_preCloseTime.getSelection();
			serialManager.updateParamValue(PhotoduinoParams.intervalometerMode_preCloseTime, photoduinoConfig.intervalometerMode_preCloseTime);
		}
		
		else if(e.getSource() == intervalometerMode_intervalUnits){
			photoduinoConfig.intervalometerMode_intervalUnits = intervalometerMode_intervalUnits.getSelectionIndex();
			serialManager.updateParamValue(PhotoduinoParams.intervalometerMode_intervalUnits, photoduinoConfig.intervalometerMode_intervalUnits);
		}
		
		else if(e.getSource() == intervalometerMode_intervalValue){
			photoduinoConfig.intervalometerMode_intervalValue = intervalometerMode_intervalValue.getSelection();
			serialManager.updateParamValue(PhotoduinoParams.intervalometerMode_intervalValue, photoduinoConfig.intervalometerMode_intervalValue);
		}
		
		else if(e.getSource() == intervalometerMode_numCycles){
			photoduinoConfig.intervalometerMode_numCycles = intervalometerMode_numCycles.getSelection();
			serialManager.updateParamValue(PhotoduinoParams.intervalometerMode_numCycles, photoduinoConfig.intervalometerMode_numCycles);
		}
		
		else if(e.getSource() == intervalometerMode_runButton){
			serialManager.runAsIntervalomenter();
		}
				
		/**
		 * Sensor trigger
		 */
		
		else if(e.getSource() == sensorBeepOnLimit){
			serialManager.setSensorBeepOnLimit(sensorBeepOnLimit.getSelection());
			refreshSensorLimits();
		}
		
		else if(e.getSource() == sensorTriggerMode_sensorType){
			photoduinoConfig.sensorTriggerMode_sensorType = sensorTriggerMode_sensorType.getSelectionIndex();
			serialManager.updateParamValue(PhotoduinoParams.sensorTriggerMode_sensorType, photoduinoConfig.sensorTriggerMode_sensorType);
			refreshSensorLimits();
		}
		
		else if(e.getSource() == sensorTriggerMode_sensorBar){
			this.sensorTriggerMode_sensorLimit.setSelection(sensorTriggerMode_sensorBar.getSelection());
			this.sensorTriggerMode_sensorLimit.notifyListeners(SWT.Selection, new Event());
		}
		
		else if(e.getSource() == sensorTriggerMode_sensorLimit){
			
			switch(photoduinoConfig.sensorTriggerMode_sensorType){
				case PhotoduinoSensorTypes.AUDIO:
					photoduinoConfig.sensorTriggerMode_sensorAudioLimit = sensorTriggerMode_sensorLimit.getSelection();
					serialManager.updateParamValue(PhotoduinoParams.sensorTriggerMode_sensorAudioLimit, photoduinoConfig.sensorTriggerMode_sensorAudioLimit);
					break;
				case PhotoduinoSensorTypes.BARRIER:
					photoduinoConfig.sensorTriggerMode_sensorBarrierLimit = sensorTriggerMode_sensorLimit.getSelection();
					serialManager.updateParamValue(PhotoduinoParams.sensorTriggerMode_sensorBarrierLimit, photoduinoConfig.sensorTriggerMode_sensorBarrierLimit);
					break;
				case PhotoduinoSensorTypes.LIGHT:
					photoduinoConfig.sensorTriggerMode_sensorLightLimit = sensorTriggerMode_sensorLimit.getSelection();
					serialManager.updateParamValue(PhotoduinoParams.sensorTriggerMode_sensorLightLimit, photoduinoConfig.sensorTriggerMode_sensorLightLimit);
					break;
				case PhotoduinoSensorTypes.SHOCK:
					photoduinoConfig.sensorTriggerMode_sensorShockLimit = sensorTriggerMode_sensorLimit.getSelection();
					serialManager.updateParamValue(PhotoduinoParams.sensorTriggerMode_sensorShockLimit, photoduinoConfig.sensorTriggerMode_sensorShockLimit);
					break;
			}
			refreshSensorLimits(); 
			
		}
		
		else if(e.getSource() == sensorTriggerMode_shootingMode){
			photoduinoConfig.sensorTriggerMode_shootingMode = sensorTriggerMode_shootingMode.getSelectionIndex();
			serialManager.updateParamValue(PhotoduinoParams.sensorTriggerMode_shootingMode, photoduinoConfig.sensorTriggerMode_shootingMode);
		}
		
		else if(e.getSource() == sensorTriggerMode_autofocusTime){
			photoduinoConfig.sensorTriggerMode_autofocusTime = sensorTriggerMode_autofocusTime.getSelection();
			serialManager.updateParamValue(PhotoduinoParams.sensorTriggerMode_autofocusTime, photoduinoConfig.sensorTriggerMode_autofocusTime);
		}
		
		else if(e.getSource() == sensorTriggerMode_preFlash1Time){
			photoduinoConfig.sensorTriggerMode_preFlash1Time = sensorTriggerMode_preFlash1Time.getSelection();
			serialManager.updateParamValue(PhotoduinoParams.sensorTriggerMode_preFlash1Time, photoduinoConfig.sensorTriggerMode_preFlash1Time);
		}
		
		else if(e.getSource() == sensorTriggerMode_preFlash2Time){
			photoduinoConfig.sensorTriggerMode_preFlash2Time = sensorTriggerMode_preFlash2Time.getSelection();
			serialManager.updateParamValue(PhotoduinoParams.sensorTriggerMode_preFlash2Time, photoduinoConfig.sensorTriggerMode_preFlash2Time);
		}
		
		else if(e.getSource() == sensorTriggerMode_preCloseTime){
			photoduinoConfig.sensorTriggerMode_preCloseTime = sensorTriggerMode_preCloseTime.getSelection();
			serialManager.updateParamValue(PhotoduinoParams.sensorTriggerMode_preCloseTime, photoduinoConfig.sensorTriggerMode_preCloseTime);
		}
		
		else if(e.getSource() == sensorTriggerMode_numCycles){
			photoduinoConfig.sensorTriggerMode_numCycles = sensorTriggerMode_numCycles.getSelection();
			serialManager.updateParamValue(PhotoduinoParams.sensorTriggerMode_numCycles, photoduinoConfig.sensorTriggerMode_numCycles);
		}
		
		else if(e.getSource() == sensorTriggerMode_interCycleTime){
			photoduinoConfig.sensorTriggerMode_interCycleTime = sensorTriggerMode_interCycleTime.getSelection();
			serialManager.updateParamValue(PhotoduinoParams.sensorTriggerMode_interCycleTime, photoduinoConfig.sensorTriggerMode_interCycleTime);
		}
		else if(e.getSource() == sensorTrigger_runButton){
			serialManager.runAsSensorTrigger();
		}
		
		/**
		 * Drops settings
		 */
		else if(e.getSource() == sensorTriggerMode_dropsCount){
			photoduinoConfig.sensorTriggerMode_dropsCount = sensorTriggerMode_dropsCount.getSelection();
			serialManager.updateParamValue(PhotoduinoParams.sensorTriggerMode_dropsCount, photoduinoConfig.sensorTriggerMode_dropsCount);
		}
		
		else if(e.getSource() == sensorTriggerMode_dropsDuration){
			photoduinoConfig.sensorTriggerMode_dropsDuration = sensorTriggerMode_dropsDuration.getSelection();
			serialManager.updateParamValue(PhotoduinoParams.sensorTriggerMode_dropsDuration, photoduinoConfig.sensorTriggerMode_dropsDuration);
		}
		
		else if(e.getSource() == sensorTriggerMode_dropsInterval){
			photoduinoConfig.sensorTriggerMode_dropsInterval = sensorTriggerMode_dropsInterval.getSelection();
			serialManager.updateParamValue(PhotoduinoParams.sensorTriggerMode_dropsInterval, photoduinoConfig.sensorTriggerMode_dropsInterval);
		}
		else if(e.getSource() == this.sensorTriggerMode_testDropsButton){
			serialManager.testDrops();
		}
		
	}
	
	/**
	 * Double click mouse handler
	 */
	public void mouseDoubleClick(MouseEvent e) {
		// Nothing to do yet
	}
	
	/**
	 * Mouse down handler
	 */
	public void mouseDown(MouseEvent e) {
		if(e.getSource() == manualControl_autofocusButton){
			serialManager.manualControlStartAutofocus();
		} 
		else if(e.getSource() == manualControl_shutterButton){
			serialManager.manualControlStartShutter();
		} 
		else if(e.getSource() == manualControl_autofocusAndShutterButton){
			serialManager.manualControlStartAutofocus();
			serialManager.manualControlStartShutter();
		} 
		else if(e.getSource() == manualControl_flash1Button){
			serialManager.manualControlShootFlash1();
		} 
		else if(e.getSource() == manualControl_flash2Button){
			serialManager.manualControlShootFlash2();
		}
		else if(e.getSource() == manualControl_solenoidValveButton){
			serialManager.manualControlDeviceOn();
		}
	}
	
	/**
	 * Mouse Up handler
	 */
	public void mouseUp(MouseEvent e) {
		if(e.getSource() == manualControl_autofocusButton){
			serialManager.manualControlStopAutofocus();
		} 
		else if(e.getSource() == manualControl_shutterButton){
			serialManager.manualControlStopShutter();
		} 
		else if(e.getSource() == manualControl_autofocusAndShutterButton){
			serialManager.manualControlStopShutter();
			serialManager.manualControlStopAutofocus();
		} 
		else if(e.getSource() == manualControl_solenoidValveButton){
			serialManager.manualControlDeviceOff();
		}
	}

	
	/**
	 * Handler for Photoduino events
	 */
	@Override
	public void handlePhotoduinoEvent(final PhotoduinoEvent e) {
		
		Display display = Display.getDefault();
		
		switch(e.getCommand()){		
		
			case PhotoduinoEvent.RSP_REPORT_READY:
				
				display.asyncExec( new Runnable() {  public void run(){
					
					String firmwareVersion = String.format("%d.%d", e.getValues()[1], e.getValues()[2]);
					
					if(firmwareVersion.equals(appConfig.getProperty("app.version"))){
						serialManager.requestStartRemoteMode(sensorBeepOnLimit.getSelection());
						logger.info("Connected to Photoduino Firmware v"+firmwareVersion);
						statusBar.setText("Connected to Photoduino Firmware v"+firmwareVersion );
						statusBar.setForeground(new Color(shell.getDisplay(), 0,0,0));
					} else {
						logger.info("You need Photoduino with firmware v"+appConfig.getProperty("app.version")+" instead v"+firmwareVersion);
						statusBar.setText("You need Photoduino with firmware v"+appConfig.getProperty("app.version")+" instead v"+firmwareVersion);
						statusBar.setForeground(new Color(shell.getDisplay(), 255,0,0));
					}
					
					
				}});
				break;
 		
			case PhotoduinoEvent.RSP_REPORT_REMOTE_MODE :
				display.asyncExec( new Runnable() {  public void run(){
					tabsPanel.setVisible(true);
					logger.info("Remote mode started");
				}});
				break;	
				
			case PhotoduinoEvent.RSP_REPORT_PARAM :
				updateReportedParam(e.getValues());
				break;
				
			case PhotoduinoEvent.RSP_REPORT_SENSOR_READ :
				updateReportedSensorRead(e.getValues());
				break;
				
			case PhotoduinoEvent.RSP_REPORT_SYSTEM_BUSY :
				display.asyncExec( new Runnable() {  public void run(){
					 // Display the message box
			        busyDialog =  new BusyDialog(shell, (e.getValues()[0] == 0) ? false : true, serialManager);
			        busyDialog.open();
				}});
				break;
			
			case PhotoduinoEvent.RSP_REPORT_SYSTEM_IDLE :
				display.asyncExec( new Runnable() {  public void run(){
					// Display the message box
			        if(busyDialog != null && !busyDialog.shell.isDisposed()) {
			        	busyDialog.shell.close();
			        	busyDialog.shell.dispose();
			        	busyDialog = null;
			        }
			        			        
				}});
				break;

				
			default: 
				logger.debug(String.format("Received unknown command %d", e.getCommand()));
				logger.debug(e.getValues());
				
				
		}
		
	}
	
	/**
	 * Handle the reported sensor read
	 * @param values
	 */
	public void updateReportedSensorRead(int[] values){
		
		//int sensorType  = values[0];
		int msb			= values[1];
		int lsb 		= values[2];
		
		lastSensorRead 	= msb*256+lsb;
		lastSensorOverflow 	= (values[3] > 0) ? true : false;

	}
	
	/**
	 * Handle a reported param value
	 * @param values
	 */
	public void updateReportedParam(int[] values){
	
		final int param = values[0];
		final int value = values[1]*256+values[2];
		
		logger.debug(String.format("Reported param: 0x%02x = %d", param, value));
		
		Display.getDefault().asyncExec( new Runnable() {  public void run(){
			
			switch(param){
				/**	
				 * System settings
				 */
				case PhotoduinoParams.system_devicePortType: 
					system_devicePortType.select(value);
					photoduinoConfig.system_devicePortType = value;
					refreshDevicePortTypeDependantFields();
					break;
					
				case PhotoduinoParams.system_sensorTuningMode:
					system_sensorTuningMode.select(value);
					photoduinoConfig.system_sensorTuningMode = value;
					break;
					
				case PhotoduinoParams.system_cameraShutterLag:
					system_cameraShutterLag.setSelection(value);
					photoduinoConfig.system_cameraShutterLag = value;
					break;
					
				case PhotoduinoParams.system_cameraMirrorLockUpTimeout:
					system_cameraMirrorLockUpTimeout.setSelection(value);
					photoduinoConfig.system_cameraMirrorLockUpTimeout = value;
					break;
				
				case PhotoduinoParams.system_useFlash1:
					system_useFlash1.setSelection( value == 1 ? true : false );
					photoduinoConfig.system_useFlash1 = value;
					refreshFlashDependantFields();
					break;	
				
				case PhotoduinoParams.system_useFlash2:
					system_useFlash2.setSelection( value == 1 ? true : false );
					photoduinoConfig.system_useFlash2 = value;
					refreshFlashDependantFields();
					break;	
					
				case PhotoduinoParams.system_useBacklight:
					system_useBacklight.setSelection( value == 1 ? true : false );
					photoduinoConfig.system_useBacklight = value;
					break;
				
				/**
				 * Intervalometer mode settings
				 */
				case PhotoduinoParams.intervalometerMode_autofocusTime:
					intervalometerMode_autofocusTime.setSelection(value);
					photoduinoConfig.intervalometerMode_autofocusTime = value;
					break;	
					
				case PhotoduinoParams.intervalometerMode_preFlash1Time:
					intervalometerMode_preFlash1Time.setSelection(value);
					photoduinoConfig.intervalometerMode_preFlash1Time = value;
					break;	
				
				case PhotoduinoParams.intervalometerMode_preFlash2Time:
					intervalometerMode_preFlash2Time.setSelection(value);
					photoduinoConfig.intervalometerMode_preFlash2Time = value;
					break;	
				
				case PhotoduinoParams.intervalometerMode_preCloseTime:
					intervalometerMode_preCloseTime.setSelection(value);
					photoduinoConfig.intervalometerMode_preCloseTime = value;
					break;	
				
				case PhotoduinoParams.intervalometerMode_intervalValue:
					intervalometerMode_intervalValue.setSelection(value);
					photoduinoConfig.intervalometerMode_intervalValue = value;
					break;	
				
				case PhotoduinoParams.intervalometerMode_intervalUnits:
					intervalometerMode_intervalUnits.select(value);
					photoduinoConfig.intervalometerMode_intervalUnits = value;
					break;	
				
				case PhotoduinoParams.intervalometerMode_numCycles:
					intervalometerMode_numCycles.setSelection(value);
					photoduinoConfig.intervalometerMode_numCycles = value;
					break;	
				
				/**
				 * Sensor trigger settings
				 */	
				case PhotoduinoParams.sensorTriggerMode_sensorType:
					sensorTriggerMode_sensorType.select(value);
					photoduinoConfig.sensorTriggerMode_sensorType = value;
					refreshSensorLimits();
					break;	
					
				case PhotoduinoParams.sensorTriggerMode_sensorAudioLimit:
					photoduinoConfig.sensorTriggerMode_sensorAudioLimit = value;
					refreshSensorLimits();
					break;
					
				case PhotoduinoParams.sensorTriggerMode_sensorBarrierLimit:
					photoduinoConfig.sensorTriggerMode_sensorBarrierLimit = value;
					refreshSensorLimits();
					break;
				
				case PhotoduinoParams.sensorTriggerMode_sensorLightLimit:
					photoduinoConfig.sensorTriggerMode_sensorLightLimit = value;
					refreshSensorLimits();
					break;
				
				case PhotoduinoParams.sensorTriggerMode_sensorShockLimit:
					photoduinoConfig.sensorTriggerMode_sensorShockLimit = value;
					refreshSensorLimits();
					break;
				
				case PhotoduinoParams.sensorTriggerMode_shootingMode:
					sensorTriggerMode_shootingMode.select(value);
					photoduinoConfig.sensorTriggerMode_shootingMode = value;
					break;	
				
				case PhotoduinoParams.sensorTriggerMode_autofocusTime:
					sensorTriggerMode_autofocusTime.setSelection(value);
					photoduinoConfig.sensorTriggerMode_autofocusTime = value;
					break;	
				
				case PhotoduinoParams.sensorTriggerMode_preFlash1Time:
					sensorTriggerMode_preFlash1Time.setSelection(value);
					photoduinoConfig.sensorTriggerMode_preFlash1Time = value;
					break;	
				
				case PhotoduinoParams.sensorTriggerMode_preFlash2Time:
					sensorTriggerMode_preFlash2Time.setSelection(value);
					photoduinoConfig.sensorTriggerMode_preFlash2Time = value;
					break;	
				
				case PhotoduinoParams.sensorTriggerMode_preCloseTime:
					sensorTriggerMode_preCloseTime.setSelection(value);
					photoduinoConfig.sensorTriggerMode_preCloseTime = value;
					break;	
								
				case PhotoduinoParams.sensorTriggerMode_numCycles:
					sensorTriggerMode_numCycles.setSelection(value);
					photoduinoConfig.sensorTriggerMode_numCycles = value;
					break;	
								
				case PhotoduinoParams.sensorTriggerMode_interCycleTime:
					sensorTriggerMode_interCycleTime.setSelection(value);
					photoduinoConfig.sensorTriggerMode_interCycleTime = value;
					break;	
								
				case PhotoduinoParams.sensorTriggerMode_dropsCount:
					sensorTriggerMode_dropsCount.setSelection(value);
					photoduinoConfig.sensorTriggerMode_dropsCount = value;
					break;	
								
				case PhotoduinoParams.sensorTriggerMode_dropsDuration:
					sensorTriggerMode_dropsDuration.setSelection(value);
					photoduinoConfig.sensorTriggerMode_dropsDuration = value;
					break;	
								
				case PhotoduinoParams.sensorTriggerMode_dropsInterval:
					sensorTriggerMode_dropsInterval.setSelection(value);
					photoduinoConfig.sensorTriggerMode_dropsInterval = value;
					break;	
			}
		
		}});
		
	}
	
	/**
	 * Refresh sensor limits depending of the sensor type
	 */
	private void refreshSensorLimits(){
		
	 switch(photoduinoConfig.sensorTriggerMode_sensorType){
	 	
	 	case PhotoduinoSensorTypes.NONE:	
	 		sensorBeepOnLimit.setVisible(false);
	 		sensorTriggerMode_sensorLimitLabel.setVisible(false);
	 		sensorTriggerMode_sensorLimit.setVisible(false);	 		
	 		sensorTriggerMode_sensorBar.setVisible(false);
	 		break;
	 		
	 	case PhotoduinoSensorTypes.AUDIO:
	 		sensorBeepOnLimit.setVisible(true);
	 		sensorTriggerMode_sensorLimitLabel.setVisible(true);
	 		sensorTriggerMode_sensorLimit.setVisible(true);	 		
	 		sensorTriggerMode_sensorBar.setVisible(true);
	 		sensorTriggerMode_sensorLimit.setSelection(photoduinoConfig.sensorTriggerMode_sensorAudioLimit);
	 		break;
	 	
	 	case PhotoduinoSensorTypes.BARRIER:
	 		sensorBeepOnLimit.setVisible(true);
	 		sensorTriggerMode_sensorLimitLabel.setVisible(true);
	 		sensorTriggerMode_sensorLimit.setVisible(true);	 		
	 		sensorTriggerMode_sensorBar.setVisible(true);
	 		sensorTriggerMode_sensorLimit.setSelection(photoduinoConfig.sensorTriggerMode_sensorBarrierLimit);
	 		break;
	 		
	 	case PhotoduinoSensorTypes.LIGHT:
	 		sensorBeepOnLimit.setVisible(true);
	 		sensorTriggerMode_sensorLimitLabel.setVisible(true);
	 		sensorTriggerMode_sensorLimit.setVisible(true);	 		
	 		sensorTriggerMode_sensorBar.setVisible(true);
	 		sensorTriggerMode_sensorLimit.setSelection(photoduinoConfig.sensorTriggerMode_sensorLightLimit);
	 		break;
	 
	 	case PhotoduinoSensorTypes.SHOCK:
	 		sensorBeepOnLimit.setVisible(true);
	 		sensorTriggerMode_sensorLimitLabel.setVisible(true);
	 		sensorTriggerMode_sensorLimit.setVisible(true);	 		
	 		sensorTriggerMode_sensorBar.setVisible(true);
	 		sensorTriggerMode_sensorLimit.setSelection(photoduinoConfig.sensorTriggerMode_sensorShockLimit);
	 		break;

	 }
	}
	
	/**
	 * Hide or show flash dependant fields
	 */
	private void refreshFlashDependantFields(){
		
		if(photoduinoConfig.system_useFlash1 == 0) {
			intervalometerMode_preFlash1Time.setVisible(false);
			sensorTriggerMode_preFlash1Time.setVisible(false);
		} else {
			intervalometerMode_preFlash1Time.setVisible(true);
			sensorTriggerMode_preFlash1Time.setVisible(true);
		}
		
		if(photoduinoConfig.system_useFlash2 == 0) {
			intervalometerMode_preFlash2Time.setVisible(false);
			sensorTriggerMode_preFlash2Time.setVisible(false);
		} else {
			intervalometerMode_preFlash2Time.setVisible(true);
			sensorTriggerMode_preFlash2Time.setVisible(true);
		}
	}
	
	/**
	 * Hide or show device port dependant fields
	 */
	private void refreshDevicePortTypeDependantFields(){
	
		switch(photoduinoConfig.system_devicePortType){
		
			case PhotoduinoDevicePortTypes.NONE: 
				sensorTrigger_dropsConfigGroup.setVisible(false);
				manualControl_solenoidValveGroup.setVisible(false);
				break;
				
			case PhotoduinoDevicePortTypes.LASER: 
				sensorTrigger_dropsConfigGroup.setVisible(false);
				manualControl_solenoidValveGroup.setVisible(false);
				break;
				
			case PhotoduinoDevicePortTypes.SOLENOID_VALVE: 
				sensorTrigger_dropsConfigGroup.setVisible(true);
				manualControl_solenoidValveGroup.setVisible(true);
				break;
				
		}
	}
	
	private void connect(){
		String portName = serialPortListCombo.getItem(serialPortListCombo.getSelectionIndex());
		if(serialManager.connect(portName, appConfig.getProperty("app.name")+" "+appConfig.getProperty("app.version"))){
			serialPortListCombo.setEnabled(false);
			connectButton.setText("Disconnect");
			statusBar.setText("Connected and waiting for firmware response ...");
			statusBar.setForeground(new Color(shell.getDisplay(), 0,0,0));
		}
	}
	
	private void disconnect(){
		
		if(serialManager.isConnected()){
			serialManager.requestStopRemoteMode();
			serialManager.disconnect();
			serialPortListCombo.setEnabled(true);
			connectButton.setText("Connect");
			statusBar.setText("Disconnected");
			statusBar.setForeground(new Color(shell.getDisplay(), 0,0,0));
			tabsPanel.setVisible(false);
		}
	}
}
