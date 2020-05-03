#include "ft_printf.h"

int inter(char *form, ...)
{
    va_list ap;
    t_oneforall *lst;

    lst = malloc(sizeof(t_oneforall));
    initlst(lst, form);
    lst->width = 10;
    va_start(ap, form);
    return(printint(lst, ap));
}
int main()
{
    int r;
    int t;


	
	t = inter("%d|", 42);
    printf("r = %i\nt = %i\n", r, t);

}