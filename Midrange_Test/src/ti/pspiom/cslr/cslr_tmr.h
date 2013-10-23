/*
 * cslr_tmr.h
 *
 * This file contains the macros for Register Chip Support Library (CSL) which 
 * can be used for operations on the respective underlying hardware/peripheral
 *
 * Copyright (C) 2009 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/


/** ============================================================================
 *   @file  cslr_tmr.h
 *
 *   @path  $(CSLPATH)\inc
 *
 *   @desc  This file contains the Register Descriptions for TMR
 *
 *  ============================================================================
 */
#ifndef _CSLR_TMR_H_
#define _CSLR_TMR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/pspiom/cslr/cslr.h>
#include <ti/pspiom/cslr/tistdtypes.h>


/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 REVID;
    volatile Uint32 EMUMGT;
    volatile Uint32 GPINTGPEN;
    volatile Uint32 GPDATGPDIR;
    volatile Uint32 TIM12;
    volatile Uint32 TIM34;
    volatile Uint32 PRD12;
    volatile Uint32 PRD34;
    volatile Uint32 TCR;
    volatile Uint32 TGCR;
    volatile Uint32 WDTCR;
    volatile Uint8 RSVD0[8];
    volatile Uint32 REL12;
    volatile Uint32 REL34;
    volatile Uint32 CAP12;
    volatile Uint32 CAP34;
    volatile Uint32 INTCTLSTAT;
    volatile Uint8 RSVD1[24];
    volatile Uint32 CMP0;
    volatile Uint32 CMP1;
    volatile Uint32 CMP2;
    volatile Uint32 CMP3;
    volatile Uint32 CMP4;
    volatile Uint32 CMP5;
    volatile Uint32 CMP6;
    volatile Uint32 CMP7;
} CSL_TmrRegs;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_TmrRegs         *CSL_TmrRegsOvly;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* REVID */

#define CSL_TMR_REVID_REV_MASK           (0xFFFFFFFFu)
#define CSL_TMR_REVID_REV_SHIFT          (0x00000000u)
#define CSL_TMR_REVID_REV_RESETVAL       (0x44720211u)

#define CSL_TMR_REVID_RESETVAL           (0x44720211u)

/* EMUMGT */




#define CSL_TMR_EMUMGT_SOFT_MASK         (0x00000002u)
#define CSL_TMR_EMUMGT_SOFT_SHIFT        (0x00000001u)
#define CSL_TMR_EMUMGT_SOFT_RESETVAL     (0x00000000u)
/*----SOFT Tokens----*/
#define CSL_TMR_EMUMGT_SOFT_IMMEDIATE    (0x00000000u)
#define CSL_TMR_EMUMGT_SOFT_INCREMENT    (0x00000001u)

#define CSL_TMR_EMUMGT_FREE_MASK         (0x00000001u)
#define CSL_TMR_EMUMGT_FREE_SHIFT        (0x00000000u)
#define CSL_TMR_EMUMGT_FREE_RESETVAL     (0x00000000u)
/*----FREE Tokens----*/
#define CSL_TMR_EMUMGT_FREE_SOFT         (0x00000000u)
#define CSL_TMR_EMUMGT_FREE_FREE         (0x00000001u)

#define CSL_TMR_EMUMGT_RESETVAL          (0x00000000u)

/* GPINTGPEN */


#define CSL_TMR_GPINTGPEN_GPENO34_MASK   (0x02000000u)
#define CSL_TMR_GPINTGPEN_GPENO34_SHIFT  (0x00000019u)
#define CSL_TMR_GPINTGPEN_GPENO34_RESETVAL (0x00000000u)
/*----GPENO34 Tokens----*/
#define CSL_TMR_GPINTGPEN_GPENO34_TIMER  (0x00000000u)
#define CSL_TMR_GPINTGPEN_GPENO34_GPIO   (0x00000001u)

#define CSL_TMR_GPINTGPEN_GPENI34_MASK   (0x01000000u)
#define CSL_TMR_GPINTGPEN_GPENI34_SHIFT  (0x00000018u)
#define CSL_TMR_GPINTGPEN_GPENI34_RESETVAL (0x00000000u)
/*----GPENI34 Tokens----*/
#define CSL_TMR_GPINTGPEN_GPENI34_TIMER  (0x00000000u)
#define CSL_TMR_GPINTGPEN_GPENI34_GPIO   (0x00000001u)


#define CSL_TMR_GPINTGPEN_GPENO12_MASK   (0x00020000u)
#define CSL_TMR_GPINTGPEN_GPENO12_SHIFT  (0x00000011u)
#define CSL_TMR_GPINTGPEN_GPENO12_RESETVAL (0x00000000u)
/*----GPENO12 Tokens----*/
#define CSL_TMR_GPINTGPEN_GPENO12_TIMER  (0x00000000u)
#define CSL_TMR_GPINTGPEN_GPENO12_GPIO   (0x00000001u)

#define CSL_TMR_GPINTGPEN_GPENI12_MASK   (0x00010000u)
#define CSL_TMR_GPINTGPEN_GPENI12_SHIFT  (0x00000010u)
#define CSL_TMR_GPINTGPEN_GPENI12_RESETVAL (0x00000000u)
/*----GPENI12 Tokens----*/
#define CSL_TMR_GPINTGPEN_GPENI12_TIMER  (0x00000000u)
#define CSL_TMR_GPINTGPEN_GPENI12_GPIO   (0x00000001u)


