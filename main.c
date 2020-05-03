#include "ft_printf.h"

int inter(char *form, ...)
{
    va_list ap;
    t_oneforall *lst;

    lst = malloc(sizeof(t_oneforall));
    initlst(lst, form);
    lst->width = 50;
    lst->preci = 5;
    va_start(ap, form);
    return(printint(lst, ap));
}

int main()
{
    int r;
    int t;

    r = ft_printf("|a|\n");
    t =    printf("|a|\n");
    printf("r = %i\nt = %i\n", r, t);

}
