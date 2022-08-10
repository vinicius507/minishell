/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:33:21 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/10 14:37:23 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_free_string_array(char **str_arr)
{
	size_t	offset;

	if (str_arr == NULL)
		return ;
	offset = 0;
	while (str_arr[offset] != NULL)
		free(str_arr[offset++]);
	free(str_arr);
}