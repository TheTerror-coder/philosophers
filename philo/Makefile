# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 21:26:28 by TheTerror         #+#    #+#              #
#    Updated: 2023/11/15 16:28:51 by TheTerror        ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

### EXECUTABLE ###
NAME = philo

### DIRECTORIES PATHS ###
OBJ_PATH = ./objs/

### INCLUDE FILES ###
INCLUDE = preprocss.h philo.h

### VARIABLES ###
CC = 				cc
CFLAGS=				-Wall -Werror -Wextra -pthread
RM =				rm -rf

### SOURCE FILES ###
SRC = main.c parsing.c time.c philo.c init.c activity.c

### OBJECT FILES ###
OBJ = $(addprefix $(OBJ_PATH), $(SRC:%.c=%.o))


### RULES ###

all : mk_objs_dir $(NAME)

$(OBJ_PATH)%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) -I. $(OBJ) -o $@

c : all clean

mk_objs_dir :
	@mkdir -p $(OBJ_PATH)

clean :
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_PATH)
fclean : clean
	@$(RM) $(NAME)
re : fclean all