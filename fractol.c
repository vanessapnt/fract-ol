#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal fractal;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10) || argc == 4
		&& !ft_strncmp(argv[1], "julia", 5))
	{
		fractal.isjulia = false;
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			fractal.isjulia = true;
			fractal.julia_x = atod(argv[2]);
			fractal.julia_y = atod(argv[3]);
		}
		init_mlx(&fractal);
		fractal_draw(&fractal);
		mlx_loop(fractal.mlx_ptr);
	}
	else
	{
		putstr_fd("\"./fractol madelbrot\" or \"./fractol julia x y\"",
			STDERR_FILENO);
		exit(1);
	}
}