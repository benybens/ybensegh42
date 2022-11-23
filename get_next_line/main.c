/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinebenseghir <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:49:10 by yassinebenseg     #+#    #+#             */
/*   Updated: 2022/11/23 10:21:52 by yassinebenseg    ###   ########.fr       */
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
			printf("\nNew Line : \n");
			buf = get_next_line(fd);
			if(buf)
			{
				printf("%s", buf);
				buf[0] = 0;
			}
			else
				break;
		}
	}
		

	return (0);
}

