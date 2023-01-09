/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:38:51 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/08 20:38:53 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_strstr(char *str, char *to_find)
{
	int	i;

	if (str == NULL || to_find == NULL)
		return (0);
	i = 0;
	while (str[i] && to_find[i] && str[i] == to_find[i])
		i++;
	if (str[i] == '\0' && to_find[i] == '\0')
		return (1);
	return (0);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
