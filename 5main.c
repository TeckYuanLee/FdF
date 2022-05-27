#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data  data;
    t_grid	grid;
    t_transform transf;

	if (init_grid(&grid, argv[1]) == -1)
		return (2);
    if (argc == 2)
    {
	    init_window(&data, argv[1]);
	    init_transform(&transf);
	    output_grid(&data);
	    mlx_key_hook(data.win, key_hook, &data);
    }
    else
    {
        ft_putstr_fd("Please insert map\n", 2);
        return (1);
    }
	// mlx_loop required to display image changes
	mlx_loop(data.mlx);
	return (0);
}