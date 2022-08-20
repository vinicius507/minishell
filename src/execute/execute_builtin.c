/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:32:01 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/20 16:18:50 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execute/execute.h>
#include <builtins/builtins.h>

int	execute_builtin(t_command *command)
{
	int			stdout_fd;
	t_builtin	*builtin;
	int			return_code;

	stdout_fd = -1;
	if (command->redirections != NULL)
	{
		stdout_fd = dup(STDOUT_FILENO);
		handle_redirects(command->redirections);
	}
	builtin = get_builtin(command->argv[0]);
	if (builtin == NULL)
	{
		error(command->argv[0], "could not execute builtin");
		return (-1);
	}
	return_code = builtin(command->argc - 1, command->argv + 1);
	if (stdout_fd >= 0)
	{
		dup2(stdout_fd, STDOUT_FILENO);
		close(stdout_fd);
	}
	return (return_code);
}