#define CSL_TMR_GPINTGPEN_GPINT34INVO_MASK (0x00002000u)
#define CSL_TMR_GPINTGPEN_GPINT34INVO_SHIFT (0x0000000Du)
#define CSL_TMR_GPINTGPEN_GPINT34INVO_RESETVAL (0x00000000u)
/*----GPINT34INVO Tokens----*/
#define CSL_TMR_GPINTGPEN_GPINT34INVO_DISABLE (0x00000000u)
#define CSL_TMR_GPINTGPEN_GPINT34INVO_ENABLE (0x00000001u)

#define CSL_TMR_GPINTGPEN_GPINT34INVI_MASK (0x00001000u)
#define CSL_TMR_GPINTGPEN_GPINT34INVI_SHIFT (0x0000000Cu)
#define CSL_TMR_GPINTGPEN_GPINT34INVI_RESETVAL (0x00000000u)
/*----GPINT34INVI Tokens----*/
#define CSL_TMR_GPINTGPEN_GPINT34INVI_DISABLE (0x00000000u)
#define CSL_TMR_GPINTGPEN_GPINT34INVI_ENABLE (0x00000001u)


#define CSL_TMR_GPINTGPEN_GPINT34ENO_MASK (0x00000200u)
#define CSL_TMR_GPINTGPEN_GPINT34ENO_SHIFT (0x00000009u)
#define CSL_TMR_GPINTGPEN_GPINT34ENO_RESETVAL (0x00000000u)
/*----GPINT34ENO Tokens----*/
#define CSL_TMR_GPINTGPEN_GPINT34ENO_DISABLE (0x00000000u)
#define CSL_TMR_GPINTGPEN_GPINT34ENO_ENABLE (0x00000001u)

#define CSL_TMR_GPINTGPEN_GPINT34ENI_MASK (0x00000100u)
#define CSL_TMR_GPINTGPEN_GPINT34ENI_SHIFT (0x00000008u)
#define CSL_TMR_GPINTGPEN_GPINT34ENI_RESETVAL (0x00000000u)
/*----GPINT34ENI Tokens----*/
#define CSL_TMR_GPINTGPEN_GPINT34ENI_DISABLE (0x00000000u)
#define CSL_TMR_GPINTGPEN_GPINT34ENI_ENABLE (0x00000001u)


#define CSL_TMR_GPINTGPEN_GPINT12INVO_MASK (0x00000020u)
#define CSL_TMR_GPINTGPEN_GPINT12INVO_SHIFT (0x00000005u)
#define CSL_TMR_GPINTGPEN_GPINT12INVO_RESETVAL (0x00000000u)
/*----GPINT12INVO Tokens----*/
#define CSL_TMR_GPINTGPEN_GPINT12INVO_DISABLE (0x00000000u)
#define CSL_TMR_GPINTGPEN_GPINT12INVO_ENABLE (0x00000001u)

#define CSL_TMR_GPINTGPEN_GPINT12INVI_MASK (0x00000010u)
#define CSL_TMR_GPINTGPEN_GPINT12INVI_SHIFT (0x00000004u)
#define CSL_TMR_GPINTGPEN_GPINT12INVI_RESETVAL (0x00000000u)
/*----GPINT12INVI Tokens----*/
#define CSL_TMR_GPINTGPEN_GPINT12INVI_DISABLE (0x00000000u)
#define CSL_TMR_GPINTGPEN_GPINT12INVI_ENABLE (0x00000001u)


#define CSL_TMR_GPINTGPEN_GPINT12ENO_MASK (0x00000002u)
#define CSL_TMR_GPINTGPEN_GPINT12ENO_SHIFT (0x00000001u)
#define CSL_TMR_GPINTGPEN_GPINT12ENO_RESETVAL (0x00000000u)
/*----GPINT12ENO Tokens----*/
#define CSL_TMR_GPINTGPEN_GPINT12ENO_DISABLE (0x00000000u)
#define CSL_TMR_GPINTGPEN_GPINT12ENO_ENABLE (0x00000001u)

#define CSL_TMR_GPINTGPEN_GPINT12ENI_MASK (0x00000001u)
#define CSL_TMR_GPINTGPEN_GPINT12ENI_SHIFT (0x00000000u)
#define CSL_TMR_GPINTGPEN_GPINT12ENI_RESETVAL (0x00000000u)
/*----GPINT12ENI Tokens----*/
#define CSL_TMR_GPINTGPEN_GPINT12ENI_DISABLE (0x00000000u)
#define CSL_TMR_GPINTGPEN_GPINT12ENI_ENABLE (0x00000001u)

#define CSL_TMR_GPINTGPEN_RESETVAL       (0x00000000u)

/* GPDATGPDIR */


#define CSL_TMR_GPDATGPDIR_GPDIRO34_MASK (0x02000000u)
#define CSL_TMR_GPDATGPDIR_GPDIRO34_SHIFT (0x00000019u)
#define CSL_TMR_GPDATGPDIR_GPDIRO34_RESETVAL (0x00000000u)
/*----GPDIRO34 Tokens----*/
#define CSL_TMR_GPDATGPDIR_GPDIRO34_INPUT (0x00000000u)
#define CSL_TMR_GPDATGPDIR_GPDIRO34_OUTPUT (0x00000001u)

