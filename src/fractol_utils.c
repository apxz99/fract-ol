/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:07:59 by sarayapa          #+#    #+#             */
/*   Updated: 2026/03/04 16:00:38 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
	
void	parse_args(int ac, char **av, t_fractol *f)
{
	if(ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11))
		f->type = mandelbrot;
	else if(ac == 4 && !ft_strncmp(av[1], "julia", 6))
		f->type = julia;
	else
	{
		ft_putstr_fd("Usage :\n\t./fractol mandelbrot\n\t./fractol julia <value_1> <value_2>", 2);
		exit(1);
	}
}

void	render(t_fractol)
{
}