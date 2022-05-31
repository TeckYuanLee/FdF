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

t_list	*get_list(int fd, int *row)
{
	t_list	*lst;
	char	*tmp;

	lst = NULL;
	*row = 0;
	while (get_next_line(fd, &tmp) > 0)
	{
		ft_lstadd_front(&lst, ft_lstnew(tmp));
		(*row)++;
	}
	free(tmp);
	return (lst);
}

char	***create_array(t_list *lst, int row)
{
	char	***split;
	int		i;

	split = malloc(sizeof(char **) * row);
	if (!split)
		return (NULL);
	i = row - 1;
	while (i >= 0)
	{
		split[i--] = ft_split((char *)(lst->content), ' ');
		lst = lst->next;
	}
	return (split);
}

int	check_array(char ***split, int row, int *col)
{
	int	i;
	int	count_tmp;

	*col = 0;
	while (split && split[0][*col])
		(*col)++;
	if (row == 0 || *col == 0)
		return (-1);
	i = -1;
	while (++i < row)
	{
		count_tmp = 0;
		while (split[i][count_tmp])
			count_tmp++;
		if (count_tmp != *col)
			return (-1);
	}
	return (0);
}

int	grid_build(int fd, t_grid *grid)
{
	t_list	*lst;
	int		row;
	int		col;
	int		error;
	char	***split;

	lst = NULL;
	error = 0;
	split = NULL;
	lst = get_list(fd, &row);
	split = create_array(lst, row);
	error = check_array(split, row, &col);
	if (!error)
	{
		grid->grid = NULL;
		grid_wireframe(grid, row, col);
		grid->grid = grid_plot(split, grid);
	}
	ft_lstclear(&lst, free);
	split = free_array(split, row);
	close(fd);
	return (error);
}
