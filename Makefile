# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 05:44:17 by olopez-s          #+#    #+#              #
#    Updated: 2025/07/17 00:57:02 by olopez-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME       = pushswap
# CC         = gcc

# SRC_DIR    = src
# OBJ_DIR    = obj
# SRCS       = $(wildcard $(SRC_DIR)/*.c)
# OBJS       = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# LIBFT_DIR  = libft
# LIBFT      = $(LIBFT_DIR)/libft.a

# # include paths: your headers + libft’s headers
# CFLAGS     = -Wall -Wextra -Werror -Iincludes -I$(LIBFT_DIR) -g -Og

# # Default target: build libft, then pushswap
# all: $(LIBFT) $(NAME)

# # Build libft first
# $(LIBFT):
# 	@$(MAKE) -C $(LIBFT_DIR)

# # Link your executable
# $(NAME): $(OBJS)
# 	@echo "Linking $(NAME)..."
# 	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# # Compile each source file
# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
# 	@echo "Compiling $<..."
# 	@$(CC) $(CFLAGS) -c $< -o $@

# # Ensure obj directory exists
# $(OBJ_DIR):
# 	@mkdir -p $(OBJ_DIR)

# # Remove only pushswap objects
# clean:
# 	@$(MAKE) -C $(LIBFT_DIR) clean
# 	@rm -rf $(OBJ_DIR)

# # Remove everything, including the binary
# fclean: clean
# 	@rm -f $(NAME)
# 	@$(MAKE) -C $(LIBFT_DIR) fclean

# # Rebuild from scratch
# re: fclean all

# .PHONY: all clean fclean re
#

# **************************************************************************** #
#                                   Makefile                                   #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iincludes -Ilibft
RM          = rm -f

# ---------------------------- Sources & Objects ----------------------------- #

SRC_DIR     = src
OBJ_DIR     = obj

SRC         = $(wildcard $(SRC_DIR)/*.c)
OBJ         = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# ------------------------------- Libft Path -------------------------------- #

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

# --------------------------------- Rules ----------------------------------- #

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "🔗 Linking objects with libft into $(NAME)..."
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "✅ Build complete!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "⚙️  Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@echo "📚 Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@echo "🧹 Cleaning object files..."
	@$(RM) $(OBJ)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@echo "🗑️  Removing executable and libft..."
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "💨 Full clean done!"

re: fclean all
	@echo "🔄 Rebuilt everything!"

.PHONY: all clean fclean re