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
#ifndef _AU1000_H_
#define _AU1000_H_

#ifndef _LANGUAGE_ASSEMBLY

#include <linux/delay.h>
#include <linux/types.h>

#include <asm/io.h>
#include <asm/irq.h>

struct au1xxx_irqmap {
 int im_irq;
 int im_type;
 int im_request;
};

#endif

#define ALLINTS (IE_IRQ0 | IE_IRQ1 | IE_IRQ2 | IE_IRQ3 | IE_IRQ4 | IE_IRQ5)

#define MEM_STCFG0 0xB4001000
#define MEM_STTIME0 0xB4001004
#define MEM_STADDR0 0xB4001008

#define MEM_STCFG1 0xB4001010
#define MEM_STTIME1 0xB4001014
#define MEM_STADDR1 0xB4001018

#define MEM_STCFG2 0xB4001020
#define MEM_STTIME2 0xB4001024
#define MEM_STADDR2 0xB4001028

#define MEM_STCFG3 0xB4001030
#define MEM_STTIME3 0xB4001034
#define MEM_STADDR3 0xB4001038

#define IC0_CFG0RD 0xB0400040
#define IC0_CFG0SET 0xB0400040
#define IC0_CFG0CLR 0xB0400044

#define IC0_CFG1RD 0xB0400048
#define IC0_CFG1SET 0xB0400048
#define IC0_CFG1CLR 0xB040004C

#define IC0_CFG2RD 0xB0400050
#define IC0_CFG2SET 0xB0400050
#define IC0_CFG2CLR 0xB0400054

#define IC0_REQ0INT 0xB0400054
#define IC0_SRCRD 0xB0400058
#define IC0_SRCSET 0xB0400058
#define IC0_SRCCLR 0xB040005C
#define IC0_REQ1INT 0xB040005C

#define IC0_ASSIGNRD 0xB0400060
#define IC0_ASSIGNSET 0xB0400060
#define IC0_ASSIGNCLR 0xB0400064

#define IC0_WAKERD 0xB0400068
#define IC0_WAKESET 0xB0400068
#define IC0_WAKECLR 0xB040006C

#define IC0_MASKRD 0xB0400070
#define IC0_MASKSET 0xB0400070
#define IC0_MASKCLR 0xB0400074

#define IC0_RISINGRD 0xB0400078
#define IC0_RISINGCLR 0xB0400078
#define IC0_FALLINGRD 0xB040007C
#define IC0_FALLINGCLR 0xB040007C

#define IC0_TESTBIT 0xB0400080

#define IC1_CFG0RD 0xB1800040
#define IC1_CFG0SET 0xB1800040
#define IC1_CFG0CLR 0xB1800044

#define IC1_CFG1RD 0xB1800048
#define IC1_CFG1SET 0xB1800048
#define IC1_CFG1CLR 0xB180004C

#define IC1_CFG2RD 0xB1800050
#define IC1_CFG2SET 0xB1800050
#define IC1_CFG2CLR 0xB1800054

#define IC1_REQ0INT 0xB1800054
#define IC1_SRCRD 0xB1800058
#define IC1_SRCSET 0xB1800058
#define IC1_SRCCLR 0xB180005C
#define IC1_REQ1INT 0xB180005C

#define IC1_ASSIGNRD 0xB1800060
#define IC1_ASSIGNSET 0xB1800060
#define IC1_ASSIGNCLR 0xB1800064

#define IC1_WAKERD 0xB1800068
#define IC1_WAKESET 0xB1800068
#define IC1_WAKECLR 0xB180006C

#define IC1_MASKRD 0xB1800070
#define IC1_MASKSET 0xB1800070
#define IC1_MASKCLR 0xB1800074

#define IC1_RISINGRD 0xB1800078
#define IC1_RISINGCLR 0xB1800078
#define IC1_FALLINGRD 0xB180007C
#define IC1_FALLINGCLR 0xB180007C

#define IC1_TESTBIT 0xB1800080

#define INTC_INT_DISABLED 0
#define INTC_INT_RISE_EDGE 0x1
#define INTC_INT_FALL_EDGE 0x2
#define INTC_INT_RISE_AND_FALL_EDGE 0x3
#define INTC_INT_HIGH_LEVEL 0x5
#define INTC_INT_LOW_LEVEL 0x6
#define INTC_INT_HIGH_AND_LOW_LEVEL 0x7

#define AU1000_INTC0_INT_BASE (MIPS_CPU_IRQ_BASE + 8)
#define AU1000_INTC0_INT_LAST (AU1000_INTC0_INT_BASE + 31)
#define AU1000_INTC1_INT_BASE (AU1000_INTC0_INT_BASE + 32)
#define AU1000_INTC1_INT_LAST (AU1000_INTC1_INT_BASE + 31)

