#ifdef CONFIG_OF
#include <linux/of_device.h>
#endif

#ifdef CONFIG_OF
#if LINUX_VERSION_IS_GEQ(4,4,0)
/**
 * of_device_modalias - Fill buffer with newline terminated modalias string
 */
ssize_t bp_of_device_modalias(struct device *dev, char *str, ssize_t len)
{
	ssize_t sl = of_device_get_modalias(dev, str, len - 2);
	if (sl < 0)
		return sl;
	if (sl > len - 2)
		return -ENOMEM;

	str[sl++] = '\n';
	str[sl] = 0;
	return sl;
}
EXPORT_SYMBOL_GPL(bp_of_device_modalias);
#endif
#endif
