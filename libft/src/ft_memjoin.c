/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:26:00 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/09 12:26:00 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(const void *m1, const void *m2, size_t size1, size_t size2)
{
	void	*m;

	if (m1 == NULL || m2 == NULL)
		return (NULL);
	m = ft_calloc(size1 + size2, sizeof(char));
	if (m == NULL)
		return (NULL);
	ft_memcpy(m, m1, size1);
	ft_memcpy(m + size1, m2, size2);
	return (m);
}
