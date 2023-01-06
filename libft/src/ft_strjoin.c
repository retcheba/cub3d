/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:51:50 by retcheba          #+#    #+#             */
/*   Updated: 2022/04/11 18:40:57 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	l_s1;
	size_t	l_s2;
	size_t	i;

	if (!s1)
		return (NULL);
	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (l_s1 + l_s2 + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < l_s1)
	{
		str[i] = s1[i];
		i++;
	}
	while ((i - l_s1) < l_s2)
	{
		str[i] = s2[(i - l_s1)];
		i++;
	}
	str[i] = '\0';
	return (str);
}
