/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:00:07 by retcheba          #+#    #+#             */
/*   Updated: 2022/03/31 21:21:33 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = n;
	if (dest == src || n == 0)
		return (dest);
	else if (dest > src && dest <= (src + n))
	{
		dest += n;
		src += n;
		while (i > 0)
		{
			dest--;
			src--;
			*(unsigned char *)dest = *(unsigned char *)src;
			i--;
		}
	}
	else
		dest = ft_memcpy(dest, src, n);
	return (dest);
}
