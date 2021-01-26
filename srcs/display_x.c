#include "ft_printf.h"

void	display_x(t_ptf *ptf)
{
	unsigned long int x;
	char *str;
	int prec;

	if (ptf->type == 'X')
		ft_strlcpy(ptf->base, "0123456789ABCDEF", 17);
	x = (unsigned long int)va_arg(ptf->ap, unsigned int);
	if (!(str = itohex(ptf->base, x)))
		return ;
	if (!x && !ptf->prec && !ptf->width && !ptf->neg)
		return ;
	prec = ptf->prec;
	if (ptf->prec >= 0)
		ptf->prec -=hexalen(x);
	if (ptf->prec < 0)
		ptf->width -= hexalen(x);
	else
		ptf->width -= (ptf->prec + hexalen(x));
	if(ptf->space == '0' && ptf->width > 0 && prec >= 0)
		ptf->space = ' ';
	if (ptf->neg == 0)
	{
		while (ptf->width-- > 0)
			ptf->ret += ft_putchar(ptf->space);
	}
	if (!x && !prec)
		ptf->ret += ft_putchar(' ');
	else
		ft_hexstr(ptf, str);
	if(ptf->neg == 1)
	{
		while (ptf->width-- > 0)
			ptf->ret += ft_putchar(' ');
	}
}
