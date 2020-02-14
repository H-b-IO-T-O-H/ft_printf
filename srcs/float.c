#include <math.h>
#include "../includes/ft_printf.h"

long int multiplication(long double num, int *size)
{
	long int multipl;
	
	multipl = 1;
	while ((int)num/10 != 0)
	{
		multipl *= 10;
		(*size)++;
		num /= 10;
	}
	return (multipl);
}

void handle_integer(long double *num, char **str, int *i, long int multipl)
{
	int k;
	int j;
	
	j = 1;
	k = (int)*num;
	
	while (j-- == 1 || k != 0 )
	{
		(*str)[(*i)] = (char)((*num)/multipl + '0'); //берем первую цифру из целой части
		*num -= (int)((*num)/multipl)*multipl; //вычитаем ее в соответсвии с разрядом
		k -= ((int)k/multipl)*multipl;
		multipl /= 10;
		(*i)++;
	}
}


int handle_decimals(char **str, int *i, long double num, int precision) {
	int k;
	int tmp_num;
	double ac;
	
	ac = 5;
	k = 0;
	num *= 10; //появляется цифра в целой части
	while (k++ < precision)
		ac *= 0.1;
	k = 1;
	if (precision <= 0)
		ac = 0.5;
	else
		(*str)[(*i)++] = '.';
	while (k <= precision + 1) {
		if (k == precision + 1)
		{
			if ((int)(num)  >= 5)
				return (*i - 1);
			return (-2);
		}
		if ((num >= 0 && k <= precision) || (num < 0 && k <= precision)) {
			tmp_num = ((int) num != 9) ? (int) (num + ac) : (int) num;
			(*str)[(*i)++] = (char) (tmp_num + '0');
			num = (num - tmp_num) * 10;
		} else {
			tmp_num = ((int) num != 9) ? (int) (num + ac) : (int) num;
			if (k > precision + 1 && tmp_num > 5 && num > 0)
				return (1);
			else if ((k == precision + 1) && tmp_num < 5 && num > 0)
				return (0);
			if (tmp_num > 0 && k > precision + 1) {
				break;
			}
			num = (num - tmp_num) * 10;
		}
		k++;
	}
	return (-2);
}

void rounding(char **temp_str, int i)
{
	int j;
	char *str;
	
	str = *temp_str;
	if (i < 0)
		return ;
	str[i] == '.' ? --i : 0;
	j = (int)(str[i] - '0');
	if (j != 9)
		str[i] = (char)((int)(str[i] - '0') + 1 + '0');
	else
	{
		str[i] = '0';
		rounding(temp_str, i - 1);
	}
}

int create_str_put_flags(char **str, t_param param, int *size, int neg) {
	int i;
	int size_num;
	char flag;
	
	i = -1;
	size_num = *size - neg;
	((param.flags & FLAG_PLUS || param.flags & FLAG_SPACE) && !neg) ? ++(*size) : 0;
	flag = (param.flags & FLAG_SPACE ? ' ' : 0);
	flag = (param.flags & FLAG_PLUS ? '+' : 0);
	neg ? flag = '-' : 0;
	if (param.width > *size)
		*size = param.width;
	if (!(*str = malloc(sizeof(char)*(*size + 1))))
		return(-1);
	if (param.flags & FLAG_MINUS)
	{
		if (flag)
			(*str)[++i] = flag;
		i = size_num + (flag != 0);
		while (i < *size)
			(*str)[i++] =  ' ';
		(*str)[i] = '\0';
		i = (flag ? 1 : 0);
	}
	else {
		while (++i < *size - size_num)
			(*str)[i] = (char) (param.flags & FLAG_ZERO ? '0' : ' ');
		if (flag)
			param.flags & FLAG_ZERO ? (*str)[0] = flag : ((*str)[*size - size_num - 1] = flag);
	}
	return (i);
}

int float_to_str(char **str, long double num, int precision, t_param param)
{
	int size;
	long int multipl;
	int i;
	int neg;
	
	neg = 0;
	size = 1;
	if (num < 0 || (1/num == -INFINITY))
	{
		size++;
		neg = 1;
		num = -num;//danger
	}
	multipl = multiplication(num, &size); // считаем сколько степеней 10ки в целой части
	size += precision + (param.precision > 0);
	if ((i = create_str_put_flags(str, param, &size, neg))== -1)
		return (0);
	handle_integer(&num, str, &i, multipl); // записываем в tmp_str целую часть num с точкой, остается 0.(дробная часть)
	param.flags & FLAG_HASH && param.precision <= 0 ? (*str)[i++] = '.' : 0;
	if ((neg = handle_decimals(str, &i, num, precision)) != -2)
		rounding(str, neg);
	return (size);
}


int treat_f_float(t_param param, va_list arg)
{
	char *str;
	long double nb;
	int size;
	
	param.precision < 0 ? param.precision = 6 : 0;
	param.mode == LL ? nb = va_arg(arg, long double) : (nb = va_arg(arg, double));
	size = float_to_str(&str, nb, param.precision, param);
	write(1, str, size);
	//free(str);
	return (size);
}