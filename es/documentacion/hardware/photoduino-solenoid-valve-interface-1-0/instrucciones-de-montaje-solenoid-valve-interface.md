---
layout: default
lang: es
title: Instrucciones de montaje Solenoid Valve Interface
---
El montaje de este circuito es muy sencillo. Para realizar el montaje necesitarás además de todos los componentes, un soldador, estaño, un alicate de corte y un par de destornilladores (punta plana y estrella).

**ES MUY IMPORTANTE** saber soldar correctamente.[Descárgate este comic para aprender a soldar facilmente “Soldar es fácil”](https://kalanda.github.io/photoduino/assets/pdf/FullSolderComic_ES.pdf)

## La PCB

![](../../../../../assets/images/IMG_4791.jpg "IMG_4791")

## Componentes

Lo primero que hay que soldar es la resistencia de 10k (bandas marron,negro y naranja). No tiene polaridad y solamente hay una. Aparece en la PCB como R2.

![](../../../../../assets/images/IMG_4792.jpg "IMG_4792")

Lo siguiente es soldar el diodo 1N4004. Tiene polaridad indicada por una banda de color gris en uno de los lados. Fíjate bien en su posición en la foto para soldarla correctamente.

![](../../../../../assets/images/IMG_4793.jpg "IMG_4793")

Ahora tienes que soldar el transistor MOSFET IRL520. Tiene polaridad, por lo que fíjate en la imagen para soldarlo correctamente.

![](../../../../../assets/images/IMG_4803.jpg "IMG_4803")

Ahora debes soldar los dos terminales de tornillo. El orificio para insertar los cables debe quedar hacia afuera como en la imagen.

![](../../../../../assets/images/IMG_4804.jpg "IMG_4804")

Por último para finalizar el circuito hay que soldar el conector RCA.

![](../../../../../assets/images/IMG_48061.jpg "IMG_4806")

## Cableado de la electrovávula

Para conectar la electroválvula, primero debes soldarla a un cable. Aunque el cable es de dos colores, la electroválvula NO tiene polaridad, por lo que no es importante la posición de cada color.

![](../../../../../assets/images/IMG_4808.jpg "IMG_4808")

![](../../../../../assets/images/IMG_4809.jpg "IMG_4809")

Con un par de trozos de tubo termorretráctil aislaremos las conexiones después de soldar.

![](../../../../../assets/images/IMG_4812.jpg "IMG_4812")

![](../../../../../assets/images/IMG_4813.jpg "IMG_4813")

![](../../../../../assets/images/IMG_4816.jpg "IMG_4816")

![](../../../../../assets/images/IMG_4818.jpg "IMG_4818")

![](../../../../../assets/images/IMG_4822.jpg "IMG_4822")

![](../../../../../assets/images/IMG_4823.jpg "IMG_4823")

![](../../../../../assets/images/IMG_4824.jpg "IMG_4824")

## Conexiones de electroválvula y alimentación.

Debes tener mucho cuidado con respetar la polaridad de la alimentación. En la imagen puedes ver que el positivo de la alimentación (rojo) va conectado a +12v power, y el negativo a GND power. Si en lugar de las baterias usas una fuente de alimentación, utiliza un multimetro para averiguar la polaridad. ES MUY IMPORTANTE.

![](../../../../../assets/images/IMG_48301.jpg "IMG_4830")

![](../../../../../assets/images/IMG_48281.jpg "IMG_4828")

## Conexión a Photoduino

La conexión a se realiza mediante un cable RCA al puerto DEVICE de Photoduino.

![](../../../../../assets/images/IMG_52351.jpg "IMG_5235")

## Ejemplo de montaje

En la foto anterior puedes ver como usar la jeringa como deposito de liquido usando el microtubo de plastico para conectarla con la entrada de la electroválvula. Aunque no se incluyen en el kit el resto de materiales que puedes ver en las fotos, las pongo a modo de ejemplo de como puedes montar el sistema.

![](../../../../../assets/images/IMG_52411.jpg "IMG_5241")

![](../../../../../assets/images/IMG_52451.jpg "IMG_5245")
