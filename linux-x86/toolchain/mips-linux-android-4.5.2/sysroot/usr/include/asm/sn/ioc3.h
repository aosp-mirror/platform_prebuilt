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
#ifndef _IOC3_H
#define _IOC3_H

#include <linux/types.h>

typedef volatile struct ioc3_uartregs {
 union {
 volatile u8 rbr;
 volatile u8 thr;
 volatile u8 dll;
 } u1;
 union {
 volatile u8 ier;
 volatile u8 dlm;
 } u2;
 union {
 volatile u8 iir;
 volatile u8 fcr;
 } u3;
 volatile u8 iu_lcr;
 volatile u8 iu_mcr;
 volatile u8 iu_lsr;
 volatile u8 iu_msr;
 volatile u8 iu_scr;
} ioc3_uregs_t;

#define iu_rbr u1.rbr
#define iu_thr u1.thr
#define iu_dll u1.dll
#define iu_ier u2.ier
#define iu_dlm u2.dlm
#define iu_iir u3.iir
#define iu_fcr u3.fcr

struct ioc3_sioregs {
 volatile u8 fill[0x141];

 volatile u8 uartc;
 volatile u8 kbdcg;

 volatile u8 fill0[0x150 - 0x142 - 1];

 volatile u8 pp_data;
 volatile u8 pp_dsr;
 volatile u8 pp_dcr;

 volatile u8 fill1[0x158 - 0x152 - 1];

 volatile u8 pp_fifa;
 volatile u8 pp_cfgb;
 volatile u8 pp_ecr;

 volatile u8 fill2[0x168 - 0x15a - 1];

 volatile u8 rtcad;
 volatile u8 rtcdat;

 volatile u8 fill3[0x170 - 0x169 - 1];

 struct ioc3_uartregs uartb;
 struct ioc3_uartregs uarta;
};

struct ioc3 {
 volatile u32 pad0[7];
 volatile u32 sio_ir;
 volatile u32 sio_ies;
 volatile u32 sio_iec;
 volatile u32 sio_cr;
 volatile u32 int_out;
 volatile u32 mcr;

 volatile u32 gpcr_s;
 volatile u32 gpcr_c;
 volatile u32 gpdr;
 volatile u32 gppr_0;
 volatile u32 gppr_1;
 volatile u32 gppr_2;
 volatile u32 gppr_3;
 volatile u32 gppr_4;
 volatile u32 gppr_5;
 volatile u32 gppr_6;
 volatile u32 gppr_7;
 volatile u32 gppr_8;
 volatile u32 gppr_9;
 volatile u32 gppr_10;
 volatile u32 gppr_11;
 volatile u32 gppr_12;
 volatile u32 gppr_13;
 volatile u32 gppr_14;
 volatile u32 gppr_15;

 volatile u32 ppbr_h_a;
 volatile u32 ppbr_l_a;
 volatile u32 ppcr_a;
 volatile u32 ppcr;
 volatile u32 ppbr_h_b;
 volatile u32 ppbr_l_b;
 volatile u32 ppcr_b;

 volatile u32 km_csr;
 volatile u32 k_rd;
 volatile u32 m_rd;
 volatile u32 k_wd;
 volatile u32 m_wd;

 volatile u32 sbbr_h;
 volatile u32 sbbr_l;
 volatile u32 sscr_a;
 volatile u32 stpir_a;
 volatile u32 stcir_a;
 volatile u32 srpir_a;
 volatile u32 srcir_a;
 volatile u32 srtr_a;
 volatile u32 shadow_a;
 volatile u32 sscr_b;
 volatile u32 stpir_b;
 volatile u32 stcir_b;
 volatile u32 srpir_b;
 volatile u32 srcir_b;
 volatile u32 srtr_b;
 volatile u32 shadow_b;

