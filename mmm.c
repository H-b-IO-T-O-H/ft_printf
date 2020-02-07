
#include "includes/ft_printf.h"

#define check_str "%p\n"
#define arg 1

int main()
{
	int l1;
	int l2;
	void* s;

	s = 0;
	//l1 = printf(check_str,s);
	//l2 = ft_printf(check_str, s);
	printf("%lld\n", LLONG_MIN);
	ft_printf("%lld\n", LLONG_MIN);
	//printf("printf = %d, ft_printf = %d\n", l1, l2);
	return 0;
}
