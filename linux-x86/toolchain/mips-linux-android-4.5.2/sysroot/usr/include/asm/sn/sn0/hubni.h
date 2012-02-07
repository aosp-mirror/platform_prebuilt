/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _ASM_SGI_SN0_HUBNI_H
#define _ASM_SGI_SN0_HUBNI_H

#ifndef __ASSEMBLY__
#include <linux/types.h>
#endif

#define NI_BASE 0x600000
#define NI_BASE_TABLES 0x630000

#define NI_STATUS_REV_ID 0x600000  
#define NI_PORT_RESET 0x600008  
#define NI_PROTECTION 0x600010  
#define NI_GLOBAL_PARMS 0x600018  
#define NI_SCRATCH_REG0 0x600100  
#define NI_SCRATCH_REG1 0x600108  
#define NI_DIAG_PARMS 0x600110  

#define NI_VECTOR_PARMS 0x600200  
#define NI_VECTOR 0x600208  
#define NI_VECTOR_DATA 0x600210  
#define NI_VECTOR_STATUS 0x600300  
#define NI_RETURN_VECTOR 0x600308  
#define NI_VECTOR_READ_DATA 0x600310  
#define NI_VECTOR_CLEAR 0x600380  

#define NI_IO_PROTECT 0x600400  
#define NI_IO_PROT_OVRRD 0x600408  

#define NI_AGE_CPU0_MEMORY 0x600500  
#define NI_AGE_CPU0_PIO 0x600508  
#define NI_AGE_CPU1_MEMORY 0x600510  
#define NI_AGE_CPU1_PIO 0x600518  
#define NI_AGE_GBR_MEMORY 0x600520  
#define NI_AGE_GBR_PIO 0x600528  
#define NI_AGE_IO_MEMORY 0x600530  
#define NI_AGE_IO_PIO 0x600538  
#define NI_AGE_REG_MIN NI_AGE_CPU0_MEMORY
#define NI_AGE_REG_MAX NI_AGE_IO_PIO

#define NI_PORT_PARMS 0x608000  
#define NI_PORT_ERROR 0x608008  
#define NI_PORT_ERROR_CLEAR 0x608088  

#define NI_META_TABLE0 0x638000  
#define NI_META_TABLE(_x) (NI_META_TABLE0 + (8 * (_x)))
#define NI_META_ENTRIES 32

#define NI_LOCAL_TABLE0 0x638100  
#define NI_LOCAL_TABLE(_x) (NI_LOCAL_TABLE0 + (8 * (_x)))
#define NI_LOCAL_ENTRIES 16

#define NSRI_8BITMODE_SHFT 30
#define NSRI_8BITMODE_MASK (UINT64_CAST 0x1 << 30)
#define NSRI_LINKUP_SHFT 29
#define NSRI_LINKUP_MASK (UINT64_CAST 0x1 << 29)
#define NSRI_DOWNREASON_SHFT 28  
#define NSRI_DOWNREASON_MASK (UINT64_CAST 0x1 << 28)  
#define NSRI_MORENODES_SHFT 18
#define NSRI_MORENODES_MASK (UINT64_CAST 1 << 18)  
#define MORE_MEMORY 0
#define MORE_NODES 1
#define NSRI_REGIONSIZE_SHFT 17
#define NSRI_REGIONSIZE_MASK (UINT64_CAST 1 << 17)  
#define REGIONSIZE_FINE 1
#define REGIONSIZE_COARSE 0
#define NSRI_NODEID_SHFT 8
#define NSRI_NODEID_MASK (UINT64_CAST 0x1ff << 8) 
#define NSRI_REV_SHFT 4
#define NSRI_REV_MASK (UINT64_CAST 0xf << 4)  
#define NSRI_CHIPID_SHFT 0
#define NSRI_CHIPID_MASK (UINT64_CAST 0xf)  

#define NASID_TO_FINEREG_SHFT 0
#define NASID_TO_COARSEREG_SHFT 3

#define NPR_PORTRESET (UINT64_CAST 1 << 7)  
#define NPR_LINKRESET (UINT64_CAST 1 << 1)  
#define NPR_LOCALRESET (UINT64_CAST 1)  

#define NPROT_RESETOK (UINT64_CAST 1)

#define NGP_MAXRETRY_SHFT 48  
#define NGP_MAXRETRY_MASK (UINT64_CAST 0x3ff << 48)
#define NGP_TAILTOWRAP_SHFT 32  
#define NGP_TAILTOWRAP_MASK (UINT64_CAST 0xffff << 32)

#define NGP_CREDITTOVAL_SHFT 16  
#define NGP_CREDITTOVAL_MASK (UINT64_CAST 0xf << 16)
#define NGP_TAILTOVAL_SHFT 4  
#define NGP_TAILTOVAL_MASK (UINT64_CAST 0xf << 4)

#define NDP_PORTTORESET (UINT64_CAST 1 << 18)  
#define NDP_LLP8BITMODE (UINT64_CAST 1 << 12)  
#define NDP_PORTDISABLE (UINT64_CAST 1 << 6)  
#define NDP_SENDERROR (UINT64_CAST 1)  

