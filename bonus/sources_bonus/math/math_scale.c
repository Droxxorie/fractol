/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:20:25 by eraad             #+#    #+#             */
/*   Updated: 2025/02/25 14:20:25 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//* Scale a number based on the length of its old distribution
//* and the limits of the new obe
double	scale(double num_to_scale, double min, double max, double length)
{
	return (((max - min) * (num_to_scale / length)) + min);
}
