/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:42:31 by telee             #+#    #+#             */
/*   Updated: 2022/05/27 19:42:31 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	abs_int(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

float	abs_float(float n)
{
	if (n < 0.0)
		return (-n);
	return (n);
}

int	check_array(char ***split, int row, int *col)
{
	int	arr_len;
	int	i;
	int	count_tmp;

	*col = 0;
	arr_len = 0;
	while (split && split[0][arr_len])
		arr_len++;
	i = -1;
	while (++i < row)
	{
		count_tmp = 0;
		while (split[i][count_tmp])
			count_tmp++;
		if (count_tmp != arr_len)
			return (-1);
	}
	*col = arr_len;
	if (row == 0 || *col == 0)
		return (-1);
	return (0);
}
