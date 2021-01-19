#include "ft_printf.h"

void	ft_putnbr(t_ptf *ptf, int nb)
{
	long n;

	n = nb;
	if (n < 0)
		n = n * -1;
	if (n >= 10)
	{
		ft_putnbr(ptf, n / 10);
		ft_putnbr(ptf, n % 10);
	}
	else
		ptf->ret += ft_putchar(n + '0');
}

int		integerlen(int nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
//	if (nb < 0)
//		i++;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void	ft_nbstr(t_ptf *ptf, int nb)
{
	if (ptf->prec < 0)
		ft_putnbr(ptf, nb);
	else
	{
		while(ptf->prec-- > 0)
			ptf->ret += ft_putchar('0');
		ft_putnbr(ptf, nb);
	}
}
