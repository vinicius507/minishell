/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:01:23 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/10 01:48:35 by jefernan         ###   ########.fr       */
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

char	*find_bin_path(char *token)
{
	char	**temp;
	char	*path;
	char 	*bin_path;
	int		i;

	i = 0;
	path = getenv("PATH");
	if (path == NULL)
		perror("minishell");
	temp = ft_split(path, ':');
	while (temp)
	{
		bin_path = ft_strjoin(temp[i], token);
		if (access(bin_path, F_OK) == 0)
			return (temp[i]);	
		free(bin_path);
		i++;
	}
	free_process_env(temp);
	return (NULL);
}

void	free_process_env(char **envp)
{
	int	i;

	if (envp == NULL)
		return ;
	i = 0;
	while (envp[i] != NULL)
		free(envp[i++]);
	free(envp);
}