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
#ifndef _ASM_PCI_BRIDGE_H
#define _ASM_PCI_BRIDGE_H

#include <linux/types.h>
#include <linux/pci.h>
#include <asm/xtalk/xwidget.h>  
#include <asm/sn/types.h>

#define IOPFNSHIFT 12  

#define IOPGSIZE (1 << IOPFNSHIFT)
#define IOPG(x) ((x) >> IOPFNSHIFT)
#define IOPGOFF(x) ((x) & (IOPGSIZE-1))

#define BRIDGE_ATE_RAM_SIZE 0x00000400  

#define BRIDGE_CONFIG_BASE 0x20000
#define BRIDGE_CONFIG1_BASE 0x28000
#define BRIDGE_CONFIG_END 0x30000
#define BRIDGE_CONFIG_SLOT_SIZE 0x1000

#define BRIDGE_SSRAM_512K 0x00080000  
#define BRIDGE_SSRAM_128K 0x00020000  
#define BRIDGE_SSRAM_64K 0x00010000  
#define BRIDGE_SSRAM_0K 0x00000000  

#ifndef __ASSEMBLY__

typedef u32 bridgereg_t;

typedef u64 bridge_ate_t;

typedef volatile bridge_ate_t *bridge_ate_p;

typedef volatile struct bridge_s {

 widget_cfg_t b_widget;

#define b_wid_id b_widget.w_id
#define b_wid_stat b_widget.w_status
#define b_wid_err_upper b_widget.w_err_upper_addr
#define b_wid_err_lower b_widget.w_err_lower_addr
#define b_wid_control b_widget.w_control
#define b_wid_req_timeout b_widget.w_req_timeout
#define b_wid_int_upper b_widget.w_intdest_upper_addr
#define b_wid_int_lower b_widget.w_intdest_lower_addr
#define b_wid_err_cmdword b_widget.w_err_cmd_word
#define b_wid_llp b_widget.w_llp_cfg
#define b_wid_tflush b_widget.w_tflush

 bridgereg_t _pad_000058;
 bridgereg_t b_wid_aux_err;
 bridgereg_t _pad_000060;
 bridgereg_t b_wid_resp_upper;
 bridgereg_t _pad_000068;
 bridgereg_t b_wid_resp_lower;
 bridgereg_t _pad_000070;
 bridgereg_t b_wid_tst_pin_ctrl;
 bridgereg_t _pad_000078[2];

 bridgereg_t _pad_000080;
 bridgereg_t b_dir_map;
 bridgereg_t _pad_000088[2];

 bridgereg_t _pad_000090;
 bridgereg_t b_ram_perr;
 bridgereg_t _pad_000098[2];

 bridgereg_t _pad_0000A0;
 bridgereg_t b_arb;
 bridgereg_t _pad_0000A8[2];

 bridgereg_t _pad_0000B0;
 bridgereg_t b_nic;
 bridgereg_t _pad_0000B8[2];

 bridgereg_t _pad_0000C0;
 bridgereg_t b_bus_timeout;
#define b_pci_bus_timeout b_bus_timeout

 bridgereg_t _pad_0000C8;
 bridgereg_t b_pci_cfg;
 bridgereg_t _pad_0000D0;
 bridgereg_t b_pci_err_upper;
 bridgereg_t _pad_0000D8;
 bridgereg_t b_pci_err_lower;
 bridgereg_t _pad_0000E0[8];
#define b_gio_err_lower b_pci_err_lower
#define b_gio_err_upper b_pci_err_upper

 bridgereg_t _pad_000100;
 bridgereg_t b_int_status;
 bridgereg_t _pad_000108;
 bridgereg_t b_int_enable;
 bridgereg_t _pad_000110;
 bridgereg_t b_int_rst_stat;
 bridgereg_t _pad_000118;
 bridgereg_t b_int_mode;
 bridgereg_t _pad_000120;
 bridgereg_t b_int_device;
 bridgereg_t _pad_000128;
 bridgereg_t b_int_host_err;

 struct {
 bridgereg_t __pad;
 bridgereg_t addr;
 } b_int_addr[8];

 bridgereg_t _pad_000170[36];

 struct {
 bridgereg_t __pad;
 bridgereg_t reg;
 } b_device[8];

 struct {
 bridgereg_t __pad;
 bridgereg_t reg;
 } b_wr_req_buf[8];

 struct {
 bridgereg_t __pad;
 bridgereg_t reg;
 } b_rrb_map[2];
#define b_even_resp b_rrb_map[0].reg  
#define b_odd_resp b_rrb_map[1].reg  

 bridgereg_t _pad_000290;
 bridgereg_t b_resp_status;
 bridgereg_t _pad_000298;
 bridgereg_t b_resp_clear;

 bridgereg_t _pad_0002A0[24];

 char _pad_000300[0x10000 - 0x000300];

 union {
 bridge_ate_t wr;
 struct {
 bridgereg_t _p_pad;
 bridgereg_t rd;
 } hi;
 } b_int_ate_ram[128];

 char _pad_010400[0x11000 - 0x010400];

 struct {
 bridgereg_t _p_pad;
 bridgereg_t rd;
 } b_int_ate_ram_lo[128];

 char _pad_011400[0x20000 - 0x011400];

 union {
 u8 c[0x1000 / 1];
 u16 s[0x1000 / 2];
 u32 l[0x1000 / 4];
 u64 d[0x1000 / 8];
 union {
 u8 c[0x100 / 1];
 u16 s[0x100 / 2];
 u32 l[0x100 / 4];
 u64 d[0x100 / 8];
 } f[8];
 } b_type0_cfg_dev[8];

 union {
 u8 c[0x1000 / 1];
 u16 s[0x1000 / 2];
 u32 l[0x1000 / 4];
 u64 d[0x1000 / 8];
 } b_type1_cfg;

 char _pad_029000[0x007000];

 union {
 u8 c[8 / 1];
 u16 s[8 / 2];
 u32 l[8 / 4];
 u64 d[8 / 8];
 } b_pci_iack;

 u8 _pad_030007[0x04fff8];

 bridge_ate_t b_ext_ate_ram[0x10000];

 char _pad_100000[0x200000-0x100000];

 union {
 u8 c[0x100000 / 1];
 u16 s[0x100000 / 2];
 u32 l[0x100000 / 4];
 u64 d[0x100000 / 8];
 } b_devio_raw[10];

#define b_devio(n) b_devio_raw[((n)<2)?(n*2):(n+2)]

 union {
 u8 c[0x400000 / 1];
 u16 s[0x400000 / 2];
 u32 l[0x400000 / 4];
 u64 d[0x400000 / 8];
 } b_external_flash;
} bridge_t;

