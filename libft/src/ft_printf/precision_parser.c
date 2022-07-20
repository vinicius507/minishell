/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_parser_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:42:11 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/09 18:42:11 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	precision_parser(char **f, va_list ap)
{
	char	*ptr;
	int		precision;

	ptr = *f;
	if (*ptr && *ptr++ != '.')
		return (-1);
	precision = 0;
	if (*ptr && ft_isdigit(*ptr))
	{
		precision = ft_atoi(ptr);
		while (*ptr && ft_isdigit(*ptr))
			ptr++;
	}
	else if (*ptr && *ptr == '*')
	{
		precision = va_arg(ap, int);
		ptr++;
	}
	*f = ptr;
	return (precision);
}
