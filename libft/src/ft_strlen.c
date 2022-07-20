/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:56:33 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/15 00:12:10 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	wordlen(const unsigned long int *word, const char *str)
{
	const char			*ptr;
	unsigned long int	lo;
	unsigned long int	hi;
	unsigned long int	longword;
	size_t				counter;

	lo = 0x01010101L;
	if (sizeof(unsigned long int) > 4)
		lo |= (lo << 16) << 16;
	hi = lo << 7;
	while (1)
	{
		longword = *word++;
		if ((longword - lo) & ~longword & hi)
		{
			ptr = (const char *)(word - 1);
			counter = 0;
			while (counter < sizeof(longword))
			{
				if (ptr[counter] == '\0')
					return (ptr - str + counter);
				counter++;
			}
		}
	}
}

size_t	ft_strlen(const char *str)
{
	const char				*ptr;
	const unsigned long int	*word;

	ptr = str;
	while ((unsigned long)ptr & (sizeof(unsigned long) - 1))
	{
		if (*ptr == '\0')
			return (ptr - str);
		ptr++;
	}
	word = (unsigned long int *)ptr;
	return (wordlen(word, str));
}
