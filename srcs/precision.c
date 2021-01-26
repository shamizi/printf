#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_atoi(const char *str)
{
	int i;
	int res;
	int neg;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res = res * neg;
	return (res);
}


int		ft_strlen_prec(t_ptf *ptf, char *str)
{
	int i;

	i = 0;
	if (ptf->prec < 0)
		return (ft_strangelen(str));
	while (str[i] && i < ptf->prec)
		i++;
	return (i);
}
int		ft_putstr_prec(t_ptf *ptf, char *str)
{
	int i;

	i = 0;
	if (ptf->prec < 0)
		ptf->ret += ft_putstr(str);
	else
		while (str[i] && i < ptf->prec)
			ptf->ret += ft_putchar(str[i++]);
	return (i);
}

int		parser_prec(t_ptf *ptf, const char *str)
{
	int i;

	i = 0;
	if (str[i] == '.')
	{
		i++;
		if (str[i] == '*')
		{
			ptf->prec = va_arg(ptf->ap, int);
			i++;
		}
		else if (ft_isdigit(str[i]))
		{
			if (str[i] == '0')
			{
				ptf->prec = 0;
				i++;
			}
			if (ft_isdigit(str[i]))
			{
				ptf->prec = ft_atoi(&str[i]);
				while (ft_isdigit(str[i]))
					i++;
			}
		}
		else
			ptf->prec = 0;
	}
	return (i);
}
