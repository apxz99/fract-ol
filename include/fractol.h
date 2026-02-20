/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:07:39 by sarayapa          #+#    #+#             */
/*   Updated: 2026/02/20 14:05:17 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>

# define MINIMUM_ITER 10
# define DEFAULT_ITER 100
# define MAX_ITER 100

# define HEIGHT 720.0
# define WIDTH 1080.0

# define EXIT_KEY 65307
# define RESET_KEY MLX_KEY_R
# define INCREASE_ITER_KEY 61
# define DECREASE_ITER_KEY 45
# define COLOR_SHIFT_KEY MLX_KEY_C

typedef struct s_data
{
	mlx_t	*mlx;
	mlx_image_t	*img;

	double	scale;
	double	offset_x;
	double	offset_y;

	int		max_iter;
}   t_data;

//void	put_pixel(t_data *d, int x, int y, int color);

//int		mandelbrot(double cr, double ci);

#endif