/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:22:33 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/15 15:39:57 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtins.h>

int	unset(int argc, t_token *args)
{
	while (args != NULL)
	{
		unset_env(args->value);
		args = args->next;
	}
	(void)argc;
	return (0);
}
