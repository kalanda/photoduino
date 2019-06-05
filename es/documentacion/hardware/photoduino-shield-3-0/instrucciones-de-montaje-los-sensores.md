---
layout: default
lang: es
title: "Instrucciones de montaje: Los sensores"
---
Seguramente está sea la parte mas complicada del montaje de Photoduino. No por el número de componentes, sino por que hay que tener algo más de destreza a la hora de soldar y que es muy importante respetar la polaridad de los sensores. Para realizar esta parte del montaje necesitarás además de los componentes necesarios, unas tijeras, un alicate de corte, un pelacables, el soldador y estaño, un mechero de gas y un “tercer brazo” articulado, aunque puedes hacerlo sin el pero te será mucho más complicado.

## Cable para los sensores

Si estás usando el kit a la venta, tendrás un cable como el de la siguiente foto de unos 5 metros de longitud. El cable tiene 3 conectores RCA macho por cada extremo. Los sensores que vas a montar en este tutorial son los básicos de sonido, luz, barrera infrarroja y de impacto. En el caso de la barrera infrarroja, aunque el emisor siempre será un led IR, vas a poder usar dos receptores diferentes. Uno basado en un fotodiodo y otro basado en un fototransistor. El primero es más preciso en cuanto al ancho del haz de luz pero su tamaño de barrera es menor (unos 10-20cm) muy orientado al uso con gotas de agua u objetos pequeños. El otro, basado en fototransistor, tiene la posibilidad de crear barreras más grandes (unos 100cm), pero obviamente su precisión de haz de luz es menor debido a que la luz se expande en la distancia. Si necesitas una barrera mayor pero muy precisa, debes usar un laser como emisor (no incluido en el kit) y el sensor de luz visible (LDR) como receptor.

Dicho esto, necesitaremos 6 cables en total. Uno para el microfono, otro para el sensor de impacto, otro para el diodo IR emisor, otro para el sensor de luz visible (LDR) y otros dos para el receptor IR basado en fotodiodo y el basado en fototransistor. Para consiguir esos 6 cables debes cortar el cable de 5 metros para obtener dos. Si lo cortas por la mitad tendrás 2,5m de cable para cada sensor. Si consideras demasiado largos estos cables para tus necesidades debes cortarlos a la longitud que prefieras.

![](../../../../../assets/images/shield3-sensors-00.jpg)

Una vez cortado el cable de 5 metros, tendrás dos cables con 3 conectores cada uno como en la siguiente foto.  
![](../../../../../assets/images/shield3-sensors-01.jpg)

Ahora ya puedes separar cada cable de los que van unidos para obtener 6 cables con su conector RCA cada uno.

![](../../../../../assets/images/shield3-sensors-02.jpg)![](../../../../../assets/images/shield3-sensors-03.jpg)

## Cómo pelar y preparar cada cable

Lo siguiente que vas a hacer, vas a tener que repetirlo para cada sensor prácticamente de la misma forma. Básicamente se trata de pelar y preparar cada cable con trozos de plástico termoretractil (aunque en las fotos sean de color azul o amarillo, seguramente tu los tengas en negro) con los cuales sellaras y aislarás las conexiones que hagas.

![](../../../../../assets/images/shield3-sensors-04.jpg)

Ten en cuenta que de los 6 cables que tienes ahora, los dos que tienen conector amarillo son un poco más gruesos que los que tienen conectores rojo o blanco, así que para los amarillos necesitarás usar el termoretráctil de más diametro incluido en el kit, y con los otros (rojo y blanco) el mediano. Lo más fácil es que hagas pasar el cable por el termoretractil antes de pelarlo y veas si entra con suavidad o no. No debe entrar forzado pero tampoco debe ser desproporcionado y sobrarle demasiado.

![](../../../../../assets/images/shield3-sensors-05.jpg)

Antes de pelar el cable, pon un trozo de unos 4 o 5 cm. Más tarde este será el que cierre y aisle toda la conexión con el sensor.

![](../../../../../assets/images/shield3-sensors-06.jpg)

Ayudándote de un pelacables, pela un trozo de unos 3 cm con cuidado de no romper los hilos de cobre que van dentro.

