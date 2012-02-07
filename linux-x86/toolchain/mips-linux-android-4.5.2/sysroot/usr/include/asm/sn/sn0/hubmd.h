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
#ifndef _ASM_SN_SN0_HUBMD_H
#define _ASM_SN_SN0_HUBMD_H

#define CACHE_SLINE_SIZE 128  

#define MAX_REGIONS 64

#define MD_PAGE_SIZE 4096  
#define MD_PAGE_NUM_SHFT 12  

#define MD_BASE 0x200000
#define MD_BASE_PERF 0x210000
#define MD_BASE_JUNK 0x220000

#define MD_IO_PROTECT 0x200000  
#define MD_IO_PROT_OVRRD 0x200008  
#define MD_HSPEC_PROTECT 0x200010  
#define MD_MEMORY_CONFIG 0x200018  
#define MD_REFRESH_CONTROL 0x200020  
#define MD_FANDOP_CAC_STAT 0x200028  
#define MD_MIG_DIFF_THRESH 0x200030  
#define MD_MIG_VALUE_THRESH 0x200038  
#define MD_MIG_CANDIDATE 0x200040  
#define MD_MIG_CANDIDATE_CLR 0x200048  
#define MD_DIR_ERROR 0x200050  
#define MD_DIR_ERROR_CLR 0x200058  
#define MD_PROTOCOL_ERROR 0x200060  
#define MD_PROTOCOL_ERROR_CLR 0x200068  
#define MD_MEM_ERROR 0x200070  
#define MD_MEM_ERROR_CLR 0x200078  
#define MD_MISC_ERROR 0x200080  
#define MD_MISC_ERROR_CLR 0x200088  
#define MD_MEM_DIMM_INIT 0x200090  
#define MD_DIR_DIMM_INIT 0x200098  
#define MD_MOQ_SIZE 0x2000a0  
#define MD_MLAN_CTL 0x2000a8  

#define MD_PERF_SEL 0x210000  
#define MD_PERF_CNT0 0x210010  
#define MD_PERF_CNT1 0x210018  
#define MD_PERF_CNT2 0x210020  
#define MD_PERF_CNT3 0x210028  
#define MD_PERF_CNT4 0x210030  
#define MD_PERF_CNT5 0x210038  

#define MD_UREG0_0 0x220000  
#define MD_UREG0_1 0x220008  
#define MD_UREG0_2 0x220010  
#define MD_UREG0_3 0x220018  
#define MD_UREG0_4 0x220020  
#define MD_UREG0_5 0x220028  
#define MD_UREG0_6 0x220030  
#define MD_UREG0_7 0x220038  

#define MD_SLOTID_USTAT 0x220048  
#define MD_LED0 0x220050  
#define MD_LED1 0x220058  

#define MD_UREG1_0 0x220080  
#define MD_UREG1_1 0x220088  
#define MD_UREG1_2 0x220090  
#define MD_UREG1_3 0x220098  
#define MD_UREG1_4 0x2200a0  
#define MD_UREG1_5 0x2200a8  
#define MD_UREG1_6 0x2200b0  
#define MD_UREG1_7 0x2200b8  
#define MD_UREG1_8 0x2200c0  
#define MD_UREG1_9 0x2200c8  
#define MD_UREG1_10 0x2200d0  
#define MD_UREG1_11 0x2200d8  
#define MD_UREG1_12 0x2200e0  
#define MD_UREG1_13 0x2200e8  
#define MD_UREG1_14 0x2200f0  
#define MD_UREG1_15 0x2200f8  

#define MD_MEM_BANKS 8  

#define MD_SIZE_EMPTY 0  
#define MD_SIZE_8MB 1
#define MD_SIZE_16MB 2
#define MD_SIZE_32MB 3  
#define MD_SIZE_64MB 4  
#define MD_SIZE_128MB 5  
#define MD_SIZE_256MB 6
#define MD_SIZE_512MB 7  
#define MD_SIZE_1GB 8
#define MD_SIZE_2GB 9
#define MD_SIZE_4GB 10

