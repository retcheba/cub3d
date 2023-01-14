/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 04:56:02 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/14 02:17:24 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static float	ft_draw_one_line(t_game *game, t_img_data *mini_map, float x2, float y2)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	err;

	(void)mini_map;
	x = game->px;
	y = game->py;
	dx = fabsf(x2 - game->px);
	dy = fabsf(y2 - game->py);
	err = dx - dy;
	while (game->map[(int)y / game->cell_size][(int)x / game->cell_size] != '1'
		&& x != x2 && y != y2)
	{
		my_mlx_pixel_put(mini_map, x, y, 0x008000);
		if (2 * err > -dy)
		{
			err -= dy;
			if (game->px < x2)
				x++;
			else
				x--;
		}
		if (2 * err < dx)
		{
			err += dx;
			if (game->py < y2)
				y++;
			else
				y--;
		}
	}
	return (sqrt(((game->px - x) * (game->px - x)) + ((game->py - y) * (game->py - y))));
}

void	ft_draw_lines(t_game *game, t_img_data *mini_map)
{
	float	angle;
	float	x2;
	float	y2;
	int		i;

	i = -450;
	while (i < 450)
	{
		angle = game->pa + ((float)i * 0.00175);
		if (angle == M_PI || angle == 0.0 || angle == M_PI / 2.0 || angle == 3.0 * M_PI / 2.0)
			angle += 0.0001;
		x2 = game->px + cosf(angle) * 10000.0;
		y2 = game->py - sinf(angle) * 10000.0;
		game->lines_len[i + 450] = ft_draw_one_line(game, mini_map, x2, y2);
		i++;
	}
}
