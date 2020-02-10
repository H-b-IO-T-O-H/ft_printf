
#include "includes/ft_printf.h"

#define check_str "%-15.10f\n"
#define arg l

int main()
{
	int l1,l2;
	char str[10] = "a\t\adfafsdf";
	
	char *str1=NULL;
	//l1 = printf("111%.100s\n", str);
	//l2 = ft_printf("111%100s\n", str);
	l2 = ft_printf("%10r", str);
	printf("\nl1 = %d, l2 = %d", l1, l2);
	//printf("%llf", 1.1l);
	return 0;
}

