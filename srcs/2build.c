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

char	***create_array(int fd, int *row, char *file)
{
	char	*tmp;
	char	***split;
	int i;

	*row = 0;
	while (get_next_line(fd, &tmp) > 0)
		(*row)++;
	free(tmp);
	// close(fd);
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
	return (split);
}

int	check_array(char ***split, int row, int *col)
{
	int	i;
	int	tmp_col;

	*col = 0;
	while (split && split[0][*col])
		(*col)++;
	if (row == 0 || *col == 0)
		return (-1);
	i = -1;
	while (++i < row)
	{
		tmp_col = 0;
		while (split[i][tmp_col])
			tmp_col++;
		if (tmp_col != *col)
			return (-1);
	}
	return (0);
}

int	grid_build(int fd, t_grid *grid, char *file)
{
	int		error;
	char	***split;

	error = 0;
	split = create_array(fd, &grid->row, file);
	error = check_array(split, grid->row, &grid->col);
	if (!error)
	{
		grid_size(grid, grid->row, grid->col);
		grid_plot(split, grid);
	}
	split = free_array(split, grid->row, grid->col);
	close(fd);
	return (error);
}
