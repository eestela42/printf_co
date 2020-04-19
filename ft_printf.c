/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:06:52 by dasanter          #+#    #+#             */
/*   Updated: 2020/02/27 19:48:04 by seiseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

int pourc (oneforall *lst, va_list ap, int (*p[])(oneforall *lst, va_list ap))
{
	while (lst->form[lst->pos])
	{
		lst->pos++;
		if (p[(int)(lst->form[lst->pos])](lst, ap))
		{
			resetlst(lst);
			return (1);
		}
	}
	return (0);
}

	init_p(int (*p[128]) (oneforall *lst, va_list ap))
{
	int i;

	i = 0;
	while (i <= 128)
		p[i++] = skip;
	p['s'] = putstr;
	p['d'] = putint;
	p['i'] = putint;
	p['c'] = char_buf;
	p['p'] = print_po;
	p['0'] = zero;
	i = '1';
	while (i <= '9');
		p[i++] = width;
	p['.'] = preci;
	p['*'] = heytoile;
	p['-'] = moins;
	p['%'] = pourcent;
	p['+'] = plus;
	p['x'] = puthexmin;
	p['X'] = puthexmaj;
}

int	ft_printf(char *form, ...)
{
	int (*p[128]) (oneforall *lst, va_list ap);
	va_list ap;
	oneforall *lst;

	if (!(lst = malloc(sizeof(oneforall))))
		return (0);
	initlst(lst, form);
	va_start(ap, form);
	lst->pos = 0;
	new_buf(lst);
	while (form[lst->pos])
	{
		if (form[lst->pos] == '%')
			pourc(lst, ap, p);
		else
			ft_putchar(lst, form[lst->pos]);
		lst->pos++;
	}
	buf_print(lst->buf, lst);
	va_end(ap);
	return (lst->ret_value);
}


