#include "../includes/ft_printf.h"
#include "float.h"

int transform_param_conv(t_param param, va_list arg)//в заивисимости от типа преобразования возвращаем результат нужной отработавшей функции-обработчика
{
	int i;
	static t_treat_conv (treat_array[12]) = {
			{.conversion = 'd', .treat = treat_f_number},//done
			{.conversion = 'o', .treat = treat_f_number},
			{.conversion = 'u', .treat = treat_f_number},
			{.conversion = 'x', .treat = treat_f_number},
			{.conversion = 'b', .treat = treat_f_number},//!!!!!!!!!!!
			{.conversion = 'r', .treat = treat_f_string},//!!!!!!!!!!!
			{.conversion = 'X', .treat = treat_f_number},
			{.conversion = 'c', .treat = treat_f_char},//done
			{.conversion = 's', .treat = treat_f_string},//done
			{.conversion = 'p', .treat = treat_f_number},
			{.conversion = 'f', .treat = treat_f_float},
			{.conversion = '%', .treat = treat_f_percent},//done
	};
	i = -1;
	if (param.error)
		return (0);
	while (++i < 12)
		if (param.conversion == treat_array[i].conversion)
			return (treat_array[i].treat(param, arg));
	return (0);
}

int begin_conv(va_list arg, const char *str, int *i, int len)//выделяем все флаги и модификаторы после знака %
{
	static int (*treat_func_arr[6])(t_param *param, const char *str, int *i) = {
			treat_colour, treat_flags, treat_width, treat_precision,  treat_modifier, treat_conversion};
	t_param param;
	int j;
	int start;
	
	j = 0;
	start = *i;
	param.error = 0;
	param.flags = 0;
	param.precision = 0;
	param.mode = NONE;
	param.conversion = 0;
	param.str.str = str;
	param.str.len = len;
	while (j < 6 && *i <= start + len)
	{
		if (treat_func_arr[j](&param, str, i))
		{
			param.error = 1;
			break;
		}
		++j;
	}
	param.conversion == 'i' ? param.conversion = 'd' : 0;
	param.conversion == 'p' ? param.mode = LL : 0;
	param.width != -2 && param.width_flag == 1 ? param.width_flag = 0 * va_arg(arg, int) : 0;
	param.width == -2 ? param.width = va_arg(arg, int) : 0;
	if (param.width < 0)
	{
		param.flags |= FLAG_MINUS;
		param.width = -param.width;
	}
	//param.precision != -2 && param.prec_flag == 1 ? param.prec_flag = 0 * va_arg(arg, int) : 0;
	param.precision == -2 ? param.precision = va_arg(arg, int) : 0;
	param.precision < 0 && param.precision != -1 ? param.precision = -1 : 0;
	return (transform_param_conv(param, arg));
}

void	pf_is_colour(const char *str, int *i)
{
	int j;
	
	j = *i + 1;
	while(str[j] && str[j] != '}')
		++j;
	*i = ++j;
}

int format_parser(const char *str, va_list arg)//разделяем выражение на модификаторы и обычные строчки
{
	int i;
	int j;
	int k;
	int count;
	
	count = 0;
	i = 0;
	
	while (str[i])
	{
		if (str[i] == '%')
		{
			j = ++i;
			if (str[j] == '{')
				pf_is_colour(str, &i);
			while ((str[i] && pf_is_valid(str[i]) && !pf_is_conversion(str[i])) || (str[i] && str[i] != '%' && pf_is_conversion(str[i])) )
				++i;
			str[i] == '%' ? ++i : 0;
			count += begin_conv(arg, str, &j, i - j);
			i = j;
		}
		else
			{
				k = i;
				while (str[i] && str[i] != '%')
					++i;
				count += i - k;
				write(1, str + k, i - k);
		}
	}
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list arg;
	int result;
	va_start(arg, format);
	result = format_parser(format, arg);
	va_end(arg);
	return (result);
}

