#include "ft_printf.h"

int			pf_write(const char *str, const size_t len)
{
	write(1, str, len);
	return (len);
}

int format_parser(const char *format, va_list arg)
{
	int i;
	int count;
	int a;
	double b;
	char c;
	
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			pf_write(format, count);
			if (format[i + 1] == 'd') {
				a = va_arg(arg, int);
				printf("%d", a);//тут itoa нужна конеч
			}
			else if (format[i + 1] == 'l')
				b = va_arg(arg, double);
			else
				c = va_arg(arg, int);
			break;
		}
		else
			++count;
		++i;
	}
	
	return (0);
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
	int a = 9;
	ft_printf("gdhd%d\n", a);
	//printf("Hello, World!\n");

	return 0;
}
