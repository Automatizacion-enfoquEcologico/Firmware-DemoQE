# Firmware-DemoQE

Programa en C que ejecuta un microcontrolador MC9S08QE128 de FREESCALE. 

Este microcontrolador se utiliza como modulo central del sistema a nivel de capa fisica y enlace, es maestro para la comunicación con modulos externos por lo que recopila informacion de sensores y prepara los datos para ser enviados a la GUI.

Esta configurado para ser un modulo interno en el hogar, posee como entradas y salidas:

Entradas:
=

+ 2 sensores de temperatura analogicos. 
+ Sensor de caudal FS400A, configurado como interrupcion externa.
+

Salidas:
=

