bool wildcard_match(const char *pattern, const char *filename)
{
	int	f;
	int	p;
	int	last_astric;
	int	match;

	f = 0;
	p = 0;
	last_astric = -1;
	match = 0;
	while (filename[f])
	{
		if (pattern[p] && pattern[p] == filename[f])
		{
			p++;
			f++;
		}
		else if (pattern[p] == '*')
		{
			last_astric = p++;
			match = f;
		}
		else if (last_astric != -1)
		{
			p = last_astric + 1;
			f = ++match;
		}
		else
			return  false;	
	}
	while (pattern[p] == '*')
		p++;
	return (pattern[p] == '\0');
}

typedef struct dirent t_dir_entry;

void	find_files(t_token *list, t_token **expanded_list, int *error)
{
	t_dir_entry	*entry;
	DIR			*directory;
	bool		flag;

	*error = 0;
	flag = 0;
	directory = opendir(".");
	if (!directory)
		return ;
	//in_case there is a allocation error we set error to 2
	entry = readdir(directory);
	while (entry)
	{
		if (entry->d_name[0] == '.' && list->value[0] != '.')
		{
			entry = readdir(directory);
			continue;
		}
		if (wildcard_match(list->value, entry->d_name))
		{
			if (!flag)
			{
				add_token(expanded_list, new_token(list->type, ft_strdup(entry->d_name)));
				flag = true;
			}
			else
			{
				add_token(expanded_list, new_token(AMBIGUOUS, ft_strdup(entry->d_name)));
				*error = 1;
			}
		}
		entry = readdir(directory);
	}

	closedir(directory);
}

void	ft_lstfree(t_list *list)
{
	t_list *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->content);
		free(tmp);
	}
}


t_token	*ft_wildcard(t_token *list)
{
	t_token		*expanded_list;
	t_token		*freee;
	int			err;

	freee = list;
	expanded_list = NULL;
	while (list)
	{
		if (!ft_strchr(list->value, '*'))
			add_token(&expanded_list, new_token(list->type, ft_strdup(list->value)));
		else
		{
			find_files(list, &expanded_list, &err);
			if (!err)
				add_token(&expanded_list, new_token(list->type, ft_strdup(list->value)));
		}
		list = list->next;
	}
	free_list(freee);
	return (expanded_list);
}


t_full_cmd	*full_wildcard(t_full_cmd *cmd)
{
	t_full_cmd	*expanded;

	expanded = cmd;
	expanded->cmd = NULL;
	expanded->red_in = ft_wildcard(cmd->red_in);
	expanded->red_out = ft_wildcard(cmd->red_out);
	expanded->args = ft_wildcard(cmd->args);
	if ((cmd->red_in && !expanded->red_in)
		|| (cmd->red_out && !expanded->red_out)
		|| (cmd->args && !expanded->args))
		return (ft_print_error(0), NULL);
	return (expanded);
}