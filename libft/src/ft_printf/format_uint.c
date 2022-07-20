/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_uint_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:17:43 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/12 13:17:43 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long int	get_nbr(t_arg *arg, unsigned long long int n)
{
	long long int	nbr;

	if (arg->modifier == L_NONE)
		nbr = (unsigned int)n;
	else if (arg->modifier == L_L)
		nbr = (unsigned long int)n;
	else if (arg->modifier == L_LL)
		nbr = (unsigned long long int)n;
	else if (arg->modifier == L_H)
		nbr = (unsigned short int)n;
	else
		nbr = (unsigned char)n;
	return (nbr);
}

static char	*get_nbr_str(t_arg *arg, unsigned long long int n)
{
	char	*nbr;

	if (arg->modifier == L_NONE)
		nbr = ft_uitoa((unsigned int)n);
	else if (arg->modifier == L_L)
		nbr = ft_ultoa((unsigned long int)n);
	else if (arg->modifier == L_LL)
		nbr = ft_ulltoa((unsigned long long int)n);
	else if (arg->modifier == L_H)
		nbr = ft_uitoa((unsigned short int)n);
	else
		nbr = ft_uitoa((unsigned char)n);
	return (nbr);
}

char	*format_uint(t_arg *arg, va_list ap)
{
	unsigned long long int	nbr;
	char					*nbr_str;

	nbr = get_nbr(arg, va_arg(ap, unsigned long long int));
	nbr_str = get_nbr_str(arg, nbr);
	if (nbr_str == NULL)
		return (NULL);
	if (apply_precision_uint(&nbr_str, arg)
		|| apply_width_uint(&nbr_str, arg))
		return (NULL);
	arg->printed += ft_strlen(nbr_str);
	return (nbr_str);
}
