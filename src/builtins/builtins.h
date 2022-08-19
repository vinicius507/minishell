/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:21:28 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/18 13:23:08 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <minishell.h>

typedef int	t_builtin (int argc, char **args);

int			is_builtin(char *cmd);

t_builtin	*get_builtin(const char *cmd);

int			shell_exit(int argc, char **args);

int			pwd(int argc, char **args);

int			echo(int argc, char **args);

int			env(int argc, char **args);

int			export(int argc, char **args);

int			unset(int argc, char **args);

int			cd(int argc, char **args);

#endif
