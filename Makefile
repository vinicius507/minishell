NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./libft/includes -I./src
LIBS = -L./libft -lft -lreadline
LIBFT = ./libft/libft.a
RM = rm -rf

vpath %.c src src/builtins src/env src/lexer
SRCS = main.c exit.c pwd.c lex.c echo.c env.c set_env.c \
	setup_env.c get_env.c free_env.c export.c get_builtin.c \
	unset_env.c unset.c cd.c prompt.c execute.c tokens.c \
	word.c char.c get_env_key.c redirect_out.c

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
