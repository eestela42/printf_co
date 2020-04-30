#include "ft_printf.h"

static void xchar_buf(oneforall *lst, int nb)
{
	if (lst->buf_i + nb < BUFFER_SIZE)
		return;
	buf_print(lst->buf, lst);
	new_buf(lst);
	lst->buf_i = 0;
}

void convert_base(unsigned long long int nb, char *table, oneforall *lst)
{
	int i;
	unsigned long long tmp;
	int base;

	tmp = nb;
	i = 0;
	base = ft_strlen(table);
	if (nb == 0)
		lst->buf[lst->buf_i++] = '0'; //si on est a la fin du buf ?
	while (tmp > 0)
	{
		i++;
		tmp /= base;
	}
//	if (i == 0)
//		lst->buf[lst->buf_i++] = '0';
	xchar_buf(lst, i);
	while (nb > 0)
	{
		lst->buf[lst->buf_i + i - 1] = table[nb % base];
		i--;
		nb /= base;
	}
	while (lst->buf[lst->buf_i])
		lst->buf_i++;
}

int get_int_size(int nb)
{
	int i;

	if (nb == -2147483648)
		return (10);
	i = 0;
	if (nb == 0 )
		return (1);
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}