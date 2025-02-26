/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_complex_squared.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:43:54 by eraad             #+#    #+#             */
/*   Updated: 2025/02/25 14:43:54 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_vector	complex_squared(t_vector z)
{
	t_vector	result;

	result.x = pow(z.x, 2) - pow(z.y, 2);
	result.y = 2 * z.x * z.y;
	return (result);
}
