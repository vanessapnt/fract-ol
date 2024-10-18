#include "fractol.h"

// 2^2 + 2^2 = hypotenuse squared(4)
static void	data_init(t_fractal *fractal)
{
	fractal->hypothenuse = 4.0; 
	fractal->iterations_defintion = 50; 
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}
//establish the connection between key and function so it's used later with loop
void	init_events(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx_win_ptr, key_hook, fractal);
	mlx_key_hook(fractal->mlx_win_ptr, mouse_hook, fractal);
	mlx_hook(fractal->window, DestroyNotify, 0, end_fractol, fractal);
}

init_mlx(t_fractal *fractal)
{
    fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		ft_error();
	fractal->mlx_win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT,
			fractal->name);
	if (!fractal->mlx_win_ptr)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		ft_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_win_ptr);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		ft_error();
	}
	fractal->img.pix_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	init_events(fractal);
	data_init(fractal);
}
