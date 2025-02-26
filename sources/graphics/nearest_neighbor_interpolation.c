/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_neighbor_interpolation.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:38:42 by eraad             #+#    #+#             */
/*   Updated: 2025/02/26 09:38:42 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//* Nearest neigbor to diminue computation time and create smooth animations
void	nearest_neighbor_interpolation(int x, int y, int c, t_fractal *fractal)
{
	int	color;
	int	dx;
	int	dy;

	color = c;
	dy = 0;
	while (dy < 2 && (y + dy) < HEIGHT)
	{
		dx = 0;
		while (dx < 2 && (x + dx) < WIDTH)
		{
			new_pixel_put(x + dx, y + dy, &fractal->image, color);
			dx++;
		}
		dy++;
	}
}
