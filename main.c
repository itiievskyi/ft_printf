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
	wchar_t *line3 = L"\u041f\u0440\u0438\u0432\u0435\u0442";
	wchar_t *line3_1 = L"\xd0\x9f\xd1\x80\xd0\xb8\xd0\xb2\xd0\xb5\xd1\x82";
	wchar_t *line3_2 = L"Привет";
	char *line4 = "yyyyyyyy";

	printf("##################= CHARS =##################\n\n");

	b = printf("\"a\"\n\"%0-000000020.04c\"\t\n", line[0]);
	b += printf("\"%04.01c\"\n", line[1]);
	printf("printf return = %d\n", b);
	ft_printf("% bsdfsfasfsfsfsfdsfsfsfasfas\n");
	ft_printf("%s", 0);
	printf("\n");
	b = ft_printf("\"a\"\n\"%0-000000020.04c\"\t\n", line[0]);
	b += printf("\"%04.01c\"\n", line[1]);
	printf("ft_printf return = %d\n", b);

	printf("##################= STRINGS =##################\n\n");

	b = printf("\"aaaaa\"\n\"%0-000000020.04s\"\t\tAAA\n", line);
	printf("printf return = %d\n", b);
	printf("\n");
	b = ft_printf("\"aaaaa\"\n\"%0-000000020.04s\"\t\tAAA\n", line);
	printf("ft_printf return = %d\n", b);

	printf("\n");
	ft_printf("%.0%");
	printf("\n");

	printf("##################= UNICODE #1 =##################\n\n");

	ft_printf("\"%20lc\"\n", line3[0]);

	b = ft_printf("\"%15.4S\"\n", L"我是一只猫。");
	printf("ft_printf return = %d\n", b);
	b = printf("\"%15.4S\"\n", L"我是一只猫。");
	if ((printf("printf return = %d\n", b)) < 0)
		perror("printf");

	printf("##################= INTEGERS #1 =##################\n\n");

	unsigned long long ll = 9223372;

	b = printf("%0 d", -42);
	printf("\n");
	if ((printf("printf return = %d\n", b)) < 0)
		perror("printf");
	b = ft_printf("%0 d", -42);
	printf("\n");
	printf("ft_printf return = %d\n", b);

	ll = 0;


//	system("leaks a.out");


}
