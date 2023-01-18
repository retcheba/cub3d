/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 04:56:02 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/18 23:33:16 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static float	ft_draw_one_line(t_game *game, t_img_data *mini_map, float x2, float y2, int i)
{
	float	x;
	float	y;
	float	ox;
	float	oy;
	float	dx;
	float	dy;
	float	err;

	x = game->px;
	y = game->py;
	dx = fabsf(x2 - game->px);
	dy = fabsf(y2 - game->py);
	err = dx - dy;
	while (game->map[(int)y / game->cell_size][(int)x / game->cell_size] != '1'
		&& !(game->map[(int)(y - 0.1) / game->cell_size][(int)x / game->cell_size] == '1'
		&& game->map[(int)y / game->cell_size][(int)(x - 0.1) / game->cell_size] == '1'))
	{
		ox = x;
		oy = y;
		my_mlx_pixel_put(mini_map, x, y, 0x008000);
		if (2 * err > -dy)
		{
			err -= dy;
			if (game->px < x2)
				x += 0.1;
			else
				x -= 0.1;
		}
		if (2 * err < dx)
		{
			err += dx;
			if (game->py < y2)
				y += 0.1;
			else
				y -= 0.1;
		}
	}
	game->lines_len[i][2] = x;
	game->lines_len[i][3] = y;
	game->lines_len[i][1] = 0;
	if (((int)oy - game->cell_size) / game->cell_size == (int)y /game->cell_size)
		game->lines_len[i][1] = NORTH;
	if (((int)oy + game->cell_size) / game->cell_size == (int)y / game->cell_size)
		game->lines_len[i][1] = SOUTH;
	if (((int)ox - game->cell_size) / game->cell_size == (int)x / game->cell_size)
		game->lines_len[i][1] = WEST;
	if (((int)ox + game->cell_size) / game->cell_size == (int)x / game->cell_size)
		game->lines_len[i][1] = EAST;
	return (sqrt(((game->px - x) * (game->px - x)) + ((game->py - y) * (game->py - y))));
}

void	ft_draw_lines(t_game *game, t_img_data *mini_map)
{
	float	ra;
	float	ca;
	float	x2;
	float	y2;
	float	disT;
	int		nbr;
	int		i;


	nbr = NB_RAYS;
	i = - (nbr / 2);
	while (i < (nbr / 2))
	{
		ra = game->pa + ((float)i * (DR) * 60 / nbr);
		if (ra == M_PI || ra == 0.0 || ra == M_PI / 2.0 || ra == 3.0 * M_PI / 2.0)
			ra += (DR * 60 / nbr);
		x2 = game->px + cosf(ra) * 10000.0;
		y2 = game->py - sinf(ra) * 10000.0;
		disT = ft_draw_one_line(game, mini_map, x2, y2, i + (nbr / 2));
		// fix fisheye
		ca = game->pa - ra;
		if (ca < 0.0)
			ca += 2.0 * M_PI;
		if (ca > 2.0 * M_PI)
			ca -= 2/.0 * M_PI;
		disT = disT * cosf(ca);
		game->lines_len[i + (nbr / 2)][0] = CUBE_HEIGHT * (1.0 / disT); 
		i++;
	}
}
