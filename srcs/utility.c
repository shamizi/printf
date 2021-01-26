#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	reinitialize(t_ptf *ptf)
{
	ptf->neg = 0;
	ptf->width = 0;
	ptf->type = 0;
	ptf->space = ' ';
	ptf->hexa = 0;
	ptf->prec = -1;
	ptf->nbneg = 0;
	ft_strlcpy(ptf->base, "0123456789abcdef", 17);
}


int		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int		ft_strangelen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
