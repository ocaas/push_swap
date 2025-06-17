# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/16 06:27:42 by olopez-s          #+#    #+#              #
#    Updated: 2025/06/17 04:39:02 by olopez-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME     = libft.a
CC       = cc
AR       = ar
CFLAGS   = -Wall -Wextra -Werror
INCLUDES = -I.

SRC_DIR  = src
OBJ_DIR  = obj

# all .c files under src/
SRCS     = $(wildcard $(SRC_DIR)/*.c)
# corresponding .o files go into obj/
OBJS     = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Default rule: build the archive
all: $(NAME)

# Archive rule: only runs if OBJS exist
$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@$(AR) rcs $(NAME) $(OBJS)

# Compile each .c → .o
# The pipe '|' before $(OBJ_DIR) makes sure the directory exists first
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "  CC $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Ensure obj directory exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "Cleaning objects in libft..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
