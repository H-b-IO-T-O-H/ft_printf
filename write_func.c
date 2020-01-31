#include "ft_printf.h"

int			pf_write(const char *str, int len)
{
	write(1, str, len);
	return (len);
}

int repeat_write(char c, int n)
{
	int i;
	
	i = -1;
	while (++i < n)
		ft_putchar(c);
	return (i);
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

