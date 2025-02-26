# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eraad <eraad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 14:33:34 by eraad             #+#    #+#              #
#    Updated: 2025/02/26 21:22:18 by eraad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME		= fractol
BONUS_NAME	= fractol_bonus
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -O3 -march=native -funroll-loops -ffast-math -fomit-frame-pointer

INCLUDE		= -I./include -I./minilibx-linux
MLX 		= minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a
BONUS_INCLUDE	= -I./bonus/bonus_include -I./minilibx-linux

#Colors
DEF = \033[0m
Y = \033[0;93m
G = \033[0;92m
R = \033[0;91m
ORANGE = \033[38;5;208m
LIGHT_GREEN = \033[38;5;120m
NEON_GREEN = \033[38;5;82m

#Sources
SRCS_DIR		=	sources/
SRC_FILES		=	fractals/julia.c fractals/mandelbrot.c \
					graphics/clean_close.c graphics/fractal_renderer.c graphics/handling_keys.c graphics/handling_mouse.c graphics/init_data.c graphics/init_events.c graphics/init_fractal.c graphics/new_pixel_put.c graphics/color_interpolation.c graphics/nearest_neighbor_interpolation.c graphics/render_ui.c \
					math/math_complex_norm.c math/math_complex_squared.c math/math_complex_sum.c math/math_scale.c \
					utils/error_wrong_input.c utils/ft_atodbl.c utils/ft_putchar_fd.c utils/ft_putstr_fd.c utils/ft_strncmp.c utils/error_malloc.c \
					main.c

SRCS = $(addprefix $(SRCS_DIR), $(SRC_FILES))

#Bonus
BONUS_SRCS_DIR	=	bonus/bonus_sources/
BONUS_SRC_FILES	=	fractals/julia.c fractals/mandelbrot.c fractals/burning_ship.c fractals/tricorn.c fractals/lambda.c \
					graphics/clean_close.c graphics/fractal_renderer.c graphics/handling_keys.c graphics/handling_mouse.c graphics/init_data.c graphics/init_events.c graphics/init_fractal.c graphics/new_pixel_put.c graphics/color_interpolation.c graphics/nearest_neighbor_interpolation.c graphics/render_ui.c \
					math/math_complex_norm.c math/math_complex_squared.c math/math_complex_sum.c math/math_scale.c \
					utils/error_wrong_input.c utils/ft_atodbl.c utils/ft_putchar_fd.c utils/ft_putstr_fd.c utils/ft_strncmp.c utils/error_malloc.c \
					main.c

BONUS_SRCS = $(addprefix $(BONUS_SRCS_DIR), $(BONUS_SRC_FILES))

#Objects
OBJS_DIR		=	objects/
OBJS			=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))
BONUS_OBJS_DIR	=	bonus/objects/
BONUS_OBJS		=	$(patsubst $(BONUS_SRCS_DIR)%.c, $(BONUS_OBJS_DIR)%.o, $(BONUS_SRCS))

#Rules
all: $(NAME)

$(NAME): $(OBJS)
				@echo "_________________________________________________"
				@echo "$(G)\n--- Creating $(NAME)...\n$(DEF)"
				@$(CC) $(CFLAGS) $(OBJS) $(MLX) -lX11 -lXext -lm -lz -o $(NAME)
				@echo "$(NEON_GREEN)     ---------------------------------------$(DEF)"
				@echo "$(NEON_GREEN)     |    $(NAME) compiled succesfully!    |$(DEF)"
				@echo "$(NEON_GREEN)     ---------------------------------------$(DEF)"
				@echo "_________________________________________________\n"


$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				@mkdir -p $(dir $@)
				@echo "$(Y)- Compiling $<...$(DEF)"
				@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

bonus: all $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
				@echo "_________________________________________________"
				@echo "$(G)\n--- Creating $(BONUS_NAME)...\n$(DEF)"
				@$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLX) -lX11 -lXext -lm -lz -o $(BONUS_NAME)
				@echo "$(NEON_GREEN)     ---------------------------------------$(DEF)"
				@echo "$(NEON_GREEN)     | $(BONUS_NAME) compiled succesfully! |$(DEF)"
				@echo "$(NEON_GREEN)     ---------------------------------------$(DEF)"
				@echo "_________________________________________________\n"

$(BONUS_OBJS_DIR)%.o: $(BONUS_SRCS_DIR)%.c
				@mkdir -p $(dir $@)
				@echo "$(Y)- Compiling $<...$(DEF)"
				@$(CC) $(CFLAGS) $(BONUS_INCLUDE) -c -o $@ $<

clean:
				@echo "_________________________________________________"
				@echo "$(ORANGE)\n--- Cleaning objects files...\n$(DEF)"
				@rm -rf $(OBJS_DIR)
				@rm -rf $(BONUS_OBJS_DIR)
				@echo "$(R)            * Objects files cleaned!$(DEF)"
				@echo "_________________________________________________\n"


fclean: clean
				@echo "_________________________________________________"
				@echo "$(ORANGE)\n--- Cleaning programs...\n$(DEF)"
				@rm -f $(NAME)
				@rm -f $(BONUS_NAME)
				@echo "$(R)            * Programs Cleaned!$(DEF)"
				@echo "_________________________________________________\n"



re: fclean $(NAME)

re_bonus: fclean $(BONUS_NAME)

.PHONY: all clean fclean re bonus re_bonus