/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 04:28:26 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/22 04:29:17 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execute/execute.h>

int	has_pipes(t_token *tokens)
{
	while (tokens != NULL)
	{
		if (tokens->type == TPIPE)
			return (1);
		tokens = tokens->next;
	}
	return (0);
}

void	free_pipeline(t_pipe_proc *pipeline)
{
	if (pipeline == NULL)
		return ;
	free_pipeline(pipeline->next);
	free_command(pipeline->command);
	free(pipeline);
}

t_pipe_proc	*new_pipeline(t_token *tokens, t_pipe_proc *prev)
{
	t_pipe_proc	*proc;
	t_command	*command;

	command = new_command(tokens);
	if (command == NULL)
		return (NULL);
	proc = ft_calloc(1, sizeof(t_pipe_proc));
	if (proc == NULL)
		return (NULL);
	if (prev != NULL)
		prev->next = proc;
	proc->prev = prev;
	proc->command = command;
	return (proc);
}

static t_token	*get_next_pipe_token(t_token *tokens)
{
	while (tokens != NULL)
	{
		if (tokens->type == TPIPE)
			return (tokens->next);
		tokens = tokens->next;
	}
	return (NULL);
}

t_pipe_proc	*build_pipeline(t_token *tokens)
{
	t_pipe_proc	*start;
	t_pipe_proc	*pipeline;

	start = NULL;
	pipeline = NULL;
	while (tokens != NULL)
	{
		pipeline = new_pipeline(tokens, pipeline);
		tokens = get_next_pipe_token(tokens);
		if (pipeline == NULL)
		{
			free_pipeline(start);
			return (NULL);
		}
		if (start == NULL)
			start = pipeline;
	}
	return (start);
}
