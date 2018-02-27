/* ###################################################################
**     Filename    : main.c
**     Project     : serial2
**     Processor   : MC9S08QE128CLK
**     Version     : Driver 01.12
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2018-02-14, 14:22, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.12
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "TI1.h"
#include "AD1.h"
#include "AS1.h"
#include "PWM1.h"
#include "Bit1.h"
#include "PWM2.h"
#include "Bit2.h"
#include "Bit3.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

unsigned char palabra[8];
unsigned char preambulo = 255;
unsigned char binaria = 0x0;
unsigned char adc0 = 0;
unsigned char adc1 = 0;
int num = 8;
int estado = 0;
unsigned char basura = 200;
int dc_ms = 900;
int ERROR;

int estado_s = 0;
bool aire = FALSE; //salida
unsigned char pir; //entrada PTA2
unsigned char reed; //entrada PTA3


void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/


	PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  
  for(;;){ 	  
	  
	  switch (estado){
	  
	  case 0:
		  
		  break;
	  
	  case 1:
  		  palabra[0] = preambulo;
  		  palabra[1] = 0;
  		  //leer data digital binaria
  		  
  		  pir = !Bit2_GetVal(); // pta2
  		  reed = !Bit3_GetVal();//pta3
  		  Bit1_PutVal(reed);
  		  
  		  binaria = (reed << 1); 
  		  palabra[1] = binaria|palabra[1];
  		  binaria = pir;
  		  palabra[1] = binaria|palabra[1];
  		  
  		  //////////////
  		  
  		  AD1_MeasureChan(TRUE, 0);
  		  AD1_GetChanValue8(0,&adc0);
  		 
  		  AD1_MeasureChan(TRUE, 1);
  		  AD1_GetChanValue8(1,&adc1);
  		 
  		  if(adc0 == 255){
  			  palabra[2] = 254;
  		  }else
  		  {
  			  palabra[2] = adc0;
  		  }
  		  if(adc1 == 255){
  			  palabra[3] = 254;
  		  }else
  		  {
  			  palabra[3] = adc1;
  		  }
  		  
  		  
  		  palabra[4] = basura;
  		  palabra[5] = basura;
  		  palabra[6] = basura;
  		  palabra[7] = basura;
  		  
  		  AS1_SendBlock(palabra, num, &num);
  		  
  		  estado = 0;
  		 
  		  break;
  		 
  	  }  
	  
	  switch(estado_s){
	  case 0:
		  // ACTUALIZA LAS SALIDAS, ESPERA ENVIO DESDE PC
		 // Bit1_PutVal(pir);
		  PWM2_SetRatio8(adc1); 
		  PWM1_SetRatio8(adc0);
		  break;
	  case 1:
		  
		  // DESENCAPSULO LA TRAMA ENVIADA DESDE LA PC
		  // ACTUALIZO LAS VARIABLES DE LAS SALIDAS
		  estado_s = 0;
		  break;
	  
	  }
  	  
  	  
    }
  
  

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
