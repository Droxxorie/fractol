/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_complex_norm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:44:58 by eraad             #+#    #+#             */
/*   Updated: 2025/02/25 15:44:58 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	complex_norm(t_vector number)
{
	if (!number.x || !number.y)
		return (0);
	return (sqrt(pow(number.x, 2) + pow(number.y, 2)));
}
