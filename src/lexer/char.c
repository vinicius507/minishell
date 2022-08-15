/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:43:09 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/15 17:43:35 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <minishell.h>

int	is_metachar(char c)
{
	return ((ft_isspace(c) != 0));
}

int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

char	has_matching_quote(char *str)
{
	char	quote;

	if (str == NULL)
		return (0);
	quote = str[0];
	str++;
	while (*str != '\0')
	{
		if (*str == quote)
			return (1);
		str++;
	}
	return (0);
}