 volatile u32 emcr;
 volatile u32 eisr;
 volatile u32 eier;
 volatile u32 ercsr;
 volatile u32 erbr_h;
 volatile u32 erbr_l;
 volatile u32 erbar;
 volatile u32 ercir;
 volatile u32 erpir;
 volatile u32 ertr;
 volatile u32 etcsr;
 volatile u32 ersr;
 volatile u32 etcdc;
 volatile u32 ebir;
 volatile u32 etbr_h;
 volatile u32 etbr_l;
 volatile u32 etcir;
 volatile u32 etpir;
 volatile u32 emar_h;
 volatile u32 emar_l;
 volatile u32 ehar_h;
 volatile u32 ehar_l;
 volatile u32 micr;
 volatile u32 midr_r;
 volatile u32 midr_w;
 volatile u32 pad1[(0x20000 - 0x00154) / 4];

 struct ioc3_sioregs sregs;
 volatile u32 pad2[(0x40000 - 0x20180) / 4];

 volatile u32 ssram[(0x80000 - 0x40000) / 4];

};

struct ioc3_erxbuf {
 u32 w0;
 u32 err;

};

#define ERXBUF_IPCKSUM_MASK 0x0000ffff
#define ERXBUF_BYTECNT_MASK 0x07ff0000
#define ERXBUF_BYTECNT_SHIFT 16
#define ERXBUF_V 0x80000000

#define ERXBUF_CRCERR 0x00000001  
#define ERXBUF_FRAMERR 0x00000002  
#define ERXBUF_CODERR 0x00000004  
#define ERXBUF_INVPREAMB 0x00000008  
#define ERXBUF_LOLEN 0x00007000  
#define ERXBUF_HILEN 0x03ff0000  
#define ERXBUF_MULTICAST 0x04000000  
#define ERXBUF_BROADCAST 0x08000000  
#define ERXBUF_LONGEVENT 0x10000000  
#define ERXBUF_BADPKT 0x20000000  
#define ERXBUF_GOODPKT 0x40000000  
#define ERXBUF_CARRIER 0x80000000  

#define ETXD_DATALEN 104
struct ioc3_etxd {
 u32 cmd;
 u32 bufcnt;
 u64 p1;
 u64 p2;
 u8 data[ETXD_DATALEN];
};

#define ETXD_BYTECNT_MASK 0x000007ff  
#define ETXD_INTWHENDONE 0x00001000  
#define ETXD_D0V 0x00010000  
#define ETXD_B1V 0x00020000  
#define ETXD_B2V 0x00040000  
#define ETXD_DOCHECKSUM 0x00080000  
#define ETXD_CHKOFF_MASK 0x07f00000  
#define ETXD_CHKOFF_SHIFT 20

#define ETXD_D0CNT_MASK 0x0000007f
#define ETXD_B1CNT_MASK 0x0007ff00
#define ETXD_B1CNT_SHIFT 8
#define ETXD_B2CNT_MASK 0x7ff00000
#define ETXD_B2CNT_SHIFT 20

#define IOC3_BYTEBUS_DEV0 0x80000L
#define IOC3_BYTEBUS_DEV1 0xa0000L
#define IOC3_BYTEBUS_DEV2 0xc0000L
#define IOC3_BYTEBUS_DEV3 0xe0000L

#define IOC3_SIO_BASE 0x20000
#define IOC3_SIO_UARTC (IOC3_SIO_BASE+0x141)  
#define IOC3_SIO_KBDCG (IOC3_SIO_BASE+0x142)  
#define IOC3_SIO_PP_BASE (IOC3_SIO_BASE+PP_BASE)  
#define IOC3_SIO_RTC_BASE (IOC3_SIO_BASE+0x168)  
#define IOC3_SIO_UB_BASE (IOC3_SIO_BASE+UARTB_BASE)  
#define IOC3_SIO_UA_BASE (IOC3_SIO_BASE+UARTA_BASE)  

#define IOC3_SSRAM IOC3_RAM_OFF  
#define IOC3_SSRAM_LEN 0x40000  
#define IOC3_SSRAM_DM 0x0000ffff  
#define IOC3_SSRAM_PM 0x00010000  

