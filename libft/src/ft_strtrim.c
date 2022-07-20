/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:01:19 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/19 15:01:19 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contains(const char *set, const char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static size_t	get_limit(const char *str, const char *set)
{
	size_t	len;

	len = ft_strlen(str);
	while (len-- && contains(set, str[len]))
		;
	return (len + 1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*res;
	size_t	limit;
	size_t	offset;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (contains(set, *s1))
		s1++;
	limit = get_limit(s1, set);
	res = malloc(limit + 1);
	if (res == NULL)
		return (NULL);
	offset = 0;
	while (offset < limit)
	{
		res[offset] = s1[offset];
		offset++;
	}
	res[offset] = '\0';
	return (res);
}
