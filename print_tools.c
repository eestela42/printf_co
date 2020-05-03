#include "ft_printf.h"

void	ft_putchar(t_oneforall *lst, char a)
{
	write(1, &a, 1);
	lst->ret_value++;
}

void	print_width(int width, t_oneforall *lst)
{
	while (width--)
		ft_putchar(lst, lst->zero);
}

void	print_preci(int preci, t_oneforall *lst)
{
	while (preci--)
		ft_putchar(lst, '0');
}

void	print_buf(t_oneforall *lst)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && lst->buf[i])
		ft_putchar(lst, lst->buf[i++]);
}