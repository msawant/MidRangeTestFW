/*
 * kmcl2_config.h
 *
 *  Created on: Oct 11, 2013
 *      Author: msawant
 */

#ifndef KMCL2_CONFIG_H_
#define KMCL2_CONFIG_H_

#include <DataTypes.h>

#define KNX_IP_KMCL2_CONFIG		(KNX_IP_CONFIG)

typedef struct{
volatile uint16 IRQ_CFG;
	volatile uint16 IRQ_STAT;
	volatile uint16 EVENT_MASK;
	volatile uint16 KMCL2_DMA_ONESHOT;
	volatile uint16 DMA_SELECT;
	volatile uint16 BLANK1;
	volatile uint16 BLANK2;
	volatile uint16 BLANK3;
	volatile uint16 BLANK4;
	volatile uint16 BLANK5;
	volatile uint16 BLANK6;
	volatile uint16 BLANK7;
	volatile uint16 BLANK8;
	volatile uint16 BLANK9;
	volatile uint16 ENET_LED_CTL;
	volatile uint16 KMCL2_REV;
	volatile uint16 BLANK10;
	volatile uint16 BLANK11;
	volatile uint16 BLANK12;
	volatile uint16 BLANK13;
	volatile uint16 BLANK14;
	volatile uint16 BLANK15;
	volatile uint16 BLANK16;
	volatile uint16 BLANK17;
	volatile uint16 BLANK18;
	volatile uint16 BLANK19;
	volatile uint16 BLANK20;
	volatile uint16 SCNT;
}KMCL2_CONFIG;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile KMCL2_CONFIG             *KMCL2_Config_RegsOvly;

#ifdef __cplusplus
extern "C" {
#endif

int kmcl2_config_get_rev_id();

#ifdef __cplusplus
}
#endif


#endif /* KMCL2_CONFIG_H_ */
