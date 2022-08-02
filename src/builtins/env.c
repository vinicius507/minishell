/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:08:01 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/02 11:17:31 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <env/env.h>
#include <builtins/builtins.h>

void 	env(void)
{
	t_env	*env;

	env = g_env;
	while (env != NULL)
	{
		printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}