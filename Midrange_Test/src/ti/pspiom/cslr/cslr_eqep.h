/*
 * cslr_eqep.h
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


#ifndef _CSLR_EQEP_H_
#define _CSLR_EQEP_H_

#include <ti/pspiom/cslr/cslr.h>
#include <ti/pspiom/cslr/tistdtypes.h>


/* Minimum unit = 2 bytes */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 QPOSCNT;
    volatile Uint32 QPOSINIT;
    volatile Uint32 QPOSMAX;
    volatile Uint32 QPOSCMP;
    volatile Uint32 QPOSILAT;
    volatile Uint32 QPOSSLAT;
    volatile Uint32 QPOSLAT;
    volatile Uint32 QUTMR;
    volatile Uint32 QUPRD;
    volatile Uint16 QWDTMR;
    volatile Uint16 QWDPRD;
    volatile Uint16 QDECCTL;
    volatile Uint16 QEPCTL;
    volatile Uint16 QCAPCTL;
    volatile Uint16 QPOSCTL;
    volatile Uint16 QEINT;
    volatile Uint16 QFLG;
    volatile Uint16 QCLR;
    volatile Uint16 QFRC;
    volatile Uint16 QEPSTS;
    volatile Uint16 QCTMR;
    volatile Uint16 QCPRD;
    volatile Uint16 QCTMRLAT;
    volatile Uint16 QCPRDLAT;
    volatile Uint16 RSVD0[13];
    volatile Uint32 REVID;
} CSL_EqepRegs;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_EqepRegs         *CSL_EqepRegsOvly;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* QPOSCNT */

#define CSL_EQEP_QPOSCNT_QPOSCNT_MASK (0xFFFFFFFFu)
#define CSL_EQEP_QPOSCNT_QPOSCNT_SHIFT (0x00000000u)
#define CSL_EQEP_QPOSCNT_QPOSCNT_RESETVAL (0x00000000u)

#define CSL_EQEP_QPOSCNT_RESETVAL (0x00000000u)

/* QPOSINIT */

#define CSL_EQEP_QPOSINIT_QPOSINIT_MASK (0xFFFFFFFFu)
#define CSL_EQEP_QPOSINIT_QPOSINIT_SHIFT (0x00000000u)
#define CSL_EQEP_QPOSINIT_QPOSINIT_RESETVAL (0x00000000u)

#define CSL_EQEP_QPOSINIT_RESETVAL (0x00000000u)

/* QPOSMAX */

#define CSL_EQEP_QPOSMAX_QPOSMAX_MASK (0xFFFFFFFFu)
#define CSL_EQEP_QPOSMAX_QPOSMAX_SHIFT (0x00000000u)
#define CSL_EQEP_QPOSMAX_QPOSMAX_RESETVAL (0x00000000u)

#define CSL_EQEP_QPOSMAX_RESETVAL (0x00000000u)

/* QPOSCMP */

#define CSL_EQEP_QPOSCMP_QPOSCMP_MASK (0xFFFFFFFFu)
#define CSL_EQEP_QPOSCMP_QPOSCMP_SHIFT (0x00000000u)
#define CSL_EQEP_QPOSCMP_QPOSCMP_RESETVAL (0x00000000u)

#define CSL_EQEP_QPOSCMP_RESETVAL (0x00000000u)

/* QPOSILAT */

#define CSL_EQEP_QPOSILAT_QPOSILAT_MASK (0xFFFFFFFFu)
#define CSL_EQEP_QPOSILAT_QPOSILAT_SHIFT (0x00000000u)
#define CSL_EQEP_QPOSILAT_QPOSILAT_RESETVAL (0x00000000u)

#define CSL_EQEP_QPOSILAT_RESETVAL (0x00000000u)

/* QPOSSLAT */

#define CSL_EQEP_QPOSSLAT_QPOSSLAT_MASK (0xFFFFFFFFu)
#define CSL_EQEP_QPOSSLAT_QPOSSLAT_SHIFT (0x00000000u)
#define CSL_EQEP_QPOSSLAT_QPOSSLAT_RESETVAL (0x00000000u)

#define CSL_EQEP_QPOSSLAT_RESETVAL (0x00000000u)

/* QPOSLAT */

#define CSL_EQEP_QPOSLAT_QPOSLAT_MASK (0xFFFFFFFFu)
#define CSL_EQEP_QPOSLAT_QPOSLAT_SHIFT (0x00000000u)
#define CSL_EQEP_QPOSLAT_QPOSLAT_RESETVAL (0x00000000u)

#define CSL_EQEP_QPOSLAT_RESETVAL (0x00000000u)

/* QUTMR */

#define CSL_EQEP_QUTMR_QUTMR_MASK (0xFFFFFFFFu)
#define CSL_EQEP_QUTMR_QUTMR_SHIFT (0x00000000u)
#define CSL_EQEP_QUTMR_QUTMR_RESETVAL (0x00000000u)

#define CSL_EQEP_QUTMR_RESETVAL (0x00000000u)

/* QUPRD */

#define CSL_EQEP_QUPRD_QUPRD_MASK (0xFFFFFFFFu)
#define CSL_EQEP_QUPRD_QUPRD_SHIFT (0x00000000u)
#define CSL_EQEP_QUPRD_QUPRD_RESETVAL (0x00000000u)

#define CSL_EQEP_QUPRD_RESETVAL (0x00000000u)

/* QWDTMR */

#define CSL_EQEP_QWDTMR_QWDTMR_MASK (0xFFFFu)
#define CSL_EQEP_QWDTMR_QWDTMR_SHIFT (0x0000u)
#define CSL_EQEP_QWDTMR_QWDTMR_RESETVAL (0x0000u)

#define CSL_EQEP_QWDTMR_RESETVAL (0x0000u)

/* QWDPRD */

#define CSL_EQEP_QWDPRD_QWDPRD_MASK (0xFFFFu)
#define CSL_EQEP_QWDPRD_QWDPRD_SHIFT (0x0000u)
#define CSL_EQEP_QWDPRD_QWDPRD_RESETVAL (0x0000u)

