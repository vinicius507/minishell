NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./libft/includes -I./src
LIBS = -L./libft -lft -lreadline
LIBFT = ./libft/libft.a
RM = rm -rf

vpath %.c src src/builtins src/env src/lexer src/execute src/signals
SRCS = main.c exit.c pwd.c lex.c echo.c env.c set_env.c \
	setup_env.c get_env.c free_env.c export.c get_builtin.c \
	unset_env.c unset.c cd.c prompt.c tokens.c word.c char.c \
	get_env_key.c redirect.c is_builtin.c args.c execute_bin.c \
	execute_builtin.c error.c handle_redirects.c command.c \
	redirections.c heredoc.c command_utils.c signals.c sig_child.c \
	sig_parent.c sig_prompt.c heredoc_utils.c sig_heredoc.c \
	cleanup_process.c execute_simple_cmd.c pipeline.c execute_pipeline.c

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
