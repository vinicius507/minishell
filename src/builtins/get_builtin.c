/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:11:42 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/02 13:01:24 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtins.h>

t_builtin	*get_builtin(const char *cmd)
{
	if ((ft_strcmp(cmd, "exit") == 0))
		return (shell_exit);
	if ((ft_strcmp(cmd, "pwd") == 0))
		return (pwd);
	if ((ft_strcmp(cmd, "echo") == 0))
		return (echo);
	if ((ft_strcmp(cmd, "env") == 0))
		return (env);
	if ((ft_strcmp(cmd, "export") == 0))
		return (export);
	return (NULL);
}
