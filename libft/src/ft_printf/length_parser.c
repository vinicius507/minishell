/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_parser_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:42:48 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/09 18:42:48 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	has_length_modifier(char c)
{
	if (c == 'l' || c == 'h')
		return (1);
	return (0);
}

uint8_t	length_parser(char **f)
{
	char		*ptr;
	t_length	length;

	ptr = *f;
	length = L_NONE;
	if (!has_length_modifier(*ptr))
		return (length);
	if (!ft_strncmp(ptr, "ll", 2))
	{
		length = L_LL;
		ptr++;
	}
	else if (*ptr == 'l')
		length = L_L;
	else if (!ft_strncmp(ptr, "hh", 2))
	{
		length = L_HH;
		ptr++;
	}
	else if (*ptr == 'h')
		length = L_H;
	*f = ++ptr;
	return (length);
}
