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

static void	ft_read_arg(t_params *par, va_list arg, int i, int length)
{
	while (!ft_strchr("diouxXDOUeEfFgGaAcCsSPn", (par->str)[length]))
		length++;
	par->convert = (par->str)[length];
	while (i < length)
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

	}

}

t_params	*ft_get_param(const char *fmt, va_list arg)
{
	t_params	*par;

	if((par = (t_params*)malloc(sizeof(t_params))) == NULL)
			return (NULL);
	par->str = fmt;
	par->length = 0;
	par->width = 0;
//	par->index = 0;
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
	ft_read_arg(par, arg, 0, 0);
	return (par);
}
