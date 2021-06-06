
#include <float.h>
#include "includes/ft_printf.h"
#include <math.h>
#define check_str "%-15.10f\n"
#define arg 12.e451L
//No = -1, WHITE = 0, GREEN = 1, BLUE = 2, RED = 3, PURPLE = 4, GREY = 5, YELLOW = 6, AQUA = 7
int main()
{
	int l1,l2;
	int i = -1;
	while (++i < 5)
	{
		ft_printf("asdfadsffdsfds%{RED}10d\n", 1000000);
		ft_printf("asdfadsffdsfds%{GREEN}10d\n", 1000000);
		ft_printf("asdfadsffdsfds%{YELLOW}10d\n", 1000000);
		ft_printf("asdfadsffdsfds%{WHITE}10d\n", 1000000);
		ft_printf("asdfadsffdsfds%{BLUE}10d\n", 1000000);
		ft_printf("asdfadsffdsfds%{GREY}10d\n", 1000000);
		ft_printf("asdfadsffdsfds%{AQUA}10d\n", 1000000);
		ft_printf("asdfadsffdsfds%{PURPLE}10d\n", 1000000);
	}
	return 0;
}