#define CSL_TMR_GPDATGPDIR_GPDIRI34_MASK (0x01000000u)
#define CSL_TMR_GPDATGPDIR_GPDIRI34_SHIFT (0x00000018u)
#define CSL_TMR_GPDATGPDIR_GPDIRI34_RESETVAL (0x00000000u)
/*----GPDIRI34 Tokens----*/
#define CSL_TMR_GPDATGPDIR_GPDIRI34_INPUT (0x00000000u)
#define CSL_TMR_GPDATGPDIR_GPDIRI34_OUTPUT (0x00000001u)


#define CSL_TMR_GPDATGPDIR_GPDIRO12_MASK (0x00020000u)
#define CSL_TMR_GPDATGPDIR_GPDIRO12_SHIFT (0x00000011u)
#define CSL_TMR_GPDATGPDIR_GPDIRO12_RESETVAL (0x00000000u)
/*----GPDIRO12 Tokens----*/
#define CSL_TMR_GPDATGPDIR_GPDIRO12_INPUT (0x00000000u)
#define CSL_TMR_GPDATGPDIR_GPDIRO12_OUTPUT (0x00000001u)

#define CSL_TMR_GPDATGPDIR_GPDIRI12_MASK (0x00010000u)
#define CSL_TMR_GPDATGPDIR_GPDIRI12_SHIFT (0x00000010u)
#define CSL_TMR_GPDATGPDIR_GPDIRI12_RESETVAL (0x00000000u)
/*----GPDIRI12 Tokens----*/
#define CSL_TMR_GPDATGPDIR_GPDIRI12_INPUT (0x00000000u)
#define CSL_TMR_GPDATGPDIR_GPDIRI12_OUTPUT (0x00000001u)


#define CSL_TMR_GPDATGPDIR_GPDATO34_MASK (0x00000200u)
#define CSL_TMR_GPDATGPDIR_GPDATO34_SHIFT (0x00000009u)
#define CSL_TMR_GPDATGPDIR_GPDATO34_RESETVAL (0x00000000u)
/*----GPDATO34 Tokens----*/
#define CSL_TMR_GPDATGPDIR_GPDATO34_CLR  (0x00000000u)
#define CSL_TMR_GPDATGPDIR_GPDATO34_SET  (0x00000001u)

#define CSL_TMR_GPDATGPDIR_GPDATI34_MASK (0x00000100u)
#define CSL_TMR_GPDATGPDIR_GPDATI34_SHIFT (0x00000008u)
#define CSL_TMR_GPDATGPDIR_GPDATI34_RESETVAL (0x00000000u)
/*----GPDATI34 Tokens----*/
#define CSL_TMR_GPDATGPDIR_GPDATI34_CLR  (0x00000000u)
#define CSL_TMR_GPDATGPDIR_GPDATI34_SET  (0x00000001u)


#define CSL_TMR_GPDATGPDIR_GPDATO12_MASK (0x00000002u)
#define CSL_TMR_GPDATGPDIR_GPDATO12_SHIFT (0x00000001u)
#define CSL_TMR_GPDATGPDIR_GPDATO12_RESETVAL (0x00000000u)
/*----GPDATO12 Tokens----*/
#define CSL_TMR_GPDATGPDIR_GPDATO12_CLR  (0x00000000u)
#define CSL_TMR_GPDATGPDIR_GPDATO12_SET  (0x00000001u)

#define CSL_TMR_GPDATGPDIR_GPDATI12_MASK (0x00000001u)
#define CSL_TMR_GPDATGPDIR_GPDATI12_SHIFT (0x00000000u)
#define CSL_TMR_GPDATGPDIR_GPDATI12_RESETVAL (0x00000000u)
/*----GPDATI12 Tokens----*/
#define CSL_TMR_GPDATGPDIR_GPDATI12_CLR  (0x00000000u)
#define CSL_TMR_GPDATGPDIR_GPDATI12_SET  (0x00000001u)

#define CSL_TMR_GPDATGPDIR_RESETVAL      (0x00000000u)

/* TIM12 */

#define CSL_TMR_TIM12_TIM12_MASK         (0xFFFFFFFFu)
#define CSL_TMR_TIM12_TIM12_SHIFT        (0x00000000u)
#define CSL_TMR_TIM12_TIM12_RESETVAL     (0x00000000u)

#define CSL_TMR_TIM12_RESETVAL           (0x00000000u)

/* TIM34 */

#define CSL_TMR_TIM34_TIM34_MASK         (0xFFFFFFFFu)
#define CSL_TMR_TIM34_TIM34_SHIFT        (0x00000000u)
#define CSL_TMR_TIM34_TIM34_RESETVAL     (0x00000000u)

#define CSL_TMR_TIM34_RESETVAL           (0x00000000u)

/* PRD12 */

#define CSL_TMR_PRD12_PRD12_MASK         (0xFFFFFFFFu)
#define CSL_TMR_PRD12_PRD12_SHIFT        (0x00000000u)
#define CSL_TMR_PRD12_PRD12_RESETVAL     (0x00000000u)

#define CSL_TMR_PRD12_RESETVAL           (0x00000000u)

/* PRD34 */

