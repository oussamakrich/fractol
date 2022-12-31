
NAME = fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra

LINKS = -lmlx -framework OpenGL -framework AppKit

SRC = main ft_printf draw utils mlx_utils events zoom 

OBJ = $(addsuffix .o , $(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(LINKS) $^ -o $@  

%.o : %.c fractol.h
	$(CC) $(CFLAGS) -Imlx $< 

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all 