#define AU1000_MAX_INTR AU1000_INTC1_INT_LAST
#define INTX 0xFF  

#define SYS_BASE 0xB1900000
#define SYS_COUNTER_CNTRL (SYS_BASE + 0x14)
#define SYS_CNTRL_E1S (1<<23)
#define SYS_CNTRL_T1S (1<<20)
#define SYS_CNTRL_M21 (1<<19)
#define SYS_CNTRL_M11 (1<<18)
#define SYS_CNTRL_M01 (1<<17)
#define SYS_CNTRL_C1S (1<<16)
#define SYS_CNTRL_BP (1<<14)
#define SYS_CNTRL_EN1 (1<<13)
#define SYS_CNTRL_BT1 (1<<12)
#define SYS_CNTRL_EN0 (1<<11)
#define SYS_CNTRL_BT0 (1<<10)
#define SYS_CNTRL_E0 (1<<8)
#define SYS_CNTRL_E0S (1<<7)
#define SYS_CNTRL_32S (1<<5)
#define SYS_CNTRL_T0S (1<<4)
#define SYS_CNTRL_M20 (1<<3)
#define SYS_CNTRL_M10 (1<<2)
#define SYS_CNTRL_M00 (1<<1)
#define SYS_CNTRL_C0S (1<<0)

#define SYS_TOYTRIM (SYS_BASE + 0)
#define SYS_TOYWRITE (SYS_BASE + 4)
#define SYS_TOYMATCH0 (SYS_BASE + 8)
#define SYS_TOYMATCH1 (SYS_BASE + 0xC)
#define SYS_TOYMATCH2 (SYS_BASE + 0x10)
#define SYS_TOYREAD (SYS_BASE + 0x40)

#define SYS_RTCTRIM (SYS_BASE + 0x44)
#define SYS_RTCWRITE (SYS_BASE + 0x48)
#define SYS_RTCMATCH0 (SYS_BASE + 0x4C)
#define SYS_RTCMATCH1 (SYS_BASE + 0x50)
#define SYS_RTCMATCH2 (SYS_BASE + 0x54)
#define SYS_RTCREAD (SYS_BASE + 0x58)

#define I2S_DATA 0xB1000000
#define I2S_DATA_MASK (0xffffff)
#define I2S_CONFIG 0xB1000004
#define I2S_CONFIG_XU (1<<25)
#define I2S_CONFIG_XO (1<<24)
#define I2S_CONFIG_RU (1<<23)
#define I2S_CONFIG_RO (1<<22)
#define I2S_CONFIG_TR (1<<21)
#define I2S_CONFIG_TE (1<<20)
#define I2S_CONFIG_TF (1<<19)
#define I2S_CONFIG_RR (1<<18)
#define I2S_CONFIG_RE (1<<17)
#define I2S_CONFIG_RF (1<<16)
#define I2S_CONFIG_PD (1<<11)
#define I2S_CONFIG_LB (1<<10)
#define I2S_CONFIG_IC (1<<9)
#define I2S_CONFIG_FM_BIT 7
#define I2S_CONFIG_FM_MASK (0x3 << I2S_CONFIG_FM_BIT)
#define I2S_CONFIG_FM_I2S (0x0 << I2S_CONFIG_FM_BIT)
#define I2S_CONFIG_FM_LJ (0x1 << I2S_CONFIG_FM_BIT)
#define I2S_CONFIG_FM_RJ (0x2 << I2S_CONFIG_FM_BIT)
#define I2S_CONFIG_TN (1<<6)
#define I2S_CONFIG_RN (1<<5)
#define I2S_CONFIG_SZ_BIT 0
#define I2S_CONFIG_SZ_MASK (0x1F << I2S_CONFIG_SZ_BIT)

#define I2S_CONTROL 0xB1000008
#define I2S_CONTROL_D (1<<1)
#define I2S_CONTROL_CE (1<<0)

#ifndef USB_OHCI_LEN
#define USB_OHCI_LEN 0x00100000
#endif

