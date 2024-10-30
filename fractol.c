/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:34:07 by varodrig          #+#    #+#             */
/*   Updated: 2024/10/30 21:21:13 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	pb_parsing(int argc, char **argv)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		return (0);
	if (argc == 4 && !ft_strncmp(argv[1], "julia", 6))
	{
		if (is_valid_number(argv[2]) && is_valid_number(argv[3]))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (!pb_parsing(argc, argv))
	{
		fractal.isjulia = false;
		if (!ft_strncmp(argv[1], "julia", 6))
		{
			fractal.isjulia = true;
			fractal.julia_x = ft_atod(argv[2]);
			fractal.julia_y = ft_atod(argv[3]);
		}
		init_mlx(&fractal);
		init_events(&fractal);
		fractal_draw(&fractal);
		mlx_loop(fractal.mlx_ptr);
	}
	else
	{
		ft_putstr_fd("\"./fractol madelbrot\" or \"./fractol julia x y (x and y being floats)\"",
			STDERR_FILENO);
		exit(1);
	}
}
