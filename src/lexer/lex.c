/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:56:34 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/11 11:54:14 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <minishell.h>

static size_t	word_len(char *word)
{
	size_t	counter;

	counter = 0;
	while (word[counter] != '\0')
	{
		if (ft_isspace(word[counter]) != 0)
			break ;
		counter++;
	}
	return (counter);
}

static char	*word(char *input, size_t *counter)
{
	char	*word;
	size_t	length;

	length = word_len(input + *counter);
	word = ft_substr(input, *counter, length);
	*counter = *counter + length - 1;
	return (word);
}

t_token	*lex(char *input)
{
	size_t	counter;
	t_token	*start;
	t_token	*token;

	if (input == NULL)
		input = ft_strdup("exit");
	counter = 0;
	start = NULL;
	token = NULL;
	while (input[counter] != '\0')
	{
		if (ft_isspace(input[counter]) != 0 && ++counter)
			continue ;
		token = new_token(token);
		if (start == NULL)
			start = token;
		token->value = word(input, &counter);
		counter++;
	}
	return (start);
}
