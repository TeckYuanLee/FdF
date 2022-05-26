#include "fdf.h"

t_map   *init_map(void)
{
    t_map   *map;

    map = malloc(sizeof(t_map));
    if (!map)
        exit (1);
    map->width = 0;
    map->height = 0;
    map->point_arr = NULL;
    map->color_arr = NULL;
    map->z_min = FT_INT_MAX;
    map->z_max = FT_INT_MIN;
    map->z_range = 0;
    return (map);
}

/*_data  *init_data(t_map *map)
{
    t_data  *data;


}*/

void    init_window(t_data *data/*, char *title*/)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Hellooooooo");
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->addr  = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
}