/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:42:59 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/09 18:42:59 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int	get_nbr(t_arg *arg, long long int n)
{
	long long int	nbr;

	if (arg->modifier == L_NONE)
		nbr = (int)n;
	else if (arg->modifier == L_L)
		nbr = (long int)n;
	else if (arg->modifier == L_LL)
		nbr = (long long int)n;
	else if (arg->modifier == L_H)
		nbr = (short int)n;
	else
		nbr = (char)n;
	return (nbr);
}

static char	*get_nbr_str(t_arg *arg, long long int n)
{
	char	*nbr;

	if (arg->modifier == L_NONE)
		nbr = ft_itoa((int)n);
	else if (arg->modifier == L_L)
		nbr = ft_ltoa((long int)n);
	else if (arg->modifier == L_LL)
		nbr = ft_lltoa((long long int)n);
	else if (arg->modifier == L_H)
		nbr = ft_itoa((short int)n);
	else
		nbr = ft_itoa((char)n);
	return (nbr);
}

static int	apply_sign(char **nbr_str, t_arg *arg)
{
	char	*res;

	if (**nbr_str == '-')
		return (0);
	if (!(arg->flags & (PLUS | SPACE)))
		return (0);
	if (arg->flags & PLUS)
		res = ft_strjoin("+", *nbr_str);
	else
		res = ft_strjoin(" ", *nbr_str);
	safe_free((void **) nbr_str);
	*nbr_str = res;
	if (*nbr_str == NULL)
		return (FT_PRINTF_ERROR);
	return (0);
}

char	*format_int(t_arg *arg, va_list ap)
{
	long long int	nbr;
	char			*nbr_str;

	nbr = get_nbr(arg, va_arg(ap, long long int));
	nbr_str = get_nbr_str(arg, nbr);
	if (nbr_str == NULL)
		return (NULL);
	if (apply_sign(&nbr_str, arg) || apply_precision_int(&nbr_str, arg)
		|| apply_width_int(&nbr_str, arg))
		return (NULL);
	arg->printed += ft_strlen(nbr_str);
	return (nbr_str);
}
