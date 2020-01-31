#include "ft_printf.h"

int treat_f_number(t_param param, va_list arg)
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
	int count;
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

}