FT_FILE:= ft_$(shell basename *main.c | sed s/_main//)
NAME= libft.a
NAME_FILE:= ft_$(shell basename *main.c .c| sed s/_main//)
FT_MAIN:= *main.c
GCC_FLAGS = -Wall\
			-Werror\
			-Wextra
OBJ = ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_strlen.o ft_memset.o ft_bzero.o
#gcc  *main.c > xargs "ft_$(basename *main.c | sed s/_main//)" 
all: $(NAME)

$(NAME): obj lib

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

compile: lib
	gcc $(GCC_FLAGS) $(FT_MAIN) -L. -lft

obj: $(OBJ)

lib: obj
	ar rc libft.a $(OBJ)

%.o: %.c libft.h
	gcc -c $< -o $@