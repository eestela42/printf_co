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

typedef struct		s_oneforall
{
	int		pos;
	int		buf_i;
	char	buf[BUFFER_SIZE];
	char	*form;
	int		ret_value;
	int		sharp;
	char	zero;
	int		plus;
	int		minus;
	int		space;
	int		width;
	int		preci;
}					t_oneforall;

typedef	struct		s_int
{
	int		nbr;
	char	sign;
	int		size;
	int 	to_width;
	int		to_preci;
}					t_int;


int					ft_printf(char *form, ...);

int					printstr(t_oneforall *lst, va_list ap);
int					print_nbr(t_oneforall *lst, va_list ap);
int					printint(t_oneforall *lst, va_list ap);
int					printunsi(t_oneforall *lst, va_list ap);
int					printhexmin(t_oneforall *lst, va_list ap);
int					printhexmaj(t_oneforall *lst, va_list ap);

int 				flags(t_oneforall *lst, va_list ap);

void				new_buf(t_oneforall *lst);
void				initlst(t_oneforall *lst, char *form);
void				resetlst(t_oneforall *lst);
int					skip(t_oneforall *lst, va_list ap);

char				signer(int nbr, t_oneforall *lst);
int					sizer(int nbr, int sign, int base);
int					precier(t_oneforall *lst, int size);
int					widther(t_oneforall *lst, int size);
void				nbr_to_buf(t_oneforall *lst, t_int a, int base_size,
					char *base);

void				print_width(int width, t_oneforall *lst);
void				print_preci(int preci, t_oneforall *lst);
void				print_buf(t_oneforall *lst);

int					ft_strlen(char *s);
int					get_int_size(int nb);
void				ft_putchar(t_oneforall *lst, char c);

void buf_print(char *s, t_oneforall *lst);
void new_buf(t_oneforall *lst);
int char_buf(t_oneforall *lst, va_list ap);
int print_po(t_oneforall *lst, va_list ap);
int width(t_oneforall *lst, va_list ap);
int preci(t_oneforall *lst, va_list ap);
int zero(t_oneforall *lst, va_list ap);
int heytoile(t_oneforall *lst, va_list ap);
int pourcent(t_oneforall *lst, va_list ap);
int sign(t_oneforall *lst, va_list ap);
void resetlst(t_oneforall *lst);
void convert_base(unsigned long long int nb, char *table, t_oneforall *lst);

void spacing(int nbchar, t_oneforall *lst, int minus);
