# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrasoloh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/23 18:57:55 by jrasoloh          #+#    #+#              #
#    Updated: 2018/04/11 13:01:14 by jrasoloh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= minishell

CFLAGS 		= -Wall -Werror -Wextra

INCLUDES 	= includes/minishell.h

SRCS 		= srcs/dir.c\
			  srcs/dir_tools.c\
			  srcs/dotdot.c\
			  srcs/echo.c\
			  srcs/env.c\
			  srcs/env_tools.c\
			  srcs/error.c\
			  srcs/exe.c\
			  srcs/init_env.c\
			  srcs/main.c\
			  srcs/main_tools.c\
			  srcs/path.c\
			  srcs/split.c\
			  srcs/str.c\

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
