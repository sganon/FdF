# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sganon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/08 12:50:42 by sganon            #+#    #+#              #
#    Updated: 2016/01/08 17:27:10 by sganon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =	main.c \
		get_next_line.c \
		parcing.c \

SRC_DIR = srcs/ \

SRC_LIST =	$(addprefix srcs/, $(SRC))

O_FILES = $(SRC:.c=.o)

CC = clang

CC_FLAGS = -Wall -Werror -Wextra

LIB_FT_FLAG = -L./libft

MLX_FLAGS =	-L./minilibx_macos

INC_FLAG = -I./

INC_DIR = includes

all : $(NAME)

$(NAME): 
		@make -C libft/ fclean && make -C libft/
		@echo "Libft compiled."
		@make -C minilibx_macos/ clean && make -C minilibx_macos
		@echo "Minlibx compiled"
		@cp minilibx_macos/mlx.h ./includes
		@$(CC) $(CC_FLAGS) -c $(SRC_LIST) $(INC_FLAG)$(INC_DIR)
		@echo "Objects compiled."
		@$(CC) $(CC_FLAGS) -o $(NAME) $(O_FILES) $(LIB_FT_FLAG) -lft $(MLX_FLAG) -lmlx -framework OpenGL -framework AppKit $(INC_FLAG)$(INC_DIR)
		@echo "Fdf compiled."

clean:
		@rm -f $(O_FILES)
		@make -C libft/ clean
		@make -C minilibx_macos clean
		@echo "Objects cleaned."

fclean : clean
		@rm -f $(NAME)
		@make -C libft/ fclean
		@echo "Fdf cleaned."

re : fclean all
