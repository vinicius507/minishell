/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:43:07 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/02 19:17:31 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <readline/history.h>
#include <readline/readline.h>

static char	*prompt_string(void)
{
	const char	*home;
	char		*path;
	size_t		home_size;
	const char	*absolute_path;

	home = get_env("HOME")->value;
	home_size = ft_strlen(home);
	absolute_path = get_env("PWD")->value;
	if ((ft_strncmp(absolute_path, home, home_size) == 0))
	{
		ft_asprintf(&path, "%s@%s:~%s$ ",
			get_env("USER")->value,
			"minishell",
			absolute_path + home_size);
	}
	else
		ft_asprintf(&path, "%s@%s:%s$",
			get_env("USER")->value,
			"minishell",
			absolute_path);
	return (path);
}

char	**prompt(void)
{
	char	*input;
	char	**tokens;
	char	*prompt;

	prompt = prompt_string();
	input = readline(prompt);
	free(prompt);
	tokens = lex(input);
	if (input != NULL)
	{
		add_history(input);
		free(input);
	}
	return (tokens);
}