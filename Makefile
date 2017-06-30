# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/04 17:19:25 by tettouat          #+#    #+#              #
#    Updated: 2015/06/10 17:24:50 by tettouat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = YOLO

all: $(NAME)

$(NAME):
	make -C libft/
	make -C ft_p-client/
	cp ft_p-client/client client
	make -C ft_p-server/
	cp ft_p-server/serveur serveur

clean:
	make -C libft/ clean
	make -C ft_p-client/ clean
	make -C ft_p-server/ clean

fclean:
	make -C libft/ fclean
	make -C ft_p-client/ fclean
	make -C ft_p-server/ fclean
	rm -f client
	rm -f server

re: fclean all

.PHONY: all clean fclean re
