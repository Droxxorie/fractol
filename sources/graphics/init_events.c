/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:58:43 by eraad             #+#    #+#             */
/*   Updated: 2025/02/25 15:58:43 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//* Initialize the events for the fractal
void	init_events(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, handling_keys,
		fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, handling_mouse,
		fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
		clean_close, fractal);
}
