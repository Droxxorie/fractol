/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:11:15 by eraad             #+#    #+#             */
/*   Updated: 2025/02/27 11:11:15 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	intlen(int number)
{
	int	len;

	if (number == 0)
		return (1);
	len = 0;
	if (number < 0)
	{
		number *= -1;
		len++;
	}
	while (number > 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int number)
{
	char	*str;
	int		len;

	len = intlen(number);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (number == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (number < 0)
	{
		str[0] = '-';
		number *= -1;
	}
	while (number > 0)
	{
		str[len - 1] = (number % 10) + '0';
		number /= 10;
		len--;
	}
	return (str);
}
