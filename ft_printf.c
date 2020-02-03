#include "ft_printf.h"
#include "float.h"

int transform_param_conv(t_param param, va_list arg)//в заивисимости от типа преобразования возвращаем результат нужной отработавшей функции-обработчика
{
	int i;
	static t_treat_conv (treat_array[10]) = {
			{.conversion = 'd', .treat = treat_f_number},
			{.conversion = 'o', .treat = treat_f_number},
			{.conversion = 'u', .treat = treat_f_number},
			{.conversion = 'x', .treat = treat_f_number},
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
	while (++i < 10)
		if (param.conversion == treat_array[i].conversion)
			return (treat_array[i].treat(param, arg));
	return (0);
}

int begin_conv(va_list arg, const char *str, int *i, int len)//выделяем все флаги и модификаторы после знака %
{
	static int (*treat_func_arr[5])(t_param *param, const char *str, int *i) = {
			 treat_flags, treat_width, treat_precision,  treat_modifier, treat_conversion};
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
	while (j < 5 && *i <= start + len)
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
	return (transform_param_conv(param, arg));
}

int format_parser(const char *str, va_list arg)//разделяем выражение на модификаторы и обычные строчки
{
	int i;
	int j;
	int count;
	
	count = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			j = ++i;
			while ((str[i] && pf_is_valid(str[i]) && !pf_is_conversion(str[i])) || (str[i] && str[i] != '%' && pf_is_conversion(str[i])) )
				++i;
			str[i] == '%' ? ++i : 0;
			count += begin_conv(arg, str, &j, i - j);
			i = j;
		}
		else
		{
			ft_putchar(str[i++]);
			++count;
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

int main() {
	int a;
	char c;
	c = 'a';
	int l1, l2;
	a = -110;
	//char str[] = "asdfafdjhiofaiihafiohshiofdsssssssssssss;;;;;;;hfsaodiohfaihofashihifsadhioafdsio;hioafs";
	char *s = NULL;
	ft_printf("%10s\n", s);
	printf("%10s",s);
	//printf("%s",s);
	//l1 = printf("%100.0s\n, %s\n", str, str);
	//l2 = ft_printf("%100.0s\n, %s\n", str, str);
	//l1 = printf("abcdef%c\n",c);
	//l2 = ft_printf("abcdef%c\n", c);
	//ft_printf("abcdef%d\n",a);
	//printf("count(printf) = %d\n",l1);
	//printf("count(ft_printf) = %d\n",l2);
	//ft_printf("aaa%-12c\n", c);
	//printf("%10%%%%10.0%%d\n",a);
	//ft_printf("%%%d\n", a);
	return 0;
}
