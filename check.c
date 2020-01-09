#include "ft_printf.h"

void cmp()
{
	printf("hi");
}


/*
void test() {
	static t_pf_treat    (treat[12]) = {
			{.conversion = 's', .treat = pf_treat_string},
			{.conversion = 'S', .treat = pf_treat_string},
			{.conversion = 'c', .treat = pf_treat_char},
			{.conversion = 'C', .treat = pf_treat_char},
			{.conversion = '%', .treat = pf_treat_percent},
			{.conversion = 'd', .treat = pf_treat_hex},
			{.conversion = 'x', .treat = pf_treat_hex},
			{.conversion = 'X', .treat = pf_treat_hex},
			{.conversion = 'p', .treat = pf_treat_hex},
			{.conversion = 'u', .treat = pf_treat_hex},
			{.conversion = 'U', .treat = pf_treat_hex},
			{.conversion = 'o', .treat = pf_treat_hex}
	};
*/




/*

typedef struct	s_pf_param
{
	t_pf_string		str;
	int				access;
	int				flags;
	unsigned int	width;
	int				width_access;
	int				precision;
	t_pf_modifier	modifier;
	char			conversion;
	int				error;
	void			*value;
}				t_pf_param;

typedef struct	s_pf_treat
{
	char			conversion;
	int				(*treat)(t_pf_param, va_list);
}				t_pf_treat;

void test() {
	static t_pf_treat    (treat[12]) = {
			{.conversion = 's', .treat = pf_treat_string},
			{.conversion = 'S', .treat = pf_treat_string},
			{.conversion = 'c', .treat = pf_treat_char},
			{.conversion = 'C', .treat = pf_treat_char},
			{.conversion = '%', .treat = pf_treat_percent},
			{.conversion = 'd', .treat = pf_treat_hex},
			{.conversion = 'x', .treat = pf_treat_hex},
			{.conversion = 'X', .treat = pf_treat_hex},
			{.conversion = 'p', .treat = pf_treat_hex},
			{.conversion = 'u', .treat = pf_treat_hex},
			{.conversion = 'U', .treat = pf_treat_hex},
			{.conversion = 'o', .treat = pf_treat_hex}
	};
	
}*/