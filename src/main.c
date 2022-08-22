/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:22:43 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/22 04:28:42 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <builtins/builtins.h>
#include <execute/execute.h>

t_shell	g_sh;

static void	setup_shell(int argc, char **argv, char **envp)
{
	setup_env(envp);
	g_sh.sh_name = argv[0];
	g_sh.loop = 1;
	g_sh.ret_code = 0;
	(void)argc;
}

int	main(int argc, char **argv, char **envp)
{
	t_token		*tokens;
	t_pipe_proc	*pipeline;

	setup_shell(argc, argv, envp);
	while (g_sh.loop == 1)
	{
		tokens = prompt();
		if (tokens == NULL)
			continue ;
		if ((has_pipes(tokens) != 0))
		{
			pipeline = build_pipeline(tokens);
			if (pipeline != NULL)
			{ 
				execute_pipeline(pipeline);
				free_pipeline(pipeline);
			}
		}
		else
			execute_simple_cmd(tokens);
		free_tokens(tokens);
	}
	free_env();
	return (0);
}