#define CSL_EQEP_QWDPRD_RESETVAL (0x0000u)

/* QDECCTL */

#define CSL_EQEP_QDECCTL_QSRC_MASK (0xC000u)
#define CSL_EQEP_QDECCTL_QSRC_SHIFT (0x000Eu)
#define CSL_EQEP_QDECCTL_QSRC_RESETVAL (0x0000u)
#define CSL_EQEP_QDECCTL_QSRC_QUADCOUNT (0x0000u)
#define CSL_EQEP_QDECCTL_QSRC_DIRCOUNT (0x0001u)
#define CSL_EQEP_QDECCTL_QSRC_UPCOUNT (0x0002u)
#define CSL_EQEP_QDECCTL_QSRC_DOWNCOUNT (0x0003u)

#define CSL_EQEP_QDECCTL_SOEN_MASK (0x2000u)
#define CSL_EQEP_QDECCTL_SOEN_SHIFT (0x000Du)
#define CSL_EQEP_QDECCTL_SOEN_RESETVAL (0x0000u)
#define CSL_EQEP_QDECCTL_SOEN_DISABLE (0x0000u)
#define CSL_EQEP_QDECCTL_SOEN_ENABLE (0x0001u)

#define CSL_EQEP_QDECCTL_SPSEL_MASK (0x1000u)
#define CSL_EQEP_QDECCTL_SPSEL_SHIFT (0x000Cu)
#define CSL_EQEP_QDECCTL_SPSEL_RESETVAL (0x0000u)
#define CSL_EQEP_QDECCTL_SPSEL_INDEX (0x0000u)
#define CSL_EQEP_QDECCTL_SPSEL_STROBE (0x0001u)

#define CSL_EQEP_QDECCTL_XCR_MASK (0x0800u)
#define CSL_EQEP_QDECCTL_XCR_SHIFT (0x000Bu)
#define CSL_EQEP_QDECCTL_XCR_RESETVAL (0x0000u)
#define CSL_EQEP_QDECCTL_XCR_2XRESOLUTION (0x0000u)
#define CSL_EQEP_QDECCTL_XCR_1XRESOLUTION (0x0001u)

#define CSL_EQEP_QDECCTL_SWAP_MASK (0x0400u)
#define CSL_EQEP_QDECCTL_SWAP_SHIFT (0x000Au)
#define CSL_EQEP_QDECCTL_SWAP_RESETVAL (0x0000u)
#define CSL_EQEP_QDECCTL_SWAP_NOSWAP (0x0000u)
#define CSL_EQEP_QDECCTL_SWAP_SWAP (0x0001u)

#define CSL_EQEP_QDECCTL_IGATE_MASK (0x0200u)
#define CSL_EQEP_QDECCTL_IGATE_SHIFT (0x0009u)
#define CSL_EQEP_QDECCTL_IGATE_RESETVAL (0x0000u)
#define CSL_EQEP_QDECCTL_IGATE_DISABLE (0x0000u)
#define CSL_EQEP_QDECCTL_IGATE_GATE (0x0001u)

#define CSL_EQEP_QDECCTL_QAP_MASK (0x0100u)
#define CSL_EQEP_QDECCTL_QAP_SHIFT (0x0008u)
#define CSL_EQEP_QDECCTL_QAP_RESETVAL (0x0000u)
#define CSL_EQEP_QDECCTL_QAP_NOEFFECT (0x0000u)
#define CSL_EQEP_QDECCTL_QAP_NEGATEQEPA (0x0001u)

#define CSL_EQEP_QDECCTL_QBP_MASK (0x0080u)
#define CSL_EQEP_QDECCTL_QBP_SHIFT (0x0007u)
#define CSL_EQEP_QDECCTL_QBP_RESETVAL (0x0000u)
#define CSL_EQEP_QDECCTL_QBP_NOEFFECT (0x0000u)
#define CSL_EQEP_QDECCTL_QBP_NEGATEQEPB (0x0001u)

#define CSL_EQEP_QDECCTL_QIP_MASK (0x0040u)
#define CSL_EQEP_QDECCTL_QIP_SHIFT (0x0006u)
#define CSL_EQEP_QDECCTL_QIP_RESETVAL (0x0000u)
#define CSL_EQEP_QDECCTL_QIP_NOEFFECT (0x0000u)
#define CSL_EQEP_QDECCTL_QIP_NEGATEQEPI (0x0001u)

#define CSL_EQEP_QDECCTL_QSP_MASK (0x0020u)
#define CSL_EQEP_QDECCTL_QSP_SHIFT (0x0005u)
#define CSL_EQEP_QDECCTL_QSP_RESETVAL (0x0000u)
#define CSL_EQEP_QDECCTL_QSP_NOEFFECT (0x0000u)
#define CSL_EQEP_QDECCTL_QSP_NEGATEQEPS (0x0001u)


#define CSL_EQEP_QDECCTL_RESETVAL (0x0000u)

/* QEPCTL */

#define CSL_EQEP_QEPCTL_FREESOFT_MASK (0xC000u)
#define CSL_EQEP_QEPCTL_FREESOFT_SHIFT (0x000Eu)
#define CSL_EQEP_QEPCTL_FREESOFT_RESETVAL (0x0000u)
#define CSL_EQEP_QEPCTL_FREESOFT_STOPNOW (0x0000u)
#define CSL_EQEP_QEPCTL_FREESOFT_COUNTUNTIL (0x0001u)
#define CSL_EQEP_QEPCTL_FREESOFT_IGNORE (0x0002u)
#define CSL_EQEP_QEPCTL_FREESOFT_IGNORE1 (0x0003u)

