#ifndef PSC_H_
#define PSC_H_

typedef enum PERIPHERALNAMEENUM
{
	EDMA0_CC0	= 0,
	EDMA0_TC0 	= 1,
	EDMA0_TC1 	= 2,
	EMIFA 		= 3,
	SPI0		= 4,
	MMC_SD0 	= 5,
	ARM_INTC	= 6,
	ARM_RAM_ROM	= 7,
	UART0		= 8,
	SCR0		= 9,
	SCR1		= 10,
	SCR2		= 11,
	PRU			= 12,
	ARM			= 13,
	DSP			= 14,
	EDMA1_CC0	= 15,
	USB0		= 16,
	USB1		= 17,
	GPIO		= 18,
	HPI			= 19,
	EMAC		= 20,
	DDR2_MDDR	= 21,
	MCASP0		= 22,
	SATA		= 23,
	VPIF		= 24,
	SPI1		= 25,
	IIC1		= 26,
	UART1		= 27,
	UART2		= 28,
	MCBSP0		= 29,
	MCBSP1		= 30,
	LCDC		= 31,
	EHRPWM_01	= 32,
	MMC_SD1		= 33,
	UPP			= 34,
	ECAP_012	= 35,
	EDMA1_TC0	= 36,
	SCR_F0		= 37,
	SCR_F1		= 38,
	SCR_F2		= 39,
	SCR_F6		= 40,
	SCR_F7		= 41,
	SCR_F8		= 42,
	BR_F7		= 43,
	L3_RAM		= 44,
		
	TOTAL_NUMBER_OF_PSC_CONTROLLED_PERIPHERALS = 45
} PERIPHERAL_NAME;

#define TRANSITION_SUCCESS (0)
#define TRANSITION_TIMEOUT_ERR (-1)
#define INVALID_PERIPHERAL_TABLE (-2)

#ifdef __cplusplus
extern "C" {
#endif
int PSC_InitSystem(void);

int PSC_EnablePeripheral(PERIPHERAL_NAME periphName);

int PSC_DisablePeripheral(PERIPHERAL_NAME periphName);

int PSC_LocalAssertDSP(PERIPHERAL_NAME periphName);

int PSC_LocalDeassertDSP(PERIPHERAL_NAME periphName);

int PSC_LocalAssertARM(PERIPHERAL_NAME periphName);

int PSC_LocalDeassertARM(PERIPHERAL_NAME periphName);

#ifdef __cplusplus
}
#endif

#endif /*PSC_H_*/
