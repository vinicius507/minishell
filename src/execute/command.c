#include <execute/execute.h>
#include <builtins/builtins.h>

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

void	free_command(t_command *command)
{
	if (command == NULL)
		return ;
	if (command->bin_path != NULL)
		free(command->bin_path);
	if (command->argv != NULL)
		free(command->argv);
	if (command->envp != NULL)
		ft_free_string_array(command->envp);
	if (command->redirections != NULL)
		free_redirections(command->redirections);
	free(command);
}

t_command	*new_command(t_token *token)
{
	t_command	*command;

	command = ft_calloc(1, sizeof(t_command));
	if (command == NULL)
		return (NULL);
	command->argv = build_argv(token);
	command->argc = count_argc(token);
	if ((is_builtin(command->argv[0]) == 0))
		command->bin_path = find_bin_path(command->argv[0]);
	command->envp = process_env();
	command->redirections = get_redirections(token);
	if (command->argv == NULL
		|| command->envp == NULL)
	{
		free_command(command);
		command = NULL;
	}
	return (command);
}