typedef struct bridge_err_cmdword_s {
 union {
 u32 cmd_word;
 struct {
 u32 didn:4,
 sidn:4,
 pactyp:4,
 tnum:5,
 coh:1,
 ds:2,
 gbr:1,
 vbpm:1,
 error:1,
 barr:1,
 rsvd:8;
 } berr_st;
 } berr_un;
} bridge_err_cmdword_t;

#define berr_field berr_un.berr_st
#endif

#define BRIDGE_WID_ID WIDGET_ID
#define BRIDGE_WID_STAT WIDGET_STATUS
#define BRIDGE_WID_ERR_UPPER WIDGET_ERR_UPPER_ADDR
#define BRIDGE_WID_ERR_LOWER WIDGET_ERR_LOWER_ADDR
#define BRIDGE_WID_CONTROL WIDGET_CONTROL
#define BRIDGE_WID_REQ_TIMEOUT WIDGET_REQ_TIMEOUT
#define BRIDGE_WID_INT_UPPER WIDGET_INTDEST_UPPER_ADDR
#define BRIDGE_WID_INT_LOWER WIDGET_INTDEST_LOWER_ADDR
#define BRIDGE_WID_ERR_CMDWORD WIDGET_ERR_CMD_WORD
#define BRIDGE_WID_LLP WIDGET_LLP_CFG
#define BRIDGE_WID_TFLUSH WIDGET_TFLUSH

#define BRIDGE_WID_AUX_ERR 0x00005C  
#define BRIDGE_WID_RESP_UPPER 0x000064  
#define BRIDGE_WID_RESP_LOWER 0x00006C  
#define BRIDGE_WID_TST_PIN_CTRL 0x000074  

#define BRIDGE_DIR_MAP 0x000084  

#define BRIDGE_RAM_PERR 0x000094  

#define BRIDGE_ARB 0x0000A4  

#define BRIDGE_NIC 0x0000B4  

#define BRIDGE_BUS_TIMEOUT 0x0000C4  
#define BRIDGE_PCI_BUS_TIMEOUT BRIDGE_BUS_TIMEOUT
#define BRIDGE_PCI_CFG 0x0000CC  
#define BRIDGE_PCI_ERR_UPPER 0x0000D4  
#define BRIDGE_PCI_ERR_LOWER 0x0000DC  

#define BRIDGE_INT_STATUS 0x000104  
#define BRIDGE_INT_ENABLE 0x00010C  
#define BRIDGE_INT_RST_STAT 0x000114  
#define BRIDGE_INT_MODE 0x00011C  
#define BRIDGE_INT_DEVICE 0x000124  
#define BRIDGE_INT_HOST_ERR 0x00012C  

#define BRIDGE_INT_ADDR0 0x000134  
#define BRIDGE_INT_ADDR_OFF 0x000008  
#define BRIDGE_INT_ADDR(x) (BRIDGE_INT_ADDR0+(x)*BRIDGE_INT_ADDR_OFF)

#define BRIDGE_DEVICE0 0x000204  
#define BRIDGE_DEVICE_OFF 0x000008  
#define BRIDGE_DEVICE(x) (BRIDGE_DEVICE0+(x)*BRIDGE_DEVICE_OFF)

