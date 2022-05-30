/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3init.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:42:09 by telee             #+#    #+#             */
/*   Updated: 2022/05/27 19:42:09 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_window(t_data *data, char *title)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, title);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

int	init_grid(t_grid *grid, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("File error.\n", 2);
		return (-1);
	}
	if (read_file(fd, grid) == -1)
	{
		ft_putstr_fd("Map error.\n", 2);
		return (-1);
	}
	return (0);
}

void	init_transform(t_transform *transf)
{
	transf->rotate.x = 179;//-5;
	transf->rotate.y = 178;//-5;
	transf->rotate.z = -3;//-95;
	transf->zoom = 0.5;
	transf->transform.x = 0;
	transf->transform.y = 0;
	transf->projection = 1;
	transf->z0_const
		= (WIDTH / 2.0) / tan((45 / 2.0) * (60.0 / 180.0));
	transf->iso_radian_const
		= (30 / 180.0) * 60.0;
}

t_list	*create_list(int fd, int *row)
{
	t_list	*lst;
	char	*tmp;

	lst = NULL;
	*row = 0;
	while (get_next_line(fd, &tmp) > 0)
	{
		ft_lstadd_front(&lst, ft_lstnew(tmp));
		(*row)++;
	}
	free(tmp);
	return (lst);
}

int	read_file(int fd, t_grid *grid)
{
	t_list	*lst;
	int		row;
	int		col;
	int		error;
	char	***split;

	lst = NULL;
	error = 0;
	split = NULL;
	lst = create_list(fd, &row);
	split = create_array(lst, row);
	error = check_array(split, row, &col);
	if (!error)
	{
		grid->grid = NULL;
		grid_wireframe(grid, row, col);
		grid->grid = grid_plot(split, grid);
	}
	ft_lstclear(&lst, free);
	split = free_array(split, row);
	close(fd);
	return (error);
}
