/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-17 12:33:00 by vgoncalv          #+#    #+#             */
/*   Updated: 2024-04-17 12:34:00 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_isspace(int c)
{
	return (c == ' '
		|| c == '\t'
		|| c == '\r'
		|| c == '\f'
		|| c == '\n'
		|| c == '\v');
}

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
