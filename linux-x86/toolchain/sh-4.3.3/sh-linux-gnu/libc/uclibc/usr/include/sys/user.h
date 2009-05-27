/* Copyright (C) 1998, 1999, 2000, 2003 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#ifndef _SYS_USER_H
#define _SYS_USER_H	1

#include <features.h>

typedef unsigned long elf_greg_t;

#define ELF_NGREG 76
typedef elf_greg_t elf_gregset_t[ELF_NGREG];

struct user_fpu_struct {
	unsigned long fp_regs[16];
	unsigned long xfp_regs[16];
	unsigned long fpscr;
	unsigned long fpul;
};
typedef struct user_fpu_struct elf_fpregset_t;

#undef start_thread

#endif  /* sys/user.h */
