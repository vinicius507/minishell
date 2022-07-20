/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_literal_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:04:38 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/13 14:04:38 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	should_default(t_arg *arg)
{
	if (!(arg->flags & ZERO_PAD)
		|| arg->flags & LEFT_JUSTIFY)
		return (1);
	return (0);
}

static char	*get_pad_w(int size)
{
	char	*pad;

	if (size <= 0)
		return (ft_strdup(""));
	pad = ft_calloc(size + 1, sizeof(char));
	if (pad == NULL)
		return (NULL);
	while (size--)
		pad[size] = '0';
	return (pad);
}

int	apply_width_literal(char **str, t_arg *arg)
{
	char	*res;
	char	*temp;

	if (should_default(arg))
	{
		if (apply_width(str, arg))
			return (FT_PRINTF_ERROR);
		return (0);
	}
	temp = get_pad_w(arg->width - ft_strlen(*str));
	res = ft_strjoin(temp, *str);
	safe_free((void **)str);
	safe_free((void **)&temp);
	*str = res;
	if (*str == NULL)
		return (FT_PRINTF_ERROR);
	return (0);
}
