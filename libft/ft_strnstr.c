/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:03:30 by retcheba          #+#    #+#             */
/*   Updated: 2022/04/04 14:20:22 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str;
	char	*to_find;
	size_t	i;
	size_t	j;

	str = (char *)big;
	to_find = (char *)little;
	i = 0;
	j = 0;
	if (*to_find == 0)
		return (str);
	while (*str && j++ < len)
	{
		if (*str == *to_find)
		{
			while (str[i] == to_find[i] && to_find[i] && (i + j) <= len)
				i++;
			if (to_find[i] == 0)
				return (str);
			else
				i = 0;
		}
		str++;
	}
	return (NULL);
}
