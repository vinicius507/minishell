/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:22:33 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/18 13:21:42 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtins.h>

int	unset(int argc, char **args)
{
	while (*args != NULL)
	{
		unset_env(*args);
		args++;
	}
	(void)argc;
	return (0);
}
