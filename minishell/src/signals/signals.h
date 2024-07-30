/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:31:02 by vgoncalv          #+#    #+#             */
/*   Updated: 2024/07/30 10:14:43 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "../minishell.h"
# include <signal.h>

void	setup_signal(void (*handler)(int), int signal);

void	sig_child(int signal);

void	sig_parent(int signal);

void	sig_prompt(int signal);

void	sig_heredoc_child(int signal);

void	sig_heredoc_parent(int signal);

#endif
