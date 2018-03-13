# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/05 12:24:55 by jrasoloh          #+#    #+#              #
#    Updated: 2018/03/13 13:14:18 by jrasoloh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= minishell

CFLAGS 		= -Wall -Wextra -Werror

INCLUDES 	= includes/minishell.h

SRCS 		= srcs/main.c\
			  srcs/builtin.c\
			  srcs/ft_split.c\
			  srcs/dir.c\
			  srcs/dir_tools.c\
			  srcs/variables.c\
			  srcs/main_tools.c\
			  srcs/tools.c\
			  srcs/exe.c\
			  srcs/error.c\
			  srcs/path.c\
			  srcs/echo.c\
			  srcs/tri.c\

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
