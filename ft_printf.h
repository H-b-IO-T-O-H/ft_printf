#ifndef PRINTF_NEW_FT_PRINTF_H
#define PRINTF_NEW_FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct	s_string
{
	char	*str;
	size_t	len;
}				t_string;

typedef enum	e_modifier
{
	NONE = 0, L = 1, H = 2, J = 3, Z = 4, LL = 5, HH = 6 //условно взяты названия типов с чужого гита
}				t_modifier;

typedef struct	s_params
{
	t_string	str;
	t_modifier	mode;
	int			width;
	int			precision;
	int			error;
	void		*value;
}				t_params;

typedef struct	s_pf_treat //
{
	char			conversion;
	int				(*treat)(t_params, va_list);
}				t_pf_treat;

int		pf_atoi(const char *str, int allow_neg, int *result, size_t *i);

#endif
