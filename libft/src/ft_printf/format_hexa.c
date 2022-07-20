/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hexa_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:32:06 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/12 19:32:06 by vgoncalv         ###   ########.fr       */
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
	char	*base;

	base = "0123456789abcdef";
	if (arg->modifier == L_NONE)
		nbr = ft_uitoa_base((unsigned int)n, base);
	else if (arg->modifier == L_L)
		nbr = ft_ultoa_base((unsigned long int)n, base);
	else if (arg->modifier == L_LL)
		nbr = ft_ulltoa_base((unsigned long long int)n, base);
	else if (arg->modifier == L_H)
		nbr = ft_uitoa_base((unsigned short int)n, base);
	else
		nbr = ft_uitoa_base((unsigned char)n, base);
	return (nbr);
}

static int	apply_alternate(char **str, t_arg *arg)
{
	char	*res;

	if (!(arg->flags & ALTERNATE)
		|| ft_strncmp("0", *str, ft_strlen(*str)) == 0)
		return (0);
	res = ft_strjoin("0x", *str);
	safe_free((void **)str);
	*str = res;
	if (*str == NULL)
		return (FT_PRINTF_ERROR);
	return (0);
}

char	*format_hexa(t_arg *arg, va_list ap)
{
	unsigned long long int	nbr;
	char					*nbr_str;
	char					*temp;

	nbr = get_nbr(arg, va_arg(ap, unsigned long long int));
	nbr_str = get_nbr_str(arg, nbr);
	if (nbr_str == NULL)
		return (NULL);
	if (apply_alternate(&nbr_str, arg) || apply_precision_hexa(&nbr_str, arg)
		|| apply_width_hexa(&nbr_str, arg))
		return (NULL);
	arg->printed += ft_strlen(nbr_str);
	if (arg->type == HEXA_U)
	{
		temp = ft_striter(nbr_str, ft_toupper);
		safe_free((void **)&nbr_str);
		nbr_str = temp;
	}
	return (nbr_str);
}
