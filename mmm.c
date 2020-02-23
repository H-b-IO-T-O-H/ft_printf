
#include <float.h>
#include "includes/ft_printf.h"
#include <math.h>
#define check_str "%-15.10f\n"
#define arg 12.e451L

int main()
{
	int l1,l2;
	l1 = printf("%Lf\n", arg);
	l2 = ft_printf("%Lf\n", arg);
	printf ("\n%5d %d", l1, l2);
	return 0;
}

