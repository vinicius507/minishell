/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:43:32 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/09/13 09:01:42 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vasprintf(char **buf, const char *format, va_list ap)
{
	char	*dup;
	char	*var;
	t_arg	arg;

	dup = ft_strdup(format);
	var = ft_strchr(dup, '%');
	arg.printed = 0;
	while (var != NULL)
	{
		arg.printed = var - dup;
		if (arg_parser(&arg, &var, ap) || format_current(&arg, &dup, var, ap))
		{
			arg.printed = FT_PRINTF_ERROR;
			break ;
		}
		var = ft_strchr(dup + arg.printed, '%');
	}
	if (arg.printed != FT_PRINTF_ERROR)
	{
		arg.printed += ft_strlen(dup + arg.printed);
		*buf = dup;
	}
	return (arg.printed);
}

int	ft_asprintf(char **buf, const char *format, ...)
{
	va_list	ap;
	int		printed;

	va_start(ap, format);
	printed = ft_vasprintf(buf, format, ap);
	va_end(ap);
	return (printed);
}
