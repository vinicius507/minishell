/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:47:23 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/20 18:47:23 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signals/signals.h>
#include <execute/execute.h>

void	sig_parent(int signal)
{
	if (signal == SIGINT)
		printf("\n");
	else if (signal == SIGQUIT)
		ft_dprintf(STDERR_FILENO, "Quit\n");
	cleanup_process();
	(void)signal;
}
