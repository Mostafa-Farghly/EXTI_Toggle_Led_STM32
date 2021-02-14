/*
 * Author:	Mostafa ALaa
 * Layer:	MCAL
 * SWC:		EXTI Driver
 * Version:	1.00
 */

#ifndef EXTI_H_
#define EXTI_H_

 /* ----------------------------------------------------------------------------
   -- Enums
   ---------------------------------------------------------------------------- */

/*
 * Enum Name: PinNum_Type
 * 
 * Enum Description: Maintains EXTI lines.
 * 
 */
typedef enum
{
	EXTI0,								/* Connected to GPIO pin 0 of each port */									
	EXTI1,								/* Connected to GPIO pin 1 of each port */									
	EXTI2,								/* Connected to GPIO pin 2 of each port */									
	EXTI3,								/* Connected to GPIO pin 3 of each port */									
	EXTI4,								/* Connected to GPIO pin 4 of each port */									
	EXTI5,								/* Connected to GPIO pin 5 of each port */									
	EXTI6,								/* Connected to GPIO pin 6 of each port */									
	EXTI7,								/* Connected to GPIO pin 7 of each port */									
	EXTI8,								/* Connected to GPIO pin 8 of each port */									
	EXTI9,								/* Connected to GPIO pin 9 of each port */									
	EXTI10,								/* Connected to GPIO pin 10 of each port */
	EXTI11,								/* Connected to GPIO pin 11 of each port */
	EXTI12,								/* Connected to GPIO pin 12 of each port */
	EXTI13,								/* Connected to GPIO pin 13 of each port */
	EXTI14,								/* Connected to GPIO pin 14 of each port */
	EXTI15,								/* Connected to GPIO pin 15 of each port */
	EXTI16,								/* EXTI line 16 is connected to the PVD output */
	EXTI17,								/* EXTI line 17 is connected to the RTC Alarm event */
	EXTI18,								/* EXTI line 18 is connected to the USB OTG FS Wakeup event */
	
	EXTI20 = 20,						/* EXTI line 20 is connected to the USB OTG HS (configured in FS) Wakeup event */
	EXTI21,								/* EXTI line 21 is connected to the RTC Tamper and TimeStamp events */
	EXTI22								/* EXTI line 22 is connected to the RTC Wakeup event */
	
}EXTILine_Type;


/*
 * Enum Name: Trigger_Type
 * 
 * Enum Description: Maintains triggers.
 * 
 */
typedef enum
{
	EXTI_RISING_TRIGGER,
	EXTI_FALLING_TRIGGER,
	EXTI_RIS_FALL_TRIGGER
	
}Trigger_Type;



/* ----------------------------------------------------------------------------
   -- Structures
   ---------------------------------------------------------------------------- */

/*
 * Struct Name: EXTI_pinConfig_Type
 * 
 * Struct Description: EXTI configurations initialization structure.
 *		Maintains all necessary elements for EXTI initialization.
 * 
 */
typedef struct
{
    EXTILine_Type 	Line;
    Trigger_Type 	Trigger;
    void (*callBackFunc)(void);

}EXTI_lineInterruptConfig_Type;


/* ----------------------------------------------------------------------------
   -- Function Declerations
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
void EXTI_interruptInit(const EXTI_lineInterruptConfig_Type *a_pinConfig);

 
 /***************************************************************************************
 * Function Name:	EXTI_clearPendingFlag
 *
 * Description: 	Clears the pending flag of the required pin.
 *
 * Arguments:		a_Line: The desired EXTI line number to disable its interrupt.
 *
 * Return:			void
 ***************************************************************************************/
void EXTI_clearPendingFlag(EXTILine_Type a_Line);
 
 
 /***************************************************************************************
 * Function Name:	EXTI_interruptEnable
 *
 * Description: 	Enables Interrupt for a pin.
 *
 * Arguments:		a_Line: The desired EXTI line number to disable its interrupt.
 *
 * Return:			void
 ***************************************************************************************/
void EXTI_interruptEnable(EXTILine_Type a_Line);
 
 
 /***************************************************************************************
 * Function Name:	EXTI_interruptDisable
 *
 * Description: 	Disables Interrupt for a pin.
 *
 * Arguments:		a_Line: The desired EXTI line number to disable its interrupt.
 *
 * Return:			void
 ***************************************************************************************/
void EXTI_interruptDisable(EXTILine_Type a_Line);


#endif /* EXTI_H_ */
