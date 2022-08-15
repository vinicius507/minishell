/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:30:51 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/15 17:34:39 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <minishell.h>

static inline int	is_metachar(char c)
{
	return ((ft_isspace(c) != 0));
}

static inline int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

static char	has_matching_quote(char *str)
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

char	*word(char *input, size_t *counter)
{
	char	*word;
	size_t	length;

	length = word_len(input + *counter);
	word = ft_calloc(length + 1, sizeof(char));
	*counter += word_copy(input + *counter, word);
	return (word);
}
