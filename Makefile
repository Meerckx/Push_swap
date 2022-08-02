# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 14:55:46 by anonymous         #+#    #+#              #
#    Updated: 2022/04/10 19:03:18 by anonymous        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	push_swap

CHECKER			:=	checker

LIBFT_DIR		:=	libft

HEADERS			:=	include/push_swap.h $(LIBFT_DIR)/includes/ft_printf.h $(LIBFT_DIR)/includes/get_next_line.h\
					$(LIBFT_DIR)/includes/libft.h

LIBFT			:=	$(LIBFT_DIR)/libft.a

SRCS			:=	src/push_swap.c src/parsing.c src/stack_utils.c src/stack_utils_index.c src/swap_commands.c src/push_commands.c\
					src/rotate_commands.c src/reverse_rotate_commands.c src/init_stacks.c src/sort.c src/large_sort.c\
					src/small_sort.c src/small_sort_utils.c src/error.c

SRCS_B			:=	src_b/checker.c src_b/error.c src_b/init_stacks.c src_b/parsing.c src_b/push_commands.c src_b/rotate_commands.c\
					src_b/reverse_rotate_commands.c src_b/stack_utils.c src_b/stack_utils_index.c src_b/swap_commands.c

OBJS			:=	$(SRCS:%.c=%.o)
OBJS_B			:=	$(SRCS_B:%.c=%.o)

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror
LDLIBS			:=	-L$(LIBFT_DIR) -lft

.PHONY : all bonus clean fclean re

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LDLIBS) -o $(NAME)

$(CHECKER) : $(LIBFT) $(OBJS_B)
	$(CC) $(OBJS_B) $(LDLIBS) -o $(CHECKER)

$(LIBFT) :
	$(MAKE) --directory=$(LIBFT_DIR)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(CHECKER)

clean :
	rm -rf $(OBJS)
	rm -rf $(OBJS_B)
	$(MAKE) clean --directory=$(LIBFT_DIR)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(CHECKER)
	$(MAKE) fclean --directory=$(LIBFT_DIR)

re : fclean all