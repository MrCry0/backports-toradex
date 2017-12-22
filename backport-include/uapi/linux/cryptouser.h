#ifndef __BACKPORT_LINUX_CRYPTOUSER_H
#define __BACKPORT_LINUX_CRYPTOUSER_H
#include_next <linux/cryptouser.h>
#include <linux/version.h>

#if LINUX_VERSION_IS_LESS(4,8,0)
struct crypto_report_kpp {
        char type[CRYPTO_MAX_NAME];
};
#endif /* < 4.8 */

#endif
