/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:31:08 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/19 16:40:43 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execute/execute.h>
#include <sys/wait.h>

static void	child_process(t_command *command)
{
	if (command->redirections != NULL
		&& (handle_redirects(command->redirections) == -1))
	{
		perror("minishell");
		exit(1);
	}
	execve(command->bin_path, command->argv, command->envp);
	perror("minishell");
	exit(1);
}

void	execute_bin(t_command *command)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		perror("minishell");
		g_sh.ret_code = 1;
	}
	else if (pid == 0)
		child_process(command);
	else
	{
		if (waitpid(pid, &status, 0) == -1)
			perror("minishell");
		g_sh.ret_code = (((status) & 0xff00) >> 8);
	}
}
