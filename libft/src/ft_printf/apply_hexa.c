/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_hexa_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:46:00 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/12 19:46:00 by vgoncalv         ###   ########.fr       */
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

int	apply_width_hexa(char **str, t_arg *arg)
{
	char	*res;
	char	*temp;
	size_t	start;

	if (should_default(arg))
	{
		if (apply_width(str, arg))
			return (FT_PRINTF_ERROR);
		return (0);
	}
	start = hexa_has_alternate(*str) * 2;
	temp = get_pad_w(arg->width - ft_strlen(*str));
	res = ft_strjoin(temp, *str + start);
	safe_free((void **)&temp);
	safe_free((void **)str);
	if (start)
	{
		temp = ft_strjoin("0x", res);
		safe_free((void **)&res);
		res = temp;
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

int	apply_precision_hexa(char **str, t_arg *arg)
{
	char	*res;
	char	*temp;
	int		start;

	if (arg->precision < 0)
		return (0);
	start = hexa_has_alternate(*str) * 2;
	temp = get_pad_p(arg->precision - ft_strlen(*str) + start);
	if (arg->precision == 0 && ft_strncmp(*str, "0", ft_strlen(*str)) == 0)
		res = ft_strdup("");
	else
		res = ft_strjoin(temp, (*str + start));
	safe_free((void **)&temp);
	safe_free((void **)str);
	if (start)
	{
		temp = ft_strjoin("0x", res);
		safe_free((void **)&res);
		res = temp;
	}
	*str = res;
	if (*str == NULL)
		return (FT_PRINTF_ERROR);
	return (0);
}
