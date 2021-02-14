/*
 * Author:	Mostafa ALaa
 * Layer:	MCAL
 * SWC:		EXTI Driver
 * Version:	1.00
 */

/* ----------------------------------------------------------------------------
   -- Includes
   ---------------------------------------------------------------------------- */

#include "std_types.h"
#include "stm32f446xe.h"
#include "exti.h"


/* ----------------------------------------------------------------------------
   -- Global Variables
   ---------------------------------------------------------------------------- */
static void (*HandlersCallBack_Arr[23])(void);


/* ----------------------------------------------------------------------------
   -- Functions Definitions
   ---------------------------------------------------------------------------- */

/***************************************************************************************
 * Function Name:	EXTI_interruptInit
 *
 * Description: 	Initializes the required EXTI pin configuration options.
 *
 * Arguments:		*a_pinConfig: constant pointer to EXTI_lineInterruptConfig_Type
 *						structure which holds the configuration options.
 *
 * Return:			void
 ***************************************************************************************/
void EXTI_interruptInit(const EXTI_lineInterruptConfig_Type *a_pinConfig)
{
	/* Initialize corresponding handler */
	HandlersCallBack_Arr[a_pinConfig->Line] = a_pinConfig->callBackFunc;

	/* Enable Interrupt */
	EXTI->IMR |= 0x1 << a_pinConfig->Line;

	/* Configure trigger */

	/* Clear triggers */
	/*TODO*/

	/* set required trigger */
	if(a_pinConfig->Trigger == EXTI_RIS_FALL_TRIGGER || a_pinConfig->Trigger == EXTI_RISING_TRIGGER)
	{
		EXTI->RTSR |= 0x1 << a_pinConfig->Line;
	}

	if(a_pinConfig->Trigger == EXTI_RIS_FALL_TRIGGER || a_pinConfig->Trigger == EXTI_FALLING_TRIGGER)
	{
		EXTI->FTSR |= 0x1 << a_pinConfig->Line;
	}
}


/***************************************************************************************
 * Function Name:	EXTI_clearPendingFlag
 *
 * Description: 	Clears the pending flag of the required pin.
 *
 * Arguments:		a_Line: The desired EXTI line number to disable its interrupt.
 *
 * Return:			void
 ***************************************************************************************/
void EXTI_clearPendingFlag(EXTILine_Type a_Line)
{
	EXTI->PR |= 0x1 << a_Line;
}


/***************************************************************************************
 * Function Name:	EXTI_interruptEnable
 *
 * Description: 	Enables Interrupt for a pin.
 *
 * Arguments:		a_Line: The desired EXTI line number to disable its interrupt.
 *
 * Return:			void
 ***************************************************************************************/
void EXTI_interruptEnable(EXTILine_Type a_Line)
{
	EXTI->IMR |= 0x1 << a_Line;
}


/***************************************************************************************
 * Function Name:	EXTI_interruptDisable
 *
 * Description: 	Disables Interrupt for a pin.
 *
 * Arguments:		a_Line: The desired EXTI line number to disable its interrupt.
 *
 * Return:			void
 ***************************************************************************************/
void EXTI_interruptDisable(EXTILine_Type a_Line)
{
	EXTI->IMR &= ~(0x1 << a_Line);
}


/* ----------------------------------------------------------------------------
   -- ISRs
   ---------------------------------------------------------------------------- */

/* EXTI Line0 interrupt */
void EXTI0_IRQHandler(void)
{
	/* Clear pending flag */
	EXTI->PR |= 0x1 << 0;

	/* Call handler call back function */
	HandlersCallBack_Arr[0]();
}


/* EXTI Line1 interrupt */
void EXTI1_IRQHandler(void)
{
	/* Clear pending flag */
	EXTI->PR |= 0x1 << 1;

	/* Call handler call back function */
	HandlersCallBack_Arr[1]();
}


/* EXTI Line2 interrupt */
void EXTI2_IRQHandler(void)
{
	/* Clear pending flag */
	EXTI->PR |= 0x1 << 2;

	/* Call handler call back function */
	HandlersCallBack_Arr[2]();
}


/* EXTI Line3 interrupt */
void EXTI3_IRQHandler(void)
{
	/* Clear pending flag */
	EXTI->PR |= 0x1 << 3;

	/* Call handler call back function */
	HandlersCallBack_Arr[3]();
}


/* EXTI Line4 interrupt */
void EXTI4_IRQHandler(void)
{
	/* Clear pending flag */
	EXTI->PR |= 0x1 << 4;

	/* Call handler call back function */
	HandlersCallBack_Arr[4]();
}


/* EXTI Line[9:5] interrupts */
void EXTI9_5_IRQHandler(void)
{
	/* Check which line generated the interrupt request */
	int i;
	for(i = 5; i <= 9; i++)
	{
		if((EXTI->PR >> i) & (EXTI->IMR >> i) & 0x01)
		{
			/* Clear pending flag */
			EXTI->PR |= 0x1 << i;

			/* Call handler call back function */
			HandlersCallBack_Arr[i]();
		}
	}
}


/* EXTI Line[15:10] ISR */
void EXTI15_10_IRQHandler(void)
{
	/* Check which line generated the interrupt request */
	int i;
	for(i = 10; i <= 15; i++)
	{
		if((EXTI->PR >> i) & (EXTI->IMR >> i) & 0x01)
		{
			/* Clear pending flag */
			EXTI->PR |= 0x1 << i;

			/* Call handler call back function */
			HandlersCallBack_Arr[i]();
		}
	}
}


/* PVD through EXTI16 line detection interrupt */
void PVD_IRQHandler(void)
{
	/* Clear pending flag */
	EXTI->PR |= 0x1 << 16;

	/* Call handler call back function */
	HandlersCallBack_Arr[16]();
}


/* RTC Alarms (A and B) through EXTI17 line interrupt */
void RTC_Alarm_IRQHandler(void)
{
	/* Clear pending flag */
	EXTI->PR |= 0x1 << 17;

	/* Call handler call back function */
	HandlersCallBack_Arr[17]();
}


/* USB On-The-Go FS Wakeup through EXTI18 line interrupt */
void OTG_FS_WKUP_IRQHandler(void)
{
	/* Clear pending flag */
	EXTI->PR |= 0x1 << 18;

	/* Call handler call back function */
	HandlersCallBack_Arr[18]();
}


/* Tamper and TimeStamp interrupts through the EXTI21 line */
void TAMP_STAMP_IRQHandler(void)
{
	/* Clear pending flag */
	EXTI->PR |= 0x1 << 21;

	/* Call handler call back function */
	HandlersCallBack_Arr[21]();
}


/* RTC Wakeup interrupt through the EXTI22 line */
void RTC_WKUP_IRQHandler(void)
{
	/* Clear pending flag */
	EXTI->PR |= 0x1 << 22;

	/* Call handler call back function */
	HandlersCallBack_Arr[22]();
}


/*-------------------------------------------- End of exti.c --------------------------------------------*/
