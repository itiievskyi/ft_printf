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

int			ft_write(const char *c)
{
	static int	ret;

	write(1, c, 1);
	return(++ret);
}

int			ft_write_string(const char *s, int index)
{
	int	ret;

	ret = 0;
	while(s[index] != '\0')
		ret = ft_write(&(s[index++]));
	return (ret);
}
