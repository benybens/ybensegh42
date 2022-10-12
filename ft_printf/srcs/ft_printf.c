
#include "../includes/ft_printf.h"

//-----------------------------------------------------------------------------
//function name: print_str
//
//description: print str of format until next '%' or next '\' or '\0'
//-----------------------------------------------------------------------------
int	print_str(const char *format, int i)
{
	char	*str;
	int start;

	start = i;
	while (format[i] && (format[i] != '%'))
		i++;
	str = ft_calloc(i-start, sizeof(char));
	ft_strlcpy(str, format + start, i+1-start );
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
//function name: process_str
//
//description: print str 
//-----------------------------------------------------------------------------
void	process_str(char *str)
{
	ft_putstr_fd(str, 1);
}

//-----------------------------------------------------------------------------
//function name: format_parse
//
//description: identify printf format
//-----------------------------------------------------------------------------
int	format_parse(const char *format, int i, va_list *ap)
{
	int format_int;
	char *format_str;

	i++;
	if(format[i] == 'd')
	{
		format_int = va_arg(*ap,int);
		process_int(format_int);
		i++;
	}
	if(format[i] == 's')
	{
		format_str = va_arg(*ap,char *);
		process_str(format_str);
		i++;
	}
	return (i);
}

//-----------------------------------------------------------------------------
//function name: countarg
//
//description: count number of '%' to know the number of ellistic arg
//-----------------------------------------------------------------------------
int	countarg(const char *format)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count++;
		i++;
	}
	printf("count %d",count);
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
	va_list	ap;

	i = 0;
	va_start(ap, format);
	str = ft_strdup(format);
//	countarg(format);
	while (str[i])
	{	
		if (str[i] == '%')
		{
			i = format_parse(format, i, &ap);
		}	
		else
		{
			i = print_str(str, i);
		}
	}
	free(str);
	va_end(ap);
	return (1);
}
