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
		free(tmp);
		tmp = NULL;
	}
	free(tmp);
	return (lst);
}

char	***create_array(t_list *lst, int row)
{
	char	***split;
	int		i;

	split = malloc(sizeof(char **) * (row + 1));
	if (!split)
		return (NULL);
	i = row;// - 1;
	split[i--] = 0;
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

int	grid_build(int fd, t_grid *grid)
{
	t_list	*lst;
	int		error;
	char	***split;

	lst = NULL;
	error = 0;
	split = NULL;
	lst = get_list(fd, &grid->row);
	split = create_array(lst, grid->row);
	error = check_array(split, grid->row, &grid->col);
	if (!error)
	{
		grid_size(grid, grid->row, grid->col);
		grid_plot(split, grid);
	}
	ft_lstclear(&lst, free);
	//printf("%s\n", split[2][2]);
	//printf("%p\n", split[2][2]);
	split = free_array(split, grid->row, grid->col);
	//printf("%s\n", split[0][0]);
	//printf("%s\n", split[2][2]);
	//free(split);
	close(fd);
	return (error);
}
