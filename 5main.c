/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:42:20 by telee             #+#    #+#             */
/*   Updated: 2022/05/27 19:42:20 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_grid		grid;
	t_transform	transf;
	int			a;
	int			b;

	if (argc == 2)
	{
		if (init_grid(&grid, argv[1]) == -1)
			return (2);
		init_window(&data, argv[1]);
		init_transform(&transf);
		grid_put(&grid, &data, &transf);
		a = mlx_key_hook(data.win, key_hook, &data);
		b = mlx_hook(data.win, 17, 1L << 1, exit_win, &data);
		if (a == 3 || b == 17)
		{
			printf("looool\n");
			grid_free(grid.grid, grid.row);
			grid_free(grid.tmp_grid, grid.row);
		}
	}
	else
	{
		ft_putstr_fd("Please insert map\n", 1);
		return (1);
	}
	mlx_loop(data.mlx);
	return (0);
}
