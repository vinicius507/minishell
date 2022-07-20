/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:42:09 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/09/13 08:45:54 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			offset;
	unsigned char	*s1_u;
	unsigned char	*s2_u;

	offset = 0;
	s1_u = (unsigned char *)s1;
	s2_u = (unsigned char *)s2;
	while (s1_u[offset] && s2_u[offset])
	{
		if (s1_u[offset] != s2_u[offset])
			break ;
		offset++;
	}
	return (s1_u[offset] - s2_u[offset]);
}
