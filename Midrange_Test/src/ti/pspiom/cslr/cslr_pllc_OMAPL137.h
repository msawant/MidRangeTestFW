/*
 * cslr_pllc_OMAPL137.h
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


#ifndef _CSLR_PLLC_H_
#define _CSLR_PLLC_H_

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
    volatile Uint8 RSVD0[224];
    volatile Uint32 RSTYPE;
    volatile Uint8 RSVD1[24];
    volatile Uint32 PLLCTL;
    volatile Uint8 RSVD2[12];
    volatile Uint32 PLLM;
    volatile Uint32 PREDIV;
    volatile Uint32 PLLDIV1;
    volatile Uint32 PLLDIV2;
    volatile Uint32 PLLDIV3;
    volatile Uint8 RSVD4[4];
    volatile Uint32 POSTDIV;
    volatile Uint8 RSVD5[12];
    volatile Uint32 PLLCMD;
    volatile Uint32 PLLSTAT;
    volatile Uint32 ALNCTL;
    volatile Uint32 DCHANGE;
    volatile Uint32 CKEN;
    volatile Uint32 CKSTAT;
    volatile Uint32 SYSTAT;
    volatile Uint8 RSVD6[12];
    volatile Uint32 PLLDIV4;
    volatile Uint32 PLLDIV5;
    volatile Uint32 PLLDIV6;
    volatile Uint32 PLLDIV7;
} CSL_PllcRegs;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_PllcRegs             *CSL_PllcRegsOvly;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* REVID */

#define CSL_PLLC_REVID_REV_MASK        (0xFFFFFFFFu)
#define CSL_PLLC_REVID_REV_SHIFT       (0x00000000u)
#define CSL_PLLC_REVID_REV_RESETVAL    (0x44813C00u)

#define CSL_PLLC_REVID_RESETVAL          (0x44813C00u)

/* RSTYPE */


#define CSL_PLLC_RSTYPE_SRST_MASK        (0x00000008u)
#define CSL_PLLC_RSTYPE_SRST_SHIFT       (0x00000003u)
#define CSL_PLLC_RSTYPE_SRST_RESETVAL    (0x00000000u)
/*----SRST Tokens----*/
#define CSL_PLLC_RSTYPE_SRST_NO          (0x00000000u)
#define CSL_PLLC_RSTYPE_SRST_YES         (0x00000001u)

#define CSL_PLLC_RSTYPE_MRST_MASK        (0x00000004u)
#define CSL_PLLC_RSTYPE_MRST_SHIFT       (0x00000002u)
#define CSL_PLLC_RSTYPE_MRST_RESETVAL    (0x00000000u)
/*----MRST Tokens----*/
#define CSL_PLLC_RSTYPE_MRST_NO          (0x00000000u)
#define CSL_PLLC_RSTYPE_MRST_YES         (0x00000001u)

#define CSL_PLLC_RSTYPE_XWRST_MASK       (0x00000002u)
#define CSL_PLLC_RSTYPE_XWRST_SHIFT      (0x00000001u)
#define CSL_PLLC_RSTYPE_XWRST_RESETVAL   (0x00000000u)
/*----XWRST Tokens----*/
#define CSL_PLLC_RSTYPE_XWRST_NO         (0x00000000u)
#define CSL_PLLC_RSTYPE_XWRST_YES        (0x00000001u)

#define CSL_PLLC_RSTYPE_POR_MASK         (0x00000001u)
#define CSL_PLLC_RSTYPE_POR_SHIFT        (0x00000000u)
#define CSL_PLLC_RSTYPE_POR_RESETVAL     (0x00000000u)
/*----POR Tokens----*/
#define CSL_PLLC_RSTYPE_POR_NO           (0x00000000u)
#define CSL_PLLC_RSTYPE_POR_YES          (0x00000001u)

#define CSL_PLLC_RSTYPE_RESETVAL         (0x00000000u)

/* PLLCTL */


#define CSL_PLLC_PLLCTL_CLKMODE_MASK     (0x00000100u)
#define CSL_PLLC_PLLCTL_CLKMODE_SHIFT    (0x00000008u)
#define CSL_PLLC_PLLCTL_CLKMODE_RESETVAL (0x00000000u)
/*----CLKMODE Tokens----*/
#define CSL_PLLC_PLLCTL_CLKMODE_OSCIN    (0x00000000u)
#define CSL_PLLC_PLLCTL_CLKMODE_CLKIN    (0x00000001u)


