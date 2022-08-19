#include "lexer/lexer.h"
#include <fcntl.h>
#include <execute/execute.h>

static int	get_stdout_fd(t_redirection *redirections)
{
	int	fd;
	
	fd = -1;
	while (redirections != NULL)
	{
		if (fd >= 0)
			close(fd);
		fd = open(redirections->content, FWRITE_MODE, FWRITE_PERM);
		redirections = redirections->next;
	}
	return (fd);
}

void	handle_redirects(t_redirection *redirections)
{
	int				fd;

	fd = get_stdout_fd(redirections);
	if (fd >= 0)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}
