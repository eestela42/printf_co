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

int 	pourc(t_oneforall *lst, va_list ap, int (*p[])(t_oneforall *lst, va_list ap))
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

void	init_p(int (*p[128]) (t_oneforall *lst, va_list ap))
{
	int i;

	i = 0;
	while (i <= 128)
		p[i++] = skip;
	//p['s'] = printstr;
	p['d'] = printint;
	p['i'] = printint;
	//p['c'] = char_buf;
	//p['p'] = print_po;
	p['0'] = flags;
	i = '1';
	while (i <= '9')
		p[i++] = width;
	p['.'] = preci;
	p['*'] = heytoile;
	p['-'] = flags;
	//p['%'] = pourcent;
	p['+'] = flags;
	//p['x'] = printhexmin;
	//p['X'] = printhexmaj;
}

int		ft_printf(char *form, ...)
{
	int (*p[128]) (t_oneforall *lst, va_list ap);
	va_list ap;
	t_oneforall *lst;

	if (!(lst = malloc(sizeof(t_oneforall))))
		return (0);
	initlst(lst, form);
	va_start(ap, form);
	lst->pos = 0;
	new_buf(lst);
	init_p(p);
	while (form[lst->pos])
	{
		if (form[lst->pos] == '%')
			pourc(lst, ap, p);
		else
			ft_putchar(lst, lst->form[lst->pos]);
		lst->pos++;
	}
	va_end(ap);
	free(lst);
	return (lst->ret_value);
}


