/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:33:47 by varodrig          #+#    #+#             */
/*   Updated: 2024/10/30 13:42:20 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
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
	bool	isjulia;
	double	julia_x;
	double	julia_y;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	hypothenuse;
	double	iterations;
}			t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
bool		is_valid_number(char *str);
double		ft_atod(const char *str);

void		init_mlx(t_fractal *fractal);
void		fractal_draw(t_fractal *fractal);
void		ft_putstr_fd(char *s, int fd);

int			key_hook(int keysym, t_fractal *fractal);
int			mouse_hook(int button, int keysym, t_fractal *fractal);
int			end_fractol(t_fractal *fractal);

double		map(double unscaled_num, double new_min, double new_max,
				double old_min, double old_max);
t_complex	*square_complex(t_complex *z);
void		sum_complex(t_complex *z, t_complex *c);
double		ft_atod(const char *str);
int	ft_isdigit(char c);

#endif
