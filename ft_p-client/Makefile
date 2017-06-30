# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/04 17:26:17 by tettouat          #+#    #+#              #
#    Updated: 2015/06/04 17:53:54 by tettouat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client

LIB = ../libft/libft.a

CFLAG = -Wall -Wextra -Werror

SRCC = client.c handle_cd.c handle_get.c handle_ls.c \
		handle_put.c handle_pwd.c handle_quit.c \
		stream.c write_stream.c read_signed.c \
		read_unsigned.c read_line.c

SRCO = $(SRCC:.c=.o)

all: $(NAME)

$(NAME): $(SRCO) $(LIB)
	gcc $(SRCO) $(LIB) -o $(NAME) $(CFLAG)

%.o: %.c
	gcc $(CFLAG) -c $< -o $@

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
