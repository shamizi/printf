#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct s_ptf	t_ptf;
struct					s_ptf
{
	int ret;
	int neg;
	int width;
	int type;
	int space;
	va_list ap;
};

#endif
