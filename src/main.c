/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:22:43 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/10 17:40:00 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <builtins/builtins.h>

t_shell	g_sh;

int	main(int argc, char **argv, char **envp)
{
	t_token		*tokens;
	t_builtin	*builtin;

	g_sh.loop = 1;
	builtin = NULL;
	setup_env(envp);
	while (g_sh.loop == 1)
	{
		tokens = prompt();
		if (tokens == NULL)
			continue ;
		builtin = get_builtin(tokens->value);
		if (builtin != NULL)
			builtin(tokens->next);
		else if (tokens != NULL)
			execute(tokens);
		free_tokens(tokens);
	}
	free_env();
	(void)argc;
	(void)argv;
	return (0);
}
