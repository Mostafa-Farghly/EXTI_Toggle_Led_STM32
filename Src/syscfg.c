/*
 * Author:	Mostafa ALaa
 * Layer:	
 * SWC:		
 * Version:	1.00
 */

/* ----------------------------------------------------------------------------
   -- Includes
   ---------------------------------------------------------------------------- */

#include "std_types.h"
#include "stm32f446xe.h"
#include "syscfg.h"


/* ----------------------------------------------------------------------------
   -- Functions Definitions
   ---------------------------------------------------------------------------- */

/***************************************************************************************
 * Function Name:	SYSCFG_EXTIPort
 *
 * Description: 	Selects the source input for the EXTIx external interrupt.
 *
 * Arguments:		1. a_port: Indicates the port desired to be the source input for the
 *						EXTIx external interrupt.
 *					2. a_pinNum: Indicates the pin number desired to be the source input
 *						for the EXTIx external interrupt.
 *
 * Return:			void
 ***************************************************************************************/
void SYSCFG_EXTIPort(SYSCFG_Port_Type a_port, SYSCFG_PinNum_Type a_pinNum)
{
	SYSCFG->EXTICR[a_pinNum / 4] &= ~(0xFUL << ((a_pinNum % 4) * 4));
	SYSCFG->EXTICR[a_pinNum / 4] |= (a_port << ((a_pinNum % 4) * 4));
}


/*-------------------------------------------- End of file.c --------------------------------------------*/