#define BRIDGE_WR_REQ_BUF0 0x000244  
#define BRIDGE_WR_REQ_BUF_OFF 0x000008  
#define BRIDGE_WR_REQ_BUF(x) (BRIDGE_WR_REQ_BUF0+(x)*BRIDGE_WR_REQ_BUF_OFF)

#define BRIDGE_EVEN_RESP 0x000284  
#define BRIDGE_ODD_RESP 0x00028C  

#define BRIDGE_RESP_STATUS 0x000294  
#define BRIDGE_RESP_CLEAR 0x00029C  

#define BRIDGE_ATE_RAM 0x00010000  

#define BRIDGE_TYPE0_CFG_DEV0 0x00020000  
#define BRIDGE_TYPE0_CFG_SLOT_OFF 0x00001000  
#define BRIDGE_TYPE0_CFG_FUNC_OFF 0x00000100  
#define BRIDGE_TYPE0_CFG_DEV(s) (BRIDGE_TYPE0_CFG_DEV0+  (s)*BRIDGE_TYPE0_CFG_SLOT_OFF)
#define BRIDGE_TYPE0_CFG_DEVF(s, f) (BRIDGE_TYPE0_CFG_DEV0+  (s)*BRIDGE_TYPE0_CFG_SLOT_OFF+  (f)*BRIDGE_TYPE0_CFG_FUNC_OFF)

#define BRIDGE_TYPE1_CFG 0x00028000  

#define BRIDGE_PCI_IACK 0x00030000  
#define BRIDGE_EXT_SSRAM 0x00080000  

#define BRIDGE_DEV_CNT 8  
#define BRIDGE_DEVIO0 0x00200000  
#define BRIDGE_DEVIO1 0x00400000  
#define BRIDGE_DEVIO2 0x00600000  
#define BRIDGE_DEVIO_OFF 0x00100000  

#define BRIDGE_DEVIO_2MB 0x00200000  
#define BRIDGE_DEVIO_1MB 0x00100000  

#define BRIDGE_DEVIO(x) ((x)<=1 ? BRIDGE_DEVIO0+(x)*BRIDGE_DEVIO_2MB : BRIDGE_DEVIO2+((x)-2)*BRIDGE_DEVIO_1MB)

#define BRIDGE_EXTERNAL_FLASH 0x00C00000  

#define BRIDGE_WIDGET_PART_NUM 0xc002
#define XBRIDGE_WIDGET_PART_NUM 0xd002

#define BRIDGE_WIDGET_MFGR_NUM 0x036
#define XBRIDGE_WIDGET_MFGR_NUM 0x024

#define BRIDGE_REV_A 0x1
#define BRIDGE_REV_B 0x2
#define BRIDGE_REV_C 0x3
#define BRIDGE_REV_D 0x4

#define BRIDGE_STAT_LLP_REC_CNT (0xFFu << 24)
#define BRIDGE_STAT_LLP_TX_CNT (0xFF << 16)
#define BRIDGE_STAT_FLASH_SELECT (0x1 << 6)
#define BRIDGE_STAT_PCI_GIO_N (0x1 << 5)
#define BRIDGE_STAT_PENDING (0x1F << 0)

#define BRIDGE_CTRL_FLASH_WR_EN (0x1ul << 31)
#define BRIDGE_CTRL_EN_CLK50 (0x1 << 30)
#define BRIDGE_CTRL_EN_CLK40 (0x1 << 29)
#define BRIDGE_CTRL_EN_CLK33 (0x1 << 28)
#define BRIDGE_CTRL_RST(n) ((n) << 24)
#define BRIDGE_CTRL_RST_MASK (BRIDGE_CTRL_RST(0xF))
#define BRIDGE_CTRL_RST_PIN(x) (BRIDGE_CTRL_RST(0x1 << (x)))
#define BRIDGE_CTRL_IO_SWAP (0x1 << 23)
#define BRIDGE_CTRL_MEM_SWAP (0x1 << 22)
#define BRIDGE_CTRL_PAGE_SIZE (0x1 << 21)
#define BRIDGE_CTRL_SS_PAR_BAD (0x1 << 20)
#define BRIDGE_CTRL_SS_PAR_EN (0x1 << 19)
#define BRIDGE_CTRL_SSRAM_SIZE(n) ((n) << 17)
#define BRIDGE_CTRL_SSRAM_SIZE_MASK (BRIDGE_CTRL_SSRAM_SIZE(0x3))
#define BRIDGE_CTRL_SSRAM_512K (BRIDGE_CTRL_SSRAM_SIZE(0x3))
#define BRIDGE_CTRL_SSRAM_128K (BRIDGE_CTRL_SSRAM_SIZE(0x2))
#define BRIDGE_CTRL_SSRAM_64K (BRIDGE_CTRL_SSRAM_SIZE(0x1))
#define BRIDGE_CTRL_SSRAM_1K (BRIDGE_CTRL_SSRAM_SIZE(0x0))
#define BRIDGE_CTRL_F_BAD_PKT (0x1 << 16)
#define BRIDGE_CTRL_LLP_XBAR_CRD(n) ((n) << 12)
#define BRIDGE_CTRL_LLP_XBAR_CRD_MASK (BRIDGE_CTRL_LLP_XBAR_CRD(0xf))
#define BRIDGE_CTRL_CLR_RLLP_CNT (0x1 << 11)
#define BRIDGE_CTRL_CLR_TLLP_CNT (0x1 << 10)
#define BRIDGE_CTRL_SYS_END (0x1 << 9)
#define BRIDGE_CTRL_MAX_TRANS(n) ((n) << 4)
#define BRIDGE_CTRL_MAX_TRANS_MASK (BRIDGE_CTRL_MAX_TRANS(0x1f))
#define BRIDGE_CTRL_WIDGET_ID(n) ((n) << 0)
#define BRIDGE_CTRL_WIDGET_ID_MASK (BRIDGE_CTRL_WIDGET_ID(0xf))

