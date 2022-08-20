/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:23:33 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/18 13:26:44 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env/env.h>
#include <builtins/builtins.h>

static int	is_valid_key(char *key)
{
	if (key == NULL)
		return (0);
	while (*key != '\0')
	{
		if ((ft_isalnum(*key) == 0) && (*key != '_'))
			return (0);
		key++;
	}
	return (1);
}

static void	export_env(char *env)
{
	const char	*equal_sign;
	const char	*key;
	const char	*value;

	equal_sign = ft_strchr(env, '=');
	if (equal_sign == NULL)
		return ;
	if (equal_sign == env)
		return (error("export: invalid key", env));
	key = ft_substr(env, 0, equal_sign - env);
	if ((is_valid_key((char *)key)) == 0)
		error("export: invalid key", (char *)key);
	else
	{
		value = ft_strdup(equal_sign + 1);
		set_env(key, value);
		free((void *)value);
	}
	free((void *)key);
}

int	export(int argc, char **args)
{
	while (*args != NULL)
	{
		export_env(*args);
		args++;
	}
	(void)argc;
	return (0);
}
