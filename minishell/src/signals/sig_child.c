/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:47:18 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/20 18:47:18 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signals/signals.h>
#include <execute/execute.h>

void	sig_child(int signal)
{
	cleanup_process();
	exit(signal);
}
