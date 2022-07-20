/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:55:30 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/15 00:13:06 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char					*ptr;
	unsigned long int		*destp;
	const unsigned long int	*srcp;

	if (dest == src)
		return (dest);
	ptr = dest;
	while ((unsigned long int)ptr & (sizeof(unsigned long) - 1) && n)
	{
		*ptr++ = *((char *)src++);
		n--;
	}
	destp = (unsigned long int *)(ptr);
	srcp = (unsigned long int *)(src);
	while (n >= sizeof(unsigned long))
	{
		*destp++ = *srcp++;
		n -= sizeof(unsigned long);
	}
	ptr = (char *)destp;
	src = (void *)srcp;
	while (n--)
		*ptr++ = *(char *)(src++);
	return (dest);
}
