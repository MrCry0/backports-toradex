#undef __print_array
#define __print_array(array, count, el_size)				\
	({								\
		BUILD_BUG_ON(el_size != 1 && el_size != 2 &&		\
			     el_size != 4 && el_size != 8);		\
		ftrace_print_array_seq(p, array, count, el_size);	\
	})

#undef __get_dynamic_array_len
#define __get_dynamic_array_len(field)	\
		((__entry->__data_loc_##field >> 16) & 0xffff)
#if LINUX_VERSION_IS_GEQ(3,2,0)
#include_next <trace/ftrace.h>
#endif
