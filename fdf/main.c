/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinebenseghir <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:57:39 by yassinebenseg     #+#    #+#             */
/*   Updated: 2022/12/01 11:15:05 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "get_next_line.h"
#include "ft_printf.h"


int	deal_key(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	ft_printf("Key event\n");
	return (1);
}

void	parse_map(t_list **ptr_line_lst, int fd)
{
	int		i;
	t_list	*next_lst;
	char	*new_line;

	i = 0;
	while()
	{
		new_line = get_next_line();
		ft_lstadd_back(ptr_line_lst, (void *)new_line); 
	}
}

int	main(int argc, char **argv)
{
	void *mlx_ptr;
	void *win_ptr;
	int i;
	t_list *line_lst;
	t_list **ptr_line_lst;
	int fd;

	(void) argv;
	if (argc != 2)
	{
		ft_printf("Please run : ./fdf 'map_path'\n");
		return (0);
	}
	ft_printf("Start fdf\n");
	fd = open(argv[1],O_RDONLY);
	line_lst = ft_lstnew(get_next_line(fd));
	*ptr_line_lst = line_lst;
	parse_map(ptr_line_lst,fd);



	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Fdf window");
	i = 0;
	while (i < 500)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 250, i,0x43C0A3);
		i++;
	}
	mlx_key_hook(win_ptr,deal_key,(void *)0);
	mlx_loop(mlx_ptr);
}
