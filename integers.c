#include "ft_printf.h"

int		widther(t_oneforall *lst, int size)
{
	if (lst->zero == '0' && lst->preci > lst->width && !lst->minus)
	{
		lst->preci = lst->width;
		lst->width = 0;
	}
	if (lst->preci || lst->minus)
		lst->zero = ' ';
	if (lst->width - lst->preci > 0)
		return (lst->width - lst->preci);
	return (0);
}

static int		negation(int nbr)
{
	if (nbr > 0)
		return (-nbr);
	return (nbr);
}

static void		int_printer(t_oneforall *lst, t_int a)
{
	int i;

	i = 0;
	if (!lst->minus)
		print_width(a.to_width, lst);
	if (a.sign)
	{
		write(1, &a.sign, 1);
		lst->ret_value++;
	}
	print_preci(a.to_preci, lst);
	print_buf(lst);
	if (lst->minus)
		print_width(a.to_width, lst);
}

int				printint(t_oneforall *lst, va_list ap)
{
	t_int	a;

	a.nbr = va_arg(ap, int);
	a.sign = signer(a.nbr, lst);
	a.nbr = negation(a.nbr);
	a.size = sizer(a.nbr, a.sign, 10);
	a.to_width = widther(lst, a.to_preci);
	a.to_preci = precier(lst, a.size);
	nbr_to_buf(lst, a, 10, "0123456789");
	int_printer(lst, a);
	return(lst->ret_value);

}