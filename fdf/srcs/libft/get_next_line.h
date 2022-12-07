/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinebenseghir <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:56:27 by yassinebenseg     #+#    #+#             */
/*   Updated: 2022/12/07 16:21:26 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif 

char	*get_next_line(int fd);
int		ft_linelen(char *str);
int		checknl(char *str);
char	*get_from_fd(int fd, char *readbuf);
char	*concat(char *readbuf, char *fdbuffer);
char	*cleanbuf(char *readbuf, char *line);
char	*extract_line(char *readbuf);

#endif
