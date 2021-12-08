NAME = push_swap
CC = gcc
C_FLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
OBJ_DIR = obj
SRCS =	push_swap	list_utils	read_utils	write_utils	\
		supporting_sort	stack_a_utils	stack_b_utils	sort_utils \
		list_utils_2
HEADERS_DIR = includes
HEADERS = $(HEADERS_DIR)/push_swap.h
SRC_FILE = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRCS)))
OBJ_FILE = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRCS)))

all: $(NAME)

$(NAME): $(OBJ_FILE)
	$(CC) $(C_FLAGS) $(OBJ_FILE) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	mkdir -p $(@D)
	$(CC) -c $(C_FLAGS) -I$(HEADERS_DIR) $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re