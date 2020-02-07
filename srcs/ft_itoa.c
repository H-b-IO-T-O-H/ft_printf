#include <stdlib.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int len_base(char c, __intmax_t nb, int *base)
{
	int len;
	__intmax_t n;
	
	len = 0;
	(c == 'x' || c == 'X' || c == 'p') ? *base = 16 : 0;
	(c == 'u' || c == 'd') ? *base = 10 : 0;
	c == 'o' ? *base = 8 : 0;
	n = nb;
	while(nb)
	{
		nb /= *base;
		++len;
	}
	return (len + (n == 0));
}

void treat_min_value()
{

}

char	*ft_itoa(t_param param, __intmax_t nb, char sign, int *res)
{
	t_for_itoa a;
	
	a.count = len_base(param.conversion, nb, &a.base);
	a.i = 0;
	a.length = a.count;
	a.length < param.precision ? a.length = param.precision : 0;
	(nb < 0 || sign == '+' || sign == ' ') ? a.length++ : 0;
	nb < 0 ? sign = '-' : 0;
	nb < 0 ? nb = -nb : 0;
	*res = a.length;
	if (!(a.str = (char *)malloc(a.length + 1)))
		return (NULL);
	a.str[a.length] = '\0';
	sign ? a.str[a.i++] = sign : 0;
	while(a.count--)
	{
		a.str[--a.length] = nb % a.base + '0';
		nb /= 10;
	}
	while (a.i < a.length)
		a.str[a.i++] = '0';
	return (a.str);
}

char *ft_uitoa(t_param param, __uintmax_t nb, int *res)
{
	t_for_itoa a;
	char hex16[16] = "0123456789abcdef";
	char HEX16[16] = "0123456789ABCDEF";
	
	a.flag = 0;
	a.i = 0;
	if (param.flags & FLAG_HASH || param.conversion == 'p')
		(param.conversion == 'x' || param.conversion == 'X' || param.conversion == 'p') ? a.flag = 2 : (a.flag = 1);
	a.count = len_base(param.conversion, nb, &a.base);
	a.length = a.count;
	a.length < param.precision ? a.length = param.precision : 0;
	a.length == param.precision && a.flag == 1 ? a.length-- : 0;
	((a.flag && nb) || (a.flag && param.conversion == 'p')) ? a.length += a.flag : 0;
	*res =a.length;
	if (!(a.str = (char *)malloc(a.length + 1)))
		return (NULL);
	a.str[a.length] = '\0';
	if ((a.flag == 2 && nb) || (a.flag && param.conversion == 'p'))
	{
		a.str[1] = (param.conversion == 'x' || param.conversion == 'p') ? 'x' : 'X';
		++a.i;
	}
	if (a.flag)
	{
		a.str[0] = '0';
		++a.i;
	}
	while(a.count--)
	{
		param.conversion == 'x' || param.conversion == 'p' ?
		a.str[--a.length] = hex16[nb % a.base]: (a.str[--a.length] = HEX16[nb % a.base]);
		nb /= a.base;
	}
	while (a.i < a.length)
		a.str[a.i++] = '0';
	return (a.str);
}