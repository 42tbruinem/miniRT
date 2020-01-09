# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tbruinem <tbruinem@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/30 11:07:31 by tbruinem       #+#    #+#                 #
#    Updated: 2020/01/09 10:30:57 by tbruinem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
SRC_DIR = ./src
PARSE_DIR = $(SRC_DIR)/parse
UTILS_DIR = $(SRC_DIR)/utils
INPUT_DIR = $(SRC_DIR)/input
GNL_DIR = ./get_next_line
MLX_DIR = ./minilibx_mms_20191025_beta
SRC = *.c

SRC = 	./src/ft_collision_functs.c \
		./src/ft_minirt.c \
		./src/ft_mlx.c \
		./src/ft_ray_camera.c \
		./src/ft_render.c \
		./src/input/ft_input_key.c \
		./src/input/ft_input_mouse.c \
		./src/parse/ft_ambient.c \
		./src/parse/ft_camera.c \
		./src/parse/ft_cylinder.c \
		./src/parse/ft_data.c \
		./src/parse/ft_debug.c \
		./src/parse/ft_filter.c \
		./src/parse/ft_free_and_return.c \
		./src/parse/ft_identifier.c \
		./src/parse/ft_initialization_functs.c \
		./src/parse/ft_light.c \
		./src/parse/ft_plane.c \
		./src/parse/ft_resolution.c \
		./src/parse/ft_sphere.c \
		./src/parse/ft_square.c \
		./src/parse/ft_triangle.c \
		./src/utils/ft_color.c \
		./src/utils/ft_digit_utils.c \
		./src/utils/ft_error.c \
		./src/utils/ft_matrix.c \
		./src/utils/ft_objects.c \
		./src/utils/ft_property.c \
		./src/utils/ft_ray.c \
		./src/utils/ft_string_utils.c \
		./src/utils/ft_vector_advanced.c \
		./src/utils/ft_vector_basic.c
ifdef RAW
SRC +=	./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c
endif

FLAGS = -O3 -I .
ifndef RAW
FLAGS += -Wall -Wextra -Werror
FLAGS += -L $(GNL_DIR) -lgnl
FLAGS += -I minilibx_mms_20191025_beta -L minilibx_mms_20191025_beta -lmlx -framework OpenGL -framework AppKit
endif
FILES = $(addprefix $(SRC_DIR)/,$(SRC)) 
FILES += $(addprefix $(PARSE_DIR)/,$(SRC)) 
FILES += $(addprefix $(UTILS_DIR)/,$(SRC)) 
FILES += $(addprefix $(INPUT_DIR)/,$(SRC)) 
ifdef RAW
FILES += $(addprefix $(GNL_DIR)/,$(SRC))
FLAGS += -D BUFFER_SIZE=40
endif
ifdef DEBUG
	FLAGS += -fsanitize=address -g
endif
ifdef WIDTH
	FLAGS += -D MAX_WIDTH=$(WIDTH)
endif
ifdef HEIGHT
	FLAGS += -D MAX_HEIGHT=$(HEIGHT)
endif

all: $(NAME)

$(NAME):
	@echo "Compiling.."
ifndef RAW
	@make -C $(MLX_DIR) all
	@make -C $(GNL_DIR) all
	@cp -rf $(MLX_DIR)/libmlx.dylib .
endif
	-gcc $(FLAGS) $(SRC) -o $(NAME)

clean:
	@echo "Cleaning"
ifdef LIB
	@make -C $(MLX_DIR) clean
	@make -C $(GNL_DIR) clean
endif
	@rm -rf $(SRC:%.c=%.o)

fclean: clean
ifdef LIB
	@echo "Force cleaning"
	@make -C $(GNL_DIR) fclean
	@rm -rf libmlx.dylib
endif
	@rm -rf $(NAME)

re: fclean all
