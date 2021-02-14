/*
 * Author:	Mostafa ALaa
 * Layer:	LIB
 * SWC:		STM32F446XX device
 * Version:	1.00
 */

#ifndef STM32F446XE_H_
#define STM32F446XE_H_

/* ----------------------------------------------------------------------------
   -- Core Peripherals
   ---------------------------------------------------------------------------- */
   
/* ----------------------------------------------------------------------------
   -- SysTick
   ---------------------------------------------------------------------------- */

/************************ SysTick base address ************************/
#define SYSTICK_BASE_ADDRESS				0xE000E010UL

/*************** SysTick register definition structure ****************/
typedef struct
{
	volatile uint32 STK_CTRL;				/* SysTick control and status register */
	volatile uint32 STK_LOAD;				/* SysTick reload value register */
	volatile uint32 STK_VAL;				/* SysTick current value register */
	volatile uint32 STK_CALIB;				/* SysTick calibration value register */
	
}SysTick_Type;

/************************* SysTick structure pointer **************************/
#define SYSTICK								((SysTick_Type *)(SYSTICK_BASE_ADDRESS))


/* ----------------------------------------------------------------------------
   -- SCB
   ---------------------------------------------------------------------------- */

/**************************** SCB base address *****************************/
#define SCB_BASE_ADDRESS					0xE000ED00UL

/******************* SCB register definition structure *********************/
typedef struct
{
	volatile uint32 CPUID;					/* CPUID base register */
	volatile uint32 ICSR;					/* Interrupt control and state register */
	volatile uint32 VTOR;					/* Vector table offset register */
	volatile uint32 AIRCR;					/* Application interrupt and reset control register */
	volatile uint32 SCR;					/* System control register */
	volatile uint32 CCR;					/* Configuration and control register */
	volatile uint32 SHPR[3];				/* System handler priority registers */
	volatile uint32 SHCSR;					/* System handler control and state register */
	volatile uint32 CFSR;					/* Configurable fault status register */
	volatile uint32 HFSR;					/* Hard fault status register */
			 uint32 RESERVED0;				
	volatile uint32 MMAR;					/* Memory management fault address register */
	volatile uint32 BFAR;					/* Bus fault address register */
	volatile uint32 AFSR;					/* Auxiliary fault status register */
	
}SCB_Type;

/************************* SysTick structure pointer **************************/
#define SCB									((SCB_Type *)(SCB_BASE_ADDRESS))


/* ----------------------------------------------------------------------------
   -- NVIC
   ---------------------------------------------------------------------------- */

/************************* NVIC base address **************************/
#define NVIC_BASE_ADDRESS					0xE000E100UL

/***************** NVIC register definition structure *****************/
typedef struct
{
	volatile uint32 ISER[8];				/* Interrupt set-enable register */
			 uint32 RESERVED0[24];			
	volatile uint32 ICER[8]; 				/* Interrupt clear-enable register */
			 uint32 RESERVED1[24];			
	volatile uint32 ISPR[8];				/* Interrupt set-pending register */
			 uint32 RESERVED2[24];			
	volatile uint32 ICPR[8];				/* Interrupt clear-pending register */
			 uint32 RESERVED3[24];			
	volatile uint32 IABR[8];				/* Interrupt active bit register */
			 uint32 RESERVED4[56];			
	volatile uint8 IPR[240];				/* Interrupt Priority Registers */

}NVIC_Type;

/******************* NVIC structure pointer **********************/
#define NVIC								((NVIC_Type *)(NVIC_BASE_ADDRESS))


/* ----------------------------------------------------------------------------
   -- Memory mapping
   ---------------------------------------------------------------------------- */

/****************** Memories base addresses ******************/
#define FLASH_BASE_ADDRESS      			0X08000000UL
#define SRAM1_BASE_ADDRESS      			0x20000000UL
#define SRAM2_BASE_ADDRESS      			0x2001C000UL
#define SRAM_BASE_ADDRESS       			SRAM1_BASE_ADDRESS
#define ROM_BASE_ADDRESS        			0x1FFF0000UL

