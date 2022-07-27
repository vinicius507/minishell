/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:22:43 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/07/27 15:32:00 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <readline/readline.h>
#include <builtins/builtins.h>
#include <minishell.h>

void	free_tokens(char **tokens)
{
	int i;

	if (tokens == NULL)
		return ;
	i = 0;
	while (tokens[i] != NULL)
		free(tokens[i++]);
	free(tokens);
}

int main(int argc, char **argv, char **envp)
{
	char 	*input;
	char	**tokens;

	while(1)
	{
		input = readline("prompt: ");
		tokens = lex(input);
		if (input != NULL)
			free(input);
		if (tokens == NULL || ft_strcmp(tokens[0], "exit") == 0)
		{
			free_tokens(tokens);
			shell_exit();
		}
		if (ft_strcmp(tokens[0], "pwd") == 0)
			pwd();
		if (ft_strncmp(tokens[0], "echo", 4) == 0)
			echo(tokens + 1);
		if (ft_strcmp(tokens[0], "env") == 0)
			env(envp);
		free_tokens(tokens);
	}
	(void)argc;
	(void)argv;
	return (0);
}
