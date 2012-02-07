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
#ifndef _ASM_SN_SN0_HUBPI_H
#define _ASM_SN_SN0_HUBPI_H

#include <linux/types.h>

#define PI_BASE 0x000000

#define PI_CPU_PROTECT 0x000000  
#define PI_PROT_OVERRD 0x000008  
#define PI_IO_PROTECT 0x000010  
#define PI_REGION_PRESENT 0x000018  
#define PI_CPU_NUM 0x000020  
#define PI_CALIAS_SIZE 0x000028  
#define PI_MAX_CRB_TIMEOUT 0x000030  
#define PI_CRB_SFACTOR 0x000038  

#define PI_CALIAS_SIZE_0 0
#define PI_CALIAS_SIZE_4K 1
#define PI_CALIAS_SIZE_8K 2
#define PI_CALIAS_SIZE_16K 3
#define PI_CALIAS_SIZE_32K 4
#define PI_CALIAS_SIZE_64K 5
#define PI_CALIAS_SIZE_128K 6
#define PI_CALIAS_SIZE_256K 7
#define PI_CALIAS_SIZE_512K 8
#define PI_CALIAS_SIZE_1M 9
#define PI_CALIAS_SIZE_2M 10
#define PI_CALIAS_SIZE_4M 11
#define PI_CALIAS_SIZE_8M 12
#define PI_CALIAS_SIZE_16M 13
#define PI_CALIAS_SIZE_32M 14
#define PI_CALIAS_SIZE_64M 15

#define PI_CPU_PRESENT_A 0x000040  
#define PI_CPU_PRESENT_B 0x000048  
#define PI_CPU_ENABLE_A 0x000050  
#define PI_CPU_ENABLE_B 0x000058  
#define PI_REPLY_LEVEL 0x000060  
#define PI_HARDRESET_BIT 0x020068  
#define PI_NMI_A 0x000070  
#define PI_NMI_B 0x000078  
#define PI_NMI_OFFSET (PI_NMI_B - PI_NMI_A)
#define PI_SOFTRESET 0x000080  

#define PI_INT_PEND_MOD 0x000090  
#define PI_INT_PEND0 0x000098  
#define PI_INT_PEND1 0x0000a0  
#define PI_INT_MASK0_A 0x0000a8  
#define PI_INT_MASK1_A 0x0000b0  
#define PI_INT_MASK0_B 0x0000b8  
#define PI_INT_MASK1_B 0x0000c0  

#define PI_INT_MASK_OFFSET 0x10  

#define PI_CC_PEND_SET_A 0x0000c8  
#define PI_CC_PEND_SET_B 0x0000d0  
#define PI_CC_PEND_CLR_A 0x0000d8  
#define PI_CC_PEND_CLR_B 0x0000e0  
#define PI_CC_MASK 0x0000e8  

#define PI_INT_SET_OFFSET 0x08  

#define PI_RT_COUNT 0x030100  
#define PI_RT_COMPARE_A 0x000108  
#define PI_RT_COMPARE_B 0x000110  
#define PI_PROFILE_COMPARE 0x000118  
#define PI_RT_PEND_A 0x000120  
#define PI_RT_PEND_B 0x000128  
#define PI_PROF_PEND_A 0x000130  
#define PI_PROF_PEND_B 0x000138  
#define PI_RT_EN_A 0x000140  
#define PI_RT_EN_B 0x000148  
#define PI_PROF_EN_A 0x000150  
#define PI_PROF_EN_B 0x000158  
#define PI_RT_LOCAL_CTRL 0x000160  
#define PI_RT_FILTER_CTRL 0x000168  

#define PI_COUNT_OFFSET 0x08  

#define PI_BIST_WRITE_DATA 0x000200  
#define PI_BIST_READ_DATA 0x000208  
#define PI_BIST_COUNT_TARG 0x000210  
#define PI_BIST_READY 0x000218  
#define PI_BIST_SHIFT_LOAD 0x000220  
#define PI_BIST_SHIFT_UNLOAD 0x000228  
#define PI_BIST_ENTER_RUN 0x000230  

