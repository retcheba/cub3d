/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:23:11 by retcheba          #+#    #+#             */
/*   Updated: 2022/04/11 19:08:52 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (((unsigned char)s1[i] == (unsigned char)s2[i]) && i < (n - 1)
			&& s1[i] && s2[i])
			i++;
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	else
		return (0);
}
