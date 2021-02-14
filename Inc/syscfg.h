/*
 * Author:	Mostafa ALaa
 * Layer:	
 * SWC:		
 * Version:	1.00
 */

#ifndef SYSCFG_H_
#define SYSCFG_H_

 /* ----------------------------------------------------------------------------
   -- Enums
   ---------------------------------------------------------------------------- */

/*
 * Enum Name: Port_Type
 * 
 * Enum Description: Maintains port types.
 * 
 */
typedef enum
{
	SYSCFG_EXTI_PORTA,
	SYSCFG_EXTI_PORTB,
	SYSCFG_EXTI_PORTC,
	SYSCFG_EXTI_PORTD,
	SYSCFG_EXTI_PORTE,
	SYSCFG_EXTI_PORTF,
	SYSCFG_EXTI_PORTG,
	SYSCFG_EXTI_PORTH
	
}SYSCFG_Port_Type;


/*
 * Enum Name: SYSCFG_PinNum_Type
 *
 * Enum Description: Maintains pins' numbers.
 *
 * Note that for port H only PIN0 and PIN1 are implemented.
 */
typedef enum
{
	SYSCFG_GPIO0,									/* GPIO pin number 0 */
	SYSCFG_GPIO1,									/* GPIO pin number 1 */
	
	/* The following pins aren't implemented for port H. */
	
	SYSCFG_GPIO2,									/* GPIO pin number 2 */
	SYSCFG_GPIO3,									/* GPIO pin number 3 */
	SYSCFG_GPIO4,									/* GPIO pin number 4 */
	SYSCFG_GPIO5,									/* GPIO pin number 5 */
	SYSCFG_GPIO6,									/* GPIO pin number 6 */
	SYSCFG_GPIO7,									/* GPIO pin number 7 */
	SYSCFG_GPIO8,									/* GPIO pin number 8 */
	SYSCFG_GPIO9,									/* GPIO pin number 9 */
	SYSCFG_GPIO10,									/* GPIO pin number 10 */
	SYSCFG_GPIO11,									/* GPIO pin number 11 */
	SYSCFG_GPIO12,									/* GPIO pin number 12 */
	SYSCFG_GPIO13,									/* GPIO pin number 13 */
	SYSCFG_GPIO14,									/* GPIO pin number 14 */
	SYSCFG_GPIO15									/* GPIO pin number 15 */

}SYSCFG_PinNum_Type;


/* ----------------------------------------------------------------------------
   -- Function Decelerations
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
void SYSCFG_EXTIPort(SYSCFG_Port_Type a_port, SYSCFG_PinNum_Type a_pinNum);


#endif /* SYSCFG_H_ */
