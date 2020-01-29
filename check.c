#include "ft_printf.h"

int		pf_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		++s;
	}
	if (c == '\0')
		return ((char*)s);
	return (NULL);
}





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

inline extern int			pf_is_conversion(char c)
{
	return (ft_strchr("diouxXcspf%", c) != NULL);
}

inline extern int			pf_is_modifier(char c)
{
	return (ft_strchr("hljz", c) != NULL);
}

inline extern int			pf_is_flag(char c)
{
	return (ft_strchr("#0-+' ", c) != NULL);
}

inline extern int			pf_is_precision(char c)
{
	return (ft_strchr("$*.", c) != NULL);
}

inline int					pf_is_valid(char c)
{
	return (pf_is_conversion(c) || pf_is_modifier(c) || pf_is_flag(c) ||
			pf_isdigit(c) || pf_is_precision(c));
}