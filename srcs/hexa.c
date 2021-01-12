// afficher l'adresse en hexa d'un poiteur 
#include "ft_printf.h"

void	hexsize(t_ptf *ptf, unsigned long int nb)
{
	if (nb >= 16)
		hexsize(ptf, (nb / 16));
	ptf->hexa++;
}

void	hexbase(t_ptf *ptf, unsigned long int nb)
{
	if (nb >= 16)
		hexbase(ptf, (nb / 16));
	ptf->ret += ft_putchar(ptf->base[nb % 16]);
}
