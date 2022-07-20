/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:56:41 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/12 15:56:41 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_pad_w(int size)
{
	char	*pad;

	if (size < 0)
		return (ft_strdup(""));
	pad = ft_calloc(size + 1, sizeof(char));
	if (pad == NULL)
		return (NULL);
	while (size--)
		pad[size] = ' ';
	return (pad);
}

int	apply_width_char(char **str, t_arg *arg)
{
	char	*res;
	char	*temp;

	if (**str != 0)
	{
		if (apply_width(str, arg))
			return (FT_PRINTF_ERROR);
		return (0);
	}
	temp = get_pad_w(arg->width - 1);
	if (arg->flags & LEFT_JUSTIFY)
		res = ft_memjoin(*str, temp, 1, ft_strlen(temp) + 1);
	else
		res = ft_memjoin(temp, *str, ft_strlen(temp), 2);
	safe_free((void **)&temp);
	safe_free((void **)str);
	*str = res;
	if (*str == NULL)
		return (FT_PRINTF_ERROR);
	return (0);
}
