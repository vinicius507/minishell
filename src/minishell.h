/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:39:22 by jefernan          #+#    #+#             */
/*   Updated: 2022/08/02 18:44:09 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <env/env.h>

typedef struct s_shell
{
	char	loop;
	t_env	*env;
}	t_shell;

extern t_shell	g_sh;

char	**lex(char *input);

char	**prompt(void);

#endif
