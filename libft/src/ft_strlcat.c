/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:41:37 by retcheba          #+#    #+#             */
/*   Updated: 2022/04/04 21:04:28 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	i;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (!size)
		return (lsrc);
	if (size < ldst)
		return (size + lsrc);
	i = 0;
	while (src[i] && (ldst + i) < (size - 1))
	{
		dst[i + ldst] = src[i];
		i++;
	}
	dst[i + ldst] = '\0';
	return (ldst + lsrc);
}
