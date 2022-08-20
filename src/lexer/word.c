/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:30:51 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/20 16:18:11 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <minishell.h>

static size_t	env_len(char *input, size_t *counter)
{
	char	*key;
	size_t	length;
	t_env	*env;

	key = get_env_key(input);
	if (key == NULL)
		return (1);
	env = get_env(key);
	*counter += ft_strlen(key);
	free(key);
	if (env == NULL)
		return (0);
	length = ft_strlen(env->value);
	return (length);
}

static size_t	word_len(char *input, int expand)
{
	char	quote;
	size_t	length;
	size_t	counter;

	quote = 0;
	length = 0;
	counter = 0;
	while (input[counter] != '\0')
	{
		if (quote == 0 && (is_metachar(input[counter]) != 0))
			break ;
		if (quote == 0
			&& (is_quote(input[counter]) != 0)
			&& (has_matching_quote(input + counter) != 0))
			quote = input[counter];
		else if (quote == input[counter])
			quote = 0;
		else if (expand != 0 && input[counter] == '$'
			&& (quote == 0 || quote == DOUBLE_QUOTE))
			length += env_len(&input[counter + 1], &counter);
		else
			length++;
		counter++;
	}
	return (length);
}

static char	*env_copy(char *dest, char *src, size_t *counter)
{
	char	*key;
	t_env	*env;

	key = get_env_key(&src[*counter + 1]);
	if (key == NULL)
	{
		*dest = src[*counter];
		return (&dest[1]);
	}
	*counter += ft_strlen(key);
	env = get_env(key);
	free(key);
	if (env == NULL)
		return (dest);
	ft_strlcpy(dest, env->value, ft_strlen(env->value) + 1);
	return (ft_strchr(dest, '\0'));
}

static size_t	word_copy(char *src, char *dest, int expand)
{
	char	quote;
	size_t	counter;

	quote = 0;
	counter = 0;
	while (src[counter] != '\0')
	{
		if (quote == 0 && (is_metachar(src[counter]) != 0))
			break ;
		if (quote == 0 && (is_quote(src[counter]) != 0)
			&& (has_matching_quote(&(src[counter])) != 0))
			quote = src[counter];
		else if (quote == src[counter])
			quote = 0;
		else if (expand != 0 && src[counter] == '$'
			&& (quote == 0 || quote == DOUBLE_QUOTE))
			dest = env_copy(dest, src, &counter);
		else
		{
			*dest = src[counter];
			dest++;
		}
		counter++;
	}
	return (counter - 1);
}

char	*word(char *input, size_t *counter, int expand)
{
	char	*temp;
	char	*word;
	size_t	length;

	length = word_len(input + *counter, expand);
	temp = ft_calloc(length + 1, sizeof(char));
	*counter += word_copy(input + *counter, temp, expand);
	word = ft_strdup(temp);
	free(temp);
	return (word);
}
