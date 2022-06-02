/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:26:18 by telee             #+#    #+#             */
/*   Updated: 2022/06/02 13:26:18 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	grid_build(int fd, t_grid *grid)
{
	char	*tmp;

	grid->row = 0;
	grid->col = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		(grid->row)++;
		if (check_map(tmp, grid) == -1)
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
	}
	grid_size(grid);
	return (0);
}

int	init_grid(t_grid *grid, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("File error.\n", 2);
		system("leaks fdf");
		return (-1);
	}
	if (grid_build(fd, grid) == -1)
	{
		ft_putstr_fd("Map error.\n", 2);
		system("leaks fdf");
		return (-1);
	}
	close(fd);
	grid_plot(grid);
	get_z(grid, file);
	return (0);
}

void	init_window(t_data *data, char *title)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, title);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

void	init_transform(t_transform *transf)
{
	transf->rotate.x = 0;//9;
	transf->rotate.y = 0;//10;
	transf->rotate.z = 0;//90;
	transf->zoom = 0.4;
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_grid		grid;
	t_transform	transf;

	if (argc == 2)
	{
		if (init_grid(&grid, argv[1]) == -1)
			return (2);
		init_window(&data, argv[1]);
		init_transform(&transf);
		grid_put(&grid, &data, &transf);
		grid.grid = free_grid(grid.grid, grid.row);
		mlx_key_hook(data.win, key_hook, &data);
		mlx_hook(data.win, ON_DESTROY, 1L << 1, exit_win, &data);
	}
	else
	{
		ft_putstr_fd("Please insert map\n", 2);
		return (1);
	}
	mlx_loop(data.mlx);
	return (0);
}
