/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:22:42 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/02 18:37:00 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtins.h>

void	cd(char **args)
{
	const char	*path;
	const char	*pwd;

	pwd = get_env("PWD")->value;
	if (*args == NULL)
		path = get_env("HOME")->value;
	else
		path = *args;
	if ((chdir(path) == -1))
	{ 
		perror("error");
		return ;
	}
	set_env("OLDPWD", pwd);
	set_env("PWD", path);
}