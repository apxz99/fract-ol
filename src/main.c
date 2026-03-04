/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:18:11 by sarayapa          #+#    #+#             */
/*   Updated: 2026/03/04 16:13:13 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol f;

	parse_args(ac, av, &f);
	f.mlx = mlx_init(WIDTH, HEIGHT, "FRACT-OL", true);
	if (!f.mlx)
		return (EXIT_FAILURE);
	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(f.mlx, f.img, 0, 0);
	for(int i; i < WIDTH ; i++)
		mlx_put_pixel(f.img, i, HEIGHT/2,  0xFFFFFFFF);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (0);
}