#include "../includes/ft_printf.h"

void pf_write_non_print(char *str, int len, int *countx3)
{
	int i;
	char *non_print[33] = {"^NUL", "^SOH", "^STX", "^ETX", "^EOT", "^ENQ", "^ACK", "^BEL", "^BS ", "^TAB", "^LF",
						   "^VT ", "^FF ", "^CR ", "^S0 ", "^SI ", "^DLE", "^DC1", "^DC3", "^DC3", "^DC4", "^NAK",
						   "^SYN", "^ETB", "^CAN", "^EM ", "^SUB", "^ESC", "^FS ", "^GS ", "^RS ", "^US ", "^DEL"};
	i = -1;
	while (++i < len)
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			if (str[i] == 126)
				write(1, non_print[32], 4);
			else if (str[i] < 33)
				write(1, non_print[(int)(str[i])], 4);
			else
				{
					--*countx3;
					write(1, ".", 1);
				}
			++*countx3;
		}
		else
			write(1, &str[i], 1);
	}
}

/*
#define GREEN "\033[031m"
#define BROWN "\033[031m"
#define BLUE "\033[034m"
#define PURPLE "\033[035m"
#define CYAN "\033[036m"
#define WHITE "\033[0m"*/

void colour_write(char *str, int len, t_colour colour)
{
	colour == WHITE ? write(1,"\033[30m", 5): 0;
	colour == RED ? write(1,"\033[031m", 6): 0;
	colour == GREEN ? write(1,"\033[032m", 6): 0;
	colour == YELLOW ? write(1,"\033[033m", 6): 0;
	colour == BLUE ? write(1,"\033[034m", 6): 0;
	colour == PURPLE ? write(1,"\033[035m", 6): 0;
	colour == AQUA ? write(1,"\033[036m", 6): 0;
	colour == GREEY? write(1,"\033[037m", 6): 0;
	write(1, str, len);
}

//flag = -1 - non_print, flag == 1 -free, flag == -2 - colour +

int			pf_write(char *str, int len, int flag, t_colour colour)
{
	int countx3;
	
	countx3 = 0;
	if (!str)
		return (0);
	if (flag == -1)
		pf_write_non_print(str,len, &countx3);
	else if (colour == No)
		write(1, str, len);
	else
		colour_write(str, len, colour);
	flag == 1 ? free((void *)str) : 0;
	return (len + 3*countx3);
}

int repeat_write(char c, int n)
{
	int i;
	char str[n + 1];
	
	i = -1;
	while (++i < n)
		str[i] = c;
	write(1, str, i);
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
	if (s)
		while (s[i] && i < INT_MAX)
			++i;
	return (i);
}

