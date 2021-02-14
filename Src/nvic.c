/*
 * nvic.c
 *
 *  Created on: Jan 18, 2021
 *      Author: Mostafa Alaa
 */

#include "std_types.h"
#include "stm32f446xe.h"
#include "nvic.h"
#include "nvic_private.h"


/*
 * Function Name: NVIC_enableIRQ
 *
 * Description: Enables NVIC interrupt for the given IRQn
 *
 * Arguments:
 * 			1.IRQn_Type a_IRQn:
 * 					This argument shall indicate the IRQ number to enable the interrupt to
 *
 * Return:
 * 			void: Returns nothing
 */
void NVIC_enableIRQ(IRQn_Type a_IRQn)
{
	NVIC->ISER[GET_IRQ_REG_NUM(a_IRQn)] = 1 << GET_IRQ_BIT_NUM(a_IRQn);
}


/*
 * Function Name: NVIC_disableIRQ
 *
 * Description: Disables NVIC interrupt for the given IRQn
 *
 * Arguments:
 * 			1.uint8 a_IRQn:
 * 					This argument shall indicate the IRQ number to disable the interrupt to.
 * 					(Check the IRQn_Type structure for eligible values)
 *
 * Return:
 * 			void: Returns nothing
 */
void NVIC_disableIRQ(IRQn_Type a_IRQn)
{
	NVIC->ICER[GET_IRQ_REG_NUM(a_IRQn)] = 1 << GET_IRQ_BIT_NUM(a_IRQn);
}


/*
 * Function Name: NVIC_SetPendingIRQ
 *
 * Description: Sets the pending status of interrupt to 1.
 *
 * Arguments:
 * 			1. IRQn_Type a_IRQn:
 * 					This argument shall indicate the IRQ number to set its pending flag.
 *
 * Return:
 * 			void: Returns nothing
 */
void NVIC_SetPendingIRQ(IRQn_Type a_IRQn)
{
	NVIC->ISPR[GET_IRQ_REG_NUM(a_IRQn)] = 1 << GET_IRQ_BIT_NUM(a_IRQn);
}


/*
 * Function Name: NVIC_clearPendingIRQ
 *
 * Description: Clears the pending status of interrupt to 1.
 *
 * Arguments:
 * 			1. uint8 a_IRQn:
 * 					This argument shall indicate the IRQ number to clear its pending flag.
 * 					(Check the IRQn_Type structure for eligible values)
 *
 * Return:
 * 			void: Returns nothing
 */
void NVIC_clearPendingIRQ(IRQn_Type a_IRQn)
{
	NVIC->ICPR[GET_IRQ_REG_NUM(a_IRQn)] = 1 << GET_IRQ_BIT_NUM(a_IRQn);
}


/*
 * Function Name: NVIC_getPendingIRQ
 *
 * Description: Reads the pending status of interrupt.
 *
 * Arguments:
 * 			1. uint8 a_IRQn:
 * 					This argument shall indicate the IRQ number to get its pending flag.
 * 					(Check the IRQn_Type structure for eligible values)
 *
 * Return:
 * 			uint8: This function returns non-zero value if the pending status is set to 1.
 */
uint8 NVIC_getPendingIRQ(IRQn_Type a_IRQn)
{
	return (uint8)((NVIC->IABR[GET_IRQ_REG_NUM(a_IRQn)] >> GET_IRQ_BIT_NUM(a_IRQn)) & 0x1);
}


/*
 * Function Name: NVIC_setPriority
 *
 * Description: Sets group and sup priorities for a specific IRQ.
 *
 * Arguments:
 * 			1. IRQn_Type a_IRQn:
 * 					This argument shall indicate the IRQ number to enable the interrupt to.
 * 			2. uint8 a_gpPriority:
 * 					This argument shall indicate the group priority for the given IRQ.
 * 			3. uint8 a_subPriority:
 * 					This argument shall indicate the sub priority for the given IRQ.
 *
 * Return:
 * 			void: Returns nothing
 */
void NVIC_setPriority(IRQn_Type a_IRQn, uint8 a_gpPriority, uint8 a_subPriority)
{
	NVIC->IPR[a_IRQn] = GET_IRQ_PRIORITY(a_gpPriority, a_subPriority);
}


/* ----------------------------------- End of nvic.c ----------------------------------- */
