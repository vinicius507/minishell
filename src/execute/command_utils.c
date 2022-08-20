#include <execute/execute.h>

int	command_redirects_stdout(t_command *command)
{
	t_redirection	*redirections;

	redirections = command->redirections;
	while (redirections != NULL)
	{
		if (redirections->type == RED_STDOUT || redirections->type == RED_APPND)
			return (1);
		redirections = redirections->next;
	}
	return (0);
}

int	command_redirects_stdin(t_command *command)
{
	t_redirection	*redirections;

	redirections = command->redirections;
	while (redirections != NULL)
	{
		if (redirections->type == RED_STDIN || redirections->type == RED_HDOC)
			return (1);
		redirections = redirections->next;
	}
	return (0);
}