#define CSL_TMR_PRD34_PRD34_MASK         (0xFFFFFFFFu)
#define CSL_TMR_PRD34_PRD34_SHIFT        (0x00000000u)
#define CSL_TMR_PRD34_PRD34_RESETVAL     (0x00000000u)

#define CSL_TMR_PRD34_RESETVAL           (0x00000000u)

/* TCR */


#define CSL_TMR_TCR_CAPEVTMODE34_MASK    (0x30000000u)
#define CSL_TMR_TCR_CAPEVTMODE34_SHIFT   (0x0000001Cu)
#define CSL_TMR_TCR_CAPEVTMODE34_RESETVAL (0x00000000u)
/*----CAPEVTMODE34 Tokens----*/
#define CSL_TMR_TCR_CAPEVTMODE34_RISE    (0x00000000u)
#define CSL_TMR_TCR_CAPEVTMODE34_FALL    (0x00000001u)
#define CSL_TMR_TCR_CAPEVTMODE34_BOTH    (0x00000002u)

#define CSL_TMR_TCR_CAPMODE34_MASK       (0x08000000u)
#define CSL_TMR_TCR_CAPMODE34_SHIFT      (0x0000001Bu)
#define CSL_TMR_TCR_CAPMODE34_RESETVAL   (0x00000000u)
/*----CAPMODE34 Tokens----*/
#define CSL_TMR_TCR_CAPMODE34_DISABLE    (0x00000000u)
#define CSL_TMR_TCR_CAPMODE34_ENABLE     (0x00000001u)

#define CSL_TMR_TCR_READRSTMODE34_MASK   (0x04000000u)
#define CSL_TMR_TCR_READRSTMODE34_SHIFT  (0x0000001Au)
#define CSL_TMR_TCR_READRSTMODE34_RESETVAL (0x00000000u)
/*----READRSTMODE34 Tokens----*/
#define CSL_TMR_TCR_READRSTMODE34_CONTINUE (0x00000000u)
#define CSL_TMR_TCR_READRSTMODE34_RESET  (0x00000001u)

#define CSL_TMR_TCR_TIEN34_MASK          (0x02000000u)
#define CSL_TMR_TCR_TIEN34_SHIFT         (0x00000019u)
#define CSL_TMR_TCR_TIEN34_RESETVAL      (0x00000000u)
/*----TIEN34 Tokens----*/
#define CSL_TMR_TCR_TIEN34_NOTGATED      (0x00000000u)
#define CSL_TMR_TCR_TIEN34_GATED         (0x00000001u)

#define CSL_TMR_TCR_CLKSRC34_MASK        (0x01000000u)
#define CSL_TMR_TCR_CLKSRC34_SHIFT       (0x00000018u)
#define CSL_TMR_TCR_CLKSRC34_RESETVAL    (0x00000000u)
/*----CLKSRC34 Tokens----*/
#define CSL_TMR_TCR_CLKSRC34_INTERNAL    (0x00000000u)
#define CSL_TMR_TCR_CLKSRC34_TIMER       (0x00000001u)

#define CSL_TMR_TCR_ENAMODE34_MASK       (0x00C00000u)
#define CSL_TMR_TCR_ENAMODE34_SHIFT      (0x00000016u)
#define CSL_TMR_TCR_ENAMODE34_RESETVAL   (0x00000000u)
/*----ENAMODE34 Tokens----*/
#define CSL_TMR_TCR_ENAMODE34_DISABLE    (0x00000000u)
#define CSL_TMR_TCR_ENAMODE34_EN_ONCE    (0x00000001u)
#define CSL_TMR_TCR_ENAMODE34_EN_CONT    (0x00000002u)
#define CSL_TMR_TCR_ENAMODE34_EN_CONTRELOAD (0x00000003u)

#define CSL_TMR_TCR_PWID34_MASK          (0x00300000u)
#define CSL_TMR_TCR_PWID34_SHIFT         (0x00000014u)
#define CSL_TMR_TCR_PWID34_RESETVAL      (0x00000000u)
/*----PWID34 Tokens----*/
#define CSL_TMR_TCR_PWID34_ONE_CLK       (0x00000000u)
#define CSL_TMR_TCR_PWID34_TWO_CLK       (0x00000001u)
#define CSL_TMR_TCR_PWID34_THREE_CLK     (0x00000002u)
#define CSL_TMR_TCR_PWID34_FOUR_CLK      (0x00000003u)

#define CSL_TMR_TCR_CP34_MASK            (0x00080000u)
#define CSL_TMR_TCR_CP34_SHIFT           (0x00000013u)
#define CSL_TMR_TCR_CP34_RESETVAL        (0x00000000u)
/*----CP34 Tokens----*/
#define CSL_TMR_TCR_CP34_PULSE           (0x00000000u)
#define CSL_TMR_TCR_CP34_CLOCK           (0x00000001u)

#define CSL_TMR_TCR_INVINP34_MASK        (0x00040000u)
#define CSL_TMR_TCR_INVINP34_SHIFT       (0x00000012u)
#define CSL_TMR_TCR_INVINP34_RESETVAL    (0x00000000u)
/*----INVINP34 Tokens----*/
#define CSL_TMR_TCR_INVINP34_NON_INVERTED (0x00000000u)
#define CSL_TMR_TCR_INVINP34_INVERTED    (0x00000001u)

