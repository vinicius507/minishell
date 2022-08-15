/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:22:43 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/15 15:43:45 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <builtins/builtins.h>

t_shell	g_sh;

static void	setup_shell(char **envp)
{
	setup_env(envp);
	g_sh.loop = 1;
	g_sh.ret_code = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_token		*tokens;
	t_builtin	*builtin;
	int			builtin_argc;

	builtin = NULL;
	setup_shell(envp);
	while (g_sh.loop == 1)
	{
		tokens = prompt();
		if (tokens == NULL)
			continue ;
		builtin = get_builtin(tokens->value);
		if (builtin != NULL)
		{
			builtin_argc = tokens_count(tokens->next);
			g_sh.ret_code = builtin(builtin_argc, tokens->next);
		}
		else if (tokens != NULL)
			execute(tokens);
		free_tokens(tokens);
	}
	free_env();
	(void)argc;
	(void)argv;
	return (0);
}
