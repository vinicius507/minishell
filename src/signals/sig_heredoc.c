/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:06:30 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/20 20:06:31 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signals/signals.h>
#include <execute/execute.h>
#include <readline/readline.h>

void	sig_heredoc_child(int signal)
{
	if (signal == SIGINT)
	{
		cleanup_process();
		printf("\n");
		exit(signal);
	}
}

void	sig_heredoc_parent(int signal)
{
	rl_replace_line("", 0);
	rl_on_new_line();
	cleanup_process();
	(void)signal;
}
