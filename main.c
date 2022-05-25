#include <mlx.h>

enum	{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef	struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/*void	add_shade(double dst, int color)
{
	color = 0.5;
}*/

int		create_trgb(int t, int r, int g, int b)
{
	return	(t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data	*data, int x, int y, int color)
{
	char	*dst;

	dst	=	data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst	= color;
}

void	my_mlx_line_put(t_data *data, int x, int y, int color)
{
	int		i;

	i = 0;
	while (i < 1000)
	{
		my_mlx_pixel_put(data, x + i++, y, color);
	}
}

int	main(void)
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img	= mlx_new_image(mlx, 1920, 1080);
	img.addr	= mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	my_mlx_line_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	/*
	** After creating an image, we can call 'mlx_get_data_addr', we pass
	** 'bits_per_pixel', `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	mlx_loop(mlx);
}
