
#include "includes/ft_printf.h"

#define check_str "%-15.10f\n"
#define arg l

int main()
{
	int l1,l2;

	//ft_printf("%d",10);
	int i = -1;
	int ar = 22;
	long double k = -0.60015000l;
	while (++i < 1)
	{
		printf("\n  do = %Lf  printf = %.*Lf",k,ar, k);
		ft_printf("ft = %.*Lf", ar,k);
		k+=0.1;
	}
	//ft_printf("%.2f\n", 1.215);
	//ft_printf("% h");
	//printf("%.o|%-.o|%#.o|%0.o\n", 0U, 0U, 0U, 0U);
	//ft_printf("%.o|%-.o|%#.o|%0.o", 0U, 0U, 0U, 0U);
	//printf("\nl1 = %d, l2 = %d", l1, l2);
	return 0;
}

