#ifndef __BACKPORT_LINUX_HRTIMER_H
#define __BACKPORT_LINUX_HRTIMER_H
#include_next <linux/hrtimer.h>

#if LINUX_VERSION_IS_LESS(3,17,0)
#if LINUX_VERSION_IS_LESS(3,3,0)
inline u64 bp_ktime_divns(const ktime_t kt, s64 div)
{
	u64 dclc;
	int sft = 0;

	dclc = ktime_to_ns(kt);
	/* Make sure the divisor is less than 2^32: */
	while (div >> 32) {
		sft++;
		div >>= 1;
	}
	dclc >>= sft;
	do_div(dclc, (unsigned long) div);

	return dclc;
}
#define ktime_get_boottime_seconds() bp_ktime_divns(ktime_get_boottime(), NSEC_PER_SEC)
#else
u64 bp_ktime_divns(const ktime_t kt, s64 div);
#define ktime_divns bp_ktime_divns
#endif
#endif /* < 3.17 */

#endif /* __BACKPORT_LINUX_HRTIMER_H */
