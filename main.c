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
	char *line2 = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	const wchar_t *line3 = L"\xd0\x9f\xd1\x80\xd0\xb8\xd0\xb2\xd0\xb5\xd1\x82\xe2\x82\xac";
	char *line4 = "yyyyyyyy";

	b = printf("\"aaaaa\"\n\"%0-000000020.04s\"\nAAA\n", line);
	printf("printf return = %d\n", b);
	printf("\n");
	b = ft_printf("\"aaaaa\"\n\"%0-000000020.04s\"\nAAA\n", line);
	printf("ft_printf return = %d\n", b);


	printf("\n");
	b = printf("%s %S %s\n", line2, line3, line4);
	printf("printf return = %d\n", b);
	write(1, "\xd0\x9f\xd1\x80\xd0\xb8\xd0\xb2\xd0\xb5\xd1\x82\xe2\x82\xac\n", 16);
//	printf("\n");
//	b = ft_printf("%s %S %s\n", line2, line3, line4);
//	printf("ft_printf return = %d\n", b);
	const wchar_t ch = L'猫';
	int iw = (int)ch;
	printf("%d\n", iw);
	write(1, "\u732b", 3);

//	system("leaks a.out");
}
