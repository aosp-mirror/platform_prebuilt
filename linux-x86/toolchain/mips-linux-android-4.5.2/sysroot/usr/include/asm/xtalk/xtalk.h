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
#ifndef _ASM_XTALK_XTALK_H
#define _ASM_XTALK_XTALK_H

#ifndef __ASSEMBLY__

typedef char xwidgetnum_t;

#define XWIDGET_NONE -1

typedef int xwidget_part_num_t;

#define XWIDGET_PART_NUM_NONE -1

typedef int xwidget_rev_num_t;

#define XWIDGET_REV_NUM_NONE -1

typedef int xwidget_mfg_num_t;

#define XWIDGET_MFG_NUM_NONE -1

typedef struct xtalk_piomap_s *xtalk_piomap_t;

#define XIO_NOWHERE (0xFFFFFFFFFFFFFFFFull)
#define XIO_ADDR_BITS (0x0000FFFFFFFFFFFFull)
#define XIO_PORT_BITS (0xF000000000000000ull)
#define XIO_PORT_SHIFT (60)

#define XIO_PACKED(x) (((x)&XIO_PORT_BITS) != 0)
#define XIO_ADDR(x) ((x)&XIO_ADDR_BITS)
#define XIO_PORT(x) ((xwidgetnum_t)(((x)&XIO_PORT_BITS) >> XIO_PORT_SHIFT))
#define XIO_PACK(p, o) ((((uint64_t)(p))<<XIO_PORT_SHIFT) | ((o)&XIO_ADDR_BITS))

#endif

#endif
