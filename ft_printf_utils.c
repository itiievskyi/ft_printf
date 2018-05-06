/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:43:48 by itiievsk          #+#    #+#             */
/*   Updated: 2018/05/03 17:43:50 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_check_pad(t_params *par, int *ret)
{
	if (par->zero)
		ft_write("0", ret, 1);
	else
		ft_write(" ", ret, 1);
}

void		ft_put_sign(t_params *par, int *ret)
{
	if (!par->space && par->plus != 0)
	{
		if (par->plus < 0)
			ft_write("-", ret, 1);
		else
			ft_write("+", ret, 1);
	}
}
