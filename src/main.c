/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sarayapa <sarayapa@student.42bangkok.co	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/20 03:05:22 by sarayapa		  #+#	#+#			 */
/*   Updated: 2026/02/20 10:31:40 by sarayapa		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "fractol.h"

void	error(void)
{
	write(2, "error", 5);
	exit(0);
}

int main()
{
	t_data	d;
	d.mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	d.img = mlx_new_image(d.mlx, WIDTH, HEIGHT);
	//mlx_put_string( d.mlx, "Hello",  HEIGHT / 2, WIDTH / 2 );
	//mlx_put_pixel( d.img, WIDTH / 2 ,  HEIGHT / 2, 0xFFFF0000);
	for (int y = 0; y < HEIGHT; y++)
{
	for (int x = 0; x < WIDTH; x++)
	{
		mlx_put_pixel(d.img, x, y, 0xFFFF0000);
	}
}
	if (mlx_image_to_window(d.mlx, d.img, 0, 0) < 0)
		error();
	mlx_loop(d.mlx);
	mlx_terminate(d.mlx);
}