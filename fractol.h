#ifndef FRACTOL_H
#define FRACTOL_H

#include <unistd.h>
#include <stdio.h>
#include <X11/keysym.h>

#define WIDTH 700
#define HEIGHT 700

typedef struct s_img
{
    void *img_ptr;
    char *pix_ptr;
    int		bpp;
	int		line_len;
	int		endian;
} t_img;


typedef struct s_fractal
{
    char *name;
    void *mlx_ptr;
    void *mlx_win_ptr;
    t_img img;
    double	shift_x;
	double	shift_y;
	double	zoom;
    double  hypothenuse;
}   t_fractal;

typedef struct s_fractal
{
    double x;
    double y;
}

#endif
