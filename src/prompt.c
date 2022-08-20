/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:43:07 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/18 13:12:52 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <signals/signals.h>
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
		ft_asprintf(&path, "%s@%s:%s$ ",
			get_env("USER")->value,
			"minishell",
			absolute_path);
	return (path);
}

t_token	*prompt(void)
{
	char	*input;
	char	*prompt;
	t_token	*tokens;

	setup_signal(sig_prompt, SIGINT);
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
