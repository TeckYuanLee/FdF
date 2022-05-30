# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: telee <telee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/28 10:32:20 by telee             #+#    #+#              #
#    Updated: 2022/05/30 18:25:39 by telee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
LIBFT	=	libft/libft.a
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I. -c
LIBRARY	=	-lmlx -framework OpenGL -framework AppKit
ARFLAGS	= 	rcs

SRCS	=	$(wildcard ./*.c)
OBJS	=	$(SRCS:./%.c=obj/%.o)

obj/%.o:	%.c
		@mkdir -p obj
		@gcc $(FLAGS) -c $< -o $@ -Iincludes

all: $(NAME)

$(NAME):		$(OBJS) 
		@$(CC) $(SRCS) $(LIBFT) $(LIBRARY) -o $(NAME)
		@$(MAKE) clean -sC ./libft

clean:
		@rm -f $(OBJS)

fclean:	clean
			@rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re