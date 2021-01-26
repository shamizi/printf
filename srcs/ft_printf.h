#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

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

void	reinitialize(t_ptf *ptf);
int		ft_putchar(char c);
int		ft_strangelen(char *str);
int		ft_putstr(char *str);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	display_c(t_ptf *ptf);
void	display_s(t_ptf *ptf);
void	display_p(t_ptf *ptf);
void	display_x(t_ptf *ptf);
void	display_i(t_ptf *ptf);
void	display_u(t_ptf *ptf);
void	display_percent(t_ptf *ptf);
int		integerlen(int nb);
int		ft_strlen_prec(t_ptf *ptf, char *str);
int		ft_putstr_prec(t_ptf *ptf, char *str);
int		parser_prec(t_ptf *ptf, const char *str);
int		ft_abs(t_ptf *ptf, int n);
void	hexsize(t_ptf *ptf, unsigned long int nb);
void	hexbase(t_ptf *ptf, unsigned long int nb);
char	*itohex(char *base, unsigned long int nb);
int		hexalen(unsigned long int nb);
void	ft_hexstr(t_ptf *ptf, char *str);
void	ft_nbstr(t_ptf *ptf, int nb);

#endif
