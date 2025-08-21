/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 05:07:42 by risattou          #+#    #+#             */
/*   Updated: 2025/03/19 23:04:33 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_files
{
	int	fdin;
	int	fdout;
	int	fd[2];
	int	index;
	int	count;
}		t_files;

typedef struct s_qouts
{
	int	coundd;
	int	counds;
	int	count;
	int	index;
}		t_qouts;

void	ft_free_cmnds(char **array, t_files files);
void	ft_close(t_files files, char **array, char **array1);
void	count_words(const char *str, t_qouts *qouts, char c);
int		skip_delimiters(const char *str, t_qouts *qouts, char c);
int		process_quotes(char **new1, char *str, int *i, int *index);
int		process_non_quotes(char **new1, char *str, int *i, int *index);
char	*ft_strdup_qouts(char *str, char c);
void	*ft_free_qouts(char **new1, int index);
int		ft_home(char **new1, char *str);
int		ft_count(char const *str, char c);
char	**ft_get_path(char **env);
char	**ft_split_qouts(char const *str, char c);
void	ft_free(char **array);
char	**ft_get_cmnds(char **av, int ac, char **path, int index);
t_files	ft_here_doc(char **av, int ac);
t_files	ft_open_files(char *file_in, char *file_out);
void	ft_child_process(t_files files, char **cmnds, char **env, char **av);
int		ft_parent_process(t_files files, int id);
#endif