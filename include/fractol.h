/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:07:39 by sarayapa          #+#    #+#             */
/*   Updated: 2026/03/06 20:08:27 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define MAX_ITER 100

# define HEIGHT 900
# define WIDTH 900

typedef enum type
{
	manda,
	jul
}	t_type;

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	double		scale;
	double		offset_x;
	double		offset_y;

	double		julia_cr;
	double		julia_ci;
	t_type		type;
}	t_fractol;

void		parse_args(int ac, char **av, t_fractol *f);
void		init_fractol(t_fractol *f);
int			get_color(int i);
double		ft_atof(const char *str);
void		render(t_fractol *f);
int			julia(double zr, double zi, double cr, double ci);
int			mandelbrot(double cr, double ci);
void		key_hook(mlx_key_data_t keydata, void *param);
void		scroll_hook(double xdelta, double ydelta, void *param);
void		close_hook(void *param);
void		error_exit(void);
bool		is_float_str(char *str);

#endif