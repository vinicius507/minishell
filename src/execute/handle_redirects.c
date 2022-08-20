#include <fcntl.h>
#include <execute/execute.h>

#define ERRO -2

static int	set_stdout_fd(t_redirection *redirections)
{
	int	fd;
	int	fmode;
	int	dup_fd;
	
	fd = -1;
	while (redirections != NULL)
	{
		if (redirections->type == RED_STDOUT || redirections->type == RED_APPND)
		{
			if (fd >= 0)
				close(fd);
			fmode = FWRITE_MODE;
			if (redirections->type == RED_APPND)
				fmode = FAPPND_MODE;
			fd = open(redirections->content, fmode, FWRITE_PERM);
			if (fd == -1)
				return (ERRO);
			dup_fd = dup2(fd, STDOUT_FILENO);
			close(fd);
			if (dup_fd == -1)
				return (ERRO);
		}
		redirections = redirections->next;
	}
	return (fd);
}

static int	handle_red_stdin(int fd, t_redirection *redirection)
{
	if (fd >= 0)
		close(fd);
	fd = open(redirection->content, FREAD_MODE, FREAD_PERM);
	if (fd == -1)
		return (ERRO);
	return (fd);
}

static int	handle_red_heredoc(int fd, t_redirection *heredoc)
{
	if (fd >= 0)
		close(fd);
	fd = open(HDOC_TMPFILE, FHDOC_MODE, FWRITE_PERM);
	if (fd == -1)
		return (ERRO);
	ft_putstr_fd(heredoc->content, fd);
	fd = open(HDOC_TMPFILE, FREAD_MODE, 0);
	if (fd == -1)
		return (ERRO);
	return (fd);
}

static int	set_stdin_fd(t_redirection *redirections)
{
	int				fd;
	int				dup_fd;
	
	fd = -1;
	while (redirections != NULL)
	{
		if (redirections->type == RED_STDIN)
			fd = handle_red_stdin(fd, redirections);
		else if (redirections->type == RED_HDOC)
			fd = handle_red_heredoc(fd, redirections);
		if (fd == ERRO)
			return (ERRO);
		dup_fd = dup2(fd, STDIN_FILENO);
		close(fd);
		if (dup_fd == -1)
			return (ERRO);
		redirections = redirections->next;
	}
	unlink(HDOC_TMPFILE);
	return (fd);
}

int	handle_redirects(t_redirection *redirections)
{
	int	stdout_fd;
	int	stdin_fd;

	stdout_fd = set_stdout_fd(redirections);
	if (stdout_fd == ERRO)
		return (-1);
	stdin_fd = set_stdin_fd(redirections);
	if (stdin_fd == ERRO)
		return (-1);
	return (0);
}