#define USBD_EP0RD 0xB0200000
#define USBD_EP0WR 0xB0200004
#define USBD_EP2WR 0xB0200008
#define USBD_EP3WR 0xB020000C
#define USBD_EP4RD 0xB0200010
#define USBD_EP5RD 0xB0200014
#define USBD_INTEN 0xB0200018
#define USBD_INTSTAT 0xB020001C
#define USBDEV_INT_SOF (1<<12)
#define USBDEV_INT_HF_BIT 6
#define USBDEV_INT_HF_MASK (0x3f << USBDEV_INT_HF_BIT)
#define USBDEV_INT_CMPLT_BIT 0
#define USBDEV_INT_CMPLT_MASK (0x3f << USBDEV_INT_CMPLT_BIT)
#define USBD_CONFIG 0xB0200020
#define USBD_EP0CS 0xB0200024
#define USBD_EP2CS 0xB0200028
#define USBD_EP3CS 0xB020002C
#define USBD_EP4CS 0xB0200030
#define USBD_EP5CS 0xB0200034
#define USBDEV_CS_SU (1<<14)
#define USBDEV_CS_NAK (1<<13)
#define USBDEV_CS_ACK (1<<12)
#define USBDEV_CS_BUSY (1<<11)
#define USBDEV_CS_TSIZE_BIT 1
#define USBDEV_CS_TSIZE_MASK (0x3ff << USBDEV_CS_TSIZE_BIT)
#define USBDEV_CS_STALL (1<<0)
#define USBD_EP0RDSTAT 0xB0200040
#define USBD_EP0WRSTAT 0xB0200044
#define USBD_EP2WRSTAT 0xB0200048
#define USBD_EP3WRSTAT 0xB020004C
#define USBD_EP4RDSTAT 0xB0200050
#define USBD_EP5RDSTAT 0xB0200054
#define USBDEV_FSTAT_FLUSH (1<<6)
#define USBDEV_FSTAT_UF (1<<5)
#define USBDEV_FSTAT_OF (1<<4)
#define USBDEV_FSTAT_FCNT_BIT 0
#define USBDEV_FSTAT_FCNT_MASK (0x0f << USBDEV_FSTAT_FCNT_BIT)
#define USBD_ENABLE 0xB0200058
#define USBDEV_ENABLE (1<<1)
#define USBDEV_CE (1<<0)

#define MAC_CONTROL 0x0
#define MAC_RX_ENABLE (1<<2)
#define MAC_TX_ENABLE (1<<3)
#define MAC_DEF_CHECK (1<<5)
#define MAC_SET_BL(X) (((X)&0x3)<<6)
#define MAC_AUTO_PAD (1<<8)
#define MAC_DISABLE_RETRY (1<<10)
#define MAC_DISABLE_BCAST (1<<11)
#define MAC_LATE_COL (1<<12)
#define MAC_HASH_MODE (1<<13)
#define MAC_HASH_ONLY (1<<15)
#define MAC_PASS_ALL (1<<16)
#define MAC_INVERSE_FILTER (1<<17)
#define MAC_PROMISCUOUS (1<<18)
#define MAC_PASS_ALL_MULTI (1<<19)
#define MAC_FULL_DUPLEX (1<<20)
#define MAC_NORMAL_MODE 0
#define MAC_INT_LOOPBACK (1<<21)
#define MAC_EXT_LOOPBACK (1<<22)
#define MAC_DISABLE_RX_OWN (1<<23)
#define MAC_BIG_ENDIAN (1<<30)
#define MAC_RX_ALL (1<<31)
#define MAC_ADDRESS_HIGH 0x4
#define MAC_ADDRESS_LOW 0x8
#define MAC_MCAST_HIGH 0xC
#define MAC_MCAST_LOW 0x10
#define MAC_MII_CNTRL 0x14
#define MAC_MII_BUSY (1<<0)
#define MAC_MII_READ 0
#define MAC_MII_WRITE (1<<1)
#define MAC_SET_MII_SELECT_REG(X) (((X)&0x1f)<<6)
#define MAC_SET_MII_SELECT_PHY(X) (((X)&0x1f)<<11)
#define MAC_MII_DATA 0x18
#define MAC_FLOW_CNTRL 0x1C
#define MAC_FLOW_CNTRL_BUSY (1<<0)
#define MAC_FLOW_CNTRL_ENABLE (1<<1)
#define MAC_PASS_CONTROL (1<<2)
#define MAC_SET_PAUSE(X) (((X)&0xffff)<<16)
#define MAC_VLAN1_TAG 0x20
#define MAC_VLAN2_TAG 0x24

#define MAC_EN_CLOCK_ENABLE (1<<0)
#define MAC_EN_RESET0 (1<<1)
#define MAC_EN_TOSS (0<<2)
#define MAC_EN_CACHEABLE (1<<3)
#define MAC_EN_RESET1 (1<<4)
#define MAC_EN_RESET2 (1<<5)
#define MAC_DMA_RESET (1<<6)

#define MAC0_TX_DMA_ADDR 0xB4004000
#define MAC1_TX_DMA_ADDR 0xB4004200

