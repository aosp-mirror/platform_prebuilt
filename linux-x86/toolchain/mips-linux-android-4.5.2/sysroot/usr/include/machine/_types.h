/*	$OpenBSD: _types.h,v 1.5 2008/07/21 20:50:54 martynas Exp $	*/

/*-
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)types.h	8.3 (Berkeley) 1/5/94
 *	@(#)ansi.h	8.2 (Berkeley) 1/4/94
 */

#ifndef _MIPS64__TYPES_H_
#define _MIPS64__TYPES_H_

/*
 *  We need to handle the various ISA levels for sizes.
 */
#define	_MIPS_ISA_MIPS1	1	/* R2000/R3000 */
#define	_MIPS_ISA_MIPS2	2	/* R4000/R6000 */
#define	_MIPS_ISA_MIPS3	3	/* R4000 */
#define	_MIPS_ISA_MIPS4	4	/* TFP (R1x000) */

/* 7.18.1.1 Exact-width integer types */
typedef	__signed char		__int8_t;
typedef	unsigned char		__uint8_t;
typedef	short			__int16_t;
typedef	unsigned short		__uint16_t;
typedef	int			__int32_t;
typedef	unsigned int		__uint32_t;
/* LONGLONG */
typedef	long long		__int64_t;
/* LONGLONG */
typedef	unsigned long long	__uint64_t;

/* 7.18.1.2 Minimum-width integer types */
typedef	__int8_t		__int_least8_t;
typedef	__uint8_t		__uint_least8_t;
typedef	__int16_t		__int_least16_t;
typedef	__uint16_t		__uint_least16_t;
typedef	__int32_t		__int_least32_t;
typedef	__uint32_t		__uint_least32_t;
typedef	__int64_t		__int_least64_t;
typedef	__uint64_t		__uint_least64_t;

/* 7.18.1.3 Fastest minimum-width integer types */
typedef	__int32_t		__int_fast8_t;
typedef	__uint32_t		__uint_fast8_t;
typedef	__int32_t		__int_fast16_t;
typedef	__uint32_t		__uint_fast16_t;
typedef	__int32_t		__int_fast32_t;
typedef	__uint32_t		__uint_fast32_t;
typedef	__int64_t		__int_fast64_t;
typedef	__uint64_t		__uint_fast64_t;

/* 7.18.1.4 Integer types capable of holding object pointers */
typedef	long			__intptr_t;
typedef	unsigned long		__uintptr_t;

/* 7.18.1.5 Greatest-width integer types */
typedef	__int64_t		__intmax_t;
typedef	__uint64_t		__uintmax_t;

/* Register size */
#if (_MIPS_ISA == _MIPS_ISA_MIPS3 || _MIPS_ISA == _MIPS_ISA_MIPS4)
typedef __int64_t		__register_t;
typedef __int64_t		f_register_t;	/* XXX */
#else
typedef __int32_t		__register_t;
typedef __int32_t		f_register_t;	/* XXX */
#endif

/* VM system types */
typedef unsigned long		__vaddr_t;
typedef unsigned long		__paddr_t;
typedef unsigned long		__vsize_t;
typedef unsigned long		__psize_t;

/* Standard system types */
typedef int			__clock_t;
typedef int			__clockid_t;
typedef double			__double_t;
typedef float			__float_t;
typedef long long		__off_t;
typedef long			__ptrdiff_t;
/*typedef	unsigned long		__size_t;*/
typedef	long			__ssize_t;
typedef	int			__time_t;
typedef int			__timer_t;
#if defined(__GNUC__) && __GNUC__ >= 3
typedef	__builtin_va_list	__va_list;
#else
typedef	char *			__va_list;
#endif

/* Wide character support types */
#ifndef __cplusplus
typedef	int			__wchar_t;
#endif
typedef int			__wint_t;
typedef	int			__rune_t;
typedef	void *			__wctrans_t;
typedef	void *			__wctype_t;

#ifdef __MIPSEB__
#define _BYTE_ORDER _BIG_ENDIAN
#else
#define _BYTE_ORDER _LITTLE_ENDIAN
#endif

#if defined(_KERNEL)
typedef struct label_t {
	__register_t val[14];
} label_t;
#endif

/* XXX check why this still has to be defined. pmap.c issue? */
#define __SWAP_BROKEN

/* Feature test macros */
#define __HAVE_TIMECOUNTER

#endif	/* _MIPS64__TYPES_H_ */
