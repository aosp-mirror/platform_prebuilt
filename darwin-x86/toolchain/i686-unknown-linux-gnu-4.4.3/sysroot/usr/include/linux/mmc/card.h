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
#ifndef LINUX_MMC_CARD_H
#define LINUX_MMC_CARD_H

#include <linux/mmc/mmc.h>

struct mmc_cid {
 unsigned int manfid;
 char prod_name[8];
 unsigned int serial;
 unsigned short oemid;
 unsigned short year;
 unsigned char hwrev;
 unsigned char fwrev;
 unsigned char month;
};

struct mmc_csd {
 unsigned char mmca_vsn;
 unsigned short cmdclass;
 unsigned short tacc_clks;
 unsigned int tacc_ns;
 unsigned int r2w_factor;
 unsigned int max_dtr;
 unsigned int read_blkbits;
 unsigned int write_blkbits;
 unsigned int capacity;
 unsigned int read_partial:1,
 read_misalign:1,
 write_partial:1,
 write_misalign:1;
};

struct sd_scr {
 unsigned char sda_vsn;
 unsigned char bus_widths;
#define SD_SCR_BUS_WIDTH_1 (1<<0)
#define SD_SCR_BUS_WIDTH_4 (1<<2)
};

struct mmc_host;

struct mmc_card {
 struct list_head node;
 struct mmc_host *host;
 struct device dev;
 unsigned int rca;
 unsigned int state;
#define MMC_STATE_PRESENT (1<<0)  
#define MMC_STATE_DEAD (1<<1)  
#define MMC_STATE_BAD (1<<2)  
#define MMC_STATE_SDCARD (1<<3)  
#define MMC_STATE_READONLY (1<<4)  
 u32 raw_cid[4];
 u32 raw_csd[4];
 u32 raw_scr[2];
 struct mmc_cid cid;
 struct mmc_csd csd;
 struct sd_scr scr;
};

#define mmc_card_present(c) ((c)->state & MMC_STATE_PRESENT)
#define mmc_card_dead(c) ((c)->state & MMC_STATE_DEAD)
#define mmc_card_bad(c) ((c)->state & MMC_STATE_BAD)
#define mmc_card_sd(c) ((c)->state & MMC_STATE_SDCARD)
#define mmc_card_readonly(c) ((c)->state & MMC_STATE_READONLY)

#define mmc_card_set_present(c) ((c)->state |= MMC_STATE_PRESENT)
#define mmc_card_set_dead(c) ((c)->state |= MMC_STATE_DEAD)
#define mmc_card_set_bad(c) ((c)->state |= MMC_STATE_BAD)
#define mmc_card_set_sd(c) ((c)->state |= MMC_STATE_SDCARD)
#define mmc_card_set_readonly(c) ((c)->state |= MMC_STATE_READONLY)

#define mmc_card_name(c) ((c)->cid.prod_name)
#define mmc_card_id(c) ((c)->dev.bus_id)

#define mmc_list_to_card(l) container_of(l, struct mmc_card, node)
#define mmc_get_drvdata(c) dev_get_drvdata(&(c)->dev)
#define mmc_set_drvdata(c,d) dev_set_drvdata(&(c)->dev, d)

struct mmc_driver {
 struct device_driver drv;
 int (*probe)(struct mmc_card *);
 void (*remove)(struct mmc_card *);
 int (*suspend)(struct mmc_card *, pm_message_t);
 int (*resume)(struct mmc_card *);
};

#define mmc_card_release_host(c) mmc_release_host((c)->host)
#endif
