NAME = avm

CC = clang++
FLAGS = -Wall -Wextra -Werror --std=c++11

CPP_DIR = srcs

SRC := $(wildcard $(CPP_DIR)/*.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJ)
	@$(CC) -o $@ $^
	@echo "\033[0;32m$(NAME) : Compilation successful !! \033[0;32m"

%.o: %.cpp
	@$(CC) -o $@ -c $< $(FLAGS)

clean:
	@rm $(OBJ)

fclean: clean
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