#define CSL_PLLC_PLLCTL_PLLENSRC_MASK    (0x00000020u)
#define CSL_PLLC_PLLCTL_PLLENSRC_SHIFT   (0x00000005u)
#define CSL_PLLC_PLLCTL_PLLENSRC_RESETVAL (0x00000001u)
/*----PLLENSRC Tokens----*/
#define CSL_PLLC_PLLCTL_PLLENSRC_CLEAR   (0x00000000u)

#define CSL_PLLC_PLLCTL_PLLDIS_MASK      (0x00000010u)
#define CSL_PLLC_PLLCTL_PLLDIS_SHIFT     (0x00000004u)
#define CSL_PLLC_PLLCTL_PLLDIS_RESETVAL  (0x00000001u)
/*----PLLDIS Tokens----*/
#define CSL_PLLC_PLLCTL_PLLDIS_DEASSERT  (0x00000000u)
#define CSL_PLLC_PLLCTL_PLLDIS_ASSERT    (0x00000001u)

#define CSL_PLLC_PLLCTL_PLLRST_MASK      (0x00000008u)
#define CSL_PLLC_PLLCTL_PLLRST_SHIFT     (0x00000003u)
#define CSL_PLLC_PLLCTL_PLLRST_RESETVAL  (0x00000000u)
/*----PLLRST Tokens----*/
#define CSL_PLLC_PLLCTL_PLLRST_ASSERT    (0x00000000u)
#define CSL_PLLC_PLLCTL_PLLRST_DEASSERT  (0x00000001u)


#define CSL_PLLC_PLLCTL_PLLPWRDN_MASK    (0x00000002u)
#define CSL_PLLC_PLLCTL_PLLPWRDN_SHIFT   (0x00000001u)
#define CSL_PLLC_PLLCTL_PLLPWRDN_RESETVAL (0x00000001u)
/*----PLLPWRDN Tokens----*/
#define CSL_PLLC_PLLCTL_PLLPWRDN_POWERED_UP (0x00000000u)
#define CSL_PLLC_PLLCTL_PLLPWRDN_POWERED_DOWN (0x00000001u)

#define CSL_PLLC_PLLCTL_PLLEN_MASK       (0x00000001u)
#define CSL_PLLC_PLLCTL_PLLEN_SHIFT      (0x00000000u)
#define CSL_PLLC_PLLCTL_PLLEN_RESETVAL   (0x00000000u)
/*----PLLEN Tokens----*/
#define CSL_PLLC_PLLCTL_PLLEN_BYPASS     (0x00000000u)
#define CSL_PLLC_PLLCTL_PLLEN_PLL        (0x00000001u)

#define CSL_PLLC_PLLCTL_RESETVAL         (0x00000072u)

/* PLLM */


#define CSL_PLLC_PLLM_PLLM_MASK          (0x0000001Fu)
#define CSL_PLLC_PLLM_PLLM_SHIFT         (0x00000000u)
#define CSL_PLLC_PLLM_PLLM_RESETVAL      (0x00000010u)

#define CSL_PLLC_PLLM_RESETVAL           (0x00000010u)

/* PREDIV */


#define CSL_PLLC_PREDIV_PREDEN_MASK      (0x00008000u)
#define CSL_PLLC_PREDIV_PREDEN_SHIFT     (0x0000000Fu)
#define CSL_PLLC_PREDIV_PREDEN_RESETVAL  (0x00000001u)
/*----PREDEN Tokens----*/
#define CSL_PLLC_PREDIV_PREDEN_DISABLE   (0x00000000u)
#define CSL_PLLC_PREDIV_PREDEN_ENABLE    (0x00000001u)


#define CSL_PLLC_PREDIV_RATIO_MASK       (0x0000001Fu)
#define CSL_PLLC_PREDIV_RATIO_SHIFT      (0x00000000u)
#define CSL_PLLC_PREDIV_RATIO_RESETVAL   (0x00000000u)

#define CSL_PLLC_PREDIV_RESETVAL         (0x00008000u)


/* PLLDIV1 */


