/*
 * nvic.h
 *
 *  Created on: Jan 18, 2021
 *      Author: Mostafa Alaa
 */

#ifndef NVIC_H_
#define NVIC_H_


/* ---------------------------------------- ENUMS ---------------------------------------- */

/*
 * Enum Name: IRQn_Type
 *
 * Enum Description:
 * This enum is responsible for providing easier interface with IRQ numbers by mapping the
 * numbers to the vector table acronyms of STM32F446xx.
 */
typedef enum
{
	WWDG_IRQ,              			/* Window Watchdog interrupt                                          */
  	PVD_IRQ,               			/* PVD through EXTI line detection interrupt                          */
  	TAMP_STAMP_IRQ,        			/* Tamper and TimeStamp interrupts through the EXTI line              */
  	RTC_WKUP_IRQ,          			/* RTC Wakeup interrupt through the EXTI line                         */
  	FLASH_IRQ,             			/* Flash global interrupt                                             */
  	RCC_IRQ,               			/* RCC global interrupt                                               */
  	EXTI0_IRQ,             			/* EXTI Line0 interrupt                                               */
  	EXTI1_IRQ,             			/* EXTI Line1 interrupt                                               */
  	EXTI2_IRQ,             			/* EXTI Line2 interrupt                                               */
  	EXTI3_IRQ,             			/* EXTI Line3 interrupt                                               */
  	EXTI4_IRQ,             			/* EXTI Line4 interrupt                                               */
  	DMA1_Stream0_IRQ,      			/* DMA1 Stream0 global interrupt                                      */
  	DMA1_Stream1_IRQ,      			/* DMA1 Stream1 global interrupt                                      */
  	DMA1_Stream2_IRQ,      			/* DMA1 Stream2 global interrupt                                      */
  	DMA1_Stream3_IRQ,      			/* DMA1 Stream3 global interrupt                                      */
  	DMA1_Stream4_IRQ,      			/* DMA1 Stream4 global interrupt                                      */
  	DMA1_Stream5_IRQ,      			/* DMA1 Stream5 global interrupt                                      */
  	DMA1_Stream6_IRQ,      			/* DMA1 Stream6 global interrupt                                      */
  	ADC_IRQ,               			/* ADC1 global interrupt                                              */
  	CAN1_TX_IRQ,           			/* CAN1 TX interrupts                                                 */
  	CAN1_RX0_IRQ,          			/* CAN1 RX0 interrupts                                                */
  	CAN1_RX1_IRQ,          			/* CAN1 RX1 interrupts                                                */
  	CAN1_SCE_IRQ,          			/* CAN1 SCE interrupt                                                 */
  	EXTI9_5_IRQ,           			/* EXTI Line[9:5] interrupts                                          */
  	TIM1_BRK_TIM9_IRQ,     			/* TIM1 Break interrupt and TIM9 global interrupt                     */
  	TIM1_UP_TIM10_IRQ,     			/* TIM1 Update interrupt and TIM10 global interrupt                   */
  	TIM1_TRG_COM_TIM11_IRQ,			/* TIM1 Trigger and Commutation interrupts and TIM11 global interrupt */
  	TIM1_CC_IRQ,           			/* TIM1 Capture Compare interrupt                                     */
  	TIM2_IRQ,              			/* TIM2 global interrupt                                              */
  	TIM3_IRQ,              			/* TIM3 global interrupt                                              */
  	TIM4_IRQ,              			/* TIM4 global interrupt                                              */
  	I2C1_EV_IRQ,           			/* I2C1 event interrupt                                               */
  	I2C1_ER_IRQ,           			/* I2C1 error interrupt                                               */
  	I2C2_EV_IRQ,           			/* I2C2 event interrupt                                               */
  	I2C2_ER_IRQ,           			/* I2C2 error interrupt                                               */
  	SPI1_IRQ,              			/* SPI1 global interrupt                                              */
  	SPI2_IRQ,              			/* SPI2 global interrupt                                              */
  	USART1_IRQ,            			/* USART1 global interrupt                                            */
  	USART2_IRQ,            			/* USART2 global interrupt                                            */
  	USART3_IRQ,            			/* USART3 global interrupt                                            */
  	EXTI15_10_IRQ,         			/* EXTI Line[15:10] interrupts                                        */
  	RTC_Alarm_IRQ,         			/* RTC Alarms (A and B) through EXTI line interrupt                   */
  	OTG_FS_WKUP_IRQ,       			/* USB On-The-Go FS Wakeup through EXTI line interrupt                */
  	TIM8_BRK_TIM12_IRQ,    			/* TIM8 Break interrupt and TIM12 global interrupt                    */
  	TIM8_UP_TIM13_IRQ,     			/* TIM8 Update interrupt and TIM13 global interrupt                   */
  	TIM8_TRG_COM_TIM14_IRQ,			/* TIM8 Trigger and Commutation interrupts and TIM14 global interrupt */
  	TIM8_CC_IRQ,           			/* TIM8 Capture Compare interrupt                                     */
  	DMA1_Stream7_IRQ,      			/* DMA1 Stream7 global interrupt                                      */
  	FMC_IRQ,               			/* FMC global interrupt                                               */
  	SDIO_IRQ,              			/* SDIO global interrupt                                              */
  	TIM5_IRQ,              			/* TIM5 global interrupt                                              */
  	SPI3_IRQ,              			/* SPI3 global interrupt                                              */
  	UART4_IRQ,             			/* UART4 global interrupt                                             */
  	UART5_IRQ,             			/* UART5 global interrupt                                             */
  	TIM6_DAC_IRQ,          			/* TIM6 global interrupt_IRQ, DAC1 and DAC2 underrun error interrupt      */
  	TIM7_IRQ,              			/* TIM7 global interrupt                                              */
  	DMA2_Stream0_IRQ,      			/* DMA2 Stream0 global interrupt                                      */
  	DMA2_Stream1_IRQ,      			/* DMA2 Stream1 global interrupt                                      */
  	DMA2_Stream2_IRQ,      			/* DMA2 Stream2 global interrupt                                      */
  	DMA2_Stream3_IRQ,      			/* DMA2 Stream3 global interrupt                                      */
  	DMA2_Stream4_IRQ,      			/* DMA2 Stream4 global interrupt                                      */
  	CAN2_TX_IRQ = 63,           	/* CAN2 TX interrupts                                                 */
  	CAN2_RX0_IRQ,          			/* CAN2 RX0 interrupts                                                */
  	CAN2_RX1_IRQ,          			/* CAN2 RX1 interrupts                                                */
  	CAN2_SCE_IRQ,          			/* CAN2 SCE interrupt                                                 */
  	OTG_FS_IRQ,            			/* USB On The Go FS global interrupt                                  */
  	DMA2_Stream5_IRQ,      			/* DMA2 Stream5 global interrupt                                      */
  	DMA2_Stream6_IRQ,      			/* DMA2 Stream6 global interrupt                                      */
  	DMA2_Stream7_IRQ,      			/* DMA2 Stream7 global interrupt                                      */
  	USART6_IRQ,            			/* USART6 global interrupt                                            */
  	I2C3_EV_IRQ,           			/* I2C3 event interrupt                                               */
  	I2C3_ER_IRQ,           			/* I2C3 error interrupt                                               */
  	OTG_HS_EP1_OUT_IRQ,    			/* USB On The Go HS End Point 1 Out                                   */
  	OTG_HS_EP1_IN_IRQ,     			/* USB On The Go HS End Point 1 In                                    */
  	OTG_HS_WKUP_IRQ,       			/* USB On The Go HS Wakeup                                            */
  	OTG_HS_IRQ,            			/* USB On The Go HS global interrupt                                  */
  	DCMI_IRQ,              			/* DCMI global interrupt                                              */
  	FPU_IRQ = 81,               	/* Floating point unit interrupt                                      */
  	SPI4_IRQ = 84,          		/* SPI 4 global interrupt                                             */
  	SAI1_IRQ = 87,             		/* SAI1 global interrupt                                              */
  	SAI2_IRQ = 91,              	/* SAI2 global interrupt                                              */
  	QuadSPI_IRQ,           			/* QuadSPI global interrupt                                           */
  	HDMI_CEC_IRQ,          			/* HDMI-CEC global interrupt                                          */
  	SPDIF_Rx_IRQ,          			/* SPDIF-Rx global interrupt                                          */
  	FMPI2C1_IRQ,           			/* FMPI2C1 event interrupt                                            */
  	FMPI2C1_error_IRQ,     			/* FMPI2C1 error interrupt                                            */

}IRQn_Type;