#define PI_GFX_PAGE_A 0x000300  
#define PI_GFX_CREDIT_CNTR_A 0x000308  
#define PI_GFX_BIAS_A 0x000310  
#define PI_GFX_INT_CNTR_A 0x000318  
#define PI_GFX_INT_CMP_A 0x000320  
#define PI_GFX_PAGE_B 0x000328  
#define PI_GFX_CREDIT_CNTR_B 0x000330  
#define PI_GFX_BIAS_B 0x000338  
#define PI_GFX_INT_CNTR_B 0x000340  
#define PI_GFX_INT_CMP_B 0x000348  

#define PI_GFX_OFFSET (PI_GFX_PAGE_B - PI_GFX_PAGE_A)
#define PI_GFX_PAGE_ENABLE 0x0000010000000000LL

#define PI_ERR_INT_PEND 0x000400  
#define PI_ERR_INT_MASK_A 0x000408  
#define PI_ERR_INT_MASK_B 0x000410  
#define PI_ERR_STACK_ADDR_A 0x000418  
#define PI_ERR_STACK_ADDR_B 0x000420  
#define PI_ERR_STACK_SIZE 0x000428  
#define PI_ERR_STATUS0_A 0x000430  
#define PI_ERR_STATUS0_A_RCLR 0x000438  
#define PI_ERR_STATUS1_A 0x000440  
#define PI_ERR_STATUS1_A_RCLR 0x000448  
#define PI_ERR_STATUS0_B 0x000450  
#define PI_ERR_STATUS0_B_RCLR 0x000458  
#define PI_ERR_STATUS1_B 0x000460  
#define PI_ERR_STATUS1_B_RCLR 0x000468  
#define PI_SPOOL_CMP_A 0x000470  
#define PI_SPOOL_CMP_B 0x000478  
#define PI_CRB_TIMEOUT_A 0x000480  
#define PI_CRB_TIMEOUT_B 0x000488  
#define PI_SYSAD_ERRCHK_EN 0x000490  
#define PI_BAD_CHECK_BIT_A 0x000498  
#define PI_BAD_CHECK_BIT_B 0x0004a0  
#define PI_NACK_CNT_A 0x0004a8  
#define PI_NACK_CNT_B 0x0004b0  
#define PI_NACK_CMP 0x0004b8  
#define PI_STACKADDR_OFFSET (PI_ERR_STACK_ADDR_B - PI_ERR_STACK_ADDR_A)
#define PI_ERRSTAT_OFFSET (PI_ERR_STATUS0_B - PI_ERR_STATUS0_A)
#define PI_RDCLR_OFFSET (PI_ERR_STATUS0_A_RCLR - PI_ERR_STATUS0_A)

#define PI_ERR_SPOOL_CMP_B 0x00000001  
#define PI_ERR_SPOOL_CMP_A 0x00000002
#define PI_ERR_SPUR_MSG_B 0x00000004  
#define PI_ERR_SPUR_MSG_A 0x00000008
#define PI_ERR_WRB_TERR_B 0x00000010  
#define PI_ERR_WRB_TERR_A 0x00000020
#define PI_ERR_WRB_WERR_B 0x00000040  
#define PI_ERR_WRB_WERR_A 0x00000080
#define PI_ERR_SYSSTATE_B 0x00000100  
#define PI_ERR_SYSSTATE_A 0x00000200
#define PI_ERR_SYSAD_DATA_B 0x00000400  
#define PI_ERR_SYSAD_DATA_A 0x00000800
#define PI_ERR_SYSAD_ADDR_B 0x00001000  
#define PI_ERR_SYSAD_ADDR_A 0x00002000
#define PI_ERR_SYSCMD_DATA_B 0x00004000  
#define PI_ERR_SYSCMD_DATA_A 0x00008000
#define PI_ERR_SYSCMD_ADDR_B 0x00010000  
#define PI_ERR_SYSCMD_ADDR_A 0x00020000
#define PI_ERR_BAD_SPOOL_B 0x00040000  
#define PI_ERR_BAD_SPOOL_A 0x00080000
#define PI_ERR_UNCAC_UNCORR_B 0x00100000  
#define PI_ERR_UNCAC_UNCORR_A 0x00200000
#define PI_ERR_SYSSTATE_TAG_B 0x00400000  
#define PI_ERR_SYSSTATE_TAG_A 0x00800000
#define PI_ERR_MD_UNCORR 0x01000000  

#define PI_ERR_CLEAR_ALL_A 0x00aaaaaa
#define PI_ERR_CLEAR_ALL_B 0x00555555

