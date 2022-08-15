/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:57:58 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/15 15:40:51 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtins.h>

int	pwd(int argc, t_token *args)
{
	printf("%s\n", get_env("PWD")->value);
	(void)args;
	(void)argc;
	return (0);
}