/* -------------------------------- FUNCTION DECLERATIONS -------------------------------- */

/*
 * Function Name: NVIC_enableIRQ
 *
 * Description: Enables NVIC interrupt for the given IRQn
 *
 * Arguments:
 * 			1.uint8 a_IRQn:
 * 					This argument shall indicate the IRQ number to enable the interrupt to.
 * 					(Check the IRQn_Type structure for eligible values)
 *
 * Return:
 * 			void: Returns nothing
 */
void NVIC_enableIRQ(IRQn_Type a_IRQn);


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
void NVIC_disableIRQ(IRQn_Type a_IRQn);


/*
 * Function Name: NVIC_SetPendingIRQ
 *
 * Description: Sets the pending status of interrupt to 1.
 *
 * Arguments:
 * 			1. uint8 a_IRQn:
 * 					This argument shall indicate the IRQ number to set its pending flag.
 * 					(Check the IRQn_Type structure for eligible values)
 *
 * Return:
 * 			void: Returns nothing
 */
void NVIC_SetPendingIRQ(IRQn_Type a_IRQn);


/*
 * Function Name: NVIC_clearPendingIRQ
 *
 * Description: Clears the pending status of interrupt.
 *
 * Arguments:
 * 			1. uint8 a_IRQn:
 * 					This argument shall indicate the IRQ number to clear its pending flag.
 * 					(Check the IRQn_Type structure for eligible values)
 *
 * Return:
 * 			void: Returns nothing
 */
void NVIC_clearPendingIRQ(IRQn_Type a_IRQn);


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
uint8 NVIC_getPendingIRQ(IRQn_Type a_IRQn);


/*
 * Function Name: NVIC_setPriority
 *
 * Description: Sets group and sub priorities for a specific IRQ.
 *
 * Arguments:
 * 			1. IRQn_Type a_IRQn:
 * 					This argument shall indicate the IRQ number to enable the interrupt to.
 * 					(Check the IRQn_Type structure for eligible values)
 * 			2. uint8 a_gpPriority:
 * 					This argument shall indicate the group priority for the given IRQ.
 * 					Note that eligible values are [0, 1, 2, 3]. (Only the first three LSB
 * 					are taken)
 * 			3. uint8 a_subPriority:
 * 					This argument shall indicate the sub priority for the given IRQ.
 * 					Note that eligible values are [0, 1, 2, 3]. (Only the first three LSB
 * 					are taken)
 *
 * Return:
 * 			void: Returns nothing
 */
void NVIC_setPriority(IRQn_Type a_IRQn, uint8 a_gpPriority, uint8 a_subPriority);


#endif /* NVIC_H_ */
