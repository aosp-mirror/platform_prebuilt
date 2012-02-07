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
#ifndef _ASM_TYPES_H
#define _ASM_TYPES_H

#ifndef __ASSEMBLY__

typedef unsigned short umode_t;

typedef __signed__ char __s8;
typedef unsigned char __u8;

typedef __signed__ short __s16;
typedef unsigned short __u16;

typedef __signed__ int __s32;
typedef unsigned int __u32;

#if _MIPS_SZLONG == 64

typedef __signed__ long __s64;
typedef unsigned long __u64;

#else

#ifdef __GNUC__
typedef __signed__ long long __s64;
typedef unsigned long long __u64;
#endif

#endif

#endif

#endif