![](../../../../../assets/images/shield3-sensors-07.jpg)

Con la ayuda de los dedos, haz que todos los hilos de cobre que ves en la siguiente foto queden unidos.

![](../../../../../assets/images/shield3-sensors-08.jpg)![](../../../../../assets/images/shield3-sensors-09.jpg)

Ahora ya puedes pelar el cable centrál con el pelacables. Con unos 5mm será suficiente.

![](../../../../../assets/images/shield3-sensors-10.jpg)

Anteriormente hemos dejado en el cable un trozo de termorretráctil que luego servirá para cubrirlo todo. Ahora necesitas poner otro trozo de termoretráctil de 1’5cm de longitud del tipo de menor diametro en el exterior (cobre a la vista en la siguiente foto) para posteriormente evitar que ese cable donde soldaremos con el sensor haga contacto con el otro cable centrar (en la siguiente foto con recubrimiento amarillo).

![](../../../../../assets/images/shield3-sensors-11.jpg)

## Sensor de sonido

Para el sensor de sonido vamos a usar el micrófono electret. Este microfono tiene polaridad que es muy importante respetar. En la siguiente foto puedes ver como debes conectarlo correctamente. En este caso, el contacto nombrado en la foto como SIGNAL debes soldarlo al cable central (en amarillo) y el denominado como GND al otro (cobre a la vista). Asegurate de el trozo de termorretráctil esté lo más separado posible de la zona donde vas a soldar, pues este material se contrae con el calor.

![](../../../../../assets/images/shield3-sensors-12.jpg)

Puedes ayudarte con algunos alicates para conseguir posicionar lo que vas a soldar y así poder usar las dos manos para coger el soldador y el estaño. Ten en cuenta que es muy importante que cuando una soldadura se está enfriando, no se muevan sus contactos o puede quedar mal unida.

![](../../../../../assets/images/shield3-sensors-13.jpg)

Una vez soldado cada contacto correctamente, debes desplazar el termorretráctil como en la foto siguiente hasta el punto más cercano a la soldadura y con la llama de un mechero calentar el termorretráctil sin dejar de mover el mechero. Verás como enseguida se contrae el material ajustándose al cable. Dejalo enfriar un poco antes de tocarlo.

![](../../../../../assets/images/shield3-sensors-14.jpg)![](../../../../../assets/images/shield3-sensors-15.jpg)

Haz lo mismo con el trozo grande de termorretráctil desplazandolo hasta cubrir las conexiones y caliéntalo con el mechero para que se ajuste.

![](../../../../../assets/images/shield3-sensors-16.jpg)  
![](../../../../../assets/images/shield3-sensors-17.jpg)

El resultado debe ser como el que se ve en la siguiente foto.

![](../../../../../assets/images/shield3-sensors-18.jpg)

Yá tienes preparado tu sensor de sonido.

![](../../../../../assets/images/shield3-sensors-19.jpg)

## El sensor de impacto

De igual forma que has hecho con anteriormente, tienes que preparar el cable pelándolo y poniendo los trozos de termorretráctil necesarios para aislar las conexiones después. Fijate que el termorretractil más fino esta en el cable central y no en el de cobre a la vista.

![](../../../../../assets/images/shield3-sensors-20.jpg)

Para este sensor de impacto se utiliza el altavoz piezoeléctrico plano que ves en la siguiente imagen que genera pequeños voltajes cuando es presionado o golpeado. Su polaridad es muy clara pues los cables son rojo y negro. El rojo debe ir soldado al cable central y el negro al cable exterior (cobre a la vista).

![](../../../../../assets/images/shield3-sensors-21.jpg)  
![](../../../../../assets/images/shield3-sensors-22.jpg)  
![](../../../../../assets/images/shield3-sensors-23.jpg)  
![](../../../../../assets/images/shield3-sensors-24.jpg)  
![](../../../../../assets/images/shield3-sensors-25.jpg)  
![](../../../../../assets/images/shield3-sensors-26.jpg)  
![](../../../../../assets/images/shield3-sensors-27.jpg)

Ya tienes tu sensor de impacto finalizado.

![](../../../../../assets/images/shield3-sensors-28.jpg)

## Led infrarrojo

