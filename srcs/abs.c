#include "ft_printf.h"

int		ft_abs(t_ptf *ptf, int n)
{
	if (n < 0)
	{
		ptf->neg = 1;
		n = n * -1;
	}
	return (n);
}
