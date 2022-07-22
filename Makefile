NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./libft/includes
LIBS = -L./libft -lft -lreadline
LIBFT = ./libft/libft.a
SRCS = main.c
RM = rm -rf

all: $(NAME) 

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) main.c $(LIBS) -o $@

$(LIBFT):
	make -C ./libft/

clean:
	echo "Not implemented"

fclean:
	$(RM) $(NAME)

re: fclean all