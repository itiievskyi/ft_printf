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

void		ft_printf_string(t_params *par, va_list arg, int *ret)
{
	par->data = strdup(va_arg(arg, char*));
	if (par->precision >= 0 && (par->precision < (int)ft_strlen(par->data)))
	{
		(par->data)[par->precision] = '\0';
	}
	ft_write_string(par->data, 0, ret);
}