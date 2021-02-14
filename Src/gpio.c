/*
 * Author:	Mostafa ALaa
 * Layer:	MCAL
 * SWC:		GPIO Driver
 * Version:	1.00
 */

/* ----------------------------------------------------------------------------
   -- Includes
   ---------------------------------------------------------------------------- */

#include "std_types.h"
#include "stm32f446xe.h"
#include "gpio.h"


/* ----------------------------------------------------------------------------
   -- Global Variables
   ---------------------------------------------------------------------------- */
   
static GPIO_Type* GPIO_PORTS_ARRAY[8] = {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG, GPIOH};


/* ----------------------------------------------------------------------------
   -- Functions Definitions
   ---------------------------------------------------------------------------- */

/***************************************************************************************
 * Function Name:	GPIO_pinInit
 *
 * Description: 	The function initializes the required pin configuration options.
 *
 * Arguments:		*a_pinConfig_Ptr: constant pointer to GPIO_PinConfig_Type
 *						structure which holds the configurations
 *
 * Return:			void
 ***************************************************************************************/
void GPIO_pinInit(const GPIO_PinConfig_Type *a_pinConfig_Ptr)
{
	/*
	 * Setting the pin's mode.
	 *
	 * Notice the relation ship between the pin number and the shift value of
	 * its two corresponding MODER bits in the MODER.
	 * (shift value of MODER bits = 2 * pin number)
	 *
	 * 1. Clear the two bits of MODER which corresponds to the bit number.
	 * 2. Put the desired value into the targeted MODER bits.
	 */
	GPIO_PORTS_ARRAY[a_pinConfig_Ptr->Port]->MODER &= ~(0x03UL << (2 * a_pinConfig_Ptr->PinNum));
	GPIO_PORTS_ARRAY[a_pinConfig_Ptr->Port]->MODER |= (a_pinConfig_Ptr->PinMode << (2 * a_pinConfig_Ptr->PinNum));
	
	/*
	 * Setting the pin's pull-up or pull-down.
	 *
	 * The same approach of the MODER is used here.
	 *
	 * 1. Clear the two bits of PUPDR which corresponds to the bit number.
	 * 2. Put the desired value into the targeted PUPDR bits.
	 */
	GPIO_PORTS_ARRAY[a_pinConfig_Ptr->Port]->PUPDR &= ~(0x03UL << (2 * a_pinConfig_Ptr->PinNum));
	GPIO_PORTS_ARRAY[a_pinConfig_Ptr->Port]->PUPDR |= (a_pinConfig_Ptr->PullStatus << (2 * a_pinConfig_Ptr->PinNum));
	
	/*Set output type and output speed in case of output mode*/
	if(a_pinConfig_Ptr->PinMode == GPIO_OUTPUT)
	{
		/*Set output type*/
		GPIO_PORTS_ARRAY[a_pinConfig_Ptr->Port]->OTYPER &= ~(0x01UL << (a_pinConfig_Ptr->PinNum));
		GPIO_PORTS_ARRAY[a_pinConfig_Ptr->Port]->OTYPER |= ((a_pinConfig_Ptr->OutputType) << (a_pinConfig_Ptr->PinNum));
		
		/*Set output speed*/
		GPIO_PORTS_ARRAY[a_pinConfig_Ptr->Port]->OSPEEDR &= ~(0x03UL << (2 * a_pinConfig_Ptr->PinNum));
		GPIO_PORTS_ARRAY[a_pinConfig_Ptr->Port]->OSPEEDR |= (a_pinConfig_Ptr->OutputSpeed << (2 * a_pinConfig_Ptr->PinNum));
	}
	
	/*Set alternate function options in case of alternate mode*/
	else if(a_pinConfig_Ptr->PinMode == GPIO_ALT)
	{
		/*determine low register or high register*/
		uint8 registerNumber = (a_pinConfig_Ptr->PinNum) / 8;
		/*determine pin number refer to low register and high register*/
		uint8 pinNumShift = (a_pinConfig_Ptr->PinNum) % 8;
		
		GPIO_PORTS_ARRAY[a_pinConfig_Ptr->Port]->AFR[registerNumber] &= ~(0x0FUL << (pinNumShift));
		GPIO_PORTS_ARRAY[a_pinConfig_Ptr->Port]->AFR[registerNumber] |= ((a_pinConfig_Ptr->AltFunc) << (pinNumShift * 4));
	}
}


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
void GPIO_setPinValue(Port_Type a_port, PinNum_Type a_pinNum, OutputValue_Type a_value)
{
	GPIO_PORTS_ARRAY[a_port]->BSRR = 0x01UL << (a_pinNum + a_value);
}


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
void GPIO_setPortValue(Port_Type a_port, uint16 a_value)
{
	GPIO_PORTS_ARRAY[a_port]->ODR &= 0xFFFF0000;
	GPIO_PORTS_ARRAY[a_port]->ODR |= (uint32)a_value;
}


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
uint8 GPIO_readPinValue(Port_Type a_port, PinNum_Type a_pinNum)
{
	return (uint8)((GPIO_PORTS_ARRAY[a_port]->IDR >> a_pinNum) & 0x01);
}


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
void GPIO_togglePinValue(Port_Type a_port, PinNum_Type a_pinNum)
{
	GPIO_PORTS_ARRAY[a_port]->ODR ^= 0x01 << a_pinNum;
}


/*-------------------------------------------- End of gpio.c --------------------------------------------*/
