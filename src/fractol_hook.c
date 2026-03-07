/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 20:32:59 by sarayapa          #+#    #+#             */
/*   Updated: 2026/03/07 14:15:45 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*f;

	f = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(f->mlx);
		exit(0);
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		f->offset_x -= 0.05 * f->scale;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		f->offset_x += 0.05 * f->scale;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		f->offset_y -= 0.05 * f->scale;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		f->offset_y += 0.05 * f->scale;
	render(f);
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractol	*f;

	(void)xdelta;
	f = param;
	if (ydelta > 0)
		f->scale /= 1.08;
	else if (ydelta < 0)
		f->scale *= 1.08;
	render(f);
}

void	close_hook(void *param)
{
	t_fractol	*f;

	f = param;
	mlx_terminate(f->mlx);
	exit(0);
}
