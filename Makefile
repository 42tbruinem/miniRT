# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tbruinem <tbruinem@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/30 11:07:31 by tbruinem       #+#    #+#                 #
#    Updated: 2020/01/04 17:12:30 by tbruinem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
SRC_DIR = ./src
PARSE_DIR = $(SRC_DIR)/parse
SRC = *.c
FLAGS = -Wall -Wextra -Werror -I .
ifndef RAW
	FLAGS += ./minilibx_mms_20191025_beta/
	FLAGS += -L $(GNL_DIR) -lgnl
endif
ifdef RAW
	FLAGS += -D BUFFER_SIZE=40
endif
GNL_DIR = ./get_next_line/
MLX_FLAGS = -I minilibx_mms_20191025_beta -L minilibx_mms_20191025_beta -lmlx -framework OpenGL -framework AppKit

ALL: $(NAME)

$(NAME):
ifndef RAW
	make -C $(MLX_DIR) all
	make -C $(GNL_DIR) all
	cp $(MLX_DIR)libmlx.dylib ./
endif
	gcc $(FLAGS) \
	$(addprefix $(SRC_DIR)/,$(SRC)) \
	$(addprefix $(PARSE_DIR)/,$(SRC)) \
	$(addprefix $(GNL_DIR)/,$(SRC)) \
	-o $(NAME) -lm

clean:
ifndef RAW
	make -C $(MLX_DIR) clean
	make -C $(GNL_DIR) clean
endif
	rm -rf $(SRC:%.c=%.o)

fclean: clean
ifndef RAW
	make -C $(GNL_DIR) fclean
endif
	rm -rf libmlx.dylib
	rm -rf $(NAME)

re: fclean all
