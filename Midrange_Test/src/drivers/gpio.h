#ifndef GPIO_H_
#define GPIO_H_

#include "DataTypes.h"

#define KICK0R_UNLOCK      (0x83E70B13)
#define KICK1R_UNLOCK      (0x95A4F1E0)

#define KICK0R_LOCK      (0x00000000)
#define KICK1R_LOCK      (0x00000000)


#define EVEN_P0  0
#define EVEN_P1  1
#define EVEN_P2  2
#define EVEN_P3  3
#define EVEN_P4  4
#define EVEN_P5  5
#define EVEN_P6  6
#define EVEN_P7  7
#define EVEN_P8  8
#define EVEN_P9  9
#define EVEN_P10 10
#define EVEN_P11 11
#define EVEN_P12 12
#define EVEN_P13 13
#define EVEN_P14 14
#define EVEN_P15 15
#define ODD_P0  16
#define ODD_P1  17
#define ODD_P2  18
#define ODD_P3  19
#define ODD_P4  20
#define ODD_P5  21
#define ODD_P6  22
#define ODD_P7  23
#define ODD_P8  24
#define ODD_P9  25
#define ODD_P10 26
#define ODD_P11 27
#define ODD_P12 28
#define ODD_P13 29
#define ODD_P14 30
#define ODD_P15 31


#define NUM_GPIO_PINS			16
#define NUM_GPIO_BANKS			9

#define PINMUX_MASK				0x0000000F
#define PINMUX_SET_PIN_AS_GPIO	0x00000008
#define PINMUX_BASE				(Uint32*)0x01C14120

#define PINMUX0_ADDR	( PINMUX_BASE + 0 )
#define PINMUX1_ADDR	( PINMUX_BASE + 1 )
#define PINMUX2_ADDR	( PINMUX_BASE + 2 )
#define PINMUX3_ADDR	( PINMUX_BASE + 3 )
#define PINMUX4_ADDR	( PINMUX_BASE + 4 )
#define PINMUX5_ADDR	( PINMUX_BASE + 5 )
#define PINMUX6_ADDR	( PINMUX_BASE + 6 )
#define PINMUX7_ADDR	( PINMUX_BASE + 7 )
#define PINMUX8_ADDR	( PINMUX_BASE + 8 )
#define PINMUX9_ADDR	( PINMUX_BASE + 9 )
#define PINMUX10_ADDR	( PINMUX_BASE + 10 )
#define PINMUX11_ADDR	( PINMUX_BASE + 11 )
#define PINMUX12_ADDR	( PINMUX_BASE + 12 )
#define PINMUX13_ADDR	( PINMUX_BASE + 13 )
#define PINMUX14_ADDR	( PINMUX_BASE + 14 )
#define PINMUX15_ADDR	( PINMUX_BASE + 15 )
#define PINMUX16_ADDR	( PINMUX_BASE + 16 )
#define PINMUX17_ADDR	( PINMUX_BASE + 17 )
#define PINMUX18_ADDR	( PINMUX_BASE + 18 )
#define PINMUX19_ADDR	( PINMUX_BASE + 19 )

typedef struct GPIO_PINMUX_DESCRIPTOR_s
{
	volatile uint32*	pinmux;
	uint32			shift; 
}GPIO_PINMUX_DESCRIPTOR;


typedef enum
{
	BANK0 = 0,
	BANK1 = 1,
	BANK2 = 2,
	BANK3 = 3,
	BANK4 = 4,
	BANK5 = 5,
	BANK6 = 6,
	BANK7 = 7,
	BANK8 = 8,							// Unmapped bank. Verify datasheet before using
	TOTAL_NUMBER_OF_BANKS = NUM_GPIO_BANKS
}GPIO_BANK_NUMBER;

typedef enum
{
	PIN0 = 0,
	PIN1 = 1,
	PIN2 = 2,
	PIN3 = 3,
	PIN4 = 4,
	PIN5 = 5,
	PIN6 = 6,
	PIN7 = 7,
	PIN8 = 8,
	PIN9 = 9,
	PIN10 = 10,
	PIN11 = 11,
	PIN12 = 12,
	PIN13 = 13,
	PIN14 = 14,
	PIN15 = 15,
	TOTAL_NUMBER_OF_PINS = NUM_GPIO_PINS
}GPIO_PIN_NUMBER;

typedef enum
{
	OUT = 0,
	IN = 1
}GPIO_PIN_DIRECTION;

typedef enum
{
	ZERO = 0,
	ONE = 1
}GPIO_PIN_VALUE;

typedef enum
{
	RISING_EDGE = 0,
	FALLING_EDGE = 1,
	BOTH_EDGES = 2
}GPIO_PIN_INTERRUPT_TRIGGER;

typedef enum
{
	NO_EVENT = 0,
	PENDING_EVENT = 1
}GPIO_PIN_INTERRUPT_FLAG;

#ifdef __cplusplus
extern "C" {
#endif

int32 GPIO_Init();
void GPIO_SetPinDirection(GPIO_BANK_NUMBER bank, GPIO_PIN_NUMBER pin, GPIO_PIN_DIRECTION direction);
void GPIO_SetBankDirection(GPIO_BANK_NUMBER bank, GPIO_PIN_DIRECTION direction);
void GPIO_SetGpioPin(GPIO_BANK_NUMBER bank, GPIO_PIN_NUMBER pin);
void GPIO_WriteToGpioBank(GPIO_BANK_NUMBER bank, uint16 val);
void GPIO_ClearGpioPin(GPIO_BANK_NUMBER bank, GPIO_PIN_NUMBER pin);
GPIO_PIN_VALUE GPIO_ReadGpioPin(GPIO_BANK_NUMBER bank, GPIO_PIN_NUMBER pin);
uint16 GPIO_ReadFromGpioBank(GPIO_BANK_NUMBER bank);
void GPIO_EnableInterruptForGpioBank(GPIO_BANK_NUMBER bank);
void GPIO_DisableInterruptForGpioBank(GPIO_BANK_NUMBER bank);
void GPIO_EnableInterruptForGpioPin(GPIO_BANK_NUMBER bank, GPIO_PIN_NUMBER pin, GPIO_PIN_INTERRUPT_TRIGGER trigger);
void GPIO_DisableInterruptForGpioPin(GPIO_BANK_NUMBER bank, GPIO_PIN_NUMBER pin, GPIO_PIN_INTERRUPT_TRIGGER trigger);
GPIO_PIN_INTERRUPT_FLAG GPIO_CheckInterruptFlagForGpioPin(GPIO_BANK_NUMBER bank, GPIO_PIN_NUMBER pin);
void GPIO_ClearInterruptFlagForGpioPin(GPIO_BANK_NUMBER bank, GPIO_PIN_NUMBER pin);

// Method to get a pointer to the Rising Edge Interrupt Trigger Flag Set Register for a specific GPIO pin
volatile uint32* GPIO_GetSetRisingTriggerPtr(GPIO_BANK_NUMBER bank, GPIO_PIN_NUMBER pin);
// Method to get a pointer to the Rising Edge Interrupt Trigger Flag Clear Register for a specific GPIO pin
volatile uint32* GPIO_GetClearRisingTriggerPtr(GPIO_BANK_NUMBER bank, GPIO_PIN_NUMBER pin);
// Method to get the mask to use to set/clear the Rising Edge Interrupt Trigger for a specific GPIO pin
uint32 GPIO_GetRisingTriggerMask(GPIO_BANK_NUMBER bank, GPIO_PIN_NUMBER pin);

#ifdef __cplusplus
}
#endif

#endif /*GPIO_H_*/
