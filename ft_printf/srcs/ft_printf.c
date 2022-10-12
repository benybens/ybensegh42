
#include "../includes/ft_printf.h"

//-----------------------------------------------------------------------------
//function name: print_str
//
//description: print str of format until next '%' or next '\' or '\0'
//-----------------------------------------------------------------------------
int	print_str(const char *format)
{
	int	i;
	char	*str;
	i = 0;
	while (format[i] && (format[i] != '%'))
		i++;
	str = ft_calloc(i, sizeof(char));
	ft_strlcpy(str, format, i + 1);
	ft_putstr_fd(str, 1);
	free(str);
	return (i);

}

//-----------------------------------------------------------------------------
//function name: process_int
//
//description: convert int in ascii and print
//-----------------------------------------------------------------------------
void	process_int(int nbr)
{
	ft_putstr_fd(ft_itoa(nbr), 1);
}

//-----------------------------------------------------------------------------
//function name: format_parse
//
//description: identify printf format
//-----------------------------------------------------------------------------
int	format_parse(const char *format, int i)
{
	i++;
	if(format[i] == 'd')
	{
		process_int(15);
		i++;
	}
	return (i);
}

//-----------------------------------------------------------------------------
//function name: countarg
//
//description: count number of '%' to know the number of ellistic arg
//-----------------------------------------------------------------------------
int	countarg(format)
{
	int count;
	int i;

	i = ;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count++;
	}
	return (count);
}

//-----------------------------------------------------------------------------
//function name: ft_printf
//
//description: mimic printf
//-----------------------------------------------------------------------------
int	ft_printf(const char *format, ...)
{
	char	*str;
	int	i;
	int 	nbarg;

	i = 0;
	str = ft_strdup(format);
	nbarg = countarg(format);
	while (str[i])
	{	
		if (str[i] == '%')
		{
			i = format_parse(format, i);
			ft_putendl_fd("",1);
			break;
		}	
		else
			i = print_str(str);
	}
	free(str);
	return (1);
}
