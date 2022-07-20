/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_int_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:42:29 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/09 18:42:29 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	should_default(t_arg *arg)
{
	if (arg->flags & LEFT_JUSTIFY || !(arg->flags & ZERO_PAD)
		|| (arg->flags & ZERO_PAD && arg->precision >= 0))
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

int	apply_width_int(char **str, t_arg *arg)
{
	int		sign;
	char	*res;
	char	*temp;

	if (should_default(arg))
	{
		if (apply_width(str, arg))
			return (FT_PRINTF_ERROR);
		return (0);
	}
	sign = int_has_sign(*str);
	temp = get_pad_w(arg->width - ft_strlen(*str));
	res = ft_strjoin(temp, *str + (sign != 0));
	safe_free((void **)str);
	safe_free((void **)&temp);
	if (sign)
	{
		temp = ft_calloc(2, sizeof(char));
		temp[0] = sign;
		res = safe_join(&temp, &res);
	}
	*str = res;
	if (*str == NULL)
		return (FT_PRINTF_ERROR);
	return (0);
}

static char	*get_pad_p(int size)
{
	char	*str;

	if (size <= 0)
		return (ft_strdup(""));
	str = ft_calloc(size + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (size--)
		str[size] = '0';
	return (str);
}

int	apply_precision_int(char **str, t_arg *arg)
{
	char	*res;
	char	*temp;
	int		sign;

	if (arg->precision < 0)
		return (0);
	sign = int_has_sign(*str);
	temp = get_pad_p(arg->precision - ft_strlen(*str) + (sign != 0));
	if (arg->precision == 0 && ft_strncmp(*str
			+ (sign != 0), "0", ft_strlen(*str + (sign != 0))) == 0)
		res = ft_strdup("");
	else
		res = ft_strjoin(temp, *str + (sign != 0));
	safe_free((void **)str);
	safe_free((void **)&temp);
	if (sign)
	{
		temp = ft_calloc(2, sizeof(char));
		temp[0] = sign;
		res = safe_join(&temp, &res);
	}
	*str = res;
	if (*str == NULL)
		return (FT_PRINTF_ERROR);
	return (0);
}
