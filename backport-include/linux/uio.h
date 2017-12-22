#ifndef _BP_LINUX_UIO_H
#define _BP_LINUX_UIO_H
#include_next <linux/uio.h>

bool _copy_from_iter_full(void *addr, size_t bytes, struct iov_iter *i);

#endif /* _BP_LINUX_UIO_H */
