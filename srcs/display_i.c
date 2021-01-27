#include "ft_printf.h"

void	display_i(t_ptf *ptf)
{
	int nb;
	int prec;
	int nega;

	nega = 0;
	prec = ptf->prec;
	nb = va_arg(ptf->ap, int);
	if (!nb && !ptf->prec && !ptf->width)
		return ;
	if (nb < 0)
		ptf->width--;
	if (ptf->prec >= 0)
		ptf->prec -= integerlen(nb);
	if (ptf->prec < 0)
		ptf->width -= integerlen(nb);
	else
		ptf->width -= (integerlen(nb) + ptf->prec);
	if ((ptf->space == '0' && ptf->width > 0 && prec >= 0) || (!nb && !prec))
		ptf->space = ' ';

	//printf("\n\n space : %d \n\n width : %d \n\n prec : %d \n\n", ptf->space, ptf->width, prec);

	//if (nb == 0 && ptf->width > 0 && prec == 0 && ptf->neg == 0)
	//	ptf->width++;
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
	if(!nb && !prec)
			ptf->ret += ft_putchar(' ');
	else
		ft_nbstr(ptf, nb);
	if(ptf->neg == 1)
	{
		while (ptf->width-- > 0)
			ptf->ret += ft_putchar(' ');
	}
}


//width 1, prec 0, nb  0