#define BRIDGE_RESP_ERRUPPR_DEVNUM_SHFT (20)
#define BRIDGE_RESP_ERRUPPR_DEVNUM_MASK (0x7 << BRIDGE_RESP_ERRUPPR_DEVNUM_SHFT)
#define BRIDGE_RESP_ERRUPPR_BUFNUM_SHFT (16)
#define BRIDGE_RESP_ERRUPPR_BUFNUM_MASK (0xF << BRIDGE_RESP_ERRUPPR_BUFNUM_SHFT)
#define BRIDGE_RESP_ERRRUPPR_BUFMASK (0xFFFF)

#define BRIDGE_RESP_ERRUPPR_BUFNUM(x)   (((x) & BRIDGE_RESP_ERRUPPR_BUFNUM_MASK) >>   BRIDGE_RESP_ERRUPPR_BUFNUM_SHFT)

#define BRIDGE_RESP_ERRUPPR_DEVICE(x)   (((x) & BRIDGE_RESP_ERRUPPR_DEVNUM_MASK) >>   BRIDGE_RESP_ERRUPPR_DEVNUM_SHFT)

#define BRIDGE_DIRMAP_W_ID_SHFT 20
#define BRIDGE_DIRMAP_W_ID (0xf << BRIDGE_DIRMAP_W_ID_SHFT)
#define BRIDGE_DIRMAP_RMF_64 (0x1 << 18)
#define BRIDGE_DIRMAP_ADD512 (0x1 << 17)
#define BRIDGE_DIRMAP_OFF (0x1ffff << 0)
#define BRIDGE_DIRMAP_OFF_ADDRSHFT (31)  

#define BRIDGE_ARB_REQ_WAIT_TICK(x) ((x) << 16)
#define BRIDGE_ARB_REQ_WAIT_TICK_MASK BRIDGE_ARB_REQ_WAIT_TICK(0x3)
#define BRIDGE_ARB_REQ_WAIT_EN(x) ((x) << 8)
#define BRIDGE_ARB_REQ_WAIT_EN_MASK BRIDGE_ARB_REQ_WAIT_EN(0xff)
#define BRIDGE_ARB_FREEZE_GNT (1 << 6)
#define BRIDGE_ARB_HPRI_RING_B2 (1 << 5)
#define BRIDGE_ARB_HPRI_RING_B1 (1 << 4)
#define BRIDGE_ARB_HPRI_RING_B0 (1 << 3)
#define BRIDGE_ARB_LPRI_RING_B2 (1 << 2)
#define BRIDGE_ARB_LPRI_RING_B1 (1 << 1)
#define BRIDGE_ARB_LPRI_RING_B0 (1 << 0)

#define BRIDGE_BUS_PCI_RETRY_HLD(x) ((x) << 16)
#define BRIDGE_BUS_PCI_RETRY_HLD_MASK BRIDGE_BUS_PCI_RETRY_HLD(0x1f)
#define BRIDGE_BUS_GIO_TIMEOUT (1 << 12)
#define BRIDGE_BUS_PCI_RETRY_CNT(x) ((x) << 0)
#define BRIDGE_BUS_PCI_RETRY_MASK BRIDGE_BUS_PCI_RETRY_CNT(0x3ff)

