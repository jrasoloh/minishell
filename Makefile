# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/05 12:24:55 by jrasoloh          #+#    #+#              #
#    Updated: 2018/03/08 19:47:47 by jrasoloh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= minishell

CFLAGS 		= -Wall -Wextra #-Werror

INCLUDES 	= includes/minishell.h

SRCS 		= srcs/main.c\
			  srcs/tools.c\
			  srcs/exe.c\
			  srcs/error.c\
			  srcs/path.c\
			  srcs/echo.c\

OBJ 		= $(SRCS:.c=.o)

all 		: $(NAME) $(OBJ) $(SRCS)

$(NAME) 	: $(OBJ)
			make -C Libft
			gcc $(CFLAGS) $(SRCS) Libft/libft.a -I$(INCLUDES) -o $(NAME)

clean 		:
			make clean -C Libft
			rm -f $(OBJ)

fclean 		: clean
			make fclean -C libft
			rm -f $(NAME)

re 			: fclean all

.PHONY : clean fclean re
