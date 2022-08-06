/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:01:23 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/06 16:20:21 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	execute(char **tokens)
{
	char	*bin_path;
	char	**envp;
	int		pid;

	bin_path = find_bin_path(tokens[0]);
	if (bin_path == NULL)
		printf("minishell: %s: command not found\n", tokens[0]);
	else
	{
		envp = process_env();
		pid = fork();
		if (pid == -1)
			perror("minishell");
		else if (pid == 0)
		{
			execve(bin_path, tokens, envp);
			perror("minishell");
			exit(1);
		}
		else
		{
			if (waitpid(pid, NULL, 0) == -1)
				perror("minishell");
		}
		free_process_env(process_env);
	}
}