#define BRIDGE_ISR_MULTI_ERR (0x1u << 31)
#define BRIDGE_ISR_PMU_ESIZE_FAULT (0x1 << 30)
#define BRIDGE_ISR_UNEXP_RESP (0x1 << 29)
#define BRIDGE_ISR_BAD_XRESP_PKT (0x1 << 28)
#define BRIDGE_ISR_BAD_XREQ_PKT (0x1 << 27)
#define BRIDGE_ISR_RESP_XTLK_ERR (0x1 << 26)
#define BRIDGE_ISR_REQ_XTLK_ERR (0x1 << 25)
#define BRIDGE_ISR_INVLD_ADDR (0x1 << 24)
#define BRIDGE_ISR_UNSUPPORTED_XOP (0x1 << 23)
#define BRIDGE_ISR_XREQ_FIFO_OFLOW (0x1 << 22)
#define BRIDGE_ISR_LLP_REC_SNERR (0x1 << 21)
#define BRIDGE_ISR_LLP_REC_CBERR (0x1 << 20)
#define BRIDGE_ISR_LLP_RCTY (0x1 << 19)
#define BRIDGE_ISR_LLP_TX_RETRY (0x1 << 18)
#define BRIDGE_ISR_LLP_TCTY (0x1 << 17)
#define BRIDGE_ISR_SSRAM_PERR (0x1 << 16)
#define BRIDGE_ISR_PCI_ABORT (0x1 << 15)
#define BRIDGE_ISR_PCI_PARITY (0x1 << 14)
#define BRIDGE_ISR_PCI_SERR (0x1 << 13)
#define BRIDGE_ISR_PCI_PERR (0x1 << 12)
#define BRIDGE_ISR_PCI_MST_TIMEOUT (0x1 << 11)
#define BRIDGE_ISR_GIO_MST_TIMEOUT BRIDGE_ISR_PCI_MST_TIMEOUT
#define BRIDGE_ISR_PCI_RETRY_CNT (0x1 << 10)
#define BRIDGE_ISR_XREAD_REQ_TIMEOUT (0x1 << 9)
#define BRIDGE_ISR_GIO_B_ENBL_ERR (0x1 << 8)
#define BRIDGE_ISR_INT_MSK (0xff << 0)
#define BRIDGE_ISR_INT(x) (0x1 << (x))

#define BRIDGE_ISR_LINK_ERROR   (BRIDGE_ISR_LLP_REC_SNERR|BRIDGE_ISR_LLP_REC_CBERR|   BRIDGE_ISR_LLP_RCTY|BRIDGE_ISR_LLP_TX_RETRY|   BRIDGE_ISR_LLP_TCTY)

#define BRIDGE_ISR_PCIBUS_PIOERR   (BRIDGE_ISR_PCI_MST_TIMEOUT|BRIDGE_ISR_PCI_ABORT)

#define BRIDGE_ISR_PCIBUS_ERROR   (BRIDGE_ISR_PCIBUS_PIOERR|BRIDGE_ISR_PCI_PERR|   BRIDGE_ISR_PCI_SERR|BRIDGE_ISR_PCI_RETRY_CNT|   BRIDGE_ISR_PCI_PARITY)

#define BRIDGE_ISR_XTALK_ERROR   (BRIDGE_ISR_XREAD_REQ_TIMEOUT|BRIDGE_ISR_XREQ_FIFO_OFLOW|  BRIDGE_ISR_UNSUPPORTED_XOP|BRIDGE_ISR_INVLD_ADDR|   BRIDGE_ISR_REQ_XTLK_ERR|BRIDGE_ISR_RESP_XTLK_ERR|   BRIDGE_ISR_BAD_XREQ_PKT|BRIDGE_ISR_BAD_XRESP_PKT|   BRIDGE_ISR_UNEXP_RESP)

#define BRIDGE_ISR_ERRORS   (BRIDGE_ISR_LINK_ERROR|BRIDGE_ISR_PCIBUS_ERROR|   BRIDGE_ISR_XTALK_ERROR|BRIDGE_ISR_SSRAM_PERR|   BRIDGE_ISR_PMU_ESIZE_FAULT)

#define BRIDGE_ISR_ERROR_FATAL   ((BRIDGE_ISR_XTALK_ERROR & ~BRIDGE_ISR_XREAD_REQ_TIMEOUT)|  BRIDGE_ISR_PCI_SERR|BRIDGE_ISR_PCI_PARITY )

#define BRIDGE_ISR_ERROR_DUMP   (BRIDGE_ISR_PCIBUS_ERROR|BRIDGE_ISR_PMU_ESIZE_FAULT|   BRIDGE_ISR_XTALK_ERROR|BRIDGE_ISR_SSRAM_PERR)

