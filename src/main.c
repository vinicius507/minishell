/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:22:43 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/18 13:29:41 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <builtins/builtins.h>
#include <execute/execute.h>

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
	t_command	*command;

	setup_shell(envp);
	while (g_sh.loop == 1)
	{
		tokens = prompt();
		if (tokens == NULL)
			continue ;
		command = new_command(tokens);
		if (command == NULL)
		{
			free_tokens(tokens);
			continue ;
		}
		if ((is_builtin(command->argv[0]) != 0))
			g_sh.ret_code = execute_builtin(command);
		else
			execute_bin(command);
		free_tokens(tokens);
		free_command(command);
	}
	free_env();
	(void)argc;
	(void)argv;
	return (0);
}
