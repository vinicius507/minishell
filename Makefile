NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./libft/includes -I./src
LIBS = -L./libft -lft -lreadline
LIBFT = ./libft/libft.a
RM = rm -rf

vpath %.c src src/builtins
SRCS = main.c exit.c pwd.c lexer.c echo.c

OBJ_DIR = ./objs
OBJECTS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all: $(NAME) 

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) $(LIBS) -o $@

$(LIBFT):
	make -C ./libft/

$(OBJ_DIR)/%.o: %.c 
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	make clean -C ./libft

fclean:
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)
	make fclean -C ./libft

re: fclean all