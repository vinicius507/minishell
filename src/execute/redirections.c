#include <execute/execute.h>
#include <builtins/builtins.h>

void	free_redirections(t_redirection *redirection)
{
	if (redirection == NULL)
		return ;
	free_redirections(redirection->next);
	free(redirection);
}

t_redirection	*new_redirection(t_type type, t_redirection *prev)
{
	t_redirection	*redirection;

	redirection = ft_calloc(1, sizeof(t_redirection));
	if (redirection == NULL)
		return (NULL);
	if (type == TREDIRECT_OUT)
		redirection->type = RED_STDOUT;
	else if (type == TREDIRECT_IN)
		redirection->type = RED_STDIN;
	else if (type == TREDIRECT_APPND)
		redirection->type = RED_APPND;
	else
		redirection->type = RED_HDOC;
	if (prev != NULL)
		prev->next = redirection;
	return (redirection);
}

t_redirection	*get_redirections(t_token *tokens)
{
	t_redirection	*start;
	t_redirection	*redirections;
	
	start = NULL;
	redirections = NULL;
	while (tokens != NULL)
	{
		if (tokens->type == TREDIRECT_OUT
			|| tokens->type == TREDIRECT_IN || tokens->type == TREDIRECT_APPND
			|| tokens->type == TREDIRECT_HDOC)
		{
			redirections = new_redirection(tokens->type, redirections);
			if (redirections == NULL)
			{ 
				free_redirections(start);
				error("error while parsing the input", NULL);
				return (NULL);
			}
			if (start == NULL)
				start = redirections;
			redirections->content = tokens->value;
		}
		tokens = tokens->next;
	}
	return (start);
}

