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
#ifndef _ASM_SN_SN0_ADDRS_H
#define _ASM_SN_SN0_ADDRS_H

#define NODE_SIZE_BITS 32
#define BWIN_SIZE_BITS 29

#define NASID_BITMASK (0xffLL)
#define NASID_BITS 8
#define NASID_SHFT 32
#define NASID_META_BITS 4
#define NASID_LOCAL_BITS 4

#define BDDIR_UPPER_MASK (UINT64_CAST 0xfffff << 10)
#define BDECC_UPPER_MASK (UINT64_CAST 0x7ffffff << 3)

#define NODE_ADDRSPACE_SIZE (UINT64_CAST 1 << NODE_SIZE_BITS)

#define NASID_MASK (UINT64_CAST NASID_BITMASK << NASID_SHFT)
#define NASID_GET(_pa) (int) ((UINT64_CAST (_pa) >>   NASID_SHFT) & NASID_BITMASK)

#ifndef __ASSEMBLY__

#define NODE_SWIN_BASE(nasid, widget)   ((widget == 0) ? NODE_BWIN_BASE((nasid), SWIN0_BIGWIN)   : RAW_NODE_SWIN_BASE(nasid, widget))
#else
#define NODE_SWIN_BASE(nasid, widget)   (NODE_IO_BASE(nasid) + (UINT64_CAST(widget) << SWIN_SIZE_BITS))
#endif

#define BWIN_INDEX_BITS 3
#define BWIN_SIZE (UINT64_CAST 1 << BWIN_SIZE_BITS)
#define BWIN_SIZEMASK (BWIN_SIZE - 1)
#define BWIN_WIDGET_MASK 0x7
#define NODE_BWIN_BASE0(nasid) (NODE_IO_BASE(nasid) + BWIN_SIZE)
#define NODE_BWIN_BASE(nasid, bigwin) (NODE_BWIN_BASE0(nasid) +   (UINT64_CAST(bigwin) << BWIN_SIZE_BITS))

#define BWIN_WIDGETADDR(addr) ((addr) & BWIN_SIZEMASK)
#define BWIN_WINDOWNUM(addr) (((addr) >> BWIN_SIZE_BITS) & BWIN_WIDGET_MASK)

#define NODE_BWIN_ADDR(nasid, addr)   (((addr) >= NODE_BWIN_BASE0(nasid)) &&   ((addr) < (NODE_BWIN_BASE(nasid, HUB_NUM_BIG_WINDOW) +   BWIN_SIZE)))

#define CALIAS_BASE CAC_BASE

#define BRIDGE_REG_PTR(_base, _off) ((volatile bridgereg_t *)   ((__psunsigned_t)(_base) + (__psunsigned_t)(_off)))

#define SN0_WIDGET_BASE(_nasid, _wid) (NODE_SWIN_BASE((_nasid), (_wid)))

#define SABLE_LOG_TRIGGER(_map)

#ifndef __ASSEMBLY__
#define KERN_NMI_ADDR(nasid, slice)   TO_NODE_UNCAC((nasid), IP27_NMI_KREGS_OFFSET +   (IP27_NMI_KREGS_CPU_SIZE * (slice)))
#endif

#ifdef PROM

#define MISC_PROM_BASE PHYS_TO_K0(0x01300000)
#define MISC_PROM_SIZE 0x200000

#define DIAG_BASE PHYS_TO_K0(0x01500000)
#define DIAG_SIZE 0x300000

#define ROUTE_BASE PHYS_TO_K0(0x01800000)
#define ROUTE_SIZE 0x200000

#define IP27PROM_FLASH_HDR PHYS_TO_K0(0x01300000)
#define IP27PROM_FLASH_DATA PHYS_TO_K0(0x01301000)
#define IP27PROM_CORP_MAX 32
#define IP27PROM_CORP PHYS_TO_K0(0x01800000)
#define IP27PROM_CORP_SIZE 0x10000
#define IP27PROM_CORP_STK PHYS_TO_K0(0x01810000)
#define IP27PROM_CORP_STKSIZE 0x2000
#define IP27PROM_DECOMP_BUF PHYS_TO_K0(0x01900000)
#define IP27PROM_DECOMP_SIZE 0xfff00

#define IP27PROM_BASE PHYS_TO_K0(0x01a00000)
#define IP27PROM_BASE_MAPPED (UNCAC_BASE | 0x1fc00000)
#define IP27PROM_SIZE_MAX 0x100000

#define IP27PROM_PCFG PHYS_TO_K0(0x01b00000)
#define IP27PROM_PCFG_SIZE 0xd0000
#define IP27PROM_ERRDMP PHYS_TO_K1(0x01bd0000)
#define IP27PROM_ERRDMP_SIZE 0xf000

