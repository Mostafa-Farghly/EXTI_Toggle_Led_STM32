/*
 * Author:	Mostafa ALaa
 * Layer:	MCAL
 * SWC:		GPIO Driver
 * Version:	1.00
 */
 
 
#ifndef GPIO_H_
#define GPIO_H_
 
 /* ----------------------------------------------------------------------------
   -- Enums
   ---------------------------------------------------------------------------- */

/*
 * Enum Name: Port_Type
 *
 * Enum Description: Maintains port types.
 */
typedef enum
{
	GPIO_PORTA,									/* GPIO port A */
	GPIO_PORTB,									/* GPIO port B */
	GPIO_PORTC,									/* GPIO port C */
	GPIO_PORTD,									/* GPIO port D */
	GPIO_PORTE,									/* GPIO port E */
	GPIO_PORTF,									/* GPIO port F */
	GPIO_PORTG,									/* GPIO port G */
	GPIO_PORTH									/* GPIO port H */

}Port_Type;


/*
 * Enum Name: PinNum_Type
 *
 * Enum Description: Maintains pins' numbers.
 *
 * Note that for port H only PIN0 and PIN1 are implemented.
 */
typedef enum
{
	GPIO_PIN0,									/* GPIO pin number 0 */
	GPIO_PIN1,									/* GPIO pin number 1 */
	
	/* The following pins aren't implemented for port H. */
	
	GPIO_PIN2,									/* GPIO pin number 2 */
	GPIO_PIN3,									/* GPIO pin number 3 */
	GPIO_PIN4,									/* GPIO pin number 4 */
	GPIO_PIN5,									/* GPIO pin number 5 */
	GPIO_PIN6,									/* GPIO pin number 6 */
	GPIO_PIN7,									/* GPIO pin number 7 */
	GPIO_PIN8,									/* GPIO pin number 8 */
	GPIO_PIN9,									/* GPIO pin number 9 */
	GPIO_PIN10,									/* GPIO pin number 10 */
	GPIO_PIN11,									/* GPIO pin number 11 */
	GPIO_PIN12,									/* GPIO pin number 12 */
	GPIO_PIN13,									/* GPIO pin number 13 */
	GPIO_PIN14,									/* GPIO pin number 14 */
	GPIO_PIN15									/* GPIO pin number 15 */

}PinNum_Type;


/*
 * Enum Name: PinMode_Type
 *
 * Enum Description: Has the four pin modes.
 */
typedef enum
{
	GPIO_INPUT,									/* Input (reset state) */
	GPIO_OUTPUT,								/* General purpose output mode */
	GPIO_ALT,									/* Alternate function mode */
	GPIO_ANALOG									/* Analog mode */

}PinMode_Type;


/*
 * Enum Name: PinPullStatus_Type 
 *
 * Enum Description: GPIO pin pull status
 */
typedef enum
{
	GPIO_NOPULL,								/* No pull-up, pull-down */
	GPIO_PULLUP,								/* Pull-up */
	GPIO_PULLDOWN								/* Pull-Down */

}PinPullStatus_Type;


/*
 * Enum Name: PinAltFunc_Type
 *
 * Enum Description: GPIO pin alternate function
 */
typedef enum
{
	GPIO_AF0,									/* Alternate function 0 */
	GPIO_AF1,									/* Alternate function 1 */
	GPIO_AF2,									/* Alternate function 2 */
	GPIO_AF3,									/* Alternate function 3 */
	GPIO_AF4,									/* Alternate function 4 */
	GPIO_AF5,									/* Alternate function 5 */
	GPIO_AF6,									/* Alternate function 6 */
	GPIO_AF7,									/* Alternate function 7 */
	GPIO_AF8,									/* Alternate function 8 */
	GPIO_AF9,									/* Alternate function 9 */
	GPIO_AF10,									/* Alternate function 10 */
	GPIO_AF11,									/* Alternate function 11 */
	GPIO_AF12,									/* Alternate function 12 */
	GPIO_AF13,									/* Alternate function 13 */
	GPIO_AF14,									/* Alternate function 14 */
	GPIO_AF15,									/* Alternate function 15 */
	
	GPIO_AF_NA = 0								/* Alternate function not applicable */

}PinAltFunc_Type;


/*
 * Enum Name: OutputType_Type
 *
 * Enum Description: GPIO output type
 */
typedef enum
{
	GPIO_OUT_PUSH_PULL,							/* Output push-pull (reset state) */
	GPIO_OUT_OPEN_DRAIN,						/* Output open-drain */
	
	GPIO_OUT_TYPE_NA = 0						/* GPIO pin output type is not applicable */

}OutputType_Type;


