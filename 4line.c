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
    // not sure what is the use of 'p' yet
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
    // not sure what is the use of 'p' yet
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

void	line_put(t_point a, t_point b, int color, t_data *data)
{
	int		temp;
	float	grad;

	if (b.x - a.x == 0)
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

void	gridline_put(t_grid *grid, t_data *data, int color)
{
	int	    i;
	int	    j;
	t_point	**g;

	g = grid->tmp_grid;
	i = -1;
	while (++i < grid->row)
	{
		j = -1;
		while (++j < grid->col)
		{
			if (i != (grid->row -1))
				line_put(g[i][j], g[i + 1][j], color, data);
			if (j != (grid->col - 1))
				line_put(g[i][j], g[i][j + 1], color, data);
		}
	}
}