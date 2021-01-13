#include "ft_printf.h"
#include "libft/libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}



/*teste de fonction pour les flags *chiffre* et -chiffre pour decaler le %c a gauche ou droite;
 */

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

void	display_c(t_ptf *ptf)
{
	int i;

	i = 1;
	if(ptf->neg == 0)
	{
		while(i < ptf->width)
		{
			ptf->ret += ft_putchar(ptf->space);
			i++;
		}
	}
	ft_putchar(va_arg(ptf->ap, int));
	if (ptf->neg == 1)
	{
		while (i < ptf->width)
		{
			ptf->ret += ft_putchar(' ');
			i++;
		}
	}
}

void	display_s(t_ptf *ptf)
{
	char *str;
	int i;

	str = (va_arg(ptf->ap, char *));
	//i = ft_strangelen(str);
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

void	display_p(t_ptf *ptf)
{
	unsigned long int p;
	int i;

	i = 0;
	p = (unsigned long int)va_arg(ptf->ap, void *);
	hexsize(ptf, p);
	ptf->width = ptf->width - ptf->hexa - 2;
	if (ptf->neg == 0)
	{
		while (i++ < ptf->width)
			ptf->ret += ft_putchar(ptf->space);
	}
	ptf->ret += ft_putstr("0x");
	if (!p)
		ptf->ret += ft_putchar('0');
	else
		hexbase(ptf, p);
	if (ptf->neg == 1)
	{
		while (i++ < ptf->width)
			ft_putchar(' ');
	}
}

void	display_x(t_ptf *ptf)
{
	int i;
	unsigned long int x;
	char *str;

	if (ptf->type == 'X')
		ft_strlcpy(ptf->base, "0123456789ABCDEF", 17);
	i = 0;
	x = (unsigned long int)va_arg(ptf->ap, unsigned int);
	if(!(str = itohex(ptf->base, x)))
			return ;
	if (ptf->prec >= 0 && ptf->prec - hexalen(x) > 0)
		ptf->prec = ptf->prec - hexalen(x);
	ptf->width -= (hexalen(x) + ptf->prec);
	if (ptf->neg == 0)
	{
		while (ptf->width-- > 0)
			ptf->ret += ft_putchar(ptf->space);
	}
	ft_hexstr(ptf, str);
	if(ptf->neg == 1)
	{
		while (ptf->width-- > 0)
			ptf->ret += ft_putchar(' ');
	}
}
/*void	display_x(t_ptf *ptf)
{
	unsigned long int x;
	int i;

	i = 0;
	x = (unsigned long int)va_arg(ptf->ap, unsigned int);
	hexsize(ptf, x);
	ptf->width -= ptf->hexa;
	if (ptf->type == 'X')
		ft_strlcpy(ptf->base, "0123456789ABCDEF", 17);
	if(ptf->neg == 0)
	{
		while (i++ < ptf->width)
			ptf->ret += ft_putchar(ptf->space);
	}
	hexbase(ptf, x);
	if (ptf->neg == 1)
	{
		while (i++ < ptf->width)
			ft_putchar(' ');
	}
	
}
*/
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
//	if (ptf->type = 'c')
//	if (ptf->type = 'c')
//	if (ptf->type = 'c')
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
	ft_strlcpy(ptf->base, "0123456789abcdef", 17);
	ft_strlcpy(ptf->null, "(null)", 7);
	// space = si flag 0 on mets des 0 a la place des espace pour le decalage
}


int		ft_printf(const char *str, ...)
{
	int i;
	t_ptf *ptf;

	ptf = malloc(sizeof(ptf));
	initialize(ptf);
	va_start(ptf->ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{

			initialize(ptf);
			i += flags(ptf, &str[i + 1]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	return (0);
}

int		main(void)
{
	char c;
	int d;
	char str[50] = "abcdef";
	void	*p;
	unsigned int x;

	x = 123456789;
	c = 's';
	d = 12;
	printf("chiffre : %50.*x\n",15, x);
	ft_printf("chiffre : %50.*x\n",15,  x);
}
