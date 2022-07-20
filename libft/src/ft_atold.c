/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:11:10 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/07/20 15:38:42 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long double	get_decimal(const char *nptr, int sign)
{
	long double	num;
	long double	decimal;

	num = 0;
	decimal = 0.1;
	if (*nptr && *nptr++ == '.')
	{
		while (*nptr && ft_isdigit(*nptr))
		{
			num += sign * (*nptr - '0') * decimal;
			decimal *= 0.1;
			nptr++;
		}
	}
	return (num);
}

long double	ft_atold(const char *nptr)
{
	long double	num;
	int			sign;

	while (ft_isspace(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	num = 0;
	while (*nptr && ft_isdigit(*nptr))
	{
		num *= 10;
		num += sign * (*nptr - '0');
		nptr++;
	}
	num += get_decimal(nptr, sign);
	return (num);
}
