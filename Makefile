# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/05 09:23:08 by cglanvil          #+#    #+#              #
#    Updated: 2019/07/05 09:51:42 by cglanvil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl
FILES = main.c \
		get_next_line.c \
		libft/libft.a
all: $(NAME)
$(NAME):
	gcc -Wall -Wextra -Werror $(FILES) -o $(NAME)
fclean:
	rm -f $(NAME)
re: fclean all

