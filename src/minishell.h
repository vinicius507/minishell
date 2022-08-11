/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:39:22 by jefernan          #+#    #+#             */
/*   Updated: 2022/08/11 11:50:53 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <env/env.h>
# include <lexer/lexer.h>

typedef struct s_shell
{
	char	loop;
	t_env	*env;
}	t_shell;

extern t_shell	g_sh;

t_token	*prompt(void);

void	execute(t_token *tokens);

#endif
