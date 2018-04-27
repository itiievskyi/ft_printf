/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:00:22 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/26 17:00:25 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_get_flags(t_params *par, size_t i, size_t length)
{
	while (!ft_strchr("diouxXDOUeEfFgGaAcCsSPn%%", (par->str)[length]))
		length++;
	par->convert = (par->str)[length];
	while (i < length && ft_strchr("#0 -+\'", (par->str)[i]))
	{
		if ((par->str)[i] == '#')
			par->hash = 1;
		if ((par->str)[i] == '0')
			par->zero = 1;
		if ((par->str)[i] == ' ')
			par->space = 1;
		if ((par->str)[i] == '-' &&
			(par->str)[i + 1] > '9' && (par->str)[i + 1] < '1')
			par->minus = 1;
		if ((par->str)[i] == '+')
			par->plus = 1;
		if ((par->str)[i] == '\'')
			par->apostrophe = 1;
		i++;
	}
	par->index = i;
	par->ret_point = par->ret_point + length + 1;
}

static void		ft_get_width(t_params *par, va_list arg, int i)
{
	if (par->str[i] == '-' && par->str[i + 1] >= '1' && par->str[i + 1] <= '9')
		par->minus = ++i;
	if (par->str[i] >= '1' && par->str[i] <= '9')
	{
		while (par->str[i] >= '1' && par->str[i] <= '9')
			i++;
		par->width = ft_atoi(&par->str[par->index]);
		par->index += i;
	}
	else if (par->str[i] == '*')
	{
		par->width = va_arg(arg, int);
		par->index += 1;
	}
	if (par->width < 0)
		par->width *= -1;
}

static void		ft_get_prec(t_params *par, va_list arg, int i)
{
	if (par->str[i] == '.')
	{
		i++;
		par->precision = 0;
		if (par->str[i] == '-' &&
			par->str[i + 1] >= '1' && par->str[i + 1] <= '9')
			par->minus = i++;
		if (par->str[i] >= '1' && par->str[i] <= '9')
		{
			while (par->str[i] >= '1' && par->str[i] <= '9')
				i++;
			par->precision = ft_atoi(&par->str[par->index + 1]);
			par->index += i + 1;
		}
		else if (par->str[i] == '*')
		{
			par->precision = va_arg(arg, int);
			par->index += i;
		}
	}
}

static void		ft_handle_conflicts(t_params *par)
{
	if (par->zero && par->minus)
		par->zero = 0;
	if (par->plus && par->space)
		par->space = 0;
}

void			ft_get_param(t_params *par, va_list arg)
{
	ft_get_flags(par, 0, 0);
	ft_get_width(par, arg, 0);
	ft_get_prec(par, arg, 0);
	if (ft_strchr("hlLjtzq", par->str[par->index]))
	{
		if (par->str[par->index] == 'h' && par->str[par->index + 1] == 'h')
		{
			par->mod = '1';
			par->index += 2;
		}
		else if (par->str[par->index] == 'l' && par->str[par->index + 1] == 'l')
		{
			par->mod = '2';
			par->index += 2;
		}
		else
		{
			par->mod = '2';
			par->index += 1;
		}
	}
	ft_handle_conflicts(par);
}