#define MD_SIZE_BYTES(size) ((size) == 0 ? 0 : 0x400000L << (size))
#define MD_SIZE_MBYTES(size) ((size) == 0 ? 0 : 4 << (size))

#define MMC_FPROM_CYC_SHFT 49  
#define MMC_FPROM_CYC_MASK (UINT64_CAST 31 << 49)  
#define MMC_FPROM_WR_SHFT 44  
#define MMC_FPROM_WR_MASK (UINT64_CAST 31 << 44)
#define MMC_UCTLR_CYC_SHFT 39
#define MMC_UCTLR_CYC_MASK (UINT64_CAST 31 << 39)
#define MMC_UCTLR_WR_SHFT 34
#define MMC_UCTLR_WR_MASK (UINT64_CAST 31 << 34)
#define MMC_DIMM0_SEL_SHFT 32
#define MMC_DIMM0_SEL_MASK (UINT64_CAST 3 << 32)
#define MMC_IO_PROT_EN_SHFT 31
#define MMC_IO_PROT_EN_MASK (UINT64_CAST 1 << 31)
#define MMC_IO_PROT (UINT64_CAST 1 << 31)
#define MMC_ARB_MLSS_SHFT 30
#define MMC_ARB_MLSS_MASK (UINT64_CAST 1 << 30)
#define MMC_ARB_MLSS (UINT64_CAST 1 << 30)
#define MMC_IGNORE_ECC_SHFT 29
#define MMC_IGNORE_ECC_MASK (UINT64_CAST 1 << 29)
#define MMC_IGNORE_ECC (UINT64_CAST 1 << 29)
#define MMC_DIR_PREMIUM_SHFT 28
#define MMC_DIR_PREMIUM_MASK (UINT64_CAST 1 << 28)
#define MMC_DIR_PREMIUM (UINT64_CAST 1 << 28)
#define MMC_REPLY_GUAR_SHFT 24
#define MMC_REPLY_GUAR_MASK (UINT64_CAST 15 << 24)
#define MMC_BANK_SHFT(_b) ((_b) * 3)
#define MMC_BANK_MASK(_b) (UINT64_CAST 7 << MMC_BANK_SHFT(_b))
#define MMC_BANK_ALL_MASK 0xffffff
#define MMC_RESET_DEFAULTS (UINT64_CAST 0x0f << MMC_FPROM_CYC_SHFT |   UINT64_CAST 0x07 << MMC_FPROM_WR_SHFT |   UINT64_CAST 0x1f << MMC_UCTLR_CYC_SHFT |   UINT64_CAST 0x0f << MMC_UCTLR_WR_SHFT |   MMC_IGNORE_ECC | MMC_DIR_PREMIUM |   UINT64_CAST 0x0f << MMC_REPLY_GUAR_SHFT |   MMC_BANK_ALL_MASK)

#define MRC_ENABLE_SHFT 63
#define MRC_ENABLE_MASK (UINT64_CAST 1 << 63)
#define MRC_ENABLE (UINT64_CAST 1 << 63)
#define MRC_COUNTER_SHFT 12
#define MRC_COUNTER_MASK (UINT64_CAST 0xfff << 12)
#define MRC_CNT_THRESH_MASK 0xfff
#define MRC_RESET_DEFAULTS (UINT64_CAST 0x400)

#define MDI_SELECT_SHFT 32
#define MDI_SELECT_MASK (UINT64_CAST 0x0f << 32)
#define MDI_DIMM_MODE_MASK (UINT64_CAST 0xfff)

#define MMS_RP_SIZE_SHFT 8
#define MMS_RP_SIZE_MASK (UINT64_CAST 0x3f << 8)
#define MMS_RQ_SIZE_SHFT 0
#define MMS_RQ_SIZE_MASK (UINT64_CAST 0x1f)
#define MMS_RESET_DEFAULTS (0x32 << 8 | 0x12)