#define MAC_TX_BUFF0_STATUS 0x0
#define TX_FRAME_ABORTED (1<<0)
#define TX_JAB_TIMEOUT (1<<1)
#define TX_NO_CARRIER (1<<2)
#define TX_LOSS_CARRIER (1<<3)
#define TX_EXC_DEF (1<<4)
#define TX_LATE_COLL_ABORT (1<<5)
#define TX_EXC_COLL (1<<6)
#define TX_UNDERRUN (1<<7)
#define TX_DEFERRED (1<<8)
#define TX_LATE_COLL (1<<9)
#define TX_COLL_CNT_MASK (0xF<<10)
#define TX_PKT_RETRY (1<<31)
#define MAC_TX_BUFF0_ADDR 0x4
#define TX_DMA_ENABLE (1<<0)
#define TX_T_DONE (1<<1)
#define TX_GET_DMA_BUFFER(X) (((X)>>2)&0x3)
#define MAC_TX_BUFF0_LEN 0x8
#define MAC_TX_BUFF1_STATUS 0x10
#define MAC_TX_BUFF1_ADDR 0x14
#define MAC_TX_BUFF1_LEN 0x18
#define MAC_TX_BUFF2_STATUS 0x20
#define MAC_TX_BUFF2_ADDR 0x24
#define MAC_TX_BUFF2_LEN 0x28
#define MAC_TX_BUFF3_STATUS 0x30
#define MAC_TX_BUFF3_ADDR 0x34
#define MAC_TX_BUFF3_LEN 0x38

#define MAC0_RX_DMA_ADDR 0xB4004100
#define MAC1_RX_DMA_ADDR 0xB4004300

#define MAC_RX_BUFF0_STATUS 0x0
#define RX_FRAME_LEN_MASK 0x3fff
#define RX_WDOG_TIMER (1<<14)
#define RX_RUNT (1<<15)
#define RX_OVERLEN (1<<16)
#define RX_COLL (1<<17)
#define RX_ETHER (1<<18)
#define RX_MII_ERROR (1<<19)
#define RX_DRIBBLING (1<<20)
#define RX_CRC_ERROR (1<<21)
#define RX_VLAN1 (1<<22)
#define RX_VLAN2 (1<<23)
#define RX_LEN_ERROR (1<<24)
#define RX_CNTRL_FRAME (1<<25)
#define RX_U_CNTRL_FRAME (1<<26)
#define RX_MCAST_FRAME (1<<27)
#define RX_BCAST_FRAME (1<<28)
#define RX_FILTER_FAIL (1<<29)
#define RX_PACKET_FILTER (1<<30)
#define RX_MISSED_FRAME (1<<31)

#define RX_ERROR (RX_WDOG_TIMER | RX_RUNT | RX_OVERLEN |   RX_COLL | RX_MII_ERROR | RX_CRC_ERROR |   RX_LEN_ERROR | RX_U_CNTRL_FRAME | RX_MISSED_FRAME)
#define MAC_RX_BUFF0_ADDR 0x4
#define RX_DMA_ENABLE (1<<0)
#define RX_T_DONE (1<<1)
#define RX_GET_DMA_BUFFER(X) (((X)>>2)&0x3)
#define RX_SET_BUFF_ADDR(X) ((X)&0xffffffc0)
#define MAC_RX_BUFF1_STATUS 0x10
#define MAC_RX_BUFF1_ADDR 0x14
#define MAC_RX_BUFF2_STATUS 0x20
#define MAC_RX_BUFF2_ADDR 0x24
#define MAC_RX_BUFF3_STATUS 0x30
#define MAC_RX_BUFF3_ADDR 0x34

#define UART_BASE UART0_ADDR
#define UART_DEBUG_BASE UART3_ADDR

#define UART_RX 0  
#define UART_TX 4  
#define UART_IER 8  
#define UART_IIR 0xC  
#define UART_FCR 0x10  
#define UART_LCR 0x14  
#define UART_MCR 0x18  
#define UART_LSR 0x1C  
#define UART_MSR 0x20  
#define UART_CLK 0x28  
#define UART_MOD_CNTRL 0x100  

#define UART_FCR_ENABLE_FIFO 0x01  
#define UART_FCR_CLEAR_RCVR 0x02  
#define UART_FCR_CLEAR_XMIT 0x04  
#define UART_FCR_DMA_SELECT 0x08  
#define UART_FCR_TRIGGER_MASK 0xF0  
#define UART_FCR_R_TRIGGER_1 0x00  
#define UART_FCR_R_TRIGGER_4 0x40  
#define UART_FCR_R_TRIGGER_8 0x80  
#define UART_FCR_R_TRIGGER_14 0xA0  
#define UART_FCR_T_TRIGGER_0 0x00  
#define UART_FCR_T_TRIGGER_4 0x10  
#define UART_FCR_T_TRIGGER_8 0x20  
#define UART_FCR_T_TRIGGER_12 0x30  

