NAME = philo

SRC = main.c

INC = philo.h

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

philo: $(SRC) $(INC)
		gcc $(SRC) $(FLAGS) -o philo

clean: 
		rm -rf $(NAME)

fclean: clean

re: clean all