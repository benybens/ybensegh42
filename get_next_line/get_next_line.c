/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinebenseghir <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:01:52 by yassinebenseg     #+#    #+#             */
/*   Updated: 2022/11/25 17:11:48 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 200
#endif 

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str && str[i])
		i++;
	return (i);
}

int ft_linelen(char *str)
{
	int i;

	i = 0;
	while(str && str[i] && str[i] != '\n')
		i++;
	return (++i);
}

char *concat(char *readbuf, char *fdbuffer)
{
	int readbuf_size;
	int fdbuffer_size;
	int i;
	int j;
	char *concat_str;
	
	i = 0;
	j = 0;
	readbuf_size = ft_strlen(readbuf);
	fdbuffer_size = ft_strlen(fdbuffer);
	concat_str = malloc ((readbuf_size + fdbuffer_size + 1) * sizeof(char));
	while(readbuf && readbuf[i])
	{
		concat_str[i] = readbuf[i];
		i++;
	}
	while(fdbuffer && fdbuffer[j])
		concat_str[i++] = fdbuffer[j++];
	concat_str[i] = 0;
	free(readbuf);
   	return(concat_str);	
}

int	checknl(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] == '\n')
			return (1);
		i++;
	}
	return(0);
}

char *get_from_fd(int fd, char *readbuf)
{
	char	*fdbuffer;
	int		rr;
	
	if(!readbuf)
	{
		readbuf = malloc(1 * sizeof(char));
		readbuf[0] = 0;
	}
	rr = 1;
	while(rr)
	{
		fdbuffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		rr = read(fd, fdbuffer, BUFFER_SIZE);
		fdbuffer[rr] = 0;
		if(rr == -1)
		{
			free(fdbuffer);
			free(readbuf);
			return(NULL);
		}
		if(rr == 0 && !readbuf[0])
		{
			free(fdbuffer);
			free(readbuf);
			return(NULL);
		}
		readbuf = concat(readbuf,fdbuffer);
		free(fdbuffer);
		if(checknl(readbuf))
			break;
	}
	return (readbuf);
}

char *extract_line(char *readbuf)
{
	int i;
	char *newline;

	i = 0;
	newline = malloc((ft_linelen(readbuf) + 1) * sizeof(char));
	while(readbuf[i] && i < ft_linelen(readbuf))
	{
		newline[i] = readbuf[i];
		i++;
	}
	newline[i] = 0;

	return(newline);
}

char *cleanbuf(char *readbuf, char *line)
{
	int linelen;
	char *bufcleaned;
	int i;

	i = 0;
	linelen = ft_linelen(line);
	bufcleaned = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while(readbuf[linelen +i])
	{
		bufcleaned[i] = readbuf[linelen + i];
		i++;
	}
	bufcleaned[i] = 0;
	free(readbuf);
	return (bufcleaned);
}

char *get_next_line(int fd)
{
	static char *readbuf;
	char *line;

	readbuf = get_from_fd(fd, readbuf);
	if(!readbuf)
		return(NULL);
	line = extract_line(readbuf);
	readbuf = cleanbuf(readbuf, line);
	return(line);
}
