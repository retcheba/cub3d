/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:02:47 by retcheba          #+#    #+#             */
/*   Updated: 2022/04/16 21:27:30 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_hexa_ptr(char *hexa)
{
	hexa[0] = '0';
	hexa[1] = '1';
	hexa[2] = '2';
	hexa[3] = '3';
	hexa[4] = '4';
	hexa[5] = '5';
	hexa[6] = '6';
	hexa[7] = '7';
	hexa[8] = '8';
	hexa[9] = '9';
	hexa[10] = 'a';
	hexa[11] = 'b';
	hexa[12] = 'c';
	hexa[13] = 'd';
	hexa[14] = 'e';
	hexa[15] = 'f';
}

static void	ft_puthexa_ptr(unsigned long long nb, int *len)
{
	char	hexa[16];

	init_hexa_ptr(hexa);
	if (nb >= 16)
		ft_puthexa_ptr((nb / 16), len);
	*len += write (1, &hexa[nb % 16], 1);
}

void	ft_putptr(unsigned long long ptr, int *len)
{
	if (!ptr)
	{
		*len += write(1, "(nil)", 5);
		return ;
	}
	*len += write(1, "0x", 2);
	ft_puthexa_ptr(ptr, len);
}
