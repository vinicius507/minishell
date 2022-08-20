/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:31:08 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/20 17:16:56 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <execute/execute.h>
#include <signals/signals.h>

static void	child_process(t_command *command)
{
	setup_signal(sig_child, SIGINT);
	setup_signal(sig_child, SIGQUIT);
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

static void	set_ret_code(int wstatus)
{
	if (WIFEXITED(wstatus))
		g_sh.ret_code = WEXITSTATUS(wstatus);
	else if (WIFSIGNALED(wstatus))
		g_sh.ret_code = WTERMSIG(wstatus) + 128;
}

void	execute_bin(t_command *command)
{
	int		pid;
	int		status;

	if (command->bin_path == NULL && command->redirections == NULL)
	{
		error(command->argv[0], "command not found");
		g_sh.ret_code = 127;
		return ;
	}
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
		setup_signal(sig_parent, SIGINT);
		setup_signal(sig_parent, SIGQUIT);
		if (waitpid(pid, &status, 0) == -1)
			perror("minishell");
		set_ret_code(status);
	}
}
