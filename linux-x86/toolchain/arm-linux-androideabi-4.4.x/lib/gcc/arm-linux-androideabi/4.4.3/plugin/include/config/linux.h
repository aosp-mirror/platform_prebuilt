/* Definitions for Linux-based GNU systems with ELF format
   Copyright (C) 1995, 1996, 1997, 1998, 1999, 2000, 2003, 2004, 2005, 2006,
   2007, 2009 Free Software Foundation, Inc.
   Contributed by Eric Youngdale.
   Modified for stabs-in-ELF by H.J. Lu (hjl@lucon.org).

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/* Don't assume anything about the header files.  */
#define NO_IMPLICIT_EXTERN_C

#undef ASM_APP_ON
#define ASM_APP_ON "#APP\n"

#undef ASM_APP_OFF
#define ASM_APP_OFF "#NO_APP\n"

#undef MD_EXEC_PREFIX
#undef MD_STARTFILE_PREFIX

/* Provide a STARTFILE_SPEC appropriate for GNU/Linux.  Here we add
   the GNU/Linux magical crtbegin.o file (see crtstuff.c) which
   provides part of the support for getting C++ file-scope static
   object constructed before entering `main'.  */
   
#if defined (HAVE_LD_PIE) && defined (ENABLE_CRTBEGINTS)
#define LINUX_TARGET_STARTFILE_SPEC \
  "%{!shared: %{pg|p|profile:gcrt1.o%s;pie:Scrt1.o%s;:crt1.o%s}} crti.o%s \
   %{static:%{pie:crtbeginTS.o%s;:crtbeginT.o%s}} %{!static:%{shared|pie:crtbeginS.o%s;:crtbegin.o%s}}"
#elif defined (HAVE_LD_PIE) && ! defined (ENABLE_CRTBEGINTS)
#define LINUX_TARGET_STARTFILE_SPEC \
  "%{!shared: %{pg|p|profile:gcrt1.o%s;pie:Scrt1.o%s;:crt1.o%s}} \
   crti.o%s %{static:crtbeginT.o%s;shared|pie:crtbeginS.o%s;:crtbegin.o%s}"
#else
#define LINUX_TARGET_STARTFILE_SPEC \
  "%{!shared: %{pg|p|profile:gcrt1.o%s;:crt1.o%s}} \
   crti.o%s %{static:crtbeginT.o%s;shared|pie:crtbeginS.o%s;:crtbegin.o%s}"
#endif
#undef  STARTFILE_SPEC
#define STARTFILE_SPEC LINUX_TARGET_STARTFILE_SPEC

/* Provide a ENDFILE_SPEC appropriate for GNU/Linux.  Here we tack on
   the GNU/Linux magical crtend.o file (see crtstuff.c) which
   provides part of the support for getting C++ file-scope static
   object constructed before entering `main', followed by a normal
   GNU/Linux "finalizer" file, `crtn.o'.  */

#define LINUX_TARGET_ENDFILE_SPEC \
  "%{shared|pie:crtendS.o%s;:crtend.o%s} crtn.o%s"
#undef  ENDFILE_SPEC
#define ENDFILE_SPEC LINUX_TARGET_ENDFILE_SPEC

/* This is for -profile to use -lc_p instead of -lc.  */
#define LINUX_TARGET_CC1_SPEC "%{profile:-p}"
#ifndef CC1_SPEC
#define CC1_SPEC LINUX_TARGET_CC1_SPEC
#endif

/* The GNU C++ standard library requires that these macros be defined.  */
#undef CPLUSPLUS_CPP_SPEC
#define CPLUSPLUS_CPP_SPEC "-D_GNU_SOURCE %(cpp)"

#define LINUX_TARGET_LIB_SPEC \
  "%{pthread:-lpthread} \
   %{shared:-lc} \
   %{!shared:%{mieee-fp:-lieee} %{profile:-lc_p}%{!profile:-lc}}"
#undef  LIB_SPEC
#define LIB_SPEC LINUX_TARGET_LIB_SPEC

/* C libraries supported on Linux.  */
#define OPTION_GLIBC  (linux_libc == LIBC_GLIBC)
#define OPTION_UCLIBC (linux_libc == LIBC_UCLIBC)
#define OPTION_BIONIC (linux_libc == LIBC_BIONIC)

