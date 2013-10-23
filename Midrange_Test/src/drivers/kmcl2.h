#ifndef KMCL2_H_
#define KMCL2_H_

#include <stdio.h>
#include <stdlib.h>

#define HPI

// Includes Register Descriptions for KMCL2
#define DAI_BASE				(0xC0000000)
#define HPI_BASE				(0x60000000)

#ifdef HPI
#define KMCL2_BASE (HPI_BASE)
#endif

#ifdef DAI
#define KMCL2_BASE (DAI_BASE)
#endif


/** @brief Base address of Universal Feedback memory mapped registers */
#define KMCL2_IP_CONFIG				(KMCL2_BASE + 0x1000)

#define KNX_IP_TIMEKEEPER			(KMCL2_BASE + 0x1100)

#define SICK_DSL_A					(KMCL2_BASE + 0x2000)

#define KNX_REG_DSL_A				(KMCL2_BASE + 0x2100)

#define KNX_IP_UNIV_FBK_A			(KMCL2_BASE + 0x3000)

#define KNX_IP_DIG_INPUTS			(KMCL2_BASE + 0x4000)

#define SICK_DSL_B					(KMCL2_BASE + 0x5000)

#define KNX_IP_REG_DSL_A 			(KMCL2_BASE + 0x5100)

#define KNX_IP_UNIV_FBK_B			(KMCL2_BASE + 0x6000)

#define KNX_IP_SINCOS				(KMCL2_BASE + 0x8000)

#define KNX_IP_ADC7866				(KMCL2_BASE + 0x9000)

#define KNX_IP_GPIO					(KMCL2_BASE + 0xA000)

#define KNX_IP_HMI					(KMCL2_BASE + 0xA100)

#define KNX_IP_SFTY_DAIG			(KMCL2_BASE + 0xA200)

#define KNX_IP_UART_INCIP_PKT_MGR	(KMCL2_BASE + 0xA300)

#define KNX_IP_EVT_TS				(KMCL2_BASE + 0xA400)

#define RA_SWITCH					(KMCL2_BASE + 0xB000)

#define BULK_DATA					(KMCL2_BASE + 0xC000)

#define AXI_EMIF_CONFIG 			(KMCL2_BASE + 0x10000)	


#endif /*KMCL2_H_*/
