NAME = philo_bonus
SRC_F = main_bonus.c error_bonus.c \
		liba_bonus.c init_bonus.c \
		utils_bonus.c
OBJ_F = $(SRC_F:.c=.o)
HEAD = philo_bonus.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_F) $(HEAD)
	cc $(FLAGS) -I $(HEAD) $(OBJ_F) -o $(NAME)
	
%.o: %.c
	cc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_F)

fclean: clean
	rm -rf $(NAME)

re: fclean all