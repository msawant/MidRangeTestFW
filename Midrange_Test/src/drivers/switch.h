/*
 * switch.h
 *
 *  Created on: Oct 18, 2013
 *      Author: miglab
 */

#ifndef SWITCH_H_
#define SWITCH_H_
#include <DataTypes.h>

typedef struct{
	volatile uint16 TS_CONTROL;
	volatile uint16 TS_EVENT;
	volatile uint16 ADDEND_LO;
	volatile uint16 ADDEND_HI;
	volatile uint16 ACCUM_LO;
	volatile uint16 ACCUM_HI;
	volatile uint16 BLANK0;
	volatile uint16 BLANK1;
	volatile uint16 SYSTIME_LO_LO;
	volatile uint16 SYSTIME_LO_HI;
	volatile uint16 SYSTIME_HI_LO;
	volatile uint16 SYSTIME_HI_HI;
	volatile uint16 BLANK2;
	volatile uint16 BLANK3;
	volatile uint16 BLANK4;
	volatile uint16 BLANK5;
	volatile uint16 TGTTIM1_LO_LO;
	volatile uint16 TGTTIM1_LO_HI;
	volatile uint16 TGTTIM1_HI_LO;
	volatile uint16 TGTTIM1_HI_HI;
	volatile uint16 TGTTIM2_LO_LO;
	volatile uint16 TGTTIM2_LO_HI;
	volatile uint16 TGTTIM2_HI_LO;
	volatile uint16 TGTTIM2_HI_HI;
	volatile uint16 BLANK6;
	volatile uint16 BLANK7;
	volatile uint16 BLANK8;
	volatile uint16 BLANK9;
	volatile uint16 Evnt1_Lo_Lo;
	volatile uint16 Evnt1_Lo_Hi;
	volatile uint16 Evnt1_Hi_Lo;
	volatile uint16 Evnt1_Hi_Hi;
	volatile uint16 Evnt2_Lo_Lo;
	volatile uint16 Evnt2_Lo_Hi;
	volatile uint16 Evnt2_Hi_Lo;
	volatile uint16 Evnt2_Hi_Hi;
	volatile uint16 XMIT_LO_LO;
	volatile uint16 XMIT_LO_HI;
	volatile uint16 XMIT_HI_LO;
	volatile uint16 XMIT_HI_HI;
	volatile uint16 RECV_LO_LO;
	volatile uint16 RECV_LO_HI;
	volatile uint16 RECV_HI_LO;
	volatile uint16 RECV_HI_HI;
	volatile uint16 RxID_Lo_Lo;
	volatile uint16 RxID_Lo_Hi;
	volatile uint16 RxID_Hi_Lo;
	volatile uint16 RxID_Hi_Hi;
	volatile uint16 RECV_SEQ_ID;
	volatile uint16 TS_SUBDOMAIN;
	volatile uint16 SW_CONTROL;
	volatile uint16 SW_EVENT;
	volatile uint16 SW_MASK;
	volatile uint16 PRT1SEED;
	volatile uint16 PRT2SEED;
	volatile uint16 BLANK10;
	volatile uint16 MAC_LO_LO;
	volatile uint16 MAC_LO_HI;
	volatile uint16 MAC_HI_LO;
	volatile uint16 BLANK11;
	volatile uint16 MCHFI;
	volatile uint16 MCHFV;
	volatile uint16 BLANK12;
	volatile uint16 BLANK13;
	volatile uint16 BLANK14;
	volatile uint16 BLANK15;
	volatile uint16 BLANK16;
	volatile uint16 BLANK17;
	volatile uint16 BLANK18;
	volatile uint16 BLANK19;
	volatile uint16 BLANK20;
	volatile uint16 BLANK21;
	volatile uint16 FREE_TIMER_LO;
	volatile uint16 FREE_TIMER_HI;
	volatile uint16 PITTmo_Lo;
	volatile uint16 PITTmo_Hi;
	volatile uint16 Rdndnc_Control;
	volatile uint16 Rng_BcnState;
	volatile uint16 BcnTmo_Lo;
	volatile uint16 BcnTmo_Hi;
	volatile uint16 P1BcnTS_Lo;
	volatile uint16 P1BcnTS_Hi;
	volatile uint16 P2BcnTS_Lo;
	volatile uint16 P2BcnTS_Hi;
	volatile uint16 P1NChkSId_Lo_Lo;
	volatile uint16 P1NChkSId_Lo_Hi;
	volatile uint16 P1NChkSId_Hi_Lo;
	volatile uint16 BLANK22;
	volatile uint16 P2NChkSId_Lo_Lo;
	volatile uint16 P2NChkSId_Lo_Hi;
	volatile uint16 P2NChkSId_Hi_Lo;
	volatile uint16 BLANK23;
	volatile uint16 P1NStsSId_Lo_Lo;
	volatile uint16 P1NStsSId_Lo_Hi;
	volatile uint16 P1NStsSId_Hi_Lo;
	volatile uint16 BLANK24;
	volatile uint16 P2NStsSId_Lo_Lo;
	volatile uint16 P2NStsSId_Lo_Hi;
	volatile uint16 P2NStsSId_Hi_Lo;
	volatile uint16 BLANK25;
	volatile uint16 RngSprvsrId_Lo_Lo;
	volatile uint16 RngSprvsrId_Lo_Hi;
	volatile uint16 RngSprvsrId_Hi_Lo;
	volatile uint16 BLANK26;
	volatile uint16 BLANK27;
	volatile uint16 BLANK28;
	volatile uint16 BLANK29;
	volatile uint16 BLANK30;
	volatile uint16 BLANK31;
	volatile uint16 BLANK32;
	volatile uint16 BLANK33;
	volatile uint16 BLANK34;
	volatile uint16 BLANK35;
	volatile uint16 BLANK36;
	volatile uint16 BLANK37;
	volatile uint16 BLANK38;
	volatile uint16 BLANK39;
	volatile uint16 BLANK40;
	volatile uint16 BLANK41;
	volatile uint16 BLANK42;
	volatile uint16 BLANK43;
	volatile uint16 BLANK44;
	volatile uint16 BLANK45;
	volatile uint16 BLANK46;
	volatile uint16 BLANK47;
	volatile uint16 BLANK48;
	volatile uint16 BLANK49;
	volatile uint16 BLANK50;
	volatile uint16 BLANK51;
	volatile uint16 BLANK52;
	volatile uint16 BLANK53;
	volatile uint16 BLANK54;
	volatile uint16 BLANK55;
	volatile uint16 BLANK56;
	volatile uint16 P1_GRP_FRM_RCV_CNT;
	volatile uint16 P2_GRP_FRM_RCV_CNT;
	volatile uint16 P1_UNI_FRM_RCV_CNT;
	volatile uint16 P2_UNI_FRM_RCV_CNT;
	volatile uint16 P1_BYTE_RCV_CNT_LO;
	volatile uint16 P1_BYTE_RCV_CNT_HI;
	volatile uint16 P2_BYTE_RCV_CNT_LO;
	volatile uint16 P2_BYTE_RCV_CNT_HI;
	volatile uint16 P1_LRG_ERR_FRM_RCV_CNT;
	volatile uint16 P2_LRG_ERR_FRM_RCV_CNT;
	volatile uint16 P1_ALIGN_ERR_FRM_RCV_CNT;
	volatile uint16 P2_ALIGN_ERR_FRM_RCV_CNT;
	volatile uint16 P1_FCS_ERR_FRM_RCV_CNT;
	volatile uint16 P2_FCS_ERR_FRM_RCV_CNT;
	volatile uint16 P1_RCV_ERR_FRM_RCV_CNT;
	volatile uint16 P2_RCV_ERR_FRM_RCV_CNT;
	volatile uint16 P1_GRP_FRM_XMT_CNT;
	volatile uint16 P2_GRP_FRM_XMT_CNT;
	volatile uint16 P1_UNI_FRM_XMT_CNT;
	volatile uint16 P2_UNI_FRM_XMT_CNT;
	volatile uint16 P1_XMT_BYTE_CNT_LO;
	volatile uint16 P1_XMT_BYTE_CNT_HI;
	volatile uint16 P2_XMT_BYTE_CNT_LO;
	volatile uint16 P2_XMT_BYTE_CNT_HI;
	volatile uint16 P1_XMT_SCOL_FRM_CNT;
	volatile uint16 P2_XMT_SCOL_FRM_CNT;
	volatile uint16 P1_XMT_MCOL_FRM_CNT;
	volatile uint16 P2_XMT_MCOL_FRM_CNT;
	volatile uint16 P1_XMT_ECOL_FRM_CNT;
	volatile uint16 P2_XMT_ECOL_FRM_CNT;
	volatile uint16 P1_XMT_ERR_FRM_CNT;
	volatile uint16 P2_XMT_ERR_FRM_CNT;
	volatile uint16 BLANK58;
	volatile uint16 BLANK59;
	volatile uint16 ID;
	volatile uint16 SCRATCHPAD;
}EthernetSwitchRegs;


/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile EthernetSwitchRegs             *EthernetSwitchRegsOvly;


#ifdef __cplusplus
extern "C" {
#endif

int SetupSwitchForTest();
int RunSwitchTestCase();

#ifdef __cplusplus
}
#endif



#endif /* SWITCH_H_ */
