/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:53:22 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/17 16:39:40 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <minishell.h>

char	*get_env_key(char *str)
{
	int	i;

	i = 0;
	while ((ft_isalnum(str[i]) != 0) || str[i] == '_')
		i++;
	if (i == 0)
		return (NULL);
	return (ft_substr(str, 0, i));
}
