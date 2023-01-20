/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:52:14 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/18 23:34:14 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	get_y_texture(int y_len, float len)
{
	int	p_len;
	int	y;

	p_len = 140;
	y = p_len * y_len / (int)len;
	return (y);
}

int	get_x_texture(t_game *game, int i)
{
	float	x_ray;
	int		len;
	int		p_len;
	int		x;

	x_ray = 0.0;
	len = game->cell_size;
	p_len = 140;
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