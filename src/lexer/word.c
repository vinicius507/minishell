/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:30:51 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/15 17:46:47 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <minishell.h>

static size_t	word_len(char *word)
{
	char	quote;
	size_t	length;
	size_t	counter;

	quote = 0;
	length = 0;
	counter = 0;
	while (word[counter] != '\0')
	{
		if (quote == 0 && (is_metachar(word[counter]) != 0))
			break ;
		if (quote == 0
			&& (is_quote(word[counter]) != 0)
			&& (has_matching_quote(word + counter) != 0))
			quote = word[counter];
		else if (quote == word[counter])
			quote = 0;
		else
			length++;
		counter++;
	}
	return (length);
}

static size_t	word_copy(char *src, char *dest)
{
	char	quote;
	size_t	src_counter;

	quote = 0;
	src_counter = 0;
	while (src[src_counter] != '\0')
	{
		if (quote == 0 && (is_metachar(src[src_counter]) != 0))
			break ;
		if (quote == 0
			&& (is_quote(src[src_counter]) != 0)
			&& (has_matching_quote(&(src[src_counter])) != 0))
			quote = src[src_counter];
		else if (quote == src[src_counter])
			quote = 0;
		else
		{
			*dest = src[src_counter];
			dest++;
		}
		src_counter++;
	}
	return (src_counter - 1);
}

char	*expand_env_vars(char *word)
{
	t_env	*env;

	if (word[0] != '$')
		return (ft_strdup(word));
	env = get_env(ft_strdup(&(word[1])));
	if (env == NULL)
		return (ft_strdup(""));
	return (ft_strdup(env->value));
}

char	*word(char *input, size_t *counter)
{
	char	*temp;
	char	*word;
	size_t	length;

	length = word_len(input + *counter);
	temp = ft_calloc(length + 1, sizeof(char));
	*counter += word_copy(input + *counter, temp);
	word = expand_env_vars(temp);
	free(temp);
	return (word);
}
