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

int	check_map(char *split, t_grid *grid)
{
	int	i;
	int	j;
	char	**lol;

	lol = ft_split(split, ' ');
	printf("lol %p split %p\n", lol, split);
	i = 0;
	while (lol[i])
	{
		printf("%s %d\n", lol[i], i);
		i++;
	}
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
	j = 0;
	while (lol[i])
	{
		j++;
		i++;
	}
	printf("%d  %d  %d\n", j, grid->row, grid->col);
	free_array(lol);
	if (grid->row == 0 || grid->col == 0)
		return (-1);
	if (j != grid->col)
		return (-1);
	return (0);
}

int	grid_size(int fd, t_grid *grid)
{
	char	*tmp;
	int	max_width;
	int	max_height;

	grid->row = 0;
	grid->col = 0;
	tmp = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		printf("%p\n", tmp);
		if (tmp == NULL)
		{
			free(tmp);
			break ;
		}
		(grid->row)++;
		//printf("%s\n", tmp);
		if (check_map(tmp, grid) == -1)
		{
			free(tmp);
			close(fd);
			return (-1);
		}
		printf("here\n");
		free(tmp);
		tmp = 0;
	}
	free(tmp);
	tmp = 0;
	max_width = WIDTH / (grid->col);
	max_height = HEIGHT / (grid->row);
	if (max_width > max_height)
		grid->grid_size = max_width;
	else
		grid->grid_size = max_height;
	close(fd);
	return (0);
}


// int	main()
// {
// 	char *line;

// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		printf("%s\n", line);
// 	}
// }