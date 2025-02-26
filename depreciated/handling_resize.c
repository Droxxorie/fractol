/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_resize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:43:29 by eraad             #+#    #+#             */
/*   Updated: 2025/02/26 20:43:29 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handling_resize(t_fractal *fractal)
{
	int new_width;
	int new_height;

	mlx_get_screen_size(fractal->mlx_connection, &new_width, &new_height);
	if (new_width != fractal->width || new_height != fractal->height)
	{
		fractal->width = new_width;
		fractal->height = new_height;
		mlx_destroy_image(fractal->mlx_connection, fractal->image.image_ptr);
		fractal->image.image_ptr = mlx_new_image(fractal->mlx_connection, fractal->width,
				fractal->height);
		if (!fractal->image.image_ptr)
		{
			mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
			mlx_destroy_display(fractal->mlx_connection);
			free(fractal->mlx_connection);
			error_malloc();
		}
		fractal_renderer(fractal);
	}
	return (0);
}
