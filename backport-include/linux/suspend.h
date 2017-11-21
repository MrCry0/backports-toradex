#ifndef __BP_LINUX_SUSPEND_H
#define __BP_LINUX_SUSPEND_H
#include_next <linux/suspend.h>

#if LINUX_VERSION_IS_LESS(3,18,0)
static inline void pm_system_wakeup(void)
{
#if LINUX_VERSION_IS_GEQ(3,10,0)
	freeze_wake();
#endif
}
#endif

#endif /* __BP_LINUX_SUSPEND_H */
