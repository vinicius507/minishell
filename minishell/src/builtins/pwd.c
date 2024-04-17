/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:57:58 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/18 13:04:11 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtins.h>

int	pwd(int argc, char **args)
{
	printf("%s\n", get_env("PWD")->value);
	(void)args;
	(void)argc;
	return (0);
}
