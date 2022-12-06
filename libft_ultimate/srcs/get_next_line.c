/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinebenseghir <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:01:52 by yassinebenseg     #+#    #+#             */
/*   Updated: 2022/11/28 19:08:56 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*concat(char *readbuf, char *fdbuffer)
{
	int		readbuf_size;
	int		fdbuffer_size;
	int		i;
	int		j;
	char	*concat_str;

	i = 0;
	j = 0;
	readbuf_size = ft_strlen(readbuf);
	fdbuffer_size = ft_strlen(fdbuffer);
	concat_str = malloc ((readbuf_size + fdbuffer_size + 1) * sizeof(char));
	while (readbuf && readbuf[i])
	{
		concat_str[i] = readbuf[i];
		i++;
	}
	while (fdbuffer && fdbuffer[j])
		concat_str[i++] = fdbuffer[j++];
	concat_str[i] = 0;
	free(readbuf);
	free(fdbuffer);
	return (concat_str);
}

char	*get_from_fd(int fd, char *readbuf)
{
	char	*fdbuffer;
	int		rr;

	if (!readbuf)
	{
		readbuf = malloc(1 * sizeof(char));
		readbuf[0] = 0;
	}
	rr = 1;
	while (rr)
	{
		fdbuffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		rr = read(fd, fdbuffer, BUFFER_SIZE);
		fdbuffer[rr] = 0;
		if (rr == -1 || (rr == 0 && !readbuf[0]))
		{
			free(fdbuffer);
			free(readbuf);
			return (NULL);
		}
		readbuf = concat(readbuf, fdbuffer);
		if (checknl(readbuf))
			break ;
	}
	return (readbuf);
}

char	*get_next_line(int fd)
{
	static char	*readbuf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0 || read(fd, 0, 0) < 0)
	{
		free(readbuf);
		readbuf = NULL;
		return (NULL);
	}
	readbuf = get_from_fd(fd, readbuf);
	if (!readbuf)
		return (NULL);
	line = extract_line(readbuf);
	if (!line)
		return (NULL);
	readbuf = cleanbuf(readbuf, line);
	if (!readbuf)
		return (NULL);
	return (line);
}
