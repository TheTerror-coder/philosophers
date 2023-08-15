# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 21:26:28 by TheTerror         #+#    #+#              #
#    Updated: 2023/08/15 22:48:58 by TheTerror        ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = philo

INCLUDE = preprocss.h philo.h


CC = 				cc
CFLAGS=				-Wall -Werror -Wextra
RM =				rm -rf

SRC = main.c parsing.c time.c philo.c init.c activity.c

OBJ = $(SRC:%.c=%.o)

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) -I. $(OBJ) -o $@



clean :
	@$(RM) $(OBJ)
fclean : clean
	@$(RM) $(NAME)
re : fclean all