#define NVP_PIOID_SHFT 40
#define NVP_PIOID_MASK (UINT64_CAST 0x3ff << 40)
#define NVP_WRITEID_SHFT 32
#define NVP_WRITEID_MASK (UINT64_CAST 0xff << 32)
#define NVP_ADDRESS_MASK (UINT64_CAST 0xffff8)  
#define NVP_TYPE_SHFT 0
#define NVP_TYPE_MASK (UINT64_CAST 0x3)

#define NVS_VALID (UINT64_CAST 1 << 63)
#define NVS_OVERRUN (UINT64_CAST 1 << 62)
#define NVS_TARGET_SHFT 51
#define NVS_TARGET_MASK (UINT64_CAST 0x3ff << 51)
#define NVS_PIOID_SHFT 40
#define NVS_PIOID_MASK (UINT64_CAST 0x3ff << 40)
#define NVS_WRITEID_SHFT 32
#define NVS_WRITEID_MASK (UINT64_CAST 0xff << 32)
#define NVS_ADDRESS_MASK (UINT64_CAST 0xfffffff8)  
#define NVS_TYPE_SHFT 0
#define NVS_TYPE_MASK (UINT64_CAST 0x7)
#define NVS_ERROR_MASK (UINT64_CAST 0x4)  

#define PIOTYPE_READ 0  
#define PIOTYPE_WRITE 1  
#define PIOTYPE_UNDEFINED 2  
#define PIOTYPE_EXCHANGE 3  
#define PIOTYPE_ADDR_ERR 4  
#define PIOTYPE_CMD_ERR 5  
#define PIOTYPE_PROT_ERR 6  
#define PIOTYPE_UNKNOWN 7  

#define NAGE_VCH_SHFT 10
#define NAGE_VCH_MASK (UINT64_CAST 3 << 10)
#define NAGE_CC_SHFT 8
#define NAGE_CC_MASK (UINT64_CAST 3 << 8)
#define NAGE_AGE_SHFT 0
#define NAGE_AGE_MASK (UINT64_CAST 0xff)
#define NAGE_MASK (NAGE_VCH_MASK | NAGE_CC_MASK | NAGE_AGE_MASK)

#define VCHANNEL_A 0
#define VCHANNEL_B 1
#define VCHANNEL_ANY 2

#define NPP_NULLTO_SHFT 10
#define NPP_NULLTO_MASK (UINT64_CAST 0x3f << 16)
#define NPP_MAXBURST_SHFT 0
#define NPP_MAXBURST_MASK (UINT64_CAST 0x3ff)
#define NPP_RESET_DFLT_HUB20 ((UINT64_CAST 1 << NPP_NULLTO_SHFT) |   (UINT64_CAST 0x3f0 << NPP_MAXBURST_SHFT))
#define NPP_RESET_DEFAULTS ((UINT64_CAST 6 << NPP_NULLTO_SHFT) |   (UINT64_CAST 0x3f0 << NPP_MAXBURST_SHFT))

#define NPE_LINKRESET (UINT64_CAST 1 << 37)
#define NPE_INTERNALERROR (UINT64_CAST 1 << 36)
#define NPE_BADMESSAGE (UINT64_CAST 1 << 35)
#define NPE_BADDEST (UINT64_CAST 1 << 34)
#define NPE_FIFOOVERFLOW (UINT64_CAST 1 << 33)
#define NPE_CREDITTO_SHFT 28
#define NPE_CREDITTO_MASK (UINT64_CAST 0xf << 28)
#define NPE_TAILTO_SHFT 24
#define NPE_TAILTO_MASK (UINT64_CAST 0xf << 24)
#define NPE_RETRYCOUNT_SHFT 16
#define NPE_RETRYCOUNT_MASK (UINT64_CAST 0xff << 16)
#define NPE_CBERRCOUNT_SHFT 8
#define NPE_CBERRCOUNT_MASK (UINT64_CAST 0xff << 8)
#define NPE_SNERRCOUNT_SHFT 0
#define NPE_SNERRCOUNT_MASK (UINT64_CAST 0xff << 0)
#define NPE_MASK 0x3effffffff

#define NPE_COUNT_MAX 0xff

#define NPE_FATAL_ERRORS (NPE_LINKRESET | NPE_INTERNALERROR |   NPE_BADMESSAGE | NPE_BADDEST |   NPE_FIFOOVERFLOW | NPE_CREDITTO_MASK |   NPE_TAILTO_MASK)

#define NMT_EXIT_PORT_MASK (UINT64_CAST 0xf)

#define NLT_EXIT_PORT_MASK (UINT64_CAST 0xf)

#ifndef __ASSEMBLY__

typedef union hubni_port_error_u {
 u64 nipe_reg_value;
 struct {
 u64 nipe_rsvd: 26,
 nipe_lnk_reset: 1,
 nipe_intl_err: 1,
 nipe_bad_msg: 1,
 nipe_bad_dest: 1,
 nipe_fifo_ovfl: 1,
 nipe_rsvd1: 1,
 nipe_credit_to: 4,
 nipe_tail_to: 4,
 nipe_retry_cnt: 8,
 nipe_cb_cnt: 8,
 nipe_sn_cnt: 8;
 } nipe_fields_s;
} hubni_port_error_t;

#define NI_LLP_RETRY_MAX 0xff
#define NI_LLP_CB_MAX 0xff
#define NI_LLP_SN_MAX 0xff

#endif

#endif
