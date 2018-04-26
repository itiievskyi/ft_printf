/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 10:21:52 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/26 10:22:08 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_write(const char *c, int *ret)
{
	write(1, c, 1);
	*ret = *ret + 1;
}

void			ft_write_string(const char *s, int index, int *ret)
{
	while(s[index] != '\0')
		ft_write(&(s[index++]), ret);
}
