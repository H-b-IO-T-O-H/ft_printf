#ifndef PRINTF_NEW_FT_PRINTF_H
#define PRINTF_NEW_FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

# define NONE 0
# define FLAG_HASH 1
# define FLAG_ZERO 2
# define FLAG_MINUS 4
# define FLAG_PLUS 8
# define FLAG_SPACE 16
# define FLAG_APOSTROPHE 32

typedef union {
	
	long double D;
	struct
	{
		uintmax_t mantissa : 64;
		uintmax_t exponent : 15;
		unsigned int sign : 1;
		
	} parts;
} long_double_cast;

typedef struct	s_string
{
	const char	*str;
	int		len;
}				t_string;

typedef enum	e_modifier
{
	NO = 0, L = 1, H = 2, J = 3, Z = 4, LL = 5, HH = 6
}				t_modifier;

typedef struct	s_param
{
	t_string	str;
	t_modifier	mode;
	char 		conversion;
	char 		flags;
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

typedef struct s_for_itoa
{
	char *str;
	int flag;
	int base;
	int length;
	int count;
	int i;
	char conversion;
} t_for_itoa;

int ft_printf(const char *format, ...);

int		ft_atoi(const char *str, int allow_neg, int *result, int *i);
int		pf_is_conversion(char c);
int		pf_is_modifier(char c);
int		pf_is_flag(char c);
int		pf_is_precision(char c);
int		pf_is_valid(char c);
int		pf_isdigit(int c);
char	*ft_itoa(t_param param, intmax_t nb, char sign, int *res);
char *ft_uitoa(t_param param, uintmax_t nb, int *res);
void	ft_putchar(char c);
int		repeat_write(char c, int n);
int		pf_write(const char *str, int len, int flag);
int		ft_strlen(const char *s);

int treat_conversion(t_param *param, const char *str, int *i);
int treat_flags(t_param *param, const char *str, int *i);
int treat_modifier(t_param *param, const char *str, int *i);
int treat_precision(t_param *param, const char *str, int *i);
int			treat_width(t_param *param, const char *str, int *i);

int treat_f_number(t_param param, va_list arg);
int treat_f_char(t_param param, va_list arg);
int treat_f_string(t_param param, va_list arg);
int treat_f_percent(t_param param, va_list arg);
int treat_f_float(t_param param, va_list arg);

#endif