#define PCI_SCR_PAR_RESP_EN 0x00000040  
#define PCI_SCR_SERR_EN 0x00000100  
#define PCI_SCR_DROP_MODE_EN 0x00008000  
#define PCI_SCR_RX_SERR (0x1 << 16)
#define PCI_SCR_DROP_MODE (0x1 << 17)
#define PCI_SCR_SIG_PAR_ERR (0x1 << 24)
#define PCI_SCR_SIG_TAR_ABRT (0x1 << 27)
#define PCI_SCR_RX_TAR_ABRT (0x1 << 28)
#define PCI_SCR_SIG_MST_ABRT (0x1 << 29)
#define PCI_SCR_SIG_SERR (0x1 << 30)
#define PCI_SCR_PAR_ERR (0x1 << 31)

#define KM_CSR_K_WRT_PEND 0x00000001  
#define KM_CSR_M_WRT_PEND 0x00000002  
#define KM_CSR_K_LCB 0x00000004  
#define KM_CSR_M_LCB 0x00000008  
#define KM_CSR_K_DATA 0x00000010  
#define KM_CSR_K_CLK 0x00000020  
#define KM_CSR_K_PULL_DATA 0x00000040  
#define KM_CSR_K_PULL_CLK 0x00000080  
#define KM_CSR_M_DATA 0x00000100  
#define KM_CSR_M_CLK 0x00000200  
#define KM_CSR_M_PULL_DATA 0x00000400  
#define KM_CSR_M_PULL_CLK 0x00000800  
#define KM_CSR_EMM_MODE 0x00001000  
#define KM_CSR_SIM_MODE 0x00002000  
#define KM_CSR_K_SM_IDLE 0x00004000  
#define KM_CSR_M_SM_IDLE 0x00008000  
#define KM_CSR_K_TO 0x00010000  
#define KM_CSR_M_TO 0x00020000  
#define KM_CSR_K_TO_EN 0x00040000  
#define KM_CSR_M_TO_EN 0x00080000  
#define KM_CSR_K_CLAMP_ONE 0x00100000  
#define KM_CSR_M_CLAMP_ONE 0x00200000  
#define KM_CSR_K_CLAMP_THREE 0x00400000  
#define KM_CSR_M_CLAMP_THREE 0x00800000  

#define KM_RD_DATA_2 0x000000ff  
#define KM_RD_DATA_2_SHIFT 0
#define KM_RD_DATA_1 0x0000ff00  
#define KM_RD_DATA_1_SHIFT 8
#define KM_RD_DATA_0 0x00ff0000  
#define KM_RD_DATA_0_SHIFT 16
#define KM_RD_FRAME_ERR_2 0x01000000  
#define KM_RD_FRAME_ERR_1 0x02000000  
#define KM_RD_FRAME_ERR_0 0x04000000  

#define KM_RD_KBD_MSE 0x08000000  
#define KM_RD_OFLO 0x10000000  
#define KM_RD_VALID_2 0x20000000  
#define KM_RD_VALID_1 0x40000000  
#define KM_RD_VALID_0 0x80000000  
#define KM_RD_VALID_ALL (KM_RD_VALID_0|KM_RD_VALID_1|KM_RD_VALID_2)

#define KM_WD_WRT_DATA 0x000000ff  
#define KM_WD_WRT_DATA_SHIFT 0

#define RXSB_OVERRUN 0x01  
#define RXSB_PAR_ERR 0x02  
#define RXSB_FRAME_ERR 0x04  
#define RXSB_BREAK 0x08  
#define RXSB_CTS 0x10  
#define RXSB_DCD 0x20  
#define RXSB_MODEM_VALID 0x40  
#define RXSB_DATA_VALID 0x80  

#define TXCB_INT_WHEN_DONE 0x20  
#define TXCB_INVALID 0x00  
#define TXCB_VALID 0x40  
#define TXCB_MCR 0x80  
#define TXCB_DELAY 0xc0  