/****************** AHB1 Peripherals base addresses ******************/
#define GPIOA_BASE_ADDRESS      			0x40020000UL
#define GPIOB_BASE_ADDRESS      			0x40020400UL
#define GPIOC_BASE_ADDRESS      			0x40020800UL
#define GPIOD_BASE_ADDRESS      			0x40020C00UL
#define GPIOE_BASE_ADDRESS      			0x40021000UL
#define GPIOF_BASE_ADDRESS      			0x40021400UL
#define GPIOG_BASE_ADDRESS      			0x40021800UL
#define GPIOH_BASE_ADDRESS      			0x40021C00UL
#define RCC_BASE_ADDRESS					0x40023800UL


/****************** APB1 Peripherals base addresses ******************/
#define SPI2_BASE_ADDRESS       			0x40003800UL
#define SPI3_BASE_ADDRESS       			0x40003C00UL
#define USART2_BASE_ADDRESS     			0x40004400UL
#define USART3_BASE_ADDRESS     			0x40004800UL
#define UART4_BASE_ADDRESS      			0x40004C00UL
#define UART5_BASE_ADDRESS      			0x40005000UL
#define I2C1_BASE_ADDRESS       			0x40005400UL
#define I2C2_BASE_ADDRESS       			0x40005800UL
#define I2C3_BASE_ADDRESS       			0x40005C00UL


/****************** APB2 Peripherals base addresses ******************/
#define USART1_BASE_ADDRESS     			0x40011000UL
#define USART6_BASE_ADDRESS     			0x40011400UL
#define SPI1_BASE_ADDRESS       			0x40013000UL
#define SPI4_BASE_ADDRESS       			0x40013400UL
#define SYSCFG_BASE_ADDRESS     			0x40013800UL
#define EXTI_BASE_ADDRESS       			0x40013C00UL


/* ----------------------------------------------------------------------------
   -- RCC
   ---------------------------------------------------------------------------- */
   
/********************** RCC register definition structure **********************/
typedef struct
{
	volatile uint32 CR;						/* RCC clock control register */
	volatile uint32 PLLCFGR;				/* RCC PLL configuration register */
	volatile uint32 CFGR;					/* RCC clock configuration register */
	volatile uint32 CIR;					/* RCC clock interrupt register */
	volatile uint32 AHB1RSTR;				/* RCC AHB1 peripheral reset register */
	volatile uint32 AHB2RSTR;				/* RCC AHB2 peripheral reset register */
	volatile uint32 AHB3RSTR;				/* RCC AHB3 peripheral reset register */
			 uint32 RESERVED0;
	volatile uint32 APB1RSTR;				/* RCC APB1 peripheral reset register */
	volatile uint32 APB2RSTR;				/* RCC APB2 peripheral reset register */
			 uint32 RESERVED1[2];
	volatile uint32 AHB1ENR;				/* RCC AHB1 peripheral clock enable register */
	volatile uint32 AHB2ENR;				/* RCC AHB2 peripheral clock enable register */
	volatile uint32 AHB3ENR;				/* RCC AHB3 peripheral clock enable register */
			 uint32 RESERVED2;
	volatile uint32 APB1ENR;				/* RCC APB1 peripheral clock enable register */
	volatile uint32 APB2ENR;				/* RCC APB2 peripheral clock enable register */
			 uint32 RESERVED3[2];
	volatile uint32 AHB1LPENR;				/* RCC AHB1 peripheral clock enable in low power mode register */
	volatile uint32 AHB2LPENR;				/* RCC AHB2 peripheral clock enable in low power mode register */
	volatile uint32 AHB3LPENR;				/* RCC AHB3 peripheral clock enable in low power mode register */
			 uint32 RESERVED4;
	volatile uint32 APB1LPENR;				/* RCC APB1 peripheral clock enable in low power mode register */
	volatile uint32 APB2LPENR;				/* RCC APB2 peripheral clock enabled in low power mode register */
			 uint32 RESERVED5[2];
	volatile uint32 BDCR;					/* RCC Backup domain control register */
	volatile uint32 CSR;					/* RCC clock control & status register */
			 uint32 RESERVED6[2];
	volatile uint32 SSCGR;					/* RCC spread spectrum clock generation register */
	volatile uint32 PLLI2SCFGR;				/* RCC PLLI2S configuration register */
	volatile uint32 PLLSAICFGR;				/* RCC PLL configuration register */
	volatile uint32 DCKCFGR;				/* RCC dedicated clock configuration register */
	volatile uint32 CKGATENR;				/* RCC clocks gated enable register */
	volatile uint32 DCKCFGR2;				/* RCC dedicated clocks configuration register 2 */
	
}RCC_Type;

