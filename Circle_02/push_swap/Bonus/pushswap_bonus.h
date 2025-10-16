/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:47:01 by risattou          #+#    #+#             */
/*   Updated: 2025/01/28 09:49:16 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H

# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				nb;
	int				index;
	struct s_list	*next;
}					t_list;

int					ft_check_rule(t_list **stack_a, t_list **stack_b,
						char *str);
int					ft_strcmp(char *s1, char *s2);
int					ft_error_r(char **str);
int					ft_error_node(t_list *new_node);
void				ft_putstr_fd(char *str, int fd);
int					ft_read_output(t_list **stack_a, t_list **stack_b);
void				rotate_a(t_list **stack_a);
void				rotate_b(t_list **stack_b);
void				swap_a(t_list **stack_a);
void				push_b(t_list **stack_b, t_list **stack_a);
void				push_a(t_list **stack_a, t_list **stack_b);
void				swap_b(t_list **stack_b);
void				reverse_rotate_a(t_list **stack_a);
void				reverse_rotate_b(t_list **stack_b);
void				rotate_a_b(t_list **stack_b, t_list **stack_a);
void				swap_a_b(t_list **stack_b, t_list **stack_a);
void				reverse_rotate_a_b(t_list **stack_b, t_list **stack_a);

int					ft_lstadd_back(t_list **lst, t_list *new_node);
void				ft_lstadd_front(t_list **lst, t_list *new_node);
t_list				*ft_lstnew(int content);
void				ft_lstclear(t_list **lst);
void				ft_lstindex(t_list **lst);
int					ft_lstsize(t_list *lst);

void				ft_sortlist(t_list **stack_a);
int					ft_is_sorted(t_list **stack_a);

int					ft_atoi(const char *str);
int					ft_split(char const *str, char c, t_list **lst);

int					ft_error(void);
int					ft_atoi_check(const char *str);
int					ft_split_check(char const *str, char c);
#endif