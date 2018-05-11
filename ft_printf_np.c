/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_np.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:54:28 by itiievsk          #+#    #+#             */
/*   Updated: 2018/05/06 12:54:34 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_n(t_params *par, va_list arg, int *ret, int a)
{
	int *s;
	a = 0;
	if (par->convert == 'n')
		s = va_arg(arg, int*);
		s = ret;


/*	if (par->mod == 'l' || par->mod == 'z')
		(s = va_arg(arg, long*)) = (long*)*ret;
	else if (par->convert == 'd' && par->mod == '2')
		s = va_arg(arg, long long);
	else if (par->convert == 'd' && par->mod == 'j')
		s = va_arg(arg, intmax_t);
	else if (par->convert == 'd' && par->mod == 'h')
		s = (short)va_arg(arg, int);
	else if (par->convert == 'd' && par->mod == '1')
		s = (signed char)va_arg(arg, int);
	if (par->convert == 'n')
		((int*)s = va_arg(arg, int*)) = *ret;
*/
}
