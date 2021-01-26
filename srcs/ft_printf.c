#include "ft_printf.h"

void	display_type(t_ptf *ptf)
{
	
	if (ptf->type == 'c')
		display_c(ptf);
	if (ptf->type == 's')
		display_s(ptf);
	if (ptf->type == 'p')
		display_p(ptf);
	if (ptf->type == 'x' || ptf->type == 'X') 
		display_x(ptf);
	if (ptf->type == 'i' || ptf->type == 'd')
		display_i(ptf);
	if (ptf->type == 'u')
		display_u(ptf);
	if (ptf->type == '%')
		display_percent(ptf);
}

int		flags(t_ptf *ptf, const char *str)
{
	int i;

	i = 0;
	while (str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
			ptf->neg = 1;
		if (str[i] == '0')
			ptf->space = '0';
		i++;
	}
	if (ft_isdigit(str[i]))
	{
		ptf->width = ft_atoi(&str[i]);
		while (ft_isdigit(str[i]))
			i++;
	}
	if (str[i] == '*')
	{
		ptf->width = ft_abs(ptf, va_arg(ptf->ap, int));
		i++;
	}
	i += parser_prec(ptf, &str[i]);
	ptf->type = str[i];
	display_type(ptf);
	return (++i);
}

/*fct pour initialiser valeur structure*/
void	initialize(t_ptf *ptf)
{
	ptf->ret = 0;
	ptf->neg = 0;
	ptf->width = 0;
	ptf->type = 0;
	ptf->space = ' ';
	ptf->hexa = 0;
	ptf->prec = -1;
	ptf->nbneg = 0;
	ft_strlcpy(ptf->base, "0123456789abcdef", 17);
	ft_strlcpy(ptf->null, "(null)", 7);
	// space = si flag 0 on mets des 0 a la place des espace pour le decalage
}


int		ft_printf(const char *str, ...)
{
	int i;
	int ret;
	t_ptf *ptf;

	ptf = malloc(sizeof(*ptf));
	initialize(ptf);
	va_start(ptf->ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{

			reinitialize(ptf);
			i += flags(ptf, &str[i + 1]);
		}
		else
			ptf->ret += ft_putchar(str[i]);
		i++;
	}
	va_end(ptf->ap);
	ret = ptf->ret;
	free(ptf);
	return (ret);
}
/*
int		main(void)
{
	int d;

	d = 123456789;
	printf("%d\n", (printf("original : %d, %d, %1.d %10.d, %1.50d", d,d,d,d,d)));
	printf("%d\n", (ft_printf("chiffres : %d, %d, %1.d %10.d, %1.50d", d,d,d,d,d)));
}
*/
