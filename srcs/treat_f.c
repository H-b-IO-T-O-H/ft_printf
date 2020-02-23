#include "../includes/ft_printf.h"

int treat_f_number_d(t_param param, va_list arg) {
	char sign_flag;
	intmax_t n;
	
	sign_flag = 0;
	if (param.mode == L)
		n = va_arg(arg, long);
	else if (param.mode == LL)
		n = va_arg(arg, long long);
	else if (param.mode == J)
		n = va_arg(arg, intmax_t);
	else if (param.mode == Z)
		n = va_arg(arg, ssize_t); // уточнить не size_t случаем!!!!!!!!!!!!!!!!!!!
	else
		n = va_arg(arg, int);
	if (param.mode == HH)
		n = (char) n;
	else if (param.mode == H)
		n = (short) n;
	param.flags & FLAG_SPACE ? sign_flag = ' ' : 0;
	param.flags & FLAG_PLUS ? sign_flag = '+' : 0;
	return (ft_itoa(param, n, sign_flag));
}

int treat_f_number(t_param param, va_list arg)
{
	uintmax_t n;
	
	if (param.conversion == 'd')
		return(treat_f_number_d(param, arg));
	if (param.mode == L)
		n = va_arg(arg, unsigned long);
	else if (param.mode == LL)
		n = va_arg(arg, unsigned long long);
	else if (param.mode == J)
		n = va_arg(arg, uintmax_t);
	else if (param.mode == Z)
		n = va_arg(arg, ssize_t);
	else
		n = va_arg(arg, unsigned int);
	if (param.mode == HH)
		n = (unsigned char) n;
	else if (param.mode == H)
		n = (unsigned short) n;
	return(ft_uitoa(param, n));
}

int treat_f_char(t_param param, va_list arg)
{
	char a;
	char c;
	
	a = param.flags & FLAG_ZERO ? '0' : ' ';
	c = (char)va_arg(arg, int);
	if ((param.flags & FLAG_MINUS) == 0)
		return(repeat_write(a, param.width - 1) + pf_write(&c,1,0,param.colour));
	return(pf_write(&c,1,0,param.colour) + repeat_write(a, param.width - 1));
}

int treat_f_string(t_param param, va_list arg)
{
	char *str;//no free !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	int flag;
	int length;
	
	str = va_arg(arg, char *);
	length = ft_strlen(str);
	if (!str || (param.conversion == 'r' && param.precision == -1))
	{
		str = (!str ? "(null)" : "NoPre");
		str[0] == '(' ? length = 6 : (param.precision = 6);
	}
	param.precision == -1 && param.conversion != 'r' ? param.precision = INT_MAX : 0;
	param.precision > length && param.conversion != 'r' ? param.precision = length : 0;
	flag = (param.conversion == 'r' ? -1 : 0);
	if ((param.flags & FLAG_MINUS) == 0 && param.width > param.precision)
		return(repeat_write(' ', param.width - param.precision) + pf_write(str,param.precision, flag, param.colour));
	if (param.width > param.precision)
		return(pf_write(str,param.precision, flag, param.colour) + repeat_write(' ', param.width - param.precision));
	return (pf_write(str, param.precision, flag, param.colour));
}

int treat_f_percent(t_param param, va_list arg)
{
	char a;
	
	a = param.flags & FLAG_ZERO ? '0' : ' ';
	if ((param.flags & FLAG_MINUS) == 0)
		return(repeat_write(a, param.width - 1) + pf_write("%",1,0, param.colour)); //  В оригинальном принтф получить сдвиг процента не получилось, но реализация все равное такая, т.к. вывод совпал с чуваком с гита + хер знает, зачем такую
	return(pf_write("%",1,0, param.colour) + repeat_write(a, param.width - 1));//парашу выводить, но мб кто-то додумался и до таких тестов
}
