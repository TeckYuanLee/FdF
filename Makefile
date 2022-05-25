NAME	=	fdf
LIBFT	=	libft/libft.a
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I.
LIBRARY	=	-lmlx -framework OpenGL -framework AppKit

SRCS	=	main_img.c
OBJS	=	$(SRCS:c=o)

all: $(NAME)

$(NAME):		$(OBJS) 
		@$(MAKE) all -sC ./libft
		@$(CC) $(SRCS) $(LIBFT) $(LIBRARY) -o $(NAME)
		@$(MAKE) clean -sC ./libft
		@rm -f $(OBJ)

clean:
		@$(MAKE) clean -sC ./libft
		@rm -f $(OBJ)

fclean:	clean
			@$(MAKE) fclean -sC ./libft
			@rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re