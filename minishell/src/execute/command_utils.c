/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:31:52 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/20 16:31:53 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
