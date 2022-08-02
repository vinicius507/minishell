/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:23:33 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/02 11:34:11 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <env/env.h>

void	export(char **args)
{
	const char	*key;
	const char	*value;
	const char	*equal_sign;

	while (*args != NULL)
	{
		equal_sign = ft_strchr(*args, '=');
		if (equal_sign == NULL || equal_sign == *args)
		{
			args++;
			continue ;
		}
		key = ft_substr(*args, 0, equal_sign - *args);
		value = ft_strdup(equal_sign + 1);
		set_env(key, value);
		args++;
	}
}