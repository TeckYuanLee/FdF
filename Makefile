NAME	=	fdf
LIBFT	=	libft/libft.a
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I.
LIBRARY	=	-lmlx -framework OpenGL -framework AppKit
ARFLAGS	= 	rcs

SRCS	=	main.c draw.c\
OBJS	=	$(SRCS:c=o)

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