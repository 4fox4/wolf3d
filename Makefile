SRC =	wolf3d.c hook.c parser.c ft_init.c fill_str.c raycaster.c key_move.c

OBJ =	wolf3d.o hook.o parser.o ft_init.o fill_str.o raycaster.o key_move.o

LIB = libft/libft.a

INC = libft/

NAME = wolf3d

FLAGS = -Wall -Wextra -Werror

XFLAG = -framework OpenGL -framework AppKit

all: libft.a mlx $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -c $(SRC) -I $(INC)
	gcc -o $(NAME) $(OBJ) $(XFLAG) $(LIB) minilibx_macos/libmlx.a

mlx:
	make -C minilibx_macos/

libft.a:
	make -C libft/

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C minilibx_macos/ clean

re: fclean all
