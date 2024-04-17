/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 04:28:22 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/22 04:28:23 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execute/execute.h>
#include <builtins/builtins.h>

void	execute_simple_cmd(t_token *tokens)
{
	t_command	*command;

	command = new_command(tokens);
	if (command == NULL)
		return ;
	if ((is_builtin(command->argv[0]) != 0))
		g_sh.ret_code = execute_builtin(command);
	else
		execute_bin(command);
	free_command(command);
}
