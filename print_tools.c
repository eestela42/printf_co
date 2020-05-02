#include "ft_printf.h"

void	ft_putchar(char a)
{
	write(1, &a, 1);
}
void	print_width(int width, t_oneforall *lst)
{
	while (width--)
	{
		ft_putchar(lst->zero);
		lst->ret_value++;
	}
}

void	print_preci(int preci, t_oneforall *lst)
{
	while (preci--)
	{
	ft_putchar('0');
	lst->ret_value++;
	}
}

void	print_buf(t_oneforall *lst)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && lst->buf[i])
	{
		ft_putchar(lst->buf[i]);
		lst->ret_value++;
	}
}