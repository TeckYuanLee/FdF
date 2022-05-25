#include <mlx.h>

int main()
{
    void    *mlx;
    void    *img;
    char    *relative_path = "./download.png";
    int     img_width;
    int     img_height;

    mlx = mlx_init();
    img = mlx_png_file_to_image(mlx, relative_path, &img_width, &img_height);
}