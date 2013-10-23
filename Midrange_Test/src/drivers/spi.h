#ifndef OMAP_SPI_H
#define OMAP_SPI_H 1

#include <DataTypes.h>

#if defined(OMAP_ARM)

#include <INTEGRITY.h>

#ifndef TRUE
    #define TRUE true
#endif

#ifndef FALSE
    #define FALSE false
#endif

#endif

typedef enum SPIINSTANCEENUM
{
	SPI_INSTANCE_0 = 0,
	SPI_INSTANCE_1 = 1
} SPIInstance; 

typedef enum SPISHIFTDIRENUM
{
	SPI_SHIFT_MSB = 0,
	SPI_SHIFT_LSB = 1
} SPIShiftDirection;

typedef enum SPICLOCKPOLENUM
{
	SPI_CLOCK_POL_NORMAL = 0,
	SPI_CLOCK_POL_INVERTED = 1
} SPIClockPolarity;

typedef enum SPICLOCKPHASENUM
{
	SPI_CLOCK_PHASE_NORMAL = 0,
	SPI_CLOCK_PHASE_SHIFTED = 1
} SPIClockPhase;

#ifdef __cplusplus
extern "C" {
#endif

// Method to initialize a specific SPI Instance for master mode use
uint8 SPI_InitSPIMaster	(	SPIInstance spiInst,
							uint32 spiClockFrequency, 
							uint8 transferSize, 
							SPIShiftDirection spiShiftDir, 
							SPIClockPolarity spiClockPol, 
							SPIClockPhase spiClockPhase);

// Method to get a pointer to the RX Data register in the SPI peripheral for a specific instance.
volatile uint32* SPI_GetRxDataPtr(SPIInstance spiInst);

// Method to get a pointer to the TX Data register in the SPI peripheral for a specific instance.
volatile uint32* SPI_GetTxDataPtr(SPIInstance spiInst);

// Method to send the a unit of data on the SPI channel
void SPI_SendData(SPIInstance spiInst, uint16 data);

#ifdef __cplusplus
}
#endif

extern void SPI_ISRHandler(uint32 arg);


#endif
