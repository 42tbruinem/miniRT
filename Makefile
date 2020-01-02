# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tbruinem <tbruinem@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/30 11:07:31 by tbruinem       #+#    #+#                 #
#    Updated: 2020/01/02 12:39:34 by tbruinem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
SRC_DIR = ./src
PARSE_DIR = $(SRC_DIR)/parse
SRC = *.c
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./minilibx_mms_20191025_beta/
GNL_DIR = ./get_next_line/
GNL_FLAGS = -L $(GNL_DIR) -lgnl
MLX_FLAGS = -I minilibx_mms_20191025_beta -L minilibx_mms_20191025_beta -lmlx -framework OpenGL -framework AppKit

ALL: $(NAME)

$(NAME):
	make -C $(MLX_DIR) all
	make -C $(GNL_DIR) all
	cp $(MLX_DIR)libmlx.dylib ./
	gcc $(CFLAGS) $(MLX_FLAGS) $(GNL_FLAGS) $(addprefix $(SRC_DIR)/,$(SRC)) $(addprefix $(PARSE_DIR)/,$(SRC)) -o $(NAME)

clean:
	rm -rf $(SRC:%.c=%.o)

fclean: clean
	rm -rf $(NAME)

re: fclean all
