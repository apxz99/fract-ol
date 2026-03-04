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
#include "stdio.h"

void	error(void)
{
	write(2, "error", 5);
	exit(0);
}

int	set_color(int r, int g, int b)
{
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

int main(void)
{
	double	border = 100;
    mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Red Screen", true);
    if (!mlx)
        return (EXIT_FAILURE);

    mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
    mlx_image_to_window(mlx, img, 0, 0);

    for (int y = 0 + border; y < HEIGHT - border ; y++)
    { 
        for (int x = 0 + border; x < WIDTH - border ; x++)
		{
			int color = set_color( rand() % 256, rand() % 256, rand() % 256);
			mlx_put_pixel(img, x, y, color);
		}
    }

    mlx_loop(mlx);
    mlx_terminate(mlx);
}
//int main()
//{
//	t_data	d;
//	d.mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
//	d.img = mlx_new_image(d.mlx, WIDTH, HEIGHT);
//	//mlx_put_string( d.mlx, "Hello",  HEIGHT / 2, WIDTH / 2 );
//	//mlx_put_pixel( d.img, WIDTH / 2 ,  HEIGHT / 2, 0xFFFF0000);
//	for (int y = 0; y < HEIGHT; y++)
//	{
//		for (int x = 0; x < WIDTH; x++)
//		{
//			mlx_put_pixel(d.img, x, y, 0xFFFF0000);
//		}
//	}
	
//	if (mlx_image_to_window(d.mlx, d.img, 0, 0) < 0)
//		error();
//	int ret = mlx_image_to_window(d.mlx, d.img, 0, 0);
//	printf("ret = %d\n", ret);
//	mlx_loop(d.mlx);
	
//	mlx_terminate(d.mlx);
//}

//int main(void)
//{
//	t_data	d;

//	d.mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
//	if (!d.mlx)
//		return (1);

//	d.img = mlx_new_image(d.mlx, WIDTH, HEIGHT);
//	if (!d.img)
//		return (1);

//	if (mlx_image_to_window(d.mlx, d.img, 0, 0) < 0)
//		return (1);

//	// วาดลง buffer ตรง ๆ (เร็วกว่า put_pixel)
//	uint32_t *pixels = (uint32_t *)d.img->pixels;

//	for (int y = 0; y < HEIGHT; y++)
//	{
//		for (int x = 0; x < WIDTH; x++)
//		{
//			pixels[y * WIDTH + x] = 0xFFFF0000;
//		}
//	}

//	mlx_loop(d.mlx);
//	mlx_terminate(d.mlx);
//	return (0);
//}