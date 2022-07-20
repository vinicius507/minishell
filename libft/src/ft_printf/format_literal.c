/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_literal_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:25:36 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/12 19:25:36 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_literal(t_arg *arg)
{
	char		*str;

	str = ft_strdup("%");
	if (str == NULL)
		return (NULL);
	if (apply_width_literal(&str, arg))
		return (NULL);
	arg->printed += ft_strlen(str);
	return (str);
}