#define CSL_EQEP_QEPCTL_PCRM_MASK (0x3000u)
#define CSL_EQEP_QEPCTL_PCRM_SHIFT (0x000Cu)
#define CSL_EQEP_QEPCTL_PCRM_RESETVAL (0x0000u)
#define CSL_EQEP_QEPCTL_PCRM_ONINDEX (0x0000u)
#define CSL_EQEP_QEPCTL_PCRM_ONMAXPOS (0x0001u)
#define CSL_EQEP_QEPCTL_PCRM_ON1STINDEX (0x0002u)
#define CSL_EQEP_QEPCTL_PCRM_ONUTEVT (0x0003u)

#define CSL_EQEP_QEPCTL_SEI_MASK (0x0C00u)
#define CSL_EQEP_QEPCTL_SEI_SHIFT (0x000Au)
#define CSL_EQEP_QEPCTL_SEI_RESETVAL (0x0000u)
#define CSL_EQEP_QEPCTL_SEI_NOEFFECT (0x0000u)
#define CSL_EQEP_QEPCTL_SEI_NOEFFECT1 (0x0001u)
#define CSL_EQEP_QEPCTL_SEI_ONREDGE (0x0002u)
#define CSL_EQEP_QEPCTL_SEI_ONFEDGE (0x0003u)

#define CSL_EQEP_QEPCTL_IEI_MASK (0x0300u)
#define CSL_EQEP_QEPCTL_IEI_SHIFT (0x0008u)
#define CSL_EQEP_QEPCTL_IEI_RESETVAL (0x0000u)
#define CSL_EQEP_QEPCTL_IEI_NOEFFECT (0x0000u)
#define CSL_EQEP_QEPCTL_IEI_NOEFFECT1 (0x0001u)
#define CSL_EQEP_QEPCTL_IEI_ONREDGE (0x0002u)
#define CSL_EQEP_QEPCTL_IEI_ONFEDGE (0x0003u)

#define CSL_EQEP_QEPCTL_SWI_MASK (0x0080u)
#define CSL_EQEP_QEPCTL_SWI_SHIFT (0x0007u)
#define CSL_EQEP_QEPCTL_SWI_RESETVAL (0x0000u)
#define CSL_EQEP_QEPCTL_SWI_NOEFFECT (0x0000u)
#define CSL_EQEP_QEPCTL_SWI_INIT (0x0001u)

#define CSL_EQEP_QEPCTL_SEL_MASK (0x0040u)
#define CSL_EQEP_QEPCTL_SEL_SHIFT (0x0006u)
#define CSL_EQEP_QEPCTL_SEL_RESETVAL (0x0000u)
#define CSL_EQEP_QEPCTL_SEL_ONREDGE (0x0000u)
#define CSL_EQEP_QEPCTL_SEL_ONFEDGE (0x0001u)

#define CSL_EQEP_QEPCTL_IEL_MASK (0x0030u)
#define CSL_EQEP_QEPCTL_IEL_SHIFT (0x0004u)
#define CSL_EQEP_QEPCTL_IEL_RESETVAL (0x0000u)
#define CSL_EQEP_QEPCTL_IEL_RESERVED (0x0000u)
#define CSL_EQEP_QEPCTL_IEL_ONREDGE (0x0001u)
#define CSL_EQEP_QEPCTL_IEL_ONFEDGE (0x0002u)
#define CSL_EQEP_QEPCTL_IEL_SWINDEX (0x0003u)

#define CSL_EQEP_QEPCTL_QPEN_MASK (0x0008u)
#define CSL_EQEP_QEPCTL_QPEN_SHIFT (0x0003u)
#define CSL_EQEP_QEPCTL_QPEN_RESETVAL (0x0000u)
#define CSL_EQEP_QEPCTL_QPEN_SWRESET (0x0000u)
#define CSL_EQEP_QEPCTL_QPEN_ENPOSCNT (0x0001u)

#define CSL_EQEP_QEPCTL_QCLM_MASK (0x0004u)
#define CSL_EQEP_QEPCTL_QCLM_SHIFT (0x0002u)
#define CSL_EQEP_QEPCTL_QCLM_RESETVAL (0x0000u)
#define CSL_EQEP_QEPCTL_QCLM_ONPOSCNT (0x0000u)
#define CSL_EQEP_QEPCTL_QCLM_ONUTIMEOUT (0x0001u)

#define CSL_EQEP_QEPCTL_UTE_MASK (0x0002u)
#define CSL_EQEP_QEPCTL_UTE_SHIFT (0x0001u)
#define CSL_EQEP_QEPCTL_UTE_RESETVAL (0x0000u)
#define CSL_EQEP_QEPCTL_UTE_DISABLE (0x0000u)
#define CSL_EQEP_QEPCTL_UTE_ENABLE (0x0001u)

#define CSL_EQEP_QEPCTL_WDE_MASK (0x0001u)
#define CSL_EQEP_QEPCTL_WDE_SHIFT (0x0000u)
#define CSL_EQEP_QEPCTL_WDE_RESETVAL (0x0000u)
#define CSL_EQEP_QEPCTL_WDE_DISABLE (0x0000u)
#define CSL_EQEP_QEPCTL_WDE_ENABLE (0x0001u)

#define CSL_EQEP_QEPCTL_RESETVAL (0x0000u)

/* QCAPCTL */

#define CSL_EQEP_QCAPCTL_CEN_MASK (0x8000u)
#define CSL_EQEP_QCAPCTL_CEN_SHIFT (0x000Fu)
#define CSL_EQEP_QCAPCTL_CEN_RESETVAL (0x0000u)
#define CSL_EQEP_QCAPCTL_CEN_DISABLED (0x0000u)
#define CSL_EQEP_QCAPCTL_CEN_ENABLED (0x0001u)


