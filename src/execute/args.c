/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:36:43 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/18 12:56:50 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execute/execute.h>

int	count_argc(t_token *tokens)
{
	return (tokens_count(tokens));
}

char	**build_argv(t_token *tokens)
{
	size_t	len;
	t_token	*temp;
	size_t	counter;
	char	**argv;

	len = 0;
	temp = tokens;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	argv = ft_calloc(len + 1, sizeof(char *));
	if (argv == NULL)
		return (NULL);
	counter = 0;
	while (counter < len)
	{
		argv[counter++] = tokens->value;
		tokens = tokens->next;
	}
	return (argv);
}