#define BRIDGE_IMR_UNEXP_RESP BRIDGE_ISR_UNEXP_RESP
#define BRIDGE_IMR_PMU_ESIZE_FAULT BRIDGE_ISR_PMU_ESIZE_FAULT
#define BRIDGE_IMR_BAD_XRESP_PKT BRIDGE_ISR_BAD_XRESP_PKT
#define BRIDGE_IMR_BAD_XREQ_PKT BRIDGE_ISR_BAD_XREQ_PKT
#define BRIDGE_IMR_RESP_XTLK_ERR BRIDGE_ISR_RESP_XTLK_ERR
#define BRIDGE_IMR_REQ_XTLK_ERR BRIDGE_ISR_REQ_XTLK_ERR
#define BRIDGE_IMR_INVLD_ADDR BRIDGE_ISR_INVLD_ADDR
#define BRIDGE_IMR_UNSUPPORTED_XOP BRIDGE_ISR_UNSUPPORTED_XOP
#define BRIDGE_IMR_XREQ_FIFO_OFLOW BRIDGE_ISR_XREQ_FIFO_OFLOW
#define BRIDGE_IMR_LLP_REC_SNERR BRIDGE_ISR_LLP_REC_SNERR
#define BRIDGE_IMR_LLP_REC_CBERR BRIDGE_ISR_LLP_REC_CBERR
#define BRIDGE_IMR_LLP_RCTY BRIDGE_ISR_LLP_RCTY
#define BRIDGE_IMR_LLP_TX_RETRY BRIDGE_ISR_LLP_TX_RETRY
#define BRIDGE_IMR_LLP_TCTY BRIDGE_ISR_LLP_TCTY
#define BRIDGE_IMR_SSRAM_PERR BRIDGE_ISR_SSRAM_PERR
#define BRIDGE_IMR_PCI_ABORT BRIDGE_ISR_PCI_ABORT
#define BRIDGE_IMR_PCI_PARITY BRIDGE_ISR_PCI_PARITY
#define BRIDGE_IMR_PCI_SERR BRIDGE_ISR_PCI_SERR
#define BRIDGE_IMR_PCI_PERR BRIDGE_ISR_PCI_PERR
#define BRIDGE_IMR_PCI_MST_TIMEOUT BRIDGE_ISR_PCI_MST_TIMEOUT
#define BRIDGE_IMR_GIO_MST_TIMEOUT BRIDGE_ISR_GIO_MST_TIMEOUT
#define BRIDGE_IMR_PCI_RETRY_CNT BRIDGE_ISR_PCI_RETRY_CNT
#define BRIDGE_IMR_XREAD_REQ_TIMEOUT BRIDGE_ISR_XREAD_REQ_TIMEOUT
#define BRIDGE_IMR_GIO_B_ENBL_ERR BRIDGE_ISR_GIO_B_ENBL_ERR
#define BRIDGE_IMR_INT_MSK BRIDGE_ISR_INT_MSK
#define BRIDGE_IMR_INT(x) BRIDGE_ISR_INT(x)

#define BRIDGE_IRR_MULTI_CLR (0x1 << 6)
#define BRIDGE_IRR_CRP_GRP_CLR (0x1 << 5)
#define BRIDGE_IRR_RESP_BUF_GRP_CLR (0x1 << 4)
#define BRIDGE_IRR_REQ_DSP_GRP_CLR (0x1 << 3)
#define BRIDGE_IRR_LLP_GRP_CLR (0x1 << 2)
#define BRIDGE_IRR_SSRAM_GRP_CLR (0x1 << 1)
#define BRIDGE_IRR_PCI_GRP_CLR (0x1 << 0)
#define BRIDGE_IRR_GIO_GRP_CLR (0x1 << 0)
#define BRIDGE_IRR_ALL_CLR 0x7f

#define BRIDGE_IRR_CRP_GRP (BRIDGE_ISR_UNEXP_RESP |   BRIDGE_ISR_XREQ_FIFO_OFLOW)
#define BRIDGE_IRR_RESP_BUF_GRP (BRIDGE_ISR_BAD_XRESP_PKT |   BRIDGE_ISR_RESP_XTLK_ERR |   BRIDGE_ISR_XREAD_REQ_TIMEOUT)
#define BRIDGE_IRR_REQ_DSP_GRP (BRIDGE_ISR_UNSUPPORTED_XOP |   BRIDGE_ISR_BAD_XREQ_PKT |   BRIDGE_ISR_REQ_XTLK_ERR |   BRIDGE_ISR_INVLD_ADDR)
#define BRIDGE_IRR_LLP_GRP (BRIDGE_ISR_LLP_REC_SNERR |   BRIDGE_ISR_LLP_REC_CBERR |   BRIDGE_ISR_LLP_RCTY |   BRIDGE_ISR_LLP_TX_RETRY |   BRIDGE_ISR_LLP_TCTY)
#define BRIDGE_IRR_SSRAM_GRP (BRIDGE_ISR_SSRAM_PERR |   BRIDGE_ISR_PMU_ESIZE_FAULT)
#define BRIDGE_IRR_PCI_GRP (BRIDGE_ISR_PCI_ABORT |   BRIDGE_ISR_PCI_PARITY |   BRIDGE_ISR_PCI_SERR |   BRIDGE_ISR_PCI_PERR |   BRIDGE_ISR_PCI_MST_TIMEOUT |   BRIDGE_ISR_PCI_RETRY_CNT)

#define BRIDGE_IRR_GIO_GRP (BRIDGE_ISR_GIO_B_ENBL_ERR |   BRIDGE_ISR_GIO_MST_TIMEOUT)

#define BRIDGE_INT_DEV_SHFT(n) ((n)*3)
#define BRIDGE_INT_DEV_MASK(n) (0x7 << BRIDGE_INT_DEV_SHFT(n))
#define BRIDGE_INT_DEV_SET(_dev, _line) (_dev << BRIDGE_INT_DEV_SHFT(_line))

#define BRIDGE_INT_ADDR_HOST 0x0003FF00
#define BRIDGE_INT_ADDR_FLD 0x000000FF

#define BRIDGE_TMO_PCI_RETRY_HLD_MASK 0x1f0000
#define BRIDGE_TMO_GIO_TIMEOUT_MASK 0x001000
#define BRIDGE_TMO_PCI_RETRY_CNT_MASK 0x0003ff

