/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:23:33 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/20 17:22:57 by vgoncalv         ###   ########.fr       */
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

static int	export_env(char *env)
{
	const char	*equal_sign;
	const char	*key;
	const char	*value;
	int			is_valid;

	equal_sign = ft_strchr(env, '=');
	if (equal_sign == NULL)
		return (0);
	if (equal_sign == env)
	{
		error("export: invalid key", env);
		return (1);
	}
	key = ft_substr(env, 0, equal_sign - env);
	is_valid = is_valid_key((char *)key);
	if (is_valid == 0)
		error("export: invalid key", (char *)key);
	else
	{
		value = ft_strdup(equal_sign + 1);
		set_env(key, value);
		free((void *)value);
	}
	free((void *)key);
	return (is_valid != 0);
}

int	export(int argc, char **args)
{
	int	ret_code;

	ret_code = 0;
	while (*args != NULL)
	{
		if ((export_env(*args) != 0))
			ret_code = 1;
		args++;
	}
	(void)argc;
	return (ret_code);
}
