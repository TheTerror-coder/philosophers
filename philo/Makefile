# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 21:26:28 by TheTerror         #+#    #+#              #
#    Updated: 2023/08/16 02:37:56 by TheTerror        ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = philo

OBJ_PATH = ./objs/

INCLUDE = preprocss.h philo.h


CC = 				cc
CFLAGS=				-Wall -Werror -Wextra
RM =				rm -rf

SRC = main.c parsing.c time.c philo.c init.c activity.c

OBJ = $(addprefix $(OBJ_PATH), $(SRC:%.c=%.o))

$(OBJ_PATH)%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) -I. $(OBJ) -o $@

clean :
	@$(RM) $(OBJ)
fclean : clean
	@$(RM) $(NAME)
re : fclean all