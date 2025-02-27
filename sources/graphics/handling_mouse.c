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

//* handle mouse events
int	handling_mouse(int button, int x, int y, t_fractal *fractal)
{
	double	zooming_factor;

	(void)x;
	(void)y;
	zooming_factor = 1.02;
	if (button == 4)
		fractal->zoom *= exp(-log(zooming_factor));
	else if (button == 5)
		fractal->zoom *= exp(log(zooming_factor));
	fractal_renderer(fractal);
	return (0);
}
