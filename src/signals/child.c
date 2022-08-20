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

void	sig_child(int signal)
{
	if (signal == SIGINT)
		g_sh.ret_code = 130;
	else if (signal == SIGQUIT)
		g_sh.ret_code = 131;
	exit(g_sh.ret_code);
}
