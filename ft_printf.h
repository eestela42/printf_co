/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:07:52 by dasanter          #+#    #+#             */
/*   Updated: 2020/02/27 19:23:56 by seiseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#define BUFFER_SIZE 1024

typedef struct		s_list
{
	int		pos;
	char	*form;
	char	buf[BUFFER_SIZE];
	int		buf_i;
	int		ret_value;
	int		sharp;
	char	zero;
	int		plus;
	int		minus;
	int		space;
	int		width;
	int		preci;
}					oneforall;

int					printstr(oneforall *lst, va_list ap);
int					print_nbr(oneforall *lst, va_list ap);
int					printint(oneforall *lst, va_list ap);
int					printunsi(oneforall *lst, va_list ap);
int					printhexmin(oneforall *lst, va_list ap);
int					printhexmaj(oneforall *lst, va_list ap);

void				new_buf(oneforall *lst);
void				initlst(oneforall *lst, char *form);
void				resetlst(oneforall *lst);
int					skip(oneforall *lst, va_list ap);

int					ft_strlen(char *s);
int					get_int_size(int nb);
void				ft_putchar(oneforall *lst, char c);
void buf_print(char *s, oneforall *lst);
void new_buf(oneforall *lst);
int char_buf(oneforall *lst, va_list ap);
int print_po(oneforall *lst, va_list ap);
int width(oneforall *lst, va_list ap);
int preci(oneforall *lst, va_list ap);
int zero(oneforall *lst, va_list ap);
int heytoile(oneforall *lst, va_list ap);
int pourcent(oneforall *lst, va_list ap);
int sign(oneforall *lst, va_list ap);
void resetlst(oneforall *lst);
void convert_base(unsigned long long int nb, char *table, oneforall *lst);

void spacing(int nbchar, oneforall *lst, int minus);
