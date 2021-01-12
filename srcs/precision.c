#include "ft_printf.h"

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
