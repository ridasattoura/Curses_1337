/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:26:47 by risattou          #+#    #+#             */
/*   Updated: 2025/01/22 11:13:13 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *str, unsigned int start, size_t len);
int		ft_strchr(const char *str, int c);
char	*ft_help(char **all);
size_t	ft_all(char **all, char *buff);
char	*ft_zero(char **all, char **buff);
char	*collect_line(int fd, char **all, char *buff);

#endif