/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:36:43 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/20 16:19:09 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execute/execute.h>

int	count_argc(t_token *tokens)
{
	int	argc;

	argc = 0;
	if (tokens == NULL)
		return (0);
	while (tokens != NULL)
	{
		if (tokens->type == TWORD && (ft_strcmp(tokens->value, "") != 0))
			argc++;
		tokens = tokens->next;
	}
	return (argc);
}

char	**build_argv(t_token *tokens)
{
	size_t	len;
	size_t	counter;
	char	**argv;

	len = count_argc(tokens);
	argv = ft_calloc(len + 1, sizeof(char *));
	if (argv == NULL)
		return (NULL);
	counter = 0;
	while (counter < len)
	{
		if (tokens->type == TWORD && (ft_strcmp(tokens->value, "") != 0))
			argv[counter++] = tokens->value;
		tokens = tokens->next;
	}
	return (argv);
}
