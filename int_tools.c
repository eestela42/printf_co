#include "ft_printf.h"

char	signer(int nbr, t_oneforall *lst)
{
	if (nbr < 0)
		return ('-');
	else if (nbr > 0 && lst->plus == 1)
		return ('+');
	else if (nbr >= 0 && lst->space == 1)
		return (' ');
	else
		return (0);
}

int		sizer(int nbr, int sign, int base)
{
	int	size;

	size = 0;
	if (sign)
		size++;
	if (!nbr)
		size++;
	while (nbr)
	{
		nbr /= base;
		size++;
	}
	return (size);
}

int		precier(t_oneforall *lst, int size)
{
	if (lst->preci - size > 0)
		return (lst->preci - size);
	return (0);
}

void	nbr_to_buf(t_oneforall *lst, t_int a, int base_size, char *base)
{
	if (a.sign)
		a.size--;
	lst->buf[a.size] = 0;
	if (a.nbr = 0)
		lst->buf[0] = '0';
	while (a.nbr)
	{
		lst->buf[--a.size] = 48 - (a.nbr % base_size);
		a.nbr /= base_size;
	}
}