/************************* RCC structure pointer ****************************/
#define RCC									((RCC_Type *)(RCC_BASE_ADDRESS))

/**************************** RCC bit fields ********************************/

/* CR bit fields */
/* Internal high-speed clock enable */
#define RCC_CR_HSION_MASK					0x00000001UL
#define RCC_CR_HSION_SHIFT					0
/* Internal high-speed clock ready flag */
#define RCC_CR_HSIRDY_MASK					0x00000002UL		
#define RCC_CR_HSIRDY_SHIFT					1
/* Internal high-speed clock trimming */
#define RCC_CR_HSITRIM_MASK					0x000000F8UL
#define RCC_CR_HSITRIM_SHIFT				3
/* Internal high-speed clock calibration */
#define RCC_CR_HSICAL_MASK					0x0000FF00UL		
#define RCC_CR_HSICAL_SHIFT					8
/* HSE clock enable */
#define RCC_CR_HSEON_MASK					0x00010000UL		
#define RCC_CR_HSEON_SHIFT					16
/* HSE clock ready flag */
#define RCC_CR_HESRDY_MASK					0x00020000UL		
#define RCC_CR_HESRDY_SHIFT					17
/* HSE clock bypass */
#define RCC_CR_HSEBYP_MASK					0x00040000UL		
#define RCC_CR_HSEBYP_SHIFT					18
/* Clock security system enable */
#define RCC_CR_CSSON_MASK					0x00080000UL		
#define RCC_CR_CSSON_SHIFT					19
/* Main PLL (PLL) enable */
#define RCC_CR_PLLON_MASK					0x01000000UL		
#define RCC_CR_PLLON_SHIFT					24
/* Main PLL (PLL) clock ready flag */
#define RCC_CR_PLLRDY_MASK					0x02000000UL		
#define RCC_CR_PLLRDY_SHIFT					25
/* PLLI2S enable */
#define RCC_CR_PLLI2SON_MASK				0x04000000UL		
#define RCC_CR_PLLI2SON_SHIFT				26
/* PLLI2s clock ready fag */
#define RCC_CR_PLLI2SRDY_MASK				0x08000000UL		
#define RCC_CR_PLLI2SRDY_SHIFT				27
/* PLLSAI enable */
#define RCC_CR_PLLSAION_MASK				0x10000000UL		
#define RCC_CR_PLLSAION_SHIFT				28
/* PLLSAI clock ready flag */
#define RCC_CR_PLLSAIRDY_MASK				0x20000000UL		
#define RCC_CR_PLLSAIRDY_SHIFT				29


/* CFGR bit fields */
/* System clock switch */
#define RCC_CFGR_SW_MASK						0x00000003UL
#define RCC_CFGR_SW_SHIFT						0
/* System clock switch status */
#define RCC_CFGR_SWS_MASK						0x0000000CUL	
#define RCC_CFGR_SWS_SHIFT						2
/* AHB prescaler */
#define RCC_CFGR_HPRE_MASK						0x000000F0UL		
#define RCC_CFGR_HPRE_SHIFT						4
/* APB Low speed prescaler (APB1) */
#define RCC_CFGR_PPRE1_MASK						0x00001C00UL		
#define RCC_CFGR_PPRE1_SHIFT					10
/* APB high-speed prescaler (APB2) */
#define RCC_CFGR_PPRE2_MASK						0x0000E000UL		
#define RCC_CFGR_PPRE2_SHIFT					13
/* HSE division factor for RTC clock */
#define RCC_CFGR_RTCPRE_MASK					0x001F0000UL		
#define RCC_CFGR_RTCPRE_SHIFT					16
/* Microcontroller clock output 1 */
#define RCC_CFGR_MCO1_MASK						0x00600000UL		
#define RCC_CFGR_MCO1_SHIFT						21
/* MCO1 prescaler */
#define RCC_CFGR_MCO1PRE_MASK					0x07000000UL		
#define RCC_CFGR_MCO1PRE_SHIFT					24
/* MCO2 prescaler */
#define RCC_CFGR_MCO2PRE_MASK					0x38000000UL		
#define RCC_CFGR_MCO2PRE_SHIFT					27
/* Microcontroller clock output 2 */
#define RCC_CFGR_MCO2_MASK						0xC0000000UL		
#define RCC_CFGR_MCO2_SHIFT						30