#define UART_LCR_SBC 0x40  
#define UART_LCR_SPAR 0x20  
#define UART_LCR_EPAR 0x10  
#define UART_LCR_PARITY 0x08  
#define UART_LCR_STOP 0x04  
#define UART_LCR_WLEN5 0x00  
#define UART_LCR_WLEN6 0x01  
#define UART_LCR_WLEN7 0x02  
#define UART_LCR_WLEN8 0x03  

#define UART_LSR_TEMT 0x40  
#define UART_LSR_THRE 0x20  
#define UART_LSR_BI 0x10  
#define UART_LSR_FE 0x08  
#define UART_LSR_PE 0x04  
#define UART_LSR_OE 0x02  
#define UART_LSR_DR 0x01  

#define UART_IIR_NO_INT 0x01  
#define UART_IIR_ID 0x06  
#define UART_IIR_MSI 0x00  
#define UART_IIR_THRI 0x02  
#define UART_IIR_RDI 0x04  
#define UART_IIR_RLSI 0x06  

#define UART_IER_MSI 0x08  
#define UART_IER_RLSI 0x04  
#define UART_IER_THRI 0x02  
#define UART_IER_RDI 0x01  

#define UART_MCR_LOOP 0x10  
#define UART_MCR_OUT2 0x08  
#define UART_MCR_OUT1 0x04  
#define UART_MCR_RTS 0x02  
#define UART_MCR_DTR 0x01  

#define UART_MSR_DCD 0x80  
#define UART_MSR_RI 0x40  
#define UART_MSR_DSR 0x20  
#define UART_MSR_CTS 0x10  
#define UART_MSR_DDCD 0x08  
#define UART_MSR_TERI 0x04  
#define UART_MSR_DDSR 0x02  
#define UART_MSR_DCTS 0x01  
#define UART_MSR_ANY_DELTA 0x0F  

#define SSI0_STATUS 0xB1600000
#define SSI_STATUS_BF (1<<4)
#define SSI_STATUS_OF (1<<3)
#define SSI_STATUS_UF (1<<2)
#define SSI_STATUS_D (1<<1)
#define SSI_STATUS_B (1<<0)
#define SSI0_INT 0xB1600004
#define SSI_INT_OI (1<<3)
#define SSI_INT_UI (1<<2)
#define SSI_INT_DI (1<<1)
#define SSI0_INT_ENABLE 0xB1600008
#define SSI_INTE_OIE (1<<3)
#define SSI_INTE_UIE (1<<2)
#define SSI_INTE_DIE (1<<1)
#define SSI0_CONFIG 0xB1600020
#define SSI_CONFIG_AO (1<<24)
#define SSI_CONFIG_DO (1<<23)
#define SSI_CONFIG_ALEN_BIT 20
#define SSI_CONFIG_ALEN_MASK (0x7<<20)
#define SSI_CONFIG_DLEN_BIT 16
#define SSI_CONFIG_DLEN_MASK (0x7<<16)
#define SSI_CONFIG_DD (1<<11)
#define SSI_CONFIG_AD (1<<10)
#define SSI_CONFIG_BM_BIT 8
#define SSI_CONFIG_BM_MASK (0x3<<8)
#define SSI_CONFIG_CE (1<<7)
#define SSI_CONFIG_DP (1<<6)
#define SSI_CONFIG_DL (1<<5)
#define SSI_CONFIG_EP (1<<4)
#define SSI0_ADATA 0xB1600024
#define SSI_AD_D (1<<24)
#define SSI_AD_ADDR_BIT 16
#define SSI_AD_ADDR_MASK (0xff<<16)
#define SSI_AD_DATA_BIT 0
#define SSI_AD_DATA_MASK (0xfff<<0)
#define SSI0_CLKDIV 0xB1600028
#define SSI0_CONTROL 0xB1600100
#define SSI_CONTROL_CD (1<<1)
#define SSI_CONTROL_E (1<<0)

#define SSI1_STATUS 0xB1680000
#define SSI1_INT 0xB1680004
#define SSI1_INT_ENABLE 0xB1680008
#define SSI1_CONFIG 0xB1680020
#define SSI1_ADATA 0xB1680024
#define SSI1_CLKDIV 0xB1680028
#define SSI1_ENABLE 0xB1680100

#define SSI_STATUS_BF (1<<4)
#define SSI_STATUS_OF (1<<3)
#define SSI_STATUS_UF (1<<2)
#define SSI_STATUS_D (1<<1)
#define SSI_STATUS_B (1<<0)

#define SSI_INT_OI (1<<3)
#define SSI_INT_UI (1<<2)
#define SSI_INT_DI (1<<1)