#define CSL_EQEP_QCAPCTL_CCPS_MASK (0x0070u)
#define CSL_EQEP_QCAPCTL_CCPS_SHIFT (0x0004u)
#define CSL_EQEP_QCAPCTL_CCPS_RESETVAL (0x0000u)
#define CSL_EQEP_QCAPCTL_CCPS_SYSCLKOUTDIV1 (0x0000u)
#define CSL_EQEP_QCAPCTL_CCPS_SYSCLKOUTDIV2 (0x0001u)
#define CSL_EQEP_QCAPCTL_CCPS_SYSCLKOUTDIV4 (0x0002u)
#define CSL_EQEP_QCAPCTL_CCPS_SYSCLKOUTDIV8 (0x0003u)
#define CSL_EQEP_QCAPCTL_CCPS_SYSCLKOUTDIV16 (0x0004u)
#define CSL_EQEP_QCAPCTL_CCPS_SYSCLKOUTDIV32 (0x0005u)
#define CSL_EQEP_QCAPCTL_CCPS_SYSCLKOUTDIV64 (0x0006u)
#define CSL_EQEP_QCAPCTL_CCPS_SYSCLKOUTDIV128 (0x0007u)

#define CSL_EQEP_QCAPCTL_UPPS_MASK (0x000Fu)
#define CSL_EQEP_QCAPCTL_UPPS_SHIFT (0x0000u)
#define CSL_EQEP_QCAPCTL_UPPS_RESETVAL (0x0000u)
#define CSL_EQEP_QCAPCTL_UPPS_QCLKDIV1 (0x0000u)
#define CSL_EQEP_QCAPCTL_UPPS_QCLKDIV2 (0x0001u)
#define CSL_EQEP_QCAPCTL_UPPS_QCLKDIV4 (0x0002u)
#define CSL_EQEP_QCAPCTL_UPPS_QCLKDIV8 (0x0003u)
#define CSL_EQEP_QCAPCTL_UPPS_QCLKDIV16 (0x0004u)
#define CSL_EQEP_QCAPCTL_UPPS_QCLKDIV32 (0x0005u)
#define CSL_EQEP_QCAPCTL_UPPS_QCLKDIV64 (0x0006u)
#define CSL_EQEP_QCAPCTL_UPPS_QCLKDIV128 (0x0007u)
#define CSL_EQEP_QCAPCTL_UPPS_QCLKDIV256 (0x0008u)
#define CSL_EQEP_QCAPCTL_UPPS_QCLKDIV512 (0x0009u)
#define CSL_EQEP_QCAPCTL_UPPS_QCLKDIV1024 (0x000Au)
#define CSL_EQEP_QCAPCTL_UPPS_QCLKDIV2048 (0x000Bu)
#define CSL_EQEP_QCAPCTL_UPPS_RESERVED (0x000Cu)
#define CSL_EQEP_QCAPCTL_UPPS_RESERVED1 (0x000Du)
#define CSL_EQEP_QCAPCTL_UPPS_RESERVED2 (0x000Eu)
#define CSL_EQEP_QCAPCTL_UPPS_RESERVED3 (0x000Fu)

#define CSL_EQEP_QCAPCTL_RESETVAL (0x0000u)

/* QPOSCTL */

#define CSL_EQEP_QPOSCTL_PCSHDW_MASK (0x8000u)
#define CSL_EQEP_QPOSCTL_PCSHDW_SHIFT (0x000Fu)
#define CSL_EQEP_QPOSCTL_PCSHDW_RESETVAL (0x0000u)
#define CSL_EQEP_QPOSCTL_PCSHDW_DISABLED (0x0000u)
#define CSL_EQEP_QPOSCTL_PCSHDW_ENABLED (0x0001u)

#define CSL_EQEP_QPOSCTL_PCLOAD_MASK (0x4000u)
#define CSL_EQEP_QPOSCTL_PCLOAD_SHIFT (0x000Eu)
#define CSL_EQEP_QPOSCTL_PCLOAD_RESETVAL (0x0000u)
#define CSL_EQEP_QPOSCTL_PCLOAD_ONEQUALZERO (0x0000u)
#define CSL_EQEP_QPOSCTL_PCLOAD_ONEQUALQPOSCMP (0x0001u)

#define CSL_EQEP_QPOSCTL_PCPOL_MASK (0x2000u)
#define CSL_EQEP_QPOSCTL_PCPOL_SHIFT (0x000Du)
#define CSL_EQEP_QPOSCTL_PCPOL_RESETVAL (0x0000u)
#define CSL_EQEP_QPOSCTL_PCPOL_ACTIVEHIGH (0x0000u)
#define CSL_EQEP_QPOSCTL_PCPOL_ACTIVELOW (0x0001u)

#define CSL_EQEP_QPOSCTL_PCE_MASK (0x1000u)
#define CSL_EQEP_QPOSCTL_PCE_SHIFT (0x000Cu)
#define CSL_EQEP_QPOSCTL_PCE_RESETVAL (0x0000u)
#define CSL_EQEP_QPOSCTL_PCE_DISABLE (0x0000u)
#define CSL_EQEP_QPOSCTL_PCE_ENABLE (0x0001u)

#define CSL_EQEP_QPOSCTL_PCSPW_MASK (0x0FFFu)
#define CSL_EQEP_QPOSCTL_PCSPW_SHIFT (0x0000u)
#define CSL_EQEP_QPOSCTL_PCSPW_RESETVAL (0x0000u)

#define CSL_EQEP_QPOSCTL_RESETVAL (0x0000u)

/* QEINT */


#define CSL_EQEP_QEINT_UTO_MASK (0x0800u)
#define CSL_EQEP_QEINT_UTO_SHIFT (0x000Bu)
#define CSL_EQEP_QEINT_UTO_RESETVAL (0x0000u)
#define CSL_EQEP_QEINT_UTO_DISABLED (0x0000u)
#define CSL_EQEP_QEINT_UTO_ENABLED (0x0001u)

#define CSL_EQEP_QEINT_IEL_MASK (0x0400u)
#define CSL_EQEP_QEINT_IEL_SHIFT (0x000Au)
#define CSL_EQEP_QEINT_IEL_RESETVAL (0x0000u)
#define CSL_EQEP_QEINT_IEL_DISABLED (0x0000u)
#define CSL_EQEP_QEINT_IEL_ENABLED (0x0001u)

