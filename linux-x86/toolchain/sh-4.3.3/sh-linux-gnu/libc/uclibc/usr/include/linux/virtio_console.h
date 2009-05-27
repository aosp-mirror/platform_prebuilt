#ifndef _LINUX_VIRTIO_CONSOLE_H
#define _LINUX_VIRTIO_CONSOLE_H
#include <linux/virtio_config.h>
/* This header, excluding the #ifdef __KERNEL__ part, is BSD licensed so
 * anyone can use the definitions to implement compatible drivers/servers. */

/* The ID for virtio console */
#define VIRTIO_ID_CONSOLE	3

/* Feature bits */
#define VIRTIO_CONSOLE_F_SIZE	0	/* Does host provide console size? */

struct virtio_console_config {
	/* colums of the screens */
	__u16 cols;
	/* rows of the screens */
	__u16 rows;
} __attribute__((packed));



#endif /* _LINUX_VIRTIO_CONSOLE_H */
