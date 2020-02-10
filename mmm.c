
#include "includes/ft_printf.h"

#define check_str "%-15.10f\n"
#define arg l

int main()
{
void *i = 0;
	int l1,l2;
	


	
	 l1 = printf("{%Lf}\n", 1444565444646.646542524224l);
	l2 = ft_printf("{%Lf}", 1444565444646.646542524224l);
	//printf("\nl1 = %d, l2 = %d", l1, l2);
	//printf("%llf", 1.1l);
	return 0;
}
