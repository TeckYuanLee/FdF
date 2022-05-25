#include <mlx.h>
#include <stdio.h>

typedef struct s_vars {
    void    *mlx;
    void    *win;
}               t_vars;

//int render_next_frame(void *YourStruct);

int mouse_hook(int keycode, t_vars *vars)
{
    printf("Hello from key_hook!\n");
    return (0);
}

/*int close(int keycode, t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    return (0);
}*/

int main()
{
    t_vars  vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
    //mlx_hook(vars.win, 2, 1L<<0, close, &vars);
    //mlx_key_hook(vars.win, key_hook, &vars);
    mlx_mouse_hook(vars.win, mouse_hook, &vars);
    mlx_loop_hook(vars.mlx, render_next_frame, &vars);
    mlx_loop(vars.mlx);
}