#define SBBR_L_SIZE 0x00000001  
#define SBBR_L_BASE 0xfffff000  

#define SSCR_RX_THRESHOLD 0x000001ff  
#define SSCR_TX_TIMER_BUSY 0x00010000  
#define SSCR_HFC_EN 0x00020000  
#define SSCR_RX_RING_DCD 0x00040000  
#define SSCR_RX_RING_CTS 0x00080000  
#define SSCR_HIGH_SPD 0x00100000  
#define SSCR_DIAG 0x00200000  
#define SSCR_RX_DRAIN 0x08000000  
#define SSCR_DMA_EN 0x10000000  
#define SSCR_DMA_PAUSE 0x20000000  
#define SSCR_PAUSE_STATE 0x40000000  
#define SSCR_RESET 0x80000000  

#define PROD_CONS_PTR_4K 0x00000ff8  
#define PROD_CONS_PTR_1K 0x000003f8  
#define PROD_CONS_PTR_OFF 3

#define SRCIR_ARM 0x80000000  

#define SRPIR_BYTE_CNT 0x07000000  
#define SRPIR_BYTE_CNT_SHIFT 24

#define STCIR_BYTE_CNT 0x0f000000  
#define STCIR_BYTE_CNT_SHIFT 24

#define SHADOW_DR 0x00000001  
#define SHADOW_OE 0x00000002  
#define SHADOW_PE 0x00000004  
#define SHADOW_FE 0x00000008  
#define SHADOW_BI 0x00000010  
#define SHADOW_THRE 0x00000020  
#define SHADOW_TEMT 0x00000040  
#define SHADOW_RFCE 0x00000080  
#define SHADOW_DCTS 0x00010000  
#define SHADOW_DDCD 0x00080000  
#define SHADOW_CTS 0x00100000  
#define SHADOW_DCD 0x00800000  
#define SHADOW_DTR 0x01000000  
#define SHADOW_RTS 0x02000000  
#define SHADOW_OUT1 0x04000000  
#define SHADOW_OUT2 0x08000000  
#define SHADOW_LOOP 0x10000000  

#define SRTR_CNT 0x00000fff  
#define SRTR_CNT_VAL 0x0fff0000  
#define SRTR_CNT_VAL_SHIFT 16
#define SRTR_HZ 16000  

#define SIO_IR_SA_TX_MT 0x00000001  
#define SIO_IR_SA_RX_FULL 0x00000002  
#define SIO_IR_SA_RX_HIGH 0x00000004  
#define SIO_IR_SA_RX_TIMER 0x00000008  
#define SIO_IR_SA_DELTA_DCD 0x00000010  
#define SIO_IR_SA_DELTA_CTS 0x00000020  
#define SIO_IR_SA_INT 0x00000040  
#define SIO_IR_SA_TX_EXPLICIT 0x00000080  
#define SIO_IR_SA_MEMERR 0x00000100  
#define SIO_IR_SB_TX_MT 0x00000200  
#define SIO_IR_SB_RX_FULL 0x00000400  
#define SIO_IR_SB_RX_HIGH 0x00000800  
#define SIO_IR_SB_RX_TIMER 0x00001000  
#define SIO_IR_SB_DELTA_DCD 0x00002000  
#define SIO_IR_SB_DELTA_CTS 0x00004000  
#define SIO_IR_SB_INT 0x00008000  
#define SIO_IR_SB_TX_EXPLICIT 0x00010000  
#define SIO_IR_SB_MEMERR 0x00020000  
#define SIO_IR_PP_INT 0x00040000  
#define SIO_IR_PP_INTA 0x00080000  
#define SIO_IR_PP_INTB 0x00100000  
#define SIO_IR_PP_MEMERR 0x00200000  
#define SIO_IR_KBD_INT 0x00400000  
#define SIO_IR_RT_INT 0x08000000  
#define SIO_IR_GEN_INT1 0x10000000  
#define SIO_IR_GEN_INT_SHIFT 28

