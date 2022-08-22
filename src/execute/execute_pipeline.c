/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 04:28:30 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/22 04:28:49 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <execute/execute.h>
#include <signals/signals.h>
#include <builtins/builtins.h>

int	execute_bin_pipe(t_command *command)
{
	if (command->bin_path == NULL && command->redirections == NULL)
	{
		error(command->argv[0], "command not found");
		return (127);
	}
	if (command->redirections != NULL
		&& (handle_redirects(command->redirections) == -1))
	{
		perror("minishell");
		return (1);
	}
	if (command->bin_path == NULL)
		return (0);
	execve(command->bin_path, command->argv, command->envp);
	perror("minishell");
	return (1);
}

void	execute_pipe_child(t_pipe_proc *proc, int proc_fd[2])
{
	setup_signal(sig_child, SIGINT);
	setup_signal(sig_child, SIGQUIT);
	close(proc_fd[STDIN_FILENO]);
	if ((is_builtin(proc->command->argv[0]) != 0))
		proc->exit_code = execute_builtin(proc->command);
	else
		proc->exit_code = execute_bin_pipe(proc->command);
	exit(proc->exit_code);
}

void	spawn_proc(t_pipe_proc *proc, int proc_fd[2], int std_fd[2])
{
	int	pipe_fd[2];

	dup2(proc_fd[STDIN_FILENO], STDIN_FILENO);
	close(proc_fd[STDIN_FILENO]);
	if (proc->next != NULL)
	{
		pipe(pipe_fd);
		proc_fd[STDIN_FILENO] = pipe_fd[0];
		proc_fd[STDOUT_FILENO] = pipe_fd[1];
	}
	else
		proc_fd[STDOUT_FILENO] = dup(std_fd[STDOUT_FILENO]);
	dup2(proc_fd[STDOUT_FILENO], STDOUT_FILENO);
	close(proc_fd[STDOUT_FILENO]);
	proc->pid = fork();
	if (proc->pid == 0)
		execute_pipe_child(proc, proc_fd);
}

void	wait_procs(t_pipe_proc *procs)
{
	while (procs != NULL)
	{
		waitpid(procs->pid, &procs->exit_code, 0);
		if (WIFEXITED(procs->exit_code))
			procs->exit_code = WEXITSTATUS(procs->exit_code);
		else if (WIFSIGNALED(procs->exit_code))
			procs->exit_code = WTERMSIG(procs->exit_code) + 128;
		if (procs->next == NULL)
			g_sh.ret_code = procs->exit_code;
		procs = procs->next;
	}
}

void	execute_pipeline(t_pipe_proc *pipeline)
{
	int			std_fd[2];
	int			proc_fd[2];
	t_pipe_proc	*proc;

	setup_signal(sig_parent, SIGINT);
	setup_signal(sig_parent, SIGQUIT);
	std_fd[STDIN_FILENO] = dup(STDIN_FILENO);
	std_fd[STDOUT_FILENO] = dup(STDOUT_FILENO);
	proc_fd[STDIN_FILENO] = dup(STDIN_FILENO);
	proc_fd[STDOUT_FILENO] = -1;
	proc = pipeline;
	while (proc != NULL)
	{
		spawn_proc(proc, proc_fd, std_fd);
		proc = proc->next;
	}
	dup2(std_fd[STDIN_FILENO], STDIN_FILENO);
	dup2(std_fd[STDOUT_FILENO], STDOUT_FILENO);
	close(std_fd[STDIN_FILENO]);
	close(std_fd[STDOUT_FILENO]);
	wait_procs(pipeline);
}
