/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:09:12 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/02 12:51:29 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env/env.h>
#include <minishell.h>

void	free_env(void)
{
	t_env	*env;
	t_env	*next;

	env = g_sh.env;
	while (env != NULL)
	{
		next = env->next;
		free((void *)env->key);
		free((void *)env->value);
		free(env);
		env = next;
	}
}
