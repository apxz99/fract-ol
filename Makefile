# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/12 14:02:07 by sarayapa          #+#    #+#              #
#    Updated: 2026/03/06 16:34:12 by sarayapa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror


LIBMLX	:= ./MLX42

FILES = fractol_main.c fractol_parser.c fractol_utils.c fractol_hook.c 

SRCS = src/
BUILD = build/
INC = -Iinclude -Ilibft/include -I$(LIBMLX) -IMLX42/include/MLX42
LIB = $(LIBMLX)/build/libmlx42.a -ldl -pthread -lm -lglfw


SRCS_O = $(addprefix $(BUILD), $(FILES:.c=.o))

GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
BLUE = \033[1;34m
WHITE = \033[1m
RESET = \033[0m

all: libft libmlx $(BUILD) $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@echo "$(YELLOW)Building libft...$(RESET)"
	@make --no-print-directory -C libft

$(BUILD):
	@mkdir -p $(BUILD)

$(BUILD)%.o: $(SRCS)%.c
	@echo "$(YELLOW)Compiling file...$(RESET)"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(SRCS_O)
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $^ libft/libft.a $(LIB) -o $@
	@echo "$(GREEN)✔ $(NAME) ready Location: $(BLUE)$$(pwd)/$(YELLOW)$(NAME)$(RESET)"

norm:
	@echo "========= INCLUDES =========="
	@norminette ./include
	@echo "========= SOURCES ==========="
	@norminette $(SRCS)
	@echo "========= LIBFT ============="
	@norminette ./libft

clean:
	@make -s clean -C libft
	@echo "$(RED)Cleaned libft!$(RESET)"
	@rm -rf $(BUILD)
	@echo "$(RED)Cleaned objects!$(RESET)"
	@rm -rf $(LIBMLX)/build
	@echo "$(RED)Cleaned MLX42/build!$(RESET)"

fclean: clean
	@echo "$(RED)Removed $(NAME)!$(RESET)"
	@make -s fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft norm libmlx