# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trgascoi <trgascoi@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/11 17:52:01 by trgascoi          #+#    #+#              #
#    Updated: 2026/08/13 16:32:59 by trgascoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS       = $(filter-out %_bonus.s,$(wildcard srcs/*.s))
BONUS_SRCS = $(wildcard srcs/*_bonus.s)
OBJS       = $(SRCS:.s=.o)
BONUS_OBJS = $(BONUS_SRCS:.s=.o)

BONUS_ONLY_TESTS = tests/test_atoi_base.c tests/test_list_size.c \
                    tests/test_list_push_front.c

TEST_SRCS        = $(filter-out $(BONUS_ONLY_TESTS),$(wildcard tests/*.c))
BONUS_TEST_SRCS  = $(wildcard tests/*.c)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.s
	nasm -f elf64 $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) test_libasm test_libasm_bonus

re: fclean all

test: $(NAME)
	cc -Wall -Wextra -Werror $(TEST_SRCS) $(NAME) -o test_libasm
	./test_libasm

test_bonus: bonus
	cc -Wall -Wextra -Werror -DBONUS $(BONUS_TEST_SRCS) $(NAME) -o test_libasm_bonus
	./test_libasm_bonus

.PHONY: all clean fclean re test bonus test_bonus