#define CSL_PLLC_PLLDIV1_D1EN_MASK       (0x00008000u)
#define CSL_PLLC_PLLDIV1_D1EN_SHIFT      (0x0000000Fu)
#define CSL_PLLC_PLLDIV1_D1EN_RESETVAL   (0x00000000u)
/*----D1EN Tokens----*/
#define CSL_PLLC_PLLDIV1_D1EN_DISABLE    (0x00000000u)
#define CSL_PLLC_PLLDIV1_D1EN_ENABLE     (0x00000001u)


#define CSL_PLLC_PLLDIV1_RATIO_MASK      (0x0000001Fu)
#define CSL_PLLC_PLLDIV1_RATIO_SHIFT     (0x00000000u)
#define CSL_PLLC_PLLDIV1_RATIO_RESETVAL  (0x00000000u)

#define CSL_PLLC_PLLDIV1_RESETVAL        (0x00000000u)

/* PLLDIV2 */


#define CSL_PLLC_PLLDIV2_D2EN_MASK       (0x00008000u)
#define CSL_PLLC_PLLDIV2_D2EN_SHIFT      (0x0000000Fu)
#define CSL_PLLC_PLLDIV2_D2EN_RESETVAL   (0x00000001u)
/*----D2EN Tokens----*/
#define CSL_PLLC_PLLDIV2_D2EN_DISABLE    (0x00000000u)
#define CSL_PLLC_PLLDIV2_D2EN_ENABLE     (0x00000001u)


#define CSL_PLLC_PLLDIV2_RATIO_MASK      (0x0000001Fu)
#define CSL_PLLC_PLLDIV2_RATIO_SHIFT     (0x00000000u)
#define CSL_PLLC_PLLDIV2_RATIO_RESETVAL  (0x00000001u)

#define CSL_PLLC_PLLDIV2_RESETVAL        (0x00008001u)

/* PLLDIV3 */


#define CSL_PLLC_PLLDIV3_D3EN_MASK       (0x00008000u)
#define CSL_PLLC_PLLDIV3_D3EN_SHIFT      (0x0000000Fu)
#define CSL_PLLC_PLLDIV3_D3EN_RESETVAL   (0x00000001u)
/*----D3EN Tokens----*/
#define CSL_PLLC_PLLDIV3_D3EN_DISABLE    (0x00000000u)
#define CSL_PLLC_PLLDIV3_D3EN_ENABLE     (0x00000001u)


#define CSL_PLLC_PLLDIV3_RATIO_MASK      (0x0000001Fu)
#define CSL_PLLC_PLLDIV3_RATIO_SHIFT     (0x00000000u)
#define CSL_PLLC_PLLDIV3_RATIO_RESETVAL  (0x00000002u)

#define CSL_PLLC_PLLDIV3_RESETVAL        (0x00008002u)

/* POSTDIV */


#define CSL_PLLC_POSTDIV_POSTDEN_MASK    (0x00008000u)
#define CSL_PLLC_POSTDIV_POSTDEN_SHIFT   (0x0000000Fu)
#define CSL_PLLC_POSTDIV_POSTDEN_RESETVAL (0x00000001u)
/*----POSTDEN Tokens----*/
#define CSL_PLLC_POSTDIV_POSTDEN_DISABLE (0x00000000u)
#define CSL_PLLC_POSTDIV_POSTDEN_ENABLE  (0x00000001u)


#define CSL_PLLC_POSTDIV_RATIO_MASK      (0x0000001Fu)
#define CSL_PLLC_POSTDIV_RATIO_SHIFT     (0x00000000u)
#define CSL_PLLC_POSTDIV_RATIO_RESETVAL  (0x00000000u)

#define CSL_PLLC_POSTDIV_RESETVAL        (0x00008000u)

/* PLLCMD */


#define CSL_PLLC_PLLCMD_GOSET_MASK       (0x00000001u)
#define CSL_PLLC_PLLCMD_GOSET_SHIFT      (0x00000000u)
#define CSL_PLLC_PLLCMD_GOSET_RESETVAL   (0x00000000u)
/*----GOSET Tokens----*/
#define CSL_PLLC_PLLCMD_GOSET_CLRBIT     (0x00000000u)
#define CSL_PLLC_PLLCMD_GOSET_PHASE_ALIGN (0x00000001u)

#define CSL_PLLC_PLLCMD_RESETVAL         (0x00000000u)

/* PLLSTAT */


