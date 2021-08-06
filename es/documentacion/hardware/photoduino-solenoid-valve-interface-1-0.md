---
layout: default
lang: es
title: Photoduino Solenoid Valve Interface 1.0
---
![](../../../../assets/images/IMG_4806.jpg "Photoduino Solenoid Valve Interface 1.0")

Con la publicación del Photoduino Firmware v.0.10 se incluyó la posibilidad de controlar una electroválvula o válvula de solenoide, para generar gotas automáticamente desde Photoduino.

Las electroválvulas funcionan generalmente con 12v tienen un consumo alto de corriente, por lo que es necesario este nuevo circuito que conectado al puerto DEVICE de Photoduino permite la conexión de una electroválvula y su propia alimentación de 12v.

El control se realiza mediante un transistor lógico MOSFET IRL520 y el circuito incluye también un diodo 1N4004 de protección para evitar que la corriente acumulada en la bobina del solenoide retorne hacia afuera.

La PCB está diseñada en una sola cara de cobre, por lo que es fácil realizarla en casa, pero también está disponible para comprarla desde hoy en forma de kit que también incluye una electroválvula, un deposito para el líquido y un portabaterias de 12v para alimentarlo.

La alimentación de 12v puede realizarse mediante el portabaterias de 8 pilas de 1,5v (12v en total) incluido en el kit o se puede utilizar una fuente de alimentación de DC 12v de al menos 500mA (no incluida en el kit).

## Lista de componentes

<table>
<thead>
<tr>
<th style="text-align: center;" align="RIGHT" width="43" height="19">Cantidad</th>
<th align="LEFT" width="307">Componente</th>
<th align="LEFT" width="97">Sugerencia</th>
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
<td align="LEFT" width="97"><a href="http://sourceforge.net/projects/photoduino/files/hardware/photoduino.solenoid.valve.interface.1.0.zip/download" target="_blank">fichero eaglecad</a> <br>
 <a href="https://oshpark.com/profiles/photoduino">comprar en oshpark.com</a></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" width="43" height="19"><a href="http://sourceforge.net/projects/photoduino/files/hardware/photoduino.solenoid.valve.interface.1.0.zip/download" target="_blank">1</a></td>
<td align="LEFT" width="307">Electrovalvula</td>
<td align="LEFT" width="97"><a href="http://www.jameco.com/webapp/wcs/stores/servlet/Product_10001_10001_169835_-1" target="_blank">jameco</a></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" height="18">1</td>
<td align="LEFT">Diodo 1N4004</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/Fairchild-Semiconductor/1N4004/?qs=sGAEpiMZZMtbRapU8LlZD6Aoap19JQAxY2gML8gEYQU=" target="_blank">mouser</a></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" height="19">1</td>
<td align="LEFT">Resistencia 10 Kohms</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/KOA-Speer/CF1-4CT52R103J/?qs=/ha2pyFaduhcR7YWghnBNohs8vFPbHXcGsL5ejOIEA8FpelIXoecIg==" target="_blank">mouser</a></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" height="18">2</td>
<td align="LEFT">Bloque terminal 2 pines</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/TE-Connectivity/1546217-2/?qs=/ha2pyFadui5vPiFZWIRtlnll7gvt4j9cS3WxuW3x4U6b7MTIqipBA==" target="_blank">mouser</a></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" height="18">1</td>
<td align="LEFT">MOSFET IRL520</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/Vishay/IRL520PBF/?qs=%2fha2pyFadugoFc60oJQhYd0RYsxf419zr4vF1d%2frxafGYvd3gH3YYQ%3d%3d" target="_blank">mouser</a></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" height="19">1</td>
<td align="LEFT">Portabaterias 8xAA</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/Eagle-Plastic-Devices/12BH382A-GR/?qs=%2fha2pyFadui3zNDXDd7sNGvpURQZ7stWJIrkaUzvJZs%3d">mouser</a></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" height="19">1</td>
<td align="LEFT">Conector RCA para PCB</td>
<td align="LEFT"><a href="http://www.sparkfun.com/products/8631" target="_blank">sparkfun</a></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" height="18">1</td>
<td align="LEFT">Cable RCA macho a macho</td>
<td align="LEFT"><a href="http://es.farnell.com/pro-signal/av00243/lead-phono-plg-plg-1-2m/dp/3712205?Ntt=3712205">farnell</a></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" height="19">1</td>
<td align="LEFT">Jeringa sin aguja 50ml luer cateter</td>
<td align="LEFT"><a href="http://www.totclinic.com/jeringas-sin-aguja/62-jeringas-sin-aguja-de-50-ml-luer-cateter.html" target="_blank">totclinic</a></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" height="18">1</td>
<td align="LEFT">Cable 2&#215;0,50mm 0,5m bicolor</td>
<td align="LEFT"></td>
</tr>
<tr>
<td style="text-align: center;" align="RIGHT" height="19">1</td>
<td align="LEFT">Microtubo 4mm x 0,25cm</td>
<td align="LEFT"></td>
</tr>
</tbody>
</table>

[Consulta las instrucciones de montaje](instrucciones-de-montaje-solenoid-valve-interface/ "Instrucciones de montaje: Solenoid Valve Interface")

## Esquema de la PCB

\- [Descargar esquemas del circuito en formato Eaglecad](http://sourceforge.net/projects/photoduino/files/hardware/photoduino.solenoid.valve.interface.1.0.zip/download)

![](../../../../assets/images/electrovalve-interface-schema-600x492.png "electrovalve-interface-schema")

![](../../../../assets/images/electrovalve-interface-board-600x496.png "electrovalve-interface-board")

![](../../../../assets/images/IMG_5235.jpg "Photoduino Solenoid Valve Interface 1.0")

![](../../../../assets/images/IMG_4828.jpg "Photoduino Solenoid Valve Interface 1.0")

![](../../../../assets/images/IMG_5241.jpg "Photoduino Solenoid Valve Interface 1.0")

![](../../../../assets/images/IMG_5245.jpg "Photoduino Solenoid Valve Interface 1.0")

![](../../../../assets/images/IMG_5248.jpg "Photoduino Solenoid Valve Interface 1.0")

![](../../../../assets/images/IMG_5249.jpg "Photoduino Solenoid Valve Interface 1.0")

![](../../../../assets/images/IMG_5491.jpg "Photoduino Solenoid Valve Interface 1.0")
