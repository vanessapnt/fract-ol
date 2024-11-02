/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:33:53 by varodrig          #+#    #+#             */
/*   Updated: 2024/10/31 14:50:32 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n > 0 && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static double	ft_convert_atod(const char *str, int i)
{
	double	nbr;
	double	div;

	nbr = 0.0;
	div = 1.0;
	while (str[i] && ft_isdigit(str[i]))
	{
		nbr = nbr * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] && ft_isdigit(str[i]))
		{
			nbr = nbr * 10.0 + (str[i] - '0');
			div *= 10.0;
			i++;
		}
	}
	return (nbr / div);
}

double	ft_atod(const char *str)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return (ft_convert_atod(str, i) * sign);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (NULL == s || fd < 0)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
