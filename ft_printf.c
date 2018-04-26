/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:54:36 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/24 14:54:48 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_start_printf(va_list arg, const char *fmt, int i, int ret)
{
	while (fmt[i] != '\0')
	{
		if (fmt[i] != '%')
			ret = ft_write(&fmt[i++]);
		else
		{
			if (fmt[++i] == 's')
				ret = ft_write_string(va_arg(arg, char*), 0);
			i++;
		}
	}
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list	arg;
	int		ret;

	va_start(arg, format);
	ret = ft_start_printf(arg, format, 0, 0);
	va_end(arg);
	return (ret);

}
