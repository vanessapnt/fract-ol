/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:08:40 by varodrig          #+#    #+#             */
/*   Updated: 2024/10/31 15:17:40 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// line_len = length in bytes
// bpp = bits per pixel
// 1 byte = 8 bits
// if y = 4, we skip 4 lines to reach the beginning of the fith line (y = 4)
// x and y are in pix
// offset is the position of the pix in the memory so we convert to bytes
static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		offset = (y * img->line_len) + (x * (img->bpp / 8));
		*(unsigned int *)(img->pix_ptr + offset) = color;
	}
}

/*JULIA
	z0 = x + yi
	c = arg2 + arg3i (constant)
*/
/*MANDELBROT
	z0 = 0 + 0i
	c0 = x + yi
*/
static void	init_z_c(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (fractal->isjulia)
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}
// converting x and y
// storing x and y in z to have less arguments in init_z_c()
// we iterate in the sequence
// starting with z1
// changes z
// z1 = z0^2 + c
// color = map(i, BLACK, WHITE, 0, fractal->iterations_defintion);

static void	ft_pixels(double x, double y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	init_z_c(&z, &c, fractal);
	i = 0;
	while (i < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->hypothenuse)
		{
			color = map(i, 0x000000, 0xFFFFFF, fractal->iterations);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, 0xFFFFFF);
}

void	fractal_draw(t_fractal *fractal)
{
	int	x;
	int	y;

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
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
		fractal->img.img_ptr, 0, 0);
}
