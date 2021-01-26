#include "ft_printf.h"

void	display_i(t_ptf *ptf)
{
	int nb;
	int prec;
	int nega;

	nega = 0;
	prec = ptf->prec;
	nb = va_arg(ptf->ap, int);
	if (nb < 0)
		ptf->width--;
	if (ptf->prec >= 0)
		ptf->prec -= integerlen(nb);
	if (ptf->prec < 0)
		ptf->width -= integerlen(nb);
	else
		ptf->width -= (integerlen(nb) + ptf->prec);
	if (ptf->space == '0' && ptf->width > 0 && prec > 0)
		ptf->space = ' ';
	if (nb == 0 && ptf->width > 0 && prec == 0 && ptf->neg == 0)
		ptf->width++;
	if (ptf->neg == 0)
	{
		if (nb < 0 && ptf->space == '0')
		{
			ptf->ret += ft_putchar('-');
			nega++;
		}
		while (ptf->width-- > 0)
			ptf->ret += ft_putchar(ptf->space);
	}
	if (nb < 0 && nega == 0)
		ptf->ret += ft_putchar('-');
	if(nb == 0 && prec == 0)
	{
		if (ptf->width > 0)
			ptf->ret += ft_putchar(' ');
	}
	else
		ft_nbstr(ptf, nb);
	if(ptf->neg == 1)
	{
		while (ptf->width-- > 0)
			ptf->ret += ft_putchar(' ');
	}
}

/*
void	display_i(t_ptf *ptf)
{
	int nb;

	nb = va_arg(ptf->ap, int);
	if (nb < 0)
		ptf->width--;
	if (ptf->prec >= 0)
		ptf->prec -= integerlen(nb);
	if (ptf->prec < 0)
		ptf->width -= integerlen(nb);
	else
		ptf->width -= (integerlen(nb) + ptf->prec);
	if (ptf->neg == 0)
	{
		if (nb < 0 && ptf->space == '0')
			ptf->ret += ft_putchar('-');
		while (ptf->width--> 0)
			ptf->ret += ft_putchar(ptf->space);
	}
	if (nb < 0 && ptf->space == ' ')
		ptf->ret += ft_putchar('-');
	ft_nbstr(ptf, nb);
	if(ptf->neg == 1)
	{
		while (ptf->width-- > 0)
			ptf->ret += ft_putchar(' ');
	}
}
*/

