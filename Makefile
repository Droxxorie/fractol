# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eraad <eraad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 14:33:34 by eraad             #+#    #+#              #
#    Updated: 2025/03/03 12:58:38 by eraad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME			= fractol
NAME_BONUS		= fractol_bonus
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -O3 -march=native -funroll-loops -ffast-math -fomit-frame-pointer 

INCLUDE			= -I./include -I./minilibx-linux
MLX 			= minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a
INCLUDE_BONUS	= -I./bonus/include_bonus -I./minilibx-linux

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
					utils/error_wrong_input.c utils/ft_atodbl.c utils/ft_putchar_fd.c utils/ft_putstr_fd.c utils/ft_strncmp.c utils/error_malloc.c utils/ft_itoa.c utils/ft_strjoin.c utils/ft_dbltoa.c utils/ft_strdup.c \
					main.c

SRCS = $(addprefix $(SRCS_DIR), $(SRC_FILES))

#Bonus
SRCS_DIR_BONUS	=	bonus/sources_bonus/
SRC_FILES_BONUS	=	fractals/julia.c fractals/mandelbrot.c fractals/burning_ship.c fractals/tricorn.c fractals/lambda.c \
					graphics/clean_close.c graphics/fractal_renderer.c graphics/handling_keys.c graphics/handling_mouse.c graphics/init_data.c graphics/init_events.c graphics/init_fractal.c graphics/new_pixel_put.c graphics/color_interpolation.c graphics/nearest_neighbor_interpolation.c graphics/render_ui.c \
					math/math_complex_norm.c math/math_complex_squared.c math/math_complex_sum.c math/math_scale.c \
					utils/error_wrong_input.c utils/ft_atodbl.c utils/ft_putchar_fd.c utils/ft_putstr_fd.c utils/ft_strncmp.c utils/error_malloc.c utils/ft_itoa.c utils/ft_strjoin.c utils/ft_dbltoa.c utils/ft_strdup.c \
					main.c

SRCS_BONUS = $(addprefix $(SRCS_DIR_BONUS), $(SRC_FILES_BONUS))

#Objects
OBJS_DIR		=	objects/
OBJS			=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))
OBJS_DIR_BONUS	=	bonus/objects_bonus/
OBJS_BONUS		=	$(patsubst $(SRCS_DIR_BONUS)%.c, $(OBJS_DIR_BONUS)%.o, $(SRCS_BONUS))

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

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
				@echo "_________________________________________________"
				@echo "$(G)\n--- Creating $(NAME_BONUS)...\n$(DEF)"
				@$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLX) -lX11 -lXext -lm -lz -o $(NAME_BONUS)
				@echo "$(NEON_GREEN)     ---------------------------------------$(DEF)"
				@echo "$(NEON_GREEN)     | $(NAME_BONUS) compiled succesfully! |$(DEF)"
				@echo "$(NEON_GREEN)     ---------------------------------------$(DEF)"
				@echo "_________________________________________________\n"

$(OBJS_DIR_BONUS)%.o: $(SRCS_DIR_BONUS)%.c
				@mkdir -p $(dir $@)
				@echo "$(Y)- Compiling $<...$(DEF)"
				@$(CC) $(CFLAGS) $(INCLUDE_BONUS) -c -o $@ $<

clean:
				@echo "_________________________________________________"
				@echo "$(ORANGE)\n--- Cleaning objects files...\n$(DEF)"
				@rm -rf $(OBJS_DIR)
				@rm -rf $(OBJS_DIR_BONUS)
				@echo "$(R)            * Objects files cleaned!$(DEF)"
				@echo "_________________________________________________\n"


fclean: clean
				@echo "_________________________________________________"
				@echo "$(ORANGE)\n--- Cleaning programs...\n$(DEF)"
				@rm -f $(NAME)
				@rm -f $(NAME_BONUS)
				@echo "$(R)            * Programs Cleaned!$(DEF)"
				@echo "_________________________________________________\n"



re: fclean $(NAME)

re_bonus: fclean $(NAME_BONUS)

.PHONY: all clean fclean re bonus re_bonus