#define BRIDGE_TMO_PCI_RETRY_CNT_MAX 0x3ff

#define BRIDGE_INT_ADDR_NASID_SHFT 8

#define BRIDGE_INT_ADDR_DEST_IO (1 << 17)
#define BRIDGE_INT_ADDR_DEST_MEM 0
#define BRIDGE_INT_ADDR_MASK (1 << 17)

#define BRIDGE_DEV_ERR_LOCK_EN 0x10000000
#define BRIDGE_DEV_PAGE_CHK_DIS 0x08000000
#define BRIDGE_DEV_FORCE_PCI_PAR 0x04000000
#define BRIDGE_DEV_VIRTUAL_EN 0x02000000
#define BRIDGE_DEV_PMU_WRGA_EN 0x01000000
#define BRIDGE_DEV_DIR_WRGA_EN 0x00800000
#define BRIDGE_DEV_DEV_SIZE 0x00400000
#define BRIDGE_DEV_RT 0x00200000
#define BRIDGE_DEV_SWAP_PMU 0x00100000
#define BRIDGE_DEV_SWAP_DIR 0x00080000
#define BRIDGE_DEV_PREF 0x00040000
#define BRIDGE_DEV_PRECISE 0x00020000
#define BRIDGE_DEV_COH 0x00010000
#define BRIDGE_DEV_BARRIER 0x00008000
#define BRIDGE_DEV_GBR 0x00004000
#define BRIDGE_DEV_DEV_SWAP 0x00002000
#define BRIDGE_DEV_DEV_IO_MEM 0x00001000
#define BRIDGE_DEV_OFF_MASK 0x00000fff
#define BRIDGE_DEV_OFF_ADDR_SHFT 20

#define BRIDGE_DEV_PMU_BITS (BRIDGE_DEV_PMU_WRGA_EN |   BRIDGE_DEV_SWAP_PMU)
#define BRIDGE_DEV_D32_BITS (BRIDGE_DEV_DIR_WRGA_EN |   BRIDGE_DEV_SWAP_DIR |   BRIDGE_DEV_PREF |   BRIDGE_DEV_PRECISE |   BRIDGE_DEV_COH |   BRIDGE_DEV_BARRIER)
#define BRIDGE_DEV_D64_BITS (BRIDGE_DEV_DIR_WRGA_EN |   BRIDGE_DEV_SWAP_DIR |   BRIDGE_DEV_COH |   BRIDGE_DEV_BARRIER)

#define BRIDGE_ERRUPPR_DEVMASTER (0x1 << 20)  
#define BRIDGE_ERRUPPR_PCIVDEV (0x1 << 19)  
#define BRIDGE_ERRUPPR_DEVNUM_SHFT (16)
#define BRIDGE_ERRUPPR_DEVNUM_MASK (0x7 << BRIDGE_ERRUPPR_DEVNUM_SHFT)
#define BRIDGE_ERRUPPR_DEVICE(err) (((err) >> BRIDGE_ERRUPPR_DEVNUM_SHFT) & 0x7)
#define BRIDGE_ERRUPPR_ADDRMASK (0xFFFF)

#define BRIDGE_INTMODE_CLR_PKT_EN(x) (0x1 << (x))

#define BRIDGE_CREDIT 3

#define BRIDGE_RRB_EN 0x8  
#define BRIDGE_RRB_DEV 0x7  
#define BRIDGE_RRB_VDEV 0x4  
#define BRIDGE_RRB_PDEV 0x3  

#define BRIDGE_RRB_VALID(r) (0x00010000<<(r))
#define BRIDGE_RRB_INUSE(r) (0x00000001<<(r))

#define BRIDGE_RRB_CLEAR(r) (0x00000001<<(r))

#define XBOX_BRIDGE_WID 8
#define FLASH_PROM1_BASE 0xE00000  
#define XBOX_RPS_EXISTS 1 << 6  
#define XBOX_RPS_FAIL 1 << 4  

#define BRIDGE_PIO32_XTALK_ALIAS_BASE 0x000040000000L
#define BRIDGE_PIO32_XTALK_ALIAS_LIMIT 0x00007FFFFFFFL
#define BRIDGE_PIO64_XTALK_ALIAS_BASE 0x000080000000L
#define BRIDGE_PIO64_XTALK_ALIAS_LIMIT 0x0000BFFFFFFFL
#define BRIDGE_PCIIO_XTALK_ALIAS_BASE 0x000100000000L
#define BRIDGE_PCIIO_XTALK_ALIAS_LIMIT 0x0001FFFFFFFFL

#define BRIDGE_MIN_PIO_ADDR_MEM 0x00000000  
#define BRIDGE_MAX_PIO_ADDR_MEM 0x3fffffff
#define BRIDGE_MIN_PIO_ADDR_IO 0x00000000  
#define BRIDGE_MAX_PIO_ADDR_IO 0xffffffff