/* ----------------------------------------------------------------------------
   -- GPIOs
   ---------------------------------------------------------------------------- */

/***************** GPIO register definition structure ***************/
typedef struct
{
	volatile uint32 MODER;					/* GPIO port mode register */
	volatile uint32 OTYPER;					/* GPIO port output type register */
	volatile uint32 OSPEEDR;				/* GPIO port output speed register */
	volatile uint32 PUPDR;					/* GPIO port pull-up/pull-down register */
	volatile uint32 IDR;					/* GPIO port input data register */
	volatile uint32 ODR;					/* GPIO port output data register */
	volatile uint32 BSRR;					/* GPIO port bit set/reset register */
	volatile uint32 LCKR;					/* GPIO port configuration lock register */
	volatile uint32 AFR[2];					/* ARF[0]: GPIO alternate function low register */
											/* AFR[1]: GPIO alternate function high register */

}GPIO_Type;


/********************* GPIO bit fields ***********************/

/* MODER bit fields */
#define GPIO_MODER_MODER0_MASK				0x00000003UL
#define GPIO_MODER_MODER0_SHIFT				0
#define GPIO_MODER_MODER1_MASK				0x0000000CUL
#define GPIO_MODER_MODER1_SHIFT				2
#define GPIO_MODER_MODER2_MASK				0x00000030UL
#define GPIO_MODER_MODER2_SHIFT				4
#define GPIO_MODER_MODER3_MASK				0x000000C0UL
#define GPIO_MODER_MODER3_SHIFT				6
#define GPIO_MODER_MODER4_MASK				0x00000300UL
#define GPIO_MODER_MODER4_SHIFT				8
#define GPIO_MODER_MODER5_MASK				0x00000C00UL
#define GPIO_MODER_MODER5_SHIFT				10
#define GPIO_MODER_MODER6_MASK				0x00003000UL
#define GPIO_MODER_MODER6_SHIFT				12
#define GPIO_MODER_MODER7_MASK				0x0000C000UL
#define GPIO_MODER_MODER7_SHIFT				14
#define GPIO_MODER_MODER8_MASK				0x00030000UL
#define GPIO_MODER_MODER8_SHIFT				16
#define GPIO_MODER_MODER9_MASK				0x000C0000UL
#define GPIO_MODER_MODER9_SHIFT				18
#define GPIO_MODER_MODER10_MASK				0x00300000UL
#define GPIO_MODER_MODER10_SHIFT			20
#define GPIO_MODER_MODER11_MASK				0x00C00000UL
#define GPIO_MODER_MODER11_SHIFT			22
#define GPIO_MODER_MODER12_MASK				0x03000000UL
#define GPIO_MODER_MODER12_SHIFT			24
#define GPIO_MODER_MODER13_MASK				0x0C000000UL
#define GPIO_MODER_MODER13_SHIFT			26
#define GPIO_MODER_MODER14_MASK				0x30000000UL
#define GPIO_MODER_MODER14_SHIFT			28
#define GPIO_MODER_MODER15_MASK				0xC0000000UL
#define GPIO_MODER_MODER15_SHIFT			30

