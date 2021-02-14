/*
 * Author:	Mostafa ALaa
 * Layer:	MCAL
 * SWC:		RCC driver
 * Version:	1.00
 */

#ifndef RCC_H_
#define RCC_H_

/* ----------------------------------------------------------------------------
   -- Enums
   ---------------------------------------------------------------------------- */

/*
 * Enum Name: AHB1Peripheral_Type
 *
 * Enum Description: This enum is responsible for maintaining AHB1 peripherals.
 *
 * Note that reset is not applicable for both "BKPSRAM" and "OTGHSULPI".
 *
 */
typedef enum
{
	RCC_AHB1_GPIOA,
	RCC_AHB1_GPIOB,
	RCC_AHB1_GPIOC,
	RCC_AHB1_GPIOD,
	RCC_AHB1_GPIOE,
	RCC_AHB1_GPIOF,
	RCC_AHB1_GPIOG,
	RCC_AHB1_GPIOH,

	RCC_AHB1_CRC = 12,

	RCC_AHB1_BKPSRAM = 18,				/* Don't use for RCC_AHB1_resetClock */

	RCC_AHB1_DMA1 = 21,
	RCC_AHB1_DMA2 = 22,

	RCC_AHB1_OTGHS = 29,
	RCC_AHB1_OTGHSULPI = 30				/* Don't use for RCC_AHB1_resetClock */

}AHB1Peripheral_Type;
   

/*
 * Enum Name: AHB2Peripheral_Type
 *
 * Enum Description: This enum is responsible for maintaining AHB2 peripherals.
 *
 */
typedef enum
{
	RCC_AHB2_DCMI = 0,
	RCC_AHB2_OTGFS = 7

}AHB2Peripheral_Type;


/*
 * Enum Name: AHB3Peripheral_Type
 *
 * Enum Description: This enum is responsible for maintaining AHB3 peripherals.
 *
 */
typedef enum
{
	RCC_AHB3_FMC,
	RCC_AHB3_QSPI
	
}AHB3Peripheral_Type;


/*
 * Enum Name: APB1Peripheral_Type
 *
 * Enum Description: This enum is responsible for maintaining APB1 peripherals.
 *
 */
typedef enum
{
	RCC_APB1_TIM2 = 0,
	RCC_APB1_TIM3,
	RCC_APB1_TIM4,
	RCC_APB1_TIM5,
	RCC_APB1_TIM6,
	RCC_APB1_TIM7,
	RCC_APB1_TIM12,
	RCC_APB1_TIM13,
	RCC_APB1_TIM14,
	
	RCC_APB1_WWDG = 11,
	
	RCC_APB1_SPI2 = 13,
	RCC_APB1_SPI3,
	
	RCC_APB1_SPDIFRX = 16,
	
	RCC_APB1_USART2 = 17,
	RCC_APB1_USART3,
	RCC_APB1_USART4,
	RCC_APB1_USART5,
	
	RCC_APB1_I2C1 = 21,
	RCC_APB1_I2C2,
	RCC_APB1_I2C3,
	
	RCC_APB1_FMPI2C1 = 24,
	
	RCC_APB1_CAN1 = 25,
	RCC_APB1_CAN2,
	
	RCC_APB1_CEC = 27,
	RCC_APB1_PWR = 28,
	RCC_APB1_DAC = 29
	
}APB1Peripheral_Type;


/*
 * Enum Name: APB2Peripheral_Type
 *
 * Enum Description: This enum is responsible for maintaining APB2 peripherals.
 *
 */
typedef enum
{
	RCC_APB2_TIM1 = 0,
	RCC_APB2_TIM8,
	
	RCC_APB2_USART1 = 4,
	RCC_APB2_USART6,
	
	RCC_APB2_ADC1 = 8,
	RCC_APB2_ADC2,
	RCC_APB2_ADC3,
	
	RCC_APB2_SDIO = 11,
	
	RCC_APB2_SPI1 = 12,
	RCC_APB2_SPI4,
	
	RCC_APB2_SYSCFG = 14,
	
	RCC_APB2_TIM9 = 16,
	RCC_APB2_TIM10,
	RCC_APB2_TIM11,
	
	RCC_APB2_SAI1 = 22,
	RCC_APB2_SAI2
	
}APB2Peripheral_Type;


/*
 * Enum Name: SystemClock_Type
 *
 * Enum Description: This enum is responsible for maintaining system clocks.
 *
 */
typedef enum
{
	RCC_SC_HSI,
	RCC_SC_HSE,
	RCC_SC_PLL_P,
	RCC_SC_PLL_R
	
}SystemClock_Type;


/*
 * Enum Name: Clock_Type
 *
 * Enum Description: This enum is responsible for maintaining clock types.
 *
 */
typedef enum
{
	RCC_CLOCK_HSI = 0,
	RCC_CLOCK_HSE = 16,
	RCC_CLOCK_PLL = 24,
	RCC_CLOCK_PLLI2S = 26,
	RCC_CLOCK_PLLSAI = 28
	
}Clock_Type;


/*
 * Enum Name: ClockStatus_Type
 *
 * Enum Description: This enum is responsible for maintaining clock status.
 *
 */
typedef enum
{
	RCC_CLOCK_STATUS_OFF,
	RCC_CLOCK_STATUS_ON
	
}ClockStatus_Type;


/*
 * Enum Name: ClockStatus_Type
 *
 * Enum Description: This enum is responsible for maintaining clock status.
 *
 */
typedef enum
{
	RCC_CLOCK_NO_BYPASS,
	RCC_CLOCK_BYPASS
	
}ClockBypass_Type;


/* ----------------------------------------------------------------------------
   -- Structures
   ---------------------------------------------------------------------------- */
/*
 * Struct Name: RCC_ClockStatus_Type
 *
 * Struct Description :This struct is responsible for maintaining clock status
 * information to pass to "RCC_setClockStatus" function.
 *
 */
typedef struct
{
	/* ClockType indicates which clock to set its status. */
	Clock_Type		 	ClockType;
	/* ClockStatus indicates whether to turn the clock on or off */
	ClockStatus_Type 	ClockStatus;
	/* Bypass indicates whether to bypass the oscillator with an external
	 * clock or not (Bypass is needed if an external RC clock) */
	ClockBypass_Type	Bypass;
	
}RCC_ClockStatus_Type;



/* ----------------------------------------------------------------------------
   -- Function Declerations
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
void RCC_AHB1_enableClock(AHB1Peripheral_Type a_peripheral);


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
void RCC_AHB2_enableClock(AHB2Peripheral_Type a_peripheral);


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
void RCC_AHB3_enableClock(AHB3Peripheral_Type a_peripheral);


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
void RCC_APB1_enableClock(APB1Peripheral_Type a_peripheral);


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
void RCC_APB2_enableClock(APB2Peripheral_Type a_peripheral);


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
void RCC_AHB1_disableClock(AHB1Peripheral_Type a_peripheral);


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
void RCC_AHB2_disableClock(AHB2Peripheral_Type a_peripheral);


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
void RCC_AHB3_disableClock(AHB3Peripheral_Type a_peripheral);


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
void RCC_APB1_disableClock(APB1Peripheral_Type a_peripheral);


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
void RCC_APB2_disableClock(APB2Peripheral_Type a_peripheral);


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
void RCC_setCLockStatus(const RCC_ClockStatus_Type *a_clockStatus_Ptr);


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
uint8 RCC_getClockStatus(Clock_Type a_clockType);


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
uint8 RCC_getCLockSource(void);


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
uint8 RCC_setCLockSource(SystemClock_Type a_systemClock);


#endif /* RCC_H_ */
