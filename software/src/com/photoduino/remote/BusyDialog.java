package com.photoduino.remote;

import org.eclipse.swt.widgets.Dialog;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Listener;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.SWT;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.events.SelectionEvent;

public class BusyDialog extends Dialog implements SelectionListener {
	
	protected Object result;
	protected Shell shell;
	private PhotoduinoSerialManager serialManager;
	private Label lblPhotoduinoHardwareIs;
	private Boolean isCancelable;
	private Button btnCancel;
	
	/**
	 * Create the dialog.
	 * @param parent
	 * @param style
	 */
	public BusyDialog(Shell parent, Boolean cancelable, PhotoduinoSerialManager serialManager) {
		super(parent);
		this.isCancelable = cancelable;
		this.serialManager = serialManager;
		
	}
	

	/**
	 * Open the dialog.
	 * @return the result
	 */
	public Object open() {
		createContents();
		
		if(isCancelable == false) btnCancel.setVisible(false); 
		
		shell.addListener(SWT.Traverse, new Listener() {
	  		@Override
			public void handleEvent(Event e) {
				if (e.detail == SWT.TRAVERSE_ESCAPE) {
		              e.doit = false;
		            }
			}
        });
		
		shell.pack();
		shell.open();
		shell.layout();
		Display display = getParent().getDisplay();
		while (!shell.isDisposed()) {
			if (!display.readAndDispatch()) {
				display.sleep();
			}
		}
		return result;
	}

	/**
	 * Create contents of the dialog.
	 */
	private void createContents() {
		shell = new Shell(getParent(), SWT.PRIMARY_MODAL | SWT.SHEET /*| SWT.NO_TRIM*/ );
		shell.setText(getText());
		shell.setLayout(new GridLayout(1, false));
		new Label(shell, SWT.NONE);
		
		lblPhotoduinoHardwareIs = new Label(shell, SWT.WRAP | SWT.CENTER);
		GridData gd_lblPhotoduinoHardwareIs = new GridData(SWT.CENTER, SWT.CENTER, true, false, 1, 1);
		gd_lblPhotoduinoHardwareIs.widthHint = 234;
		gd_lblPhotoduinoHardwareIs.heightHint = 44;
		lblPhotoduinoHardwareIs.setLayoutData(gd_lblPhotoduinoHardwareIs);
		lblPhotoduinoHardwareIs.setText("Photoduino hardware is busy doing some magic things. Please wait.");
		
		btnCancel = new Button(shell, SWT.NONE);
		btnCancel.addSelectionListener(this);
		btnCancel.setLayoutData(new GridData(SWT.CENTER, SWT.CENTER, false, false, 1, 1));
		btnCancel.setText("Request cancel on next cycle");

	}
	public void widgetDefaultSelected(SelectionEvent e) {
	}
	public void widgetSelected(SelectionEvent e) {
		if (e.getSource() == btnCancel){
			serialManager.requestCancelRunMode();
			btnCancel.setText("Cancellation in progress...");
			btnCancel.setEnabled(false);
		}
	}
}
