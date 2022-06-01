/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2grid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:42:04 by telee             #+#    #+#             */
/*   Updated: 2022/05/27 19:42:04 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	**grid_alloc(int row, int col)
{
	t_point	**tmp;
	int		i;

	tmp = malloc(sizeof(t_point *) * row);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < row)
	{
		tmp[i] = malloc(sizeof(t_point) * col);
		//printf("%p\n", tmp[i]);
		i++;
	}
	return (tmp);
}

void	grid_plot(t_grid *grid)
{
	int		i;
	int		j;
	int		x;
	int		y;

	grid->grid = grid_alloc(grid->row, grid->col);
	x = -(grid->grid_size * (grid->col - 1) / 2);
	y = (grid->grid_size * (grid->row - 1) / 2);
	i = -1;
	while (++i < grid->row)
	{
		j = -1;
		while (++j < grid->col)
		{
			grid->grid[i][j].x = x + (j * grid->grid_size);
			grid->grid[i][j].y = y - (i * grid->grid_size);
		}
	}
}

void	get_z(t_grid *grid, char *file)
{
	int fd;
	char	*tmp;
	char	**lol;
	int	i;
	int	j;

	fd = open(file, O_RDONLY);
	i = -1;
	while (++i < grid->row)
	{
		if (get_next_line(fd, &tmp) > 0)
		{
			lol = ft_split(tmp, ' ');
			free(tmp);
		}
		j = -1;
		while (++j < grid->col)
		{
			grid->grid[i][j].z = -(ft_atoi(lol[j])) * (grid->grid_size) * Z_ELVTD;
		}
		free_array(lol);
		lol = 0;
	}
	close(fd);
}

void	grid_put(t_grid *grid, t_data *data, t_transform *transf)
{
	transform(grid, transf);
	gridline_put(grid, data, 0x0000FF00);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