#define CSL_EQEP_QEINT_SEL_MASK (0x0200u)
#define CSL_EQEP_QEINT_SEL_SHIFT (0x0009u)
#define CSL_EQEP_QEINT_SEL_RESETVAL (0x0000u)
#define CSL_EQEP_QEINT_SEL_DISABLED (0x0000u)
#define CSL_EQEP_QEINT_SEL_ENABLED (0x0001u)

#define CSL_EQEP_QEINT_PCM_MASK (0x0100u)
#define CSL_EQEP_QEINT_PCM_SHIFT (0x0008u)
#define CSL_EQEP_QEINT_PCM_RESETVAL (0x0000u)
#define CSL_EQEP_QEINT_PCM_DISABLED (0x0000u)
#define CSL_EQEP_QEINT_PCM_ENABLED (0x0001u)

#define CSL_EQEP_QEINT_PCR_MASK (0x0080u)
#define CSL_EQEP_QEINT_PCR_SHIFT (0x0007u)
#define CSL_EQEP_QEINT_PCR_RESETVAL (0x0000u)
#define CSL_EQEP_QEINT_PCR_DISABLED (0x0000u)
#define CSL_EQEP_QEINT_PCR_ENABLED (0x0001u)

#define CSL_EQEP_QEINT_PCO_MASK (0x0040u)
#define CSL_EQEP_QEINT_PCO_SHIFT (0x0006u)
#define CSL_EQEP_QEINT_PCO_RESETVAL (0x0000u)
#define CSL_EQEP_QEINT_PCO_DISABLED (0x0000u)
#define CSL_EQEP_QEINT_PCO_ENABLED (0x0001u)

#define CSL_EQEP_QEINT_PCU_MASK (0x0020u)
#define CSL_EQEP_QEINT_PCU_SHIFT (0x0005u)
#define CSL_EQEP_QEINT_PCU_RESETVAL (0x0000u)
#define CSL_EQEP_QEINT_PCU_DISABLED (0x0000u)
#define CSL_EQEP_QEINT_PCU_ENABLED (0x0001u)

#define CSL_EQEP_QEINT_WTO_MASK (0x0010u)
#define CSL_EQEP_QEINT_WTO_SHIFT (0x0004u)
#define CSL_EQEP_QEINT_WTO_RESETVAL (0x0000u)
#define CSL_EQEP_QEINT_WTO_DISABLED (0x0000u)
#define CSL_EQEP_QEINT_WTO_ENABLED (0x0001u)

#define CSL_EQEP_QEINT_QDC_MASK (0x0008u)
#define CSL_EQEP_QEINT_QDC_SHIFT (0x0003u)
#define CSL_EQEP_QEINT_QDC_RESETVAL (0x0000u)
#define CSL_EQEP_QEINT_QDC_DISABLED (0x0000u)
#define CSL_EQEP_QEINT_QDC_ENABLED (0x0001u)

#define CSL_EQEP_QEINT_PHE_MASK (0x0004u)
#define CSL_EQEP_QEINT_PHE_SHIFT (0x0002u)
#define CSL_EQEP_QEINT_PHE_RESETVAL (0x0000u)
#define CSL_EQEP_QEINT_PHE_DISABLED (0x0000u)
#define CSL_EQEP_QEINT_PHE_ENABLED (0x0001u)

#define CSL_EQEP_QEINT_PCE_MASK (0x0002u)
#define CSL_EQEP_QEINT_PCE_SHIFT (0x0001u)
#define CSL_EQEP_QEINT_PCE_RESETVAL (0x0000u)
#define CSL_EQEP_QEINT_PCE_DISABLED (0x0000u)
#define CSL_EQEP_QEINT_PCE_ENABLED (0x0001u)


#define CSL_EQEP_QEINT_RESETVAL (0x0000u)

/* QFLG */


#define CSL_EQEP_QFLG_UTO_MASK (0x0800u)
#define CSL_EQEP_QFLG_UTO_SHIFT (0x000Bu)
#define CSL_EQEP_QFLG_UTO_RESETVAL (0x0000u)
#define CSL_EQEP_QFLG_UTO_NOINT (0x0000u)
#define CSL_EQEP_QFLG_UTO_INT (0x0001u)

#define CSL_EQEP_QFLG_IEL_MASK (0x0400u)
#define CSL_EQEP_QFLG_IEL_SHIFT (0x000Au)
#define CSL_EQEP_QFLG_IEL_RESETVAL (0x0000u)
#define CSL_EQEP_QFLG_IEL_NOINT (0x0000u)
#define CSL_EQEP_QFLG_IEL_INT (0x0001u)

#define CSL_EQEP_QFLG_SEL_MASK (0x0200u)
#define CSL_EQEP_QFLG_SEL_SHIFT (0x0009u)
#define CSL_EQEP_QFLG_SEL_RESETVAL (0x0000u)
#define CSL_EQEP_QFLG_SEL_NOINT (0x0000u)
#define CSL_EQEP_QFLG_SEL_INT (0x0001u)

#define CSL_EQEP_QFLG_PCM_MASK (0x0100u)
#define CSL_EQEP_QFLG_PCM_SHIFT (0x0008u)
#define CSL_EQEP_QFLG_PCM_RESETVAL (0x0000u)
#define CSL_EQEP_QFLG_PCM_NOINT (0x0000u)
#define CSL_EQEP_QFLG_PCM_INT (0x0001u)

#define CSL_EQEP_QFLG_PCR_MASK (0x0080u)
#define CSL_EQEP_QFLG_PCR_SHIFT (0x0007u)
#define CSL_EQEP_QFLG_PCR_RESETVAL (0x0000u)
#define CSL_EQEP_QFLG_PCR_NOINT (0x0000u)
#define CSL_EQEP_QFLG_PCR_INT (0x0001u)

#define CSL_EQEP_QFLG_PCO_MASK (0x0040u)
#define CSL_EQEP_QFLG_PCO_SHIFT (0x0006u)
#define CSL_EQEP_QFLG_PCO_RESETVAL (0x0000u)
#define CSL_EQEP_QFLG_PCO_NOINT (0x0000u)
#define CSL_EQEP_QFLG_PCO_INT (0x0001u)

