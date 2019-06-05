---
layout: default
lang: es
title: Photoduino Shield 3.0
---
**Caracteristicas de Photoduino Shield 3.0:**

-   Totalmente aislada electricamente de la camara usando optoacopladores (no ha habido ningún problema con los tiristores, pero tu tranquilidad es siempre buena)
-   Botón de reset en la shield para su fácil acceso.
-   Incluye solución al problema con la Arduino UNO R2
-   Arregla un fallo detectado con algunos fashes Canon como el EX580 y EX430 (no testeado completamente)
-   Es la versión mas sencilla de montar
-   Totalmente compatible con la versión actual y futuras del firmware
-   Totalmente compatible con los sensores de las versiones anteriores si ya tienes alguno.
-   Caja propia de plástico acrílico
-   Alimentación propia por batería de 9V

## Algunas fotos:

[![](../../../../assets/images/shield3-complete-600x400.jpg "Photoduino Shield 3.0 Complete")](../../../../assets/images/shield3-complete.jpg)

[![](../../../../assets/images/shield3-pcbmounted-600x400.jpg "Photoduino Shield 3.0 Mounted PCB")](../../../../assets/images/shield3-pcbmounted.jpg)

[![](../../../../assets/images/shield3-incase-600x400.jpg "Photoduino Shield 3.0 Case")](../../../../assets/images/shield3-incase.jpg)

## Ficheros Eaglecad

