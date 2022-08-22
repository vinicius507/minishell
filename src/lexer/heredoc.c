/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:11:37 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/20 16:17:16 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <lexer/lexer.h>
#include <minishell.h>
#include <signals/signals.h>
#include <readline/history.h>
#include <readline/readline.h>

static char	*here_doc_content(char *delim, char quote)
{
	char	*content;
	char	*line;

	content = ft_strdup("");
	line = readline("here_doc: ");
	while (line != NULL && (ft_strcmp(line, delim) != 0))
	{
		content = join_line(content, line, quote);
		if (content == NULL)
			break ;
		line = readline("here_doc: ");
	}
	check_line_and_free(line, delim);
	return (content);
}

static void	here_doc_process(int pipe_fd[2], char *delim, char quote)
{
	char	*content;

	setup_signal(sig_heredoc_child, SIGINT);
	content = here_doc_content(delim, quote);
	if (content == NULL)
		exit(EXIT_FAILURE);
	ft_putstr_fd(content, pipe_fd[1]);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	free(content);
	exit(EXIT_SUCCESS);
}

static char	*get_content_from_pipe(int pipe_fd[2])
{
	int		res;
	char	*line;
	char	*content;

	content = ft_strdup("");
	res = get_next_line(pipe_fd[0], &line);
	while (res != END_OF_FILE)
	{
		if (res == GNL_ERROR)
		{
			free(content);
			return (NULL);
		}
		content = join_line(content, line, SINGLE_QUOTE);
		res = get_next_line(pipe_fd[0], &line);
		if (content == NULL)
			return (NULL);
	}
	if (line != NULL)
		free(line);
	return (content);
}

static char	*handle_child_process_quit(int pid, int pipe_fd[2])
{
	int		status;
	char	*content;

	setup_signal(sig_heredoc_parent, SIGINT);
	content = NULL;
	close(pipe_fd[1]);
	if ((waitpid(pid, &status, 0) == -1))
		perror(g_sh.sh_name);
	if (WIFEXITED(status))
	{
		g_sh.ret_code = WEXITSTATUS(status);
		content = get_content_from_pipe(pipe_fd);
		if (g_sh.ret_code == 0)
		{
			if (content == NULL)
				error(NULL, NULL);
		}
		else
		{ 
			free(content);
			content = NULL;
			g_sh.ret_code = 130;
		}
	}
	close(pipe_fd[0]);
	return (content);
}

char	*here_doc(char *input, size_t *counter)
{
	int		pid;
	int		pipe_fd[2];
	char	*delim;
	char	quote;
	char	*content;

	content = NULL;
	quote = '"';
	delim = get_delimiter(input, counter, &quote);
	if (delim == NULL)
		return (NULL);
	if ((pipe(pipe_fd) == -1))
	{
		perror(g_sh.sh_name);
		return (NULL);
	}
	pid = fork();
	if (pid == -1)
		perror(g_sh.sh_name);
	else if (pid == 0)
		here_doc_process(pipe_fd, delim, quote);
	else
		content = handle_child_process_quit(pid, pipe_fd);
	free(delim);
	return (content);
}
