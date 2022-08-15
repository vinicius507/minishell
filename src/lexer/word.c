/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:30:51 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/15 14:31:32 by vgoncalv         ###   ########.fr       */
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
	size_t	counter;

	quote = 0;
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
		counter++;
	}
	return (counter);
}

static char	*word_copy(char *src, char *dest)
{
	char	quote;
	size_t	src_counter;
	size_t	dest_counter;

	quote = 0;
	src_counter = 0;
	dest_counter = 0;
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
			dest[dest_counter] = src[src_counter];
			dest_counter++;
		}
		src_counter++;
	}
	return (dest);
}

char	*word(char *input, size_t *counter)
{
	char	*temp;
	char	*word;
	size_t	length;

	length = word_len(input + *counter);
	temp = ft_calloc(length + 1, sizeof(char));
	word = word_copy(input + *counter, temp);
	if (ft_strlen(word) != length)
	{
		word = ft_strdup(temp);
		free(temp);
	}
	*counter = *counter + length - 1;
	return (word);
}
