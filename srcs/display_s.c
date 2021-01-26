#include "ft_printf.h"

void	display_s(t_ptf *ptf)
{
	char *str;
	int i;

	str = (va_arg(ptf->ap, char *));
	if (!str)
		str = ptf->null;
	ptf->width -= ft_strlen_prec(ptf, str);
	i = 0;
	if (ptf->neg == 0)
	{
		while(i++ < ptf->width)
			ptf->ret += ft_putchar(ptf->space);
	}
	ft_putstr_prec(ptf, str);
	//ptf->ret += ft_putstr(str);



	if (ptf->neg == 1)
	{
		while (i++ < ptf->width)
			ptf->ret += ft_putchar(' ');
	}
}
