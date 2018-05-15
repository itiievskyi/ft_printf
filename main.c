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
//#include "locale.h"

int main()
{
//	setlocale(LC_ALL, "en_US.UTF-8");
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

printf("##################= ERRORS #1 =##################\n\n");
	printf("\"{%015.1     ?y    34543}\"\n", 128);
	ft_printf("\"{%-15Z}\"\n", 128);

printf("##################= HEX #1 =##################\n\n");
	printf("\"%5.2x\"\n", 5427);
	ft_printf("\"%5.2x\"\n", 5427);
	printf("\"%# 08x\"\n", 5427);
	ft_printf("\"%# 08x\"\n", 5427);
	printf("\"% 08x\"\n", 5427);
	ft_printf("\"% 08x\"\n", 5427);
	printf("\"%#- 08x\"\n", 5427);
	ft_printf("\"%#- 08x\"\n", 5427);
	printf("\"%# 36x\"\n", 1231333);
	ft_printf("\"%# 36x\"\n", 1231333);
	printf("\"%#+36x\"\n", 3434);
	ft_printf("\"%#+36x\"\n", 3434);
	printf("\"%# 3.10X\"\n", 1231333);
	ft_printf("\"%# 3.10X\"\n", 1231333);
	printf("\"% X\"\n", 1231333);
	ft_printf("\"% X\"\n", 1231333);
	printf("\"%#x\"\n", 0);
	ft_printf("\"%#x\"\n", 0);
	printf("\"%#08x\"\n", 42);
	ft_printf("\"%#08x\"\n", 42);
	printf("\"@moulitest: %#.x %#.0x\"\n", 0, 0);
	ft_printf("\"@moulitest: %#.x %#.0x\"\n", 0, 0);

printf("##################= HEX #2 =##################\n\n");

	printf("\"%.2hX\"\n", -1271782053);
	ft_printf("\"%.2hX\"\n", -1271782053);

printf("##################= OCTAL #1 =##################\n\n");

	printf("\"%#08o\"\n", 88);
	ft_printf("\"%#08o\"\n", 88);

	printf("\"%#o\"\n", 42);
	ft_printf("\"%#o\"\n", 42);
	printf("\"%#1o\"\n", 42);
	ft_printf("\"%#1o\"\n", 42);
	printf("\"%#4o\"\n", 42);
	ft_printf("\"%#4o\"\n", 42);
	printf("\"%04o\"\n", 42);
	ft_printf("\"%04o\"\n", 42);

	printf("\"%#04.10o\"\n", 1);
	ft_printf("\"%#04.10o\"\n", 1);
	printf("\"%#0 4.10o\"\n", 42);
	ft_printf("\"%#0 4.10o\"\n", 42);
	printf("\"%#0-4.10o\"\n", 65);
	ft_printf("\"%#0-4.10o\"\n", 65);

	printf("\"%-18.10o\"\n", 34);
	ft_printf("\"%-18.10o\"\n", 34);
	printf("\"%-18.o\"\n", 111);
	ft_printf("\"%-18.o\"\n", 111);

	printf("\"@moulitest: %o\"\n", 0);
	ft_printf("\"@moulitest: %o\"\n", 0);

	printf("\"@moulitest: %.0o\"\n", 0);
	ft_printf("\"@moulitest: %.0o\"\n", 0);

	printf("\"@moulitest: %#o\"\n", 0);
	ft_printf("\"@moulitest: %#o\"\n", 0);

	printf("\"@moulitest: %.o\"\n", 0);
	ft_printf("\"@moulitest: %.o\"\n", 0);

	printf("\"@moulitest: %#.0o\"\n", 0);
	ft_printf("\"@moulitest: %#.0o\"\n", 0);

printf("##################= N #1 =##################\n\n");

	const long count;
	printf("this%n is a test\n", &count);
	printf("%d\n", count);
	ft_printf("this%n is a test\n", &count);
	ft_printf("%d\n", count);
	printf("Kashim a 1001 histoires à raconter\n%n", &count);
	printf("%d\n", count);
	ft_printf("Kashim a 1001 histoires à raconter\n%n", &count);
	ft_printf("%d\n", count);

printf("##################= POINTERS #1 =##################\n\n");

	size_t Gb = 1024*1024;
	char *a1 = (char *)malloc(2 * Gb * sizeof(char));
	char *b1 = (char *)malloc(2 * Gb * sizeof(char));
	printf("use %%X: a=%X\n", a1);
	printf("use %%X: b=%X\n", b1);
	printf("use %%p: a=%p\n", a1);
	printf("use %%p: b=%p\n", b1);
	ft_printf("use %%X: a=%X\n", a1);
	ft_printf("use %%X: b=%X\n", b1);
	ft_printf("use %%p: a=%p\n", a1);
	ft_printf("use %%p: b=%p\n", b1);
	printf("\n");

	printf("%.0p, %.p\n", 0, 0);
	ft_printf("%.0p, %.p\n", 0, 0);

	printf("{%05p}\n", 0);
	ft_printf("{%05p}\n", 0);

	printf("x = {%05lx}\n", 0);
	ft_printf("x = {%05lx}\n", 0);

	printf("{%3*p}\n", 10, 0);
	ft_printf("{%3*p}\n", 10, 0);

	printf("\"%.p, %.0p\"\n", 0, 0);
	ft_printf("\"%.p, %.0p\"\n", 0, 0);

	printf("\"%2.9p\"\n", 1234);
	ft_printf("\"%2.9p\"\n", 1234);

	printf("\"{%-15p}\"\n", 0);
	ft_printf("\"{%-15p}\"\n", 0);
//	ft_printf("\"%hd\t%n\"\n", 32768);

printf("##################= ERRORS #2 =##################\n\n");

	printf("\"{%10RABC}\"\n");
	ft_printf("\"{%10RABC}\"\n");
	printf("\"{%10R}\"\n");
	ft_printf("\"{%10R}\"\n");
	printf("\"{%10}\"\n");
	ft_printf("\"{%10}\"\n");
	printf("% Zoooo\n");
	ft_printf("% Zoooo\n");

printf("##################= STRINGS #2 =##################\n\n");

	printf("\"{%05.s}\"\n", 0);
	ft_printf("\"{%05.s}\"\n", 0);
	printf("\"{%5.s}\"\n", 0);
	ft_printf("\"{%5.s}\"\n", 0);
	printf("\"{%.s}\"\n", 0);
	ft_printf("\"{%.s}\"\n", 0);
	printf("\"{%s}\"\n", 0);
	ft_printf("\"{%s}\"\n", 0);
	printf("\"{%*s}\"\n", 5, 0);
	ft_printf("\"{%*s}\"\n", 5, 0);
	printf("\"{%5s}\"\n", 0);
	ft_printf("\"{%5s}\"\n", 0);

printf("##################= UNICODE #2 =##################\n\n");

	b = printf("\"%.8S\"\n", L"我是一只猫。");
	printf("printf return = %d\n", b);
	b = ft_printf("\"%.8S\"\n", L"我是一只猫。");
	printf("ft_printf return = %d\n", b);

printf("##################= UNICODE #3 =##################\n\n");

	b = printf("\"%.1C\"\n", L'我');
	printf("printf return = %d\n", b);
	b = ft_printf("\"%.1C\"\n", L'我');
	printf("ft_printf return = %d\n", b);
	b = printf("\"%.C\"\n", L'我');
	printf("printf return = %d\n", b);
	b = ft_printf("\"%.C\"\n", L'我');
	printf("ft_printf return = %d\n", b);
	printf("\"%#.1C\"\n", L'ø');
	ft_printf("\"%#.1C\"\n", L'ø');

printf("##################= APOSTROPHE =##################\n\n");

	printf("\"%' 0d\"\n", -420);
	ft_printf("\"%' 0d\"\n", -420);
	printf("\"%'-5+d\"\n", -42000000);
	ft_printf("\"%'-5+d\"\n", -42000000);
	printf("\"{%'05*d}\"\n", -15, -4200011);
	ft_printf("\"{%'05*d}\"\n", -15, -4200011);
	printf("\"{%'05*d}\"\n", -15, 0);
	ft_printf("\"{%'05*d}\"\n", -15, 0);
	printf("\"%'-zd\"\n", 34545535235353);
	ft_printf("\"%'-zd\"\n", 34545535235353);

printf("##################= FLOAT =##################\n\n");

	double f = 10;
	double ff = 3.3333333333333333333333333333;
	double fff = 3.3333333333333333333333333333;
	printf("\"{%f}\"\n", 1.42);
	ft_printf("\"{%f}\"\n", 1.42);
	printf("\n");
	printf("\"{%#f}{%#F}\"\n", 10.0, 10.0);
	ft_printf("\"{%#f}{%#F}\"\n", 10.0, 10.0);

	printf("\"{%.0f}{%.0F}\"\n", f, f);
	ft_printf("\"{%.0f}{%.0F}\"\n", f, f);

	printf("\"{%.f}{%.F}\"\n", f, f);
	ft_printf("\"{%.f}{%.F}\"\n", f, f);

	printf("\"{%#.0f}{%#.0F}\"\n", f, f);
	ft_printf("\"{%#.0f}{%#.0F}\"\n", f, f);

	printf("\"{%#.f}{%#.F}\"\n", f, f);
	ft_printf("\"{%#.f}{%#.F}\"\n", f, f);
	printf("\"{%0.f}{%#0.F}\"\n", f, f);
	ft_printf("\"{%0.f}{%#0.F}\"\n", f, f);
	printf("\n");
	printf("\"{%010f}{%#06F}\"\n", f, f);
	ft_printf("\"{%010f}{%#06F}\"\n", f, f);

	printf("\"{%#.f}{%#.F}\"\n", ff, ff);
	ft_printf("\"{%#.f}{%#.F}\"\n", ff, ff);
	printf("\"{%#f}{%#F}\"\n", ff, ff);
	ft_printf("\"{%#f}{%#F}\"\n", ff, ff);

	printf("\"{%.10f}{%.10F}\"\n", ff, ff);
	ft_printf("\"{%.10f}{%.10F}\"\n", ff, ff);

	printf("\"{%f}{%F}\"\n", 1.42, 1.42);
	ft_printf("\"{%f}{%F}\"\n", 1.42, 1.42);
	printf("\"{%f}{%F}\"\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
	ft_printf("\"{%f}{%F}\"\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
	printf("\"{%.10f}{%.10F}\"\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
	ft_printf("\"{%.10f}{%.10F}\"\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
	printf("\"{%.10f}{%.10F}\"\n", fff, fff);
	ft_printf("\"{%.10f}{%.10F}\"\n", fff, fff);
	printf("\"{% 10f}{%-10F}\"\n", fff, fff);
	ft_printf("\"{% 10f}{%-10F}\"\n", fff, fff);
	printf("\"{%f}{%F}\"\n", -1.42, -1.42);
	ft_printf("\"{%f}{%F}\"\n", -1.42, -1.42);
	printf("\"{%10f}{%15F}\"\n", -1.42, -1.42);
	ft_printf("\"{%10f}{%15F}\"\n", -1.42, -1.42);
	printf("\"{%+10f}{%-15F}\"\n", 1.42, 1.42);
	ft_printf("\"{%+10f}{%-15F}\"\n", 1.42, 1.42);
	printf("\n");
	printf("\"{%+10Lf}{%-15LF}\"\n", (long double)1.42, (long double)1.42);
	ft_printf("\"{%+10Lf}{%-15LF}\"\n", (long double)1.42, (long double)1.42);

printf("##################= UNICODE #4 =##################\n\n");

	printf("\"%.1C\"\n", L'ø');
	ft_printf("\"%.1C\"\n", L'ø');
	printf("\"%.1C\"\n", L'\x01\xc3\xb8');
	ft_printf("\"%.1C\"\n", L'\x01\xc3\xb8');

/*
printf("##################= SPEED #1 =##################\n\n");

	int i = 2147483647;
	long l = 2147483647;
	long long ll = 9223372036854775807;
	char c = 0;
	intmax_t im = 9223372036854775807;

	ft_printf("\n");
	ft_printf("%%\n");
	ft_printf("%d\n", 42);
	ft_printf("%d%d\n", 42, 41);
	ft_printf("%d%d%d\n", 42, 43, 44);
	ft_printf("%ld\n", l);
	ft_printf("%lld\n", ll);
	ft_printf("%x %X %p %20.15d\n", 505, 505, &ll, 54321);
	ft_printf("%-10d % d %+d %010d %hhd\n", 3, 3, 3, 1, c);
	ft_printf("%jd %zd %u %o %#08x\n", im, (size_t)i, i, 40, 42);
	ft_printf("%x %#X %S %s%s\n", 1000, 1000, L"ݗݜशব", "test", "test2");
	ft_printf("%s%s%s\n", "test", "test", "test");
	ft_printf("%C\n", 15000);

	printf("\n");
	printf("%%\n");
	printf("%d\n", 42);
	printf("%d%d\n", 42, 41);
	printf("%d%d%d\n", 42, 43, 44);
	printf("%ld\n", l);
	printf("%lld\n", ll);
	printf("%x %X %p %20.15d\n", 505, 505, &ll, 54321);
	printf("%-10d % d %+d %010d %hhd\n", 3, 3, 3, 1, c);
	printf("%jd %zd %u %o %#08x\n", im, (size_t)i, i, 40, 42);
	printf("%x %#X %S %s%s\n", 1000, 1000, L"ݗݜशব", "test", "test2");
	printf("%s%s%s\n", "test", "test", "test");
	printf("%C\n", 15000);
*/
//	system("leaks a.out");


}
