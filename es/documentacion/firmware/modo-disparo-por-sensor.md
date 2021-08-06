---
layout: default
lang: es
title: Modo disparo por sensor
---

![](../../../../assets/images/es-lcd-sensor-trigger-mode-menu.jpg "Disparo por sensor")

Este modo de ejecución es usado para tomar fotografías basadas en la lectura de los sensores. Principalmente es útil para “Fotografía de Alta Velocidad” y para “Fotografía de naturaleza”.

## Opciones

Cuando entres en esta opción del menú principal,  encontrarás las siguiente sub-opciones.

-   **Config Disparo:** Define los parámetros de este modo usados en el “Ciclo de vida de ejecución”
-   **Config Gotas:** Solamente si el “Tipo de dispositivo” en la “[Configuración del sistema](../configuracion-de-sistema/ "Configuración de sistema")” es “Electroválvula”.
-   **Ejecutar:** Ejecuta el modo de acuerdo al “Ciclo de vida de ejecución”. Para cancelar la ejecución, mantén presionado uno de los dos botones hasta que en la pantalla aparezca “Cancelando…”
-   **Borrar config:** Esta opción devolverá todos los parámetros de configuración del modo a sus valores por defecto.

## Config Disparo

<table>
<thead>
<tr>
<th style="width: 100px;"><strong>Parámetro</strong></th>
<th style="width: 150px;"><strong>Valores</strong></th>
<th><strong>Función</strong></th>
</tr>
</thead>
<tbody>
<tr>
<td><em>Sensor</em></td>
<td>
<ul>
<li>Barrera</li>
<li>Audio</li>
<li>Luz</li>
<li>Impacto</li>
</ul>
</td>
<td>Define el tipo de sensor que será usado por el modo de ejecución.</td>
</tr>
<tr>
<td><em>Limite sensor</em></td>
<td>
<ul>
<li>0-15 en modo visual</li>
<li>0-999 en modo numérico</li>
</ul>
</td>
<td>Define el limite del sensor. El modo de ajuste viene definido por el parámetro &#8220;Ajuste de sensores&#8221; de la &#8220;<a title="Configuración de sistema" href="../configuracion-de-sistema/">Configuración de sistema</a>&#8220;</td>
</tr>
<tr>
<td><em>Modo disparo</em></td>
<td>
<ul>
<li>Normal</li>
<li>Bulb previo</li>
<li>Levantar espejo</li>
</ul>
</td>
<td>Define el modo de disparo usado más adelante por el &#8220;Ciclo de vida de ejecución&#8221;.</td>
</tr>
<tr>
<td><em>Tiempo enfoque</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>Tiempo en milisegundos usado para el autoenfoque de la cámara. Solamente es necesario si la cámara está en modo AF. Si la cámara está en enfoque manual, este valor debe ser 0.</td>
</tr>
<tr>
<td><em>Pretiempo Flash1</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>Tiempo en milisegundos a esperar antes de disparar el FLASH1.</td>
</tr>
<tr>
<td><em><em>Pretiempo Flash2</em></em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>Tiempo en milisegundos a esperar antes de disparar el FLASH2.</td>
</tr>
<tr>
<td><em>Pretiempo Cerrar</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>Tiempo en milisegundos a esperar antes de cerrar el obturador.</td>
</tr>
<tr>
<td><em>Ciclos</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>Número de veces que se debe repetir el ciclo de ejecución. Cero equivale a infinitas repeticiones.</td>
</tr>
<tr>
<td><em>Pretiempo ciclos</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>Tiempo en milisegundos a esperar entre cada ciclo. Este parámetro es sobretodo usado para dejar tiempo suficiente a la cámara para procesar la imagen final.</td>
</tr>
</tbody>
</table>

## Config Gotas

**FUNCIONALIDAD EXPERIMENTAL**

El “Ciclo de vida de ejecución no muestra esta funcionalidad de “Gotas”, pero las gotas son generadas siempre antes de los bloques “Esperar al sensor”  en el diagrama.

Estos parámetros son usados solamente si una electroválvula está conectada al puerto DEVICE y  el tipo de dispositivo está configurado como “Electroválvula” en la “[Configuración del sistema](../configuracion-de-sistema/ "Configuración de sistema")“.

<table>
<thead>
<tr>
<th style="width: 100px;">Parámetro</th>
<th style="width: 100px;">Valores</th>
<th>Función</th>
</tr>
</thead>
<tbody>
<tr>
<td><em>Número de gotas</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>Número de gotas a generar</td>
</tr>
<tr>
<td><em>Duración gota</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>Tiempo en milisegundos que dura cada gota.</td>
</tr>
<tr>
<td><em>Intervalo gotas</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>Tiempo en milisegundos entre cada gota.</td>
</tr>
</tbody>
</table>

## Ciclo de vida de ejecución

El ciclo de vida de ejecución es el diagrama que explica la ejecución y como cada parámetro es usado cuando se ejecuta el modo “Disparo por sensor”.

Existen tres ciclos de ejecución. Cada uno depende del “Modo de disparo” configurado en “Config Disparo”.

1.  Modo Normal
2.  Modo Bulb previo
3.  Modo Levantar espejo

### Modo de disparo: Normal

Este modo está pensado para tomar fotografías iniciando el proceso por un sensor pero usando el modo normal de funcionamiento de la cámara para tomar la foto. Si quieres ahorrarte los retardos mecánicos de modo convencional de funcionamiento de la cámara para realizar fotos de alta velocidad, debes usar el modo “Bulb previo” o el modo “Levantar espejo” descritos más adelante.

![](../../../../assets/images/es-sensor-shotting-normal-lifecicle.jpg "Modo disparo: Normal")

### Modo de disparo: Bulb previo

En este modo, el sistema asume que tienes configurada tu cámara en modo BULB y podrás usar uno o dos flashes para realizar la foto en una habitación a oscuras. Usando este modo evitarás todos los retardos mecánicos producidos por la cámara y tomar las fotografías con mayor tiempo de respuesta y con el tiempo de exposición más corto, definido por la duración del destello del flash que estás usando.

![](../../../../assets/images/es-sensor-shotting-prebulb-lifecicle.jpg "Modo disparo: Bulb previo")

### Modo de disparo: Levantar espejo

Tu cámara debe tener una opción interna para levantar el espejo antes de disparar el obturador, evitando retardos mecánicos. Usa este modo en combinación con la opción en tu cámara para que Photoduino levante automáticamente el espejo antes de esperar al sensor y realiza las fotos tan rápido como es posible y evita las vibraciones en tu cámara cuando la foto es tomada.

![](../../../../assets/images/es-sensor-shotting-mirrorlockup-lifecicle.jpg "Modo disparo: Levantar espejo")

## Notas importantes

-   El tiempo total de exposición es la suma de todos los tiempos de espera entre la apertura del obturador (justo después de esperar el retardo del obturador) y el cierre del obturador (justo antes de desactivar el disparador) siempre que la cámara esté configurada en modo BULB.

-   Si la cámara no está configurada en modo BULB, el tiempo de exposición total será entonces el indicado por la velocidad de obturación seleccionada en la cámara.

-   Si la cámara está configurada en enfoque manual, el tiempo de enfoque se debe configurar a valor “cero” para no insertar tiempos innecesarios.

-   Si la cámara está configurada en enfoque automático el tiempo necesario para enfocar dependerá de la escena, dandose la posibilidad de que no se dispare el obturador por falta de enfoque.

-   Si el parámetro “Ciclos” tiene valor “cero” es equivalente a “infinito”, por lo que el proceso se repetirá continuamente hasta que se cancele manteniendo pulsado alguno de los dos botones.
