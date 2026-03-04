/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:37:44 by sarayapa          #+#    #+#             */
/*   Updated: 2026/02/26 15:17:52 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	int	AIRPORT[9][16] = {
						{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
						{0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
						{0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
						{0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
						{0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
						{0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
						{0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
	int	cell_w = WIDTH / 16;
	int	cell_h = HEIGHT / 9;
	if (ac == 2)
	{
		mlx_t* mlx = mlx_init(WIDTH, HEIGHT, av[1], 1);
		mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
		mlx_image_to_window(mlx, img, 0, 0);
		for (int y = 0; y < 9 ; y++)
		{ 
			for (int x = 0; x < 16 ; x++)
			{
				if(AIRPORT[y][x] == 1)
				{
					for (int by = 0; by < cell_h; by++)
					{
						for (int bx = 0; bx < cell_w; bx++)
						{
							mlx_put_pixel(img, x * cell_w + bx, y * cell_h + by, 0xFF0000FF);
						}
					}
				}
			}
		}
		mlx_loop(mlx);
	}
	ft_putendl_fd("using ./fractol 'ARG'", 2);
}