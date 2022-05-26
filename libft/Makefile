# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: telee <telee@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/04 14:50:07 by telee             #+#    #+#              #
#    Updated: 2021/06/27 10:13:38 by telee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
FLAGS		= -Wall -Werror -Wextra -I. -c
SRC			= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
		  		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c\
		  		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c\
		  		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c\
		  		ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
		  		ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c\
		  		ft_substr.c ft_tolower.c ft_toupper.c\
				ft_putchar.c ft_putstr.c ft_putnbr.c ft_decToHexa.c ft_itoa_long.c\
				ft_decToHexaBig.c ft_abs.c ft_strncpy.c ft_atoi_sizet.c

BONUS		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
			  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ			= $(SRC:.c=.o)

BONUS_OBJ	= $(BONUS:c=o)

all: 		$(NAME)

$(NAME): 	$(OBJ)
				@ar rcs $(NAME) $(OBJ)

$(OBJ): 	$(SRC)
				@gcc $(FLAGS) -c $(SRC) -I libft.h

clean:
				@rm -f $(OBJ) $(BONUS_OBJ)

fclean: 	clean
				@rm -f $(NAME)

re: 		fclean all

bonus:		$(OBJ) $(BONUS_OBJ)
				@ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

.PHONY:		all clean fclean re bonus
