/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:40:26 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/19 20:36:01 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdlib.h>

# define DOUBLE_QUOTE '"'
# define SINGLE_QUOTE '\''
# define REDIRECT_OUT '>'
# define REDIRECT_IN '<'

typedef enum e_type
{
	TWORD,
	TREDIRECT_OUT,
	TREDIRECT_IN,
	TREDIRECT_APPND,
	TREDIRECT_HDOC,
	TCOUNT,
}	t_type;

typedef struct s_token
{
	t_type			type;
	char			*value;
	struct s_token	*next;
}	t_token;

t_token	*new_token(t_type type, char *value, t_token *previous);

void	free_tokens(t_token *token);

int		tokens_count(t_token *token);

t_token	*lex(char *input);

int		is_metachar(char c);

int		is_quote(char c);

int		is_redirect(char c);

char	has_matching_quote(char *str);

char	*get_env_key(char *str);

char	*expand_env_vars(char *word);

char	*word(char *input, size_t *counter, int expand);

char	*redirect(char *input, size_t *counter);

char	*here_doc(char *input, size_t *counter);

#endif
