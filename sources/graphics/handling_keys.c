/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:00:25 by eraad             #+#    #+#             */
/*   Updated: 2025/02/25 17:00:25 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	reset_data(t_fractal *fractal)
{
	fractal->zoom = 1;
}

static void	cycle_names(t_fractal *fractal)
{
	char	*name;

	name = fractal->name;
	if (!ft_strncmp(name, "mandelbrot", 10))
		fractal->name = "julia";
	else if (!ft_strncmp(name, "julia", 5))
		fractal->name = "mandelbrot";
}

//* NP_8, NP_2, NP_6, NP_4
static void	more_keys(int keysym, t_fractal *fractal)
{
	if (keysym == 65431)
		fractal->c_shift.y += 0.01 * fractal->c_shift_speed;
	else if (keysym == 65433)
		fractal->c_shift.y -= 0.01 * fractal->c_shift_speed;
	else if (keysym == 65432)
		fractal->c_shift.x += 0.01 * fractal->c_shift_speed;
	else if (keysym == 65430)
		fractal->c_shift.x -= 0.01 * fractal->c_shift_speed;
	else if (keysym == XK_space)
		cycle_names(fractal);
	else if (keysym == XK_Page_Up)
		fractal->c_shift_speed *= 1.2;
	else if (keysym == XK_Page_Down)
		fractal->c_shift_speed /= 1.2;
}

int	handling_keys(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		clean_close(fractal);
	else if (keysym == XK_KP_Add)
		fractal->image_quality += 5;
	else if (keysym == XK_KP_Subtract)
		fractal->image_quality -= 5;
	else if (keysym == XK_Return)
		reset_data(fractal);
	else if (keysym == XK_F1)
		fractal->fast_maths++;
	else if (keysym == XK_F11)
		fractal->ui++;
	more_keys(keysym, fractal);
	fractal_renderer(fractal);
	return (0);
}
