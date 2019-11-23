# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sganon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/08 12:50:42 by sganon            #+#    #+#              #
#    Updated: 2019/11/23 19:24:02 by simon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
OS = $(shell uname)

NAME = fdf

BUILD_DIR ?= ./build
SRC_DIR = srcs

ifeq ($(OS), Linux)
	SRCS	= $(shell find $(SRC_DIR) -regex '[a-zA-Z.\/_0-9]+\.c$$')
endif
ifeq ($(OS), Darwin)
	SRCS	= $(shell find -E $(SRC_DIR) -regex '[a-zA-Z.\/_0-9]+\.c$$' | sed 's|^./||')
endif

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
CC_FLAGS = -Wall -Werror -Wextra
LIBFT_FLAG = -L./libft -lft
MLX_FLAG = -L./mlx_metal -lmlx
INC_FLAG = -I./includes -I./mlx_metal

all : $(NAME)

libs:
	@make -C libft/ re
	@make -C mlx_metal
	@echo "Libs compiled."


$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
ifeq ($(CC_JSON_FLAG), -MJ)
	$(CC) $(CC_JSON_FLAG) $@.json $(CC_FLAGS) -c $< -o $@ $(INC_FLAG)
else
	$(CC) $(CC_FLAGS) -c $< -o $@ $(INC_FLAG)
endif
	@echo "Objects compiled."

$(NAME): libs $(OBJS) 
		@$(CC) $(CC_FLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAG) $(MLX_FLAG) -lm $(INC_FLAG)
		@echo "Fdf compiled."

compile_commands.json:
	@rm -rf $(BUILD_DIR)
	@make CC_JSON_FLAG="-MJ" $(NAME)
	@/usr/bin/sed -e '1s/^/[\n/' -e '$$s/,$$/\n]/' $(BUILD_DIR)/**/*.o.json > compile_commands.json


clean:
		@rm -rf $(BUILD_DIR)
		@make -C libft/ fclean
		@echo "Objects and libraries cleaned."

fclean : clean
		@rm -f $(NAME)
		@echo "Fdf cleaned."

re : fclean all

.PHONY: all clean fclean re