#define MFC_VALID_SHFT 63
#define MFC_VALID_MASK (UINT64_CAST 1 << 63)
#define MFC_VALID (UINT64_CAST 1 << 63)
#define MFC_ADDR_SHFT 6
#define MFC_ADDR_MASK (UINT64_CAST 0x3ffffff)

#define MLAN_PHI1_SHFT 27
#define MLAN_PHI1_MASK (UINT64_CAST 0x7f << 27)
#define MLAN_PHI0_SHFT 20
#define MLAN_PHI0_MASK (UINT64_CAST 0x7f << 27)
#define MLAN_PULSE_SHFT 10
#define MLAN_PULSE_MASK (UINT64_CAST 0x3ff << 10)
#define MLAN_SAMPLE_SHFT 2
#define MLAN_SAMPLE_MASK (UINT64_CAST 0xff << 2)
#define MLAN_DONE_SHFT 1
#define MLAN_DONE_MASK 2
#define MLAN_DONE (UINT64_CAST 0x02)
#define MLAN_RD_DATA (UINT64_CAST 0x01)
#define MLAN_RESET_DEFAULTS (UINT64_CAST 0x31 << MLAN_PHI1_SHFT |   UINT64_CAST 0x31 << MLAN_PHI0_SHFT)

#define MSU_CORECLK_TST_SHFT 7  
#define MSU_CORECLK_TST_MASK (UINT64_CAST 1 << 7)
#define MSU_CORECLK_TST (UINT64_CAST 1 << 7)
#define MSU_CORECLK_SHFT 6  
#define MSU_CORECLK_MASK (UINT64_CAST 1 << 6)
#define MSU_CORECLK (UINT64_CAST 1 << 6)
#define MSU_NETSYNC_SHFT 5  
#define MSU_NETSYNC_MASK (UINT64_CAST 1 << 5)
#define MSU_NETSYNC (UINT64_CAST 1 << 5)
#define MSU_FPROMRDY_SHFT 4  
#define MSU_FPROMRDY_MASK (UINT64_CAST 1 << 4)
#define MSU_FPROMRDY (UINT64_CAST 1 << 4)
#define MSU_I2CINTR_SHFT 3  
#define MSU_I2CINTR_MASK (UINT64_CAST 1 << 3)
#define MSU_I2CINTR (UINT64_CAST 1 << 3)
#define MSU_SLOTID_MASK 0xff
#define MSU_SN0_SLOTID_SHFT 0  
#define MSU_SN0_SLOTID_MASK (UINT64_CAST 7)
#define MSU_SN00_SLOTID_SHFT 7
#define MSU_SN00_SLOTID_MASK (UINT64_CAST 0x80)

#define MSU_PIMM_PSC_SHFT 4
#define MSU_PIMM_PSC_MASK (0xf << MSU_PIMM_PSC_SHFT)

#define MD_MIG_DIFF_THRES_VALID_MASK (UINT64_CAST 0x1 << 63)
#define MD_MIG_DIFF_THRES_VALID_SHFT 63
#define MD_MIG_DIFF_THRES_VALUE_MASK (UINT64_CAST 0xfffff)

#define MD_MIG_VALUE_THRES_VALID_MASK (UINT64_CAST 0x1 << 63)
#define MD_MIG_VALUE_THRES_VALID_SHFT 63
#define MD_MIG_VALUE_THRES_VALUE_MASK (UINT64_CAST 0xfffff)

