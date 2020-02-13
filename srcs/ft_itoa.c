#include <stdlib.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

int len_base(char c, __intmax_t nb, int *base)
{
	int len;
	
	len = 0;
	(c == 'x' || c == 'X' || c == 'p') ? *base = 16 : 0;
	(c == 'u' || c == 'd') ? *base = 10 : 0;
	c == 'o' ? *base = 8 : 0;
	c == 'b' ? *base = 2 : 0;
	while(nb)
	{
		nb /= *base;
		++len;
	}
	return (len + (len == 0));
}

void ft_itoa_1(t_for_itoa a)
{
	if (a.sign)
	{
		a.str[a.i++] = a.sign;
		a.j++;
	}
	while (a.i < a.j)
		a.str[a.i++] = '0';
	a.j = a.i;
	a.i--;
	while(a.count)
	{
		a.str[a.i + a.count--] = a.buf % 10 + '0';
		a.buf /= 10;
		++a.j;
	}
	while (a.j < a.length)
		a.str[a.j++] = ' ';
	write(1,a.str,a.k);
	free(a.str);
}

void ft_itoa_2(t_for_itoa a)
{
	while(a.count--)
	{
		a.str[--a.length] = a.buf % 10 + '0';
		a.buf /= 10;
	}
	while (a.i < a.length - a.j)
		a.str[a.i++] = a.flag_fill;
	if (a.sign)
		a.flag_fill != ' ' ? a.str[0] = a.sign : (a.str[a.i - 1] = a.sign);
	while (a.i < a.length)
		a.str[a.i++] = '0';
	write(1,a.str,a.k);
	free(a.str);
}

int ft_itoa(t_param param, __intmax_t nb, char sign_flag)
{
	t_for_itoa a;
	
	nb < 0 ? a.buf = -nb : (a.buf = nb);
	a.count = len_base(param.conversion, a.buf, &a.base);//длина числа
	nb == 0 && !param.precision ? a.count = 0 : 0;
	a.i = 0;
	param.flags & FLAG_ZERO && param.precision == -1 ? a.flag_fill = '0' : (a.flag_fill = ' ');
	a.length = a.count;
	a.length < param.precision ? a.length = param.precision : 0;
	nb < 0 || sign_flag == '+' ? a.length++ : 0;
	nb < 0 ? a.sign = '-' : (a.sign = sign_flag);
	param.width <= a.length && sign_flag == ' ' && nb >= 0 ? a.length++ : 0;
	a.length < param.width ? a.length = param.width : 0;
	if (!(a.str = (char *)malloc(a.length)))
		return (-1);
	a.k = a.length;
	param.precision != -1 ? a.j = param.precision - a.count : (a.j = 0);
	a.j < 0 ? a.j = 0 : 0;
	if (param.flags & FLAG_MINUS)
		ft_itoa_1(a);
	else
		ft_itoa_2(a);
	return (a.k);
}

void ft_uitoa_1(t_for_itoa a, t_param param)
{
	char hex16[16] = "0123456789abcdef";
	char HEX16[16] = "0123456789ABCDEF";
	
	if (((a.flag == 2 && a.buf) || (a.flag && param.conversion == 'p'))&& ++a.i >= 0)
		a.str[1] = (param.conversion == 'x' || param.conversion == 'p') ? 'x' : 'X';
	a.flag && ++a.i >= 0 ? a.str[0] = '0' : 0;
	while (a.i < a.j + a.flag)
		a.str[a.i++] = '0';
	a.j = a.i--;
	while(a.count)
	{
		param.conversion == 'x' || param.conversion == 'p' ?
				a.str[a.i + a.count--] = hex16[a.buf % a.base]: (a.str[a.i + a.count--] = HEX16[a.buf % a.base]);
		a.buf /= a.base;
		++a.j;
	}
	while (a.j < a.length)
		a.str[a.j++] = ' ';
	write(1,a.str,a.k);
	free(a.str);
}

void ft_uitoa_2(t_for_itoa a, t_param param)
{
	char hex16[16] = "0123456789abcdef";
	char HEX16[16] = "0123456789ABCDEF";
	int l;

	a.nb = a.buf;
	if (param.width >a.count && param.precision == -1 && param.flags & FLAG_ZERO  && a.flag == 2)
		l = a.flag - 1;
	else
		param.precision !=-1 ? l = a.length - a.count - 1 - a.j : (l = a.length - a.count - 1);
	while(a.count--)
	{
		param.conversion == 'x' || param.conversion == 'p' ?
				a.str[--a.length] = hex16[a.buf % a.base]: (a.str[--a.length] = HEX16[a.buf % a.base]);
		a.buf /= a.base;
	}
	while (a.i < a.length - a.j)
		a.str[a.i++] = a.flag_fill;
	while (a.i < a.length)
		a.str[a.i++] = '0';
	if ((a.flag == 2 && a.nb) || (a.flag && param.conversion == 'p'))
		a.str[l--] = (param.conversion == 'x' || param.conversion == 'p') ? 'x' : 'X';
	a.flag ? a.str[l] = '0' : 0;
	write(1,a.str,a.k);
	free(a.str);
}


int ft_uitoa(t_param param, __uintmax_t nb)
{
	t_for_itoa a;
	
	a.flag = 0;
	a.i = 0;
	a.buf = nb;
	if (param.flags & FLAG_HASH || param.conversion == 'p')
		(param.conversion == 'x' || param.conversion == 'X' || param.conversion == 'p') ? a.flag = 2 : (a.flag = 1);
	param.flags & FLAG_ZERO && param.precision == -1 ? a.flag_fill = '0' : (a.flag_fill = ' ');
	a.count = len_base(param.conversion, nb, &a.base);
	!nb && param.precision != -1 && a.flag != 1 ? a.count = 0 : 0;
	a.length = a.count;
	!nb && param.conversion != 'p' && a.flag && (param.precision > a.count || param.width > a.count) ? a.flag = 0 : 0;
	param.precision > a.count && param.conversion == 'o' ? a.flag = 0:0;
	a.length < param.precision ? a.length = param.precision : 0;
	((a.flag && nb) || (a.flag && param.conversion == 'p')) ? a.length += a.flag : 0;
	a.length < param.width ? a.length = param.width : 0;
	if (!(a.str = (char *)malloc(a.length)))
		return (-1);
	a.k = a.length;
	param.precision != -1 ? a.j = param.precision - a.count : (a.j = 0);
	a.j < 0 ? a.j = 0 : 0;
	 if (param.flags & FLAG_MINUS)
		ft_uitoa_1(a, param);
	else
		ft_uitoa_2(a, param);
	return (a.k);
}