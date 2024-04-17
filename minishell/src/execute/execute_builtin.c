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
	int			std_fd[2];
	t_builtin	*builtin;
	int			return_code;

	if (command->redirections != NULL)
	{
		std_fd[STDIN_FILENO] = dup(STDIN_FILENO);
		std_fd[STDOUT_FILENO] = dup(STDOUT_FILENO);
		handle_redirects(command->redirections);
	}
	builtin = get_builtin(command->argv[0]);
	if (builtin == NULL)
	{
		error(command->argv[0], "could not execute builtin");
		return (2);
	}
	return_code = builtin(command->argc - 1, command->argv + 1);
	if (command->redirections != NULL)
	{
		dup2(std_fd[STDIN_FILENO], STDIN_FILENO);
		dup2(std_fd[STDOUT_FILENO], STDOUT_FILENO);
		close(std_fd[STDIN_FILENO]);
		close(std_fd[STDOUT_FILENO]);
	}
	return (return_code);
}