#define MD_MIG_CANDIDATE_VALID_MASK (UINT64_CAST 0x1 << 63)
#define MD_MIG_CANDIDATE_VALID_SHFT 63
#define MD_MIG_CANDIDATE_TYPE_MASK (UINT64_CAST 0x1 << 30)
#define MD_MIG_CANDIDATE_TYPE_SHFT 30
#define MD_MIG_CANDIDATE_OVERRUN_MASK (UINT64_CAST 0x1 << 29)
#define MD_MIG_CANDIDATE_OVERRUN_SHFT 29
#define MD_MIG_CANDIDATE_INITIATOR_MASK (UINT64_CAST 0x7ff << 18)
#define MD_MIG_CANDIDATE_INITIATOR_SHFT 18
#define MD_MIG_CANDIDATE_NODEID_MASK (UINT64_CAST 0x1ff << 20)
#define MD_MIG_CANDIDATE_NODEID_SHFT 20
#define MD_MIG_CANDIDATE_ADDR_MASK (UINT64_CAST 0x3ffff)
#define MD_MIG_CANDIDATE_ADDR_SHFT 14  

#define MD_BANK_SHFT 29  
#define MD_BANK_MASK (UINT64_CAST 7 << 29)
#define MD_BANK_SIZE (UINT64_CAST 1 << MD_BANK_SHFT)  
#define MD_BANK_OFFSET(_b) (UINT64_CAST (_b) << MD_BANK_SHFT)

#define MD_DIR_SHARED (UINT64_CAST 0x0)  
#define MD_DIR_POISONED (UINT64_CAST 0x1)  
#define MD_DIR_EXCLUSIVE (UINT64_CAST 0x2)  
#define MD_DIR_BUSY_SHARED (UINT64_CAST 0x3)  
#define MD_DIR_BUSY_EXCL (UINT64_CAST 0x4)  
#define MD_DIR_WAIT (UINT64_CAST 0x5)  
#define MD_DIR_UNOWNED (UINT64_CAST 0x7)  

#define MD_DIR_FORCE_ECC (UINT64_CAST 1 << 63)

#define MD_PDIR_MASK 0xffffffffffff  
#define MD_PDIR_ECC_SHFT 0  
#define MD_PDIR_ECC_MASK 0x7f
#define MD_PDIR_PRIO_SHFT 8  
#define MD_PDIR_PRIO_MASK (0xf << 8)
#define MD_PDIR_AX_SHFT 7  
#define MD_PDIR_AX_MASK (1 << 7)
#define MD_PDIR_AX (1 << 7)
#define MD_PDIR_FINE_SHFT 12  
#define MD_PDIR_FINE_MASK (1 << 12)
#define MD_PDIR_FINE (1 << 12)
#define MD_PDIR_OCT_SHFT 13  
#define MD_PDIR_OCT_MASK (7 << 13)
#define MD_PDIR_STATE_SHFT 13  
#define MD_PDIR_STATE_MASK (7 << 13)
#define MD_PDIR_ONECNT_SHFT 16  
#define MD_PDIR_ONECNT_MASK (0x3f << 16)
#define MD_PDIR_PTR_SHFT 22  
#define MD_PDIR_PTR_MASK (UINT64_CAST 0x7ff << 22)
#define MD_PDIR_VECMSB_SHFT 22  
#define MD_PDIR_VECMSB_BITMASK 0x3ffffff
#define MD_PDIR_VECMSB_BITSHFT 27
#define MD_PDIR_VECMSB_MASK (UINT64_CAST MD_PDIR_VECMSB_BITMASK << 22)
#define MD_PDIR_CWOFF_SHFT 7  
#define MD_PDIR_CWOFF_MASK (7 << 7)
#define MD_PDIR_VECLSB_SHFT 10  
#define MD_PDIR_VECLSB_BITMASK (UINT64_CAST 0x3fffffffff)
#define MD_PDIR_VECLSB_BITSHFT 0
#define MD_PDIR_VECLSB_MASK (MD_PDIR_VECLSB_BITMASK << 10)

#define MD_PDIR_INIT_LO (MD_DIR_UNOWNED << MD_PDIR_STATE_SHFT |   MD_PDIR_AX)
#define MD_PDIR_INIT_HI 0
#define MD_PDIR_INIT_PROT (MD_PROT_RW << MD_PPROT_IO_SHFT |   MD_PROT_RW << MD_PPROT_SHFT)

