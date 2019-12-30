# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tbruinem <tbruinem@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/30 11:07:31 by tbruinem       #+#    #+#                 #
#    Updated: 2019/12/30 11:11:21 by tbruinem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
SRC = 
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -I minilibx_mms_20191025_beta -L minilibx_mms_20191025_beta -lmlx -framework OpenGL -framework AppKit

ALL: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(MLX_FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(SRC:%.c=%.o)

fclean: clean
	rm -rf $(NAME)

re: fclean all
