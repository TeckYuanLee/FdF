#include <mlx.h>
#include "fdf.h"


int	main(int argc, char **argv)
{
	t_data	img;
	t_grid	*grid = NULL;
	t_point	a;
	t_point	b;

	a.x = 800;
	a.y = 586;
	b.x = -1000;
	b.y = -356;

	if (argc == 2)
	{
		ft_putstr("yay\n");
	}
	init_window(&img/*, argv[1]*/);
	init_grid(grid, argv[1]);
	//line_put(a, b, 0x00FF0000, &img);
	grid_put(grid, &img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);

	mlx_loop(img.mlx);
}