#define LINUX_TARGET_OS_CPP_BUILTINS()				\
    do {							\
        if (OPTION_GLIBC)                                       \
          builtin_define ("__gnu_linux__");                     \
	builtin_define_std ("linux");				\
	builtin_define_std ("unix");				\
	builtin_assert ("system=linux");			\
	builtin_assert ("system=unix");				\
	builtin_assert ("system=posix");			\
    } while (0)

#if defined(HAVE_LD_EH_FRAME_HDR)
#define LINK_EH_SPEC "%{!static:--eh-frame-hdr} "
#endif

/* Define this so we can compile MS code for use with WINE.  */
#define HANDLE_PRAGMA_PACK_PUSH_POP

#undef LINK_GCC_C_SEQUENCE_SPEC
#define LINK_GCC_C_SEQUENCE_SPEC \
  "%{static:--start-group} %G %L %{static:--end-group}%{!static:%G}"

/* Use --as-needed -lgcc_s for eh support.  */
#ifdef HAVE_LD_AS_NEEDED
#define USE_LD_AS_NEEDED 1
#endif

/* Determine which dynamic linker to use depending on whether GLIBC or
+   uClibc or Bionic is the default C library and whether
+   -muclibc or -mglibc or -mbionic has been passed to change the default.  */

#define CHOOSE_DYNAMIC_LINKER1(LIBC1, LIBC2, LIBC3, LD1, LD2, LD3)     \
  "%{" LIBC2 ":" LD2 ";:%{" LIBC3 ":" LD3 ";:" LD1 "}}"

#if DEFAULT_LIBC == LIBC_GLIBC
#define CHOOSE_DYNAMIC_LINKER(G, U, B) \
  CHOOSE_DYNAMIC_LINKER1 ("mglibc", "muclibc", "mbionic", G, U, B)
#elif DEFAULT_LIBC == LIBC_UCLIBC
#define CHOOSE_DYNAMIC_LINKER(G, U, B) \
  CHOOSE_DYNAMIC_LINKER1 ("muclibc", "mglibc", "mbionic", U, G, B)
#elif DEFAULT_LIBC == LIBC_BIONIC
#define CHOOSE_DYNAMIC_LINKER(G, U, B) \
  CHOOSE_DYNAMIC_LINKER1 ("mbionic", "mglibc", "muclibc", B, G, U)
#else
#error "Unsupported DEFAULT_LIBC"
#endif /* DEFAULT_LIBC */

/* For most targets the following definitions suffice;
   GLIBC_DYNAMIC_LINKER must be defined for each target using them, or
   GLIBC_DYNAMIC_LINKER32 and GLIBC_DYNAMIC_LINKER64 for targets
   supporting both 32-bit and 64-bit compilation.  */
#ifndef RUNTIME_ROOT_PREFIX
#define RUNTIME_ROOT_PREFIX ""
#endif
#define UCLIBC_DYNAMIC_LINKER RUNTIME_ROOT_PREFIX "/lib/ld-uClibc.so.0"
#define UCLIBC_DYNAMIC_LINKER32 RUNTIME_ROOT_PREFIX "/lib/ld-uClibc.so.0"
#define UCLIBC_DYNAMIC_LINKER64 RUNTIME_ROOT_PREFIX "/lib/ld64-uClibc.so.0"
#define BIONIC_DYNAMIC_LINKER "/system/bin/linker"
#define BIONIC_DYNAMIC_LINKER32 "/system/bin/linker"
#define BIONIC_DYNAMIC_LINKER64 "/system/bin/linker64"

#define LINUX_DYNAMIC_LINKER                                           \
  CHOOSE_DYNAMIC_LINKER (GLIBC_DYNAMIC_LINKER, UCLIBC_DYNAMIC_LINKER,  \
                      BIONIC_DYNAMIC_LINKER)
#define LINUX_DYNAMIC_LINKER32                                         \
  CHOOSE_DYNAMIC_LINKER (GLIBC_DYNAMIC_LINKER32, UCLIBC_DYNAMIC_LINKER32, \
                  BIONIC_DYNAMIC_LINKER32)
#define LINUX_DYNAMIC_LINKER64                                             \
  CHOOSE_DYNAMIC_LINKER (GLIBC_DYNAMIC_LINKER64, UCLIBC_DYNAMIC_LINKER64, \
                      BIONIC_DYNAMIC_LINKER64)

/* Determine whether the entire c99 runtime
   is present in the runtime library.  */
#define TARGET_C99_FUNCTIONS (OPTION_GLIBC)

/* Whether we have sincos that follows the GNU extension.  */
#define TARGET_HAS_SINCOS (OPTION_GLIBC)

#define TARGET_POSIX_IO
