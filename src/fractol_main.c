/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:18:11 by sarayapa          #+#    #+#             */
/*   Updated: 2026/03/07 13:59:46 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	f;

	parse_args(ac, av, &f);
	init_fractol(&f);
	render(&f);
	mlx_loop(f.mlx);
	return (0);
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

int	mandelbrot(double cr, double ci)
{
	double	zr;
	double	zi;
	double	temp;
	int		i;

	i = 0;
	zr = 0;
	zi = 0;
	while (i < MAX_ITER && zr * zr + zi * zi <= 4)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = temp;
		i++;
	}
	return (i);
}

int	julia(double zr, double zi, double cr, double ci)
{
	double	temp;
	int		i;

	i = 0;
	while (i < MAX_ITER && zr * zr + zi * zi <= 4)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = temp;
		i++;
	}
	return (i);
}

void	render(t_fractol *f)
{
	int		x;
	int		y;
	double	cr;
	double	ci;
	int		iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cr = (x - WIDTH / 2.0) / (WIDTH / 2.0) * f->scale + f->offset_x;
			ci = (y - HEIGHT / 2.0) / (HEIGHT / 2.0) * f->scale + f->offset_y;
			if (f->type == manda)
				iter = mandelbrot(cr, ci);
			else
				iter = julia(cr, ci, f->julia_cr, f->julia_ci);
			mlx_put_pixel(f->img, x, y, get_color(iter));
			x++;
		}
		y++;
	}
}
