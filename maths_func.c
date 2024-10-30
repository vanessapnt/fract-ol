/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_func->c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student->42->fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:21:13 by varodrig          #+#    #+#             */
/*   Updated: 2024/10/23 13:17:05 by varodrig         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_min,
		double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min)
		+ new_min);
}

t_complex	*square_complex(t_complex *z)
{
	double	a;
	double	b;

	a = z->x;
	b = z->y;
	z->x = (a * a) - (b * b);
	z->y = 2 * a * b;
	return(z);
}

void	sum_complex(t_complex *z, t_complex *c)
{
	z->x = z->x + c->x;
	z->y = z->y + c->y;
}

