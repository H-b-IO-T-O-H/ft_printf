#ifndef PRINTF_NEW_FT_PRINTF_H
#define PRINTF_NEW_FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct	s_string
{
	const char	*str;
	int		len;
}				t_string;

typedef enum	e_modifier
{
	NONE = 0, L = 1, H = 2, J = 3, Z = 4, LL = 5, HH = 6 //условно взяты названия типов с чужого гита
}				t_modifier;

typedef struct	s_param
{
	t_string	str;
	t_modifier	mode;
	char 		conversion;
	char 		flag;
	int			width;
	int			precision;
	int			error;
	void		*value;
}				t_param;

typedef struct	s_treat //
{
	char			conversion;
	int				(*treat)(t_param, va_list);
}				t_treat_conv;


int		pf_atoi(const char *str, int allow_neg, int *result, size_t *i);
int		pf_is_conversion(char c);
int		pf_is_modifier(char c);
int		pf_is_flag(char c);
int		pf_is_precision(char c);
int		pf_is_valid(char c);
char	*ft_itoa(int nb);


#endif