#define CSL_EQEP_QFLG_PCU_MASK (0x0020u)
#define CSL_EQEP_QFLG_PCU_SHIFT (0x0005u)
#define CSL_EQEP_QFLG_PCU_RESETVAL (0x0000u)
#define CSL_EQEP_QFLG_PCU_NOINT (0x0000u)
#define CSL_EQEP_QFLG_PCU_INT (0x0001u)

#define CSL_EQEP_QFLG_WTO_MASK (0x0010u)
#define CSL_EQEP_QFLG_WTO_SHIFT (0x0004u)
#define CSL_EQEP_QFLG_WTO_RESETVAL (0x0000u)
#define CSL_EQEP_QFLG_WTO_NOINT (0x0000u)
#define CSL_EQEP_QFLG_WTO_INT (0x0001u)

#define CSL_EQEP_QFLG_QDC_MASK (0x0008u)
#define CSL_EQEP_QFLG_QDC_SHIFT (0x0003u)
#define CSL_EQEP_QFLG_QDC_RESETVAL (0x0000u)
#define CSL_EQEP_QFLG_QDC_NOINT (0x0000u)
#define CSL_EQEP_QFLG_QDC_INT (0x0001u)

#define CSL_EQEP_QFLG_PHE_MASK (0x0004u)
#define CSL_EQEP_QFLG_PHE_SHIFT (0x0002u)
#define CSL_EQEP_QFLG_PHE_RESETVAL (0x0000u)
#define CSL_EQEP_QFLG_PHE_NOINT (0x0000u)
#define CSL_EQEP_QFLG_PHE_INT (0x0001u)

#define CSL_EQEP_QFLG_PCE_MASK (0x0002u)
#define CSL_EQEP_QFLG_PCE_SHIFT (0x0001u)
#define CSL_EQEP_QFLG_PCE_RESETVAL (0x0000u)
#define CSL_EQEP_QFLG_PCE_NOINT (0x0000u)
#define CSL_EQEP_QFLG_PCE_INT (0x0001u)

#define CSL_EQEP_QFLG_INT_MASK (0x0001u)
#define CSL_EQEP_QFLG_INT_SHIFT (0x0000u)
#define CSL_EQEP_QFLG_INT_RESETVAL (0x0000u)
#define CSL_EQEP_QFLG_INT_NOINT (0x0000u)
#define CSL_EQEP_QFLG_INT_INT (0x0001u)

#define CSL_EQEP_QFLG_RESETVAL (0x0000u)

/* QCLR */


#define CSL_EQEP_QCLR_UTO_MASK (0x0800u)
#define CSL_EQEP_QCLR_UTO_SHIFT (0x000Bu)
#define CSL_EQEP_QCLR_UTO_RESETVAL (0x0000u)
#define CSL_EQEP_QCLR_UTO_NOEFFECT (0x0000u)
#define CSL_EQEP_QCLR_UTO_CLEAR (0x0001u)

#define CSL_EQEP_QCLR_IEL_MASK (0x0400u)
#define CSL_EQEP_QCLR_IEL_SHIFT (0x000Au)
#define CSL_EQEP_QCLR_IEL_RESETVAL (0x0000u)
#define CSL_EQEP_QCLR_IEL_NOEFFECT (0x0000u)
#define CSL_EQEP_QCLR_IEL_CLEAR (0x0001u)

#define CSL_EQEP_QCLR_SEL_MASK (0x0200u)
#define CSL_EQEP_QCLR_SEL_SHIFT (0x0009u)
#define CSL_EQEP_QCLR_SEL_RESETVAL (0x0000u)
#define CSL_EQEP_QCLR_SEL_NOEFFECT (0x0000u)
#define CSL_EQEP_QCLR_SEL_CLEAR (0x0001u)

#define CSL_EQEP_QCLR_PCM_MASK (0x0100u)
#define CSL_EQEP_QCLR_PCM_SHIFT (0x0008u)
#define CSL_EQEP_QCLR_PCM_RESETVAL (0x0000u)
#define CSL_EQEP_QCLR_PCM_NOEFFECT (0x0000u)
#define CSL_EQEP_QCLR_PCM_CLEAR (0x0001u)

#define CSL_EQEP_QCLR_PCR_MASK (0x0080u)
#define CSL_EQEP_QCLR_PCR_SHIFT (0x0007u)
#define CSL_EQEP_QCLR_PCR_RESETVAL (0x0000u)
#define CSL_EQEP_QCLR_PCR_NOEFFECT (0x0000u)
#define CSL_EQEP_QCLR_PCR_CLEAR (0x0001u)

#define CSL_EQEP_QCLR_PCO_MASK (0x0040u)
#define CSL_EQEP_QCLR_PCO_SHIFT (0x0006u)
#define CSL_EQEP_QCLR_PCO_RESETVAL (0x0000u)
#define CSL_EQEP_QCLR_PCO_NOEFFECT (0x0000u)
#define CSL_EQEP_QCLR_PCO_CLEAR (0x0001u)

#define CSL_EQEP_QCLR_PCU_MASK (0x0020u)
#define CSL_EQEP_QCLR_PCU_SHIFT (0x0005u)
#define CSL_EQEP_QCLR_PCU_RESETVAL (0x0000u)
#define CSL_EQEP_QCLR_PCU_NOEFFECT (0x0000u)
#define CSL_EQEP_QCLR_PCU_CLEAR (0x0001u)

#define CSL_EQEP_QCLR_WTO_MASK (0x0010u)
#define CSL_EQEP_QCLR_WTO_SHIFT (0x0004u)
#define CSL_EQEP_QCLR_WTO_RESETVAL (0x0000u)
#define CSL_EQEP_QCLR_WTO_NOEFFECT (0x0000u)
#define CSL_EQEP_QCLR_WTO_CLEAR (0x0001u)

