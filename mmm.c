
#include "includes/ft_printf.h"

#define check_str "%-15.10f\n"
#define arg l

int main()
{
void *i = 0;
	int l1,l2;
	


	
	l1 = printf("{%f}{%lf}{%Lf}\n", 1e40, 1444565444646.646542424224,1);
	l2 = ft_printf("{%f}{%lf}{%Lf}", 1e40, 1444565444646.646542424224,1444565444646.646542424224);
	//printf("\nl1 = %d, l2 = %d", l1, l2);
	//printf("%llf", 1.1l);
	return 0;
}
