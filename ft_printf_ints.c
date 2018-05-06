/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ints.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:54:28 by itiievsk          #+#    #+#             */
/*   Updated: 2018/05/06 12:54:34 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_int_length(intmax_t num, t_params *par)
{
	if (num < 0)
	{
		par->length = 1;
		par->plus = -1;
	}
	while (num)
	{
		par->length++;
		num /= 10;
	}
}

static void	ft_putnum(intmax_t num, int *ret)
{
	char	ch;

	if (num < 0)
		num = num * -1;
	if (num >= 10)
	{
		ft_putnum(num / 10, ret);
		ch = (num % 10 + '0');
	}
	else
		ch = ('0' + num);
	ft_write(&ch, ret, 1);
}

void		ft_printf_i(t_params *par, va_list arg, int *ret, int a)
{
	intmax_t	num;

	num = va_arg(arg, intmax_t);
	get_int_length(num, par);
	ft_put_sign(par, ret);
	if (par->space)
		ft_write(" ", ret, 1);
	if (par->error == 0 && (a = par->width - par->length) > 0)
	{
		if (par->minus)
			ft_putnum(num, ret);
		while (a--)
			ft_check_pad(par, ret);
		if (!(par->minus))
			ft_putnum(num, ret);
	}
	else if (par->error == 0)
		ft_putnum(num, ret);
}
