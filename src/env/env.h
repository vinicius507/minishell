/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:37:24 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/02 12:59:41 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_env
{
	const char		*key;
	const char		*value;
	struct s_env	*next;
}	t_env;

t_env	*set_env(const char *key, const char*value);

void	setup_env(char **envp);

t_env	*get_env(const char *key);

void	free_env(void);

#endif