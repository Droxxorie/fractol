/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_wrong_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:39:42 by eraad             #+#    #+#             */
/*   Updated: 2025/02/25 17:39:42 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//* Check if the input in in the right format
//* return 1 if an error is found, 0 otherwise
int	error_wrong_input(char **av)
{
	int		i;
	char	*str;
	int		dot;

	i = 2;
	while (i <= 3)
	{
		dot = 0;
		str = av[i];
		while ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
		while (*str == '+' || *str == '-')
			str++;
		while (*str)
		{
			if (*str == '.' && ++dot > 1)
				return (1);
			if (*str != '.' && !(*str >= '0' && *str <= '9'))
				return (1);
			str++;
		}
		i++;
	}
	return (0);
}
