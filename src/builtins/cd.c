/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:22:42 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/10 15:04:31 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtins.h>

static void	update_pwd_envs(void)
{
	const char	*pwd;

	pwd = getcwd(NULL, 0);
	set_env("OLDPWD", get_env("PWD")->value);
	set_env("PWD", pwd);
	free((char *)pwd);
}

void	cd(char **args)
{
	const char	*path;

	if (*args == NULL)
		path = get_env("HOME")->value;
	else
		path = *args;
	if ((chdir(path) == -1))
	{
		perror("error");
		return ;
	}
	update_pwd_envs();
}
