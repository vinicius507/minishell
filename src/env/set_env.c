/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:39:40 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/02 11:12:23 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <env/env.h>

static	t_env	*new_env(const char *key, const char*value)
{
	t_env	*env;

	env = ft_calloc(1, sizeof(t_env));
	env->key = key;
	env->value = value;
	return (env);
}

static	t_env	*update_env(t_env	*env, const char *value)
{
	free((void *)env->value);
	env->value = ft_strdup(value);
	return (env);
}

t_env	*set_env(const char *key, const char*value)
{
	t_env	*env;

	if (g_env == NULL)
	{ 
		g_env = new_env(key, value);
		return (g_env);
	}
	env = get_env(key);
	if (env != NULL)
		return (update_env(env, value));
	env = g_env;
	while (env->next != NULL)
		env = env->next;
	env->next = new_env(key, value);
	return (env->next);
}