/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parser_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:42:42 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/09 18:42:42 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	isflag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
		return (1);
	return (0);
}

static t_flags	get_flag(char f)
{
	t_flags	flag;

	if (f == '#')
		flag = ALTERNATE;
	else if (f == '0')
		flag = ZERO_PAD;
	else if (f == '-')
		flag = LEFT_JUSTIFY;
	else if (f == ' ')
		flag = SPACE;
	else
		flag = PLUS;
	return (flag);
}

uint8_t	flags_parser(char **f)
{
	char	*ptr;
	uint8_t	flags;

	ptr = *f;
	flags = 0;
	while (*ptr && isflag(*ptr))
		flags |= get_flag(*ptr++);
	*f = ptr;
	return (flags);
}
