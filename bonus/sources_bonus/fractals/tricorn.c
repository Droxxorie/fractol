/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:38:10 by eraad             #+#    #+#             */
/*   Updated: 2025/02/26 17:38:10 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//* Tricorn fractal, return the color of the pixel computed
int	tricorn(int x, int y, t_fractal *fractal)
{
	t_vector	z;
	t_vector	c;
	t_vector	temp;
	int			i;
	double		nu;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = (scale(x, -2.5, +2.5, WIDTH - 1) * fractal->zoom) + fractal->x_shift;
	c.y = (scale(y, +1.41, -1.41, HEIGHT - 1) * fractal->zoom)
		+ fractal->y_shift;
	while ((z.x * z.x + z.y * z.y) <= 5 && i < fractal->image_quality)
	{
		temp = z;
		z.x = (temp.x * temp.x) - (temp.y * temp.y) + c.x;
		z.y = -2 * temp.x * temp.y + c.y;
		i++;
	}
	if (i == fractal->image_quality)
		return (fractal->color_convg);
	nu = log((log(z.x * z.x + z.y * z.y) / 2.0) / log(2)) / log(2);
	return (color_interpolation(i + 1 - nu, fractal));
}
