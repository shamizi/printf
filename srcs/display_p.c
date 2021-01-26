#include "ft_printf.h"

void	display_p(t_ptf *ptf)
{
	unsigned long int p;
	int i;

	i = 0;
	p = (unsigned long int)va_arg(ptf->ap, void *);
	if (p)
		hexsize(ptf, p);
	if ((void *)p == NULL && ptf->prec == -1)
		ptf->width--;
	ptf->width -= (ptf->hexa + 2);
	if (ptf->neg == 0)
	{
		while (i++ < ptf->width)
			ptf->ret += ft_putchar(ptf->space);
	}
	ptf->ret += ft_putstr("0x");
	if (p)
		hexbase(ptf, p);
	else if ((void *)p == NULL && ptf->prec == -1)
		ptf->ret += ft_putchar('0');
	if (ptf->neg == 1)
	{
		while (i++ < ptf->width)
			ptf->ret += ft_putchar(' ');
	}
}
