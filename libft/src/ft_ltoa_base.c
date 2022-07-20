/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:37:52 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/09 10:37:52 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_int_base(char *base)
{
	int	int_base;

	int_base = 0;
	while (*base)
	{
		if (ft_strchr(base + 1, *base))
			return (0);
		base++;
		int_base++;
	}
	if (int_base <= 1)
		return (0);
	return (int_base);
}

static char	*get_nbr_str(long int n, int int_base, char *base, size_t size)
{
	char	*str;

	str = ft_calloc(size + 1, sizeof(char));
	if (n >= 0)
	{
		while (size--)
		{
			str[size] = base[(n % int_base)];
			n /= int_base;
		}
	}
	else
	{
		while (--size)
		{
			str[size] = base[((n % int_base) * -1)];
			n /= int_base;
		}
		str[0] = '-';
	}
	return (str);
}

char	*ft_ltoa_base(long int n, char *base)
{
	char			*res;
	int				int_base;
	long int		counter;
	size_t			size;

	int_base = get_int_base(base);
	if (!int_base)
		return (NULL);
	size = 1;
	if (n < 0)
		size += 1;
	counter = n / int_base;
	while (counter)
	{
		size++;
		counter /= int_base;
	}
	res = get_nbr_str(n, int_base, base, size);
	return (res);
}
