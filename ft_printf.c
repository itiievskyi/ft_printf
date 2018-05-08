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
		ft_printf_string(par, arg, ret, 0);
	else if (par->convert == 'c' || par->convert == '%')
		ft_printf_char(par, arg, ret);
	else if (par->convert == 'C')
		ft_printf_wchar(par, arg, ret);
	else if (par->convert == 'S')
		ft_printf_wstr(par, arg, ret, 0);
	else if (par->convert == 'd' || par->convert == 'i' || par->convert == 'u')
		ft_printf_i(par, arg, ret, 0);
	else if (par->convert == 'x' || par->convert == 'X')
		ft_printf_hex(par, arg, ret, 0);
}

static void	ft_start_printf(va_list arg, const char *fmt, size_t i, int *ret)
{
	t_params	*par;

	while (fmt[i] != '\0')
	{
		par = NULL;
		if (fmt[i] != '%')
			ft_write(&fmt[i++], ret, 1);
		else if (fmt[i + 1] != '\0')
		{
			par = ft_get_struct(&fmt[++i]);
			ft_get_param(par, arg);
			ft_write_arg(par, arg, ret);
			i = i + par->ret_point;
		}
		else
			i++;
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
