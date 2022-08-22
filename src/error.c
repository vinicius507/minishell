/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:11:21 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/18 13:14:38 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	error(char *message, char *detail)
{
	if (message == NULL)
		message = "unknown error";
	if (detail == NULL)
		ft_dprintf(STDERR_FILENO, "%s: %s\n", g_sh.sh_name, message);
	else
		ft_dprintf(STDERR_FILENO, "%s: %s: %s\n", g_sh.sh_name, message, detail);
}

void	syntax_error(char *token)
{
	error("syntax error near token", token);
	g_sh.ret_code = 2;
}
