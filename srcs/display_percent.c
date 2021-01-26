#include "ft_printf.h"

void	display_percent(t_ptf *ptf)
{
	int i;

	i = 1;
	if (ptf->neg == 0)
	{
		while (i++ < ptf->width)
			ptf->ret += ft_putchar(ptf->space);
	}
	ptf->ret += ft_putchar('%');
	if (ptf->neg == 1)
	{
		while (i++ < ptf->width)
			ptf->ret += ft_putchar(' ');
	}
}
