/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:58:35 by eraad             #+#    #+#             */
/*   Updated: 2025/02/26 17:58:35 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	lambda(int x, int y, t_fractal *fractal)
{
	t_vector	z;
	t_vector	temp;
	double		lambda;
	int			i;
	double		nu;

	i = 0;
	z.x = (scale(y, +2, -1, HEIGHT - 1) * fractal->zoom) + fractal->y_shift;
	z.y = 0;
	lambda = (scale(x, -2, +4, WIDTH - 1) * fractal->zoom) + fractal->x_shift;
	while ((z.x * z.x + z.y * z.y) <= 4 && i < fractal->image_quality)
	{
		temp = z;
		z.x = lambda * (temp.x - temp.x * temp.x - temp.y * temp.y);
		z.y = lambda * (temp.y - 2 * temp.x * temp.y);
		i++;
	}
	if (i == fractal->image_quality)
		return (fractal->color_convg);
	nu = log((log(z.x * z.x + z.y * z.y) / 2.0) / log(2)) / log(2);
	return (color_interpolation(i + 1 - nu, fractal));
}
