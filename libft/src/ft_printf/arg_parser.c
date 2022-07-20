/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:42:54 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/09 18:42:54 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_types	get_type(char f)
{
	if (f == '%')
		return (LITERAL);
	else if (f == 'd' || f == 'i')
		return (INTEGER);
	else if (f == 'u')
		return (U_INTEGER);
	else if (f == 'c')
		return (CHARACTER);
	else if (f == 's')
		return (STRING);
	else if (f == 'p')
		return (POINTER);
	else if (f == 'x')
		return (HEXA_L);
	else if (f == 'X')
		return (HEXA_U);
	return (TYPE_ERROR);
}

int	arg_parser(t_arg *arg, char **var, va_list ap)
{
	char	*ptr;

	ptr = *var + 1;
	arg->flags = flags_parser(&ptr);
	arg->width = width_parser(&ptr, ap);
	if (arg->width < 0)
	{
		arg->width *= -1;
		arg->flags |= LEFT_JUSTIFY;
	}
	arg->precision = precision_parser(&ptr, ap);
	arg->modifier = length_parser(&ptr);
	arg->type = get_type(*ptr);
	*var = ptr + 1;
	if (arg->type == TYPE_ERROR)
		return (FT_PRINTF_ERROR);
	return (0);
}