#define SIO_IR_SA (SIO_IR_SA_TX_MT | SIO_IR_SA_RX_FULL |   SIO_IR_SA_RX_HIGH | SIO_IR_SA_RX_TIMER |   SIO_IR_SA_DELTA_DCD | SIO_IR_SA_DELTA_CTS |   SIO_IR_SA_INT | SIO_IR_SA_TX_EXPLICIT |   SIO_IR_SA_MEMERR)
#define SIO_IR_SB (SIO_IR_SB_TX_MT | SIO_IR_SB_RX_FULL |   SIO_IR_SB_RX_HIGH | SIO_IR_SB_RX_TIMER |   SIO_IR_SB_DELTA_DCD | SIO_IR_SB_DELTA_CTS |   SIO_IR_SB_INT | SIO_IR_SB_TX_EXPLICIT |   SIO_IR_SB_MEMERR)
#define SIO_IR_PP (SIO_IR_PP_INT | SIO_IR_PP_INTA |   SIO_IR_PP_INTB | SIO_IR_PP_MEMERR)
#define SIO_IR_RT (SIO_IR_RT_INT | SIO_IR_GEN_INT1)

#define IOC3_PENDING_INTRS(mem) (PCI_INW(&((mem)->sio_ir)) &   PCI_INW(&((mem)->sio_ies_ro)))

#define SIO_CR_SIO_RESET 0x00000001  
#define SIO_CR_SER_A_BASE 0x000000fe  
#define SIO_CR_SER_A_BASE_SHIFT 1
#define SIO_CR_SER_B_BASE 0x00007f00  
#define SIO_CR_SER_B_BASE_SHIFT 8
#define SIO_SR_CMD_PULSE 0x00078000  
#define SIO_CR_CMD_PULSE_SHIFT 15
#define SIO_CR_ARB_DIAG 0x00380000  
#define SIO_CR_ARB_DIAG_TXA 0x00000000
#define SIO_CR_ARB_DIAG_RXA 0x00080000
#define SIO_CR_ARB_DIAG_TXB 0x00100000
#define SIO_CR_ARB_DIAG_RXB 0x00180000
#define SIO_CR_ARB_DIAG_PP 0x00200000
#define SIO_CR_ARB_DIAG_IDLE 0x00400000  

#define INT_OUT_COUNT 0x0000ffff  
#define INT_OUT_MODE 0x00070000  
#define INT_OUT_MODE_0 0x00000000  
#define INT_OUT_MODE_1 0x00040000  
#define INT_OUT_MODE_1PULSE 0x00050000  
#define INT_OUT_MODE_PULSES 0x00060000  
#define INT_OUT_MODE_SQW 0x00070000  
#define INT_OUT_DIAG 0x40000000  
#define INT_OUT_INT_OUT 0x80000000  

#define INT_OUT_NS_PER_TICK (30 * 260)  
#define INT_OUT_TICKS_PER_PULSE 3  
#define INT_OUT_US_TO_COUNT(x)     (((x) * 10 + INT_OUT_NS_PER_TICK / 200) *   100 / INT_OUT_NS_PER_TICK - 1)
#define INT_OUT_COUNT_TO_US(x)     (((x) + 1) * INT_OUT_NS_PER_TICK / 1000)
#define INT_OUT_MIN_TICKS 3  
#define INT_OUT_MAX_TICKS INT_OUT_COUNT  

#define GPCR_DIR 0x000000ff  
#define GPCR_DIR_PIN(x) (1<<(x))  
#define GPCR_EDGE 0x000f0000  
#define GPCR_EDGE_PIN(x) (1<<((x)+15))  

#define GPCR_INT_OUT_EN 0x00100000  
#define GPCR_MLAN_EN 0x00200000  
#define GPCR_DIR_SERA_XCVR 0x00000080  
#define GPCR_DIR_SERB_XCVR 0x00000040  
#define GPCR_DIR_PHY_RST 0x00000020  

