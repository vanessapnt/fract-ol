#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/keysym.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 700
# define HEIGHT 700

typedef struct s_img
{
	void	*img_ptr;
	char	*pix_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_fractal
{
	bool	*isjulia;
	double	julia_x;
	double	julia_y;
	void	*mlx_ptr;
	void	*mlx_win_ptr;
	t_img	img;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	hypothenuse;
	double	iterations_nb;
}			t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

#endif