#define CSL_PLLC_PLLSTAT_STABLE_MASK     (0x00000004u)
#define CSL_PLLC_PLLSTAT_STABLE_SHIFT    (0x00000002u)
#define CSL_PLLC_PLLSTAT_STABLE_RESETVAL (0x00000000u)
/*----STABLE Tokens----*/
#define CSL_PLLC_PLLSTAT_STABLE_OSC_NOT_STABLE (0x00000000u)
#define CSL_PLLC_PLLSTAT_STABLE_OSC_STABLE (0x00000001u)


#define CSL_PLLC_PLLSTAT_GOSTAT_MASK     (0x00000001u)
#define CSL_PLLC_PLLSTAT_GOSTAT_SHIFT    (0x00000000u)
#define CSL_PLLC_PLLSTAT_GOSTAT_RESETVAL (0x00000000u)
/*----GOSTAT Tokens----*/
#define CSL_PLLC_PLLSTAT_GOSTAT_NONE     (0x00000000u)
#define CSL_PLLC_PLLSTAT_GOSTAT_INPROG   (0x00000001u)

#define CSL_PLLC_PLLSTAT_RESETVAL        (0x00000000u)

/* ALNCTL */


#define CSL_PLLC_ALNCTL_ALN7_MASK        (0x00000040u)
#define CSL_PLLC_ALNCTL_ALN7_SHIFT       (0x00000006u)
#define CSL_PLLC_ALNCTL_ALN7_RESETVAL    (0x00000001u)
/*----ALN7 Tokens----*/
#define CSL_PLLC_ALNCTL_ALN7_NO          (0x00000000u)
#define CSL_PLLC_ALNCTL_ALN7_YES         (0x00000001u)

#define CSL_PLLC_ALNCTL_ALN6_MASK        (0x00000020u)
#define CSL_PLLC_ALNCTL_ALN6_SHIFT       (0x00000005u)
#define CSL_PLLC_ALNCTL_ALN6_RESETVAL    (0x00000001u)
/*----ALN6 Tokens----*/
#define CSL_PLLC_ALNCTL_ALN6_NO          (0x00000000u)
#define CSL_PLLC_ALNCTL_ALN6_YES         (0x00000001u)

#define CSL_PLLC_ALNCTL_ALN5_MASK        (0x00000010u)
#define CSL_PLLC_ALNCTL_ALN5_SHIFT       (0x00000004u)
#define CSL_PLLC_ALNCTL_ALN5_RESETVAL    (0x00000001u)
/*----ALN5 Tokens----*/
#define CSL_PLLC_ALNCTL_ALN5_NO          (0x00000000u)
#define CSL_PLLC_ALNCTL_ALN5_YES         (0x00000001u)

#define CSL_PLLC_ALNCTL_ALN4_MASK        (0x00000008u)
#define CSL_PLLC_ALNCTL_ALN4_SHIFT       (0x00000003u)
#define CSL_PLLC_ALNCTL_ALN4_RESETVAL    (0x00000001u)
/*----ALN4 Tokens----*/
#define CSL_PLLC_ALNCTL_ALN4_NO          (0x00000000u)
#define CSL_PLLC_ALNCTL_ALN4_YES         (0x00000001u)

#define CSL_PLLC_ALNCTL_ALN3_MASK        (0x00000004u)
#define CSL_PLLC_ALNCTL_ALN3_SHIFT       (0x00000002u)
#define CSL_PLLC_ALNCTL_ALN3_RESETVAL    (0x00000001u)
/*----ALN3 Tokens----*/
#define CSL_PLLC_ALNCTL_ALN3_NO          (0x00000000u)
#define CSL_PLLC_ALNCTL_ALN3_YES         (0x00000001u)

#define CSL_PLLC_ALNCTL_ALN2_MASK        (0x00000002u)
#define CSL_PLLC_ALNCTL_ALN2_SHIFT       (0x00000001u)
#define CSL_PLLC_ALNCTL_ALN2_RESETVAL    (0x00000001u)
/*----ALN2 Tokens----*/
#define CSL_PLLC_ALNCTL_ALN2_NO          (0x00000000u)
#define CSL_PLLC_ALNCTL_ALN2_YES         (0x00000001u)

