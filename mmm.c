
#include "includes/ft_printf.h"

int main()
{
	int l1;
	int l2;
	int s =-10;

	l1 = printf("%d\n",s);
	l2 = ft_printf("%d\n", s);
	printf("printf = %d, ft_printf = %d\n", l1, l2);
	return 0;
}
