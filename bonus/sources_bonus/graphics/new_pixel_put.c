/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:57:35 by eraad             #+#    #+#             */
/*   Updated: 2025/02/25 14:57:35 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Put pixel into buffer image befor displaying it
void	new_pixel_put(int x, int y, t_image *image, int color)
{
	int	offset;

	offset = (y * image->line_length) + (x * image->bpp / 8);
	*(unsigned int *)(image->pixel_ptr + offset) = color;
}
