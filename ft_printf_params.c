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

static void		ft_get_flags(t_params *par, size_t i, size_t len)
{
	while ((par->str)[len] != '\0' &&
		ft_strchr("0123456789# -+\'hlLjtzq.*", (par->str)[len]))
		len++;
	if (ft_strchr("diouxXDOUeEfFgGaAcCsSPn%%", (par->str)[len]))
		par->convert = (par->str)[len];
	if (par->convert == '\0')
		par->error = 1;
	while (par->error == 0 && (i < len && ft_strchr("#0 -+\'", (par->str)[i])))
	{
		if ((par->str)[i] == '#')
			par->hash = 1;
		if ((par->str)[i] == '0')
			par->zero = 1;
		if ((par->str)[i] == ' ')
			par->space = 1;
		if ((par->str)[i] == '-')
			par->minus = 1;
		if ((par->str)[i] == '+')
			par->plus = 1;
		if ((par->str)[i] == '\'')
			par->apostrophe = 1;
		i++;
	}
	par->index = i;
	par->ret_point = par->ret_point + len + 1 - ((int)par->error) / 1;
}

static void		ft_get_width(t_params *par, va_list arg, int i)
{
	i = par->index;
	if (par->str[par->index] >= '0' && par->str[par->index] <= '9')
	{
		while (par->str[par->index] >= '0' && par->str[par->index] <= '9')
			par->index += 1;
		par->width = ft_atoi(&par->str[i]);
	}
	else if (par->str[par->index] == '*')
	{
		par->width = va_arg(arg, int);
	}
	if (par->width < 0)
		par->width *= -1;
}

static void		ft_get_prec(t_params *par, va_list arg, int i)
{
	i = par->index;
	if (par->str[par->index] == '.')
	{
		par->index += 1;
		par->prec = 0;
		if (par->str[par->index] >= '0' && par->str[par->index] <= '9')
		{
			while (par->str[par->index] >= '0' && par->str[par->index] <= '9')
				par->index += 1;
			par->prec = ft_atoi(&par->str[i + 1]);
			par->index += 1;
		}
		else if (par->str[par->index] == '*')
		{
			par->prec = va_arg(arg, int);
			par->index += i;
		}
	}
	if (par->convert == 'c' || par->convert == '%')
		par->prec = -1;
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
