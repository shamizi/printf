#include "ft_printf.h"

int		hexalen(unsigned long int nb)
{
	int i;

	i = 0;
	while (nb)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

//convertir en chaine de caractere mon nombre en hexa
char	*itohex(char *base, unsigned long int nb)
{
	int len;
	char *str;

	len = hexalen(nb);
	if(!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		//str[len] = ptf->base[nb % 16];
		str[len] = base[nb % 16];
		nb /= 16;
	}
	return (str);
}

//mettre des 0 avant si necessaire

void	ft_hexstr(t_ptf *ptf, char *str)
{
	if (ptf->prec < 0)
		ptf->ret += ft_putstr(str);
	else
	{
		while (ptf->prec-- > 0)
			ptf->ret += ft_putchar('0');
		ptf->ret += ft_putstr(str);
	}
}
