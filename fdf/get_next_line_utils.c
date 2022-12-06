/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:19:01 by ybensegh          #+#    #+#             */
/*   Updated: 2022/12/02 20:44:28 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_linelen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	return (++i);
}

int	checknl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*cleanbuf(char *readbuf, char *line)
{
	int		linelen;
	int		leftlen;
	char	*bufcleaned;
	int		i;

	i = 0;
	linelen = ft_linelen(line);
	leftlen = ft_strlen(readbuf) - linelen;
	bufcleaned = malloc((leftlen + BUFFER_SIZE + 1) * sizeof(char));
	if (!bufcleaned)
		return (NULL);
	while (readbuf[linelen - 1 + i] && i < BUFFER_SIZE + leftlen)
	{
		bufcleaned[i] = readbuf[linelen + i];
		i++;
	}
	bufcleaned[i] = 0;
	free(readbuf);
	return (bufcleaned);
}

char	*extract_line(char *readbuf)
{
	int		i;
	char	*newline;

	i = 0;
	newline = malloc((ft_linelen(readbuf) + 1) * sizeof(char));
	while (readbuf[i] && i < ft_linelen(readbuf))
	{
		newline[i] = readbuf[i];
		i++;
	}
	newline[i] = 0;
	return (newline);
}
