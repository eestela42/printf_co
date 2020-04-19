#include "ft_printf.h"

int main()
{
    int r;
    int t;

	r = ft_printf("|le mien {%10.8d}|\n", 42);
	t = printf("|le vrai {%10.8d}|\n", 42);
    printf("r = %i\nt = %i\n", r, t);

}