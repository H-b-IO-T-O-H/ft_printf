#include "ft_printf.h"

int treat_f_number(t_param param, va_list arg) //в разработке (Ответственный Шуляк М.А.)
{
	int count;
	char *str;
	
	str = ft_itoa(va_arg(arg, int));
	count = ft_strlen(str);
	pf_write(str, count);
	return(count);
}

int treat_f_char(t_param param, va_list arg)
{
	char a;
	char c;
	
	a = param.flags & FLAG_ZERO ? '0' : ' ';
	c = (char)va_arg(arg, int);
	if ((param.flags & FLAG_MINUS) == 0)
		return(repeat_write(a, param.width - 1) + pf_write(&c,1));
	return(pf_write(&c,1) + repeat_write(a, param.width - 1));
}

int treat_f_string(t_param param, va_list arg)
{
	char *str;
	int i;
	int length;
	
	i = -1;
	str = va_arg(arg, char *);
	length = ft_strlen(str);
	if (!str)
	{
		str = "(null)";
		length = 6;
	}
	param.precision == -1 ? param.precision = INT_MAX : 0;
	param.precision > length ? param.precision = length : 0;
	if ((param.flags & FLAG_MINUS) == 0 && param.width > param.precision)
		return(repeat_write(' ', param.width - param.precision) + pf_write(str,param.precision));
	if (param.width > param.precision)
		return(pf_write(str,param.precision) + repeat_write(' ', param.width - param.precision));
	return (pf_write(str, param.precision));
}

int treat_f_percent(t_param param, va_list arg)
{
	char a;
	char c;
	
	a = param.flags & FLAG_ZERO ? '0' : ' ';
	if ((param.flags & FLAG_MINUS) == 0)
		return(repeat_write(a, param.width - 1) + pf_write("%",1)); //  В оригинальном принтф получить сдвиг процента не получилось, но реализация все равное такая, т.к. вывод совпал с чуваком с гита + хер знает, зачем такую
	return(pf_write("%",1) + repeat_write(a, param.width - 1));//парашу выводить, но мб кто-то додумался и до таких тестов
}