#define CSL_TMR_TCR_INVOUTP34_MASK       (0x00020000u)
#define CSL_TMR_TCR_INVOUTP34_SHIFT      (0x00000011u)
#define CSL_TMR_TCR_INVOUTP34_RESETVAL   (0x00000000u)
/*----INVOUTP34 Tokens----*/
#define CSL_TMR_TCR_INVOUTP34_NON_INVERTED (0x00000000u)
#define CSL_TMR_TCR_INVOUTP34_INVERTED   (0x00000001u)

#define CSL_TMR_TCR_TSTAT34_MASK         (0x00010000u)
#define CSL_TMR_TCR_TSTAT34_SHIFT        (0x00000010u)
#define CSL_TMR_TCR_TSTAT34_RESETVAL     (0x00000000u)
/*----TSTAT34 Tokens----*/
#define CSL_TMR_TCR_TSTAT34_LOW          (0x00000000u)
#define CSL_TMR_TCR_TSTAT34_HIGH         (0x00000001u)


#define CSL_TMR_TCR_CAPEVTMODE12_MASK    (0x00003000u)
#define CSL_TMR_TCR_CAPEVTMODE12_SHIFT   (0x0000000Cu)
#define CSL_TMR_TCR_CAPEVTMODE12_RESETVAL (0x00000000u)
/*----CAPEVTMODE12 Tokens----*/
#define CSL_TMR_TCR_CAPEVTMODE12_RISE    (0x00000000u)
#define CSL_TMR_TCR_CAPEVTMODE12_FALL    (0x00000001u)
#define CSL_TMR_TCR_CAPEVTMODE12_BOTH    (0x00000002u)

#define CSL_TMR_TCR_CAPMODE12_MASK       (0x00000800u)
#define CSL_TMR_TCR_CAPMODE12_SHIFT      (0x0000000Bu)
#define CSL_TMR_TCR_CAPMODE12_RESETVAL   (0x00000000u)
/*----CAPMODE12 Tokens----*/
#define CSL_TMR_TCR_CAPMODE12_DISABLE    (0x00000000u)
#define CSL_TMR_TCR_CAPMODE12_ENABLE     (0x00000001u)

#define CSL_TMR_TCR_READRSTMODE12_MASK   (0x00000400u)
#define CSL_TMR_TCR_READRSTMODE12_SHIFT  (0x0000000Au)
#define CSL_TMR_TCR_READRSTMODE12_RESETVAL (0x00000000u)
/*----READRSTMODE12 Tokens----*/
#define CSL_TMR_TCR_READRSTMODE12_CONTINUE (0x00000000u)
#define CSL_TMR_TCR_READRSTMODE12_RESET  (0x00000001u)

#define CSL_TMR_TCR_TIEN12_MASK          (0x00000200u)
#define CSL_TMR_TCR_TIEN12_SHIFT         (0x00000009u)
#define CSL_TMR_TCR_TIEN12_RESETVAL      (0x00000000u)
/*----TIEN12 Tokens----*/
#define CSL_TMR_TCR_TIEN12_NOTGATED      (0x00000000u)
#define CSL_TMR_TCR_TIEN12_GATED         (0x00000001u)

#define CSL_TMR_TCR_CLKSRC12_MASK        (0x00000100u)
#define CSL_TMR_TCR_CLKSRC12_SHIFT       (0x00000008u)
#define CSL_TMR_TCR_CLKSRC12_RESETVAL    (0x00000000u)
/*----CLKSRC12 Tokens----*/
#define CSL_TMR_TCR_CLKSRC12_INTERNAL    (0x00000000u)
#define CSL_TMR_TCR_CLKSRC12_TIMER       (0x00000001u)

#define CSL_TMR_TCR_ENAMODE12_MASK       (0x000000C0u)
#define CSL_TMR_TCR_ENAMODE12_SHIFT      (0x00000006u)
#define CSL_TMR_TCR_ENAMODE12_RESETVAL   (0x00000000u)
/*----ENAMODE12 Tokens----*/
#define CSL_TMR_TCR_ENAMODE12_DISABLE    (0x00000000u)
#define CSL_TMR_TCR_ENAMODE12_EN_ONCE    (0x00000001u)
#define CSL_TMR_TCR_ENAMODE12_EN_CONT    (0x00000002u)
#define CSL_TMR_TCR_ENAMODE12_EN_CONTRELOAD (0x00000003u)

#define CSL_TMR_TCR_PWID12_MASK          (0x00000030u)
#define CSL_TMR_TCR_PWID12_SHIFT         (0x00000004u)
#define CSL_TMR_TCR_PWID12_RESETVAL      (0x00000000u)
/*----PWID12 Tokens----*/
#define CSL_TMR_TCR_PWID12_ONE_CLK       (0x00000000u)
#define CSL_TMR_TCR_PWID12_TWO_CLK       (0x00000001u)
#define CSL_TMR_TCR_PWID12_THREE_CLK     (0x00000002u)
#define CSL_TMR_TCR_PWID12_FOUR_CLK      (0x00000003u)

