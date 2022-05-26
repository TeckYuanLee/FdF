#include <mlx.h>
#include "fdf.h"


int	main(void)
{
	t_data	img;
	t_point	a;
	t_point	b;

	a.x = 800;
	a.y = 586;
	b.x = -1000;
	b.y = -356;

	init_window(&img/*, argv[1]*/);
	line_put(a, b, 0x00FF0000, &img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);

	mlx_loop(img.mlx);
}
