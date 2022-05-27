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

void	clean_image(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->reso_h)
	{
		j = 0;
		while (j < img->reso_w)
		{
			my_mlx_pixel_put(img, j, i, 0x00000000);
			j++;
		}
		i++;
	}
}
