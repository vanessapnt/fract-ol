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

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

/*
 * SQUARE is trickier
 *
 * real = (x^2 - y^2)
 * i =  2*x*y
 */
t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
