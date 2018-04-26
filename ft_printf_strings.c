/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:38:22 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/26 12:38:25 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_strings(va_list arg, const char *fmt, int *ret)
{
	int	i;

	i = 0;
	if (fmt[i] == 's')
		ft_write_string(va_arg(arg, char*), 0, ret);
}
