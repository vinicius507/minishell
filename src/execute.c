/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:01:23 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/15 15:17:09 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <minishell.h>

static char	*find_bin_path(char *cmd)
{
	char	**directories;
	t_env	*path;
	char	*bin_path;
	int		i;

	if ((access(cmd, F_OK) == 0))
		return (ft_strdup(cmd));
	path = get_env("PATH");
	if (path == NULL)
		return (NULL);
	i = 0;
	directories = ft_split(path->value, ':');
	while (directories[i] != NULL)
	{
		ft_asprintf(&bin_path, "%s/%s", directories[i], cmd);
		if ((access(bin_path, F_OK) == 0))
			break ;
		free(bin_path);
		bin_path = NULL;
		i++;
	}
	ft_free_string_array(directories);
	return (bin_path);
}

static char	**process_env(void)
{
	t_env	*env;
	char	**envp;
	size_t	counter;
	size_t	envp_len;

	envp_len = 0;
	env = g_sh.env;
	while (env != NULL)
	{
		envp_len++;
		env = env->next;
	}
	envp = ft_calloc(envp_len + 1, sizeof(char *));
	counter = 0;
	env = g_sh.env;
	while (counter < envp_len)
	{
		ft_asprintf(&(envp[counter]), "%s=%s", env->key, env->value);
		env = env->next;
		counter++;
	}
	return (envp);
}

static char	**process_argv(t_token *tokens)
{
	size_t	len;
	t_token	*temp;
	size_t	counter;
	char	**argv;

	len = 0;
	temp = tokens;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	argv = ft_calloc(len + 1, sizeof(char *));
	counter = 0;
	while (counter < len)
	{
		argv[counter++] = tokens->value;
		tokens = tokens->next;
	}
	return (argv);
}

static void	execute_process(char *bin, char **argv, char **envp)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == -1)
		perror("minishell");
	else if (pid == 0)
	{
		execve(bin, argv, envp);
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

void	execute(t_token *tokens)
{
	char	*bin_path;
	char	**envp;
	char	**argv;

	bin_path = find_bin_path(tokens->value);
	if (bin_path == NULL)
		printf("minishell: %s: command not found\n", tokens->value);
	else
	{
		envp = process_env();
		argv = process_argv(tokens);
		execute_process(bin_path, argv, envp);
		ft_free_string_array(envp);
		free(bin_path);
		free(argv);
	}
}
