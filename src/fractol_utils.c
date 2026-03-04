/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:07:59 by sarayapa          #+#    #+#             */
/*   Updated: 2026/03/04 21:14:21 by sarayapa         ###   ########.fr       */
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

void	parse_args(int ac, char **av, t_fractol *f)
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11))
	{
		f->type = manda;
		f->scale = 1.5;
		f->offset_x = -0.5;
		f->offset_y = 0;
	}
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 6))
	{
		f->type = jul;
		f->scale = 2;
		f->offset_x = 0;
		f->offset_y = 0;
		f->julia_cr = ft_atof(av[2]);
		f->julia_ci = ft_atof(av[3]);
	}
	else
	{
		ft_putstr_fd("Usage :\n\t", 2);
		ft_putstr_fd("./fractol mandelbrot\n\t", 2);
		ft_putstr_fd("./fractol julia <value_1> <value_2>", 2);
		exit(1);
	}
}

void	init_fractol(t_fractol *f)
{
	f->mlx = mlx_init(WIDTH, HEIGHT, "FRACT-OL", true);
	if (!f->mlx)
		exit (EXIT_FAILURE);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		exit (EXIT_FAILURE);
	mlx_key_hook(f->mlx, key_hook, f);
	mlx_scroll_hook(f->mlx, scroll_hook, f);
	mlx_close_hook(f->mlx, close_hook, f);
	mlx_image_to_window(f->mlx, f->img, 0, 0);
}

int	get_color(int i)
{
	if (i == MAX_ITER)
		return (0x000000FF);
	return (i * 0x0303F3FF);
}
