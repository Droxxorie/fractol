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

static void	more_render_ui(t_fractal *fractal)
{
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
}