#define PI_FATAL_ERR_CPU_A (PI_ERR_SYSSTATE_TAG_A |   PI_ERR_BAD_SPOOL_A |   PI_ERR_SYSCMD_ADDR_A |   PI_ERR_SYSCMD_DATA_A |   PI_ERR_SYSAD_ADDR_A |   PI_ERR_SYSAD_DATA_A |   PI_ERR_SYSSTATE_A)

#define PI_MISC_ERR_CPU_A (PI_ERR_UNCAC_UNCORR_A |   PI_ERR_WRB_WERR_A |   PI_ERR_WRB_TERR_A |   PI_ERR_SPUR_MSG_A |   PI_ERR_SPOOL_CMP_A)

#define PI_FATAL_ERR_CPU_B (PI_ERR_SYSSTATE_TAG_B |   PI_ERR_BAD_SPOOL_B |   PI_ERR_SYSCMD_ADDR_B |   PI_ERR_SYSCMD_DATA_B |   PI_ERR_SYSAD_ADDR_B |   PI_ERR_SYSAD_DATA_B |   PI_ERR_SYSSTATE_B)

#define PI_MISC_ERR_CPU_B (PI_ERR_UNCAC_UNCORR_B |   PI_ERR_WRB_WERR_B |   PI_ERR_WRB_TERR_B |   PI_ERR_SPUR_MSG_B |   PI_ERR_SPOOL_CMP_B)

#define PI_ERR_GENERIC (PI_ERR_MD_UNCORR)

#define PI_ERR_ST0_TYPE_MASK 0x0000000000000007
#define PI_ERR_ST0_TYPE_SHFT 0
#define PI_ERR_ST0_REQNUM_MASK 0x0000000000000038
#define PI_ERR_ST0_REQNUM_SHFT 3
#define PI_ERR_ST0_SUPPL_MASK 0x000000000001ffc0
#define PI_ERR_ST0_SUPPL_SHFT 6
#define PI_ERR_ST0_CMD_MASK 0x0000000001fe0000
#define PI_ERR_ST0_CMD_SHFT 17
#define PI_ERR_ST0_ADDR_MASK 0x3ffffffffe000000
#define PI_ERR_ST0_ADDR_SHFT 25
#define PI_ERR_ST0_OVERRUN_MASK 0x4000000000000000
#define PI_ERR_ST0_OVERRUN_SHFT 62
#define PI_ERR_ST0_VALID_MASK 0x8000000000000000
#define PI_ERR_ST0_VALID_SHFT 63

#define PI_ERR_ST1_SPOOL_MASK 0x00000000001fffff
#define PI_ERR_ST1_SPOOL_SHFT 0
#define PI_ERR_ST1_TOUTCNT_MASK 0x000000001fe00000
#define PI_ERR_ST1_TOUTCNT_SHFT 21
#define PI_ERR_ST1_INVCNT_MASK 0x0000007fe0000000
#define PI_ERR_ST1_INVCNT_SHFT 29
#define PI_ERR_ST1_CRBNUM_MASK 0x0000038000000000
#define PI_ERR_ST1_CRBNUM_SHFT 39
#define PI_ERR_ST1_WRBRRB_MASK 0x0000040000000000
#define PI_ERR_ST1_WRBRRB_SHFT 42
#define PI_ERR_ST1_CRBSTAT_MASK 0x001ff80000000000
#define PI_ERR_ST1_CRBSTAT_SHFT 43
#define PI_ERR_ST1_MSGSRC_MASK 0xffe0000000000000
#define PI_ERR_ST1_MSGSRC_SHFT 53

#define PI_ERR_STK_TYPE_MASK 0x0000000000000003
#define PI_ERR_STK_TYPE_SHFT 0
#define PI_ERR_STK_SUPPL_MASK 0x0000000000000038
#define PI_ERR_STK_SUPPL_SHFT 3
#define PI_ERR_STK_REQNUM_MASK 0x00000000000001c0
#define PI_ERR_STK_REQNUM_SHFT 6
#define PI_ERR_STK_CRBNUM_MASK 0x0000000000000e00
#define PI_ERR_STK_CRBNUM_SHFT 9
#define PI_ERR_STK_WRBRRB_MASK 0x0000000000001000
#define PI_ERR_STK_WRBRRB_SHFT 12
#define PI_ERR_STK_CRBSTAT_MASK 0x00000000007fe000
#define PI_ERR_STK_CRBSTAT_SHFT 13
#define PI_ERR_STK_CMD_MASK 0x000000007f800000
#define PI_ERR_STK_CMD_SHFT 23
#define PI_ERR_STK_ADDR_MASK 0xffffffff80000000
#define PI_ERR_STK_ADDR_SHFT 31