#define IP27PROM_INIT_START PHYS_TO_K1(0x01bd0000)
#define IP27PROM_CONSOLE PHYS_TO_K1(0x01bdf000)
#define IP27PROM_CONSOLE_SIZE 0x200
#define IP27PROM_NETUART PHYS_TO_K1(0x01bdf200)
#define IP27PROM_NETUART_SIZE 0x100
#define IP27PROM_UNUSED1 PHYS_TO_K1(0x01bdf300)
#define IP27PROM_UNUSED1_SIZE 0x500
#define IP27PROM_ELSC_BASE_A PHYS_TO_K0(0x01bdf800)
#define IP27PROM_ELSC_BASE_B PHYS_TO_K0(0x01bdfc00)
#define IP27PROM_STACK_A PHYS_TO_K0(0x01be0000)
#define IP27PROM_STACK_B PHYS_TO_K0(0x01bf0000)
#define IP27PROM_STACK_SHFT 16
#define IP27PROM_STACK_SIZE (1 << IP27PROM_STACK_SHFT)
#define IP27PROM_INIT_END PHYS_TO_K0(0x01c00000)

#define SLAVESTACK_BASE PHYS_TO_K0(0x01580000)
#define SLAVESTACK_SIZE 0x40000

#define ENETBUFS_BASE PHYS_TO_K0(0x01f80000)
#define ENETBUFS_SIZE 0x20000

#define IO6PROM_BASE PHYS_TO_K0(0x01c00000)
#define IO6PROM_SIZE 0x400000
#define IO6PROM_BASE_MAPPED (UNCAC_BASE | 0x11c00000)
#define IO6DPROM_BASE PHYS_TO_K0(0x01c00000)
#define IO6DPROM_SIZE 0x200000

#define NODEBUGUNIX_ADDR PHYS_TO_K0(0x00019000)
#define DEBUGUNIX_ADDR PHYS_TO_K0(0x00100000)

#define IP27PROM_INT_LAUNCH 10  
#define IP27PROM_INT_NETUART 12  

#endif

#define IP27PROM_ELSC_SHFT 10
#define IP27PROM_ELSC_SIZE (1 << IP27PROM_ELSC_SHFT)

#define FREEMEM_BASE PHYS_TO_K0(0x2000000)

#define IO6PROM_STACK_SHFT 14  
#define IO6PROM_STACK_SIZE (1 << IO6PROM_STACK_SHFT)

#define IP27PROM_ENTRY PHYS_TO_COMPATK1(0x1fc00000)
#define IP27PROM_RESTART PHYS_TO_COMPATK1(0x1fc00008)
#define IP27PROM_SLAVELOOP PHYS_TO_COMPATK1(0x1fc00010)
#define IP27PROM_PODMODE PHYS_TO_COMPATK1(0x1fc00018)
#define IP27PROM_IOC3UARTPOD PHYS_TO_COMPATK1(0x1fc00020)
#define IP27PROM_FLASHLEDS PHYS_TO_COMPATK1(0x1fc00028)
#define IP27PROM_REPOD PHYS_TO_COMPATK1(0x1fc00030)
#define IP27PROM_LAUNCHSLAVE PHYS_TO_COMPATK1(0x1fc00038)
#define IP27PROM_WAITSLAVE PHYS_TO_COMPATK1(0x1fc00040)
#define IP27PROM_POLLSLAVE PHYS_TO_COMPATK1(0x1fc00048)

#define KL_UART_BASE LOCAL_HUB_ADDR(MD_UREG0_0)  
#define KL_UART_CMD LOCAL_HUB_ADDR(MD_UREG0_0)  
#define KL_UART_DATA LOCAL_HUB_ADDR(MD_UREG0_1)  
#define KL_I2C_REG MD_UREG0_0  

#ifndef __ASSEMBLY__

#ifdef HUB_ERR_STS_WAR
#define CACHE_ERR_EFRAME 0x480
#else
#define CACHE_ERR_EFRAME 0x400
#endif

#define CACHE_ERR_ECCFRAME (CACHE_ERR_EFRAME + EF_SIZE)
#define CACHE_ERR_SP_PTR (0x1000 - 32)  
#define CACHE_ERR_IBASE_PTR (0x1000 - 40)
#define CACHE_ERR_SP (CACHE_ERR_SP_PTR - 16)
#define CACHE_ERR_AREA_SIZE (ARCS_SPB_OFFSET - CACHE_ERR_EFRAME)

#endif

#define _ARCSPROM

#ifdef HUB_ERR_STS_WAR

#define ERR_STS_WAR_REGISTER IIO_IIBUSERR
#define ERR_STS_WAR_ADDR LOCAL_HUB_ADDR(IIO_IIBUSERR)
#define ERR_STS_WAR_PHYSADDR TO_PHYS((__psunsigned_t)ERR_STS_WAR_ADDR)

#define OLD_ERR_STS_WAR_OFFSET ((MD_MEM_BANKS * MD_BANK_SIZE) - 0x100)

#endif

#endif
