/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:27:25 by risattou          #+#    #+#             */
/*   Updated: 2024/11/28 16:31:05 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int	zero;
	int	dash;
	int	number;
	int	full_stop;
	int	plus;
	int	space;
	int	hash;

}		t_flag;

int		ft_printf(const char *str, ...);
int		ft_choose(const char **str, va_list *args, t_flag *flag);
int		ft_printstring(char *str, t_flag *flag);
int		ft_printnumber(unsigned int nbr, char *base, t_flag *flag);
int		ft_printptr(size_t nbr, char *base, t_flag *flag);
int		ft_printnegative(int nbr, t_flag *flag);
int		ft_putchar(char c, t_flag *flag);
int		ft_countnbr_base(unsigned int nbr, int len, t_flag *flag);
int		ft_countnbr(long nbr);
int		ft_hash(char *base);
int		ft_zero(t_flag *flag, int len, char *base);
void	ft_helper(t_flag *flag, int *count, int len, char *base);

#endif