#define CSL_TMR_TCR_CP12_MASK            (0x00000008u)
#define CSL_TMR_TCR_CP12_SHIFT           (0x00000003u)
#define CSL_TMR_TCR_CP12_RESETVAL        (0x00000000u)
/*----CP12 Tokens----*/
#define CSL_TMR_TCR_CP12_PULSE           (0x00000000u)
#define CSL_TMR_TCR_CP12_CLOCK           (0x00000001u)

#define CSL_TMR_TCR_INVINP12_MASK        (0x00000004u)
#define CSL_TMR_TCR_INVINP12_SHIFT       (0x00000002u)
#define CSL_TMR_TCR_INVINP12_RESETVAL    (0x00000000u)
/*----INVINP12 Tokens----*/
#define CSL_TMR_TCR_INVINP12_NON_INVERTED (0x00000000u)
#define CSL_TMR_TCR_INVINP12_INVERTED    (0x00000001u)

#define CSL_TMR_TCR_INVOUTP12_MASK       (0x00000002u)
#define CSL_TMR_TCR_INVOUTP12_SHIFT      (0x00000001u)
#define CSL_TMR_TCR_INVOUTP12_RESETVAL   (0x00000000u)
/*----INVOUTP12 Tokens----*/
#define CSL_TMR_TCR_INVOUTP12_NON_INVERTED (0x00000000u)
#define CSL_TMR_TCR_INVOUTP12_INVERTED   (0x00000001u)

#define CSL_TMR_TCR_TSTAT12_MASK         (0x00000001u)
#define CSL_TMR_TCR_TSTAT12_SHIFT        (0x00000000u)
#define CSL_TMR_TCR_TSTAT12_RESETVAL     (0x00000000u)
/*----TSTAT12 Tokens----*/
#define CSL_TMR_TCR_TSTAT12_LOW          (0x00000000u)
#define CSL_TMR_TCR_TSTAT12_HIGH         (0x00000001u)

#define CSL_TMR_TCR_RESETVAL             (0x00000000u)

/* TGCR */


#define CSL_TMR_TGCR_TDDR34_MASK         (0x0000F000u)
#define CSL_TMR_TGCR_TDDR34_SHIFT        (0x0000000Cu)
#define CSL_TMR_TGCR_TDDR34_RESETVAL     (0x00000000u)

#define CSL_TMR_TGCR_PSC34_MASK          (0x00000F00u)
#define CSL_TMR_TGCR_PSC34_SHIFT         (0x00000008u)
#define CSL_TMR_TGCR_PSC34_RESETVAL      (0x00000000u)


#define CSL_TMR_TGCR_PLUSEN_MASK         (0x00000010u)
#define CSL_TMR_TGCR_PLUSEN_SHIFT        (0x00000004u)
#define CSL_TMR_TGCR_PLUSEN_RESETVAL     (0x00000000u)
/*----PLUSEN Tokens----*/
#define CSL_TMR_TGCR_PLUSEN_DISABLE      (0x00000000u)
#define CSL_TMR_TGCR_PLUSEN_ENABLE       (0x00000001u)

#define CSL_TMR_TGCR_TIMMODE_MASK        (0x0000000Cu)
#define CSL_TMR_TGCR_TIMMODE_SHIFT       (0x00000002u)
#define CSL_TMR_TGCR_TIMMODE_RESETVAL    (0x00000000u)
/*----TIMMODE Tokens----*/
#define CSL_TMR_TGCR_TIMMODE_64BIT_GPT   (0x00000000u)
#define CSL_TMR_TGCR_TIMMODE_32BIT_UNCHAIN (0x00000001u)
#define CSL_TMR_TGCR_TIMMODE_64BIT_WDT   (0x00000002u)
#define CSL_TMR_TGCR_TIMMODE_32_CHAIN    (0x00000003u)

#define CSL_TMR_TGCR_TIM34RS_MASK        (0x00000002u)
#define CSL_TMR_TGCR_TIM34RS_SHIFT       (0x00000001u)
#define CSL_TMR_TGCR_TIM34RS_RESETVAL    (0x00000000u)
/*----TIM34RS Tokens----*/
#define CSL_TMR_TGCR_TIM34RS_RESET       (0x00000000u)
#define CSL_TMR_TGCR_TIM34RS_NO_RESET    (0x00000001u)

#define CSL_TMR_TGCR_TIM12RS_MASK        (0x00000001u)
#define CSL_TMR_TGCR_TIM12RS_SHIFT       (0x00000000u)
#define CSL_TMR_TGCR_TIM12RS_RESETVAL    (0x00000000u)
/*----TIM12RS Tokens----*/
#define CSL_TMR_TGCR_TIM12RS_RESET       (0x00000000u)
#define CSL_TMR_TGCR_TIM12RS_NO_RESET    (0x00000001u)

#define CSL_TMR_TGCR_RESETVAL            (0x00000000u)

/* WDTCR */

#define CSL_TMR_WDTCR_WDKEY_MASK         (0xFFFF0000u)
#define CSL_TMR_WDTCR_WDKEY_SHIFT        (0x00000010u)
#define CSL_TMR_WDTCR_WDKEY_RESETVAL     (0x00000000u)
/*----WDKEY Tokens----*/
#define CSL_TMR_WDTCR_WDKEY_CMD1         (0x0000A5C6u)
#define CSL_TMR_WDTCR_WDKEY_CMD2         (0x0000DA7Eu)

