/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:52:14 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/20 18:05:03 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	get_coordinates_texture(int c1, int len1, int len2)
{
	int	c2;

	c2 = len2 * c1 / len1;
	return (c2);
}

int	get_y_texture(int y1, float len1)
{
	int	y2;
	int	len2;

	len2 = 132;
	y2 = len2 * y1 / (int)len1;
	return (y2);
}

int	get_x_texture(t_game *game, int i)
{
	float	x_ray;
	int		len;
	int		p_len;
	int		x;

	x_ray = 0.0;
	len = game->cell_size;
	p_len = 132;
	if (game->lines_len[i][1] == NORTH || game->lines_len[i][1] == SOUTH)
	{
		x_ray = game->lines_len[i][2] / game->cell_size;
		x_ray = (x_ray - (int)x_ray) * game->cell_size;
	}
	else if (game->lines_len[i][1] == WEST || game->lines_len[i][1] == EAST)
	{
		x_ray = game->lines_len[i][3] / game->cell_size;
		x_ray = (x_ray - (int)x_ray) * game->cell_size;
	}
	x = p_len * x_ray / len;
	return (x);
}

int	get_color_texture(t_img_data *data, int x, int y)
{
	char	*dst;
	int		color;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}