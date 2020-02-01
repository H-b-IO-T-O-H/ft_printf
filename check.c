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