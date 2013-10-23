#include <debug/knxdebug.h>
#include <math.h>
#include <ti/pspiom/cslr/cslr.h>
#include <ti/pspiom/cslr/soc_OMAPL138.h>
#include <ti/pspiom/cslr/cslr_syscfg0_OMAPL138.h>
#include <ti/pspiom/cslr/cslr_spi.h>
#include <SharedMemory/sharedMem.h>
#include "spi.h"
#include <drivers/psc.h>
#include <drivers/gpio.h>
#include <drivers/system.h>

#define SPI_PRESCALER_MINIMUM (0x02)
#define SPI_PRESCALER_MAXIMUM (0xFF)
#define SPI_CHARLEN_MINIMUM (2)
#define SPI_CHARLEN_MAXIMUM (16)

// Internal method to reset the SPI DMA subsystem in preperation for the next 4 byte transfer
void SPI_ResetDMA(unsigned char enableGPIOStart);

// SPI driver scoped variables indicating if the instances have been initialized yet
uint8 s_IsInitInstance0 = 0;
uint8 s_IsInitInstance1 = 0;

uint8 SPI_InitSPIMaster	(	SPIInstance spiInst,
							uint32 spiClockFrequency, 
							uint8 transferSize, 
							SPIShiftDirection spiShiftDir, 
							SPIClockPolarity spiClockPol, 
							SPIClockPhase spiClockPhase)
{
	uint8 tmpReturn = TRUE;
	
	CSL_SyscfgRegsOvly syscfgRegs = (CSL_SyscfgRegsOvly)CSL_SYSCFG_0_REGS;
	CSL_SpiRegsOvly spiRegs = (spiInst == SPI_INSTANCE_0) ? (CSL_SpiRegsOvly)CSL_SPI_0_REGS : (CSL_SpiRegsOvly)CSL_SPI_1_REGS;
	
	uint32 spiPrescaler = ceil(((double)SYS_SYSCLK2_FREQ / spiClockFrequency) - 1);
	
	DBG_LogUint32(DRIVER_DEBUG_ID, VERB_LEVEL2, "SPI Master Init Instance %d! ", (uint32)(spiInst));
	
	// First things first verify some of the input data. Namely the non enumerated data like the spiFrequency
	// and the transfer size (number of transfer bits)
	if (spiPrescaler < SPI_PRESCALER_MINIMUM)
	{
		DBG_Log(DRIVER_DEBUG_ID, VERB_LEVEL1, "SPI Clock Rate Too High!");
		return FALSE;
	}
	if (spiPrescaler > SPI_PRESCALER_MAXIMUM)
	{
		DBG_Log(DRIVER_DEBUG_ID, VERB_LEVEL1, "SPI Clock Rate Too Low!");
		return FALSE;
	}
	if (transferSize < SPI_CHARLEN_MINIMUM)
	{
		DBG_Log(DRIVER_DEBUG_ID, VERB_LEVEL1, "SPI Transfer Size Too Small!");
		return FALSE;
	}
	if (transferSize > SPI_CHARLEN_MAXIMUM)
	{
		DBG_Log(DRIVER_DEBUG_ID, VERB_LEVEL1, "SPI Transfer Size Too Large!");
		return FALSE;
	}
	
	// Ensure that the SPI and DMA systems are enabled in the PSC
	if (spiInst == SPI_INSTANCE_0)
	{
		PSC_EnablePeripheral(SPI0);
	}
	else
	{
		PSC_EnablePeripheral(SPI1);
	}
	
	// Unlock (unprotect) the syscfg registers 
	SYS_ConfigUnlock();
	
	// Set the PINMux to ensure the SPI functionality is used
	if (spiInst == SPI_INSTANCE_0)
	{
		// Mux the SPI0_CLK/GP1[8] pin to be SPI Clock
		CSL_FINST(syscfgRegs->PINMUX3, SYSCFG_PINMUX3_PINMUX3_3_0, SPI0_CLK);
		// Mux the SPI0_SOMI/GP8[6] pin to be SPI SOMI
		CSL_FINST(syscfgRegs->PINMUX3, SYSCFG_PINMUX3_PINMUX3_11_8, SPI0_SOMI0);
		// Mux the SPI0_SIMO/GP8[5] to be SPI SIMO
		CSL_FINST(syscfgRegs->PINMUX3, SYSCFG_PINMUX3_PINMUX3_15_12, SPI0_SIMO0);
	}
	else
	{
		// Mux the SPI1_CLK/GP2[13] pin to be SPI Clock
		CSL_FINST(syscfgRegs->PINMUX5, SYSCFG_PINMUX5_PINMUX5_11_8, SPI1_CLK);
		// Mux the SPI1_SOMI/GP2[11] pin to be SPI SOMI
		CSL_FINST(syscfgRegs->PINMUX5, SYSCFG_PINMUX5_PINMUX5_19_16, SPI1_SOMI0);
		// Mux the SPI1_SIMO/GP2[10] to be SPI SIMO
		CSL_FINST(syscfgRegs->PINMUX5, SYSCFG_PINMUX5_PINMUX5_23_20, SPI1_SIMO0);
	}
	
	// Reset the spi subsystem
	CSL_FINST(spiRegs->SPIGCR0, SPI_SPIGCR0_RESET, IN_RESET);
	CSL_FINST(spiRegs->SPIGCR0, SPI_SPIGCR0_RESET, OUT_OF_RESET);
	
	// Configure the CPIGCR1 register:
	//    Enable = Off, Loopback = disabled, Powerdown = disable (not powerdown) 
	//    Clkmod,Master = master mode
	CSL_FINST(spiRegs->SPIGCR1, SPI_SPIGCR1_ENABLE, DISABLE);
	CSL_FINST(spiRegs->SPIGCR1, SPI_SPIGCR1_LOOPBACK, DISABLE);
	CSL_FINST(spiRegs->SPIGCR1, SPI_SPIGCR1_POWERDOWN, DISABLE);
	CSL_FINST(spiRegs->SPIGCR1, SPI_SPIGCR1_CLKMOD, INTERNAL);
	CSL_FINST(spiRegs->SPIGCR1, SPI_SPIGCR1_MASTER, MASTER);
	
	// Configure the SPIPC0 to operate SPI in 3-wire mode
	//    SPI_MISO, SPI_MOSI, SPI_CLK = SPI periph all others = GPIO.
	CSL_FINST(spiRegs->SPIPC0, SPI_SPIPC0_SOMIFUN, SPI);
	CSL_FINST(spiRegs->SPIPC0, SPI_SPIPC0_SIMOFUN, SPI);
	CSL_FINST(spiRegs->SPIPC0, SPI_SPIPC0_CLKFUN, SPI);
	CSL_FINST(spiRegs->SPIPC1, SPI_SPIPC1_SOMIDIR, INPUT);
	CSL_FINST(spiRegs->SPIPC1, SPI_SPIPC1_SIMODIR, OUTPUT);
	CSL_FINST(spiRegs->SPIPC1, SPI_SPIPC1_CLKDIR, OUTPUT);
	
	// Preselect SPI format 0 to be used
	CSL_FINST(spiRegs->SPIDAT1, SPI_SPIDAT1_DFSEL, FORMAT0);
	
	// Configure the SPI format register SPIFMT0
	//    WDELAY = 1, Parity enable = off, wait enable = off, 
	//    shift direction = User defined, disable CS Timers = On,
	//    polarity = user defined, phase = user defined,
	//    prescale = based on user desired frequency,
	//    character length = user defined
	spiRegs->SPIFMT[0] |= CSL_FMKR(29,24,3);	// WDelay = 1
	CSL_FINST(spiRegs->SPIFMT[0], SPI_SPIFMT_PARENA, DISABLE);
	CSL_FINST(spiRegs->SPIFMT[0], SPI_SPIFMT_WAITENA, DISABLE);
	if (spiShiftDir == SPI_SHIFT_MSB)
	{
		CSL_FINST(spiRegs->SPIFMT[0], SPI_SPIFMT_SHIFTDIR, MSB);
	}
	else
	{
		CSL_FINST(spiRegs->SPIFMT[0], SPI_SPIFMT_SHIFTDIR, LSB);
	}
	CSL_FINST(spiRegs->SPIFMT[0], SPI_SPIFMT_DISCSTIMERS, ENABLE);
	if (spiClockPol == SPI_CLOCK_POL_NORMAL)
	{
		CSL_FINST(spiRegs->SPIFMT[0], SPI_SPIFMT_POLARITY, LOW);
	}
	else
	{
		CSL_FINST(spiRegs->SPIFMT[0], SPI_SPIFMT_POLARITY, HIGH);
	}
	if (spiClockPhase == SPI_CLOCK_PHASE_NORMAL)
	{
		CSL_FINST(spiRegs->SPIFMT[0], SPI_SPIFMT_PHASE, NO_DELAY);
	}
	else
	{
		CSL_FINST(spiRegs->SPIFMT[0], SPI_SPIFMT_PHASE, DELAY);
	}
	// Calculate the prescale to be used based on the frequency desired by the user.
	// Need to first range clamp the prescaler value then check final prescaler to 
	// make sure actual freq is close to desired
	// Clip the minimum value in the prescaler
	spiPrescaler = (spiPrescaler < SPI_PRESCALER_MINIMUM) ? SPI_PRESCALER_MINIMUM : spiPrescaler;
	// Clip the maximum value in the prescaler
	spiPrescaler = (spiPrescaler > SPI_PRESCALER_MAXIMUM) ? SPI_PRESCALER_MAXIMUM : spiPrescaler;
	DBG_LogUint32(DRIVER_DEBUG_ID, VERB_LEVEL2, "ACTUAL SPI Master Clock %d", (uint32)(SYS_SYSCLK2_FREQ / (spiPrescaler+1)));
	spiRegs->SPIFMT[0] |= CSL_FMKR(15,8,spiPrescaler);
	spiRegs->SPIFMT[0] |= CSL_FMKR(4,0,transferSize);
	 
	// No need to program SPIDELAY register since no chip select or enable registers are being used
	
	// No interrupt requests needed except will enable bit test (self-check interrupt)
	CSL_FINST(spiRegs->SPIINT0, SPI_SPIINT0_BITERRENA, ENABLE);
	
	// Set interrupt level for bit test ISR
	CSL_FINST(spiRegs->SPILVL, SPI_SPILVL_BITERRLVL, INT1);
	
	// Enable SPI Communications
	CSL_FINST(spiRegs->SPIGCR1, SPI_SPIGCR1_ENABLE, ENABLE);
	
	// Enable dma servicing
	CSL_FINST(spiRegs->SPIINT0, SPI_SPIINT0_DMAREQEN, ENABLE);
	
	
	// Protect the syscfg registers 
	SYS_ConfigLock();
	
	// Set the initialized flag
	if (spiInst == SPI_INSTANCE_0)
	{
		s_IsInitInstance0 = TRUE;
	}
	else
	{
		s_IsInitInstance1 = TRUE;
	}
	
	return tmpReturn;
}	

