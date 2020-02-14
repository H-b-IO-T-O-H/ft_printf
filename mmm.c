
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
	ft_printf("%+#-10.4Lf\n\n",  -LDBL_MAX);
	printf("%+#-10.4Lf\n\n",  -LDBL_MIN);
	
	return 0;
}

