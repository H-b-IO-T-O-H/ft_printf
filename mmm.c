
#include <float.h>
#include "includes/ft_printf.h"

#define check_str "%-15.10f\n"
#define arg l

int main()
{
	int l1,l2;

	//ft_printf("%d",10);
	int i = -1;
	int ar = 5;

	//printf("%.1000Lf\n\n", LDBL_MAX);
	l1 = printf("%f\n",1.e201);
	l2 = ft_printf("%f\n",1.e201);
	printf("\033[034m A line of text in blue");
	printf("l1 = %d  l2 = %d", l1, l2);
	return 0;
}

