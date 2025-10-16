/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 05:42:46 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/05 06:00:44 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	core_find(t_token *list, t_dir_entry *entry,
	bool *found_first, t_token **expanded_list)
{
	if (wildcard_match(list->value, entry->d_name))
	{
		if (!*found_first)
		{
			add_token(expanded_list, new_token(list->type,
					ft_strdup(entry->d_name)));
			*found_first = true;
		}
		else
			add_token(expanded_list, new_token(AMBIGUOUS,
					ft_strdup(entry->d_name)));
	}
}

bool	find_files(t_token *list, t_token **expanded_list)
{
	t_dir_entry	*entry;
	DIR			*directory;
	bool		found_first;

	found_first = false;
	directory = opendir(".");
	if (!directory)
		return (false);
	entry = readdir(directory);
	while (entry)
	{
		if (entry->d_name[0] == '.' && list->value[0] != '.')
		{
			entry = readdir(directory);
			continue ;
		}
		core_find(list, entry, &found_first, expanded_list);
		entry = readdir(directory);
	}
	closedir(directory);
	return (found_first);
}

void	remove_quotes_from_tokens(t_token *list)
{
	char	*tmp;

	while (list)
	{
		tmp = list->value;
		list->value = remove_first_value_quotes(list->value);
		free(tmp);
		list = list->next;
	}
}
