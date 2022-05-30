# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: telee <telee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/28 10:32:20 by telee             #+#    #+#              #
#    Updated: 2022/05/30 11:42:49 by telee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
LIBFT	=	libft/libft.a
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I. -c
LIBRARY	=	-lmlx -framework OpenGL -framework AppKit
ARFLAGS	= 	rcs

SRCS	=	$(wildcard ./*.c)
OBJS	=	$(SRCS:./%.c=./%.o)

obj/%.o:	srcs/%.c
				@gcc $(FLAGS) -c $< -o $@ -Iincludes

all: $(NAME)

$(NAME):		$(OBJS) 
		@$(MAKE) all -sC ./libft
		@$(CC) $(SRCS) $(LIBFT) $(LIBRARY) -o $(NAME)
		@$(MAKE) clean -sC ./libft
		@rm -f $(OBJS)

clean:
		@$(MAKE) clean -sC ./libft
		@rm -f $(OBJS)

fclean:	clean
			@$(MAKE) fclean -sC ./libft
			@rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re