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

static int	execute_process(char *bin, char **argv, char **envp)
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

void	execute_bin(t_token *tokens)
{
	char	*bin_path;
	char	**envp;
	char	**argv;

	bin_path = find_bin_path(tokens->value);
	if (bin_path == NULL)
		return (error(tokens->value, "command not found"));
	envp = process_env();
	if (envp == NULL)
	{
		free(bin_path);
		return (error(tokens->value, "could not build process environment"));
	}
	argv = build_argv(tokens);
	if (argv == NULL)
	{
		free(envp);
		free(bin_path);
		return (error(tokens->value, "could not process command arguments"));
	}
	execute_process(bin_path, argv, envp);
	ft_free_string_array(envp);
	free(bin_path);
	free(argv);
}
