/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:04:23 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/02 12:51:24 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env/env.h>
#include <minishell.h>

t_env	*get_env(const char *key)
{
	t_env	*env;

	env = g_sh.env;
	while (env != NULL && (ft_strcmp(key, env->key) != 0))
		env = env->next;
	return (env);
}
