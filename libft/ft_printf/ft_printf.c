/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:02:01 by retcheba          #+#    #+#             */
/*   Updated: 2022/04/17 20:36:34 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	t1(char c, va_list yoyo, int *len)
{
	int	test;

	test = 0;
	if (c == 'c')
	{
		*len += ft_putchar(va_arg(yoyo, int));
		test++;
	}
	if (c == 's')
	{
		*len += ft_putstr(va_arg(yoyo, unsigned char *));
		test++;
	}
	if (c == 'p')
	{
		ft_putptr(va_arg(yoyo, unsigned long long), len);
		test++;
	}
	if (c == 'd')
	{
		ft_putnbr(va_arg(yoyo, int), len);
		test++;
	}
	return (test);
}

static int	t2(char c, va_list yoyo, int *len)
{
	int	test;

	test = 0;
	if (c == 'i')
	{
		ft_putnbr(va_arg(yoyo, int), len);
		test++;
	}
	if (c == 'u')
	{
		ft_putnbr_pos(va_arg(yoyo, unsigned int), len);
		test++;
	}
	if (c == 'x')
	{
		ft_puthexa(va_arg(yoyo, unsigned int), len);
		test++;
	}
	if (c == 'X')
	{
		ft_puthexa_maj(va_arg(yoyo, unsigned int), len);
		test++;
	}
	return (test);
}

static int	t3(char c, int *len)
{
	int	test;

	test = 0;
	if (c == '%')
	{
		*len += write(1, "%", 1);
		test++;
	}
	return (test);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		l;
	va_list	y;

	i = 0;
	l = 0;
	va_start(y, s);
	if (!s)
	{
		l += write(1, "(null)", 6);
		return (l);
	}
	while (s[i])
	{
		if (s[i] == '%')
			if (t1(s[i + 1], y, &l) || t2(s[i + 1], y, &l) || t3(s[i + 1], &l))
				i += 2;
		if (s[i] != '%' && s[i])
		{
			l += write(1, &s[i], 1);
			i++;
		}
	}
	va_end(y);
	return (l);
}
