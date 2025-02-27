/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_interpolation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:40:49 by eraad             #+#    #+#             */
/*   Updated: 2025/02/26 09:40:49 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//* Interpolate colors for smooth color gradients
int	color_interpolation(double i, t_fractal *fractal)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (i / fractal->image_quality) + log(fractal->color_divg / 255);
	t = t * t * (3 - 2 * t);
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) + (g << 8) + b);
}