#define PI_ERR_RD_PRERR 1
#define PI_ERR_RD_DERR 2
#define PI_ERR_RD_TERR 3

#define PI_ERR_WR_WERR 0
#define PI_ERR_WR_PWERR 1
#define PI_ERR_WR_TERR 3

#define PI_ERR_RRB 0
#define PI_ERR_WRB 1
#define PI_ERR_ANY_CRB 2

#define ERR_STK_ADDR_SHFT 7
#define ERR_STAT0_ADDR_SHFT 3

#define PI_MIN_STACK_SIZE 4096  
#define PI_STACK_SIZE_SHFT 12  

#define ERR_STACK_SIZE_BYTES(_sz)   ((_sz) ? (PI_MIN_STACK_SIZE << ((_sz) - 1)) : 0)

#ifndef __ASSEMBLY__

struct err_stack_format {
 u64 sk_addr : 33,
 sk_cmd : 8,
 sk_crb_sts : 10,
 sk_rw_rb : 1,
 sk_crb_num : 3,
 sk_t5_req : 3,
 sk_suppl : 3,
 sk_err_type: 3;
};

typedef union pi_err_stack {
 u64 pi_stk_word;
 struct err_stack_format pi_stk_fmt;
} pi_err_stack_t;

struct err_status0_format {
 u64 s0_valid : 1,
 s0_ovr_run : 1,
 s0_addr : 37,
 s0_cmd : 8,
 s0_supl : 11,
 s0_t5_req : 3,
 s0_err_type: 3;
};

typedef union pi_err_stat0 {
 u64 pi_stat0_word;
 struct err_status0_format pi_stat0_fmt;
} pi_err_stat0_t;

struct err_status1_format {
 u64 s1_src : 11,
 s1_crb_sts : 10,
 s1_rw_rb : 1,
 s1_crb_num : 3,
 s1_inval_cnt:10,
 s1_to_cnt : 8,
 s1_spl_cnt : 21;
};

typedef union pi_err_stat1 {
 u64 pi_stat1_word;
 struct err_status1_format pi_stat1_fmt;
} pi_err_stat1_t;

typedef u64 rtc_time_t;

#endif

#define PI_SYSAD_ERRCHK_ECCGEN 0x01  
#define PI_SYSAD_ERRCHK_QUALGEN 0x02  
#define PI_SYSAD_ERRCHK_SADP 0x04  
#define PI_SYSAD_ERRCHK_CMDP 0x08  
#define PI_SYSAD_ERRCHK_STATE 0x10  
#define PI_SYSAD_ERRCHK_QUAL 0x20  
#define PI_SYSAD_CHECK_ALL 0x3f  

#define HUB_IP_PEND0 0x0400
#define HUB_IP_PEND1_CC 0x0800
#define HUB_IP_RT 0x1000
#define HUB_IP_PROF 0x2000
#define HUB_IP_ERROR 0x4000
#define HUB_IP_MASK 0x7c00

#define PRLC_USE_INT_SHFT 16
#define PRLC_USE_INT_MASK (UINT64_CAST 1 << 16)
#define PRLC_USE_INT (UINT64_CAST 1 << 16)
#define PRLC_GCLK_SHFT 15
#define PRLC_GCLK_MASK (UINT64_CAST 1 << 15)
#define PRLC_GCLK (UINT64_CAST 1 << 15)
#define PRLC_GCLK_COUNT_SHFT 8
#define PRLC_GCLK_COUNT_MASK (UINT64_CAST 0x7f << 8)
#define PRLC_MAX_COUNT_SHFT 1
#define PRLC_MAX_COUNT_MASK (UINT64_CAST 0x7f << 1)
#define PRLC_GCLK_EN_SHFT 0
#define PRLC_GCLK_EN_MASK (UINT64_CAST 1)
#define PRLC_GCLK_EN (UINT64_CAST 1)

#define PI_NACK_CNT_EN_SHFT 20
#define PI_NACK_CNT_EN_MASK 0x100000
#define PI_NACK_CNT_MASK 0x0fffff
#define PI_NACK_CNT_MAX 0x0fffff

#endif
