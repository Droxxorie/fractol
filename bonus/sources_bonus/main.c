/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:37:14 by eraad             #+#    #+#             */
/*   Updated: 2025/02/25 10:37:14 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	error_no_input(void)
{
	ft_putstr_fd("Wrong input, please enter one of the following :\n", 2);
	ft_putstr_fd("\t-\"mandelbrot\"\n", 2);
	ft_putstr_fd("\t-\"julia\"\n", 2);
	ft_putstr_fd("\t-\"julia <x> <y>\"\n", 2);
	ft_putstr_fd("\t-\"burning_ship\"\n", 2);
	ft_putstr_fd("\t-\"tricorn\"\n", 2);
	ft_putstr_fd("\t-\"lambda\"\n", 2);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| ((ac == 4 || ac == 2) && !ft_strncmp(av[1], "julia", 5))
		|| (ac == 2 && !ft_strncmp(av[1], "burning_ship", 12))
		|| (ac == 2 && !ft_strncmp(av[1], "tricorn", 7))
		|| (ac == 2 && !ft_strncmp(av[1], "lambda", 6)))
	{
		fractal.name = av[1];
		init_fractal(&fractal, av, ac);
		fractal_renderer(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		error_no_input();
		exit(EXIT_FAILURE);
	}
}
