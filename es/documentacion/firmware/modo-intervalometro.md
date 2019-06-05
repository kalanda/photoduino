---
layout: default
lang: es
title: Modo Intervalómetro
---

![](../../../../assets/images/es-lcd-interval-mode-menu.jpg "Modo Intervalómetro")

Este modo de ejecución es utilizado para tomar fotografías en intervalos configurables. Puedes elegir el tiempo de intervalo en segundos, minutos, horas y días, y otros parámetros que definen el funcionamiento.

## Opciones

Cuando entras en esta opción del menú principal, encontrarás 3 opciones.

-   **Configuración:** Define los parámetros de este modo de ejecución que intervienen en el “Ciclo de vida de ejecución” mostrado más abajo.
-   **Run:** Al entrar en esta opción, comenzará la ejecución de este modo como se describe más abajo en el “Ciclo de vida de ejecución”. Para cancelar la ejecución, mantén pulsado cualquiera de los dos botones hasta que aparezca en la pantalla “Cancelando…”.
-   **Reset config:** Esta opción volverá todos los parámetros de este modo al sus valores por defecto.

## Parámetros de configuración

<table>
<tbody>
<tr>
<th style="width: 100px;"><strong>Parámetro</strong></th>
<th style="width: 100px;"><strong>Valores</strong></th>
<th><strong>Función</strong></th>
</tr>
<tr>
<td><em>Tiempo enfoque</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>Tiempo en milisegundos usado para el enfoque automático de la cámara. Solamente es necesario si la cámara está en modo AF. Si la cámara está en modo de enfoque manual, este valor debe ser cero.</td>
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
<td><em>Pretiempo Flash2</em></td>
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
<td><em>Unid. Intervalo</em></td>
<td>
<ul>
<li>ms</li>
<li>segundos</li>
<li>minutos</li>
<li>horas</li>
<li>dias</li>
</ul>
</td>
<td>Define las unidades de medida para el valor del intervalo.</td>
</tr>
<tr>
<td><em>Valor Intervalo</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>Define el valor del intervalo para la unidad de medida anteriormente configurada.</td>
</tr>
<tr>
<td><em>Ciclos</em></td>
<td>
<ul>
<li>0-59999</li>
</ul>
</td>
<td>Número de veces que se debe repetir el &#8220;Ciclo de vida de ejecución&#8221;. Si el valor es cero equivale a infinitas repeticiones.</td>
</tr>
</tbody>
</table>

## Ciclo de vida de ejecución

![](../../../../assets/images/es-intervalometer-lifecycle.jpg "Ciclo de vida de ejecución")

## Notas importantes

-   El tiempo total de exposición es la suma de todos los tiempos de espera entre la apertura del obturador (justo después de esperar el retardo del obturador) y el cierre del obturador (justo antes de desactivar el disparador) siempre que la cámara esté configurada en modo BULB.

-   Si la cámara no está configurada en modo BULB, el tiempo de exposición total será entonces el indicado por la velocidad de obturación seleccionada en la cámara.

-   Si la cámara está configurada en enfoque manual, el tiempo de enfoque se debe configurar a valor “cero” para no insertar tiempos innecesarios.

-   Si la cámara está configurada en enfoque automático el tiempo necesario para enfocar dependerá de la escena, dandose la posibilidad de que no se dispare el obturador por falta de enfoque.

-   Si el parámetro “Ciclos” tiene valor “cero” es equivalente a “infinito”, por lo que el proceso se repetirá continuamente hasta que se cancele manteniendo pulsado alguno de los dos botones.