#define BRIDGE_PCI_MEM32_BASE BRIDGE_PIO32_XTALK_ALIAS_BASE
#define BRIDGE_PCI_MEM32_LIMIT BRIDGE_PIO32_XTALK_ALIAS_LIMIT
#define BRIDGE_PCI_MEM64_BASE BRIDGE_PIO64_XTALK_ALIAS_BASE
#define BRIDGE_PCI_MEM64_LIMIT BRIDGE_PIO64_XTALK_ALIAS_LIMIT
#define BRIDGE_PCI_IO_BASE BRIDGE_PCIIO_XTALK_ALIAS_BASE
#define BRIDGE_PCI_IO_LIMIT BRIDGE_PCIIO_XTALK_ALIAS_LIMIT

#define BRIDGE_LOCAL_BASE 0
#define BRIDGE_DMA_MAPPED_BASE 0x40000000
#define BRIDGE_DMA_MAPPED_SIZE 0x40000000  
#define BRIDGE_DMA_DIRECT_BASE 0x80000000
#define BRIDGE_DMA_DIRECT_SIZE 0x80000000  

#define PCI32_LOCAL_BASE BRIDGE_LOCAL_BASE

#define PCI32_MAPPED_BASE BRIDGE_DMA_MAPPED_BASE
#define PCI32_DIRECT_BASE BRIDGE_DMA_DIRECT_BASE

#define IS_PCI32_LOCAL(x) ((ulong_t)(x) < PCI32_MAPPED_BASE)
#define IS_PCI32_MAPPED(x) ((ulong_t)(x) < PCI32_DIRECT_BASE &&   (ulong_t)(x) >= PCI32_MAPPED_BASE)
#define IS_PCI32_DIRECT(x) ((ulong_t)(x) >= PCI32_MAPPED_BASE)
#define IS_PCI64(x) ((ulong_t)(x) >= PCI64_BASE)

#define BRIDGE_GIO_MEM32_BASE BRIDGE_PIO32_XTALK_ALIAS_BASE
#define BRIDGE_GIO_MEM32_LIMIT BRIDGE_PIO32_XTALK_ALIAS_LIMIT

#define GIO_LOCAL_BASE BRIDGE_LOCAL_BASE

#define GIO_MAPPED_BASE BRIDGE_DMA_MAPPED_BASE
#define GIO_DIRECT_BASE BRIDGE_DMA_DIRECT_BASE

#define IS_GIO_LOCAL(x) ((ulong_t)(x) < GIO_MAPPED_BASE)
#define IS_GIO_MAPPED(x) ((ulong_t)(x) < GIO_DIRECT_BASE &&   (ulong_t)(x) >= GIO_MAPPED_BASE)
#define IS_GIO_DIRECT(x) ((ulong_t)(x) >= GIO_MAPPED_BASE)

#define BRIDGE_DIRECT_32_SEG_SIZE BRIDGE_DMA_DIRECT_SIZE
#define BRIDGE_DIRECT_32_TO_XTALK(dir_off,adr)   ((dir_off) * BRIDGE_DIRECT_32_SEG_SIZE +   ((adr) & (BRIDGE_DIRECT_32_SEG_SIZE - 1)) + PHYS_RAMBASE)

#define PCI64_ATTR_TARG_MASK 0xf000000000000000
#define PCI64_ATTR_TARG_SHFT 60
#define PCI64_ATTR_PREF 0x0800000000000000
#define PCI64_ATTR_PREC 0x0400000000000000
#define PCI64_ATTR_VIRTUAL 0x0200000000000000
#define PCI64_ATTR_BAR 0x0100000000000000
#define PCI64_ATTR_RMF_MASK 0x00ff000000000000
#define PCI64_ATTR_RMF_SHFT 48

#ifndef __ASSEMBLY__

typedef union ate_u {
 u64 ent;
 struct ate_s {
 u64 rmf:16;
 u64 addr:36;
 u64 targ:4;
 u64 reserved:3;
 u64 barrier:1;
 u64 prefetch:1;
 u64 precise:1;
 u64 coherent:1;
 u64 valid:1;
 } field;
} ate_t;
#endif

#define ATE_V 0x01
#define ATE_CO 0x02
#define ATE_PREC 0x04
#define ATE_PREF 0x08
#define ATE_BAR 0x10

#define ATE_PFNSHIFT 12
#define ATE_TIDSHIFT 8
#define ATE_RMFSHIFT 48

#define mkate(xaddr, xid, attr) ((xaddr) & 0x0000fffffffff000ULL) |   ((xid)<<ATE_TIDSHIFT) |   (attr)

#define BRIDGE_INTERNAL_ATES 128

struct bridge_controller {
 struct pci_controller pc;
 struct resource mem;
 struct resource io;
 bridge_t *base;
 nasid_t nasid;
 unsigned int widget_id;
 unsigned int irq_cpu;
 dma64_addr_t baddr;
 unsigned int pci_int[8];
};

#define BRIDGE_CONTROLLER(bus)   ((struct bridge_controller *)((bus)->sysdata))

#endif
