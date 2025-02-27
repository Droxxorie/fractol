/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:15:46 by eraad             #+#    #+#             */
/*   Updated: 2025/02/25 15:15:46 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//* Initialize the data of the fractal
void	init_data(t_fractal *fractal, char **av)
{
	fractal->image_quality = 40;
	fractal->x_shift = 0.0;
	fractal->y_shift = 0.0;
	fractal->zoom = 1;
	fractal->c.x = -1.47;
	fractal->c.y = 0.0;
	fractal->c_shift.x = 0.0;
	fractal->c_shift.y = 0.0;
	fractal->c_shift_speed = 10;
	fractal->color_divg = 437;
	fractal->color_convg = BLACK;
	fractal->fast_maths = 1;
	fractal->ui = 1;
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		if (error_wrong_input(av))
		{
			ft_putstr_fd("Error, wrong input format!\n", 2);
			clean_close(fractal);
			exit(EXIT_FAILURE);
		}
		fractal->c.x = atodbl(av[2]);
		fractal->c.y = atodbl(av[3]);
	}
}
