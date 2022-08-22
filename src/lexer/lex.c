/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:56:34 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/19 20:34:27 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <minishell.h>

static t_type	get_token_type(char *input)
{
	if (input[0] == REDIRECT_OUT && input[0] == input[1])
		return (TREDIRECT_APPND);
	else if (input[0] == REDIRECT_IN && input[0] == input[1])
		return (TREDIRECT_HDOC);
	else if (input[0] == REDIRECT_OUT)
		return (TREDIRECT_OUT);
	else if (input[0] == REDIRECT_IN)
		return (TREDIRECT_IN);
	return (TWORD);
}

static char	*get_token_value(t_type type, char *input, size_t *counter)
{
	if (type == TREDIRECT_OUT || type == TREDIRECT_IN
		|| type == TREDIRECT_APPND)
		return (redirect(input, counter));
	else if (type == TREDIRECT_HDOC)
		return (here_doc(input, counter));
	return (word(input, counter, 1));
}

static t_token	*handle_lex_errors(t_type type, t_token *tokens, char *ref)
{
	if (type == TREDIRECT_OUT)
		ref = ">";
	else if (type == TREDIRECT_IN)
		ref = "<";
	else if (type == TREDIRECT_APPND)
		ref = ">>";
	else if (type == TREDIRECT_HDOC && g_sh.ret_code != 130)
		ref = "<<";
	else if (type == TREDIRECT_HDOC && g_sh.ret_code == 130)
		return (NULL);
	free_tokens(tokens);
	error("syntax error near token", ref);
	return (NULL);
}

t_token	*lex(char *input)
{
	size_t	counter;
	t_type	type;
	char	*value;
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
		type = get_token_type(&(input[counter]));
		value = get_token_value(type, input, &counter);
		if (value == NULL)
			return (handle_lex_errors(type, start, token->value));
		token = new_token(type, value, token);
		if (start == NULL)
			start = token;
		counter++;
	}
	return (start);
}
