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
		ft_dprintf(STDERR_FILENO, "minishell: %s\n", message);
	else
		ft_dprintf(STDERR_FILENO, "minishell: %s: %s\n", message, detail);
}
