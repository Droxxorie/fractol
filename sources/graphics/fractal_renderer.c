/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_renderer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:42:54 by eraad             #+#    #+#             */
/*   Updated: 2025/02/25 13:42:54 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	select_fractal(int x, int y, t_fractal *fractal)
{
	char	*name;

	name = fractal->name;
	if (!ft_strncmp(name, "mandelbrot", 10))
		return (mandelbrot(x, y, fractal));
	else if (!ft_strncmp(name, "julia", 5))
		return (julia(x, y, fractal));
	return (0);
}

static void	fast_rendering(t_fractal *fractal)
{
	int	x;
	int	y;
	int	color;

	color = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = select_fractal(x, y, fractal);
			nearest_neighbor_interpolation(x, y, color, fractal);
			x += 2;
		}
		y += 2;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->image.image_ptr, 0, 0);
}

static void	classic_rendering(t_fractal *fractal)
{
	int	x;
	int	y;
	int	color;

	color = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = select_fractal(x, y, fractal);
			new_pixel_put(x, y, &fractal->image, color);
			x += 1;
		}
		y += 1;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->image.image_ptr, 0, 0);
}

void	fractal_renderer(t_fractal *fractal)
{
	if (fractal->fast_maths % 2 == 1)
		fast_rendering(fractal);
	else
		classic_rendering(fractal);
	if (fractal->ui % 2 == 1)
		render_ui(fractal);
}
