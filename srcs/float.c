#include "../includes/ft_printf.h"

int multiplication(long double *num, int *size, int *flag)
{
	int multipl;

	*size = 1;
	multipl = 0;
	*flag = ((int)*num == 0 ? 1 : 0); //flag == 1 pri num == 0
	while ((int)*num != 0)
	{
		(*size)++;
		*num /= 10;
		++multipl;
	}
	*size > 1 ? --*size : 0;
	return (multipl);
}



void handle_integer(long double *num, char **str, int *i, int multipl, int flag)
{
	!multipl? multipl += 1 + *i : (multipl += *i);
	int j = 0;
	while (*i < multipl)
	{
		if (!flag)
			*num *= 10;
		(*str)[(*i)++] = (char)((int)(*num) + '0');
		*num -= (int)*num;
	}
}


int handle_decimals(char **str, int *i, long double num, int precision) {
	int k;
	int tmp_num;
	double ac;

	ac = 5;
	k = 0;
	while (k++ < precision)
		ac *= 0.1;
	k = 1;
	if (precision <= 0)
		ac = 0.5;
	num*=10;
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

int re_alloc(char **str, int i, int size)
{
	char *tmp_str;
	char c;
	int j;

	c = (i != -1 ? (*str)[i] : '1');
	if (!(tmp_str = (char *)malloc(size)))
		return (-1);
	tmp_str[size] = '\0';
	j = -1;
	if (c == '1') {
		tmp_str[++j] = c;
		while (++i < size)
			tmp_str[++j] = (*str)[i];
	}
	else {
		while (++j < i)
			tmp_str[j] = (*str)[j];
		if (c != '0' && c != ' ')
		{
			j > 0 ? --j : 0;
			tmp_str[j] = c;
			tmp_str[++j] = '1';
		}
		else
			tmp_str[j] = '1';
		while (i++ < size)
			tmp_str[++j] = (*str)[i];
	}
	free(*str);
	*str = tmp_str;
	return (j);
}

void rounding(t_float *b)
{
	if (b->j < -1)
		return ;
	if ((b->count == b->num_size && b->precision != 0) || (b->count == b->num_size + 1 && b->precision == 0))
	{
		b->size == b->num_size ? b->size++  : 0;
		b->size = re_alloc(b->str,  b->j, b->size);
		return ;
	}
	(*b->str)[b->j] == '.' ? --b->j : 0;
	if ((int)((*b->str)[b->j] - '0')!= 9)
		(*b->str)[b->j] = (char)((int)((*b->str)[b->j] - '0') + 1 + '0');
	else
	{
		(*b->str)[b->j] = '0';
		++(b->count);
		b->j -=1;
		rounding(b);
	}
}

int create_str_put_flags(char **str, t_param param, int *size, int neg) {
	int i;
	int size_num;
	char flag;

	i = -1;
	flag = 0;
	((param.flags & FLAG_PLUS || param.flags & FLAG_SPACE) && !neg) ? ++(*size) : 0;
	if (param.flags & FLAG_SPACE)
		flag = ' ';
	if (param.flags & FLAG_PLUS)
		flag = '+';
	neg ? flag = '-' : 0;
	size_num = *size;
	if (param.width > *size)
		*size = param.width;
	if (!(*str = malloc(sizeof(char)*(*size + 1))))
		return(-1);
	(*str)[*size] = '\0';
	if (param.flags & FLAG_MINUS)
	{
		if (flag) {
			(*str)[++i] = flag;
			--size_num;
		}
		i = size_num + (flag != 0);
		while (i < *size)
			(*str)[i++] =  ' ';
		i = (flag ? 1 : 0);
	}
	else {
		neg = (++i < *size - size_num ? 1 : 0);
		if (neg)
		{
			while (i <= *size - size_num)
				(*str)[i++] = (char) (param.flags & FLAG_ZERO ? '0' : ' ');
			--i;
		}
		if (flag) {
			param.flags & FLAG_ZERO ? (*str)[0] = flag : ((*str)[*size - size_num] = flag);
			++i;
		}
	}
	return (i);
}
#include "math.h"

int treat_nan (int width, int flag)
{
	int len;

	width - 3 > 0 ? len = width : (len = 3);
	if (flag)
		write(1, "nan",3);
	if (len != 3)
		repeat_write(' ', len - 3);
	if (!flag)
		write(1, "nan",3);
	return(len);
}

int treat_inf(int width, int flag, char sign)
{
	int len;
	int count;

	len = 0;
	count =3;
	if (sign)
	{
		++len;
		width--;
	}
	width - len > 0 && width >= 3 ? len = width : (len = 3);
	if (flag)
	{
		sign ? write(1, &sign, 1) : 0;
		write(1, "inf", 3);
	}
	if (len != 3)
	{
		repeat_write(' ', len - 3);
		count += len - 3;
	}
	if (!flag)
	{
		sign ? write(1, &sign, 1) : 0;
		write(1, "inf", 3);
	}
	sign ? count++ : 0;
	return (count);
}

int float_to_str(char **str, long double num, t_param param, int *error)
{
	t_float b;

	if (num != num)
	{
		*error = 1;
		return (treat_nan(param.width, param.flags & FLAG_MINUS));
	}
	if (num == INFINITY || num == -INFINITY)
	{
		*error = 1;
		b.sign = 0;
		if (param.flags & FLAG_SPACE)
			b.sign = ' ';
		if (param.flags & FLAG_PLUS)
			b.sign = '+';
		num == -INFINITY ? b.sign = '-' : 0;
		return (treat_inf(param.width, param.flags & FLAG_MINUS, b.sign));
	}
	b.neg = 0;
	b.multipl = multiplication(&num, &b.size, &b.flag);
	if (num < 0 || 1/num == -INFINITY)
	{
		b.size++;
		b.neg = 1;
		num = -num;//danger
	}
	b.str = str;
	b.size +=  param.precision + (param.precision > 0) + (!param.precision && param.flags & FLAG_HASH);
	b.precision = param.precision;
	b.num_size = b.size - b.neg;
	if ((b.i = create_str_put_flags(b.str, param, &b.size, b.neg))== -1)
		return (0);
	handle_integer(&num, b.str, &b.i, b.multipl, b.flag);
	param.flags & FLAG_HASH && param.precision <= 0 ? (*b.str)[b.i++] = '.' : 0;
	param.precision > 0 ? (*b.str)[b.i++] = '.' : 0;
	b.count = 1;
	if ((b.j = handle_decimals(str, &b.i, num, param.precision)) != -2)
		rounding(&b);
	return (b.size);
}

int treat_f_float(t_param param, va_list arg)
{
	char *str;
	long double nb;
	int size;

	param.precision < 0 ? param.precision = 6 : 0;
	param.mode == LL ? nb = va_arg(arg, long double) : (nb = va_arg(arg, double));
	size = float_to_str(&str, nb, param, &param.error);
	if (!param.error)
	{
		pf_write(str, size, 0, param.colour);
		free(str);
	}
	param.error = 0;
	return (size);
}