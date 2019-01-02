# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mponomar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/08 17:12:01 by mponomar          #+#    #+#              #
#    Updated: 2018/07/08 17:12:08 by mponomar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = src/
INC = includes/
LIBFT = libft/
FT_INC = $(LIBFT)/includes

CMP =	main.o

all: $(NAME)

$(NAME): $(CMP)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME) -L $(LIBFT) -lft $(CMP)
	@echo "made" $(NAME)

$(CMP): %.o: $(SRC)%.c
	@$(CC) -c $(FLAGS) -I $(FT_INC) -I $(INC) $< -o $@

clean:
	@-/bin/rm -f $(CMP)
	@-make clean -C $(LIBFT)
	@echo "cleaned" $(NAME)

fclean: clean
	@-/bin/rm -f $(NAME)
	@-make fclean -C $(LIBFT)
	@echo "fcleaned" $(NAME)

re: fclean all

rmf:
	rm *~
	rm \#*
	rm *.out
