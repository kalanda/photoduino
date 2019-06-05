---
layout: default
title: Sensor trigger mode
---
![](../../../assets/images/lcd-sensor-trigger-mode-menu.jpg "lcd-sensor-trigger-mode-menu")

This run mode is used to take pictures based on the sensor readings. Main uses are “High Speed Photography” and “Nature photography”

## Submenus

When you enter in the “Sensor trigger” option of the main menu, you will found this submenus.

-   **Config trigger: **Defines the config parameters of this mode used according the “Life cycle of execution”.
-   **Config drops:** Only if the “Device type” in the “[System config](../system-config/ "System config")” is equal to Electrovalve.
-   **Run: **Entering this option will start the run mode according the Life cycle of execution. To cancel the execution, just press and hold one button until the LCD displays “Aborting…”
-   **Reset config: **This option resets the config parameters of this run mode to the default values.

## Config trigger

<table>
<thead>
<tr>
<th style="width: 100px;"><strong>Parameter</strong></th>
<th style="width: 150px;"><strong>Values</strong></th>
<th><strong>Function</strong></th>
</tr>
</thead>
<tbody>
<tr>
<td><em>Sensor</em></td>
<td>
<ul>
<li>Barrier</li>
<li>Audio</li>
<li>Light</li>
<li>Shock</li>
</ul>
</td>
<td>Define which type of sensor will be used in this mode.</td>
</tr>
<tr>
<td><em>Sensor limit</em></td>
<td>
<ul>
<li>0-15 in visual mode</li>
<li>0-999 in numeric mode</li>
</ul>
</td>
<td>Define the trigger limit of the sensor. The tunning mode of this limit is defined by the “Sensor tunning” parameter in the “<a title="System config" href="../system-config/">System config</a>“</td>
</tr>
<tr>
<td><em>Shooting mode</em></td>
<td>
<ul>
<li>Normal</li>
<li>Prebulb</li>
<li>Mirror Lockup</li>
</ul>
</td>
<td>Determines the shooting mode used below in the life cycle of execution.</td>
</tr>
<tr>
<td><em>Autofocus time</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>The time in milliseconds used by the camera autofocus. It is only necessary if the camera is set in AF mode. If manual focusing is set, this value should be set to 0.</td>
</tr>
<tr>
<td><em>Flash1 pretime</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>Time in milliseconds to wait before firing the FLASH1.</td>
</tr>
<tr>
<td><em>Flash2 pretime</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>Time in milliseconds to wait before firing the FLASH2.</td>
</tr>
<tr>
<td><em>Close pretime</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>Time in milliseconds to wait before closing the shutter.</td>
</tr>
<tr>
<td><em>Cycles</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>Number of times to repeat the life cycle of execution. (“Zero” is equal to endless repetitions)</td>
</tr>
<tr>
<td><em>Intercycle time</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>Time in milliseconds to wait between each cycle. This parameter is often appropriate to allow enough time to the camera to process the final image.</td>
</tr>
</tbody>
</table>

## Config drops

**EXPERIMENTAL FUNTIONALITY**

The life cycle of execution don’t shows this drops functionality, but drops are generated always before “Waits for sensor” blocks in the diagram.

This parameters are used only if the electrovalve connected to the device port and configured in the “Device type” of the “[System config](../system-config/ "System config")”

<table>
<thead>
<tr>
<th style="width: 100px;">Parameter</th>
<th style="width: 100px;">Values</th>
<th>Function</th>
</tr>
</thead>
<tbody>
<tr>
<td><em>Drops count</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>&nbsp;Number of drops to make</td>
</tr>
<tr>
<td><em>Drops duration</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>Time in milliseconds defining the duration of each drop</td>
</tr>
<tr>
<td><em>Drops interval</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>Time in millisecond between each drop</td>
</tr>
</tbody>
</table>

## Life cycle of execution

The life cycle is the diagram that explains the execution and how each parameters are used when you  run the sensor trigger mode.

There are three life cycles of execution. Each one are dependant of the “Shooting Mode” parameter of the “Config trigger” section.

1.  Normal mode
2.  Pre-Bulb mode
3.  Mirror Lock-Up mode

### Shooting mode: Normal

This mode is intended to take pictures starting the process by a sensor but using the normal operation of the camera to take it. If you want to save the mechanical time of the normal operation of the camera to take high speed pictures, you should use the “Pre-Bulb mode” or the “Mirror Lock-up mode” described later.

![](../../../assets/images/en-sensor-shotting-normal-lifecicle.jpg "Shooting mode normal lifecycle")

### Shooting mode: Pre Bulb

In this mode, the system is assuming that you set your camera in BULB mode and  you will use one or two flashes to take the picture in a dark room. Using this mode you avoid all mechanical lags produced by the camera and take the photos with fastest time of response and the fastest time of exposure defined by the duration of the flash that you are using.

![](../../../assets/images/en-sensor-shotting-prebulb-lifecicle.jpg "Shooting mode prebulb")

### Shooting mode: Mirror Lock-Up

Your camera should have a internal option to previously look-up the mirror before fire the shutter to avoid mechanical lags. Use this mode in combination with this option in your camera to automatically look-up your mirror from Photoduino before wait for the sensor and take the picture as fast as possible and avoiding vibrations in your camera when take the picture.

![](../../../assets/images/en-sensor-shotting-mirrorlockup-lifecicle.jpg "Shooting mode Mirror Lock-Up")

## Important notes

-   The total exposure time is the sum of all waiting times between shutter opening (just after waits shutter lag) and shutter closing (just before deactivate the shutter) whenever the camera is configured in BULB.

-   If the camera is not set to BULB mode, the total exposure time is then indicated by the selected shutter speed in the camera.

-   If the camera is set to manual focus, autofocus time must be set to “zero” to not add unnecessary lags.

-   If the camera is set to autofocus mode, the needed time to focus depends on the scene, giving himself the chance that the shutter not fires because of lack of focus.

-   If the parameter “Cycles” is “zero” is equivalent to “infinite”, so the process is repeated continuously until canceled by pressing and holding one of the two buttons.
