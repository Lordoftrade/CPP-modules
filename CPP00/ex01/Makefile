NAME = phonebook

CС = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I./include

SRC_DIR = src
INC_DIR = include
OBJ_DIR = objs

SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/Contact.cpp $(SRC_DIR)/PhoneBook.cpp
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CС) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CС) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
