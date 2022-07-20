/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:56:07 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/12 17:56:09 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	void	*ptr;
	size_t	distance;

	ptr = ft_memchr(src, c, n);
	if (ptr != NULL)
	{
		distance = (size_t)ptr - (size_t)src + 1;
		return (ft_memcpy(dest, src, distance) + distance);
	}
	ft_memcpy(dest, src, n);
	return (NULL);
}
