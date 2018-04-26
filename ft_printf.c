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

static void	ft_start_printf(va_list arg, const char *fmt, int i, int *ret)
{
	t_params	*par;

	while (fmt[i] != '\0')
	{
		if (fmt[i] != '%')
			ft_write(&fmt[i++], ret);
		else
		{
			i++;
			par = ft_get_param(&fmt[i], arg);

			i++;
		}
	}
}

int			ft_printf(const char *format, ...)
{
	va_list	arg;
	int		ret;
	int		*p;

	ret = 0;
	p = &ret;
	va_start(arg, format);
	ft_start_printf(arg, format, 0, p);
	va_end(arg);
	return (ret);
}
/*
a = i;
while (ft_strchr("01234567890-+#.", fmt[i]) != NULL)
	i++;
if (ft_strchr("sScC", fmt[i]) != NULL)
	ft_printf_strings(arg, &fmt[a], ret);
	*/
