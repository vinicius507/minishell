/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:39:22 by jefernan          #+#    #+#             */
/*   Updated: 2022/08/18 13:15:06 by vgoncalv         ###   ########.fr       */
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
	int		ret_code;
	t_env	*env;
}	t_shell;

extern t_shell	g_sh;

t_token	*prompt(void);

void	error(char *message, char *detail);

#endif
