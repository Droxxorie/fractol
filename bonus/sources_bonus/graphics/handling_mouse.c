/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:05:39 by eraad             #+#    #+#             */
/*   Updated: 2025/02/25 17:05:39 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//* Cycle the color of the fractal
static void	cycle_color(int button, int x, int y, t_fractal *fractal)
{
	if (button == 1)
	{
		if (fractal->color_convg == BLACK)
			fractal->color_convg = WHITE;
		else
			fractal->color_convg = BLACK;
	}
	else if (button == 3)
		fractal->color_divg = sqrt(pow(x, 2) + pow(y, 2));
}

//* Handle the mouse events
int	handling_mouse(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_x;
	double	mouse_y;
	double	mouse_x_tmp;
	double	mouse_y_tmp;

	if (button == 4)
	{
		mouse_x = fractal->x_shift + scale(x, -2, +2, WIDTH - 1)
			* fractal->zoom;
		mouse_y = fractal->y_shift + scale(y, +1.125, -1.125, HEIGHT - 1)
			* fractal->zoom;
		fractal->zoom /= 1.1;
		mouse_x_tmp = fractal->x_shift + scale(x, -2, +2, WIDTH - 1)
			* fractal->zoom;
		mouse_y_tmp = fractal->y_shift + scale(y, +1.125, -1.125, HEIGHT - 1)
			* fractal->zoom;
		fractal->x_shift -= (mouse_x_tmp - mouse_x);
		fractal->y_shift -= (mouse_y_tmp - mouse_y);
	}
	else if (button == 5)
		fractal->zoom *= 1.1;
	cycle_color(button, x, y, fractal);
	fractal_renderer(fractal);
	return (0);
}