#define GPCR_PHY_RESET 0x20  
#define GPCR_UARTB_MODESEL 0x40  
#define GPCR_UARTA_MODESEL 0x80  

#define GPPR_PHY_RESET_PIN 5  
#define GPPR_UARTB_MODESEL_PIN 6  
#define GPPR_UARTA_MODESEL_PIN 7  

#define EMCR_DUPLEX 0x00000001
#define EMCR_PROMISC 0x00000002
#define EMCR_PADEN 0x00000004
#define EMCR_RXOFF_MASK 0x000001f8
#define EMCR_RXOFF_SHIFT 3
#define EMCR_RAMPAR 0x00000200
#define EMCR_BADPAR 0x00000800
#define EMCR_BUFSIZ 0x00001000
#define EMCR_TXDMAEN 0x00002000
#define EMCR_TXEN 0x00004000
#define EMCR_RXDMAEN 0x00008000
#define EMCR_RXEN 0x00010000
#define EMCR_LOOPBACK 0x00020000
#define EMCR_ARB_DIAG 0x001c0000
#define EMCR_ARB_DIAG_IDLE 0x00200000
#define EMCR_RST 0x80000000

#define EISR_RXTIMERINT 0x00000001
#define EISR_RXTHRESHINT 0x00000002
#define EISR_RXOFLO 0x00000004
#define EISR_RXBUFOFLO 0x00000008
#define EISR_RXMEMERR 0x00000010
#define EISR_RXPARERR 0x00000020
#define EISR_TXEMPTY 0x00010000
#define EISR_TXRTRY 0x00020000
#define EISR_TXEXDEF 0x00040000
#define EISR_TXLCOL 0x00080000
#define EISR_TXGIANT 0x00100000
#define EISR_TXBUFUFLO 0x00200000
#define EISR_TXEXPLICIT 0x00400000
#define EISR_TXCOLLWRAP 0x00800000
#define EISR_TXDEFERWRAP 0x01000000
#define EISR_TXMEMERR 0x02000000
#define EISR_TXPARERR 0x04000000

#define ERCSR_THRESH_MASK 0x000001ff  
#define ERCSR_RX_TMR 0x40000000  
#define ERCSR_DIAG_OFLO 0x80000000  

#define ERBR_ALIGNMENT 4096
#define ERBR_L_RXRINGBASE_MASK 0xfffff000

#define ERBAR_BARRIER_BIT 0x0100
#define ERBAR_RXBARR_MASK 0xffff0000
#define ERBAR_RXBARR_SHIFT 16

#define ERCIR_RXCONSUME_MASK 0x00000fff

#define ERPIR_RXPRODUCE_MASK 0x00000fff
#define ERPIR_ARM 0x80000000

#define ERTR_CNT_MASK 0x000007ff

#define ETCSR_IPGT_MASK 0x0000007f
#define ETCSR_IPGR1_MASK 0x00007f00
#define ETCSR_IPGR1_SHIFT 8
#define ETCSR_IPGR2_MASK 0x007f0000
#define ETCSR_IPGR2_SHIFT 16
#define ETCSR_NOTXCLK 0x80000000

#define ETCDC_COLLCNT_MASK 0x0000ffff
#define ETCDC_DEFERCNT_MASK 0xffff0000
#define ETCDC_DEFERCNT_SHIFT 16

#define ETBR_ALIGNMENT (64*1024)
#define ETBR_L_RINGSZ_MASK 0x00000001
#define ETBR_L_RINGSZ128 0
#define ETBR_L_RINGSZ512 1
#define ETBR_L_TXRINGBASE_MASK 0xffffc000

#define ETCIR_TXCONSUME_MASK 0x0000ffff
#define ETCIR_IDLE 0x80000000

#define ETPIR_TXPRODUCE_MASK 0x0000ffff

