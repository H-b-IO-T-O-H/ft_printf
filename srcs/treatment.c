#include "../includes/ft_printf.h"

int treat_conversion(t_param *param, const char *str, int *i)
{
	
	if (pf_is_conversion(str[*i]))
	{
		param->conversion = str[*i];
		(*i)++;
		return (0);
	}
	return (1);
}

int treat_flags(t_param *param, const char *str, int *i)
{
	int start;
	
	start = *i;
	while (*i < start + param->str.len)
	{
		if (pf_is_flag(str[*i]))
		{
			str[*i] == '#' ? (param->flags |= FLAG_HASH) : 0;
			str[*i] == '0' ? (param->flags |= FLAG_ZERO) : 0;
			str[*i] == '-' ? (param->flags |= FLAG_MINUS) : 0;
			str[*i] == '+' ? (param->flags |= FLAG_PLUS) : 0;
			str[*i] == ' ' ? (param->flags |= FLAG_SPACE) : 0;
			str[*i] == '\'' ? (param->flags |= FLAG_APOSTROPHE) : 0;
		}
		else
			return (0);
		++*i;
	}
	return (1); //ошибка, если после флагов нет никаких параметров
}

int treat_modifier(t_param *param, const char *str, int *i)
{
	t_modifier c;
	
	c = NO;
	if (!pf_is_modifier(str[*i]))
		return (0);
	if (str[*i] == 'l' || str[*i] == 'L')
	{
		if (str[*i + 1] == 'l')
		{
			++*i;
			c = LL;
		}
		else if (str[*i] == 'L')
			c = LL;
		else
			c = L;
	}
	else if (str[*i] == 'h')
	{
		if (str[*i + 1] == 'h')
		{
			++*i;
			c = HH;
		}
		else
			c = H;
	}
	else if (str[*i] == 'j')//extra
		c = J;
	else if (str[*i] == 'z')//extra
		c = Z;
	++*i;
	param->mode = c;
	return (0);
}

int treat_precision(t_param *param, const char *str, int *i)
{
	int p;
	
	param->precision = -1;
	if (str[*i] != '.')
		return (0);
	param->precision = 0;
	++*i;
	if (str[*i] == '*')
	{
		++*i;
		p = -2;
	}
	else if (ft_atoi(str, 0, &p, i))//у точности не может быть +/-, поэтому флаг allow_neg = 0
		return (1);
	param->precision = p;
	return (0);
}

int			treat_width(t_param *param, const char *str, int *i)//как обрабатывать $ и * пока хз
{
	int width;

	param->width_flag = 0;
	if (str[*i] == '*')
	{
		++*i;
		ft_atoi(str, 0, &width, i);
		width <= 0 ? width = -2 : 0;
		param->width_flag = 1;
	}else if (ft_atoi(str, 0, &width, i))
		return (1);
	param->width = width;
	return (0);
}

int treat_colour(t_param *param, const char *str, int *i)
{
	param->colour = No;
	if (str[*i] != '{')
		return (0);
	++*i;
	if (str[*i] == 'G')
		param->colour = (str[*i + 4] == 'N' ? GREEN : GREEY);
	str[*i] == 'B' ? param->colour = BLUE: 0;
	str[*i] == 'Y' ? param->colour = YELLOW : 0;
	str[*i] == 'A' ? param->colour = AQUA : 0;
	str[*i] == 'R' ? param->colour = RED : 0;
	str[*i] == 'P' ? param->colour = PURPLE : 0;
	str[*i] == 'W' ? param->colour = WHITE : 0;
	while (str[*i] && str[*i] != '}')
		++*i;
	if (str[*i] == '}')
		++*i;
	else
		return (1);
	return (0);
}
