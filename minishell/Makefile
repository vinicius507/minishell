# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 09:50:45 by vgoncalv          #+#    #+#              #
#    Updated: 2024/07/30 10:34:53 by vgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS := -lft -lreadline

RM = rm -rf

vpath %.c src src/builtins src/env src/lexer src/execute src/signals
SRCS = main.c exit.c pwd.c lex.c echo.c env.c set_env.c \
	setup_env.c get_env.c free_env.c export.c get_builtin.c \
	unset_env.c unset.c cd.c prompt.c tokens.c word.c char.c \
	get_env_key.c redirect.c is_builtin.c args.c execute_bin.c \
	execute_builtin.c error.c handle_redirects.c command.c \
	redirections.c heredoc.c command_utils.c signals.c sig_child.c \
	sig_parent.c sig_prompt.c heredoc_utils.c sig_heredoc.c \
	cleanup_process.c execute_simple_cmd.c pipeline.c execute_pipeline.c \
	utils.c

OBJS_DIR = ./objs
OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

ifneq ($(LIBFT_DIR),)
	CFLAGS += -I $(LIBFT_DIR)/include
	LIBFT = $(LIBFT_DIR)/libft.a
	LIBS := -L$(LIBFT_DIR) $(LIBS)
endif

all: $(NAME)

$(NAME): $(OBJS) $(if $(LIBFT_DIR), $(LIBFT))
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $@

clean:
	$(RM) $(OBJS_DIR)
ifdef LIBFT_DIR
	make clean -C $(LIBFT_DIR)
endif

fclean:
	$(RM) $(OBJS_DIR)
	$(RM) $(NAME)
ifdef LIBFT_DIR
	make fclean -C $(LIBFT_DIR)
endif


re: fclean all
