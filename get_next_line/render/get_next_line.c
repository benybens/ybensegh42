/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinebenseghir <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:01:20 by yassinebenseg     #+#    #+#             */
/*   Updated: 2022/11/23 10:31:17 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <stdio.h>

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 1000
#endif

int	check_nl(char *buf)
{
	int i;

	i = 0;
	while(buf[i])
	{
		if(buf[i] == '\n')
		{
			buf[i] = 0;
			return (1);
		}
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char *buf;
	int i;
	ssize_t rr;

	i = 0;
	buf = malloc(BUFFER_SIZE * sizeof(char));
	if(buf == NULL)
		return NULL;
	while(i < BUFFER_SIZE)
	{
		rr = read(fd, buf + i, 1);
		if (buf[i] == '\n')
			return (buf);
		i++;
		if(rr == -1)
		{
			free(buf);
			return NULL;
		}
		if(rr == 0)
		{
			if(buf[0] == 0)
			{
				free(buf);
				return(NULL);
			}
			else
				return(buf);
		}
	}
	return (NULL);
}