#define SSI_INTEN_OIE (1<<3)
#define SSI_INTEN_UIE (1<<2)
#define SSI_INTEN_DIE (1<<1)

#define SSI_CONFIG_AO (1<<24)
#define SSI_CONFIG_DO (1<<23)
#define SSI_CONFIG_ALEN (7<<20)
#define SSI_CONFIG_DLEN (15<<16)
#define SSI_CONFIG_DD (1<<11)
#define SSI_CONFIG_AD (1<<10)
#define SSI_CONFIG_BM (3<<8)
#define SSI_CONFIG_CE (1<<7)
#define SSI_CONFIG_DP (1<<6)
#define SSI_CONFIG_DL (1<<5)
#define SSI_CONFIG_EP (1<<4)
#define SSI_CONFIG_ALEN_N(N) ((N-1)<<20)
#define SSI_CONFIG_DLEN_N(N) ((N-1)<<16)
#define SSI_CONFIG_BM_HI (0<<8)
#define SSI_CONFIG_BM_LO (1<<8)
#define SSI_CONFIG_BM_CY (2<<8)

#define SSI_ADATA_D (1<<24)
#define SSI_ADATA_ADDR (0xFF<<16)
#define SSI_ADATA_DATA (0x0FFF)
#define SSI_ADATA_ADDR_N(N) (N<<16)

#define SSI_ENABLE_CD (1<<1)
#define SSI_ENABLE_E (1<<0)

#define IRDA_BASE 0xB0300000
#define IR_RING_PTR_STATUS (IRDA_BASE+0x00)
#define IR_RING_BASE_ADDR_H (IRDA_BASE+0x04)
#define IR_RING_BASE_ADDR_L (IRDA_BASE+0x08)
#define IR_RING_SIZE (IRDA_BASE+0x0C)
#define IR_RING_PROMPT (IRDA_BASE+0x10)
#define IR_RING_ADDR_CMPR (IRDA_BASE+0x14)
#define IR_INT_CLEAR (IRDA_BASE+0x18)
#define IR_CONFIG_1 (IRDA_BASE+0x20)
#define IR_RX_INVERT_LED (1<<0)
#define IR_TX_INVERT_LED (1<<1)
#define IR_ST (1<<2)
#define IR_SF (1<<3)
#define IR_SIR (1<<4)
#define IR_MIR (1<<5)
#define IR_FIR (1<<6)
#define IR_16CRC (1<<7)
#define IR_TD (1<<8)
#define IR_RX_ALL (1<<9)
#define IR_DMA_ENABLE (1<<10)
#define IR_RX_ENABLE (1<<11)
#define IR_TX_ENABLE (1<<12)
#define IR_LOOPBACK (1<<14)
#define IR_SIR_MODE (IR_SIR | IR_DMA_ENABLE |   IR_RX_ALL | IR_RX_ENABLE | IR_SF | IR_16CRC)
#define IR_SIR_FLAGS (IRDA_BASE+0x24)
#define IR_ENABLE (IRDA_BASE+0x28)
#define IR_RX_STATUS (1<<9)
#define IR_TX_STATUS (1<<10)
#define IR_READ_PHY_CONFIG (IRDA_BASE+0x2C)
#define IR_WRITE_PHY_CONFIG (IRDA_BASE+0x30)
#define IR_MAX_PKT_LEN (IRDA_BASE+0x34)
#define IR_RX_BYTE_CNT (IRDA_BASE+0x38)
#define IR_CONFIG_2 (IRDA_BASE+0x3C)
#define IR_MODE_INV (1<<0)
#define IR_ONE_PIN (1<<1)
#define IR_INTERFACE_CONFIG (IRDA_BASE+0x40)

#define SYS_PINFUNC 0xB190002C
#define SYS_PF_USB (1<<15)  
#define SYS_PF_U3 (1<<14)  
#define SYS_PF_U2 (1<<13)  
#define SYS_PF_U1 (1<<12)  
#define SYS_PF_SRC (1<<11)  
#define SYS_PF_CK5 (1<<10)  
#define SYS_PF_CK4 (1<<9)  
#define SYS_PF_IRF (1<<8)  
#define SYS_PF_UR3 (1<<7)  
#define SYS_PF_I2D (1<<6)  
#define SYS_PF_I2S (1<<5)  
#define SYS_PF_NI2 (1<<4)  
#define SYS_PF_U0 (1<<3)  
#define SYS_PF_RD (1<<2)  
#define SYS_PF_A97 (1<<1)  
#define SYS_PF_S0 (1<<0)  

#define SYS_PF_PC (1<<18)  
#define SYS_PF_LCD (1<<17)  
#define SYS_PF_CS (1<<16)  
#define SYS_PF_EX0 (1<<9)  

