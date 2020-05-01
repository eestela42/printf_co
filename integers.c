#include "ft_printf.h"

int printint(oneforall *lst, va_list ap)
{
	int nb;
	int nbchar;
	int minus;

	nb =  va_arg(ap, int);
	minus = 0;
	if (nb < 0)
	{
		minus = 1;
		nb *= -1;
	}
	nbchar = get_int_size(nb);
	if (!lst->minus)
	{
		if(lst->zero == '0')
			lst->buf[lst->buf_i++] = '-';
		spacing(nbchar, lst, minus);
			if(lst->zero == '0')
				minus = 0;
	}
	if (lst->plus && !minus)
		ft_putchar(lst, '+');
	else if (lst->space && !minus)
		ft_putchar(lst, ' ');
	insert_preci(calc_preci(lst->preci, nbchar, minus), lst, minus);
	if (nb == -2147483648)
		convert_base(2147483648, "0123456789", lst);
	else
		convert_base(nb, "0123456789", lst);
	if (lst->minus)
		spacing(nbchar, lst, minus);
	return (1);
}

int printunsi(oneforall *lst, va_list ap)
{
	unsigned int nb;
	int nbchar;
	int minus;

	minus = 0;
	nb = va_arg(ap, unsigned int);
	nbchar = get_int_size(nb);
	if (!lst->minus)
	{
		if(lst->zero == '0')
			lst->buf[lst->buf_i++] = '-';
		spacing(nbchar, lst, minus);
	}
	if (lst->plus && !minus)
		ft_putchar(lst, '+');
	else if (lst->space && !minus)
		ft_putchar(lst, ' ');
	insert_preci(calc_preci(lst->preci, nbchar, minus), lst, minus);
	convert_base(nb, 10, lst);
	if (lst->minus)
		spacing(nbchar, lst, minus);
	return (1);
}