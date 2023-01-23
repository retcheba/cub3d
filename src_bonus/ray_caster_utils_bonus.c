/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 03:46:12 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/23 19:17:41 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

int	hit_a_wall(t_game *game, float x, float y)
{
	if (game->map[(int)y / game->cell_size][(int)x / game->cell_size] != '1'
		&& !(game->map[(int)(y - 0.1) / game->cell_size] \
			[(int)x / game->cell_size] == '1'
		&& game->map[(int)y / game->cell_size] \
			[(int)(x - 0.1) / game->cell_size] == '1')
		&& !(game->map[(int)(y - 0.1) / game->cell_size] \
			[(int)x / game->cell_size] == '1'
		&& game->map[(int)y / game->cell_size] \
			[(int)(x + 0.1) / game->cell_size] == '1'))
		return (0);
	return (1);
}

void	ft_put_pixel(t_game *game, t_raycast *raycast)
{
	if ((raycast->x >= 0 && raycast->x < game->mini_map.img_width)
		&& (raycast->y >= 0 && raycast->y < game->mini_map.img_height))
		my_mlx_pixel_put(&game->mini_map, raycast->x, raycast->y, 0x008000);
}

void	incr_or_decr_xy(t_game *game, t_raycast *raycast, float x2, float y2)
{
	if (2 * raycast->err > -raycast->dy)
	{
		raycast->err -= raycast->dy;
		if (game->player.px < x2)
			raycast->x += 0.1;
		else
			raycast->x -= 0.1;
	}
	if (2 * raycast->err < raycast->dx)
	{
		raycast->err += raycast->dx;
		if (game->player.py < y2)
			raycast->y += 0.1;
		else
			raycast->y -= 0.1;
	}
}
