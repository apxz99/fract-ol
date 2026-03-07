/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:07:59 by sarayapa          #+#    #+#             */
/*   Updated: 2026/03/07 13:46:10 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	double	fraction;

	result = 0;
	sign = 1;
	fraction = 0.1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			result += (*str++ - '0') * fraction;
			fraction *= 0.1;
		}
	}
	return (result * sign);
}

int	get_color(int i)
{
	if (i == MAX_ITER)
		return (0x000000FF);
	return (i * 0x0F0AF4FF);
}
