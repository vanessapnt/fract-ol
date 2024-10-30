/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:34:01 by varodrig          #+#    #+#             */
/*   Updated: 2024/10/30 21:41:58 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_error(void)
{
	ft_putstr_fd("malloc failed\n", STDERR_FILENO);
	exit(1);
}
// 2^2 + 2^2 = hypotenuse squared(4)
static void	data_init(t_fractal *fractal)
{
	fractal->hypothenuse = 4.0;
	fractal->iterations = 50;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}
// establish the connection between key and function so it's used later with mlx_loop
void	init_events(t_fractal *fractal)
{
	mlx_key_hook(fractal->win_ptr, key_hook, fractal);
	mlx_mouse_hook(fractal->win_ptr, mouse_hook, fractal);
	mlx_hook(fractal->win_ptr, DestroyNotify, 0, end_fractol, fractal);
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		ft_error();
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT,
			"fractol");
	if (!fractal->win_ptr)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		ft_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		ft_error();
	}
	fractal->img.pix_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	data_init(fractal);
}
