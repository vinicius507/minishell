/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:13:02 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/12 17:13:02 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	apply_precision_ptr(char **str, t_arg *arg)
{
	char	*res;

	if (arg->precision != 0)
		return (0);
	if (ft_strncmp(*str, "0x0", ft_strlen(*str)))
		return (0);
	res = ft_strdup("0x");
	safe_free((void **)str);
	*str = res;
	if (*str == NULL)
		return (FT_PRINTF_ERROR);
	return (0);
}
