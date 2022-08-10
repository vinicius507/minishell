/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:21:28 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/10 15:03:55 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <minishell.h>

typedef void	t_builtin (char **args);

t_builtin	*get_builtin(const char *cmd);

void		shell_exit(char **args);

void		pwd(char **args);

void		echo(char **args);

void		env(char **args);

void		export(char **args);

void		unset(char **args);

void		cd(char **args);

#endif
