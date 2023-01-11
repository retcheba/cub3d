/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 04:56:02 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/11 19:21:55 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_draw_one_line(t_game *game, t_img_data *mini_map, int x2, int y2)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	err;

	x = game->px;
	y = game->py;
	dx = abs(x2 - game->px);
	dy = abs(y2 - game->py);
	err = dx - dy;
	while (game->map[y / game->cell_size][x / game->cell_size] != '1'
		&& x != x2 && y != y2)
	{
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
		my_mlx_pixel_put(mini_map, x, y, 0x00FF00);
	}
}

void	ft_draw_lines(t_game *game, t_img_data *mini_map)
{
	float	angle;
	int		x2;
	int		y2;
	int		i;

	i = -45;
	while (i < 45)
	{
		angle = game->pa + (i * 0.0175);
		x2 = game->px + cos(angle) * 1000;
		y2 = game->py - sin(angle) * 1000;
		ft_draw_one_line(game, mini_map, x2, y2);
		i++;
	}
}
