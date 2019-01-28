# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 08:17:01 by nde-jesu          #+#    #+#              #
#    Updated: 2019/01/16 17:46:56 by reda-con         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
FLAGS = -Wall -Werror -Wextra 
LIBRARIES = -lmlx -lft -L$(LIBFT_DIR) -L$(MLX_DIR) -framework OpenGL \
			-framework AppKit
INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_HEAD) -I$(MLX_HEAD)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./Libft/
LIBFT_HEAD = $(LIBFT_DIR)includes/

MLX = $(MLX_DIR)libmlx.a
MLX_DIR = /usr/local/lib/
MLX_HEAD = $(MLX_DIR)/../include/mlx.h

HEADERS_LIST = fdf.h mlx_macro_keys.h
HEADERS_DIR = ./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRC_LIST = command.c control.c free_all.c init.c list_tools.c main.c menu.c \
		   mouse.c parse.c print.c projection.c segment_control.c utile.c\
		   color.c
SRC_DIR = ./src/
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))


YELLOW = \033[033m
GREEN = \033[032m
BLUE = \033[36m
RED = \033[031m
PURPLE = \033[35m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJ)
	@echo "$(RED)Sources compilation $(RESET)[$(BLUE)OK$(RESET)]\n"
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJ) -o $(NAME)
	@sleep 1
	@echo "[$(BLUE) FdF Compiled $(RESET)]"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "\n$(BLUE)Obj directory...$(RESET)[$(GREEN)created$(RESET)]\n"
	@sleep 1

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(YELLOW)$(notdir $(basename $@))...$(RESET)[$(GREEN)OK$(RESET)]"

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)
	@sleep 1

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "\n$(RED)Obj directory...$(RESET)[$(PURPLE)deleted$(RESET)]\n"
	@sleep 1

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(RED)Libft...$(RESET)[$(PURPLE)deleted$(RESET)]\n"
	@sleep 1
	@rm -f $(NAME)
	@echo "$(RED)FdF...$(RESET)[$(PURPLE)deleted$(RESET)]\n"
	@sleep 1

re:
	@$(MAKE) fclean
	@$(MAKE) all
