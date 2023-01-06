/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:08:55 by retcheba          #+#    #+#             */
/*   Updated: 2022/04/16 22:03:10 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(unsigned char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		len += write(1, "(null)", 6);
		return (len);
	}
	while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}