#define MD_SDIR_MASK 0xffff  
#define MD_SDIR_ECC_SHFT 0  
#define MD_SDIR_ECC_MASK 0x1f
#define MD_SDIR_PRIO_SHFT 6  
#define MD_SDIR_PRIO_MASK (1 << 6)
#define MD_SDIR_AX_SHFT 5  
#define MD_SDIR_AX_MASK (1 << 5)
#define MD_SDIR_AX (1 << 5)
#define MD_SDIR_STATE_SHFT 7  
#define MD_SDIR_STATE_MASK (7 << 7)
#define MD_SDIR_PTR_SHFT 10  
#define MD_SDIR_PTR_MASK (0x3f << 10)
#define MD_SDIR_CWOFF_SHFT 5  
#define MD_SDIR_CWOFF_MASK (7 << 5)
#define MD_SDIR_VECMSB_SHFT 11  
#define MD_SDIR_VECMSB_BITMASK 0x1f
#define MD_SDIR_VECMSB_BITSHFT 7
#define MD_SDIR_VECMSB_MASK (MD_SDIR_VECMSB_BITMASK << 11)
#define MD_SDIR_VECLSB_SHFT 5  
#define MD_SDIR_VECLSB_BITMASK 0x7ff
#define MD_SDIR_VECLSB_BITSHFT 0
#define MD_SDIR_VECLSB_MASK (MD_SDIR_VECLSB_BITMASK << 5)

#define MD_SDIR_INIT_LO (MD_DIR_UNOWNED << MD_SDIR_STATE_SHFT |   MD_SDIR_AX)
#define MD_SDIR_INIT_HI 0
#define MD_SDIR_INIT_PROT (MD_PROT_RW << MD_SPROT_SHFT)

#define MD_PROT_RW (UINT64_CAST 0x6)
#define MD_PROT_RO (UINT64_CAST 0x3)
#define MD_PROT_NO (UINT64_CAST 0x0)
#define MD_PROT_BAD (UINT64_CAST 0x5)

#define MD_PPROT_SHFT 0  
#define MD_PPROT_MASK 7
#define MD_PPROT_MIGMD_SHFT 3  
#define MD_PPROT_MIGMD_MASK (3 << 3)
#define MD_PPROT_REFCNT_SHFT 5  
#define MD_PPROT_REFCNT_WIDTH 0x7ffff
#define MD_PPROT_REFCNT_MASK (MD_PPROT_REFCNT_WIDTH << 5)

#define MD_PPROT_IO_SHFT 45  
#define MD_PPROT_IO_MASK (UINT64_CAST 7 << 45)

#define MD_SPROT_SHFT 0  
#define MD_SPROT_MASK 7
#define MD_SPROT_MIGMD_SHFT 3  
#define MD_SPROT_MIGMD_MASK (3 << 3)
#define MD_SPROT_REFCNT_SHFT 5  
#define MD_SPROT_REFCNT_WIDTH 0x7ff
#define MD_SPROT_REFCNT_MASK (MD_SPROT_REFCNT_WIDTH << 5)

#define MD_PROT_MIGMD_IREL (UINT64_CAST 0x3 << 3)
#define MD_PROT_MIGMD_IABS (UINT64_CAST 0x2 << 3)
#define MD_PROT_MIGMD_PREL (UINT64_CAST 0x1 << 3)
#define MD_PROT_MIGMD_OFF (UINT64_CAST 0x0 << 3)

#ifndef __ASSEMBLY__

#define CPU_LED_ADDR(_nasid, _slice)   (private.p_sn00 ?   REMOTE_HUB_ADDR((_nasid), MD_UREG1_0 + ((_slice) << 5)) :   REMOTE_HUB_ADDR((_nasid), MD_LED0 + ((_slice) << 3)))

