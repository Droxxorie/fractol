/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraad <eraad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:18:11 by eraad             #+#    #+#             */
/*   Updated: 2025/02/25 11:18:11 by eraad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//* Libraries
//* ------------------------------------------------------------------------*//
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
//* ------------------------------------------------------------------------*//

//* Defines
//* ------------------------------------------------------------------------*//
# define WIDTH 1280
# define HEIGHT 720
//* ------------------------------------------------------------------------*//

//* Colors
//* ------------------------------------------------------------------------*//
# define BLACK 0x000000
# define WHITE 0xFFFFFF
//* ------------------------------------------------------------------------*//

//* Structures
//* ------------------------------------------------------------------------*//
typedef struct s_image
{
	void		*image_ptr;
	char		*pixel_ptr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_fractal
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_image		image;
	int			image_quality;
	double		x_shift;
	double		y_shift;
	double		zoom;
	t_vector	c;
	t_vector	c_shift;
	int			color_shift;
	int			fast_maths;
	int			ui;
}				t_fractal;
//* ------------------------------------------------------------------------*//

//*** Utils ***
//* ------------------------------------------------------------------------*//
double			atodbl(char *str);
void			error_malloc(void);
int				error_wrong_input(char **av);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
int				ft_strncmp(char *s1, char *s2, int n);
//* ------------------------------------------------------------------------*//

//*** Maths ***
//* ------------------------------------------------------------------------*//
t_vector		complex_squared(t_vector z);
double			complex_norm(t_vector number);
t_vector		complex_sum(t_vector z_1, t_vector z_2);
double			scale(double num_to_scale, double start, double stop,
					double length);
//* ------------------------------------------------------------------------*//

//*** Fractals ***
//* ------------------------------------------------------------------------*//
int				julia(int x, int y, t_fractal *fractal);
int				mandelbrot(int x, int y, t_fractal *fractal);
//* ------------------------------------------------------------------------*//

//*** Graphiscs ***
//* ------------------------------------------------------------------------*//
void			render_ui(t_fractal *fractal);
int				clean_close(t_fractal *fractal);
void			init_events(t_fractal *fractal);
int				handling_resize(t_fractal *fractal);
void			fractal_renderer(t_fractal *fractal);
void			init_data(t_fractal *fractal, char **av);
void			init_fractal(t_fractal *fractal, char **av);
int				handling_keys(int keysym, t_fractal *fractal);
int				color_interpolation(double i, t_fractal *fractal);
void			new_pixel_put(int x, int y, t_image *image, int color);
int				handling_mouse(int button, int x, int y, t_fractal *fractal);
void			nearest_neighbor_interpolation(int x, int y, int color,
					t_fractal *fractal);
//* ------------------------------------------------------------------------*//

#endif