/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:16:12 by retcheba          #+#    #+#             */
/*   Updated: 2022/04/16 23:34:16 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_hexa(char *hexa)
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
	hexa[10] = 'A';
	hexa[11] = 'B';
	hexa[12] = 'C';
	hexa[13] = 'D';
	hexa[14] = 'E';
	hexa[15] = 'F';
}

void	ft_puthexa_maj(unsigned int nb, int *len)
{
	char	hexa[16];

	init_hexa(hexa);
	if (nb >= 16)
		ft_puthexa_maj((nb / 16), len);
	*len += write (1, &hexa[nb % 16], 1);
}