#define CSL_EQEP_QCLR_QDC_MASK (0x0008u)
#define CSL_EQEP_QCLR_QDC_SHIFT (0x0003u)
#define CSL_EQEP_QCLR_QDC_RESETVAL (0x0000u)
#define CSL_EQEP_QCLR_QDC_NOEFFECT (0x0000u)
#define CSL_EQEP_QCLR_QDC_CLEAR (0x0001u)

#define CSL_EQEP_QCLR_PHE_MASK (0x0004u)
#define CSL_EQEP_QCLR_PHE_SHIFT (0x0002u)
#define CSL_EQEP_QCLR_PHE_RESETVAL (0x0000u)
#define CSL_EQEP_QCLR_PHE_NOEFFECT (0x0000u)
#define CSL_EQEP_QCLR_PHE_CLEAR (0x0001u)

#define CSL_EQEP_QCLR_PCE_MASK (0x0002u)
#define CSL_EQEP_QCLR_PCE_SHIFT (0x0001u)
#define CSL_EQEP_QCLR_PCE_RESETVAL (0x0000u)
#define CSL_EQEP_QCLR_PCE_NOEFFECT (0x0000u)
#define CSL_EQEP_QCLR_PCE_CLEAR (0x0001u)

#define CSL_EQEP_QCLR_INT_MASK (0x0001u)
#define CSL_EQEP_QCLR_INT_SHIFT (0x0000u)
#define CSL_EQEP_QCLR_INT_RESETVAL (0x0000u)
#define CSL_EQEP_QCLR_INT_NOEFFECT (0x0000u)
#define CSL_EQEP_QCLR_INT_CLEAR (0x0001u)

#define CSL_EQEP_QCLR_RESETVAL (0x0000u)

/* QFRC */


#define CSL_EQEP_QFRC_UTO_MASK (0x0800u)
#define CSL_EQEP_QFRC_UTO_SHIFT (0x000Bu)
#define CSL_EQEP_QFRC_UTO_RESETVAL (0x0000u)
#define CSL_EQEP_QFRC_UTO_NOEFFECT (0x0000u)
#define CSL_EQEP_QFRC_UTO_FORCE (0x0001u)

#define CSL_EQEP_QFRC_IEL_MASK (0x0400u)
#define CSL_EQEP_QFRC_IEL_SHIFT (0x000Au)
#define CSL_EQEP_QFRC_IEL_RESETVAL (0x0000u)
#define CSL_EQEP_QFRC_IEL_NOEFFECT (0x0000u)
#define CSL_EQEP_QFRC_IEL_FORCE (0x0001u)

#define CSL_EQEP_QFRC_SEL_MASK (0x0200u)
#define CSL_EQEP_QFRC_SEL_SHIFT (0x0009u)
#define CSL_EQEP_QFRC_SEL_RESETVAL (0x0000u)
#define CSL_EQEP_QFRC_SEL_NOEFFECT (0x0000u)
#define CSL_EQEP_QFRC_SEL_FORCE (0x0001u)

#define CSL_EQEP_QFRC_PCM_MASK (0x0100u)
#define CSL_EQEP_QFRC_PCM_SHIFT (0x0008u)
#define CSL_EQEP_QFRC_PCM_RESETVAL (0x0000u)
#define CSL_EQEP_QFRC_PCM_NOEFFECT (0x0000u)
#define CSL_EQEP_QFRC_PCM_FORCE (0x0001u)

#define CSL_EQEP_QFRC_PCR_MASK (0x0080u)
#define CSL_EQEP_QFRC_PCR_SHIFT (0x0007u)
#define CSL_EQEP_QFRC_PCR_RESETVAL (0x0000u)
#define CSL_EQEP_QFRC_PCR_NOEFFECT (0x0000u)
#define CSL_EQEP_QFRC_PCR_FORCE (0x0001u)

#define CSL_EQEP_QFRC_PCO_MASK (0x0040u)
#define CSL_EQEP_QFRC_PCO_SHIFT (0x0006u)
#define CSL_EQEP_QFRC_PCO_RESETVAL (0x0000u)
#define CSL_EQEP_QFRC_PCO_NOEFFECT (0x0000u)
#define CSL_EQEP_QFRC_PCO_FORCE (0x0001u)

#define CSL_EQEP_QFRC_PCU_MASK (0x0020u)
#define CSL_EQEP_QFRC_PCU_SHIFT (0x0005u)
#define CSL_EQEP_QFRC_PCU_RESETVAL (0x0000u)
#define CSL_EQEP_QFRC_PCU_NOEFFECT (0x0000u)
#define CSL_EQEP_QFRC_PCU_FORCE (0x0001u)

#define CSL_EQEP_QFRC_WTO_MASK (0x0010u)
#define CSL_EQEP_QFRC_WTO_SHIFT (0x0004u)
#define CSL_EQEP_QFRC_WTO_RESETVAL (0x0000u)
#define CSL_EQEP_QFRC_WTO_NOEFFECT (0x0000u)
#define CSL_EQEP_QFRC_WTO_FORCE (0x0001u)

#define CSL_EQEP_QFRC_QDC_MASK (0x0008u)
#define CSL_EQEP_QFRC_QDC_SHIFT (0x0003u)
#define CSL_EQEP_QFRC_QDC_RESETVAL (0x0000u)
#define CSL_EQEP_QFRC_QDC_NOEFFECT (0x0000u)
#define CSL_EQEP_QFRC_QDC_FORCE (0x0001u)

#define CSL_EQEP_QFRC_PHE_MASK (0x0004u)
#define CSL_EQEP_QFRC_PHE_SHIFT (0x0002u)
#define CSL_EQEP_QFRC_PHE_RESETVAL (0x0000u)
#define CSL_EQEP_QFRC_PHE_NOEFFECT (0x0000u)
#define CSL_EQEP_QFRC_PHE_FORCE (0x0001u)

#define CSL_EQEP_QFRC_PCE_MASK (0x0002u)
#define CSL_EQEP_QFRC_PCE_SHIFT (0x0001u)
#define CSL_EQEP_QFRC_PCE_RESETVAL (0x0000u)
#define CSL_EQEP_QFRC_PCE_NOEFFECT (0x0000u)
#define CSL_EQEP_QFRC_PCE_FORCE (0x0001u)