#define CSL_PLLC_ALNCTL_ALN1_MASK        (0x00000001u)
#define CSL_PLLC_ALNCTL_ALN1_SHIFT       (0x00000000u)
#define CSL_PLLC_ALNCTL_ALN1_RESETVAL    (0x00000001u)
/*----ALN1 Tokens----*/
#define CSL_PLLC_ALNCTL_ALN1_NO          (0x00000000u)
#define CSL_PLLC_ALNCTL_ALN1_YES         (0x00000001u)

#define CSL_PLLC_ALNCTL_RESETVAL         (0x0000007Fu)

/* DCHANGE */


#define CSL_PLLC_DCHANGE_SYS7_MASK       (0x00000040u)
#define CSL_PLLC_DCHANGE_SYS7_SHIFT      (0x00000006u)
#define CSL_PLLC_DCHANGE_SYS7_RESETVAL   (0x00000000u)
/*----SYS7 Tokens----*/
#define CSL_PLLC_DCHANGE_SYS7_NO         (0x00000000u)
#define CSL_PLLC_DCHANGE_SYS7_YES        (0x00000001u)

#define CSL_PLLC_DCHANGE_SYS6_MASK       (0x00000020u)
#define CSL_PLLC_DCHANGE_SYS6_SHIFT      (0x00000005u)
#define CSL_PLLC_DCHANGE_SYS6_RESETVAL   (0x00000000u)
/*----SYS6 Tokens----*/
#define CSL_PLLC_DCHANGE_SYS6_NO         (0x00000000u)
#define CSL_PLLC_DCHANGE_SYS6_YES        (0x00000001u)

#define CSL_PLLC_DCHANGE_SYS5_MASK       (0x00000010u)
#define CSL_PLLC_DCHANGE_SYS5_SHIFT      (0x00000004u)
#define CSL_PLLC_DCHANGE_SYS5_RESETVAL   (0x00000000u)
/*----SYS5 Tokens----*/
#define CSL_PLLC_DCHANGE_SYS5_NO         (0x00000000u)
#define CSL_PLLC_DCHANGE_SYS5_YES        (0x00000001u)

#define CSL_PLLC_DCHANGE_SYS4_MASK       (0x00000008u)
#define CSL_PLLC_DCHANGE_SYS4_SHIFT      (0x00000003u)
#define CSL_PLLC_DCHANGE_SYS4_RESETVAL   (0x00000000u)
/*----SYS4 Tokens----*/
#define CSL_PLLC_DCHANGE_SYS4_NO         (0x00000000u)
#define CSL_PLLC_DCHANGE_SYS4_YES        (0x00000001u)

#define CSL_PLLC_DCHANGE_SYS3_MASK       (0x00000004u)
#define CSL_PLLC_DCHANGE_SYS3_SHIFT      (0x00000002u)
#define CSL_PLLC_DCHANGE_SYS3_RESETVAL   (0x00000000u)
/*----SYS3 Tokens----*/
#define CSL_PLLC_DCHANGE_SYS3_NO         (0x00000000u)
#define CSL_PLLC_DCHANGE_SYS3_YES        (0x00000001u)

#define CSL_PLLC_DCHANGE_SYS2_MASK       (0x00000002u)
#define CSL_PLLC_DCHANGE_SYS2_SHIFT      (0x00000001u)
#define CSL_PLLC_DCHANGE_SYS2_RESETVAL   (0x00000000u)
/*----SYS2 Tokens----*/
#define CSL_PLLC_DCHANGE_SYS2_NO         (0x00000000u)
#define CSL_PLLC_DCHANGE_SYS2_YES        (0x00000001u)

#define CSL_PLLC_DCHANGE_SYS1_MASK       (0x00000001u)
#define CSL_PLLC_DCHANGE_SYS1_SHIFT      (0x00000000u)
#define CSL_PLLC_DCHANGE_SYS1_RESETVAL   (0x00000000u)
/*----SYS1 Tokens----*/
#define CSL_PLLC_DCHANGE_SYS1_NO         (0x00000000u)
#define CSL_PLLC_DCHANGE_SYS1_YES        (0x00000001u)

#define CSL_PLLC_DCHANGE_RESETVAL        (0x00000000u)

/* CKEN */


