#include "ft_printf.h"

void	display_c(t_ptf *ptf)
{
	int i;

	i = 1;
	if(ptf->neg == 0)
	{
		while(i < ptf->width)
		{
			ptf->ret += ft_putchar(ptf->space);
			i++;
		}
	}
	 ptf->ret += ft_putchar(va_arg(ptf->ap, int));
	if (ptf->neg == 1)
	{
		while (i < ptf->width)
		{
			ptf->ret += ft_putchar(' ');
			i++;
		}
	}
}
