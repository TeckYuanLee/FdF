#ifndef FDF_H

# define FDF_H

# define HEIGHT     1080
# define WIDTH      1920
# define MENU_WIDTH 250
# define FT_UINT_MAX    ((unsigned)(~0L))
# define FT_INT_MAX ((int)(FT_UINT_MAX >> 1))
# define FT_INT_MIN ((int)(~FT_INT_MAX))

#include <stdlib.h>
#include <mlx.h>

typedef struct s_point
{
    int x;
    int y;
}              t_point;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}              t_data;

typedef struct s_map
{
    int     width;    
    int     height;
    int     *point_arr;
    int     *color_arr;
    int     z_min; /* what is 'z'?*/
    int     z_max; /* what is 'z'?*/
    int     z_range; /* what is 'z'?*/
}              t_map;

typedef struct s_grid
{
    t_point **grid;
    t_point **tmp_grid;
    int     box_length;
    int     row;
    int     col;
}              t_grid;

void pixel_put(t_data *data, int x, int y, int color);
static void	line_put_x(t_point a, t_point b, int color, t_data *data);
static void	line_put_y(t_point a, t_point b, int color, t_data *data);
void	line_put(t_point a, t_point b, int color, t_data *data);
int abs_int(int n);
float	abs_float(float n);
void    init_window(t_data *data/*, char *title*/);

#endif