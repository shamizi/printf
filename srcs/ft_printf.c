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
	i = ft_strangelen(str);
	ptf->width = ptf->width - i;
	i = 0;
	if (ptf->neg == 0)
	{
		while(i++ < ptf->width)
			ptf->ret += ft_putchar(ptf->space);
	}
	ptf->ret += ft_putstr(str);
	if (ptf->neg == 1)
	{
		while (i++ < ptf->width)
			ptf->ret += ft_putchar(' ');
	}
}

void	display_type(t_ptf *ptf)
{
	
	if (ptf->type == 'c')
		display_c(ptf);
	if (ptf->type == 's')
		display_s(ptf);
//	if (ptf->type = 'c')
//	if (ptf->type = 'c')
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
	char d;
	char str[50] = "test";

	c = 's';
	d = 'd';
	printf("chiffre : %01s %05c\n", str, d);
	ft_printf("chiffre : %01s %05c\n", str, d);
}
