/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1cleaner.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:41:45 by telee             #+#    #+#             */
/*   Updated: 2022/05/27 19:41:45 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	**free_grid(t_point **grid, int row)
{
	int	i;

	i = 0;
	while (i < row)
		free(grid[i++]);
	free(grid);
	return (NULL);
}

void	free_array(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = 0;
		i++;
	}
	free(split);
	split = 0;
}

int	exit_win(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	system("leaks fdf");
	exit(0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		free(data->mlx);
		system("leaks fdf");
		exit(0);
		return (0);
	}
	return (-1);
}
