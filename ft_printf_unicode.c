/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 10:57:36 by itiievsk          #+#    #+#             */
/*   Updated: 2018/05/03 10:57:37 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_wchar(va_list arg, unsigned char wch[], int *len, int num)
{
	num = (va_arg(arg, int));
	if (num >= 0 && num <= 127)
		wch[0] = num;
	else if (num >= 128 && num <= 2047)
	{
		wch[0] = (192 + (num / 64));
		wch[1] = (128 + num % 64 % 64);
		*len = 2;
	}
	else if (num >= 2048 && num <= 65535)
	{
		wch[0] = (224 + (num / 4096));
		wch[1] = (128 + (num % 4096) / 64);
		wch[2] = (128 + (num % 4096) % 64);
		*len = 3;
	}
	else if (num >= 65536 && num <= 1114111)
	{
		wch[0] = (240 + (num / 524288));
		wch[1] = (128 + (num % 524288) / 4096);
		wch[2] = (128 + (num % 524288) % 4096 / 64);
		wch[3] = (128 + (num % 524288) % 4096 % 64);
		*len = 4;
	}
}

void		ft_printf_wchar(t_params *par, va_list arg, int *ret)
{
	int				a;
	int				len;
	unsigned char	wch[4];

	len = 1;
	ft_bzero(wch, 4);
	get_wchar(arg, wch, &len, 0);
	if (par->prec >= 0 && (par->prec < len))
		(wch)[par->prec] = '\0';
	if (par->error == 0 && (a = par->width - len) > 0)
	{
		if (par->minus)
			ft_write_wstring(wch, ret, len);
		while (a--)
		{
			if (par->zero)
				ft_write("0", ret, 1);
			else
				ft_write(" ", ret, 1);
		}
		if (!(par->minus))
			ft_write_wstring(wch, ret, len);
	}
	else if (par->error == 0)
		ft_write_wstring(wch, ret, len);
}
