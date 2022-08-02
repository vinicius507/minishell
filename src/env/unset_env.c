/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:24:48 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/02 16:35:12 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env/env.h>
#include <minishell.h>

void	unset_env(const char *key)
{
	t_env	*env;

	env = get_env(key);
	if (env == NULL)
		return ;
	if (env->prev != NULL)
		env->prev->next = env->next;
	if (env->next != NULL)
		env->next->prev = env->prev;
	env->prev = NULL;
	env->next = NULL;
	free((void *)env->key);
	free((void *)env->value);
	free(env);
}
