/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 04:56:02 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/25 14:23:11 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

static void	ft_draw_one_ray(t_game *game, t_raycast *raycast, \
	float x2, float y2)
{
	raycast->x = game->player.px;
	raycast->y = game->player.py;
	raycast->dx = fabsf(x2 - game->player.px);
	raycast->dy = fabsf(y2 - game->player.py);
	raycast->err = raycast->dx - raycast->dy;
	while (!hit_a_wall(game, game->raycast.x, game->raycast.y))
	{
		raycast->ox = raycast->x;
		raycast->oy = raycast->y;
		ft_put_pixel(game, raycast);
		incr_or_decr_xy(game, raycast, x2, y2);
	}
}

static float	get_data_rays(t_game *game, t_raycast *raycast, int i)
{
	float	dist;

	game->data_rays[i][2] = raycast->x;
	game->data_rays[i][3] = raycast->y;
	game->data_rays[i][1] = 0;
	if (((int)raycast->oy - game->cell_size) / game->cell_size \
		== (int)raycast->y / game->cell_size)
		game->data_rays[i][1] = SOUTH;
	if (((int)raycast->oy + game->cell_size) / game->cell_size \
		== (int)raycast->y / game->cell_size)
		game->data_rays[i][1] = NORTH;
	if (((int)raycast->ox - game->cell_size) / game->cell_size \
		== (int)raycast->x / game->cell_size)
		game->data_rays[i][1] = EAST;
	if (((int)raycast->ox + game->cell_size) / game->cell_size \
		== (int)raycast->x / game->cell_size)
		game->data_rays[i][1] = WEST;
	dist = sqrt((game->player.px - raycast->x) * (game->player.px - raycast->x) \
		+ (game->player.py - raycast->y) * (game->player.py - raycast->y));
	return (dist);
}

static float	fix_fisheye(t_game *game, float dist, float ra)
{
	float	ca;

	ca = game->player.angle - ra;
	if (ca < 0.0)
		ca += 2.0 * M_PI;
	if (ca > 2.0 * M_PI)
		ca -= 2.0 * M_PI;
	dist = dist * cosf(ca);
	return (dist);
}

void	ft_ray_caster(t_game *game)
{
	float	ra;
	float	x2;
	float	y2;
	float	dist;
	int		i;

	i = - (NB_RAYS / 2);
	while (i < (NB_RAYS / 2))
	{
		ra = game->player.angle + ((float)i * (DR) * 60 / NB_RAYS);
		if (ra == M_PI || ra == 0.0
			|| ra == M_PI / 2.0 || ra == 3.0 * M_PI / 2.0)
			ra += (DR * 60 / NB_RAYS);
		x2 = game->player.px + cosf(ra) * 10000.0;
		y2 = game->player.py - sinf(ra) * 10000.0;
		ft_draw_one_ray(game, &game->raycast, x2, y2);
		dist = get_data_rays(game, &game->raycast, i + (NB_RAYS / 2));
		dist = fix_fisheye(game, dist, ra);
		game->data_rays[i + (NB_RAYS / 2)][0] = CUBE_HEIGHT * (1.0 / dist);
		i++;
	}
}