Para componer la barrera infrarroja necesitamos un emisor de luz infrarroja que será el led IR que vamos a montar ahora.

Cómo ya has hecho en los anteriores pasos, debes preparar el cable con sus termorretráctiles. En este caso usar un “tercer brazo articulado” como el que ves en la siguiente imagen te ayudará a posicionarlo correctamente cuando vayas a soldar.

![](../../../../../assets/images/shield3-sensors-29.jpg)

Los diodos LED tienen polaridad y esta viene indicada por la forma que tiene la base del LED. Uno de los lados de la base es plana, indicada como FLAT(-) en la siguiente imagen que corresponde al cátodo y el otro lado es redondeado, indicado como ROUNDED(+) en la siguiente imagen que corresponde al ánodo. Debes soldar el cable central al lado ROUNDED(+) y el cable exterior al lado FLAT(-).

![](../../../../../assets/images/shield3-sensors-30.jpg)![](../../../../../assets/images/shield3-sensors-31.jpg)![](../../../../../assets/images/shield3-sensors-32.jpg)![](../../../../../assets/images/shield3-sensors-33.jpg)![](../../../../../assets/images/shield3-sensors-34.jpg)

Ya tienes preparado el emisor IR.

![](../../../../../assets/images/shield3-sensors-35.jpg)

## Sensor de luz visible

El sensor de luz visible te servirá para crear barreras láser o para disparar la cámara o los flashes cuando la luz supere un umbral. Para este sensor usaremos la LDR (Light Dependant Resistor). La LDR en una resistencia que varia su valor en función de la luz, por lo que no tiene polaridad. Cómo ya has hecho en los anteriores pasos, debes preparar el cable con sus termorretráctiles.

![](../../../../../assets/images/shield3-sensors-36.jpg)![](../../../../../assets/images/shield3-sensors-37.jpg)![](../../../../../assets/images/shield3-sensors-38.jpg)![](../../../../../assets/images/shield3-sensors-39.jpg)![](../../../../../assets/images/shield3-sensors-40.jpg)

Ya tienes montado tu sensor de luz visible.

![](../../../../../assets/images/shield3-sensors-41.jpg)

## Sensor infrarrojo por Fototransistor

Como ya hemos comentado antes, podrás elegir entre dos tipos de receptor IR según las necesidades. Primero vamos a montar el que está basado en un fototransistor. El fototransistor y el fotodiodo son muy parecidos, pero el fototransistor es algo más pequeño. El color de la lente del fototransistor puede ser distinto (normalmente transparente) al que muestra la imagen. El fototransistor también tiene polaridad indicada por la forma de su base plana o redondeada. En este caso la conexión es al contrario que con el LED IR anteriormente montado. Debes soldar el lado FLAT(-) al cable central y el lado ROUNDED(+) al cable exterior como en la siguiente imagen. Cómo ya has hecho en los anteriores pasos, debes preparar el cable con sus termorretráctiles.

![](../../../../../assets/images/shield3-sensors-42.jpg)![](../../../../../assets/images/shield3-sensors-43.jpg)![](../../../../../assets/images/shield3-sensors-44.jpg)

Ya tienes tu primer sensor infrarrojo.

![](../../../../../assets/images/shield3-sensors-45.jpg)

## Sensor infrarrojo por fotodiodo

El montaje de este sensor es muy parecido al anterior. El fotodiodo es un poco más grande que el fototransistor y tiene la misma polaridad. Puedes ver la polaridad en la siguiente imagen. El lado plano (FLAT) al cable central y el lado redondeado (ROUNDED) al cable exterior. Como siempre, prepara antes de soldar los tubos termorretráctiles en sus posiciones.

![](../../../../../assets/images/shield3-sensors-46.jpg)![](../../../../../assets/images/shield3-sensors-47.jpg)

Y ya tienes tu segundo sensor infrarrojo.

![](../../../../../assets/images/shield3-sensors-48.jpg)

Enhorabuena, has completado todos los sensores :)

![](../../../../../assets/images/shield3-sensors-49.jpg)

## [**\>> Ve al siguiente paso para montar la caja**](../instrucciones-de-montaje-la-caja/ "Instrucciones de montaje: La caja")
