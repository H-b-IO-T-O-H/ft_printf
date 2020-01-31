#include "ft_printf.h"

int transform_param_conv(t_param param, va_list arg)//в заивисимости от типа преобразования возвращаем результат нужной отработавшей функции-обработчика
{
	int i;
	static t_treat_conv (treat_array[9]) = {
			{.conversion = 'd', .treat = treat_f_number},
			{.conversion = 'o', .treat = treat_f_number},
			{.conversion = 'u', .treat = treat_f_number},
			{.conversion = 'x', .treat = treat_f_number},
			{.conversion = 'X', .treat = treat_f_number},
			{.conversion = 'c', .treat = treat_f_char},
			{.conversion = 's', .treat = treat_f_string},
			{.conversion = 'p', .treat = treat_f_number},
			{.conversion = '%', .treat = treat_f_number},
	};
	i = -1;
	if (param.error)
		return (0);
	while (++i < 9)
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
	while (j < 5 && *i < start + len)
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
			while (str[i] && pf_is_valid(str[i]))
				++i;
			count += begin_conv(arg, str, &j, i - j);
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
	a = -1000000;
	/*l1 = printf("abcdef%c\n",c);
	l2 = ft_printf("abcdef%c\n", c);
	//ft_printf("abcdef%d\n",a);
	printf("count(printf) = %d\n",l1);
	printf("count(ft_printf) = %d\n",l2);*/
	//ft_printf("aaa%-12c\n", c);
	return 0;
}

/*
По идее здесь нужны несколько функций для выделения:
 -флагов:  '#', '0', '-', '+', ' ', '/'' <--(апостроф тоже флаг)
 -ширины: добавляет пробелы(нули, если указан 0 перед модификатором) перед ЧИСЛОМ(выравнивание вправо), если длина числа меньше заданной ширины, если же наоборот,
		  то параметр ширины игнорируется, и число выводится без сдвига.Если перед модификатором ширины стоит '-', то выравнивание влево(результат вывода дополнен справа пробелами)
		  Причем модификатор отмечает именно символьные позиции, поэтому знак минус отрицательного числа тоже считается позицией.
		  Надо еще разобраться с $ и со *
		  подробнее о ширине: http://microsin.net/programming/arm/secrets-of-printf.html
 -точности: количество цифр после точки(по умолчанию 6)
 -модификатора длины: тип данных входного аргумента( особо не разбирался, но это тот тип, который в va_arg(arg,type) распознается
 -и только в конце типа преобразования: d и i - одно и то же (спросил в слаке, сказали, что это наследие scanf для переносимости printf)
 про остальное можно почитать в инете, там не сложно. Будем в начале реализовывать указанные  мануле типо diouxXcspf
 
 для этого целесообрано создать массив функций и прогонять каждый символ, следующий после процента через них. Если окажется, что символ
 принадлежит нужной функции, то эта функция обрабатывает вывод, внося правки в param.(здесь указано нужное поле структуры)
*/