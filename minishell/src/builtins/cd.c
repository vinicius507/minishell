/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:22:42 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/18 13:16:02 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtins.h>
#include <unistd.h>

static void	update_pwd_envs(void)
{
	const char	*pwd;

	pwd = getcwd(NULL, 0);
	set_env("OLDPWD", get_env("PWD")->value);
	set_env("PWD", pwd);
	free((char *)pwd);
}

int	cd(int argc, char **args)
{
	const char	*path;

	if (argc > 1)
	{
		error("cd: too many arguments", NULL);
		return (1);
	}
	if (*args == NULL)
		path = get_env("HOME")->value;
	else
		path = *args;
	if ((chdir(path) == -1))
	{
		perror("error");
		return (1);
	}
	update_pwd_envs();
	return (0);
}
