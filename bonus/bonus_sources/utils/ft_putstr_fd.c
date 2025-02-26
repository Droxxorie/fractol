/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:55:22 by eraad             #+#    #+#             */
/*   Updated: 2025/02/25 10:55:22 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//* put string into file with recursion
void	ft_putstr_fd(char *str, int fd)
{
	if (fd < 0 || !str)
		return ;
	while (*str != '\0')
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
}