#define CSL_EQEP_QFRC_RESETVAL (0x0000u)

/* QEPSTS */


#define CSL_EQEP_QEPSTS_UPEVNT_MASK (0x0080u)
#define CSL_EQEP_QEPSTS_UPEVNT_SHIFT (0x0007u)
#define CSL_EQEP_QEPSTS_UPEVNT_RESETVAL (0x0000u)
#define CSL_EQEP_QEPSTS_UPEVNT_NOTDETECTED (0x0000u)
#define CSL_EQEP_QEPSTS_UPEVNT_DETECTED (0x0001u)

#define CSL_EQEP_QEPSTS_FDF_MASK (0x0040u)
#define CSL_EQEP_QEPSTS_FDF_SHIFT (0x0006u)
#define CSL_EQEP_QEPSTS_FDF_RESETVAL (0x0000u)
#define CSL_EQEP_QEPSTS_FDF_CNTRCLKWISE (0x0000u)
#define CSL_EQEP_QEPSTS_FDF_CLKWISE (0x0001u)

#define CSL_EQEP_QEPSTS_QDF_MASK (0x0020u)
#define CSL_EQEP_QEPSTS_QDF_SHIFT (0x0005u)
#define CSL_EQEP_QEPSTS_QDF_RESETVAL (0x0000u)
#define CSL_EQEP_QEPSTS_QDF_CNTRCLKWISE (0x0000u)
#define CSL_EQEP_QEPSTS_QDF_CLKWISE (0x0001u)

#define CSL_EQEP_QEPSTS_QDLF_MASK (0x0010u)
#define CSL_EQEP_QEPSTS_QDLF_SHIFT (0x0004u)
#define CSL_EQEP_QEPSTS_QDLF_RESETVAL (0x0000u)
#define CSL_EQEP_QEPSTS_QDLF_CNTRCLKWISE (0x0000u)
#define CSL_EQEP_QEPSTS_QDLF_CLKWISE (0x0001u)

#define CSL_EQEP_QEPSTS_COEF_MASK (0x0008u)
#define CSL_EQEP_QEPSTS_COEF_SHIFT (0x0003u)
#define CSL_EQEP_QEPSTS_COEF_RESETVAL (0x0001u)
#define CSL_EQEP_QEPSTS_COEF_WRITEONETOCLEAR (0x0000u)
#define CSL_EQEP_QEPSTS_COEF_OVERFLOW (0x0001u)

#define CSL_EQEP_QEPSTS_CDEF_MASK (0x0004u)
#define CSL_EQEP_QEPSTS_CDEF_SHIFT (0x0002u)
#define CSL_EQEP_QEPSTS_CDEF_RESETVAL (0x0001u)
#define CSL_EQEP_QEPSTS_CDEF_WRITEONETOCLEAR (0x0000u)
#define CSL_EQEP_QEPSTS_CDEF_DIRCHANGE (0x0001u)

#define CSL_EQEP_QEPSTS_FIMF_MASK (0x0002u)
#define CSL_EQEP_QEPSTS_FIMF_SHIFT (0x0001u)
#define CSL_EQEP_QEPSTS_FIMF_RESETVAL (0x0001u)
#define CSL_EQEP_QEPSTS_FIMF_WRITEONETOCLEAR (0x0000u)
#define CSL_EQEP_QEPSTS_FIMF_FIRSTINDEXPULSE (0x0001u)

#define CSL_EQEP_QEPSTS_PCEF_MASK (0x0001u)
#define CSL_EQEP_QEPSTS_PCEF_SHIFT (0x0000u)
#define CSL_EQEP_QEPSTS_PCEF_RESETVAL (0x0000u)
/*----PCEF Tokens----*/
#define CSL_EQEP_QEPSTS_PCEF_NOERROR (0x0000u)
#define CSL_EQEP_QEPSTS_PCEF_ERROR (0x0001u)

#define CSL_EQEP_QEPSTS_RESETVAL (0x000Eu)

/* QCTMR */

#define CSL_EQEP_QCTMR_QCTMR_MASK (0xFFFFu)
#define CSL_EQEP_QCTMR_QCTMR_SHIFT (0x0000u)
#define CSL_EQEP_QCTMR_QCTMR_RESETVAL (0x0000u)

#define CSL_EQEP_QCTMR_RESETVAL (0x0000u)

/* QCPRD */

#define CSL_EQEP_QCPRD_QCPRD_MASK (0xFFFFu)
#define CSL_EQEP_QCPRD_QCPRD_SHIFT (0x0000u)
#define CSL_EQEP_QCPRD_QCPRD_RESETVAL (0x0000u)

#define CSL_EQEP_QCPRD_RESETVAL (0x0000u)

/* QCTMRLAT */

#define CSL_EQEP_QCTMRLAT_QCTMRLAT_MASK (0xFFFFu)
#define CSL_EQEP_QCTMRLAT_QCTMRLAT_SHIFT (0x0000u)
#define CSL_EQEP_QCTMRLAT_QCTMRLAT_RESETVAL (0x0000u)

#define CSL_EQEP_QCTMRLAT_RESETVAL (0x0000u)

/* QCPRDLAT */

#define CSL_EQEP_QCPRDLAT_QCPDRLAT_MASK (0xFFFFu)
#define CSL_EQEP_QCPRDLAT_QCPDRLAT_SHIFT (0x0000u)
#define CSL_EQEP_QCPRDLAT_QCPDRLAT_RESETVAL (0x0000u)

#define CSL_EQEP_QCPRDLAT_RESETVAL (0x0000u)

/* REVID */

#define CSL_EQEP_REVID_REV_MASK          (0xFFFFFFFFu)
#define CSL_EQEP_REVID_REV_SHIFT         (0x00000000u)
#define CSL_EQEP_REVID_REV_RESETVAL      (0x44D31103u)

#define CSL_EQEP_REVID_RESETVAL          (0x44D31103u)

#endif
