/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:57:56 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/24 14:57:58 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int b = 0;
	char *line = "bbbbb";

	b = printf("\"aaaaa\"\n\"%.s\"\nAAA\n", line);
	printf("printf return = %d\n", b);
	printf("\n");
	b = ft_printf("\"aaaaa\"\n\"%.s\"\nAAA\n", line);
	printf("ft_printf return = %d\n", b);

//	system("leaks a.out");
}
