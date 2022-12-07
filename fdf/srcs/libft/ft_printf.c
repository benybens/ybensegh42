/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:05:07 by ybensegh          #+#    #+#             */
/*   Updated: 2022/12/07 16:24:44 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//-----------------------------------------------------------------------------
//function name: ft_printf
//
//description: mimic printf
//-----------------------------------------------------------------------------

int	ft_printf(const char *format, ...)
{
	char	*str;
	int		i;
	va_list	ap;
	int		len;
	int		nbr_printed;

	i = 0;
	nbr_printed = 0;
	if (format == NULL)
		return (0);
	va_start(ap, format);
	str = ft_strdup(format);
	if (str == NULL)
		return (-1);
	len = ft_strlen(str);
	while (i < len)
	{	
		if (str[i] == '%')
			i = format_parse(format, i, &ap, &nbr_printed);
		else
			i = print_str(str, i, &nbr_printed);
	}
	free(str);
	va_end(ap);
	return (nbr_printed);
}
