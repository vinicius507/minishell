#include <fcntl.h>
#include <execute/execute.h>

#define ERRO -2

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
			if (fd == -1)
				return (ERRO);
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
			if (fd == -1)
				return (ERRO);
		}
		redirections = redirections->next;
	}
	return (fd);
}

int	handle_redirects(t_redirection *redirections)
{
	int	stdout_fd;
	int	stdin_fd;
	int	dup_fd;

	stdout_fd = get_stdout_fd(redirections);
	if (stdout_fd == ERRO)
		return (-1);
	if (stdout_fd >= 0)
	{
		dup_fd = dup2(stdout_fd, STDOUT_FILENO);
		close(stdout_fd);
		if (dup_fd == ERRO)
			return (-1);
	}
	stdin_fd = get_stdin_fd(redirections);
	if (stdin_fd == ERRO)
		return (-1);
	if (stdin_fd >= 0)
	{
		dup_fd = dup2(stdin_fd, STDIN_FILENO);
		close(stdin_fd);
		if (dup_fd == ERRO)
			return (-1);
	}
	return (0);
}
