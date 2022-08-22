/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 20:54:19 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/20 16:31:22 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <minishell.h>
# include <fcntl.h>

# define HDOC_TMPFILE "/tmp/heredoc"

typedef enum e_redirection_type
{
	RED_STDOUT,
	RED_STDIN,
	RED_APPND,
	RED_HDOC,
	RED_COUNT,
}	t_redirection_type;

typedef struct s_redirection
{
	t_redirection_type		type;
	char					*content;
	struct s_redirection	*next;
}	t_redirection;

typedef struct s_command
{
	char				*bin_path;
	int					argc;
	char				**argv;
	char				**envp;
	t_redirection		*redirections;
}	t_command;

int				count_argc(t_token *tokens);

char			**build_argv(t_token *tokens);

int				execute_builtin(t_command *command);

void			execute_bin(t_command *command);

void			free_redirections(t_redirection *redirection);

t_redirection	*new_redirection(t_type type, t_redirection *prev);

t_redirection	*get_redirections(t_token *tokens);

void			free_command(t_command *command);

t_command		*new_command(t_token *token);

int				handle_redirects(t_redirection *redirections);

int				command_redirects_stdout(t_command *command);

int				command_redirects_stdin(t_command *command);

void			cleanup_process(void);

#endif