#define SYS_PF_PSC2_MASK (7 << 17)
#define SYS_PF_PSC2_AC97 (0)
#define SYS_PF_PSC2_SPI (0)
#define SYS_PF_PSC2_I2S (1 << 17)
#define SYS_PF_PSC2_SMBUS (3 << 17)
#define SYS_PF_PSC2_GPIO (7 << 17)
#define SYS_PF_PSC3_MASK (7 << 20)
#define SYS_PF_PSC3_AC97 (0)
#define SYS_PF_PSC3_SPI (0)
#define SYS_PF_PSC3_I2S (1 << 20)
#define SYS_PF_PSC3_SMBUS (3 << 20)
#define SYS_PF_PSC3_GPIO (7 << 20)
#define SYS_PF_PSC1_S1 (1 << 1)
#define SYS_PF_MUST_BE_SET ((1 << 5) | (1 << 2))

#define SYS_TRIOUTRD 0xB1900100
#define SYS_TRIOUTCLR 0xB1900100
#define SYS_OUTPUTRD 0xB1900108
#define SYS_OUTPUTSET 0xB1900108
#define SYS_OUTPUTCLR 0xB190010C
#define SYS_PINSTATERD 0xB1900110
#define SYS_PININPUTEN 0xB1900110

#define GPIO2_BASE 0xB1700000
#define GPIO2_DIR (GPIO2_BASE + 0)
#define GPIO2_OUTPUT (GPIO2_BASE + 8)
#define GPIO2_PINSTATE (GPIO2_BASE + 0xC)
#define GPIO2_INTENABLE (GPIO2_BASE + 0x10)
#define GPIO2_ENABLE (GPIO2_BASE + 0x14)

#define SYS_SCRATCH0 0xB1900018
#define SYS_SCRATCH1 0xB190001C
#define SYS_WAKEMSK 0xB1900034
#define SYS_ENDIAN 0xB1900038
#define SYS_POWERCTRL 0xB190003C
#define SYS_WAKESRC 0xB190005C
#define SYS_SLPPWR 0xB1900078
#define SYS_SLEEP 0xB190007C

#define SYS_FREQCTRL0 0xB1900020
#define SYS_FC_FRDIV2_BIT 22
#define SYS_FC_FRDIV2_MASK (0xff << SYS_FC_FRDIV2_BIT)
#define SYS_FC_FE2 (1<<21)
#define SYS_FC_FS2 (1<<20)
#define SYS_FC_FRDIV1_BIT 12
#define SYS_FC_FRDIV1_MASK (0xff << SYS_FC_FRDIV1_BIT)
#define SYS_FC_FE1 (1<<11)
#define SYS_FC_FS1 (1<<10)
#define SYS_FC_FRDIV0_BIT 2
#define SYS_FC_FRDIV0_MASK (0xff << SYS_FC_FRDIV0_BIT)
#define SYS_FC_FE0 (1<<1)
#define SYS_FC_FS0 (1<<0)
#define SYS_FREQCTRL1 0xB1900024
#define SYS_FC_FRDIV5_BIT 22
#define SYS_FC_FRDIV5_MASK (0xff << SYS_FC_FRDIV5_BIT)
#define SYS_FC_FE5 (1<<21)
#define SYS_FC_FS5 (1<<20)
#define SYS_FC_FRDIV4_BIT 12
#define SYS_FC_FRDIV4_MASK (0xff << SYS_FC_FRDIV4_BIT)
#define SYS_FC_FE4 (1<<11)
#define SYS_FC_FS4 (1<<10)
#define SYS_FC_FRDIV3_BIT 2
#define SYS_FC_FRDIV3_MASK (0xff << SYS_FC_FRDIV3_BIT)
#define SYS_FC_FE3 (1<<1)
#define SYS_FC_FS3 (1<<0)
#define SYS_CLKSRC 0xB1900028
#define SYS_CS_ME1_BIT 27
#define SYS_CS_ME1_MASK (0x7<<SYS_CS_ME1_BIT)
#define SYS_CS_DE1 (1<<26)
#define SYS_CS_CE1 (1<<25)
#define SYS_CS_ME0_BIT 22
#define SYS_CS_ME0_MASK (0x7<<SYS_CS_ME0_BIT)
#define SYS_CS_DE0 (1<<21)
#define SYS_CS_CE0 (1<<20)
#define SYS_CS_MI2_BIT 17
#define SYS_CS_MI2_MASK (0x7<<SYS_CS_MI2_BIT)
#define SYS_CS_DI2 (1<<16)
#define SYS_CS_CI2 (1<<15)
#define SYS_CS_MUH_BIT 12
#define SYS_CS_MUH_MASK (0x7<<SYS_CS_MUH_BIT)
#define SYS_CS_DUH (1<<11)
#define SYS_CS_CUH (1<<10)
#define SYS_CS_MUD_BIT 7
#define SYS_CS_MUD_MASK (0x7<<SYS_CS_MUD_BIT)
#define SYS_CS_DUD (1<<6)
#define SYS_CS_CUD (1<<5)
#define SYS_CS_MIR_BIT 2
#define SYS_CS_MIR_MASK (0x7<<SYS_CS_MIR_BIT)
#define SYS_CS_DIR (1<<1)
#define SYS_CS_CIR (1<<0)