#define CSL_PLLC_CKEN_AUXEN_MASK         (0x00000001u)
#define CSL_PLLC_CKEN_AUXEN_SHIFT        (0x00000000u)
#define CSL_PLLC_CKEN_AUXEN_RESETVAL     (0x00000001u)
/*----AUXEN Tokens----*/
#define CSL_PLLC_CKEN_AUXEN_DISABLE      (0x00000000u)
#define CSL_PLLC_CKEN_AUXEN_ENABLE       (0x00000001u)

#define CSL_PLLC_CKEN_RESETVAL           (0x00000001u)

/* CKSTAT */


#define CSL_PLLC_CKSTAT_AUXEN_MASK       (0x00000001u)
#define CSL_PLLC_CKSTAT_AUXEN_SHIFT      (0x00000000u)
#define CSL_PLLC_CKSTAT_AUXEN_RESETVAL   (0x00000000u)
/*----AUXEN Tokens----*/
#define CSL_PLLC_CKSTAT_AUXEN_OFF        (0x00000000u)
#define CSL_PLLC_CKSTAT_AUXEN_ON         (0x00000001u)

#define CSL_PLLC_CKSTAT_RESETVAL         (0x00000000u)

/* SYSTAT */


#define CSL_PLLC_SYSTAT_SYS7ON_MASK      (0x00000040u)
#define CSL_PLLC_SYSTAT_SYS7ON_SHIFT     (0x00000006u)
#define CSL_PLLC_SYSTAT_SYS7ON_RESETVAL  (0x00000001u)
/*----SYS7ON Tokens----*/
#define CSL_PLLC_SYSTAT_SYS7ON_OFF       (0x00000000u)
#define CSL_PLLC_SYSTAT_SYS7ON_ON        (0x00000001u)

#define CSL_PLLC_SYSTAT_SYS6ON_MASK      (0x00000020u)
#define CSL_PLLC_SYSTAT_SYS6ON_SHIFT     (0x00000005u)
#define CSL_PLLC_SYSTAT_SYS6ON_RESETVAL  (0x00000001u)
/*----SYS6ON Tokens----*/
#define CSL_PLLC_SYSTAT_SYS6ON_OFF       (0x00000000u)
#define CSL_PLLC_SYSTAT_SYS6ON_ON        (0x00000001u)

#define CSL_PLLC_SYSTAT_SYS5ON_MASK      (0x00000010u)
#define CSL_PLLC_SYSTAT_SYS5ON_SHIFT     (0x00000004u)
#define CSL_PLLC_SYSTAT_SYS5ON_RESETVAL  (0x00000001u)
/*----SYS5ON Tokens----*/
#define CSL_PLLC_SYSTAT_SYS5ON_OFF       (0x00000000u)
#define CSL_PLLC_SYSTAT_SYS5ON_ON        (0x00000001u)

#define CSL_PLLC_SYSTAT_SYS4ON_MASK      (0x00000008u)
#define CSL_PLLC_SYSTAT_SYS4ON_SHIFT     (0x00000003u)
#define CSL_PLLC_SYSTAT_SYS4ON_RESETVAL  (0x00000001u)
/*----SYS4ON Tokens----*/
#define CSL_PLLC_SYSTAT_SYS4ON_OFF       (0x00000000u)
#define CSL_PLLC_SYSTAT_SYS4ON_ON        (0x00000001u)

#define CSL_PLLC_SYSTAT_SYS3ON_MASK      (0x00000004u)
#define CSL_PLLC_SYSTAT_SYS3ON_SHIFT     (0x00000002u)
#define CSL_PLLC_SYSTAT_SYS3ON_RESETVAL  (0x00000001u)
/*----SYS3ON Tokens----*/
#define CSL_PLLC_SYSTAT_SYS3ON_OFF       (0x00000000u)
#define CSL_PLLC_SYSTAT_SYS3ON_ON        (0x00000001u)

#define CSL_PLLC_SYSTAT_SYS2ON_MASK      (0x00000002u)
#define CSL_PLLC_SYSTAT_SYS2ON_SHIFT     (0x00000001u)
#define CSL_PLLC_SYSTAT_SYS2ON_RESETVAL  (0x00000001u)
/*----SYS2ON Tokens----*/
#define CSL_PLLC_SYSTAT_SYS2ON_OFF       (0x00000000u)
#define CSL_PLLC_SYSTAT_SYS2ON_ON        (0x00000001u)

