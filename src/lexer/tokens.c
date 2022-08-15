/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:58:13 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/11 11:51:50 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <minishell.h>

t_token	*new_token(t_token	*previous)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	if (previous != NULL)
		previous->next = new;
	return (new);
}

void	free_tokens(t_token	*token)
{
	if (token == NULL)
		return ;
	free_tokens(token->next);
	free(token->value);
	free(token);
}
