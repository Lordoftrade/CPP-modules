
NAME		=	megaphone

CC			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++98

SRC_DIR		=	./src
OBJS_DIR	=	./objs

SRC_FILES	=	$(SRC_DIR)/megaphone.cpp
OBJS_FILES	=	$(SRC_FILES:/%.cpp=$(OBJS_DIR)/%.o)


all: $(NAME)

$(NAME): $(OBJS_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_DIR)/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re