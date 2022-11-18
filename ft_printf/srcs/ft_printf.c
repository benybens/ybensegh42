/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:05:07 by ybensegh          #+#    #+#             */
/*   Updated: 2022/11/18 16:40:58 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//-----------------------------------------------------------------------------
//function name: print_str
//
//description: print str of format until next '%' or next '\' or '\0'
//-----------------------------------------------------------------------------
int	print_str(const char *format, int i, int * nbr_printed)
{
	char	*str;
	int start;

	start = i;
	while (format[i] && (format[i] != '%'))
	{
		i++;
		*nbr_printed = *nbr_printed + 1;
	}
	str = ft_calloc(i-start+1, sizeof(char));
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
int	process_int(int nbr)
{
	char	*itoa_nbr;
	int	intlen;

	itoa_nbr = ft_itoa(nbr);
	intlen = ft_strlen(itoa_nbr);
	ft_putstr_fd(itoa_nbr, 1);
	free(itoa_nbr);
	return (intlen);
	
}

//-----------------------------------------------------------------------------
//function name: process_int
//
//description: convert int in ascii and print
//-----------------------------------------------------------------------------
int	process_unsigned(int nbr)
{
	char	*itoa_nbr;
	int	intlen;
	unsigned int nbru;

	nbru = (unsigned int) nbr;
	itoa_nbr = ft_itoa_unsigned(nbru);
	intlen = ft_strlen(itoa_nbr);
	ft_putstr_fd(itoa_nbr, 1);
	free(itoa_nbr);
	return (intlen);
	
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

int	pointer_len(void * pointer)
{
	int i;
	unsigned long pointeradd;

	pointeradd = (unsigned long)pointer;
	i = 0;
	while(pointeradd > 16)
	{
		pointeradd /= 16;
		i++;
	}
	if(pointeradd > 0)
		i++;
	return(i);
}

char	ft_itoh(long nbr,int maj)
{
	char hex[16] ="0123456789abcdef";
	char hexM[16] = "0123456789ABCDEF";
	
	if(!maj)
		return(hex[nbr]);
	else
		return(hexM[nbr]);
}
//-----------------------------------------------------------------------------
//function name: process_str
//
//description: convert pointer value into str
//-----------------------------------------------------------------------------
char * ft_ptoa(void * pointer)
{
	char	*str;
	unsigned long	pointeradd;
	int	i;

	i = 0;
	pointeradd = (unsigned long)pointer;
	if(!pointeradd)
	{
		str = ft_calloc(2, sizeof(char));
		str[0] = '0';
		return(str);
	}
	if(pointeradd == (unsigned long)LONG_MIN)
		return(ft_strdup("8000000000000000"));
	if(pointeradd == ULONG_MAX)
		return(ft_strdup("ffffffffffffffff"));
	str = ft_calloc(pointer_len(pointer) + 1,sizeof(pointer));
	while(pointeradd >= 16)
	{
		str[i] = ft_itoh(pointeradd % 16,0);
		i++;
		pointeradd /= 16;
	}
	if (pointeradd > 0)
		str[i] = ft_itoh(pointeradd,0);
	return (ft_strrev(str));
}

//-----------------------------------------------------------------------------
//function name: process_str
//
//description: print str 
//-----------------------------------------------------------------------------
void	process_pointer(void * pointer, int * nbr_printed)
{
	char	*str;

	str = ft_ptoa(pointer);
	ft_putstr_fd(str, 1);
	*nbr_printed += ft_strlen(str);
	free(str);
}

int	hex_len(unsigned int hex)
{
	int i;

	i = 0;
	while(hex >= 16)
	{
		hex /= 16;
		i++;
	}
	if(hex > 0)
		i++;
	return(i);
}
//description: print str 
//-----------------------------------------------------------------------------
void	process_hex(unsigned int  hex_value, int * nbr_printed,int maj)
{
	char	*str;
	int	i;

	i = 0;
	if(!hex_value)
	{
		str = ft_calloc(2, sizeof(char));
		str[0] = '0';
		ft_putstr_fd(str, 1);
	}
	else
	{
		str = ft_calloc(hex_len(hex_value) + 1,sizeof(char));
		while(hex_value >= 16)
		{
			str[i] = ft_itoh(hex_value % 16,maj);
			i++;
			hex_value /= 16;
		}
		if (hex_value > 0)
			str[i] = ft_itoh(hex_value,maj);
	ft_putstr_fd(ft_strrev(str), 1);
	}
	*nbr_printed += ft_strlen(str);
	free(str);
}



//-----------------------------------------------------------------------------
//function name: process_str
//
//description: print char
//-----------------------------------------------------------------------------
void	process_char(char c, int * nbr_printed)
{
	char str[2];
	
	if (c)
	{
		str[0] = (unsigned char)c;
		str[1] = 0;
		*nbr_printed = *nbr_printed + 1;
		ft_putstr_fd(str, 1);
	}
	else
	{
		write(1,"",1);
		*nbr_printed = *nbr_printed + 1;
	}
}
//-----------------------------------------------------------------------------
//function name: format_parse
//
//description: identify printf format
//-----------------------------------------------------------------------------
int	format_parse(const char *format, int i, va_list *ap, int * nbr_printed)
{
	char *format_str;

	i++;
	if(format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
	{
		if(format[i] != 'u')
			*nbr_printed += process_int(va_arg(*ap,int));
		else
			*nbr_printed += process_unsigned(va_arg(*ap,int));
		i++;
	}
	else if(format[i] == 's')
	{
		format_str = va_arg(*ap,char *);
		if(format_str)
		{
			process_str(format_str);
			*nbr_printed += ft_strlen(format_str);
		}
		else
		{
			ft_putstr_fd("(null)",1);
			*nbr_printed += ft_strlen("(null)");
		}
		i++;
	}
	else if(format[i] == 'c')
	{
		process_char(va_arg(*ap,int),nbr_printed);
		i++;
	}
	else if(format[i] == '%')
	{
		ft_putstr_fd("%",1);
		*nbr_printed = *nbr_printed + 1;
		i++;
	}
	else if(format[i] == 'p')
	{
		ft_putstr_fd("0x",1);
		*nbr_printed = *nbr_printed + 2;
		process_pointer(va_arg(*ap,void *),nbr_printed);
		i++;
	}
	else if(format[i] == 'x')
	{
		process_hex(va_arg(*ap,int),nbr_printed,0);
		i++;
	}
	else if(format[i] == 'X')
	{
		process_hex(va_arg(*ap,int),nbr_printed,1);
		i++;
	}
	return (i);
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
	int len;
	int nbr_printed;

	i = 0;
	nbr_printed = 0;
	if (format == NULL)
		return (0);
	va_start(ap, format);
	str = ft_strdup(format);
	if (str==NULL)
		return (-1);
	len = ft_strlen(str);
//	countarg(format);
	while (i < len)
	{	
		if (str[i] == '%')
		{
			i = format_parse(format, i, &ap, &nbr_printed);
		}	
		else
		{
			i = print_str(str, i, &nbr_printed);
		}
	}
	free(str);
	va_end(ap);
	return (nbr_printed);
}
