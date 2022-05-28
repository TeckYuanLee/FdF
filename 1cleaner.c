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

#include "fdf.h"

t_point	**grid_free(t_point **grid, int row)
{
	int	i;

	i = 0;
	while (i < row)
		free(grid[i++]);
	free(grid);
	return (NULL);
}

char	***free_array(char ***split, int row)
{
	int	i;
	int	j;

	i = -1;
	while (++i < row)
	{
		j = -1;
		while (split[i][++j])
			free(split[i][j]);
		free(split[i]);
	}
	free(split);
	return (NULL);
}

void	clean_image(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			pixel_put(data, j, i, 0x00000000);
	}
}
