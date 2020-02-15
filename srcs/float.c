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

int re_alloc(char *str, char c, int i, int size)
{
	char *tmp_str;
	int j;
	
	if (!(tmp_str = (char *)malloc(size)))
		return (-1);
	tmp_str[size] = '\0';
	j = -1;
	if (c == '1') {
		tmp_str[++j] = c;
		while (++i < size)
			tmp_str[++j] = str[i];
	}
	else {
		while (++j < i)
			tmp_str[j] = str[j];
		if (c != '0' && c != ' ')
		{
			j > 0 ? --j : 0;
			tmp_str[j] = c;
			tmp_str[++j] = '1';
		}
		else
			tmp_str[j] = '1';
		while (i++ < size)
			tmp_str[++j] = str[i];
	}
	free(str);
	write(1, tmp_str, j);
	free(tmp_str);
	return (j);
}

void rounding(t_float *b)
{
	static int count = 1;
	static char *str;
	
	str = *b->str;
	if (b->j < -1)
		return ;
	if ((count == b->num_size && b->precision != 0) || (count == b->num_size + 1 && b->precision == 0))
	{
		b->size == b->num_size ? b->size++  : 0;
		b->size = re_alloc(str, (b->j != -1 ? str[b->j] : '1'), b->j, b->size);
	}
	str[b->j] == '.' ? --b->j : 0;
	if ((int)(str[b->j] - '0')!= 9)
		str[b->j] = (char)((int)(str[b->j] - '0') + 1 + '0');
	else
	{
		str[b->j] = '0';
		++count;
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

int float_to_str(char **str, long double num, t_param param)
{
	t_float b;
	
	b.neg = 0;
	b.multipl = multiplication(&num, &b.size, &b.flag);
	if (num < 0)
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
	size = float_to_str(&str, nb, param);
	if (str)
	{
		write(1, str, size);
		free(str);
	}
	return (size);
}