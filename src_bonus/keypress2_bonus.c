/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 04:05:57 by retcheba          #+#    #+#             */
/*   Updated: 2023/01/23 22:36:15 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	ft_up(t_game *game)
{
	float	x2;
	float	y2;

	x2 = game->player.px + game->player.dx;
	y2 = game->player.py - game->player.dy;
	if (game->map[(int)(y2 - game->player.dy * COLLISION) / game->cell_size] \
		[(int)(x2 + game->player.dx * COLLISION) / game->cell_size] == '1')
		return ;
	game->player.px = x2;
	game->player.py = y2;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	mlx_destroy_image(game->mlx, game->background_map.img);
	ft_mini_map(game, &game->mini_map);
	ft_background_map(game, &game->background_map);
	mlx_put_image_to_window(game->mlx, game->win, game->background_map.img, \
		0, 0);
}

void	ft_down(t_game *game)
{
	float	x2;
	float	y2;

	x2 = game->player.px - game->player.dx;
	y2 = game->player.py + game->player.dy;
	if (game->map[(int)(y2 + game->player.dy * COLLISION) / game->cell_size] \
		[(int)(x2 - game->player.dx * COLLISION) / game->cell_size] == '1')
		return ;
	game->player.px = x2;
	game->player.py = y2;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	mlx_destroy_image(game->mlx, game->background_map.img);
	ft_mini_map(game, &game->mini_map);
	ft_background_map(game, &game->background_map);
	mlx_put_image_to_window(game->mlx, game->win, game->background_map.img, \
		0, 0);
}

void	ft_left(t_game *game)
{
	float	x2;
	float	y2;

	x2 = game->player.px + game->player.dx2;
	y2 = game->player.py - game->player.dy2;
	if (game->map[(int)(y2 - game->player.dy2 * COLLISION) / game->cell_size] \
		[(int)(x2 + game->player.dx2 * COLLISION) / game->cell_size] == '1')
		return ;
	game->player.px = x2;
	game->player.py = y2;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	mlx_destroy_image(game->mlx, game->background_map.img);
	ft_mini_map(game, &game->mini_map);
	ft_background_map(game, &game->background_map);
	mlx_put_image_to_window(game->mlx, game->win, game->background_map.img, \
		0, 0);
}

void	ft_right(t_game *game)
{
	float	x2;
	float	y2;

	x2 = game->player.px - game->player.dx2;
	y2 = game->player.py + game->player.dy2;
	if (game->map[(int)(y2 + game->player.dy2 * COLLISION) / game->cell_size] \
		[(int)(x2 - game->player.dx2 * COLLISION) / game->cell_size] == '1')
		return ;
	game->player.px = x2;
	game->player.py = y2;
	mlx_destroy_image(game->mlx, game->mini_map.img);
	mlx_destroy_image(game->mlx, game->background_map.img);
	ft_mini_map(game, &game->mini_map);
	ft_background_map(game, &game->background_map);
	mlx_put_image_to_window(game->mlx, game->win, game->background_map.img, \
		0, 0);
}
