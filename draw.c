/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:08:40 by varodrig          #+#    #+#             */
/*   Updated: 2024/10/23 16:08:36 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// line_len = length in bytes
// bpp = bits per pixel
// 1 byte = 8 bits
// if y = 4, we skip 4 lines to reach the beginning of the fith line (y = 4)
// x and y are in pix
//offset is the position of the pix in the memory so we convert to bytes
static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

init_julia_mandel(t_complex z, t_complex c, t_fractal *fractal)
{
	/*JULIA
		z0 = x + yi
		c = arg2 + arg3i (constant)
	*/
	if (fractal->isjulia)
	{
		c.x = fractal->julia_x;
		c.y = fractal->julia_y;
	}
	/*MANDELBROT
		z0 = 0 + 0i
		c0 = x + yi
	*/
	else
	{
		c.x = z.x;
		c.y = z.y;
		z.x = 0.0;
		z.y = 0.0;
	}
}

ft_pixels(double x, double y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;

	// converting x and y
	x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	y = (map(y, 2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	// storing x and y in z to have less arguments in init_z_c()
	z.x = x;
	z.y = y;
	init_z_c(z, c, fractal);
	// we iterate in the sequence
	// starting with z1
	i = 0;
	while (i < fractal->iterations_nb)
	{
		// changes z
		// z1 = z0^2 + c
		sum_complex(square_complex(&z), &c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->hypothenuse)
		{
			//color = map(i, BLACK, WHITE, 0, fractal->iterations_defintion);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
}

void	fractal_draw(t_fractal *fractal)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_pixels(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->mlx_win_ptr,
		fractal->img.img_ptr, 0, 0);
}