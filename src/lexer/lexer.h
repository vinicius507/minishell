/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:40:26 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/11 11:51:42 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef struct s_token
{
	char			*value;
	struct s_token	*next;
}	t_token;

t_token	*new_token(t_token *previous);

void	free_tokens(t_token *token);

t_token	*lex(char *input);

#endif