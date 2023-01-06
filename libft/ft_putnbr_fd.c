/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:59:38 by retcheba          #+#    #+#             */
/*   Updated: 2022/04/12 23:27:12 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	write_positive(long int nb, int fd)
{
	int		i;
	char	temp;
	char	tab[12];

	i = 0;
	while (nb > 0)
	{
		tab[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		temp = tab[i];
		write(fd, &temp, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = n;
	if (nb == 0)
		write(fd, "0", 1);
	if (nb < 0)
	{
		nb *= -1;
		write(fd, "-", 1);
	}
	if (nb > 0)
		write_positive(nb, fd);
}
