/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinebenseghir <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:01:20 by yassinebenseg     #+#    #+#             */
/*   Updated: 2022/11/22 16:34:56 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <stdio.h>

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 1000
#endif

char	*get_next_line(int fd)
{
	char *buf;
	int i;
	ssize_t rr;

	i = 0;
	buf = malloc(BUFFER_SIZE * sizeof(char));
	if(buf == NULL)
		return NULL;
	rr = read(fd, buf + i, 1);
	if (rr == -1 || rr == 0)
	{
		free(buf);
		return(NULL);
	}
	i++;
	while(rr > 0)
	{
		rr = read(fd, buf + i, 1);
		if(buf[i] == '\n')
		   break;	
		i++;
	}
	if (rr == -1)
	{
		free(buf);
		return(NULL);
	}

	return (buf);
}
