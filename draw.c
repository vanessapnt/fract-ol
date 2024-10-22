#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

t_complex z;
t_complex c;





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