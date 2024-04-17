/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:11:52 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/20 20:11:53 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <minishell.h>

void	check_line_and_free(char *line, char *delim)
{
	if (line != NULL)
		free(line);
	else
		error("here_doc received end-of-file, wanted", delim);
}

char	*get_delimiter(char *input, size_t *counter, char *quote)
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

char	*turn_line_into_word(char *line)
{
	size_t	counter;

	counter = 0;
	return (word(line, &counter, 1));
}

char	*join_line(char *content, char *line, char quote)
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
