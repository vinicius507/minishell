#include "lexer/lexer.h"
#include <fcntl.h>
#include <execute/execute.h>

static int	get_stdout_fd(t_redirection *redirections)
{
	int	fd;
	
	fd = -1;
	while (redirections != NULL)
	{
		if (redirections->type == RED_STDOUT)
		{
			if (fd >= 0)
				close(fd);
			fd = open(redirections->content, FWRITE_MODE, FWRITE_PERM);
		}
		redirections = redirections->next;
	}
	return (fd);
}

static int	get_stdin_fd(t_redirection *redirections)
{
	int	fd;
	
	fd = -1;
	while (redirections != NULL)
	{
		if (redirections->type == RED_STDIN)
		{
			if (fd >= 0)
				close(fd);
			fd = open(redirections->content, FREAD_MODE, FREAD_PERM);
		}
		redirections = redirections->next;
	}
	return (fd);
}

void	handle_redirects(t_redirection *redirections)
{
	int	stdout_fd;
	int	stdin_fd;

	stdout_fd = get_stdout_fd(redirections);
	if (stdout_fd >= 0)
	{
		dup2(stdout_fd, STDOUT_FILENO);
		close(stdout_fd);
	}
	stdin_fd = get_stdin_fd(redirections);
	if (stdin_fd >= 0)
	{
		dup2(stdin_fd, STDIN_FILENO);
		close(stdin_fd);
	}
}
