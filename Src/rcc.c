/*
 * Author:	Mostafa ALaa
 * Layer:	MCAL
 * SWC:		RCC driver
 * Version:	1.00
 */
 
/* ----------------------------------------------------------------------------
   -- Includes
   ---------------------------------------------------------------------------- */

#include "std_types.h"
#include "stm32f446xe.h"
#include "rcc.h"


/* ----------------------------------------------------------------------------
   -- Functions Definitions
   ---------------------------------------------------------------------------- */

/*
 * Function Name: RCC_AHB1_enableClock
 *
 * Function Description: Enables clock for an AHB1 peripheral.
 *
 * Arguments:
 * 		1. AHB1Peripheral_Type a_peripheral:
 *				The peripheral wanted to enable its clock.
 *
 * Return: void.
 *
 */
void RCC_AHB1_enableClock(AHB1Peripheral_Type a_peripheral)
{
	/* Set the bit in the AHB1ENR that corresponds to the desired peripheral */
	RCC->AHB1ENR |= (1 << a_peripheral);
}


/*
 * Function Name: RCC_AHB2_enableClock
 *
 * Function Description: Enables clock for an AHB2 peripheral.
 *
 * Arguments:
 * 		1. AHB2Peripheral_Type a_peripheral:
 * 				The peripheral wanted to enable its clock.
 *
 * Return: void.
 *
 */
void RCC_AHB2_enableClock(AHB2Peripheral_Type a_peripheral)
{
	/* Set the bit in the AHB2ENR that corresponds to the desired peripheral */
	RCC->AHB2ENR |= (1 << a_peripheral);
}


/*
 * Function Name: RCC_AHB3_enableClock
 *
 * Function Description: Enables clock for an AHB3 peripheral.
 *
 * Arguments:
 * 		1. AHB3Peripheral_Type a_peripheral:
 * 				The peripheral wanted to enable its clock.
 *
 * Return: void.
 *
 */
void RCC_AHB3_enableClock(AHB3Peripheral_Type a_peripheral)
{
	/* Set the bit in the AHB3ENR that corresponds to the desired peripheral */
	RCC->AHB3ENR |= (1 << a_peripheral);
}


/*
 * Function Name: RCC_APB1_enableClock
 *
 * Function Description: Enables clock for an APB1 peripheral.
 *
 * Arguments:
 * 		1. APB1Peripheral_Type a_peripheral:
 * 				The peripheral wanted to enable its clock.
 *
 * Return: void.
 *
 */
void RCC_APB1_enableClock(APB1Peripheral_Type a_peripheral)
{
	/* Set the bit in the APB1ENR that corresponds to the desired peripheral */
	RCC->APB1ENR |= (1 << a_peripheral);
}


/*
 * Function Name: RCC_APB2_enableClock
 *
 * Function Description: Enables clock for an APB2 peripheral.
 *
 * Arguments:
 * 		1. APB2Peripheral_Type a_peripheral:
 * 				The peripheral wanted to enable its clock.
 *
 * Return: void.
 *
 */
void RCC_APB2_enableClock(APB2Peripheral_Type a_peripheral)
{
	/* Set the bit in the APB2ENR that corresponds to the desired peripheral */
	RCC->APB2ENR |= (1 << a_peripheral);
}


/*
 * Function Name: RCC_AHB1_disableClock
 *
 * Function Description: Enables clock for an AHB1 peripheral.
 *
 * Arguments:
 * 		1. AHB1Peripheral_Type a_peripheral:
 *				The peripheral wanted to disable its clock.
 *
 * Return: void.
 *
 */
void RCC_AHB1_disableClock(AHB1Peripheral_Type a_peripheral)
{
	/* Clear the bit in the AHB1ENR that corresponds to the desired peripheral */
	RCC->AHB1ENR &= ~(1 << a_peripheral);
}


/*
 * Function Name: RCC_AHB2_disableClock
 *
 * Function Description: Disables clock for an AHB2 peripheral.
 *
 * Arguments:
 * 		1. AHB2Peripheral_Type a_peripheral:
 * 				The peripheral wanted to disable its clock.
 *
 * Return: void.
 *
 */
void RCC_AHB2_disableClock(AHB2Peripheral_Type a_peripheral)
{
	/* Clear the bit in the AHB2ENR that corresponds to the desired peripheral */
	RCC->AHB2ENR &= ~(1 << a_peripheral);
}


/*
 * Function Name: RCC_AHB3_disableClock
 *
 * Function Description: Disables clock for an AHB3 peripheral.
 *
 * Arguments:
 * 		1. AHB3Peripheral_Type a_peripheral:
 * 				The peripheral wanted to disable its clock.
 *
 * Return: void.
 *
 */
void RCC_AHB3_disableClock(AHB3Peripheral_Type a_peripheral)
{
	/* Clear the bit in the AHB3ENR that corresponds to the desired peripheral */
	RCC->AHB3ENR &= ~(1 << a_peripheral);
}


/*
 * Function Name: RCC_APB1_disableClock
 *
 * Function Description: Disables clock for an APB1 peripheral.
 *
 * Arguments:
 * 		1. APB1Peripheral_Type a_peripheral:
 * 				The peripheral wanted to disable its clock.
 *
 * Return: void.
 *
 */
