/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:34:01 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/20 18:34:02 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signals/signals.h>

void	setup_signal(void (*handler)(int), int signal)
{
	struct sigaction	action;

	ft_memset(&action, 0, sizeof(struct sigaction));
	action.sa_handler = handler;
	action.sa_flags = SA_RESTART;
	sigemptyset(&action.sa_mask);
	sigaction(signal, &action, NULL);
}
