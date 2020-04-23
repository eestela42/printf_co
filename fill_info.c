#include "ft_printf.h"

int heytoile(oneforall *lst, va_list ap)
{
    int i;

    i = va_arg(ap, int);
    if (i < 0)
    {
        i = -i;
        lst->minus = 1;
    }
    else if (i == 0)
        lst->zero = 1;
    lst->width = i;
    return(0);
}

int width(oneforall *lst, va_list ap)
{
    (void)ap;
    while('0' >= lst->form[lst->pos] <= '9')
    {
            lst->width = 10 * lst->width +
            (lst->form[lst->pos++] - '0');
    }
    return(0);
}

int preci(oneforall *lst, va_list ap)
{
    if (lst->form[++lst->pos] == '*')
    {
        lst->preci = va_arg(ap, int);
        if(lst->preci < 0)
            lst->preci = 0;
        return(0);
    }
    while('0' >= lst->form[lst->pos] && lst->form[lst->pos] <= '9')
    {
        if(lst->preci == -1)
            lst->preci = 0;
        lst->preci = 10 * lst->preci +
        (lst->form[lst->pos++] - '0');
    }
    return(0);
}

int flags(oneforall *lst, va_list ap)
{
    int i;
    char *str;

    (void)ap;
    i = lst->pos;
    str = lst->form;
    while(str[i] == '0' || str[i] == '+' || str[i] == '-' || str[i] == '#')
    {
        if (str[i] == '0')
            lst->zero = 1;
        else if (str[i] == '-')
            lst->minus = 1;
        else if (str[i] == '+')
            lst->plus = 1;
        else
            lst->sharp =1;
        i++;
    }
    lst->pos = i;
    return(0);
}