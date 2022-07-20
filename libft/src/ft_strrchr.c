/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:37:00 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/17 20:37:00 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned char	*s_u;
	unsigned char	c_u;

	len = ft_strlen(s) + 1;
	c_u = (unsigned char)c;
	s_u = (unsigned char *)s;
	while (len--)
	{
		if (s_u[len] == c_u)
			return ((char *)s + len);
	}
	return (NULL);
}
