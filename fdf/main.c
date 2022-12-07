/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinebenseghir <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:57:39 by yassinebenseg     #+#    #+#             */
/*   Updated: 2022/12/07 17:10:10 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/mlx.h"
#include "./includes/libft.h"


int	deal_key(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	ft_printf("Key event\n");
	return (1);
}

void	parse_map(t_list **ptr_line_lst, int fd)
{
	t_list *line_lst;
	int		continue_reading;

	continue_reading = 1;
	while(continue_reading)
	{
		line_lst = ft_lstnew(get_next_line(fd));
		if(line_lst->content == NULL)
			continue_reading = 0;
		ft_lstadd_back(ptr_line_lst, (void *)line_lst); 
	}
}

void	print_map(t_list **ptr_line_list)
{	
	char *line;
	t_list *next_line;

	next_line = ptr_line_list[0];
	line = next_line->content;
	while(line)
	{
		ft_printf("%s",line);
		next_line = next_line->next;
		line = next_line->content;
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
	ptr_line_lst = &line_lst;
	parse_map(ptr_line_lst,fd);
	print_map(ptr_line_lst);
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
