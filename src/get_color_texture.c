/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:52:14 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/23 20:12:50 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	get_y_texture(int y1, float len1, int len2)
{
	int	y2;

	y2 = len2 * y1 / (int)len1;
	return (y2);
}

int	get_x_texture(t_game *game, int i, int len2)
{
	float	x1;
	int		len1;
	int		x2;

	x1 = 0.0;
	len1 = game->cell_size;
	if (game->data_rays[i][1] == NORTH || game->data_rays[i][1] == SOUTH)
	{
		x1 = game->data_rays[i][2] / game->cell_size;
		x1 = (x1 - (int)x1) * game->cell_size;
	}
	else if (game->data_rays[i][1] == WEST || game->data_rays[i][1] == EAST)
	{
		x1 = game->data_rays[i][3] / game->cell_size;
		x1 = (x1 - (int)x1) * game->cell_size;
	}
	x2 = len2 * x1 / len1;
	return (x2);
}

int	get_color_texture(t_img_data *data, int x, int y)
{
	char	*dst;
	int		color;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}