// Method to get a pointer to the RX Data register in the SPI peripheral for a specific instance.
volatile uint32* SPI_GetRxDataPtr(SPIInstance spiInst)
{
	CSL_SpiRegsOvly spiRegs = (spiInst == SPI_INSTANCE_0) ? (CSL_SpiRegsOvly)CSL_SPI_0_REGS : (CSL_SpiRegsOvly)CSL_SPI_1_REGS;
	
	return &(spiRegs->SPIBUF);
}

// Method to get a pointer to the TX Data register in the SPI peripheral for a specific instance.
volatile uint32* SPI_GetTxDataPtr(SPIInstance spiInst)
{
	CSL_SpiRegsOvly spiRegs = (spiInst == SPI_INSTANCE_0) ? (CSL_SpiRegsOvly)CSL_SPI_0_REGS : (CSL_SpiRegsOvly)CSL_SPI_1_REGS;
	
	return &(spiRegs->SPIDAT0);
}

// Method to send the a unit of data on the SPI channel
void SPI_SendData(SPIInstance spiInst, uint16 data)
{
	// Written to be executed quickly. May be used by SERVOIO to send
	if (spiInst == SPI_INSTANCE_0)
	{
		if (s_IsInitInstance0)
		{
			((CSL_SpiRegsOvly)CSL_SPI_0_REGS)->SPIDAT0 = data;
		}
		else
		{
			DBG_Log(DRIVER_DEBUG_ID, VERB_LEVEL1, "SPI Attempt to send on uninitialized instance 0!");
		}
	}
	else
	{
		if (s_IsInitInstance1)
		{
			((CSL_SpiRegsOvly)CSL_SPI_1_REGS)->SPIDAT1 = data;
		}
		else
		{
			DBG_Log(DRIVER_DEBUG_ID, VERB_LEVEL1, "SPI Attempt to send on uninitialized instance 1!");
		}
	}
}
