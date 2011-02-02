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
#ifndef __LINUX_SPINLOCK_TYPES_UP_H
#define __LINUX_SPINLOCK_TYPES_UP_H

#ifndef __LINUX_SPINLOCK_TYPES_H
#error "please don't include this file directly"
#endif

typedef struct { } raw_spinlock_t;

#define __RAW_SPIN_LOCK_UNLOCKED { }

typedef struct {

} raw_rwlock_t;

#define __RAW_RW_LOCK_UNLOCKED { }

#endif
