/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_power.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:43:35 by eraad             #+#    #+#             */
/*   Updated: 2025/02/25 13:43:35 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//* Compute num^power, the exposant is an int
double	power(double number, int power)
{
	double	result;
	int		exposant;

	if (power == 0)
		return (1);
	if (number == 0)
		return (0);
	result = 1.0;
	exposant = (int)abs(power);
	while (exposant)
	{
		if (exposant % 2 == 1)
			result *= number;
		number *= number;
		exposant /= 2;
	}
	if (power < 0)
		return (1.0 / result);
	return (result);
}
