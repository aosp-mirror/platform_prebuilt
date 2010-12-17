#ifndef GCC_TM_H
#define GCC_TM_H
#ifndef UCLIBC_DEFAULT
# define UCLIBC_DEFAULT 0
#endif
#ifdef IN_GCC
# include "options.h"
# include "config/vxworks-dummy.h"
# include "config/i386/i386.h"
# include "config/i386/unix.h"
# include "config/i386/att.h"
# include "config/dbxelf.h"
# include "config/elfos.h"
# include "config/svr4.h"
# include "config/linux.h"
# include "config/glibc-stdint.h"
# include "config/i386/linux.h"
# include "defaults.h"
#endif
#if defined IN_GCC && !defined GENERATOR_FILE && !defined USED_FOR_TARGET
# include "insn-constants.h"
# include "insn-flags.h"
#endif
#endif /* GCC_TM_H */
