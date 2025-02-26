/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracking_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:49:15 by eraad             #+#    #+#             */
/*   Updated: 2025/02/25 18:49:15 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	tracking_mouse(int x, int y, t_fractal *fractal)
{
	printf("jesuislà\n");
	printf("x:%i\n", x);
	printf("y:%i\n", y);
	fractal->color_shift = sqrt(pow(x, 2) + pow(y, 2));
	fractal_renderer(fractal);
	return (0);
}