/* OTYPER bit fields */
#define GPIO_OTYPER_OT0_MASK				0x00000001UL
#define GPIO_OTYPER_OT0_SHIFT				0
#define GPIO_OTYPER_OT1_MASK				0x00000002UL
#define GPIO_OTYPER_OT1_SHIFT				1
#define GPIO_OTYPER_OT2_MASK				0x00000004UL
#define GPIO_OTYPER_OT2_SHIFT				2
#define GPIO_OTYPER_OT3_MASK				0x00000008UL
#define GPIO_OTYPER_OT3_SHIFT				3
#define GPIO_OTYPER_OT4_MASK				0x00000010UL
#define GPIO_OTYPER_OT4_SHIFT				4
#define GPIO_OTYPER_OT5_MASK				0x00000020UL
#define GPIO_OTYPER_OT5_SHIFT				5
#define GPIO_OTYPER_OT6_MASK				0x00000040UL
#define GPIO_OTYPER_OT6_SHIFT				6
#define GPIO_OTYPER_OT7_MASK				0x00000080UL
#define GPIO_OTYPER_OT7_SHIFT				7
#define GPIO_OTYPER_OT8_MASK				0x00000100UL
#define GPIO_OTYPER_OT8_SHIFT				8
#define GPIO_OTYPER_OT9_MASK				0x00000200UL
#define GPIO_OTYPER_OT9_SHIFT				9
#define GPIO_OTYPER_OT10_MASK				0x00000400UL
#define GPIO_OTYPER_OT10_SHIFT				10
#define GPIO_OTYPER_OT11_MASK				0x00000800UL
#define GPIO_OTYPER_OT11_SHIFT				11
#define GPIO_OTYPER_OT12_MASK				0x00001000UL
#define GPIO_OTYPER_OT12_SHIFT				12
#define GPIO_OTYPER_OT13_MASK				0x00002000UL
#define GPIO_OTYPER_OT13_SHIFT				13
#define GPIO_OTYPER_OT14_MASK				0x00004000UL
#define GPIO_OTYPER_OT14_SHIFT				14
#define GPIO_OTYPER_OT15_MASK				0x00008000UL
#define GPIO_OTYPER_OT15_SHIFT				15

/* OSPEEDR bit fields */
#define GPIO_OSPEEDR_OSPEEDR0_MASK			0x00000003UL
#define GPIO_OSPEEDR_OSPEEDR0_SHIFT			0
#define GPIO_OSPEEDR_OSPEEDR1_MASK			0x0000000CUL
#define GPIO_OSPEEDR_OSPEEDR1_SHIFT			2
#define GPIO_OSPEEDR_OSPEEDR2_MASK			0x00000030UL
#define GPIO_OSPEEDR_OSPEEDR2_SHIFT			4
#define GPIO_OSPEEDR_OSPEEDR3_MASK			0x000000C0UL
#define GPIO_OSPEEDR_OSPEEDR3_SHIFT			6
#define GPIO_OSPEEDR_OSPEEDR4_MASK			0x00000300UL
#define GPIO_OSPEEDR_OSPEEDR4_SHIFT			8
#define GPIO_OSPEEDR_OSPEEDR5_MASK			0x00000C00UL
#define GPIO_OSPEEDR_OSPEEDR5_SHIFT			10
#define GPIO_OSPEEDR_OSPEEDR6_MASK			0x00003000UL
#define GPIO_OSPEEDR_OSPEEDR6_SHIFT			12
#define GPIO_OSPEEDR_OSPEEDR7_MASK			0x0000C000UL
#define GPIO_OSPEEDR_OSPEEDR7_SHIFT			14
#define GPIO_OSPEEDR_OSPEEDR8_MASK			0x00030000UL
#define GPIO_OSPEEDR_OSPEEDR8_SHIFT			16
#define GPIO_OSPEEDR_OSPEEDR9_MASK			0x000C0000UL
#define GPIO_OSPEEDR_OSPEEDR9_SHIFT			18
#define GPIO_OSPEEDR_OSPEEDR10_MASK			0x00300000UL
#define GPIO_OSPEEDR_OSPEEDR10_SHIFT		20
#define GPIO_OSPEEDR_OSPEEDR11_MASK			0x00C00000UL
#define GPIO_OSPEEDR_OSPEEDR11_SHIFT		22
#define GPIO_OSPEEDR_OSPEEDR12_MASK			0x03000000UL
#define GPIO_OSPEEDR_OSPEEDR12_SHIFT		24
#define GPIO_OSPEEDR_OSPEEDR13_MASK			0x0C000000UL
#define GPIO_OSPEEDR_OSPEEDR13_SHIFT		26
#define GPIO_OSPEEDR_OSPEEDR14_MASK			0x30000000UL
#define GPIO_OSPEEDR_OSPEEDR14_SHIFT		28
#define GPIO_OSPEEDR_OSPEEDR15_MASK			0xC0000000UL
#define GPIO_OSPEEDR_OSPEEDR15_SHIFT		30

