# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tbruinem <tbruinem@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/30 11:07:31 by tbruinem       #+#    #+#                 #
#    Updated: 2020/01/06 17:17:51 by tbruinem      ########   odam.nl          #
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
FLAGS =  -O3 -I .
FLAGS += -Wall -Wextra -Werror
FLAGS += -L $(GNL_DIR) -lgnl
FLAGS += -I minilibx_mms_20191025_beta -L minilibx_mms_20191025_beta -lmlx -framework OpenGL -framework AppKit
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
	@make -C $(MLX_DIR) all
	@make -C $(GNL_DIR) all
	@cp $(MLX_DIR)/libmlx.dylib .
	@gcc $(FLAGS) \
	$(addprefix $(SRC_DIR)/,$(SRC)) \
	$(addprefix $(PARSE_DIR)/,$(SRC)) \
	$(addprefix $(UTILS_DIR)/,$(SRC)) \
	$(addprefix $(INPUT_DIR)/,$(SRC)) \
	-o $(NAME)

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
