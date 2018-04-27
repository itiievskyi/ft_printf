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

static void	ft_write_arg(t_params *par, va_list arg, int *ret)
{
	if (par->convert == 's')
		ft_printf_string(par, arg, ret);
}

static void	ft_start_printf(va_list arg, const char *fmt, size_t i, int *ret)
{
	t_params	*par;

	while (fmt[i] != '\0')
	{
		par = NULL;
		if (fmt[i] != '%')
			ft_write(&fmt[i++], ret);
		else
		{
			par = ft_get_struct(&fmt[++i]);
			ft_get_param(par, arg);
			ft_write_arg(par, arg, ret);
			i = i + par->ret_point;
		}
		free(par);
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
