/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:41:08 by eraad             #+#    #+#             */
/*   Updated: 2025/02/26 20:41:08 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//* Print error message for malloc failure
void	error_malloc(void)
{
	perror("Malloc failed\n");
	exit(EXIT_FAILURE);
}
