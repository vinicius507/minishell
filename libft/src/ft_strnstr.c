/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:25:58 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/17 21:25:58 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b_size;
	size_t	l_size;
	size_t	s_size;

	b_size = ft_strlen(big);
	l_size = ft_strlen(little);
	if (l_size == 0)
		return ((char *)big);
	else if (l_size > b_size)
		return (NULL);
	if (b_size > len)
		s_size = len;
	else
		s_size = b_size;
	while (l_size <= s_size)
	{
		if (!ft_strncmp(big, little, l_size))
			return ((char *)big);
		big++;
		s_size--;
	}
	return (NULL);
}
