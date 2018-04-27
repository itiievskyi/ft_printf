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

static void	ft_get_flags(t_params *par, int i, int length)
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
}

static void	ft_get_width(t_params *par, va_list arg, int i)
{
	if (par->str[i] == '-' && par->str[i + 1] >= '1' && par->str[i + 1] <= '9')
		par->minus = ++i;
	if (par->str[i] >= '1' && par->str[i] <= '9')
	{
		while (par->str[i] >= '1' && par->str[i] <= '9')
			i++;
		par->width = ft_atoi(&par->str[par->index]);
	}
	else if (par->str[i] >= '*')
	{
		par->width = va_arg(arg, int);
		par->index += 1;
	}
	if (par->width < 0)
		par->width *= -1;
}

t_params	*ft_get_param(const char *fmt, va_list arg)
{
	t_params	*par;

	if((par = (t_params*)malloc(sizeof(t_params))) == NULL)
			return (NULL);
	par->str = fmt;
	par->length = 0;
	par->width = 0;
	par->convert = 0;
	par->data = 0;
	par->mod = 0;
	par->precision = 0;
	par->hash = 0;
	par->zero = 0;
	par->space = 0;
	par->minus = 0;
	par->plus = 0;
	par->apostrophe = 0;
	ft_get_flags(par, 0, 0);
	ft_get_width(par, arg, 0);
	return (par);
}
