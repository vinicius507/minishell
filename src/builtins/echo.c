/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:04:15 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/18 13:23:52 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtins.h>

static char	*join(char **args)
{
	char	*temp;
	char	*result;

	if (args == NULL || *args == NULL)
		return (ft_strdup(""));
	result = ft_strdup(args[0]);
	if (result == NULL)
		return (NULL);
	args++;
	while (*args != NULL)
	{
		ft_asprintf(&temp, "%s %s", result, *args);
		free(result);
		if (temp == NULL)
			return (NULL);
		result = temp;
		args++;
	}
	return (result);
}

int	echo(int argc, char **args)
{
	char	*output;
	char	print_nl;

	print_nl = 1;
	if (args[0] != NULL && (ft_strcmp(args[0], "-n") == 0))
	{
		print_nl = 0;
		args++;
	}
	output = join(args);
	if (output == NULL)
	{
		error("echo: could not parse arguments", NULL);
		return (1);
	}
	if (print_nl == 0)
		ft_putstr(output);
	else
		ft_putendl_fd(output, 1);
	free(output);
	(void)argc;
	return (0);
}
