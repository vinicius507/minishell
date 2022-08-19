/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:56:34 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/19 16:54:36 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <minishell.h>

t_token	*lex(char *input)
{
	size_t	counter;
	t_token	*start;
	t_token	*token;

	if (input == NULL)
		input = "exit";
	counter = 0;
	start = NULL;
	token = NULL;
	while (input[counter] != '\0')
	{
		if (ft_isspace(input[counter]) != 0 && ++counter)
			continue ;
		token = new_token(&input[counter], token);
		if (start == NULL)
			start = token;
		if (token->type == TREDIRECT_OUT || token->type == TREDIRECT_IN
			|| token->type == TREDIRECT_APPND)
			token->value = redirect(input, &counter);
		else
			token->value = word(input, &counter);
		counter++;
	}
	return (start);
}
