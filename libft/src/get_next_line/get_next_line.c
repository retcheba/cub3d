/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:10:17 by retcheba          #+#    #+#             */
/*   Updated: 2022/07/26 21:40:41 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	get_next_line_4(char **buff, char **save)
{
	if (*save && **save == 0)
	{
		free(*save);
		*save = NULL;
	}
	free(*buff);
}

static void	get_next_line_3(char **str_final, char **buff, char **save)
{
	if (is_line_break(*buff))
		*save = ft_save(*buff);
	if (**buff)
		*str_final = ft_gnl_strjoin(*str_final, *buff);
}

static void	get_next_line_2(int *ret, char **str_final, char **save)
{
	if (*save && **save != 0)
	{
		*str_final = ft_gnl_strjoin(*str_final, *save);
		free(*save);
		*save = NULL;
		if (is_line_break(*str_final))
			*save = ft_save(*str_final);
	}
	*ret = 1;
}

char	*get_next_line(int fd)
{
	char			*str_final;
	char			*buff;
	static char		*save;
	int				ret;

	buff = malloc(sizeof(char) * (42 + 1));
	if ((!buff) || (fd < 0)
		|| (read(fd, buff, 0) == -1))
		return (free(buff), NULL);
	*buff = 0;
	str_final = malloc(sizeof(char) * 1);
	if (!str_final)
		return (free(buff), free(str_final), NULL);
	*str_final = 0;
	get_next_line_2(&ret, &str_final, &save);
	while (ret && !(is_line_break(str_final)))
	{
		ret = read(fd, buff, 42);
		buff[ret] = 0;
		get_next_line_3(&str_final, &buff, &save);
	}
	get_next_line_4(&buff, &save);
	if (*str_final == 0)
		return (free(str_final), NULL);
	return (str_final);
}
