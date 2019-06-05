---
layout: default
title: Intervalometer mode
---
![](../../../assets/images/lcd-interval-mode-menu.jpg "lcd-interval-mode-menu")

This run mode is used to take pictures in configurable time intervals . You can set the interval time in seconds, minutes, hours and days, and also other parameters which define the whole operation mode.

## Submenus

When you enter in this main menu option, you have 3 submenus.

-   **Config:** Define the config parameters of this mode used in the ”life cycle of execution” showed below.
-   **Run:** This option will start the run mode according to the ”Life cycle of execution”. For cancelling the execution, just press and hold one button until the LCD displays “Aborting…”
-   **Reset config:** This option will reset the config parameters of this run mode to the default values.

## Config parameters

<table>
<tbody>
<tr>
<th style="width: 100px; "><strong>Parameter</strong></th>
<th style="width: 100px; "><strong>Values</strong></th>
<th><strong>Function</strong></th>
</tr>
<tr>
<td><em>Autofocus time</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>Time in milliseconds used for autofocusing the camera. It is only necessary if the camera is set in AF mode. If manual focusing is set, this value should be set to 0.</td>
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
<td><em>Interval units</em></td>
<td>
<ul>
<li>ms</li>
<li>seconds</li>
<li>minutes</li>
<li>hours</li>
<li>days</li>
</ul>
</td>
<td>The interval units for the interval value</td>
</tr>
<tr>
<td><em>Interval value</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>The interval value for the interval units previously set.</td>
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
</tbody>
</table>

## Life cycle of execution

![](../../../assets/images/en-intervalometer-lifecycle.jpg "Intervalometer lifecycle")

## Important notes

-   The total exposure time is the sum of all waiting times between shutter opening (just after waits shutter lag) and shutter closing (just before deactivate the shutter) whenever the camera is configured in BULB.

-   If the camera is not set to BULB mode, the total exposure time is then indicated by the selected shutter speed in the camera.

-   If the camera is set to manual focus, autofocus time must be set to “zero” to not add unnecessary lags.

-   If the camera is set to autofocus mode, the needed time to focus depends on the scene, giving himself the chance that the shutter not fires because of lack of focus.

-   If the parameter “Cycles” is “zero” is equivalent to “infinite”, so the process is repeated continuously until canceled by pressing and holding one of the two buttons.
