# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 21:09:46 by vvaucoul          #+#    #+#              #
#    Updated: 2021/07/08 10:27:35 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINT_BAR		=	printf "\r- [%s]" $@

### COMPILATION ###
CC				= gcc
CFLAGS			= -I$(HEADER) -I./mlx  -g3 -Wall -Wextra -Werror

OS_VERSION		= $(shell uname -s)

ifeq ($(OS_VERSION), Linux)
	LIBS			= -L ./libs/ -lmlx -lmlx -lXext -lX11 -lm
else
	LIBS			= -lmlx -framework OpenGL -framework AppKit
endif

### EXECUTABLE ###
NAME			= fdf

### INCLUDES ###
HEADER 			= ./includes/
LIB_DIR			= ./libft/
ALL_LIB_DIR		= ./libraries/
OBJ_PATH 		= obj/
SRC_PATH 		= srcs/


### SOURCES ###

# SOURCE TO FREE MLX (does not compile with MLX Makefile)
SRCS_MLX		=	mlx/mlx_destroy_display.c

SRCS			=	$(SRCS_MLX)	\
					$(SRC_PATH)main.c	\
					$(SRC_PATH)utils/print.c	\
					$(SRC_PATH)utils/ft_multijoin.c	\
					$(SRC_PATH)utils/strings.c	\
					$(SRC_PATH)utils/utils.c	\
					$(SRC_PATH)utils/memory.c	\
					$(SRC_PATH)utils/errors.c	\
					$(SRC_PATH)utils/ft_memalloc.c	\
					$(SRC_PATH)utils/ft_memret.c	\
					$(SRC_PATH)utils/ft_itoa.c	\
					$(SRC_PATH)utils/ft_atoi.c	\
					$(SRC_PATH)utils/ft_strcmp.c	\
					$(SRC_PATH)utils/get_next_line/get_next_line.c	\
					$(SRC_PATH)utils/get_next_line/get_next_line_utils.c	\
					$(SRC_PATH)utils/char_utils.c	\
					$(SRC_PATH)utils/length.c	\
					$(SRC_PATH)mlx/mlx_color.c	\
					$(SRC_PATH)mlx/mlx_draw_pixel.c	\
					$(SRC_PATH)mlx/mlx_draw_background.c	\
					$(SRC_PATH)mlx/mlx_draw_string.c	\
					$(SRC_PATH)mlx/init_mlx.c	\
					$(SRC_PATH)mlx/mlx_draw_wireframe.c	\
					$(SRC_PATH)mlx/mlx_draw_user_interface.c	\
					$(SRC_PATH)mlx/mlx_draw_line.c	\
					$(SRC_PATH)core/fdf_draw.c	\
					$(SRC_PATH)core/fdf_clean.c	\
					$(SRC_PATH)core/fdf_core.c	\
					$(SRC_PATH)core/fdf_color.c	\
					$(SRC_PATH)core/fdf_rotations.c	\
					$(SRC_PATH)core/fdf_event_dinterp.c	\
					$(SRC_PATH)core/fdf_camera.c	\
					$(SRC_PATH)core/fdf_force_color.c	\
					$(SRC_PATH)core/fdf_event.c	\
					$(SRC_PATH)inputs/inputs.c	\
					$(SRC_PATH)inputs/inputs_movement.c	\
					$(SRC_PATH)math/projection_isometric.c	\
					$(SRC_PATH)math/math_utils.c	\
					$(SRC_PATH)math/interpolation.c	\
					$(SRC_PATH)math/bresenham.c	\
					$(SRC_PATH)math/angles_utils.c	\
					$(SRC_PATH)parsing/parse_cleaning.c	\
					$(SRC_PATH)parsing/apply_colors.c	\
					$(SRC_PATH)parsing/parse_file.c	\
					$(SRC_PATH)parsing/parse_file_utils.c	\
					$(SRC_PATH)parsing/parse_file_vector.c	\
					$(SRC_PATH)parsing/parse_file_loop.c	\
					$(SRC_PATH)parsing/fix_parsing.c	\
					$(SRC_PATH)parsing/parsing_utils.c



### OBJECTS ###
OBJS			=	 $(SRCS:.c=.o)

%.o : %.c
	@echo -n "\r                                                    "
	@$(PRINT_BAR) Compiling $@
	@$(CC) $(CFLAGS) $(FLAGS) $(LIBS) -c $< -o ${<:.c=.o}
	@sleep 0.1 > /dev/null

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

### CLEAN ###
RM				= rm -f

### RULES ###

all:			init mlx_linux $(NAME)

$(NAME):		$(OBJS)

				@$(CC) $(OBJS) $(CFLAGS) $(LIBS) -o $(NAME)
				@echo -n "\r                                                    "
			 	@echo "\r$(GREEN)- [FDF] Compiled !$(NOC)"

ifeq ($(OS_VERSION), Linux)
mlx_linux:
				@echo "$(YELLOW)- Compiling [MLX] $(NOC)"
				@cd mlx && make > /dev/null && cd ..
				@cp -f mlx/libmlx_Linux.a libs/mlx.a
				@echo "$(GREEN)- [MLX] Compiled$(NOC)"
				@sleep 0.5 > /dev/null
				@echo "$(GREEN)- Starting compilation$(NOC)"
				@sleep 0.5 > /dev/null
else
mlx_linux:
				@echo "$(YELLOW)Using 42 MAC MLX $(NOC)"
endif

init:
				@mkdir -p libs
				@mkdir -p $(OBJ_PATH)
				@echo "$(YELLOW)- Compilation for : " $(OS_VERSION) "$(NOC)"
				@sleep 0.5 > /dev/null

clean:
				@echo "$(RED)- Clean files$(NOC)"
				@$(RM) $(OBJS)
				@$(RM) -r $(ALL_LIB_DIR)
				@$(RM) -r $(OBJ_PATH)
				@$(RM) -r libs
				@echo "$(RED)- Clean MLX$(NOC)"
				@cd mlx && make clean > /dev/null && cd ..

fclean:			clean
				@$(RM) $(NAME)
				@echo "$(RED)- Remove $(NAME)$(NOC)"

re:				fclean all

.PHONY:			all clean fclean re mlx_linux init
