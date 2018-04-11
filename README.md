# Firmware

## Descripción

Programa en C que ejecuta un microcontrolador MC9S08QE128 de FREESCALE. Este microcontrolador se utiliza como modulo central a nivel de capa física y enlace del sistema, es maestro para la comunicación con el módulo externo por lo que recopila información de sensores tanto conectados directamente como externos, realiza la activación de actuadores y prepara los datos para ser enviados a la GUI. Está configurado para ser un módulo interno del hogar, utiliza comunicación serial para comunicación con esclavo y PC.

## Tabla de Contenidos
- [Requisitos](#requisitos)
- [Software](#software)
- [License](#license)

## Requisitos

La siguiente implementación fue desarrollada y probada en Windows 10 - 64 bits.

## Software

Implementación hecha en CodeWarrior v10.6 + Processor Expert.

