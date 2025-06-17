# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/16 06:27:42 by olopez-s          #+#    #+#              #
#    Updated: 2025/06/17 05:59:00 by olopez-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
CC = cc
AR = ar
ARFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror
INCLUDES= -I.

# all .c files live directly in this folder
SRCS    = $(wildcard *.c)
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

# create the archive from all .o files
$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

# compile each .c → .o
%.o: %.c
	@echo "  CC $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Cleaning libft objects..."
	@rm -f $(OBJS)

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

