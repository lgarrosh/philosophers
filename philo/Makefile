NAME = philo
SRC_F = source/main.c
OBJ_F = $(SRC_F:.c=.o)
HEAD = include/philo.h
FLAGS = -Wall -Wextra -Werror -pthread

all: $(NAME)

$(NAME): $(OBJ_F) $(HEAD)
	cc $(FLAGS) -I $(HEAD) $(OBJ_F) -o $(NAME)
	
%.o: %.c
	cc $(FLAGS) -c $< -o $@

bonus:

clean:
	rm -rf $(OBJ_F)

fclean: clean
	rm -rf $(NAME)

re: fclean all