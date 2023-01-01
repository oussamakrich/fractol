# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okrich <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 12:44:11 by okrich            #+#    #+#              #
#    Updated: 2023/01/01 12:44:16 by okrich           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra

LINKS = -lmlx -framework OpenGL -framework AppKit -ofast

SRC = main ft_printf draw utils mlx_utils events zoom 

OBJ = $(addsuffix .o , $(SRC))

all : $(NAME)

bonus : all

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(LINKS) $^ -o $@  

%.o : %.c fractol.h
	$(CC) $(CFLAGS) -c -Imlx $< 

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all 
