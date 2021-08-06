---
layout: default
lang: es
title: Navegación por los menus
---
Photoduino dispone de un LCD y de dos botones denominados como BOTON-A y BOTON-B para toda la interacción con el usuario. Como el LCD es de solamente 16 caracteres de ancho y dos lineas de alto, la primera linea nos va a indicar siempre en que sección del árbol de navegación estamos y en la segunda linea mostrará la opción actual en la que estamos y/o los valores que estamos modificando.

## Regla básica de navegación

![](../../../../assets/images/lcd-example.jpg "lcd-example")

La **regla básica** de funcionamiento de los dos botones para navegar es la siguiente:

-   Pulsar BOTON-A es equivalente a subir o incrementar
-   Mantener pulsado BOTON-A es siempre la forma de salir de la opción actual
-   Pulsar BOTON-B es equivalente a bajar o decrementar
-   Mantener pulsado BOTON-B entramos en una opción.

El funcionamiento de los botones en cada uno de los tipos de valores es similar a la regla básica, pero de detallan a continuación.

## Cambiando un valor lógico

![](../../../../assets/images/lcd-boolean-value.jpg "lcd-boolean-value")

Los valores lógicos son valores que pueden ser SI o NO. Cuando estemos sobre una opción de este tipo, podemos cambiar su valor así:

-   Mantener pulsado BOTON-B para cambiarlo (Si el valor es SI pasará a NO y viceversa)

## Cambiando un valor numérico

![](../../../../assets/images/lcd-numeric-value.jpg "lcd-numeric-value")

Los valores numéricos pueden ser valores de entre 0 y 59999, por lo que en la pantalla veremos un cursor parpadeando sobre la cifra que estamos actuando. Para modificar su valor lo haremos así:

-   Si pulsamos el BOTON-A incrementa en 1 el valor de la posición del cursor
-   Si pulsamos el BOTON-B decrementa en 1 el valor de la posición del cursor
-   Si mantenemos pulsado BOTON-A salimos al menú anterior guardando el valor
-   Si mantenemos pulsado BOTON-B avanzamos una posición con el cursor

## Cambiando valores de lista

![](../../../../assets/images/lcd-list-value.jpg "lcd-list-value")

Los valores de lista son determinado por una lista de opciones predeterminada. Cuando estemos cambiando un valor de tipo lista lo haremos así:

-   Si pulsamos el BOTON-A sube una posición en la lista
-   Si pulsamos el BOTON-B baja una posición en la lista
-   Si mantenemos pulsado BOTON-A salimos al menú anterior guardando el valor

## Cambiando valores de límite en modo visual

![](../../../../assets/images/lcd-limit-visual-value.jpg "lcd-limit-visual-value")

Los valores de límite son ajustados para el sensor que estamos calibrando y van de 0 a 15. Si tenemos conectado el sensor que estamos calibrando, en la segunda linea del LCD veremos una barra que aumenta o disminuye con la lectura en tiempo real del sensor y sobre ella una flecha hacia arriba o hacia abajo que nos indica la posición de límite seleccionada. Para cambiar el valor de umbral lo haremos así:

-   Si pulsamos el BOTON-A mueve hacia la derecha la posición de la flecha de límite
-   Si pulsamos el BOTON-B mueve hacia la izquierda la posición de la flecha de límite
-   Si mantenemos pulsado BOTON-A salimos al menú anterior guardando el valor

Si tenemos activado el uso del altavoz, oiremos un pitido cuando la lectura del sensor esté sobrepasando el valor de límite, de forma que podamos establecer el valor de forma más precisa. La dirección de la flecha indica como se va a manejar el límite del sensor y que viene determinado por el modo de ejecución que estemos configurando:

-   Si la flecha es hacia arriba (↑), el sensor estará sobrepasando su límite cuando el valor de la lectura del sensor sea mayor que el del límite.
-   Si la flecha es hacia abajo (↓), el sensor estará sobrepasando su límite cuando el valor de la lectura del sensor sea menor que el del límite.

## Cambiando valores de límite en modo numérico

![](../../../../assets/images/lcd-limit-numeric-value.jpg "lcd-limit-numeric-value")

Los valores de límite son ajustados para el sensor que estamos calibrando y van de 0 a 999. Si tenemos conectado el sensor que estamos calibrando, en la primera linea del LCD veremos el valor con la lectura en tiempo real del sensor y justo debajo vemos el valor numérico del limite establecido y a su derecha una flecha hacia arriba o hacia abajo que nos indica como se supera el limite:

-   Si la flecha es hacia arriba (↑), el sensor estará sobrepasando su límite cuando el valor de la lectura del sensor sea mayor que el valor del límite.
-   Si la flecha es hacia abajo (↓), el sensor estará sobrepasando su límite cuando el valor de la lectura del sensor sea menor que el valor del límite.

Si tenemos activado el uso del altavoz, oiremos un pitido cuando la lectura del sensor esté sobrepasando el valor de límite, de forma que podamos establecer el valor de forma más precisa.

Para modificar el valor del límite lo haremos como si estuviésemos modificado cualquier valor numérico:

-   Si pulsamos el BOTON-A incrementa en 1 el valor de la posición del cursor
-   Si pulsamos el BOTON-B decrementa en 1 el valor de la posición del cursor
-   Si mantenemos pulsado BOTON-A salimos al menú anterior guardando el valor
-   Si mantenemos pulsado BOTON-B avanzamos una posición con el cursor
-   Si mantenemos pulsados los dos botones A y B, el valor del limite se igualará a la lectura del sensor