#define SYS_CS_MUX_AUX 0x1
#define SYS_CS_MUX_FQ0 0x2
#define SYS_CS_MUX_FQ1 0x3
#define SYS_CS_MUX_FQ2 0x4
#define SYS_CS_MUX_FQ3 0x5
#define SYS_CS_MUX_FQ4 0x6
#define SYS_CS_MUX_FQ5 0x7
#define SYS_CPUPLL 0xB1900060
#define SYS_AUXPLL 0xB1900064

#define AC97C_CONFIG 0xB0000000
#define AC97C_RECV_SLOTS_BIT 13
#define AC97C_RECV_SLOTS_MASK (0x3ff << AC97C_RECV_SLOTS_BIT)
#define AC97C_XMIT_SLOTS_BIT 3
#define AC97C_XMIT_SLOTS_MASK (0x3ff << AC97C_XMIT_SLOTS_BIT)
#define AC97C_SG (1<<2)
#define AC97C_SYNC (1<<1)
#define AC97C_RESET (1<<0)
#define AC97C_STATUS 0xB0000004
#define AC97C_XU (1<<11)
#define AC97C_XO (1<<10)
#define AC97C_RU (1<<9)
#define AC97C_RO (1<<8)
#define AC97C_READY (1<<7)
#define AC97C_CP (1<<6)
#define AC97C_TR (1<<5)
#define AC97C_TE (1<<4)
#define AC97C_TF (1<<3)
#define AC97C_RR (1<<2)
#define AC97C_RE (1<<1)
#define AC97C_RF (1<<0)
#define AC97C_DATA 0xB0000008
#define AC97C_CMD 0xB000000C
#define AC97C_WD_BIT 16
#define AC97C_READ (1<<7)
#define AC97C_INDEX_MASK 0x7f
#define AC97C_CNTRL 0xB0000010
#define AC97C_RS (1<<1)
#define AC97C_CE (1<<0)

#define SD0_XMIT_FIFO 0xB0600000
#define SD0_RECV_FIFO 0xB0600004
#define SD1_XMIT_FIFO 0xB0680000
#define SD1_RECV_FIFO 0xB0680004

#define IOPORT_RESOURCE_START 0x10000000
#define IOPORT_RESOURCE_END 0xffffffff
#define IOMEM_RESOURCE_START 0x10000000
#define IOMEM_RESOURCE_END 0xffffffff

#define PCI_IO_START 0
#define PCI_IO_END 0
#define PCI_MEM_START 0
#define PCI_MEM_END 0
#define PCI_FIRST_DEVFN 0
#define PCI_LAST_DEVFN 0

#ifndef _LANGUAGE_ASSEMBLY
typedef volatile struct
{
   u32 toytrim;
   u32 toywrite;
   u32 toymatch0;
   u32 toymatch1;
   u32 toymatch2;
   u32 cntrctrl;
   u32 scratch0;
   u32 scratch1;
   u32 freqctrl0;
   u32 freqctrl1;
   u32 clksrc;
   u32 pinfunc;
   u32 reserved0;
   u32 wakemsk;
   u32 endian;
   u32 powerctrl;
   u32 toyread;
   u32 rtctrim;
   u32 rtcwrite;
   u32 rtcmatch0;
   u32 rtcmatch1;
   u32 rtcmatch2;
   u32 rtcread;
   u32 wakesrc;
   u32 cpupll;
   u32 auxpll;
   u32 reserved1;
   u32 reserved2;
   u32 reserved3;
   u32 reserved4;
   u32 slppwr;
   u32 sleep;
   u32 reserved5[32];
   u32 trioutrd;
#define trioutclr trioutrd
   u32 reserved6;
   u32 outputrd;
#define outputset outputrd
   u32 outputclr;
   u32 pinstaterd;
#define pininputen pinstaterd

} AU1X00_SYS;

#endif

#ifndef _LANGUAGE_ASSEMBLY
struct cpu_spec {

 unsigned int prid_mask;
 unsigned int prid_value;

 char *cpu_name;
 unsigned char cpu_od;
 unsigned char cpu_bclk;
 unsigned char cpu_pll_wo;
};

#endif

#endif

