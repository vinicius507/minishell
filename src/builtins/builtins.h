/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:21:28 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/10 16:58:23 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <minishell.h>

typedef void	t_builtin (t_token *args);

t_builtin	*get_builtin(const char *cmd);

void		shell_exit(t_token *args);

void		pwd(t_token *args);

void		echo(t_token *args);

void		env(t_token *args);

void		export(t_token *args);

void		unset(t_token *args);

void		cd(t_token *args);

#endif
