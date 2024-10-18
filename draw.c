#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

void ft_pixels(x, y, fractal)
{
    t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	mandel_vs_julia(&z, &c, fractal);
	while (i < fractal->hypothenuse)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->hypothenuse)
		{
			color = map(i, BLACK, WHITE, 0, fractal->hypothenuse);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;	
	}
	my_pixel_put(x, y, &fractal->img, WHITE);
}

void fractal_draw(t_fractal *fractal)
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
	mlx_put_image_to_window(fractal->mlx_ptr,
							fractal->mlx_win_ptr,
							fractal->img.img_ptr,
							0, 0);	
}