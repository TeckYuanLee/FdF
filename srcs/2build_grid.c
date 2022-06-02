/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2build_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:26:37 by telee             #+#    #+#             */
/*   Updated: 2022/06/02 13:26:37 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	grid_size(t_grid *grid)
{
	int	max_width;
	int	max_height;

	max_width = WIDTH / (grid->col);
	max_height = HEIGHT / (grid->row);
	if (max_width > max_height)
		grid->grid_size = max_width;
	else
		grid->grid_size = max_height;
}

int	check_map(char *split, t_grid *grid)
{
	int		i;
	char	**lol;

	lol = ft_split(split, ' ');
	if (grid->col == 0)
	{
		i = 0;
		while (lol[i])
		{
			(grid->col)++;
			i++;
		}
	}
	i = 0;
	while (lol[i])
		i++;
	free_array(lol);
	if (grid->row == 0 || grid->col == 0)
		return (-1);
	if (i != grid->col)
		return (-1);
	return (0);
}

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
	int		fd;
	char	*tmp;
	char	**lol;
	int		i;
	int		j;

	fd = open(file, O_RDONLY);
	i = -1;
	while (++i < grid->row)
	{
		tmp = get_next_line(fd);
		if (tmp != NULL)
		{
			lol = ft_split(tmp, ' ');
			free(tmp);
		}
		j = -1;
		while (++j < grid->col)
		{
			grid->grid[i][j].z = -(ft_atoi(lol[j]))
				* (grid->grid_size) * Z_ELVTD;
		}
		free_array(lol);
	}
	close(fd);
}
