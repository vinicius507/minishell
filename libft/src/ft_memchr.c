/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:15:51 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/16 18:15:51 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	*wordchr(const unsigned long int *word,
	unsigned long int mask, size_t *n)
{
	unsigned long int	hi;
	unsigned long int	lo;
	unsigned long int	longword;
	const unsigned char	*ptr;

	lo = 0;
	ft_memset(&lo, 0x01, sizeof(unsigned long int));
	hi = lo << 7;
	while (*n >= sizeof(unsigned long int))
	{
		longword = mask ^ *word++;
		if ((longword - lo) & ~longword & hi)
		{
			ptr = (const unsigned char *)(word - 1);
			longword = 0;
			while (longword < sizeof(unsigned long int))
			{
				if (((unsigned char *)ptr)[longword] == (unsigned char)(mask))
					return ((void *)ptr + longword);
				longword++;
			}
		}
		*n -= sizeof(unsigned long int);
	}
	return ((void *)word);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long int		mask;

	while ((unsigned long int)s & (sizeof(unsigned long int) - 1) && n)
	{
		if (*(unsigned char *)s == (char)c)
			return ((void *)s);
		s++;
		n--;
	}
	mask = 0;
	ft_memset(&mask, c & 0xff, sizeof(unsigned long int));
	s = wordchr(s, mask, &n);
	if (n >= sizeof(unsigned long int))
		return ((void *)s);
	while (n--)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