#define SET_CPU_LEDS(_nasid, _slice, _val)   (HUB_S(CPU_LED_ADDR(_nasid, _slice), (_val)))

#define SET_MY_LEDS(_v)   SET_CPU_LEDS(get_nasid(), get_slice(), (_v))

#define DIRTYPE_PREMIUM 1
#define DIRTYPE_STANDARD 0
#define MD_MEMORY_CONFIG_DIR_TYPE_GET(region) (  (REMOTE_HUB_L(region, MD_MEMORY_CONFIG) & MMC_DIR_PREMIUM_MASK) >>   MMC_DIR_PREMIUM_SHFT)

#define MD_MIG_DIFF_THRESH_GET(region) (   REMOTE_HUB_L((region), MD_MIG_DIFF_THRESH) &   MD_MIG_DIFF_THRES_VALUE_MASK)

#define MD_MIG_DIFF_THRESH_SET(region, value) (   REMOTE_HUB_S((region), MD_MIG_DIFF_THRESH,   MD_MIG_DIFF_THRES_VALID_MASK | (value)))

#define MD_MIG_DIFF_THRESH_DISABLE(region) (   REMOTE_HUB_S((region), MD_MIG_DIFF_THRESH,   REMOTE_HUB_L((region), MD_MIG_DIFF_THRESH)   & ~MD_MIG_DIFF_THRES_VALID_MASK))

#define MD_MIG_DIFF_THRESH_ENABLE(region) (   REMOTE_HUB_S((region), MD_MIG_DIFF_THRESH,   REMOTE_HUB_L((region), MD_MIG_DIFF_THRESH)   | MD_MIG_DIFF_THRES_VALID_MASK))

#define MD_MIG_DIFF_THRESH_IS_ENABLED(region) (   REMOTE_HUB_L((region), MD_MIG_DIFF_THRESH) &   MD_MIG_DIFF_THRES_VALID_MASK)

#define MD_MIG_VALUE_THRESH_GET(region) (   REMOTE_HUB_L((region), MD_MIG_VALUE_THRESH) &   MD_MIG_VALUE_THRES_VALUE_MASK)

#define MD_MIG_VALUE_THRESH_SET(region, value) (   REMOTE_HUB_S((region), MD_MIG_VALUE_THRESH,   MD_MIG_VALUE_THRES_VALID_MASK | (value)))

#define MD_MIG_VALUE_THRESH_DISABLE(region) (   REMOTE_HUB_S((region), MD_MIG_VALUE_THRESH,   REMOTE_HUB_L(region, MD_MIG_VALUE_THRESH)   & ~MD_MIG_VALUE_THRES_VALID_MASK))

#define MD_MIG_VALUE_THRESH_ENABLE(region) (   REMOTE_HUB_S((region), MD_MIG_VALUE_THRESH,   REMOTE_HUB_L((region), MD_MIG_VALUE_THRESH)   | MD_MIG_VALUE_THRES_VALID_MASK))

#define MD_MIG_VALUE_THRESH_IS_ENABLED(region) (   REMOTE_HUB_L((region), MD_MIG_VALUE_THRESH) &   MD_MIG_VALUE_THRES_VALID_MASK)

#define MD_MIG_CANDIDATE_GET(my_region_id) (   REMOTE_HUB_L((my_region_id), MD_MIG_CANDIDATE_CLR))

#define MD_MIG_CANDIDATE_HWPFN(value) ((value) & MD_MIG_CANDIDATE_ADDR_MASK)

#define MD_MIG_CANDIDATE_NODEID(value) (   ((value) & MD_MIG_CANDIDATE_NODEID_MASK) >> MD_MIG_CANDIDATE_NODEID_SHFT)

#define MD_MIG_CANDIDATE_TYPE(value) (   ((value) & MD_MIG_CANDIDATE_TYPE_MASK) >> MD_MIG_CANDIDATE_TYPE_SHFT)

