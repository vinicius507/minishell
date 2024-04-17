/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:47:03 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/02 18:17:01 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env/env.h>
#include <minishell.h>

void	setup_env(char **envp)
{
	const char	*key;
	const char	*value;
	const char	*equal_sign;

	while (*envp != NULL)
	{
		equal_sign = ft_strchr(*envp, '=');
		key = ft_substr(*envp, 0, equal_sign - *envp);
		value = ft_strdup(equal_sign + 1);
		set_env(key, value);
		free((void *)key);
		free((void *)value);
		envp++;
	}
}
