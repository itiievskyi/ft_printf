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

	long long ll = 1844674407370955161;

	b = printf("@main_ftprintf: %####0000 33..1d", 256);
	printf("\n");
	if ((printf("printf return = %d\n", b)) < 0)
		perror("printf");
	b = ft_printf("@main_ftprintf: %####0000 33..1d", 256);
	printf("\n");
	printf("ft_printf return = %d\n", b);

	b = printf("\"%+10d\"\n", 4242);
	b = printf("\"%+10.5d\"\n", 4242);
	b = printf("\"%10.5d\"\n", 4242);
	b = printf("\"%10d\"\n", 4242);
	b = printf("\"%-010.5d\"\n", 4242);
	b = printf("\"%-10.5d\"\n", 4242);
	b = printf("\"%-15.10d\"\n", 4242);
	b = printf("\"%+10d\"\n", -4242);
	b = printf("\"%10.5d\"\n", -4242);
	printf("\n");
	b = ft_printf("\"%+10d\"\n", 4242);
	b = ft_printf("\"%+10.5d\"\n", 4242);
	b = ft_printf("\"%10.5d\"\n", 4242);
	b = ft_printf("\"%10d\"\n", 4242);
	b = ft_printf("\"%-010.5d\"\n", 4242);	//+
	b = ft_printf("\"%-10.5d\"\n", 4242);	//+
	b = ft_printf("\"%-15.10d\"\n", 4242); 	//+
	b = ft_printf("\"%+10d\"\n", -4242);
	b = ft_printf("\"%10.5d\"\n", -4242);
	printf("\n");
	printf("\"% 0d\"\n", -42);
	ft_printf("\"% 0d\"\n", -42);
	printf("\"%-5+d\"\n", -42);
	ft_printf("\"%-5+d\"\n", -42);
	printf("\"{%05*d}\"\n", -15, -42);
	ft_printf("\"{%05*d}\"\n", -15, -42);
	printf("\"{%0-5d}\"\n", -15);
	ft_printf("\"{%0-5d}\"\n", -15);
	printf("\"%#010.5d\"\n", 4242);
	ft_printf("\"%#010.5d\"\n", 4242);
	printf("\"%010.5d\"\n", 4242);
	ft_printf("\"%010.5d\"\n", 4242);

	printf("\"{%05.*d}\"\n", -15, 42);
	ft_printf("\"{%05.*d}\"\n", -15, 42);
	printf("\"{%05d}\"\n", 15);
	ft_printf("\"{%05d}\"\n", 15);
	printf("\"@main_ftprintf: %####0000 33..1..#d\"\n", 15);
	ft_printf("\"@main_ftprintf: %####0000 33..1..#d\"\n", 15);
	printf("\"%0+5d\"\n", -42);
	ft_printf("\"%0+5d\"\n", -42);
	printf("\"%05d\"\n", -42);
	ft_printf("\"%05d\"\n", -42);
	printf("\"% 10.5d\"\n", 4242);
	ft_printf("\"% 10.5d\"\n", 4242);
	printf("\"@moulitest: %.d %.0d\"\n", 0, 0);
	ft_printf("\"@moulitest: %.d %.0d\"\n", 0, 0);
	printf("\"@moulitest: %5.d %5.0d\"\n", 0, 0);
	ft_printf("\"@moulitest: %5.d %5.0d\"\n", 0, 0);
	printf("\"%hd\"\n", 32768);
	ft_printf("\"%hd\"\n", 32768);
	printf("\"%hhd\"\n", -129);
	ft_printf("\"%hhd\"\n", -129);
	printf("\"%hhld\"\n", 128);
	ft_printf("\"%hhld\"\n", 128);
	ll = 0;

printf("##################= ERRORS #1 =##################\n\n");
	printf("\"{%015.1     ?y    34543}\"\n", 128);
	ft_printf("\"{%-15Z}\"\n", 128);

//	system("leaks a.out");


}
