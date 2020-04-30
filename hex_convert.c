/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:18:06 by dasanter          #+#    #+#             */
/*   Updated: 2020/03/11 17:54:56 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int putunsi(oneforall *lst, va_list ap)
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

char *uppercase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

int puthexmaj(oneforall *lst, va_list ap)
{
	 long long int nb;

	nb = va_arg(ap, long long int);
	convert_base(nb, "0123456789ABCDEF", lst)
	return 1;
}

int puthexmin(oneforall *lst, va_list ap)
{
	 long long int nb;

	nb = va_arg(ap, long long int);
	convert_base(nb, "0123456789abcdef", lst);
	return (1);
}

int putint(oneforall *lst, va_list ap)
{
	int nb;
	int nbchar;
	int minus;

	nb =  va_arg(ap, int);
	if (nb < 0)
	{
		minus = 1;
		nb *= -1;
	}
	else
		minus = 0;
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
		convert_base(2147483648, 10, lst);
	else
		convert_base(nb, 10, lst);
	if (lst->minus)
		spacing(nbchar, lst, minus);
	return (1);
}
