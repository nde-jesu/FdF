# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 15:08:50 by nde-jesu          #+#    #+#              #
#    Updated: 2019/01/16 09:20:06 by nde-jesu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Wconversion

SRC = ft_isalpha \
	  ft_isdigit \
	  ft_isalnum \
	  ft_isascii \
	  ft_isprint \
	  ft_tolower \
	  ft_toupper \
	  ft_strlen \
	  ft_strcpy \
	  ft_strncpy \
	  ft_strcat \
	  ft_strncat \
	  ft_strlcat \
	  ft_strdup \
	  ft_strstr \
	  ft_strnstr \
	  ft_strcmp \
	  ft_strncmp \
	  ft_strchr \
	  ft_strrchr \
	  ft_atoi \
	  ft_memset \
	  ft_bzero \
	  ft_memcpy \
	  ft_memccpy \
	  ft_memmove \
	  ft_memchr \
	  ft_memcmp \
	  ft_memalloc \
	  ft_memdel \
	  ft_strnew \
	  ft_strdel \
	  ft_strclr \
	  ft_striter \
	  ft_striteri \
	  ft_strmap \
	  ft_strmapi \
	  ft_strequ \
	  ft_strnequ \
	  ft_strsub \
	  ft_strjoin \
	  ft_strtrim \
	  ft_strsplit \
	  ft_itoa \
	  ft_putchar \
	  ft_putstr \
	  ft_putendl \
	  ft_putnbr \
	  ft_putchar_fd \
	  ft_putstr_fd \
	  ft_putendl_fd \
	  ft_putnbr_fd \
	  ft_lstnew \
	  ft_lstdelone \
	  ft_lstdel \
	  ft_lstadd \
	  ft_lstiter \
	  ft_lstmap \
	  ft_strndup \
	  ft_strrev \
	  ft_lstfind \
	  ft_lstiter_if \
	  ft_lstrev \
	  ft_intlen \
	  ft_lstlen \
	  ft_strrealloc \
	  ft_strccat \
	  ft_itoa_base \
	  get_next_line \
	  ft_swap \
	  ft_abs

OBJDIR = obj/
CLEANOBJDIR = OBJDIR
CLEANOBJ = OBJ

SRCDIR = srcs/

SRCNAME = $(addprefix $(SRCDIR), $(addsuffix .c, $(SRC)))

OBJ = $(addprefix $(OBJDIR), $(addsuffix .o, $(SRC)))

INCDIR = includes/

all: $(NAME)

.PHONY: all clean fclean re

$(OBJDIR)%.o:$(SRCDIR)%.c
		@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)
		@echo "\033[033m$(notdir $(basename $@))...\033[0m[\033[32mOK\033[0m\033[00m]"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "[ \033[36mLibft compiled\033[00m ]"

clean:
		@rm -rf $(OBJ) $(OBJDIR)
		@echo "\033[031mCleaning libft...\033[0m[\033[35mComplete\033[0m\033[00m]"

fclean: clean
		@rm -f $(NAME)
		@echo "\033[031mFull cleaning libft...\033[0m[\033[35mComplete\033[0m\033[00m]"

re: fclean all