#define MD_MIG_CANDIDATE_VALID(value) (   ((value) & MD_MIG_CANDIDATE_VALID_MASK) >> MD_MIG_CANDIDATE_VALID_SHFT)

#define MD_PPROT_REFCNT_GET(value) (   ((value) & MD_PPROT_REFCNT_MASK) >> MD_PPROT_REFCNT_SHFT)

#define MD_PPROT_MIGMD_GET(value) (   ((value) & MD_PPROT_MIGMD_MASK) >> MD_PPROT_MIGMD_SHFT)

#define MD_SPROT_REFCNT_GET(value) (   ((value) & MD_SPROT_REFCNT_MASK) >> MD_SPROT_REFCNT_SHFT)

#define MD_SPROT_MIGMD_GET(value) (   ((value) & MD_SPROT_MIGMD_MASK) >> MD_SPROT_MIGMD_SHFT)

struct dir_error_reg {
 u64 uce_vld: 1,
 ae_vld: 1,
 ce_vld: 1,
 rsvd1: 19,
 bad_prot: 3,
 bad_syn: 7,
 rsvd2: 2,
 hspec_addr:27,
 uce_ovr: 1,
 ae_ovr: 1,
 ce_ovr: 1;
};

typedef union md_dir_error {
 u64 derr_reg;
 struct dir_error_reg derr_fmt;
} md_dir_error_t;

struct mem_error_reg {
 u64 uce_vld: 1,
 ce_vld: 1,
 rsvd1: 22,
 bad_syn: 8,
 address: 29,
 rsvd2: 1,
 uce_ovr: 1,
 ce_ovr: 1;
};

typedef union md_mem_error {
 u64 merr_reg;
 struct mem_error_reg merr_fmt;
} md_mem_error_t;

struct proto_error_reg {
 u64 valid: 1,
 rsvd1: 2,
 initiator:11,
 backoff: 2,
 msg_type: 8,
 access: 2,
 priority: 1,
 dir_state: 4,
 pointer_me:1,
 address: 29,
 rsvd2: 2,
 overrun: 1;
};

typedef union md_proto_error {
 u64 perr_reg;
 struct proto_error_reg perr_fmt;
} md_proto_error_t;

struct md_sdir_high_fmt {
 unsigned short sd_hi_bvec : 11,
 sd_hi_ecc : 5;
};

typedef union md_sdir_high {

 unsigned short sd_hi_val;
 struct md_sdir_high_fmt sd_hi_fmt;
}md_sdir_high_t;

struct md_sdir_low_shared_fmt {

 unsigned short sds_lo_bvec : 5,
 sds_lo_unused: 1,
 sds_lo_state : 3,
 sds_lo_prio : 1,
 sds_lo_ax : 1,
 sds_lo_ecc : 5;
};

struct md_sdir_low_exclusive_fmt {

 unsigned short sde_lo_ptr : 6,
 sde_lo_state : 3,
 sde_lo_prio : 1,
 sde_lo_ax : 1,
 sde_lo_ecc : 5;
};

typedef union md_sdir_low {

 unsigned short sd_lo_val;
 struct md_sdir_low_exclusive_fmt sde_lo_fmt;
 struct md_sdir_low_shared_fmt sds_lo_fmt;
}md_sdir_low_t;

struct md_pdir_high_fmt {
 u64 pd_hi_unused : 16,
 pd_hi_bvec : 38,
 pd_hi_unused1 : 3,
 pd_hi_ecc : 7;
};

typedef union md_pdir_high {

 u64 pd_hi_val;
 struct md_pdir_high_fmt pd_hi_fmt;
}md_pdir_high_t;

struct md_pdir_low_shared_fmt {

 u64 pds_lo_unused : 16,
 pds_lo_bvec : 26,
 pds_lo_cnt : 6,
 pds_lo_state : 3,
 pds_lo_ste : 1,
 pds_lo_prio : 4,
 pds_lo_ax : 1,
 pds_lo_ecc : 7;
};

struct md_pdir_low_exclusive_fmt {

