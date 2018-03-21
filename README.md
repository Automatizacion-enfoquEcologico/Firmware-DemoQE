# Firmware-DemoQE

Programa en C que ejecuta un microcontrolador MC9S08QE128 de FREESCALE. 

Este microcontrolador se utiliza como modulo central a nivel de capa física y enlace del sistema, es maestro para la comunicación con módulos externos por lo que recopila información de sensores y prepara los datos para ser enviados a la GUI, así como realiza la activación de actuadores.

Está configurado para ser un modulo interno en el hogar, se utiliza el protocolo RS232 para comunicación, posee como entradas y salidas:

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
