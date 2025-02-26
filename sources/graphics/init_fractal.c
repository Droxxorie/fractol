/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:43:09 by eraad             #+#    #+#             */
/*   Updated: 2025/02/25 11:43:09 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//* Init mlx related stuffs, error management and initialize hooks and data
void	init_fractal(t_fractal *fractal, char **av)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		error_malloc();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			"fractol");
	if (!fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		error_malloc();
	}
	fractal->image.image_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	if (!fractal->image.image_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		error_malloc();
	}
	fractal->image.pixel_ptr = mlx_get_data_addr(fractal->image.image_ptr,
			&fractal->image.bpp, &fractal->image.line_length,
			&fractal->image.endian);
	init_data(fractal, av);
	init_events(fractal);
}
