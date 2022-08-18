/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:25:27 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/18 12:58:26 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtins.h>

int	shell_exit(int argc, char **args)
{
	printf("exit\n");
	g_sh.loop = 0;
	(void)args;
	(void)argc;
	return (0);
}
