/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:18:36 by eraad             #+#    #+#             */
/*   Updated: 2025/02/25 17:18:36 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//* atoi but for doubles, input is supposed valid
double	atodbl(char *s)
{
	int		sign;
	long	full_part;
	double	fractional_part;
	double	fraction;

	sign = 1;
	full_part = 0;
	fractional_part = 0.0;
	fraction = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign *= -1;
	while (*s && *s != '.')
		full_part = (full_part * 10) + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s)
	{
		fraction /= 10;
		fractional_part = fractional_part + (*s++ - '0') * fraction;
	}
	return ((full_part + fractional_part) * sign);
}
