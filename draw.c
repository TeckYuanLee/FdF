#include "fdf.h"

void pixel_put(t_data *data, int x, int y, int color)
{
	int		i;
	//char	*dst;

    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * data->bits_per_pixel / 8) + (y * data->line_length);
		//*(unsigned int*)dst = color;
		data->addr[i] = color;
		data->addr[++i] = color >> 8;
		data->addr[++i] = color >> 16;
	}
}

static void	line_put_x(t_point a, t_point b, int color, t_data *data)
{
	int			x;
	int			y;
	int			p;
	const int	dx = abs_int(b.x - a.x);
	const int	dy = abs_int(b.y - a.y);

	x = a.x;
	y = a.y;
	//not sure what is the use of 'p' yet
	p = 2 * dy - dx;
	while (x <= b.x)
	{
		pixel_put(data, x, y, color);
		x++;
		if (p < 0)
			p += (2 * dy);
		else
		{
			p += (2 * dy) - (2 * dx);
			if (b.y - a.y > 0)
				y++;
			else
				y--;
		}
	}
}

static void	line_put_y(t_point a, t_point b, int color, t_data *data)
{
	int			x;
	int			y;
	int			p;
	const int	dx = abs_int(b.x - a.x);
	const int	dy = abs_int(b.y - a.y);

	x = a.x;
	y = a.y;
	p = 2 * dx - dy;
	while (y <= b.y)
	{
		pixel_put(data, x, y, color);
		y++;
		if (p < 0)
			p += (2 * dx);
		else
		{
			p += (2 * dx) - (2 * dy);
			if (b.x - a.x > 0)
				x++;
			else
				x--;
		}
	}
}

int		abs_int(int n)
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

void	line_put(t_point a, t_point b, int color, t_data *data)
{
	int		temp;
	float	grad;

	if (b.x - a.x ==0)
		grad = (b.y - a.y);
	else
		grad = (b.y - a.y) / (float)(b.x - a.x);

	if ((b.x < a.x && abs_float(grad) <= 1.0) || (b.y < a.y && abs_float(grad) > 1.0))
	{
		temp = a.x;
		a.x = b.x;
		b.x = temp;
		temp = a.y;
		a.y = b.y;
		b.y = temp;
	}
	if (grad >= -1 && grad <= 1)
		line_put_x(a, b, color, data);
	else
		line_put_y(a, b, color, data);
}

void	grid_copy(t_grid *grid)
{
	int		i;
	int		j;

	i = 0;
	while (i < grid->row)
	{
		j = 0;
		while (j < grid->col)
		{
			grid->tmp_grid[i][j].x = grid->grid[i][j].x;
			grid->tmp_grid[i][j].y = grid->grid[i][j].y;
			//grid->tmp_grid[i][j].z = grid->grid[i][j].z;
			j++;
		}
		i++;
	}
}

void	gridline_put(t_grid *grid, t_data *data, int color)
{
	int	i;
	int	j;
	t_point	**g;

	g = grid->tmp_grid;
	i = 0;
	while (i < grid->row)
	{
		j = 0;
		while (j < grid->col)
		{
			if (i != (grid->row -1))
				line_put(g[i][j], g[i + 1][j], color, data);
			if (j != (grid->col - 1))
				line_put(g[i][j], g[i][j + 1], color, data);
			j++;
		}
		i++;
	}
}

void	grid_put(t_grid *grid, t_data *data)
{
	grid_copy(grid);
	gridline_put(grid, data->img, 0x00FF0000);
}

int		check_array(char ***split, int row, int *col)
{
	int		arr_len;
	int		i;
	int		count_tmp;

	*col = 0;
	arr_len = 0;
	while (split && split[0][arr_len])
		arr_len++;
	i = 0;
	while (i < row)
	{
		count_tmp = 0;
		while (split[i][count_tmp])
			count_tmp++;
		if (count_tmp != arr_len)
			return (-1);
		i++;
	}
	*col = arr_len;
	if (row == 0 || *col == 0)
		return (-1);
	return (0);
}

t_point	**alloc_grid(int row, int col)
{
	t_point	**tmp;
	int		i;

	tmp = malloc(sizeof(t_point *) * row);
	i = 0;
	while (i < row)
	{
		tmp[i] = malloc(sizeof(t_point) * col);
		i++;
	}
	return (tmp);
}

t_point	**make_grid(char ***split, t_grid *grid)
{
	int		i;
	int		j;
	t_point	**tmp;
	int		start_x;
	int		start_y;

	if (!split)
		return (NULL);
	tmp = alloc_grid(grid->row, grid->col);
	i = 0;
	start_x = -(grid->box_length * (grid->col - 1) / 2);
	start_y = (grid->box_length * (grid->row - 1) / 2);
	while (i < grid->row)
	{
		j = 0;
		while (j < grid->col)
		{
			tmp[i][j].x = start_x + (j * grid->box_length);
			tmp[i][j].y = start_y - (i * grid->box_length);
			j++;
		}
		i++;
	}
	return (tmp);
}

void	update_tgrid(t_grid *grid, int row, int col)
{
	int		max_box_width;
	int		max_box_height;

	grid->col = col;
	grid->row = row;
	max_box_width = (WIDTH * WIN_FIT) / col;
	max_box_height = (HEIGHT * WIN_FIT) / row;
	if (max_box_width > max_box_height)
		grid->box_length = max_box_width;
	else
		grid->box_length = max_box_height;
	grid->tmp_grid = alloc_grid(row, col);
}