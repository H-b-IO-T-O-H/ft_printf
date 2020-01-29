#include "ft_printf.h"

int			pf_write(const char *str, const size_t len)
{
	write(1, str, len);
	return (len);
}

void ft_putchar(char c)
{
	write(1, &c,1);
}

int ft_strlen(const char *s)
{
	int i;
	
	i = 0;
	while (s[i])
		++i;
	return (i);
}

int treat_d(t_param param, va_list arg)
{
	int count;
	char *str;
	
	str = ft_itoa(va_arg(arg, int));
	count = ft_strlen(str);
	pf_write(str, count);
	return(count);
}



int transform_param_conv(t_param param, va_list arg)//в заивисимости от типа преобразования возвращаем результат нужной отработавшей функции-обработчика
{
	int i;
	static t_treat_conv (treat_array[1]) = {
			{.conversion = 'd', .treat = treat_d}
	};
	i = -1;
	if (param.error)
		return (0);
	while (++i < 1)
		if (param.conversion == treat_array[i].conversion)
			return (treat_array[i].treat(param, arg));
	return (0);
}

int begin_conv(va_list arg, const char *str, int *i)//выделяем все флаги и модификаторы после знака %
{
	int j;
	t_param param;
	
	j = ++*i;
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
	while (str[*i])
	{
		if (pf_is_conversion(str[*i]))
			param.conversion = str[*i];
		else if (pf_is_flag(str[*i]))
			param.flag = str[*i];
		else if (pf_is_modifier(str[*i]))
			param.mode = str[*i];
		else if (pf_is_precision(str[*i]))
			param.precision = str[*i];
		else
			break ;
		++*i;//count++!!
	}
	if (param.conversion == 'i')
		param.conversion = 'd';
	param.error = 0;
	param.str.str = &str[j];
	param.str.len = *i - j;
	return (transform_param_conv(param, arg));
}

int format_parser(const char *str, va_list arg)//разделяем выражение на модификаторы и обычные строчки
{
	int i;
	int count;
	
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += begin_conv(arg, str, &i);
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
	/*int a;
	int l1, l2;
	a = 10;
	l1 = printf("abcdef\n");
	l2 = ft_printf("abcdef\n");
	//ft_printf("abcdef%d\n",a);
	printf("count(printf) = %d\n",l1);
	printf("count(ft_printf) = %d\n",l2);*/
	int a = 1012;
	double b = 12;
	printf("%-7.0f",b);
	return 0;
}
