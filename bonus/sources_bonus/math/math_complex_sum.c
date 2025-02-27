/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_complex_sum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:43:17 by eraad             #+#    #+#             */
/*   Updated: 2025/02/25 14:43:17 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_vector	complex_sum(t_vector z_1, t_vector z_2)
{
	t_vector	result;

	result.x = z_1.x + z_2.x;
	result.y = z_1.y + z_2.y;
	return (result);
}
