#include "ft_printf.h"

int		pf_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		pf_atoi(const char *str, int allow_neg, int *result, size_t *i)
{
	int nbr;
	int neg;
	
	neg = (str[*i] == '-');
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (allow_neg)
			(*i)++;
		else
			return (1);
	}
	nbr = 0;
	while (pf_isdigit(str[*i]))
	{
		nbr = nbr * 10 + (str[*i] - '0');
		(*i)++;
	}
	*result = (neg ? -nbr : nbr);
	return (0);
}