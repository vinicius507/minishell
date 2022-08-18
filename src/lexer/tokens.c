/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:58:13 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/17 21:43:27 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <minishell.h>

t_token	*new_token(char	c, t_token	*previous)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	if (is_redirect(c) == 1)
		new->type = TREDIRECT_OUT;
	else
		new->type = TWORD;
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

int	tokens_count(t_token *token)
{
	int	count;

	count = 0;
	while (token != NULL)
	{
		count++;
		token = token->next;
	}
	return (count);
}