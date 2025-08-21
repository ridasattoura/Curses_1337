/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:55:11 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/20 15:56:12 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_here_doc_input(char *av, int fdin)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if ((ft_strncmp(line, av, ft_strlen(av)) == 0)
			&& ft_strlen(line) == ft_strlen(av))
		{
			free(line);
			line = NULL;
			break ;
		}
		write(fdin, line, ft_strlen(line));
		write(fdin, "\n", 1);
		free(line);
	}
}

bool	set_flag2(char *str, int *i, t_quote *flag)
{
	if (*flag == NO_QUOTE && str[*i] == 39)
	{
		*flag = IN_S_QUOTE;
		return (true);
	}
	else if (*flag == NO_QUOTE && str[*i] == 34)
	{
		*flag = IN_D_QUOTE;
		return (true);
	}
	else if (str[*i] == 39 && *flag == IN_S_QUOTE)
	{
		*flag = NO_QUOTE;
		return (true);
	}
	else if (str[*i] == 34 && *flag == IN_D_QUOTE)
	{
		*flag = NO_QUOTE;
		return (true);
	}
	return (false);
}

char	*remove_quotes_heredoc(char *string)
{
	t_quote	flag;
	char	*expanded;
	int		i;

	i = 0;
	flag = NO_QUOTE;
	expanded = ft_strdup("");
	while (string[i])
	{
		if (set_flag2(string, &i, &flag))
			i++;
		else
			expanded = no_expand(string[i++], expanded);
	}
	free(string);
	return (expanded);
}

void	handle_all_heredocs(t_token *file, int fd)
{
	t_token	*current;
	t_token	*last_heredoc;
	int		temp_fd;

	current = file;
	last_heredoc = loop_here(current);
	while (current != NULL)
	{
		if (current->type == HEREDOC)
		{
			if (current == last_heredoc)
				temp_fd = fd;
			else
				temp_fd = open("/dev/null", O_WRONLY);
			current->value = remove_quotes_heredoc(current->value);
			handle_here_doc_input(current->value, temp_fd);
			if (temp_fd != fd)
				close(temp_fd);
		}
		current = current->next;
	}
}

void	handle_child_process(int fd[], t_token *file)
{
	signal(SIGINT, SIG_DFL);
	close(fd[0]);
	handle_all_heredocs(file, fd[1]);
	close(fd[1]);
	exit(EXIT_SUCCESS);
}
