/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:22:59 by jefernan          #+#    #+#             */
/*   Updated: 2022/08/19 17:09:49 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <minishell.h>

char	*redirect(char *input, size_t *counter)
{
	char	*fname;

	while ((is_redirect(input[*counter]) != 0))
		*counter += 1;
	while ((ft_isspace(input[*counter]) != 0))
		*counter += 1;
	fname = word(input, counter, 1);
	if (fname != NULL && (ft_strcmp(fname, "") == 0))
	{
		free(fname);
		return (NULL);
	}
	return (fname);
}
