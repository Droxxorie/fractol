/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:34:42 by eraad             #+#    #+#             */
/*   Updated: 2025/02/25 16:34:42 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//* Close the display and destroy everything
int	clean_close(t_fractal *fractal)
{
	if (fractal->image.image_ptr)
		mlx_destroy_image(fractal->mlx_connection, fractal->image.image_ptr);
	if (fractal->mlx_window)
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	if (fractal->mlx_connection)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
	}
	exit(EXIT_SUCCESS);
}
