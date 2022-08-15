/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:21:28 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/15 15:28:49 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <minishell.h>

typedef int	t_builtin (int argc, t_token *args);

t_builtin	*get_builtin(const char *cmd);

int			shell_exit(int argc, t_token *args);

int			pwd(int argc, t_token *args);

int			echo(int argc, t_token *args);

int			env(int argc, t_token *args);

int			export(int argc, t_token *args);

int			unset(int argc, t_token *args);

int			cd(int argc, t_token *args);

#endif