Puedes descargar los archivos originales en [formato Eaglecad](http://sourceforge.net/projects/photoduino/files/hardware/photoduino.shield.3.0.zip/download)  y también [el diseño de la caja](http://sourceforge.net/projects/photoduino/files/hardware/photoduino.case.1.0.zip/download)

[![](../../../../assets/images/shield3-schema-600x403.jpg "Photoduino Shield 3.0 Eaglecad Schema")](../../../../assets/images/shield3-schema.jpg)

[![](../../../../assets/images/shield3-board-600x386.jpg "Photoduino Shield 3.0 Eaglecad Board")](../../../../assets/images/shield3-board.jpg)

## Instrucciones de montaje

-   [Instrucciones de montaje: La shield](instrucciones-de-montaje-la-shield/)
-   [Instrucciones de montaje: Los sensores](instrucciones-de-montaje-los-sensores/)
-   [Instrucciones de montaje: La caja](instrucciones-de-montaje-la-caja/)

## Lista de componentes

<table border="0" frame="VOID" rules="NONE" cellspacing="0">
<thead>
<tr>
<th align="CENTER">Cantidad</th>
<th align="LEFT">Componente</th>
<th align="LEFT">Sugerencia</th>
</tr>
</thead>
<tbody>
<tr>
<td style="text-align: left;" colspan="3" align="CENTER" height="19"><strong>Placa principal</strong></td>
</tr>
<tr>
<td align="CENTER" height="19">1</td>
<td align="LEFT">PCB Photoduino Shield 3.0</td>
<td align="LEFT"><a href="http://sourceforge.net/projects/photoduino/files/hardware/photoduino.shield.3.0.zip/download" target="_blank">fichero eaglecad</a> <br>
 <a href="https://oshpark.com/profiles/photoduino">comprar en oshpark.com</a></td>
</tr>
<tr>
<td align="CENTER" height="19">1</td>
<td align="LEFT">Display LCD 16&#215;2</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/Newhaven-Display/NHD-0216K1Z-FL-YBW/?qs=/ha2pyFadui/M2mC7zuwXvLqEHfh5mAf97IIWGu45UjikkozZ%252b8n1s14kDCf2wAM" target="_blank">mouser</a></td>
</tr>
<tr>
<td align="CENTER" height="19">5</td>
<td align="LEFT">Conectores RCA para PCB</td>
<td align="LEFT"><a href="https://www.sparkfun.com/products/8631" target="_blank">sparkfun</a></td>
</tr>
<tr>
<td align="CENTER" height="19">3</td>
<td align="LEFT">Conectores JACK 3,5mm para PCB</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/Kycon/STX-3120-3B/?qs=sGAEpiMZZMv0W4pxf2HiV53lyqBtMwLM0DRdmjM0OdM=" target="_blank"><span style="text-decoration: underline;">mouser</span></a></td>
</tr>
<tr>
<td align="CENTER" height="19">3</td>
<td align="LEFT">Pulsadores PCB</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/E-Switch/TL1105SPF160Q/?qs=sGAEpiMZZMsqIr59i2oRctT61P85ivpKlcF429FVUXY=" target="_blank">mouser</a></td>
</tr>
<tr>
<td align="CENTER" height="19">1</td>
<td align="LEFT">Diodo 1N4004</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/Fairchild-Semiconductor/1N4004/?qs=sGAEpiMZZMtbRapU8LlZD6Aoap19JQAxY2gML8gEYQU=" target="_blank">mouser</a></td>
</tr>
<tr>
<td align="CENTER" height="19">1</td>
<td align="LEFT">Diodo 1N4148</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/Vishay-Semiconductors/1N4148TR/?qs=sGAEpiMZZMtoHjESLttvklTOdRQGz66dWL%252bWDOcJ/uo=" target="_blank">mouser</a></td>
</tr>
<tr>
<td align="CENTER" height="19">2</td>
<td align="LEFT">Tiristor BT169G</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/NXP-Semiconductors/BT169G126/?qs=sGAEpiMZZMuAO0%252bGuNbnQjRT2dbB0zbkYRXu9ksGhrY=" target="_blank">mouser</a></td>
</tr>
<tr>
<td align="CENTER" height="19">2</td>
<td align="LEFT">Optoacoplador PC817</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/Sharp-Microelectronics/PC817X9NSZ0F/?qs=sGAEpiMZZMteimceiIVCBwM%252bPK3Qn/7SA9mlwHmvLr4=" target="_blank">mouser</a></td>
</tr>
<tr>
<td align="CENTER" height="19">1</td>
<td align="LEFT">Amplificador operacional LM386</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/Texas-Instruments/LM386N-1-NOPB/?qs=/ha2pyFaduh03ezE8gSAL4W0di0g9Q8/2WN2tpaY3dK0qU5NN1zswQ==" target="_blank">mouser</a></td>
</tr>
<tr>
<td align="CENTER" height="19">1</td>
<td align="LEFT">Potenciometro trimmer 10K</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/Bourns/3362U-1-103LF/?qs=/ha2pyFadujW%252bXfb/PJq6mwYqbSiBcWRQmwpdBM099jbve2DsxT4aA==" target="_blank">mouser</a></td>
</tr>
<tr>
<td align="CENTER" height="19">3</td>
<td align="LEFT">Condensador 10uF Electrolitico</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/Nichicon/USV1H100MFD1TP/?qs=/ha2pyFadujLeaEnwicwNE%252bQjdtbkErT5EIE5O%252bgWXb%252bFAEjfgznFA==" target="_blank">mouser</a></td>
</tr>
<tr>
<td align="CENTER" height="19">1</td>
<td align="LEFT">Condensador 10nF cerámico</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/TDK/FK28C0G1H103J/?qs=/ha2pyFadugZGcehGmrf9lVe4O88th4psBhj5YtrRTnEoYBiv/aN%252bQ==" target="_blank">mouser</a></td>
</tr>
<tr>
<td align="CENTER" height="19">8</td>
<td align="LEFT">Resistencia 10 Kohms</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/KOA-Speer/CF1-4CT52R103J/?qs=/ha2pyFaduhcR7YWghnBNohs8vFPbHXcGsL5ejOIEA8FpelIXoecIg==" target="_blank">mouser</a></td>
</tr>
<tr>
<td align="CENTER" height="19">2</td>
<td align="LEFT">Resistencia 91 ohms</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/KOA-Speer/CF1-4CT52R910J/?qs=/ha2pyFaduhcR7YWghnBNuo0mXvkXt37Ayewl/5ipvWpwq9Y7shN5Q==" target="_blank">mouser</a></td>
</tr>
<tr>
<td align="CENTER" height="19">1</td>
<td align="LEFT">Resistencia 1 Mohms</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/KOA-Speer/CF1-4CT52R105J/?qs=/ha2pyFaduhcR7YWghnBNohs8vFPbHXcjiOznyFgWmwzA1EWcemcyw==" target="_blank">mouser</a></td>
</tr>
<tr>
<td align="CENTER" height="19">2</td>
<td align="LEFT">Resistencia 360 ohms</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/KOA-Speer/CF1-4CT52R361J/?qs=/ha2pyFaduhcR7YWghnBNhQaBJ4OB1eAK1R6V9MXIke1mGeBmVPbFQ==" target="_blank">mouser</a></td>
</tr>
<tr>
<td align="CENTER" height="19">2</td>
<td align="LEFT">Macho 2 pines</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/FCI/68001-102H/?qs=sGAEpiMZZMs%252bGHln7q6pmyrUVsykU3q/3JSd7fRuEbo=" target="_blank">mouser</a></td>
</tr>
<tr>
<td align="CENTER" height="19">2</td>
<td align="LEFT">Macho 6 pines</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/FCI/68000-206HLF/?qs=/ha2pyFaduj2kX7F/jLYs2HW5HRfwkSPElfDHhW8pDUS968GY0t3Vg==" target="_blank">mouser</a></td>
</tr>
<tr>
<td align="CENTER" height="19">2</td>
<td align="LEFT">Macho 8 pines</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/FCI/68000-208HLF/?qs=/ha2pyFaduj2kX7F/jLYs5XWdw%252bThQi1r8BH/IpQaDnJmfb9wHxj3w==" target="_blank">mouser</a></td>
</tr>
<tr>
<td align="CENTER" height="19">1</td>
<td align="LEFT">Macho 16 pines</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/FCI/68002-216HLF/?qs=/ha2pyFaduj2kX7F/jLYs4ygajQ5LxjHh%252baIBuQVvtvX3q9LUUXHnw==" target="_blank">mouser</a></td>
</tr>
<tr>
<td align="CENTER" height="19">2</td>
<td align="LEFT">Jumper 2 pines</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/Kobiconn/151-8010-E/?qs=/ha2pyFadugp3KK%252bcISazFVbukDVHh/xeJbsvZAIqB8=" target="_blank">mouser</a></td>
</tr>
<tr>
<td align="CENTER" height="19">1</td>
<td align="LEFT">Bloque terminal 2 pines</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/TE-Connectivity/1546217-2/?qs=/ha2pyFadui5vPiFZWIRtlnll7gvt4j9cS3WxuW3x4U6b7MTIqipBA==" target="_blank">mouser</a></td>
</tr>
<tr>
<td align="CENTER" height="19">1</td>
<td align="LEFT">Buzzer 12mm</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/TDK/PS1240P02CT3/?qs=/ha2pyFadug6C9WlOoUSCgkJwAgjNB16SNVdhG6hcTuEndXNRo44sA==" target="_blank">mouser</a></td>
</tr>
<tr>
<td colspan="3" align="LEFT" height="18"><strong>Sensores</strong></td>
</tr>
<tr>
<td style="text-align: center;" align="CENTER" height="19">1</td>
<td align="LEFT">Fotodiodo IR</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/Osram-Opto-Semiconductor/SFH-203-FA/?qs=/ha2pyFadugS0%252bXEsvx1CEABZTKhJbFe4NO8X%252bWDozxwzJNMvIEFQA==" target="_blank">mouser</a></td>
</tr>
<tr>
<td style="text-align: center;" align="CENTER" height="19">1</td>
<td align="LEFT">Altavoz piezoelectrico plano</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/Murata/7BB-27-4L0/?qs=/ha2pyFadugpqzbKouZTGUgS7AFYYbx3OpKWn8S%252bWaP70/8QnKHkhQ==" target="_blank">mouser</a></td>
</tr>
<tr>
<td style="text-align: center;" align="CENTER" height="19">1</td>
<td align="LEFT">Fototransistor IR</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/Everlight/EL-PT204-6B/?qs=/ha2pyFadug/Diw%252b49qvl4hrFiv/WrVjiAE2%252bL8me1XvV2Cine31Aw==" target="_blank">mouser</a></td>
</tr>
<tr>
<td style="text-align: center;" align="CENTER" height="19">1</td>
<td align="LEFT">Led emisor IR</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/OSRAM-Opto-Semiconductors/SFH-484-2/?qs=sGAEpiMZZMvAL21a/DhxMvFeLV%252bDp%252bu%252bOgZoP6Q5g5c=" target="_blank">mouser</a></td>
</tr>
<tr>
<td style="text-align: center;" align="CENTER" height="19">1</td>
<td align="LEFT">Microfono electret</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/PUI-Audio/AOM-6742L-R/?qs=sGAEpiMZZMtcsMZaWNSqu9Zb0DRRrO5QYYrEdg8XCJM=" target="_blank">mouser</a></td>
</tr>
<tr>
<td style="text-align: center;" align="CENTER" height="19">1</td>
<td align="LEFT">Resistencia LDR</td>
<td align="LEFT"><a href="http://es.farnell.com/excelitas-tech/vt90n2/ldr-series-vt900/dp/1652637" target="_blank">farnell</a></td>
</tr>
<tr>
<td style="text-align: center;" align="CENTER" height="19">1</td>
<td align="LEFT">Cable 3 RCA 5M</td>
<td align="LEFT"><a href="http://es.farnell.com/pro-signal/av02011/lead-3xphono-3xphono-5m/dp/3712503?Ntt=3712503" target="_blank">farnell</a></td>
</tr>
<tr>
<td style="text-align: center;" align="CENTER" height="19">1</td>
<td align="LEFT">Puntero Laser 5mw rojo</td>
<td align="LEFT"><a href="http://dx.com/p/red-laser-module-focusable-dot-3-5v-4-5v-16mm-5mw-5914" target="_blank">dealextreme</a></td>
</tr>
<tr>
<td style="text-align: center;" align="CENTER" height="19">1</td>
<td align="LEFT">Tubo termorretráctil 3/64&#8243;</td>
<td align="LEFT"></td>
</tr>
<tr>
<td style="text-align: center;" align="CENTER" height="19">1</td>
<td align="LEFT">Tubo termorretráctil 1/8&#8243;</td>
<td align="LEFT"></td>
</tr>
<tr>
<td style="text-align: center;" align="CENTER" height="19">1</td>
<td align="LEFT">Tubo termorretráctil 3/16&#8243;</td>
<td align="LEFT"></td>
</tr>
<tr>
<td style="text-align: left;" colspan="3" align="CENTER" height="18"><strong>Caja</strong></td>
</tr>
<tr>
<td style="text-align: center;" align="CENTER" height="19">1</td>
<td align="LEFT">Acrílico cortado con láser</td>
<td align="LEFT"><a href="http://sourceforge.net/projects/photoduino/files/hardware/photoduino.case.1.0.zip/download" target="_blank">fichero illustrator</a></td>
</tr>
<tr>
<td style="text-align: center;" align="CENTER" height="19">4</td>
<td align="LEFT">Tornillos M3x8mm</td>
<td align="LEFT"><a href="http://es.farnell.com/richco/nse-1207-m3-8/tornillo-de-fijacion-encajado-m3/dp/1261872?Ntt=1261872">farnell</a></td>
</tr>
<tr>
<td style="text-align: center;" align="CENTER" height="19">4</td>
<td align="LEFT">Espaciador M3x10mm</td>
<td align="LEFT"><a href="http://es.farnell.com/ettinger/05-13-103/separador-m3x10-ni/dp/1466826?Ntt=1466826">farnell</a></td>
</tr>
<tr>
<td style="text-align: center;" align="CENTER" height="19">4</td>
<td align="LEFT">Espaciador M3x16mm</td>
<td align="LEFT"><a href="http://es.farnell.com/ettinger/05-13-163/separador-m3x16-ni/dp/1466736?Ntt=1466736">farnell</a></td>
</tr>
<tr>
<td style="text-align: center;" align="CENTER" height="19">4</td>
<td align="LEFT">Tuercas sombrerete M3</td>
<td align="LEFT"><a href="http://es.farnell.com/tr-fastenings/m3-dnst-z100/tuerca-de-cabeza-redonda-bzp-m3/dp/1420797?Ntt=1420797">farnell</a></td>
</tr>
<tr>
<td style="text-align: center;" align="CENTER" height="19">4</td>
<td align="LEFT">Patas adhesivas</td>
<td align="LEFT"><a href="http://es.farnell.com/multicomp/pd-2164bl/bases-adherible-10-2x16-5dia-negro/dp/1800878?Ntt=1800878">farnell</a></td>
</tr>
<tr>
<td style="text-align: center;" align="CENTER" height="19">1</td>
<td align="LEFT">Trozo velcro adhesivo 5cm</td>
<td align="LEFT"><a href="http://es.farnell.com/velcro/60217/cinta-adhesiva-negro-20-mm-x-5/dp/1454582?Ntt=1454582">farnell</a></td>
</tr>
<tr>
<td style="text-align: center;" align="CENTER" height="19">1</td>
<td align="LEFT">Portapilas 9V</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/Eagle-Plastic-Devices/12BH9V-CS-GR/?qs=haXUrkBeOCfuHG/vwq4N7A==">mouser</a></td>
</tr>
<tr>
<td style="text-align: center;" align="CENTER" height="19">2</td>
<td align="LEFT">Caperuza boton blanca</td>
<td align="LEFT"><a href="http://es.mouser.com/ProductDetail/E-Switch/1RWHT/?qs=/ha2pyFadujyAUfd5pgHUcx0EYPG1%252bEJwLMkiUkh%252bRE=">mouser</a></td>
</tr>
</tbody>
</table>

