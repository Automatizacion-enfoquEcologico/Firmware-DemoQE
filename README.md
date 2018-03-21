# Firmware-DemoQE

Programa en C que ejecuta un microcontrolador MC9S08QE128 de FREESCALE. 

Este microcontrolador se utiliza como modulo central a nivel de capa física y enlace del sistema, es maestro para la comunicación con el módulo externo por lo que recopila información de sensores tanto conectados directamente como externos, realiza la activación de actuadores y prepara los datos para ser enviados a la GUI.

Está configurado para ser un modulo interno del hogar, utiliza comunicacion serial para comunicación con esclavo y PC.

Entradas:
=

+  2 sensores de temperatura analógicos. 
+  Sensor de caudal FS400A, configurado como interrupción externa.
+  Sensor de movimiento PIR.
+  Sensor inductivo digital para apertura de puertas.

Salidas:
=

+ PWM para control de luces.
+ Digital para control de encendido de aire acondicionado.
