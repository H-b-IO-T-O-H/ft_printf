#include "../includes/ft_printf.h"


int		ft_atoi(const char *str, int allow_neg, int *result, int *i)
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
