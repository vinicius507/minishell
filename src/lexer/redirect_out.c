/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:22:59 by jefernan          #+#    #+#             */
/*   Updated: 2022/08/19 15:28:37 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <minishell.h>

char	*redirect(char *input, size_t *counter)
{
	*counter += 1;
	while (ft_isspace(input[*counter]) != 0)
		*counter += 1;
	return (word(input, counter));
}