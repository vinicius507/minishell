/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:32:34 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/16 18:32:34 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_diff(const void *s1, const void *s2)
{
	size_t				counter;
	const unsigned char	*s1p;
	const unsigned char	*s2p;

	s1p = (unsigned char *)s1;
	s2p = (unsigned char *)s2;
	counter = 8;
	while (counter-- && *s1p++ == *s2p++)
		;
	return (*(s1p - 1) - *(s2p - 1));
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned long int	*s1p;
	const unsigned long int	*s2p;
	unsigned int			counter;
	unsigned int			bytes_per_word;

	counter = 3;
	while ((1 << counter) < __WORDSIZE)
		counter++;
	bytes_per_word = (1 << (counter - 3));
	while (n & (bytes_per_word - 1))
	{
		if (*((unsigned char *)s1++) != *((unsigned char *)s2++))
			return (*((unsigned char *)s1 - 1) - *((unsigned char *)s2 - 1));
		n--;
	}
	n >>= (counter - 3);
	s1p = (unsigned long int *)s1;
	s2p = (unsigned long int *)s2;
	while (n--)
	{
		if (*s1p++ ^ *s2p++)
			return (get_diff(s1p - 1, s2p - 1));
	}
	return (0);
}
