#include "ft_printf.h"

void new_buf(oneforall *lst)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
		lst->buf[i++] = 0;
}

int skip(oneforall *lst, va_list ap)
{
	if (lst->form[lst->pos] == ' ')
		lst->space = 1;
	(void)ap;
	return (0);
}

void initlst(oneforall *lst, char *form)
{
	lst->pos = 0;
	lst->form = form;
	lst->sharp = 0;
	lst->zero = ' ';
	lst->minus = 0;
	lst->space = 0;
	lst->width = 0;
	lst->preci = -1;
	lst->ret_value = 0;
}

void resetlst(oneforall *lst)
{
	lst->sharp = 0;
	lst->zero = ' ';
	lst->minus = 0;
	lst->space = 0;
	lst->width = 0;
	lst->preci = -1;
}