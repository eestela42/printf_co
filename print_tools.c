#include "ft_printf.h"

void	print_width(int width, t_oneforall *lst)
{
	while (width--)
	{
		write(1, &lst->zero, 1);
		lst->ret_value++;
	}
}

void	print_preci(int preci, t_oneforall *lst)
{
	while (preci--)
	{
	write(1, '0', 1);
	lst->ret_value++;
	}
}

void	print_buf(t_oneforall *lst)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && lst->buf[i])
	{
		write(1, &lst->buf[i], 1);
		lst->ret_value++;
	}
}