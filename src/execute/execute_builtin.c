/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:32:01 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/18 13:30:00 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execute/execute.h>
#include <builtins/builtins.h>

int	execute_builtin(t_token *tokens)
{
	int			argc;
	char		**argv;
	t_builtin	*builtin;
	int			return_code;

	builtin = get_builtin(tokens->value);
	if (builtin == NULL)
	{
		error(tokens->value, "could not execute builtin");
		return (-1);
	}
	argc = count_argc(tokens->next);
	argv = build_argv(tokens->next);
	if (argv == NULL)
	{
		error(tokens->value, "could not process command arguments");
		return (-1);
	}
	return_code = builtin(argc, argv);
	free(argv);
	return (return_code);
}