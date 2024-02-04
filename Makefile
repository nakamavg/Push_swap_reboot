# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgomez-m <aecm.davidgomez@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 19:07:08 by dgomez-m          #+#    #+#              #
#    Updated: 2024/02/04 08:30:21 by dgomez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBFT = lib/libft/libft.a
FT_PRINTF = lib/ft_printf/libftprintf.a
INCLUDES = -I include
SRCS = parse_input_utils.c parse_input.c sort_stack_utils.c sort_stack.c \
sorting_array_tools.c stack_builder.c stack_functions.c main.c error.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C lib/libft
	$(MAKE) -C lib/ft_printf
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/ft_printf clean
		rm -f $(OBJS)

fclean: clean
	$(MAKE) -C lib/libft fclean
	$(MAKE) -C lib/ft_printf fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re