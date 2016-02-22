# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sganon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/08 12:50:42 by sganon            #+#    #+#              #
#    Updated: 2016/02/22 11:55:40 by sganon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =	main.c \
		get_next_line.c \
		parsing.c \
		key_hook.c \
		image.c \
		ui.c \
		borders.c \
		init.c \
		check.c \
		color.c \

SRC_DIR = srcs/ \

SRC_LIST =	$(addprefix srcs/, $(SRC))

O_FILES = $(SRC:.c=.o)

CC = clang

CC_FLAGS = -Wall -Werror -Wextra

LIBFT_FLAG = -L./libft -lft

MLX_FLAG = -lmlx -framework AppKit -framework OpenGL 

INC_FLAG = -I./includes

all : $(NAME)

$(NAME): 
		@make -C libft/ fclean
		@make -C libft/
		@echo "Libft compiled."
		@$(CC) $(CC_FLAGS) -c $(SRC_LIST) $(INC_FLAG)$(INC_DIR)
		@echo "Objects compiled."
		@$(CC) $(CC_FLAGS) -o $(NAME) $(O_FILES) $(LIBFT_FLAG) $(MLX_FLAG) -lm $(INC_FLAG)
		@echo "Fdf compiled."

clean:
		@rm -f $(O_FILES)
		@make -C libft/ fclean
		@echo "Objects and libraries cleaned."

fclean : clean
		@rm -f $(NAME)
		@echo "Fdf cleaned."

re : fclean all
