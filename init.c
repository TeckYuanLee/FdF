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

char    ***free_char_arr(char ***split, int row)
{
    int    i;
    int    j;

    i = 0;
    while (i < row)
    {
        j = 0;
        while (split[i][j])
        {
            free(split[i][j]);
            j++;
        }
        free(split[i]);
        i++;
    }
    free(split);
    return (NULL);
}

char     ***make_char_arr(t_list *lst, int row)
{
    char    ***split;
    int        i;

    split = malloc(sizeof(char ) * row);
    i = row - 1;
    while (i >= 0)
    {
        split[i] = ft_split((char *)(lst->content), ' ');
        lst = lst->next;
        i--;
    }
    return (split);
}

t_list    *make_list(int fd, int *row)
{
    char    *tmp;
    t_list    *lst;

    lst = NULL;
    row = 0;
    while (get_next_line(fd, &tmp) > 0)
    {
        ft_lstadd_front(&lst, ft_lstnew(tmp));
        (row)++;
    }
    // TO FREE - final char tmp which has NULL in first index, but still occupies memory
    free(tmp);
    return (lst);
}

void    init_window(t_data *data/*, char *title*/)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Hellooooooo");
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->addr  = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
}

int read_file(int fd, t_grid *grid)
{
    t_list  *lst;
    int     row;
    int     col;
    char    ***split;
    int     err;

    err = 0;
    lst = NULL;
    row = 0;
    lst = make_list(fd, &row);
    split = NULL;
    split = make_char_arr(lst, row);
    if (check_array(split, row, &col) == -1)
        err = -1;
    else
    {
        grid->grid = NULL;
        update_tgrid(grid, row, col);
        grid->grid = make_grid(split, grid);
    }
    ft_lstclear(&lst, free);
    split = free_char_arr(split, row);
    close(fd);
    return (err);    
}

int     init_grid(t_grid *grid, char *file)
{
    int     fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        ft_putstr_fd("File error.\n", 2);
        return (-1);
    }
    if (read_file(fd, grid) == -1)
    {
        ft_putstr_fd("Map error.\n", 2);
        return (-1);
    }
    return (0);
}
