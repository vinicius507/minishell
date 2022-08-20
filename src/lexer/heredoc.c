/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:11:37 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/20 16:17:16 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <minishell.h>
#include <readline/history.h>
#include <readline/readline.h>

static void	check_line_and_free(char *line, char *delim)
{
	if (line != NULL)
		free(line);
	else
		error("here_doc received end-of-file, wanted", delim);
	free(delim);
}

static char	*get_delimiter(char *input, size_t *counter, char *quote)
{
	char	*delim;

	while ((is_redirect(input[*counter]) != 0))
		*counter += 1;
	while ((ft_isspace(input[*counter]) != 0))
		*counter += 1;
	if ((is_quote(input[*counter]) != 0)
		&& has_matching_quote(&(input[*counter])))
		*quote = input[*counter];
	delim = word(input, counter, 0);
	if (delim != NULL && (ft_strcmp(delim, "") == 0))
	{
		free(delim);
		return (NULL);
	}
	return (delim);
}

static char	*turn_line_into_word(char *line)
{
	size_t	counter;

	counter = 0;
	return (word(line, &counter, 1));
}

static char	*join_line(char *content, char *line, char quote)
{
	char	*temp;

	ft_asprintf(&temp, "%c%s\n%c", quote, line, quote);
	free(line);
	line = turn_line_into_word(temp);
	free(temp);
	ft_asprintf(&temp, "%s%s", content, line);
	free(content);
	free(line);
	return (temp);
}

char	*here_doc(char *input, size_t *counter)
{
	char	*delim;
	char	*content;
	char	*line;
	char	quote;

	quote = '"';
	delim = get_delimiter(input, counter, &quote);
	if (delim == NULL)
		return (NULL);
	content = ft_strdup("");
	line = readline("here_doc: ");
	while (line != NULL && (ft_strcmp(line, delim) != 0))
	{
		content = join_line(content, line, quote);
		if (content == NULL)
			break ;
		line = readline("here_doc: ");
	}
	check_line_and_free(line, delim);
	return (content);
}
