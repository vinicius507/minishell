/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:27:37 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/09/13 09:02:08 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_arg	arg;
	char	*buf;
	char	*var;

	buf = ft_strdup(format);
	var = ft_strchr(buf, '%');
	arg.printed = 0;
	while (var != NULL)
	{
		arg.printed = var - buf;
		if (arg_parser(&arg, &var, ap) || format_current(&arg, &buf, var, ap))
		{
			arg.printed = FT_PRINTF_ERROR;
			break ;
		}
		var = ft_strchr(buf + arg.printed, '%');
	}
	if (arg.printed != FT_PRINTF_ERROR)
	{
		arg.printed += ft_strlen(buf + arg.printed);
		(void)write(fd, buf, arg.printed);
		free(buf);
	}
	return (arg.printed);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		printed;

	printed = 0;
	va_start(ap, format);
	printed = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (printed);
}