#define EBIR_TXBUFPROD_MASK 0x0000001f
#define EBIR_TXBUFCONS_MASK 0x00001f00
#define EBIR_TXBUFCONS_SHIFT 8
#define EBIR_RXBUFPROD_MASK 0x007fc000
#define EBIR_RXBUFPROD_SHIFT 14
#define EBIR_RXBUFCONS_MASK 0xff800000
#define EBIR_RXBUFCONS_SHIFT 23

#define MICR_REGADDR_MASK 0x0000001f
#define MICR_PHYADDR_MASK 0x000003e0
#define MICR_PHYADDR_SHIFT 5
#define MICR_READTRIG 0x00000400
#define MICR_BUSY 0x00000800

#define MIDR_DATA_MASK 0x0000ffff

#define ERXBUF_IPCKSUM_MASK 0x0000ffff
#define ERXBUF_BYTECNT_MASK 0x07ff0000
#define ERXBUF_BYTECNT_SHIFT 16
#define ERXBUF_V 0x80000000

#define ERXBUF_CRCERR 0x00000001  
#define ERXBUF_FRAMERR 0x00000002  
#define ERXBUF_CODERR 0x00000004  
#define ERXBUF_INVPREAMB 0x00000008  
#define ERXBUF_LOLEN 0x00007000  
#define ERXBUF_HILEN 0x03ff0000  
#define ERXBUF_MULTICAST 0x04000000  
#define ERXBUF_BROADCAST 0x08000000  
#define ERXBUF_LONGEVENT 0x10000000  
#define ERXBUF_BADPKT 0x20000000  
#define ERXBUF_GOODPKT 0x40000000  
#define ERXBUF_CARRIER 0x80000000  

#define ETXD_BYTECNT_MASK 0x000007ff  
#define ETXD_INTWHENDONE 0x00001000  
#define ETXD_D0V 0x00010000  
#define ETXD_B1V 0x00020000  
#define ETXD_B2V 0x00040000  
#define ETXD_DOCHECKSUM 0x00080000  
#define ETXD_CHKOFF_MASK 0x07f00000  
#define ETXD_CHKOFF_SHIFT 20

#define ETXD_D0CNT_MASK 0x0000007f
#define ETXD_B1CNT_MASK 0x0007ff00
#define ETXD_B1CNT_SHIFT 8
#define ETXD_B2CNT_MASK 0x7ff00000
#define ETXD_B2CNT_SHIFT 20

typedef enum ioc3_subdevs_e {
 ioc3_subdev_ether,
 ioc3_subdev_generic,
 ioc3_subdev_nic,
 ioc3_subdev_kbms,
 ioc3_subdev_ttya,
 ioc3_subdev_ttyb,
 ioc3_subdev_ecpp,
 ioc3_subdev_rt,
 ioc3_nsubdevs
} ioc3_subdev_t;

#define IOC3_SDB_ETHER (1<<ioc3_subdev_ether)
#define IOC3_SDB_GENERIC (1<<ioc3_subdev_generic)
#define IOC3_SDB_NIC (1<<ioc3_subdev_nic)
#define IOC3_SDB_KBMS (1<<ioc3_subdev_kbms)
#define IOC3_SDB_TTYA (1<<ioc3_subdev_ttya)
#define IOC3_SDB_TTYB (1<<ioc3_subdev_ttyb)
#define IOC3_SDB_ECPP (1<<ioc3_subdev_ecpp)
#define IOC3_SDB_RT (1<<ioc3_subdev_rt)

#define IOC3_ALL_SUBDEVS ((1<<ioc3_nsubdevs)-1)

#define IOC3_SDB_SERIAL (IOC3_SDB_TTYA|IOC3_SDB_TTYB)

#define IOC3_STD_SUBDEVS IOC3_ALL_SUBDEVS

#define IOC3_INTA_SUBDEVS IOC3_SDB_ETHER
#define IOC3_INTB_SUBDEVS (IOC3_SDB_GENERIC|IOC3_SDB_KBMS|IOC3_SDB_SERIAL|IOC3_SDB_ECPP|IOC3_SDB_RT)

#endif
