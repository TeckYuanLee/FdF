#include "fdf.h"

void	grid_put(t_data *data)
{
	clean_image(&data->img);
	copy_grid(&data->grid);
	apply_transformation(&data->grid, &data->tform);
	print_grid_line(&data->grid, &data->img, HEX_COLOR);
	mlx_put_image_to_window(data->win.mlx,
		data->win.window, data->img.img, 0, 0);
}