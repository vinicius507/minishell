/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:31:08 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/18 13:33:31 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execute/execute.h>
#include <sys/wait.h>

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
	{
		if (command ->redirections != NULL)
			handle_redirects(command->redirections);
		execve(command->bin_path, command->argv, command->envp);
		perror("minishell");
		exit(1);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
			perror("minishell");
		g_sh.ret_code = (((status) & 0xff00) >> 8);
	}
}