/* PUPDR bit fields */
#define GPIO_PUPDR_PUPDR0_MASK				0x00000003UL
#define GPIO_PUPDR_PUPDR0_SHIFT				0
#define GPIO_PUPDR_PUPDR1_MASK				0x0000000CUL
#define GPIO_PUPDR_PUPDR1_SHIFT				2
#define GPIO_PUPDR_PUPDR2_MASK				0x00000030UL
#define GPIO_PUPDR_PUPDR2_SHIFT				4
#define GPIO_PUPDR_PUPDR3_MASK				0x000000C0UL
#define GPIO_PUPDR_PUPDR3_SHIFT				6
#define GPIO_PUPDR_PUPDR4_MASK				0x00000300UL
#define GPIO_PUPDR_PUPDR4_SHIFT				8
#define GPIO_PUPDR_PUPDR5_MASK				0x00000C00UL
#define GPIO_PUPDR_PUPDR5_SHIFT				10
#define GPIO_PUPDR_PUPDR6_MASK				0x00003000UL
#define GPIO_PUPDR_PUPDR6_SHIFT				12
#define GPIO_PUPDR_PUPDR7_MASK				0x0000C000UL
#define GPIO_PUPDR_PUPDR7_SHIFT				14
#define GPIO_PUPDR_PUPDR8_MASK				0x00030000UL
#define GPIO_PUPDR_PUPDR8_SHIFT				16
#define GPIO_PUPDR_PUPDR9_MASK				0x000C0000UL
#define GPIO_PUPDR_PUPDR9_SHIFT				18
#define GPIO_PUPDR_PUPDR10_MASK				0x00300000UL
#define GPIO_PUPDR_PUPDR10_SHIFT			20
#define GPIO_PUPDR_PUPDR11_MASK				0x00C00000UL
#define GPIO_PUPDR_PUPDR11_SHIFT			22
#define GPIO_PUPDR_PUPDR12_MASK				0x03000000UL
#define GPIO_PUPDR_PUPDR12_SHIFT			24
#define GPIO_PUPDR_PUPDR13_MASK				0x0C000000UL
#define GPIO_PUPDR_PUPDR13_SHIFT			26
#define GPIO_PUPDR_PUPDR14_MASK				0x30000000UL
#define GPIO_PUPDR_PUPDR14_SHIFT			28
#define GPIO_PUPDR_PUPDR15_MASK				0xC0000000UL
#define GPIO_PUPDR_PUPDR15_SHIFT			30

/* IDR bit fields */
#define GPIO_IDR_IDR0_MASK					0x00000001UL
#define GPIO_IDR_IDR0_SHIFT					0
#define GPIO_IDR_IDR1_MASK					0x00000002UL
#define GPIO_IDR_IDR1_SHIFT					1
#define GPIO_IDR_IDR2_MASK					0x00000004UL
#define GPIO_IDR_IDR2_SHIFT					2
#define GPIO_IDR_IDR3_MASK					0x00000008UL
#define GPIO_IDR_IDR3_SHIFT					3
#define GPIO_IDR_IDR4_MASK					0x00000010UL
#define GPIO_IDR_IDR4_SHIFT					4
#define GPIO_IDR_IDR5_MASK					0x00000020UL
#define GPIO_IDR_IDR5_SHIFT					5
#define GPIO_IDR_IDR6_MASK					0x00000040UL
#define GPIO_IDR_IDR6_SHIFT					6
#define GPIO_IDR_IDR7_MASK					0x00000080UL
#define GPIO_IDR_IDR7_SHIFT					7
#define GPIO_IDR_IDR8_MASK					0x00000100UL
#define GPIO_IDR_IDR8_SHIFT					8
#define GPIO_IDR_IDR9_MASK					0x00000200UL
#define GPIO_IDR_IDR9_SHIFT					9
#define GPIO_IDR_IDR10_MASK					0x00000400UL
#define GPIO_IDR_IDR10_SHIFT				10
#define GPIO_IDR_IDR11_MASK					0x00000800UL
#define GPIO_IDR_IDR11_SHIFT				11
#define GPIO_IDR_IDR12_MASK					0x00001000UL
#define GPIO_IDR_IDR12_SHIFT				12
#define GPIO_IDR_IDR13_MASK					0x00002000UL
#define GPIO_IDR_IDR13_SHIFT				13
#define GPIO_IDR_IDR14_MASK					0x00004000UL
#define GPIO_IDR_IDR14_SHIFT				14
#define GPIO_IDR_IDR15_MASK					0x00008000UL
#define GPIO_IDR_IDR15_SHIFT				15

