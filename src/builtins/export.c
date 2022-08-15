/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:23:33 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/10 16:57:18 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env/env.h>
#include <builtins/builtins.h>

static void	export_env(t_token *env)
{
	const char	*equal_sign;
	const char	*key;
	const char	*value;

	equal_sign = ft_strchr(env->value, '=');
	if (equal_sign == NULL || equal_sign == env->value)
		return ;
	key = ft_substr(env->value, 0, equal_sign - env->value);
	value = ft_strdup(equal_sign + 1);
	set_env(key, value);
	free((void *)key);
	free((void *)value);
}

void	export(t_token *args)
{
	while (args != NULL)
	{
		export_env(args);
		args = args->next;
	}
}
