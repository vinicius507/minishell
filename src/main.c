/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:22:43 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/02 13:09:36 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <readline/readline.h>
#include <builtins/builtins.h>
#include <minishell.h>

t_shell	g_sh;

void	free_tokens(char **tokens)
{
	int	i;

	if (tokens == NULL)
		return ;
	i = 0;
	while (tokens[i] != NULL)
		free(tokens[i++]);
	free(tokens);
}

char	**prompt(void)
{
	char	*input;
	char	**tokens;

	input = readline("prompt: ");
	tokens = lex(input);
	if (input != NULL)
		free(input);
	return (tokens);
}

int	main(int argc, char **argv, char **envp)
{
	char		**tokens;
	t_builtin	*builtin;

	g_sh.loop = 1;
	builtin = NULL;
	setup_env(envp);
	while (g_sh.loop == 1)
	{
		tokens = prompt();
		if (tokens == NULL)
			shell_exit(NULL);
		else
			builtin = get_builtin(tokens[0]);
		if (builtin != NULL)
			builtin(tokens + 1);
		else if (tokens != NULL && *tokens != NULL)
			printf("%s: %s: command not found\n", argv[0], tokens[0]);
		free_tokens(tokens);
	}
	free_env();
	(void)argc;
	return (0);
}
