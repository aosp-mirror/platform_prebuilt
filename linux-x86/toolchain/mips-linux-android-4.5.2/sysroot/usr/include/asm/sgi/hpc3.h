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
#ifndef _SGI_HPC3_H
#define _SGI_HPC3_H

#include <linux/types.h>
#include <asm/page.h>

struct hpc_dma_desc {
 u32 pbuf;
 u32 cntinfo;
#define HPCDMA_EOX 0x80000000  
#define HPCDMA_EOR 0x80000000  
#define HPCDMA_EOXP 0x40000000  
#define HPCDMA_EORP 0x40000000  
#define HPCDMA_XIE 0x20000000  
#define HPCDMA_XIU 0x01000000  
#define HPCDMA_EIPC 0x00ff0000  
#define HPCDMA_ETXD 0x00008000  
#define HPCDMA_OWN 0x00004000  
#define HPCDMA_BCNT 0x00003fff  

 u32 pnext;
};

struct hpc3_pbus_dmacregs {
 volatile u32 pbdma_bptr;
 volatile u32 pbdma_dptr;
 u32 _unused0[0x1000/4 - 2];
 volatile u32 pbdma_ctrl;

#define HPC3_PDMACTRL_INT 0x00000001  
#define HPC3_PDMACTRL_ISACT 0x00000002  

#define HPC3_PDMACTRL_SEL 0x00000002  
#define HPC3_PDMACTRL_RCV 0x00000004  
#define HPC3_PDMACTRL_FLSH 0x00000008  
#define HPC3_PDMACTRL_ACT 0x00000010  
#define HPC3_PDMACTRL_LD 0x00000020  
#define HPC3_PDMACTRL_RT 0x00000040  
#define HPC3_PDMACTRL_HW 0x0000ff00  
#define HPC3_PDMACTRL_FB 0x003f0000  
#define HPC3_PDMACTRL_FE 0x3f000000  

 u32 _unused1[0x1000/4 - 1];
};

struct hpc3_scsiregs {
 volatile u32 cbptr;
 volatile u32 ndptr;
 u32 _unused0[0x1000/4 - 2];
 volatile u32 bcd;
#define HPC3_SBCD_BCNTMSK 0x00003fff  
#define HPC3_SBCD_XIE 0x00004000  
#define HPC3_SBCD_EOX 0x00008000  

 volatile u32 ctrl;
#define HPC3_SCTRL_IRQ 0x01  
#define HPC3_SCTRL_ENDIAN 0x02  
#define HPC3_SCTRL_DIR 0x04  
#define HPC3_SCTRL_FLUSH 0x08  
#define HPC3_SCTRL_ACTIVE 0x10  
#define HPC3_SCTRL_AMASK 0x20  
#define HPC3_SCTRL_CRESET 0x40  
#define HPC3_SCTRL_PERR 0x80  

 volatile u32 gfptr;
 volatile u32 dfptr;
 volatile u32 dconfig;
#define HPC3_SDCFG_HCLK 0x00001  
#define HPC3_SDCFG_D1 0x00006  
#define HPC3_SDCFG_D2 0x00038  
#define HPC3_SDCFG_D3 0x001c0  
#define HPC3_SDCFG_HWAT 0x00e00  
#define HPC3_SDCFG_HW 0x01000  
#define HPC3_SDCFG_SWAP 0x02000  
#define HPC3_SDCFG_EPAR 0x04000  
#define HPC3_SDCFG_POLL 0x08000  
#define HPC3_SDCFG_ERLY 0x30000  

 volatile u32 pconfig;
#define HPC3_SPCFG_P3 0x0003  
#define HPC3_SPCFG_P2W 0x001c  
#define HPC3_SPCFG_P2R 0x01e0  
#define HPC3_SPCFG_P1 0x0e00  
#define HPC3_SPCFG_HW 0x1000  
#define HPC3_SPCFG_SWAP 0x2000  
#define HPC3_SPCFG_EPAR 0x4000  
#define HPC3_SPCFG_FUJI 0x8000  

