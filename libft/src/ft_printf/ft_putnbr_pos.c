/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:12:00 by retcheba          #+#    #+#             */
/*   Updated: 2022/04/16 16:39:16 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pos(unsigned int nb, int *len)
{
	char	temp;

	temp = 0;
	if (nb >= 10)
		ft_putnbr((nb / 10), len);
	temp = (nb % 10) + '0';
	*len += write (1, &temp, 1);
}
