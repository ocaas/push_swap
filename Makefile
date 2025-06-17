# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 05:44:17 by olopez-s          #+#    #+#              #
#    Updated: 2025/06/17 04:49:03 by olopez-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME    = libft.a
CC      = cc
AR      = ar
CFLAGS  = -Wall -Wextra -Werror
INCLUDES= -I.

# All .c files live directly in libft/
SRC     = $(wildcard *.c)
OBJ     = $(SRC:.c=.o)

all: $(NAME)

# Archive the .o files into libft.a
$(NAME): $(OBJ)
	@echo "Linking $(NAME)..."
	@$(AR) rcs $(NAME) $(OBJ)

# Compile each .c → .o
%.o: %.c
	@echo "  CC $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Cleaning libft objects..."
	@rm -f $(OBJ)

fclean: clean
	@echo "Removing libft archive..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
