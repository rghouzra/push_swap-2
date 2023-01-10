# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 23:20:52 by bel-idri          #+#    #+#              #
#    Updated: 2023/01/10 19:07:21 by bel-idri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c \
	libft.c \
	libft_2.c \
	libft_3.c \
	instructions.c \
	instructions_utils.c \
	parsing.c \
	parsing_utils.c \
	push_swap.c \
	sorting.c \
	sorting_utils.c \
	sorting_utils_2.c \
	sorting_utils_3.c \
	sorting_utils_4.c \
	largest_increasing_sequence.c \

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
