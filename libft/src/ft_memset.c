/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:56:19 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/14 18:05:34 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char				*ptr;
	unsigned long int	*lptr;
	unsigned long int	value;

	value = 0x01010101L * (c & 0xff);
	if (sizeof(unsigned long int) > 4)
		value |= (value << 16) << 16;
	ptr = (char *)s;
	while (((unsigned long int)ptr & (sizeof(unsigned long int) - 1)) && n)
	{
		*((char *)ptr++) = (char)c;
		n--;
	}
	lptr = (unsigned long int *)ptr;
	while (n >= sizeof(unsigned long int))
	{
		*lptr++ = value;
		n -= sizeof(unsigned long int);
	}
	ptr = (char *)lptr;
	while (n--)
		*((char *)ptr++) = (char)c;
	return (s);
}
