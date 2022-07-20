/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:14:30 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/10 17:14:30 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_pad_w(int size)
{
	char	*pad;

	pad = ft_calloc(size + 1, sizeof(char));
	if (pad == NULL)
		return (NULL);
	while (size--)
		pad[size] = ' ';
	return (pad);
}

int	apply_width(char **str, t_arg *arg)
{
	int		size;
	int		pad;
	char	*res;
	char	*temp;

	size = ft_strlen(*str);
	pad = arg->width - size;
	if (pad <= 0)
		return (0);
	temp = get_pad_w(arg->width - size);
	if (arg->flags & LEFT_JUSTIFY)
		res = ft_strjoin(*str, temp);
	else
		res = ft_strjoin(temp, *str);
	safe_free((void **)str);
	safe_free((void **)&temp);
	*str = res;
	if (res == NULL)
		return (FT_PRINTF_ERROR);
	return (0);
}
