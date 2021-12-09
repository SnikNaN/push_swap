NAME = push_swap
B_NAME = checker
CC = gcc
C_FLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
B_SRC_DIR = srcs_bonus
OBJ_DIR = obj
SRCS =	push_swap	list_utils	read_utils	write_utils	\
		supporting_sort	stack_a_utils	stack_b_utils	sort_utils \
		list_utils_2
B_SRCS = checker_bonus	write_utils_bonus	stack_utils_1_bonus	\
		stack_utils_2_bonus	list_utils_bonus	read_utils_bonus
HEADERS_DIR = includes
HEADERS = $(HEADERS_DIR)/push_swap.h
SRC_FILE = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRCS)))
OBJ_FILE = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRCS)))

all: $(NAME)

bonus:
	make SRCS="$(B_SRCS)" SRC_DIR="$(B_SRC_DIR)" $(B_NAME)

$(NAME): $(OBJ_FILE)
	$(CC) $(C_FLAGS) $(OBJ_FILE) -o $(NAME)

$(B_NAME): $(OBJ_FILE)
	$(CC) $(C_FLAGS) $(OBJ_FILE) -o $(B_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	mkdir -p $(@D)
	$(CC) -c $(C_FLAGS) -I$(HEADERS_DIR) $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(B_NAME)

re: fclean all

.PHONY: all, clean, fclean, re, bonus