void RCC_APB1_disableClock(APB1Peripheral_Type a_peripheral)
{
	/* Clear the bit in the APB1ENR that corresponds to the desired peripheral */
	RCC->APB1ENR &= ~(1 << a_peripheral);
}


/*
 * Function Name: RCC_APB2_disableClock
 *
 * Function Description: Disables clock for an APB2 peripheral.
 *
 * Arguments:
 * 		1. APB2Peripheral_Type a_peripheral:
 * 				The peripheral wanted to disable its clock.
 *
 * Return: void.
 *
 */
void RCC_APB2_disableClock(APB2Peripheral_Type a_peripheral)
{
	/* Clear the bit in the APB2ENR that corresponds to the desired peripheral */
	RCC->APB2ENR &= ~(1 << a_peripheral);
}


/*
 * Function Name: RCC_setClockStatus
 *
 * Function Description: This function is responsible for any clock's status. It does two things:
 *		1. Turns any clock on or off.
 * 		2. Bypass the oscillator with an external clock. (Used with an external RC clock)
 *
 * Arguments:
 * 		1. RCC_ClockStatus_Type *a_clockStatus_Ptr: A pointer to struct that holds the information 
 *		needed to set a clock's status. (Check the struct for the required intialization)
 *
 * Return: void
 *
 */
void RCC_setCLockStatus(const RCC_ClockStatus_Type *a_clockStatus_Ptr)
{
	/* check to bypass oscillator or not */
	if(a_clockStatus_Ptr->Bypass)
	{
		RCC->CR |= (1 << RCC_CR_HSEBYP_SHIFT);
	}
	
	/* Check whether to turn the clock on or off */
	if(a_clockStatus_Ptr->ClockStatus)
	{
		/* Turn on the desired clock by setting its ON bit in the RCC_CR */
		RCC->CR |= (1 << a_clockStatus_Ptr->ClockType);
	}
	else
	{
		/* Turn off the desired clock by clearing its ON bit in the RCC_CR */
		RCC->CR &= ~(1 << a_clockStatus_Ptr->ClockType);
	}
}


/*
 * Function Name: RCC_getClockStatus
 *
 * Function Description: Checks if a clock is ON or OFF
 *
 * Arguments:
 * 		1. Clock_Type a_clocktype: Indicates which clock to check its status.
 *
 * Return: A non-zero value if the passed clock is ON, and
 * 		a value of zero if it is OFF.
 *
 */
uint8 RCC_getClockStatus(Clock_Type a_clockType)
{
	/* Return the status of the ready flag of the corresponding clock type.
	 *
	 * Note that the relation between the ready flag and the passed ClockType
	 * of each clock is (ready flag = ClockType + 1)
	 */
	 return (uint8)((RCC->CR >> (a_clockType + 1)) & 1);
}


/*
 * Function Name: RCC_getClockSource
 *
 * Function Description: Gets the system clock source.
 *
 * Arguments: void
 * 		The function takes no arguments.
 *
 * Return: uint8 value that indicates the system clock source:
 * 			0: HSI oscillator used as the system clock.
 * 			1: HSE oscillator used as the system clock.
 * 			2: PLL used as the system clock.
 * 			3: PLL_R used as the system clock.
 *
 */
uint8 RCC_getCLockSource(void)
{
	/* Return the value of the SWS bits of the RCC_CFGR */
	return (uint8)((RCC->CFGR & RCC_CFGR_SWS_MASK) >> RCC_CFGR_SWS_SHIFT);
}


/*
 * Function Name: RCC_setClockSource
 *
 * Function Description: Selects the system clock source.
 * 
 * Note that the selected clock has to be turned on first ("RCC_setClockStatus"
 * function can be used for this) or the function will return zero and exit
 * with no effect (without changing the system clock source).
 *
 * Arguments:
 * 		1. SystemClock_Type a_systemClock: Indicates which clock to set as a source.
 *
 * Return: A non-zero value if the passed SystemClock_Type is set as the system ,
 *		clock source successfully and a value of zero if the passed SystemClock_Type is off.
 *
 */
uint8 RCC_setCLockSource(SystemClock_Type a_systemClock)
{
	/* Check if the passed clock is OFF */
	if(a_systemClock == RCC_SC_HSI)
	{
		if(!RCC_getClockStatus(RCC_CLOCK_HSI))
		{
			return 0;
		}
	}
	else if(a_systemClock == RCC_SC_HSE)
	{
		if(!RCC_getClockStatus(RCC_CLOCK_HSE))
		{
			return 0;
		}
	}
	else
	{
		if(!RCC_getClockStatus(RCC_CLOCK_PLL))
		{
			return 0;
		}
	}
	
	/* Set the passed clock as system clock by putting its
	 * corresponding value in the SW bits of the RCC_CFGR.
	 *
	 * 00: HSI oscillator selected as system clock
	 * 01: HSE oscillator selected as system clock
	 * 10: PLL_P selected as system clock
	 * 11: PLL_R selected as system clock
	 *
	 * The passed argument equals to the required value of
	 * the two SW bits.
	 */

	/* Firstly, clear the two SW bits */
	RCC->CFGR &= ~RCC_CFGR_SW_MASK;
	
	/* Secondly, put the suitable value in the SW bits */
	RCC->CFGR |= (a_systemClock & RCC_CFGR_SW_MASK);

	return 1;
}


/*-------------------------------------------- End of rcc.c --------------------------------------------*/
