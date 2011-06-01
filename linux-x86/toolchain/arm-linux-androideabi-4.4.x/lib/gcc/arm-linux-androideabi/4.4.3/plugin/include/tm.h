#ifndef GCC_TM_H
#define GCC_TM_H
#define TARGET_CPU_DEFAULT (TARGET_CPU_generic)
#ifndef LIBC_GLIBC
# define LIBC_GLIBC 1
#endif
#ifndef LIBC_UCLIBC
# define LIBC_UCLIBC 2
#endif
#ifndef LIBC_BIONIC
# define LIBC_BIONIC 3
#endif
#ifndef DEFAULT_LIBC
# define DEFAULT_LIBC LIBC_BIONIC
#endif
#ifndef ANDROID_DEFAULT
# define ANDROID_DEFAULT 1
#endif
#ifdef IN_GCC
# include "options.h"
# include "config/dbxelf.h"
# include "config/elfos.h"
# include "config/linux.h"
# include "config/linux-android.h"
# include "config/arm/elf.h"
# include "config/arm/linux-gas.h"
# include "config/arm/linux-elf.h"
# include "config/arm/bpabi.h"
# include "config/arm/linux-eabi.h"
# include "config/arm/aout.h"
# include "config/arm/arm.h"
# include "defaults.h"
#endif
#if defined IN_GCC && !defined GENERATOR_FILE && !defined USED_FOR_TARGET
# include "insn-constants.h"
# include "insn-flags.h"
#endif
#endif /* GCC_TM_H */
