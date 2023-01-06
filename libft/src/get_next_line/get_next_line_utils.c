/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:13:46 by retcheba          #+#    #+#             */
/*   Updated: 2022/05/06 18:19:38 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	is_line_break(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_gnl_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	l_s1;
	size_t	l_s2;
	size_t	i;

	if (!s2)
		return (NULL);
	l_s1 = ft_gnl_strlen(s1);
	l_s2 = ft_gnl_strlen(s2);
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
		str[i] = s2[i - l_s1];
		i++;
	}
	str[i] = '\0';
	return (free(s1), str);
}

static void	ft_save_2(char *line, unsigned int *start, unsigned int *size)
{
	unsigned int	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	i++;
	*start = i;
	*size = 0;
	while (line[i])
	{
		i++;
		*size += 1;
	}
}

char	*ft_save(char *line)
{
	unsigned int	i;
	unsigned int	size;
	unsigned int	start;
	char			*str;

	if (!line)
		return (NULL);
	ft_save_2(line, &start, &size);
	if (size == 0)
		return (NULL);
	if (size >= ft_gnl_strlen(line))
		size = ft_gnl_strlen(line) - start;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = start + size;
	size = 0;
	while (start < i)
	{
		str[size++] = line[start];
		line[start++] = 0;
	}
	str[size] = 0;
	return (str);
}