 u32 _unused1[0x1000/4 - 6];
};

struct hpc3_ethregs {

 volatile u32 rx_cbptr;
 volatile u32 rx_ndptr;
 u32 _unused0[0x1000/4 - 2];
 volatile u32 rx_bcd;
#define HPC3_ERXBCD_BCNTMSK 0x00003fff  
#define HPC3_ERXBCD_XIE 0x20000000  
#define HPC3_ERXBCD_EOX 0x80000000  

 volatile u32 rx_ctrl;
#define HPC3_ERXCTRL_STAT50 0x0000003f  
#define HPC3_ERXCTRL_STAT6 0x00000040  
#define HPC3_ERXCTRL_STAT7 0x00000080  
#define HPC3_ERXCTRL_ENDIAN 0x00000100  
#define HPC3_ERXCTRL_ACTIVE 0x00000200  
#define HPC3_ERXCTRL_AMASK 0x00000400  
#define HPC3_ERXCTRL_RBO 0x00000800  

 volatile u32 rx_gfptr;
 volatile u32 rx_dfptr;
 u32 _unused1;
 volatile u32 reset;
#define HPC3_ERST_CRESET 0x1  
#define HPC3_ERST_CLRIRQ 0x2  
#define HPC3_ERST_LBACK 0x4  

 volatile u32 dconfig;
#define HPC3_EDCFG_D1 0x0000f  
#define HPC3_EDCFG_D2 0x000f0  
#define HPC3_EDCFG_D3 0x00f00  
#define HPC3_EDCFG_WCTRL 0x01000  
#define HPC3_EDCFG_FRXDC 0x02000  
#define HPC3_EDCFG_FEOP 0x04000  
#define HPC3_EDCFG_FIRQ 0x08000  
#define HPC3_EDCFG_PTO 0x30000  

 volatile u32 pconfig;
#define HPC3_EPCFG_P1 0x000f  
#define HPC3_EPCFG_P2 0x00f0  
#define HPC3_EPCFG_P3 0x0f00  
#define HPC3_EPCFG_TST 0x1000  

 u32 _unused2[0x1000/4 - 8];

 volatile u32 tx_cbptr;
 volatile u32 tx_ndptr;
 u32 _unused3[0x1000/4 - 2];
 volatile u32 tx_bcd;
#define HPC3_ETXBCD_BCNTMSK 0x00003fff  
#define HPC3_ETXBCD_ESAMP 0x10000000  
#define HPC3_ETXBCD_XIE 0x20000000  
#define HPC3_ETXBCD_EOP 0x40000000  
#define HPC3_ETXBCD_EOX 0x80000000  

 volatile u32 tx_ctrl;
#define HPC3_ETXCTRL_STAT30 0x0000000f  
#define HPC3_ETXCTRL_STAT4 0x00000010  
#define HPC3_ETXCTRL_STAT75 0x000000e0  
#define HPC3_ETXCTRL_ENDIAN 0x00000100  
#define HPC3_ETXCTRL_ACTIVE 0x00000200  
#define HPC3_ETXCTRL_AMASK 0x00000400  

 volatile u32 tx_gfptr;
 volatile u32 tx_dfptr;
 u32 _unused4[0x1000/4 - 4];
};

struct hpc3_regs {

 struct hpc3_pbus_dmacregs pbdma[8];

 struct hpc3_scsiregs scsi_chan0, scsi_chan1;

 struct hpc3_ethregs ethregs;

 u32 _unused0[0x18000/4];

 volatile u32 istat0;
#define HPC3_ISTAT_PBIMASK 0x0ff  
#define HPC3_ISTAT_SC0MASK 0x100  
#define HPC3_ISTAT_SC1MASK 0x200  

 volatile u32 gio_misc;
#define HPC3_GIOMISC_ERTIME 0x1  
#define HPC3_GIOMISC_DENDIAN 0x2  

