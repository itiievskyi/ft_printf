/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:54:28 by itiievsk          #+#    #+#             */
/*   Updated: 2018/05/06 12:54:34 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_double_length(double num, t_params *par)
{
	uintmax_t		flint;

	flint = (uintmax_t)num;
	if (par->prec == -1 || (par->prec == -1 && par->hash))
		par->prec = 6;
	if (flint)
	{
		while (flint)
		{
			par->length++;
			flint /= 10;
		}
	}
	par->length += par->prec + 1;
}

static int	ft_putdouble(long long num, int *ret, t_params *par)
{
	char	ch;

	if (par->error == -2)
		return (0);
	if (num >= 10)
	{
		ft_putdouble(num / 10, ret, par);
		ch = (num % 10 + '0');
	}
	else
		ch = ('0' + num);
	ft_write(&ch, ret, 1);
	return (0);
}

static void	ft_putmantissa(double num, int *ret, t_params *par)
{
	char	ch;

	while (par->prec-- > 0)
	{
//		if ((double)(num * 10) - (double)((num)))
//		{
//			printf("\nnum = %.20f\n", num);
			ch = ((unsigned int)(num * 10)) + '0';
//			printf("%u\n", (unsigned int)(num * 10));
//			printf("\nch = %u\n", ch);
			num *= 10 + 0.0000000000001;
//			printf("num = %Lf\n", num);
			num -= (unsigned int)(num);
//			printf("\nnum = %.20f\n", num);
			ft_write(&ch, ret, 1);
//		}
//		else
//			ft_write("0", ret, 1);
	}
}

static void	ft_place_double(t_params *par, int *ret, int *a, double num)
{
	ft_put_sign(par, ret, a);
	par->apostrophe = 0;
	ft_putdouble((long long)num, ret, par);
	if (par->prec > 0 || (par->prec == 0 && par->hash))
		ft_write(".", ret, 1);
	if (par->prec)
		ft_putmantissa(num - (intmax_t)num, ret, par);
//	while (par->prec-- > 0 && åpar->zero)
//		ft_write("0", ret, 1);

}
/*
static void	ft_float_pad(t_params *par, int *ret, int *a)
{
	if (par->minus)
	{
		if (!par->plus)
			while ((*a)-- > 0)
				ft_check_pad(par, ret);
		else
			while ((*a)-- > 0)
				ft_check_pad(par, ret);
	}
	else
	{
		if (!par->plus)
			while ((*a)-- > 0)
				ft_check_pad(par, ret);
		else
			while ((*a)-- > 1)
				ft_check_pad(par, ret);
	}
}
*/
void		ft_printf_double(t_params *par, va_list arg, int *ret, int a)
{
	double	num;

	num = va_arg(arg, double);
	if (num < 0)
	{
		par->plus = '-';
		num *= -1;
	}
	get_double_length(num, par);
//	if (par->space && !par->plus)
//	{
//		ft_write(" ", ret, 1);
//		a--;
//	}
//	if (par->prec > (int)par->length)
//		a += par->width - par->prec;
//	else
	a = par->width - par->length;
//	printf("a = %zu\n", par->length);
	if (par->error != 1 && a > 0)
	{
		if (par->minus)
			ft_place_double(par, ret, &a, num);
		ft_int_pad(par, ret, &a);
		if (!(par->minus))
			ft_place_double(par, ret, &a, num);
	}
	else if (par->error != 1)
		ft_place_double(par, ret, &a, num);
}
