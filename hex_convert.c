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

int printhexmaj(oneforall *lst, va_list ap)
{
	long long int nb;

	nb = va_arg(ap, long long int);
	convert_base(nb, "0123456789ABCDEF", lst);
	return (1);
}

int printhexmin(oneforall *lst, va_list ap)
{
	 long long int nb;

	nb = va_arg(ap, long long int);
	convert_base(nb, "0123456789abcdef", lst);
	return (1);
}