 u32 eeprom;
#define HPC3_EEPROM_EPROT 0x01  
#define HPC3_EEPROM_CSEL 0x02  
#define HPC3_EEPROM_ECLK 0x04  
#define HPC3_EEPROM_DATO 0x08  
#define HPC3_EEPROM_DATI 0x10  

 volatile u32 istat1;
 volatile u32 bestat;
#define HPC3_BESTAT_BLMASK 0x000ff  
#define HPC3_BESTAT_CTYPE 0x00100  
#define HPC3_BESTAT_PIDSHIFT 9
#define HPC3_BESTAT_PIDMASK 0x3f700  

 u32 _unused1[0x14000/4 - 5];

 volatile u32 scsi0_ext[256];
 u32 _unused2[0x7c00/4];
 volatile u32 scsi1_ext[256];
 u32 _unused3[0x7c00/4];
 volatile u32 eth_ext[320];
 u32 _unused4[0x3b00/4];

 volatile u32 pbus_extregs[16][256];
 volatile u32 pbus_dmacfg[8][128];

#define HPC3_DMACFG_D3R_MASK 0x00000001
#define HPC3_DMACFG_D3R_SHIFT 0

#define HPC3_DMACFG_D4R_MASK 0x0000001e
#define HPC3_DMACFG_D4R_SHIFT 1

#define HPC3_DMACFG_D5R_MASK 0x000001e0
#define HPC3_DMACFG_D5R_SHIFT 5

#define HPC3_DMACFG_D3W_MASK 0x00000200
#define HPC3_DMACFG_D3W_SHIFT 9

#define HPC3_DMACFG_D4W_MASK 0x00003c00
#define HPC3_DMACFG_D4W_SHIFT 10

#define HPC3_DMACFG_D5W_MASK 0x0003c000
#define HPC3_DMACFG_D5W_SHIFT 14

#define HPC3_DMACFG_DS16 0x00040000

#define HPC3_DMACFG_EVENHI 0x00080000

#define HPC3_DMACFG_RTIME 0x00200000

#define HPC3_DMACFG_BURST_MASK 0x07c00000
#define HPC3_DMACFG_BURST_SHIFT 22

#define HPC3_DMACFG_DRQLIVE 0x08000000
 volatile u32 pbus_piocfg[16][64];

#define HPC3_PIOCFG_P2R_MASK 0x00001
#define HPC3_PIOCFG_P2R_SHIFT 0

#define HPC3_PIOCFG_P3R_MASK 0x0001e
#define HPC3_PIOCFG_P3R_SHIFT 1

#define HPC3_PIOCFG_P4R_MASK 0x001e0
#define HPC3_PIOCFG_P4R_SHIFT 5

#define HPC3_PIOCFG_P2W_MASK 0x00200
#define HPC3_PIOCFG_P2W_SHIFT 9

#define HPC3_PIOCFG_P3W_MASK 0x03c00
#define HPC3_PIOCFG_P3W_SHIFT 10

#define HPC3_PIOCFG_P4W_MASK 0x3c000
#define HPC3_PIOCFG_P4W_SHIFT 14

#define HPC3_PIOCFG_DS16 0x40000

#define HPC3_PIOCFG_EVENHI 0x80000

 volatile u32 pbus_promwe;
#define HPC3_PROM_WENAB 0x1  

 u32 _unused5[0x0800/4 - 1];
 volatile u32 pbus_promswap;
#define HPC3_PROM_SWAP 0x1  

 u32 _unused6[0x0800/4 - 1];
 volatile u32 pbus_gout;
#define HPC3_PROM_STAT 0x1  

 u32 _unused7[0x1000/4 - 1];
 volatile u32 rtcregs[14];
 u32 _unused8[50];
 volatile u32 bbram[8192-50-14];
};

#define HPC3_CHIP0_BASE 0x1fb80000  
#define HPC3_CHIP1_BASE 0x1fb00000  

#endif
