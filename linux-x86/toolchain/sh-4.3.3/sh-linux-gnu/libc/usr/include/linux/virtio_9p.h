#ifndef _LINUX_VIRTIO_9P_H
#define _LINUX_VIRTIO_9P_H
/* This header is BSD licensed so anyone can use the definitions to implement
 * compatible drivers/servers. */
#include <linux/virtio_config.h>

/* The ID for virtio console */
#define VIRTIO_ID_9P	9
/* Maximum number of virtio channels per partition (1 for now) */
#define MAX_9P_CHAN	1

#endif /* _LINUX_VIRTIO_9P_H */
