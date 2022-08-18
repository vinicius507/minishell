/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 20:54:19 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/18 13:29:35 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <minishell.h>

int		count_argc(t_token *tokens);

char	**build_argv(t_token *tokens);

int		execute_builtin(t_token *tokens);

void	execute_bin(t_token *tokens);

#endif