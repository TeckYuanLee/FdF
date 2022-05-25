static void pixel_put(t_data *data, int x, int y, int color)
{
	int		i;
	char	*dst;

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