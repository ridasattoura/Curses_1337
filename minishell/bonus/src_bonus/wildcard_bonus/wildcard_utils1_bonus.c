/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 05:42:46 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/20 18:17:18 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	core_find(t_token *list, t_dir_entry *entry, t_expand_info *info)
{
	t_token	*new;

	if (wildcard_match(list->value, entry->d_name))
	{
		new = new_token(AMBIGUOUS, ft_strdup(entry->d_name));
		add_token(info->expanded_list, new);
		if (!info->found_first)
		{
			info->first_added = new;
			info->found_first = true;
		}
	}
}

bool	find_files(t_token *list, t_token **expanded_list)
{
	t_dir_entry		*entry;
	DIR				*directory;
	t_expand_info	info;

	info.expanded_list = expanded_list;
	info.first_added = NULL;
	info.found_first = false;
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
		core_find(list, entry, &info);
		entry = readdir(directory);
	}
	closedir(directory);
	if (info.found_first && info.first_added && info.first_added->next == NULL)
		info.first_added->type = list->type;
	return (info.found_first);
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

void	search_and_add(bool *found, t_token **expanded_list, t_token *list)
{
	*found = find_files(list, expanded_list);
	if (!*found)
		add_token(expanded_list, new_token(list->type,
				ft_strdup(list->value)));
}
