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

# **************************************************************************** #
#                                   Makefile                                   #
# **************************************************************************** #

NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

# ---------------------------- Sources & Objects ----------------------------- #

SRC     = $(wildcard $(SRC_DIR)/*.c)
OBJ     = $(SRC:.c=.o)

# ------------------------------- Libft Path -------------------------------- #

LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a

INCLUDE  = push_swap.h

# --------------------------------- Rules ----------------------------------- #

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "🔗 Linking objects with libft into $(NAME)..."
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "✅ Build complete!"

%.o: %.c $(INCLUDE)
	@echo "⚙️  Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

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
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "💨 Full clean done!"

re: fclean all
	@echo "🔄 Rebuilt everything!"

.PHONY: all clean fclean re
