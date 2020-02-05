#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

int len_base(__intmax_t nb, int base)
{
	int len;
	
	len = 0;
	while(nb)
	{
		nb /= base;
		++len;
	}
	return (len);
}

char	*ft_itoa(t_param param, __intmax_t nb, char sign, int *res)
{
	int length;
	int count;
	char *str;
	int i;
	
	count = len_base(nb, 10);
	i = 0;
	length = count;
	length < param.precision ? length = param.precision : 0;
	(nb < 0 || sign == '+') ? length++ : 0;
	nb < 0 ? sign = '-' : 0;
	nb < 0 ? nb = -nb : 0;
	sign == ' ' ? length++ : 0;
	*res = length;
	if (!(str = (char *)malloc(length + 1)))
		return (NULL);
	str[length] = '\0';
	sign ? str[i++] = sign : 0;
	while(count--)
	{
		str[--length] = nb % 10 + '0';
		nb /= 10;
	}
	while (i < length)
		str[i++] = '0';
	return (str);
}

char *ft_uitoa(t_param param, __intmax_t nb, int *res)
{
	int flag;
	
	flag = 0;//2-p,X(o), 1 - x(o)
	//if (param.flags & FLAG_HASH || param.conversion == 'p')
	//	param.conversion == 'x' ? flag = 1 : (flag = 2);
	
}