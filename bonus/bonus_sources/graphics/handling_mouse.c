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

int	handling_mouse(int button, int x, int y, t_fractal *fractal)
{
	double	zooming_factor;
	double	centering_factor;
	double	mouse_x;
	double	mouse_y;

	zooming_factor = 1.1;
	centering_factor = 0.5 * fractal->zoom;
	if (button == 4)
	{
		mouse_x = scale(x, -2, +2, WIDTH - 1);
		mouse_y = scale(y, +1.125, -1.125, HEIGHT - 1);
		fractal->x_shift += (mouse_x - fractal->x_shift) * centering_factor;
		fractal->y_shift += (mouse_y - fractal->y_shift) * centering_factor;
		fractal->zoom *= exp(-log(zooming_factor));
	}
	else if (button == 5)
		fractal->zoom *= exp(log(zooming_factor));
	else if (button == 3)
		fractal->color_shift = sqrt(pow(x, 2) + pow(y, 2));
	fractal_renderer(fractal);
	return (0);
}