#define CSL_TMR_WDTCR_WDFLAG_MASK        (0x00008000u)
#define CSL_TMR_WDTCR_WDFLAG_SHIFT       (0x0000000Fu)
#define CSL_TMR_WDTCR_WDFLAG_RESETVAL    (0x00000000u)
/*----WDFLAG Tokens----*/
#define CSL_TMR_WDTCR_WDFLAG_NO_TIMEOUT  (0x00000000u)
#define CSL_TMR_WDTCR_WDFLAG_TIMEOUT     (0x00000001u)

#define CSL_TMR_WDTCR_WDEN_MASK          (0x00004000u)
#define CSL_TMR_WDTCR_WDEN_SHIFT         (0x0000000Eu)
#define CSL_TMR_WDTCR_WDEN_RESETVAL      (0x00000000u)
/*----WDEN Tokens----*/
#define CSL_TMR_WDTCR_WDEN_DISABLE       (0x00000000u)
#define CSL_TMR_WDTCR_WDEN_ENABLE        (0x00000001u)



#define CSL_TMR_WDTCR_RESETVAL           (0x00000000u)

/* REL12 */

#define CSL_TMR_REL12_REL12_MASK         (0xFFFFFFFFu)
#define CSL_TMR_REL12_REL12_SHIFT        (0x00000000u)
#define CSL_TMR_REL12_REL12_RESETVAL     (0x00000000u)

#define CSL_TMR_REL12_RESETVAL           (0x00000000u)

/* REL34 */

#define CSL_TMR_REL34_REL34_MASK         (0xFFFFFFFFu)
#define CSL_TMR_REL34_REL34_SHIFT        (0x00000000u)
#define CSL_TMR_REL34_REL34_RESETVAL     (0x00000000u)

#define CSL_TMR_REL34_RESETVAL           (0x00000000u)

/* CAP12 */

#define CSL_TMR_CAP12_CAP12_MASK         (0xFFFFFFFFu)
#define CSL_TMR_CAP12_CAP12_SHIFT        (0x00000000u)
#define CSL_TMR_CAP12_CAP12_RESETVAL     (0x00000000u)

#define CSL_TMR_CAP12_RESETVAL           (0x00000000u)

/* CAP34 */

#define CSL_TMR_CAP34_CAP34_MASK         (0xFFFFFFFFu)
#define CSL_TMR_CAP34_CAP34_SHIFT        (0x00000000u)
#define CSL_TMR_CAP34_CAP34_RESETVAL     (0x00000000u)

#define CSL_TMR_CAP34_RESETVAL           (0x00000000u)

/* INTCTLSTAT */




#define CSL_TMR_INTCTLSTAT_EVTINTSTAT34_MASK (0x00080000u)
#define CSL_TMR_INTCTLSTAT_EVTINTSTAT34_SHIFT (0x00000013u)
#define CSL_TMR_INTCTLSTAT_EVTINTSTAT34_RESETVAL (0x00000000u)
/*----EVTINTSTAT34 Tokens----*/
#define CSL_TMR_INTCTLSTAT_EVTINTSTAT34_NOPEND (0x00000000u)
#define CSL_TMR_INTCTLSTAT_EVTINTSTAT34_PEND (0x00000001u)

#define CSL_TMR_INTCTLSTAT_EVTINTEN34_MASK (0x00040000u)
#define CSL_TMR_INTCTLSTAT_EVTINTEN34_SHIFT (0x00000012u)
#define CSL_TMR_INTCTLSTAT_EVTINTEN34_RESETVAL (0x00000000u)
/*----EVTINTEN34 Tokens----*/
#define CSL_TMR_INTCTLSTAT_EVTINTEN34_DISABLE (0x00000000u)
#define CSL_TMR_INTCTLSTAT_EVTINTEN34_ENABLE (0x00000001u)

#define CSL_TMR_INTCTLSTAT_PRDINTSTAT34_MASK (0x00020000u)
#define CSL_TMR_INTCTLSTAT_PRDINTSTAT34_SHIFT (0x00000011u)
#define CSL_TMR_INTCTLSTAT_PRDINTSTAT34_RESETVAL (0x00000000u)
/*----PRDINTSTAT34 Tokens----*/
#define CSL_TMR_INTCTLSTAT_PRDINTSTAT34_NOPEND (0x00000000u)
#define CSL_TMR_INTCTLSTAT_PRDINTSTAT34_PEND (0x00000001u)

#define CSL_TMR_INTCTLSTAT_PRDINTEN34_MASK (0x00010000u)
#define CSL_TMR_INTCTLSTAT_PRDINTEN34_SHIFT (0x00000010u)
#define CSL_TMR_INTCTLSTAT_PRDINTEN34_RESETVAL (0x00000000u)
/*----PRDINTEN34 Tokens----*/
#define CSL_TMR_INTCTLSTAT_PRDINTEN34_DISABLE (0x00000000u)
#define CSL_TMR_INTCTLSTAT_PRDINTEN34_ENABLE (0x00000001u)




#define CSL_TMR_INTCTLSTAT_EVTINTSTAT12_MASK (0x00000008u)
#define CSL_TMR_INTCTLSTAT_EVTINTSTAT12_SHIFT (0x00000003u)
#define CSL_TMR_INTCTLSTAT_EVTINTSTAT12_RESETVAL (0x00000000u)
/*----EVTINTSTAT12 Tokens----*/
#define CSL_TMR_INTCTLSTAT_EVTINTSTAT12_NOPEND (0x00000000u)
#define CSL_TMR_INTCTLSTAT_EVTINTSTAT12_PEND (0x00000001u)

