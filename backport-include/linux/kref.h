#ifndef __BACKPORT_LINUX_KREF_H
#define __BACKPORT_LINUX_KREF_H
#include_next <linux/kref.h>

#if LINUX_VERSION_IS_LESS(4,11,0)
#include <linux/refcount.h>
static inline unsigned int kref_read(const struct kref *kref)
{
        return refcount_read((const refcount_t *)&kref->refcount);
}
#endif /* < 4.11 */

#endif /* __BACKPORT_LINUX_KREF_H */