#define CSL_PLLC_SYSTAT_SYS1ON_MASK      (0x00000001u)
#define CSL_PLLC_SYSTAT_SYS1ON_SHIFT     (0x00000000u)
#define CSL_PLLC_SYSTAT_SYS1ON_RESETVAL  (0x00000001u)
/*----SYS1ON Tokens----*/
#define CSL_PLLC_SYSTAT_SYS1ON_OFF       (0x00000000u)
#define CSL_PLLC_SYSTAT_SYS1ON_ON        (0x00000001u)

#define CSL_PLLC_SYSTAT_RESETVAL         (0x0000007Fu)

/* PLLDIV4 */


#define CSL_PLLC_PLLDIV4_D4EN_MASK       (0x00008000u)
#define CSL_PLLC_PLLDIV4_D4EN_SHIFT      (0x0000000Fu)
#define CSL_PLLC_PLLDIV4_D4EN_RESETVAL   (0x00000001u)
/*----D4EN Tokens----*/
#define CSL_PLLC_PLLDIV4_D4EN_DISABLE    (0x00000000u)
#define CSL_PLLC_PLLDIV4_D4EN_ENABLE     (0x00000001u)


#define CSL_PLLC_PLLDIV4_RATIO_MASK      (0x0000001Fu)
#define CSL_PLLC_PLLDIV4_RATIO_SHIFT     (0x00000000u)
#define CSL_PLLC_PLLDIV4_RATIO_RESETVAL  (0x00000003u)

#define CSL_PLLC_PLLDIV4_RESETVAL        (0x00008003u)

/* PLLDIV5 */


#define CSL_PLLC_PLLDIV5_D5EN_MASK       (0x00008000u)
#define CSL_PLLC_PLLDIV5_D5EN_SHIFT      (0x0000000Fu)
#define CSL_PLLC_PLLDIV5_D5EN_RESETVAL   (0x00000001u)
/*----D5EN Tokens----*/
#define CSL_PLLC_PLLDIV5_D5EN_DISABLE    (0x00000000u)
#define CSL_PLLC_PLLDIV5_D5EN_ENABLE     (0x00000001u)


#define CSL_PLLC_PLLDIV5_RATIO_MASK      (0x0000001Fu)
#define CSL_PLLC_PLLDIV5_RATIO_SHIFT     (0x00000000u)
#define CSL_PLLC_PLLDIV5_RATIO_RESETVAL  (0x00000005u)

#define CSL_PLLC_PLLDIV5_RESETVAL        (0x00008005u)

/* PLLDIV6 */


#define CSL_PLLC_PLLDIV6_D6EN_MASK       (0x00008000u)
#define CSL_PLLC_PLLDIV6_D6EN_SHIFT      (0x0000000Fu)
#define CSL_PLLC_PLLDIV6_D6EN_RESETVAL   (0x00000001u)
/*----D6EN Tokens----*/
#define CSL_PLLC_PLLDIV6_D6EN_DISABLE    (0x00000000u)
#define CSL_PLLC_PLLDIV6_D6EN_ENABLE     (0x00000001u)


#define CSL_PLLC_PLLDIV6_RATIO_MASK      (0x0000001Fu)
#define CSL_PLLC_PLLDIV6_RATIO_SHIFT     (0x00000000u)
#define CSL_PLLC_PLLDIV6_RATIO_RESETVAL  (0x00000000u)

#define CSL_PLLC_PLLDIV6_RESETVAL        (0x00008000u)

/* PLLDIV7 */


#define CSL_PLLC_PLLDIV7_D7EN_MASK       (0x00008000u)
#define CSL_PLLC_PLLDIV7_D7EN_SHIFT      (0x0000000Fu)
#define CSL_PLLC_PLLDIV7_D7EN_RESETVAL   (0x00000001u)
/*----D7EN Tokens----*/
#define CSL_PLLC_PLLDIV7_D7EN_DISABLE    (0x00000000u)
#define CSL_PLLC_PLLDIV7_D7EN_ENABLE     (0x00000001u)


#define CSL_PLLC_PLLDIV7_RATIO_MASK      (0x0000001Fu)
#define CSL_PLLC_PLLDIV7_RATIO_SHIFT     (0x00000000u)
#define CSL_PLLC_PLLDIV7_RATIO_RESETVAL  (0x00000005u)

#define CSL_PLLC_PLLDIV7_RESETVAL        (0x00008005u)

#ifdef __cplusplus
}
#endif

#endif
