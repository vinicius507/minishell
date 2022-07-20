/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:51:56 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/14 18:44:10 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	*wordcpy(unsigned long int *dest,
	unsigned long int *src,
	size_t *n,
	unsigned int bytes_per_word)
{
	while (*n >= bytes_per_word)
	{
		*--dest = *--src;
		*n -= bytes_per_word;
	}
	return (dest);
}

static void	cpy_bwd(void *dest, const void *src, size_t n)
{
	size_t					counter;
	unsigned int			bytes_per_word;

	counter = 3;
	while ((1 << counter) < __WORDSIZE)
		counter++;
	bytes_per_word = (1 << (counter - 3));
	src += n;
	dest += n;
	while ((unsigned long int)dest & (bytes_per_word - 1) && n)
	{
		*((char *)--dest) = *((char *)--src);
		n--;
	}
	counter = dest - wordcpy(dest, (void *)src, &n, bytes_per_word);
	dest -= counter;
	src -= counter;
	while (n--)
	{
		dest--;
		src--;
		*(char *)dest = *(char *)src;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src)
		return (dest);
	if (src < dest && dest < src + n)
		cpy_bwd(dest, src, n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
