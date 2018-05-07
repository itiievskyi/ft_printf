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

static void	get_int_length(uintmax_t num, t_params *par)
{
	if (par->plus)
	{
		par->space = 0;
		par->length = 1;
	}
	if (num == 0)
		par->length = 1;
	else
	{
		while (num)
		{
			par->length++;
			num /= 10;
		}
	}
}

static void	ft_putnum(uintmax_t num, int *ret, t_params *par)
{
	char	ch;

	if (num >= 10)
	{
		ft_putnum(num / 10, ret, par);
		ch = (num % 10 + '0');
	}
	else
	{
		ft_put_sign(par, ret);
		ch = ('0' + num);
	}
	ft_write(&ch, ret, 1);
}

uintmax_t	ft_get_num(t_params *par, uintmax_t n, intmax_t s, va_list arg)
{
	if (par->convert == 'd' && (par->mod == 'l' || par->mod == 'z'))
		s = va_arg(arg, long);
	else if (par->convert == 'd' && par->mod == '2')
		s = va_arg(arg, long long);
	else if (par->convert == 'd' && par->mod == 'j')
		s = va_arg(arg, intmax_t);
	else if (par->convert == 'd')
		s = va_arg(arg, int);
	else if (par->convert == 'u' && (par->mod == 'l' || par->mod == 'z'))
		n = va_arg(arg, unsigned long);
	else if (par->convert == 'u' && par->mod == '2')
		n = va_arg(arg, unsigned long long);
	else if (par->convert == 'u' && par->mod == 'j')
		n = va_arg(arg, uintmax_t);
	else if (par->convert == 'u')
		n = va_arg(arg, unsigned int);
	if (par->convert == 'd' && s < 0)
	{
		par->plus = '-';
		return (n = (uintmax_t)(s * -1));
	}
	else if (par->convert == 'd')
		return (n = (uintmax_t)s);
	else
		return (n);
}

void		ft_printf_i(t_params *par, va_list arg, int *ret, int a)
{
	uintmax_t	num;

	num = ft_get_num(par, 0, 0, arg);
	get_int_length(num, par);
	if (par->space && !par->plus)
		ft_write(" ", ret, 1);
	if (par->error == 0 && (a = par->width - par->length) > 0)
	{
		if (par->minus)
			ft_putnum(num, ret, par);
		while (a--)
			ft_check_pad(par, ret);
		if (!(par->minus))
			ft_putnum(num, ret, par);
	}
	else if (par->error == 0)
		ft_putnum(num, ret, par);
}
