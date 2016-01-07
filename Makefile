NAME = AbstractVM

C_DIR = srcs
O_DIR = o
FLAGS = -Wall -Wextra -Werror -std=c++11

C_FILES = $(shell find $(C_DIR) -type f -print | grep "\.s")
C_DIRS = $(shell find $(C_DIR) -type d -print)

O_DIRS = $(C_DIRS:$(C_DIR)/%=$(O_DIR)/%)
O_FILES = $(C_FILES:$(C_DIR)/%.s=$(O_DIR)/%.o)

all: $(NAME)

$(NAME): $(O_FILES)


$(O_DIR)/%.o: $(C_DIR)/%.s
	@mkdir -p $(O_DIRS) $(O_DIR)
	@nasm $(FLAGS) -o $@ $<

clean:
	@rm $(O_FILES)
	@rmdir $(O_DIRS) $(O_DIR)

fclean: clean
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
