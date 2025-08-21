/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:11:26 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/09 16:33:50 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_BONUS_H
# define LEXER_BONUS_H

# include <stdbool.h>

typedef enum e_token_type
{
	COMMAND,
	PIPE,
	REDIRECT_IN,
	REDIRECT_OUT,
	APPEND,
	HEREDOC,
	EXPAND_HERE_DOC,
	AND,
	OR,
	parenthesis_open,
	parenthesis_close,
	AMBIGUOUS,
}		t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

t_token			*create_list(char *line);
void			add_token(t_token **lst, t_token *new);
t_token			*new_token(t_token_type type, char *value);
void			skip_whitespaces(char *line, int *i);
int				is_operator_start(char *c);
t_token_type	get_token_type(char *s);
char			*grab_operator(char *s, int *i);
char			*grab_word(char *line, int *i, int *err);
int				is_whitespace(char c);
int				is_quote(char c);
#endif