/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:04:15 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/02 11:49:31 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <builtins/builtins.h>

static char	*join(char **args)
{
	char	*left;
	char	*temp;
	char	**right;

	if (args[0] == NULL)
		return (ft_strdup(""));
	left = ft_strdup(args[0]);
	right = args + 1;
	while (*right != NULL)
	{
		ft_asprintf(&temp, "%s %s", left, *right);
		free(left);
		left = temp;
		right++;
	}
	return (left);
}

void	echo(char **args)
{
	char	*output;

	if (args[0] != NULL && ft_strcmp(args[0], "-n") == 0)
	{
		output = join(args + 1);
		printf("%s", output);
	}
	else
	{
		output = join(args);
		printf("%s\n", output);
	}
	free(output);
}
