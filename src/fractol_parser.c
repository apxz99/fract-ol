/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:12:03 by sarayapa          #+#    #+#             */
/*   Updated: 2026/03/07 14:14:19 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parse_args(int ac, char **av, t_fractol *f)
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11))
	{
		f->type = manda;
		f->scale = 1.5;
		f->offset_x = -0.55;
		f->offset_y = 0;
	}
	else if ((ac <= 4) && !ft_strncmp(av[1], "julia", 6))
	{
		if (is_float_str(av[2]) && is_float_str(av[3]))
		{
			f->julia_cr = ft_atof(av[2]);
			f->julia_ci = ft_atof(av[3]);
		}
		else
			julia_error_exit();
		f->type = jul;
		f->scale = 2;
		f->offset_x = 0;
		f->offset_y = 0;
	}
	else
		error_exit();
}

bool	is_float_str(char *str)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (!str || str[i] == '\0')
		return (false);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			i++;
			dot++;
		}
		if (dot > 1 || !ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void	error_exit(void)
{
	ft_putstr_fd("Usage :\n", 2);
	ft_putstr_fd("\t./fractol mandelbrot\n", 2);
	ft_putstr_fd("\t./fractol julia <real_value> <imaginary_value>\n", 2);
	exit(1);
}

void	julia_error_exit(void)
{
	ft_putstr_fd("Error: Invalid Julia parameters\n", 2);
	ft_putstr_fd("Usage:\n", 2);
	ft_putstr_fd("\t./fractol julia <real_value> <imaginary_value>\n", 2);
	ft_putstr_fd("Example:\n", 2);
	ft_putstr_fd("\t./fractol julia -0.7 0.27015\n", 2);
	exit(1);
}
