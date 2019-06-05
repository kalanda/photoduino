---
layout: default
title: Photoduino Solenoid Valve Interface 1.0
---

![](../../../assets/images/IMG_4806.jpg "Photoduino Solenoid Valve Interface 1.0")

Photoduino’s firmware version 0.10 was released to include the ability to control a solenoid valve and  automatically generate drops with Photoduino.

Solenoid valves  are typically powered through 12VDC and have a high current consumption, so we need this new circuit to be connected to Photoduino’s DEVICE port so it allows the connection to a solenoid valve and a 12VDC power supply.

The control of the valve is performed by a Mosfet IRL520 logic transistor and the circuit also includes a 1N4004 diode to prevent the reverse current that is accumulated in the coil.

The board is designed in a single sided PCB so it is quite easy to make at home, but it is also available for purchase as a kit which includes a solenoid valve, a 60 ml syringe and a 12VDC battery holder.

The 12V needed to feed the solenoid valve can be supplied by the 8xAA (R6) battery holder included in the kit. You can also use a 12VDC with at least 500 mA current (not included).

## Part list

<table border="0" frame="VOID" rules="NONE" cellspacing="0">
<thead>
<tr>
<th style="text-align: center;" align="RIGHT" width="43" height="19">Qty</th>
<th align="LEFT" width="307">Part name</th>
<th align="LEFT" width="97">Suggestion</th>
</tr>
</thead>
<colgroup>
<col width="43" />
<col width="307" />
<col width="97" /></colgroup>
<tbody>
<tr>
<td style="text-align: center;" align="RIGHT" width="43" height="19">1</td>
<td align="LEFT" width="307">PCB Solenoid valve interface 1.0</td>
<td align="LEFT" width="97"><a href="http://sourceforge.net/projects/photoduino/files/hardware/photoduino.solenoid.valve.interface.1.0.zip/download" target="_blank">eaglecad files</a> <br>
 <a href="https://oshpark.com/profiles/photoduino">order at oshpark.com</a></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" width="43" height="19">1</td>
<td align="LEFT" width="307">12v Solenoid Valve</td>
<td align="LEFT" width="97"><a href="http://www.jameco.com/webapp/wcs/stores/servlet/Product_10001_10001_169835_-1" target="_blank">jameco</a></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" height="18">1</td>
<td align="LEFT">1N4004 Diode</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/Fairchild-Semiconductor/1N4004/?qs=sGAEpiMZZMtbRapU8LlZD6Aoap19JQAxY2gML8gEYQU=" target="_blank">mouser</a></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" height="19">1</td>
<td align="LEFT">10 Kohms resistor</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/KOA-Speer/CF1-4CT52R103J/?qs=/ha2pyFaduhcR7YWghnBNohs8vFPbHXcGsL5ejOIEA8FpelIXoecIg==" target="_blank">mouser</a></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" height="18">2</td>
<td align="LEFT">2 pins terminal block</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/TE-Connectivity/1546217-2/?qs=/ha2pyFadui5vPiFZWIRtlnll7gvt4j9cS3WxuW3x4U6b7MTIqipBA==" target="_blank">mouser</a></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" height="18">1</td>
<td align="LEFT">MOSFET IRL520</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/Vishay/IRL520PBF/?qs=%2fha2pyFadugoFc60oJQhYd0RYsxf419zr4vF1d%2frxafGYvd3gH3YYQ%3d%3d" target="_blank">mouser</a></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" height="19">1</td>
<td align="LEFT">8xAA battery socket</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/Eagle-Plastic-Devices/12BH382A-GR/?qs=%2fha2pyFadui3zNDXDd7sNGvpURQZ7stWJIrkaUzvJZs%3d">mouser</a></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" height="19">1</td>
<td align="LEFT">RCA pcb female jack</td>
<td align="LEFT"><a href="http://www.sparkfun.com/products/8631" target="_blank">sparkfun</a></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" height="18">1</td>
<td align="LEFT">RCA male-to-male cable</td>
<td align="LEFT"><a href="http://es.farnell.com/pro-signal/av00243/lead-phono-plg-plg-1-2m/dp/3712205?Ntt=3712205">farnell</a></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" height="19">1</td>
<td align="LEFT">50 ml syringe luer catheter without needle</td>
<td align="LEFT"><a href="http://www.totclinic.com/jeringas-sin-aguja/62-jeringas-sin-aguja-de-50-ml-luer-cateter.html" target="_blank">totclinic</a></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" height="18">1</td>
<td align="LEFT">Doble wire 2&#215;0,50mm</td>
<td align="LEFT"></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" height="19">1</td>
<td align="LEFT">Microtube 4mm x 0,25cm</td>
<td align="LEFT"></td>
</tr>
</tbody>
</table>

[Check the Building Instructions](build-instructions-solenoid-valve-interface/ "Build instructions: Solenoid Valve Interface")

## PCB Schematics

\- [Download the Eaglecad files of the circuit](http://sourceforge.net/projects/photoduino/files/hardware/photoduino.solenoid.valve.interface.1.0.zip/download)

![](../../../assets/images/electrovalve-interface-schema-600x492.png "electrovalve-interface-schema")

![](../../../assets/images/electrovalve-interface-board-600x496.png "electrovalve-interface-board")

## Some other pictures

![](../../../assets/images/IMG_4828.jpg "Photoduino Solenoid Valve Interface 1.0")

![](../../../assets/images/IMG_5235.jpg "Photoduino Solenoid Valve Interface 1.0")

![](../../../assets/images/IMG_5241.jpg "Photoduino Solenoid Valve Interface 1.0")

![](../../../assets/images/IMG_5245.jpg "Photoduino Solenoid Valve Interface 1.0")

![](../../../assets/images/IMG_5248.jpg "Photoduino Solenoid Valve Interface 1.0")

![](../../../assets/images/IMG_5491.jpg "Photoduino Solenoid Valve Interface 1.0")
