---
layout: default
title: System config
---

![](../../../assets/images/lcd-system-config-menu.jpg "lcd-system-config-menu")

In this section, you can set common parameters of the system.

<table>
    <thead>
        <tr>
            <th style="width: 100px;"><strong>Parameter</strong></th>
            <th style="width: 100px;"><strong>Values</strong></th>
            <th><strong>Function</strong></th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><em>Device Type</em></td>
            <td>
                <ul>
                    <li>None</li>
                    <li>Laser</li>
                    <li>Electrovalve</li>
                </ul>
            </td>
            <td>Define what type of device is connected to the DEVICE port connector. If the device is
                &#8220;Electrovalve&#8221;, you will see the &#8220;Drops config&#8221; option into the &#8220;<a
                    title="Sensor trigger mode" href="../sensor-trigger-mode/">Sensor trigger</a>&#8221; mode. If device
                is &#8220;Laser&#8221;, the system will turn off the laser before the photo is taken after the laser
                barrier is crossed.</td>
        </tr>
        <tr>
            <td><em>Sensor tunning</em></td>
            <td>
                <ul>
                    <li>Visual</li>
                    <li>Numeric</li>
                </ul>
            </td>
            <td>Define how the tunning of sensor limit works. The selected mode will be used in &#8220;<a
                    title="Sensor trigger mode" href="../sensor-trigger-mode/">Sensor trigger</a>&#8221; mode when
                adjust the sensor limit.</td>
        </tr>
        <tr>
            <td><em>Shutterlag time</em></td>
            <td>
                <ul>
                    <li>0-59999</li>
                </ul>
            </td>
            <td>Shutterlag time used in all run modes expressed in milliseconds. This time depends of the camera model.
                See the <a title="Cameras shutterlag" href="../../reference/cameras-shutterlag/">shutterlag
                    reference</a>.</td>
        </tr>
        <tr>
            <td><em>Mirror timeout</em></td>
            <td>
                <ul>
                    <li>0-59999</li>
                </ul>
            </td>
            <td>Timeout expressed in milliseconds until the mirror is lockdown by the camera when using the
                &#8220;Mirror lock-up&#8221; mode in the &#8220;<a title="Sensor trigger mode"
                    href="../sensor-trigger-mode/">Sensor trigger</a>&#8221; mode</td>
        </tr>
        <tr>
            <td><em>Use Flash1</em></td>
            <td>
                <ul>
                    <li>Yes</li>
                    <li>No</li>
                </ul>
            </td>
            <td>Define if &#8220;Flash1&#8243; is used or not. If &#8220;YES&#8221;, some options will appear in the
                &#8220;<a title="Intervalometer mode" href="../intervalometer-mode/">Intervalometer</a>&#8221; and
                &#8220;<a title="Sensor trigger mode" href="../sensor-trigger-mode/">Sensor trigger</a>&#8221; menus
                related to this flash.</td>
        </tr>
        <tr>
            <td><em>Use Flash2</em></td>
            <td>
                <ul>
                    <li>Yes</li>
                    <li>No</li>
                </ul>
            </td>
            <td>Define if &#8220;Flash2&#8243; is used or not. If &#8220;YES&#8221;, some options will appear in the
                &#8220;<a title="Intervalometer mode" href="../intervalometer-mode/">Intervalometer</a>&#8221; and
                &#8220;<a title="Sensor trigger mode" href="../sensor-trigger-mode/">Sensor trigger</a>&#8221; menus
                related to this flash.</td>
        </tr>
        <tr>
            <td><em>Speaker</em></td>
            <td>
                <ul>
                    <li>Yes</li>
                    <li>No</li>
                </ul>
            </td>
            <td>Determines if the system beeps or not. If beeps is activated, the system will beep every time you enter
                o exit a section of navigation menus, when you change a setting that is logical value and when you are
                adjusting a sensor limit to indicate that reading is exceeding the limit value selected.</td>
        </tr>
        <tr>
            <td><em>Backlight</em></td>
            <td>
                <ul>
                    <li>Yes</li>
                    <li>No</li>
                </ul>
            </td>
            <td>Will turn ON/OFF the LCD backlight.</td>
        </tr>
    </tbody>
</table>
