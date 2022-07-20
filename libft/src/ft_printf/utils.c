/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:42:23 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/09 18:42:23 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	safe_free(void **ptr)
{
	if (*ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}

char	*safe_join(char **s1, char **s2)
{
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = ft_strjoin(*s1, *s2);
	safe_free((void **)s1);
	safe_free((void **)s2);
	if (res == NULL)
		return (NULL);
	return (res);
}

int	int_has_sign(char *str)
{
	if (*str == '-' || *str == '+' || *str == ' ')
		return (*str);
	return (0);
}

int	hexa_has_alternate(char *str)
{
	if (ft_strncmp("0x", str, 2) == 0)
		return (1);
	return (0);
}

int	print_buffer(char **buf, t_arg *arg)
{
	(void)write(1, *buf, arg->printed);
	safe_free((void **)buf);
	return (arg->printed);
}
