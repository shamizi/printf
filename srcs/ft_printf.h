#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct s_ptf	t_ptf;
struct					s_ptf
{
	int ret;
	int neg;
	int width;
	int type;
	char space;
	int hexa;
	int prec;
	int	nbneg;
	char base[17];
	char null[7];
	va_list ap;
};

void	display_u(t_ptf *ptf);
int		integerlen(int nb);
int		ft_strlen_prec(t_ptf *ptf, char *str);
int		ft_strangelen(char *str);
int		ft_putstr(char *str);
int		ft_putstr_prec(t_ptf *ptf, char *str);
int		parser_prec(t_ptf *ptf, const char *str);
int		ft_abs(t_ptf *ptf, int n);
int		ft_putchar(char c);
void	hexsize(t_ptf *ptf, unsigned long int nb);
void	hexbase(t_ptf *ptf, unsigned long int nb);
char	*itohex(char *base, unsigned long int nb);
int		hexalen(unsigned long int nb);
void	ft_hexstr(t_ptf *ptf, char *str);
void	ft_nbstr(t_ptf *ptf, int nb);
#endif
