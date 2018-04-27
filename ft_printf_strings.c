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
	int	a;

	par->data = strdup(va_arg(arg, char*));
	if (par->precision >= 0 && (par->precision < (int)ft_strlen(par->data)))
		(par->data)[par->precision] = '\0';
	printf("%d\n", par->precision);
	if ((a = par->width - (int)ft_strlen(par->data)) > 0)
	{
		if (par->minus)
			ft_write_string(par->data, 0, ret);
		while (a--)
		{
			if(par->zero)
				ft_write("0", ret);
			else
				ft_write(" ", ret);
		}
		if (!(par->minus))
			ft_write_string(par->data, 0, ret);
	}
	else
		ft_write_string(par->data, 0, ret);
}
