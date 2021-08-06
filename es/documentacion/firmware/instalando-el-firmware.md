---
layout: default
lang: es
title: Instalando el firmware
---
## DESCARGAS

1.  Descargar el archivo .zip con la [última versión del firmware de Photoduino](http://sourceforge.net/projects/photoduino/files/firmware/photoduino.shield.firmware.v.1.1.zip/download)
2.  Descargar la última versión del [entorno de desarrollo de Arduino](http://arduino.cc/en/Main/Software)

## PREPARANDO

1.  **Descomprimir el entorno de desarrollo de Arduino descargado.** Encontrarás dos cosas. El instalador del entorno de Arduino y los drivers FTDI para la conexión USB. Debes instalar ambos.
2.  **Descomprimir el firmware descargado.** Es muy importante que todos los archivos estén juntos en una misma carpeta llamada “Photoduino”. Si no es así, renómbrala.
3.  **Conecta la placa Arduino al ordenador por el puerto USB.**
4.  **Abre el entorno de Arduino** que instalaste.
5.  En el entorno de Arduino ve **al menú ”Tools->Board”y selecciona tu modelo de Arduino**
6.  En el entorno de Arduino ve **al menu “Tools->Serial Port” y selecciona el puerto de tu Arduino**

## COMPILANDO Y CARGANDO EL FIRMWARE

1.  En el entorno de Arduino **ve al menú ”File-> Open …” y selecciona el archivo “Photoduino.ino”** en la carpeta donde tienes el firmware descomprimido. Esto abrirá cada archivo del firmware en una pestaña diferente.
2.  Si deseas modificar algún [parámetro del firmware](../parametros-del-firmware/ "Parámetros del firmware"), este es el momento de hacerlo.
3.  Pulsa sobre el botón “Verify” o **ve al menu “Sketch > Verify / Compile … “**
4.  En la zona negra de la parte inferior **no debe aparecer ningún error**. Solamente texto en blanco. **Si hay texto en rojo es que hay errores** y deberás chequear que el nombre de la carpeta es correcto.
5.  Si todo va bien, puedes **pulsar el botón “Upload” o ir al menu “File-> Upload”** y esperar a que termine.
6.  El entorno **te dirá si todo ha ido correctamente en la consola** (zona negra en la parte inferior)

## FINALIZANDO

-   Si todo ha ido bien, el firmware estará cargado en tu placa y deberías escuchar un pitido (si la Photoduino Shield esta conectada a la placa Arduino).
-   Si no ves texto en la pantalla LCD de photoduino, ajusta el potenciometro de contraste.
