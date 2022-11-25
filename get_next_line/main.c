/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinebenseghir <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:49:10 by yassinebenseg     #+#    #+#             */
/*   Updated: 2022/11/25 17:00:21 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"

int main (int argc, char ** argv)
{
	int fd;
	char *buf;

	(void)argv;
	if(argc!=2)
		printf("Error in arguments\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		while(1)
		{
			buf = get_next_line(fd);
			if(buf)
			{
				printf("New line --> %s", buf);
				free(buf);
			}
			else
				break;
		}
	}
		

	return (0);
}

