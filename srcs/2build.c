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

#include "../includes/fdf.h"

void	create_array(int fd, int *row, int *col, t_grid *grid)
{
	char	*tmp;
	int	max_width;
	int	max_height;

	*row = 0;
	*col = 0;
	while (get_next_line(fd, &tmp) > 0)
		(*row)++;
	while (tmp)
	{
		(*col)++;
	}
	max_width = WIDTH / (*col);
	max_height = HEIGHT / (*row);
	if (max_width > max_height)
		grid->grid_size = max_width;
	else
		grid->grid_size = max_height;
	free(tmp);
	close(fd);
	// fd = open(file, O_RDONLY);
	// split = malloc(sizeof(char **) * ((*row) + 1));
	// printf("%d\n", (*row));
	// if (!split)
	// 	return (NULL);
	// i = 0;
	// while (get_next_line(fd, &tmp) > 0)
	// {
	// 	split[i] = ft_split(tmp, ' ');
	// 	i++;
	// }
	// free(tmp);
}

// int	check_array(char ***split, int row, int *col)
// {
// 	int	i;
// 	int	tmp_col;

// 	*col = 0;
// 	while (split && split[0][*col])
// 		(*col)++;
// 	if (row == 0 || *col == 0)
// 		return (-1);
// 	i = -1;
// 	while (++i < row)
// 	{
// 		tmp_col = 0;
// 		while (split[i][tmp_col])
// 			tmp_col++;
// 		if (tmp_col != *col)
// 			return (-1);
// 	}
// 	return (0);
// }

int	grid_build(int fd, t_grid *grid, char *file)
{
	//int		error;
	//char	***split;

	//error = 0;
	create_array(fd, &grid->row, &grid->col, grid);
	//error = check_array(split, grid->row, &grid->col);
	if (!error)
	{
		grid_size(grid, grid->row, grid->col);
		grid_plot(split, grid, file);
	}
	split = free_array(split, grid->row, grid->col);
	//close(fd);
	return (error);
}
