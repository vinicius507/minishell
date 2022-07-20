/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:43:46 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/17 21:43:46 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			offset;
	unsigned char	*s1_u;
	unsigned char	*s2_u;

	offset = 0;
	s1_u = (unsigned char *)s1;
	s2_u = (unsigned char *)s2;
	while (offset < n && s1_u[offset] && s2_u[offset])
	{
		if (s1_u[offset] != s2_u[offset])
			break ;
		offset++;
	}
	if (offset == n)
		return (0);
	return (s1_u[offset] - s2_u[offset]);
}