#define CSL_TMR_INTCTLSTAT_EVTINTEN12_MASK (0x00000004u)
#define CSL_TMR_INTCTLSTAT_EVTINTEN12_SHIFT (0x00000002u)
#define CSL_TMR_INTCTLSTAT_EVTINTEN12_RESETVAL (0x00000000u)
/*----EVTINTEN12 Tokens----*/
#define CSL_TMR_INTCTLSTAT_EVTINTEN12_DISABLE (0x00000000u)
#define CSL_TMR_INTCTLSTAT_EVTINTEN12_ENABLE (0x00000001u)

#define CSL_TMR_INTCTLSTAT_PRDINTSTAT12_MASK (0x00000002u)
#define CSL_TMR_INTCTLSTAT_PRDINTSTAT12_SHIFT (0x00000001u)
#define CSL_TMR_INTCTLSTAT_PRDINTSTAT12_RESETVAL (0x00000000u)
/*----PRDINTSTAT12 Tokens----*/
#define CSL_TMR_INTCTLSTAT_PRDINTSTAT12_NOPEND (0x00000000u)
#define CSL_TMR_INTCTLSTAT_PRDINTSTAT12_PEND (0x00000001u)

#define CSL_TMR_INTCTLSTAT_PRDINTEN12_MASK (0x00000001u)
#define CSL_TMR_INTCTLSTAT_PRDINTEN12_SHIFT (0x00000000u)
#define CSL_TMR_INTCTLSTAT_PRDINTEN12_RESETVAL (0x00000000u)
/*----PRDINTEN12 Tokens----*/
#define CSL_TMR_INTCTLSTAT_PRDINTEN12_DISABLE (0x00000000u)
#define CSL_TMR_INTCTLSTAT_PRDINTEN12_ENABLE (0x00000001u)

#define CSL_TMR_INTCTLSTAT_RESETVAL      (0x00000000u)

/* CMP0 */

#define CSL_TMR_CMP0_CMP0_MASK           (0xFFFFFFFFu)
#define CSL_TMR_CMP0_CMP0_SHIFT          (0x00000000u)
#define CSL_TMR_CMP0_CMP0_RESETVAL       (0xFFFFFFFFu)

#define CSL_TMR_CMP0_RESETVAL            (0x00000000u)

/* CMP1 */

#define CSL_TMR_CMP1_CMP1_MASK           (0xFFFFFFFFu)
#define CSL_TMR_CMP1_CMP1_SHIFT          (0x00000000u)
#define CSL_TMR_CMP1_CMP1_RESETVAL       (0xFFFFFFFFu)

#define CSL_TMR_CMP1_RESETVAL            (0x00000000u)

/* CMP2 */

#define CSL_TMR_CMP2_CMP2_MASK           (0xFFFFFFFFu)
#define CSL_TMR_CMP2_CMP2_SHIFT          (0x00000000u)
#define CSL_TMR_CMP2_CMP2_RESETVAL       (0xFFFFFFFFu)

#define CSL_TMR_CMP2_RESETVAL            (0x00000000u)

/* CMP3 */

#define CSL_TMR_CMP3_CMP3_MASK           (0xFFFFFFFFu)
#define CSL_TMR_CMP3_CMP3_SHIFT          (0x00000000u)
#define CSL_TMR_CMP3_CMP3_RESETVAL       (0xFFFFFFFFu)

#define CSL_TMR_CMP3_RESETVAL            (0x00000000u)

/* CMP4 */

#define CSL_TMR_CMP4_CMP4_MASK           (0xFFFFFFFFu)
#define CSL_TMR_CMP4_CMP4_SHIFT          (0x00000000u)
#define CSL_TMR_CMP4_CMP4_RESETVAL       (0xFFFFFFFFu)

#define CSL_TMR_CMP4_RESETVAL            (0x00000000u)

/* CMP5 */

#define CSL_TMR_CMP5_CMP5_MASK           (0xFFFFFFFFu)
#define CSL_TMR_CMP5_CMP5_SHIFT          (0x00000000u)
#define CSL_TMR_CMP5_CMP5_RESETVAL       (0xFFFFFFFFu)

#define CSL_TMR_CMP5_RESETVAL            (0x00000000u)

/* CMP6 */

#define CSL_TMR_CMP6_CMP6_MASK           (0xFFFFFFFFu)
#define CSL_TMR_CMP6_CMP6_SHIFT          (0x00000000u)
#define CSL_TMR_CMP6_CMP6_RESETVAL       (0xFFFFFFFFu)

#define CSL_TMR_CMP6_RESETVAL            (0x00000000u)

/* CMP7 */

#define CSL_TMR_CMP7_CMP7_MASK           (0xFFFFFFFFu)
#define CSL_TMR_CMP7_CMP7_SHIFT          (0x00000000u)
#define CSL_TMR_CMP7_CMP7_RESETVAL       (0xFFFFFFFFu)

#define CSL_TMR_CMP7_RESETVAL            (0x00000000u)

#ifdef __cplusplus
}
#endif

#endif

