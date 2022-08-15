/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:04:15 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/11 11:54:34 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtins.h>

static char	*join(t_token *args)
{
	char	*temp;
	t_token	*token;
	char	*result;

	if (args == NULL)
		return (ft_strdup(""));
	result = ft_strdup(args->value);
	token = args->next;
	while (token != NULL)
	{
		ft_asprintf(&temp, "%s %s", result, token->value);
		free(result);
		result = temp;
		token = token->next;
	}
	return (result);
}

void	echo(t_token *args)
{
	char	*output;
	char	print_nl;

	if (args == NULL)
	{
		ft_putstr("\n");
		return ;
	}
	print_nl = 1;
	if ((ft_strcmp(args->value, "-n") == 0))
	{
		print_nl = 0;
		args = args->next;
	}
	output = join(args);
	if (print_nl == 0)
		ft_putstr(output);
	else
		ft_putendl_fd(output, 1);
	free(output);
}