/* ODR bit fields */
#define GPIO_ODR_ODR0_MASK					0x00000001UL
#define GPIO_ODR_ODR0_SHIFT					0
#define GPIO_ODR_ODR1_MASK					0x00000002UL
#define GPIO_ODR_ODR1_SHIFT					1
#define GPIO_ODR_ODR2_MASK					0x00000004UL
#define GPIO_ODR_ODR2_SHIFT					2
#define GPIO_ODR_ODR3_MASK					0x00000008UL
#define GPIO_ODR_ODR3_SHIFT					3
#define GPIO_ODR_ODR4_MASK					0x00000010UL
#define GPIO_ODR_ODR4_SHIFT					4
#define GPIO_ODR_ODR5_MASK					0x00000020UL
#define GPIO_ODR_ODR5_SHIFT					5
#define GPIO_ODR_ODR6_MASK					0x00000040UL
#define GPIO_ODR_ODR6_SHIFT					6
#define GPIO_ODR_ODR7_MASK					0x00000080UL
#define GPIO_ODR_ODR7_SHIFT					7
#define GPIO_ODR_ODR8_MASK					0x00000100UL
#define GPIO_ODR_ODR8_SHIFT					8
#define GPIO_ODR_ODR9_MASK					0x00000200UL
#define GPIO_ODR_ODR9_SHIFT					9
#define GPIO_ODR_ODR10_MASK					0x00000400UL
#define GPIO_ODR_ODR10_SHIFT				10
#define GPIO_ODR_ODR11_MASK					0x00000800UL
#define GPIO_ODR_ODR11_SHIFT				11
#define GPIO_ODR_ODR12_MASK					0x00001000UL
#define GPIO_ODR_ODR12_SHIFT				12
#define GPIO_ODR_ODR13_MASK					0x00002000UL
#define GPIO_ODR_ODR13_SHIFT				13
#define GPIO_ODR_ODR14_MASK					0x00004000UL
#define GPIO_ODR_ODR14_SHIFT				14
#define GPIO_ODR_ODR15_MASK					0x00008000UL
#define GPIO_ODR_ODR15_SHIFT				15

/* BSSR bit fields */
/*TODO*/

