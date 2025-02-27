/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:32:58 by eraad             #+#    #+#             */
/*   Updated: 2025/02/26 16:32:58 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_numbers(t_fractal *fractal)
{
	char	*julia_x;
	char	*julia_y;
	char	*julia_speed;

	julia_speed = ft_dbltoa(fractal->c_shift_speed);
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, WIDTH - 120,
		50, WHITE, "Julia Speed : ");
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, WIDTH - 35, 50,
		WHITE, julia_speed);
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		julia_x = ft_dbltoa(fractal->c_shift.x + fractal->c.x);
		julia_y = ft_dbltoa(fractal->c_shift.y + fractal->c.y);
		mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 150, HEIGHT
			- 40, WHITE, julia_x);
		mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 150, HEIGHT
			- 20, WHITE, julia_y);
		free(julia_x);
		free(julia_y);
	}
	free(julia_speed);
}

static void	more_render_ui(t_fractal *fractal)
{
	char	*image_quality;

	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 20, HEIGHT
		- 30, WHITE, "Fractal name : ");
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 110, HEIGHT
		- 30, WHITE, fractal->name);
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, WIDTH - 120,
		30, WHITE, "Fast render : ");
	if (fractal->fast_maths % 2 == 1)
		mlx_string_put(fractal->mlx_connection, fractal->mlx_window, WIDTH - 35,
			30, WHITE, "ON");
	else
		mlx_string_put(fractal->mlx_connection, fractal->mlx_window, WIDTH - 35,
			30, WHITE, "OFF");
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, WIDTH - 120,
		HEIGHT - 30, WHITE, "Quality : ");
	image_quality = ft_itoa(abs(fractal->image_quality));
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, WIDTH - 60,
		HEIGHT - 30, WHITE, image_quality);
	free(image_quality);
}

void	render_ui(t_fractal *fractal)
{
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 20, 30, WHITE,
		"Controls:");
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 20, 60, WHITE,
		"[LEFT] [RIGHT] [UP] [DOWN] : Move");
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 20, 80, WHITE,
		"[+] [-] : Quality");
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 20, 100, WHITE,
		"[Scroll] : Zooming in/out");
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 20, 120, WHITE,
		"[Right Click] : Modify Colors");
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 20, 140, WHITE,
		"[Enter] : Reset");
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 20, 160, WHITE,
		"[Escape] : Quit");
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 20, 180, WHITE,
		"[NP-4] [NP-6] [NP-8] [NP-2] : Change Julia Set");
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 20, 200, WHITE,
		"[F1] : Fast Render");
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 20, 220, WHITE,
		"[F11] : Screenshot mod");
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 20, 240, WHITE,
		"[SPACE] : Change fractal");
	more_render_ui(fractal);
	print_numbers(fractal);
	more_render_ui(fractal);
}