 u64 pde_lo_unused : 31,
 pde_lo_ptr : 11,
 pde_lo_unused1 : 6,
 pde_lo_state : 3,
 pde_lo_ste : 1,
 pde_lo_prio : 4,
 pde_lo_ax : 1,
 pde_lo_ecc : 7;
};

typedef union md_pdir_loent {

 u64 pd_lo_val;
 struct md_pdir_low_exclusive_fmt pde_lo_fmt;
 struct md_pdir_low_shared_fmt pds_lo_fmt;
}md_pdir_low_t;

typedef union md_dir_high {
 md_sdir_high_t md_sdir_high;
 md_pdir_high_t md_pdir_high;
} md_dir_high_t;

typedef union md_dir_low {
 md_sdir_low_t md_sdir_low;
 md_pdir_low_t md_pdir_low;
} md_dir_low_t;

typedef struct bddir_entry {
 md_dir_low_t md_dir_low;
 md_dir_high_t md_dir_high;
} bddir_entry_t;

typedef struct dir_mem_entry {
 u64 prcpf[MAX_REGIONS];
 bddir_entry_t directory_words[MD_PAGE_SIZE/CACHE_SLINE_SIZE];
} dir_mem_entry_t;

typedef union md_perf_sel {
 u64 perf_sel_reg;
 struct {
 u64 perf_rsvd : 60,
 perf_en : 1,
 perf_sel : 3;
 } perf_sel_bits;
} md_perf_sel_t;

typedef union md_perf_cnt {
 u64 perf_cnt;
 struct {
 u64 perf_rsvd : 44,
 perf_cnt : 20;
 } perf_cnt_bits;
} md_perf_cnt_t;

#endif

#define DIR_ERROR_VALID_MASK 0xe000000000000000
#define DIR_ERROR_VALID_SHFT 61
#define DIR_ERROR_VALID_UCE 0x8000000000000000
#define DIR_ERROR_VALID_AE 0x4000000000000000
#define DIR_ERROR_VALID_CE 0x2000000000000000

#define MEM_ERROR_VALID_MASK 0xc000000000000000
#define MEM_ERROR_VALID_SHFT 62
#define MEM_ERROR_VALID_UCE 0x8000000000000000
#define MEM_ERROR_VALID_CE 0x4000000000000000

#define PROTO_ERROR_VALID_MASK 0x8000000000000000

#define MISC_ERROR_VALID_MASK 0x3ff

#define DIR_ERR_HSPEC_MASK 0x3ffffff8
#define ERROR_HSPEC_MASK 0x3ffffff8
#define ERROR_HSPEC_SHFT 3
#define ERROR_ADDR_MASK 0xfffffff8
#define ERROR_ADDR_SHFT 3

#define MMCE_VALID_MASK 0x3ff
#define MMCE_ILL_MSG_SHFT 8
#define MMCE_ILL_MSG_MASK (UINT64_CAST 0x03 << MMCE_ILL_MSG_SHFT)
#define MMCE_ILL_REV_SHFT 6
#define MMCE_ILL_REV_MASK (UINT64_CAST 0x03 << MMCE_ILL_REV_SHFT)
#define MMCE_LONG_PACK_SHFT 4
#define MMCE_LONG_PACK_MASK (UINT64_CAST 0x03 << MMCE_lONG_PACK_SHFT)
#define MMCE_SHORT_PACK_SHFT 2
#define MMCE_SHORT_PACK_MASK (UINT64_CAST 0x03 << MMCE_SHORT_PACK_SHFT)
#define MMCE_BAD_DATA_SHFT 0
#define MMCE_BAD_DATA_MASK (UINT64_CAST 0x03 << MMCE_BAD_DATA_SHFT)

#define MD_PERF_COUNTERS 6
#define MD_PERF_SETS 6

#define MEM_DIMM_MASK 0xe0000000
#define MEM_DIMM_SHFT 29

#endif