/* LCKR bit fields */
#define GPIO_LCKR_LCKK0_MASK				0x00000001UL
#define GPIO_LCKR_LCKK0_SHIFT				0
#define GPIO_LCKR_LCKK1_MASK				0x00000002UL
#define GPIO_LCKR_LCKK1_SHIFT				1
#define GPIO_LCKR_LCKK2_MASK				0x00000004UL
#define GPIO_LCKR_LCKK2_SHIFT				2
#define GPIO_LCKR_LCKK3_MASK				0x00000008UL
#define GPIO_LCKR_LCKK3_SHIFT				3
#define GPIO_LCKR_LCKK4_MASK				0x00000010UL
#define GPIO_LCKR_LCKK4_SHIFT				4
#define GPIO_LCKR_LCKK5_MASK				0x00000020UL
#define GPIO_LCKR_LCKK5_SHIFT				5
#define GPIO_LCKR_LCKK6_MASK				0x00000040UL
#define GPIO_LCKR_LCKK6_SHIFT				6
#define GPIO_LCKR_LCKK7_MASK				0x00000080UL
#define GPIO_LCKR_LCKK7_SHIFT				7
#define GPIO_LCKR_LCKK8_MASK				0x00000100UL
#define GPIO_LCKR_LCKK8_SHIFT				8
#define GPIO_LCKR_LCKK9_MASK				0x00000200UL
#define GPIO_LCKR_LCKK9_SHIFT				9
#define GPIO_LCKR_LCKK10_MASK				0x00000400UL
#define GPIO_LCKR_LCKK10_SHIFT				10
#define GPIO_LCKR_LCKK11_MASK				0x00000800UL
#define GPIO_LCKR_LCKK11_SHIFT				11
#define GPIO_LCKR_LCKK12_MASK				0x00001000UL
#define GPIO_LCKR_LCKK12_SHIFT				12
#define GPIO_LCKR_LCKK13_MASK				0x00002000UL
#define GPIO_LCKR_LCKK13_SHIFT				13
#define GPIO_LCKR_LCKK14_MASK				0x00004000UL
#define GPIO_LCKR_LCKK14_SHIFT				14
#define GPIO_LCKR_LCKK15_MASK				0x00008000UL
#define GPIO_LCKR_LCKK15_SHIFT				15
#define GPIO_LCKR_LCKK16_MASK				0x00010000UL
#define GPIO_LCKR_LCKK16_SHIFT				16

/* AFRL bit fields */
/*TODO*/

/* AFRH bit fields */
/*TODO*/



/******************* GPIO structure pointers ******************/
#define GPIOA								((GPIO_Type *)(GPIOA_BASE_ADDRESS))
#define GPIOB								((GPIO_Type *)(GPIOB_BASE_ADDRESS))
#define GPIOC								((GPIO_Type *)(GPIOC_BASE_ADDRESS))
#define GPIOD								((GPIO_Type *)(GPIOD_BASE_ADDRESS))
#define GPIOE								((GPIO_Type *)(GPIOE_BASE_ADDRESS))
#define GPIOF								((GPIO_Type *)(GPIOF_BASE_ADDRESS))
#define GPIOG								((GPIO_Type *)(GPIOG_BASE_ADDRESS))
#define GPIOH								((GPIO_Type *)(GPIOH_BASE_ADDRESS))


/* ----------------------------------------------------------------------------
   -- SYSCFG
   ---------------------------------------------------------------------------- */

/********************** SYSCFG register definition structure ********************/
typedef struct
{
	volatile uint32 MEMRMP;					/* SYSCFG memory remap register */
	volatile uint32 PMC;					/* SYSCFG peripheral mode configuration register */
	volatile uint32 EXTICR[4];				/* SYSCFG external interrupt configuration register 1 */
											/* SYSCFG external interrupt configuration register 2 */
											/* SYSCFG external interrupt configuration register 3 */
											/* SYSCFG external interrupt configuration register 4 */
			 uint32 RESERVED0[2];
	volatile uint32 CMPCR;					/* Compensation cell control register */
			 uint32 RESERVED1[2];
	volatile uint32 CFGR;					/* SYSCFG configuration register */
	
}SYSCFG_Type;

/*************************** SYSCFG structure pointer *************************/
#define SYSCFG								((SYSCFG_Type *)(SYSCFG_BASE_ADDRESS))


/* ----------------------------------------------------------------------------
   -- External interrupt/event controller (EXTI)
   ---------------------------------------------------------------------------- */

/*********************** EXTI register definition structure *********************/
typedef struct
{
	volatile uint32 IMR;					/* Interrupt mask register */
	volatile uint32 EMR;					/* Event mask register */
	volatile uint32 RTSR;					/* Rising trigger selection register */
	volatile uint32 FTSR;					/* Falling trigger selection register */
	volatile uint32 SWIER;					/* Software interrupt event register */
	volatile uint32 PR;						/* Pending register */
	
}EXTI_Type;

/***************************** EXTI structure pointer ***************************/
#define EXTI								((EXTI_Type *)(EXTI_BASE_ADDRESS))


#endif /* STM32F446XE_H_ */
