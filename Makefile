# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/11 17:52:01 by trgascoi          #+#    #+#              #
#    Updated: 2026/08/11 22:59:53 by trgascoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS       = $(wildcard srcs/*.s)
OBJS       = $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.s
	nasm -f elf64 $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) test_libasm

re: fclean all

test: $(NAME)
	cc -Wall -Wextra -Werror tests/main.c $(NAME) -o test_libasm
	./test_libasm

.PHONY: all clean fclean re test
