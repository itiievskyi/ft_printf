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
# include <strings.h>

int				ft_atoi(const char *str);
int				ft_printf(const char *format, ...);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *src);

typedef struct	s_params
{
	const char	*str;
	size_t		length;
	char		convert;
	int			width;
	size_t		index;
	size_t		ret_point;
	char		*data;
	char		mod;
	int			prec;
	int			hash;
	int			zero;
	int			space;
	int			minus;
	int			plus;
	int			apostrophe;
	int			error;
}				t_params;

t_params		*ft_get_struct(const char *fmt);
void			ft_get_param(t_params *par, va_list arg);
void			ft_write(const char *c, int *ret, int size);
void			ft_write_string(const char *s, int index, int *ret);
void			ft_printf_char(t_params *par, va_list arg, int *ret);
void			ft_printf_string(t_params *par, va_list arg, int *ret, int a);

#endif
