# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: telee <telee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/28 10:32:20 by telee             #+#    #+#              #
#    Updated: 2022/05/31 19:49:37 by telee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
LIBFT	=	libft/libft.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -I.  -c #-Werror
LIBRARY	=	-lmlx -framework OpenGL -framework AppKit
ARFLAGS	= 	rcs

SRCS	=	$(wildcard srcs/*.c)
OBJS	=	$(SRCS:srcs/%.c=obj/%.o)

obj/%.o:	srcs/%.c
		@mkdir -p obj
		gcc $(CFLAGS) -c $< -o $@ -Iincludes

all: $(NAME)

$(NAME):		$(OBJS) 
		$(CC) -fsanitize=address -g3 $(SRCS) $(LIBFT) $(LIBRARY) -o $(NAME)
		@$(MAKE) clean -sC ./libft

clean:
		@rm -f $(OBJS)

fclean:	clean
			@rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re