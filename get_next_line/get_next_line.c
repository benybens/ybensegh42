/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinebenseghir <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:01:20 by yassinebenseg     #+#    #+#             */
/*   Updated: 2022/11/23 16:51:58 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <stdio.h>

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 1000
#endif

int line_len(char *buf)
{
	int i;

	i = 0;
	while(buf[i] !='\n' && buf[i])
		i++;
	return (i);
}



char	*extract_line(char *readbuf)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((line_len(readbuf) + 1) * sizeof(char));
	while(readbuf[i] !='\n' && readbuf[i])
	{
		str[i] = readbuf[i];
		i++;
	}
	if(readbuf[i] == '\n')
		str[i++] = '\n';
	str[i] = 0;
	return(str);
}

int	check_nl(char *buf)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if(buf[i] == '\n')
			return (1);
		i++;
	}
	return(0);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

void add_buffer(char *readbuf, char *fd_buffer)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(readbuf[i])
		i++;
	while(fd_buffer[j])
		readbuf[i++]=fd_buffer[j++];
}

int fill_buffer(int fd, char *readbuf)
{
	char 	*fd_buffer;
	int		rr;

	fd_buffer = malloc(BUFFER_SIZE *sizeof(char));
	rr = read(fd, fd_buffer, BUFFER_SIZE-(ft_strlen(readbuf)));
	if(rr == -1)
		return (-1);
	if(rr == 0)
		return (0);
	add_buffer(readbuf,fd_buffer);
	return(rr);
}

char *update_buffer(char *readbuf, int shift)
{
	char *new_buffer;
	int i;

	i = 0;
	new_buffer = malloc(BUFFER_SIZE * sizeof(char));
	while(readbuf[shift + i])
	{
		new_buffer[i] = readbuf[i+shift];
		i++;
	}
	free(readbuf);
	return (new_buffer);
}


char	*get_next_line(int fd)
{
	static char *readbuf;
	char		*line;
	
	readbuf = malloc(BUFFER_SIZE * sizeof(char));
	fill_buffer(fd,readbuf);
	line = extract_line(readbuf);
	readbuf = update_buffer(readbuf,ft_strlen(line));
	return (line);
}
