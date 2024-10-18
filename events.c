#include "fractol.h"

int	end_fractol()

int key_hook(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		end_fractol(fractal);
	if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);	
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);	
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);	
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);	
    fractal_render(fractal);
	return 0;
}

int mouse_hook(int keysym, t_fractal *fractal)
{
	if (button == Button5)
		fractal->zoom *= 0.95;
	else if (button == Button4)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return 0;
}
