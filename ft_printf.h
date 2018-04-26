/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:00:21 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/24 15:00:23 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int					ft_printf(const char *format, ...);
void				ft_write(const char *c, int *ret);
void				ft_write_string(const char *s, int index, int *ret);
char				*ft_strchr(const char *s, int c);
void				ft_printf_strings(va_list arg, const char *fmt, int *ret);

typedef struct		s_params
{
	const char		*str;
	size_t			length;
	char			convert;
	size_t			width;
	size_t			index;
	void			*data;
	char			*mod;
	int				precision;
	int				hash;
	int				zero;
	int				space;
	int				minus;
	int				plus;
	int				apostrophe;
}					t_params;

t_params			*ft_get_param(const char *fmt, va_list arg);

#endif
