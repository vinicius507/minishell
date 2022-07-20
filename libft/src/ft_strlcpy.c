/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:28:56 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/16 19:28:56 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	offset;

	if (src == NULL || dest == NULL)
		return (0);
	if (size > 0)
	{
		offset = 0;
		while (offset < size - 1 && src[offset])
		{
			dest[offset] = src[offset];
			offset++;
		}
		dest[offset] = '\0';
	}
	return (ft_strlen(src));
}
