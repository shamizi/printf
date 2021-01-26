#include "ft_printf.h"

void	ft_putnbr_u(t_ptf *ptf, unsigned int nb)
{
	if ( nb >= 10)
	{
		ft_putnbr_u(ptf, nb / 10);
		ft_putnbr_u(ptf, nb % 10);
	}
	else
		ptf->ret += ft_putchar(nb + '0');
}

int		unsignedintlen(unsigned int nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void	ft_nbstr_u(t_ptf *ptf, unsigned int nb)
{
	if (ptf->prec < 0)
		ft_putnbr_u(ptf, nb);
	else
	{
		while (ptf->prec-- > 0)
			ptf->ret += ft_putchar('0');
		ft_putnbr_u(ptf, nb);
	}
}
void	display_u(t_ptf *ptf)
{
	unsigned int nb;
	int prec;

	prec = ptf->prec;
	nb = va_arg(ptf->ap, unsigned int);
	if (ptf->prec >= 0)
		ptf->prec -= unsignedintlen(nb);
	if (ptf->prec < 0)
		ptf->width -= unsignedintlen(nb);
	else
		ptf->width -= (unsignedintlen(nb) + ptf->prec);
	if (ptf->space == '0' && ptf->width > 0 && prec > 0) 
		ptf->space = ' ';
	if (nb == 0 && ptf->width > 0 && prec == 0 && ptf->neg == 0)
		ptf->width++;
	if (ptf->neg == 0)
	{
		while (ptf->width-- > 0)
			ptf->ret += ft_putchar(ptf->space);
	}
	if (nb == 0 && prec == 0)
	{
		if (ptf->width > 0)
			ptf->ret += ft_putchar(' ');
	}
	else
		ft_nbstr_u(ptf, nb);
	if (ptf->neg == 1)
	{
		while (ptf->width-- > 0)
			ptf->ret += ft_putchar(' ');
	}
}