/*
 * Enum Name: OutputSpeed_Type
 *
 * Enum Description: GPIO output speed
 */
typedef enum
{
	GPIO_OUT_LOW_SPEED,							/* Low speed */
	GPIO_OUT_MEDIUM_SPEED,						/* Medium speed */
	GPIO_OUT_FAST_SPEED,						/* Fast speed */
	GPIO_OUT_HIGH_SPEED,						/* High speed */
	
	GPIO_OUT_SPEED_NA = 0						/* GPIO pin output speed is not applicable */

}OutputSpeed_Type;


/*
 * Enum Name: OutputValue_Type
 *
 * GPIO output values
 */
typedef enum
{
	GPIO_LOW = 0,								/* Outputs low */
	GPIO_HIGH = 16								/* Outputs high */

}OutputValue_Type;


/* ----------------------------------------------------------------------------
   -- Structures
   ---------------------------------------------------------------------------- */

/*
 * Struct Name: GPIO_PinConfig_Type
 *
 * Struct Description: GPIO configurations initialization structure.
 *		Maintains all necessary elements for GPIO initialization.
 *
 */
typedef struct
{
	Port_Type 			Port;					/* The desired port */
	PinNum_Type 		PinNum;					/* The desired pin number */
	PinMode_Type 		PinMode;				/* The desired pin mode */
	OutputSpeed_Type 	OutputSpeed;			/* The desired output speed */
												/* (OutputSpeed is ignored if PinMode != GPIO_OUTPUT) */
	OutputType_Type		OutputType;				/* The desired output type */
												/* (OutputType is ignored if PinMode != GPIO_OUTPUT) */
	PinPullStatus_Type 	PullStatus;				/* If pull-up or pull-down */
	PinAltFunc_Type 	AltFunc;				/* The desired alternative function if any */
												/* (AltFunc is ignored if PinMode != GPIO_ALT)*/

}GPIO_PinConfig_Type;


/* ----------------------------------------------------------------------------
   -- Function Declerations
   ---------------------------------------------------------------------------- */

/***************************************************************************************
 * Function Name:	GPIO_pinInit
 *
 * Description: 	The function initializes the required pin configuration options.
 *
 * Arguments:		*a_pinConfig_Ptr: constant pointer to GPIO_PinConfig_Type
 *						structure which holds the configuration options.
 *
 * Return:			void
 ***************************************************************************************/
void GPIO_pinInit(const GPIO_PinConfig_Type *a_pinConfig_Ptr);


/***************************************************************************************
 * Function Name:	GPIO_setPinValue
 *
 * Description:		The function sets an output value on the output pin
 *
 * Arguments:		1- a_port: The port of the required output pin, refer to port possible options
 * 					2- a_pinNum: The pin number of the required output pin, refer to Pin number
 *							possible options
 * 					3- a_value: The required pin state, refer to pin value possible options
 *
 * Return:			void
 ***************************************************************************************/
void GPIO_setPinValue(Port_Type a_port, PinNum_Type a_pinNum, OutputValue_Type a_value);


/***************************************************************************************
 * Function Name:	GPIO_setPortValue
 *
 * Description:		The function sets a value on the port
 *
 * Arguments:		1- a_port: The port required refer to port possible options
 * 					2- a_value: The required port value
 *
 * Return:			void
 ***************************************************************************************/
void GPIO_setPortValue(Port_Type a_port, uint16 a_value);


/***************************************************************************************
 * Function Name:	GPIO_readPinValue
 *
 * Description:		The function Reads the value on the required pin
 *
 * Arguments:		1- a_port: The port of the required pin, refer to port possible options
 * 					2- a_pinNum: The pin number of the required pin, refer to Pin number possible options
 *
 * Return:			uint8: A non-zero value if the pin reads high and a value of zero if the pin reads low.
 ***************************************************************************************/
uint8 GPIO_readPinValue(Port_Type a_port, PinNum_Type a_pinNum);


/***************************************************************************************
 * Function Name:	GPIO_togglePinValue
 *
 * Description:		The function Toggles the value on the required pin
 *
 * Arguments:		1- Port: The port of the required pin, refer to port possible options
 * 					2- Pin: The pin number of the required pin, refer to Pin number possible options
 *
 * Return:			void
 ***************************************************************************************/
void GPIO_togglePinValue(Port_Type a_port, PinNum_Type a_pinNum);


#endif /* GPIO_H_ */
 
